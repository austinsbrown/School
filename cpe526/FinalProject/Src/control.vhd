library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.numeric_std.all;

entity control is
	port
	(
		clk, rst, Z    : in std_logic;
		Op             : in std_logic_vector(5 downto 0);
		IorD, MemWrite, MemRead,
		MemtoReg, IRWrite, PCSource,
		RegDst, RegWrite, ALUSrcA,
		PCSel          : out std_logic;
		ALUOp, ALUSrcB : out std_logic_vector(1 downto 0);
		DEBUG_STATE    : out std_logic_vector(3 downto 0)
	);
end control;

architecture behave of control is 
	-- Local Variables
	signal PCWrite, PCWriteCond : std_logic;
	signal state, next_state    : std_logic_vector(3 downto 0);

	-- Control Constants
	constant IFETCH     : std_logic_vector(3 downto 0) := "0000"; -- instruction fetch
	constant IDECODE    : std_logic_vector(3 downto 0) := "0001"; -- instruction decode / register fetch
	constant ADDRESSCMP : std_logic_vector(3 downto 0) := "0010"; -- memory address computation
	constant MEMLOAD    : std_logic_vector(3 downto 0) := "0011"; -- Memory Access 'load word'
	constant MEMSTORE   : std_logic_vector(3 downto 0) := "0100"; -- Memory Access 'store word'
	constant WRITEBACK  : std_logic_vector(3 downto 0) := "0101"; -- Memory Access finished
	constant EXECUTE    : std_logic_vector(3 downto 0) := "0110";
	constant RCOMPLETE  : std_logic_vector(3 downto 0) := "0111"; -- R-type completion
	constant BCOMPLETE  : std_logic_vector(3 downto 0) := "1000"; -- Branch completion
begin

	-- advance PC
	PCSel <= (PCWrite or (PCWriteCond and Z));

	DEBUG_STATE <= state; -- output to hex display

	-- get next state
	process (clk) begin
		if rising_edge(clk) then
			if(rst = '1') then
				state <= IFETCH;
			else
				state <= next_state;
			end if;
		end if;
	end process;

	-- FSM next state
	process(state, Op) begin
		case(state) is
			when IFETCH => next_state <= IDECODE;
			when IDECODE =>
				case(Op) is
					when "000000" => next_state <= EXECUTE;
					when "000100" => next_state <= BCOMPLETE;
					when "100011" => next_state <= ADDRESSCMP;
					when "101011" => next_state <= ADDRESSCMP;
					when others   => next_state <= IFETCH;
				end case;
			when ADDRESSCMP =>
				case(Op) is
					when "100011" => next_state <= MEMLOAD;
					when "101011" => next_state <= MEMSTORE;
					when others   => next_state <= IFETCH;
				end case;
			when MEMLOAD    => next_state <= WRITEBACK;
			when MEMSTORE   => next_state <= IFETCH;
			when WRITEBACK  => next_state <= IFETCH;
			when EXECUTE    => next_state <= RCOMPLETE;
			when RCOMPLETE  => next_state <= IFETCH;
			when BCOMPLETE  => next_state <= IFETCH;
			when others     => next_state <= IFETCH; -- when in doubt: IFETCH
		end case;
	end process;

	process(state) begin
		-- init to zero - eliminate carry-over errors
		IorD        <= '0'; -- instruction mode by default
		MemRead     <= '0';
		MemWrite    <= '0';
		MemtoReg    <= '0';
		IRWrite     <= '0';
		RegWrite    <= '0';
		RegDst      <= '0';
		PCSource    <= '0';
		PCWrite     <= '0';
		PCWriteCond <= '0';
		ALUSrcB     <= "00";
		ALUSrcA     <= '0';
		ALUOp       <= "00";

		-- FSM output
		case (state) is
			when IFETCH =>
				MemRead <= '1';
				IRWrite <= '1';
				PCWrite <= '1';
				ALUSrcB <= "01";
			when IDECODE => ALUSrcB <= "11";
			when ADDRESSCMP =>
				ALUSrcA <= '1';
				ALUSrcB <= "10";
			when MEMLOAD =>
				MemRead <= '1';
				IorD    <= '1'; -- switch to data
			when MEMSTORE =>
				MemWrite <= '1';
				IorD     <= '1'; -- switch to data
			when WRITEBACK  =>
				RegDst   <= '0';
				RegWrite <= '1';
				MemtoReg <= '1';
			when EXECUTE   =>
				ALUSrcA <= '1';
				ALUOp   <= "10";
			when RCOMPLETE =>
				RegDst   <= '1';
				RegWrite <= '1';
			when BCOMPLETE =>
				PCWriteCond <= '1';
				PCSource    <= '1';
				ALUSrcA     <= '1';
				ALUOp       <= "01";
			when others => null;
		end case;
	end process;
end behave;

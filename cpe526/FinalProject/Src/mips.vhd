library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity mips is
	port 
	(
		clk : in std_logic;
		reset : in std_logic;
		ALUMirror : out std_logic_vector(3 downto 0);
		Z : out std_logic;
		DEBUG_STATE : out std_logic_vector(3 downto 0);
		DEBUG : out std_logic_vector(23 downto 0)
	);
end mips;

architecture behave of mips is

	signal zero : std_logic;
	signal IorD : std_logic;
	signal memRead : std_logic;
	signal memWrite : std_logic;
	signal memToReg : std_logic;
	signal IRWrite : std_logic;
	signal PCSource : std_logic;
	signal ALUSrcA : std_logic;
	signal ALUSrcB : std_logic_vector(1 downto 0);
	signal regWrite : std_logic;
	signal regDst : std_logic;
	signal PCSel : std_logic;
	signal op : std_logic_vector(5 downto 0);
	signal ALUop : std_logic_vector(1 downto 0);
	signal ALUCtrl : std_logic_vector(3 downto 0);
	signal func : std_logic_vector(5 downto 0);

	component datapath
		port
		(
			clk : in std_logic; 
			reset : in std_logic; 
			IorD : in std_logic; 
			memWrite : in std_logic;
			memRead : in std_logic; 
			memToReg : in std_logic;
			IRWrite : in std_logic;
			PCSource : in std_logic;
			regDst : in std_logic; 
			regWrite : in std_logic;
			PCSel : in std_logic;
			ALUSrcA : in std_logic;
			ALUSrcB : in std_logic_vector(1 downto 0);
			ALUCtrl : in std_logic_vector(3 downto 0);
			op : out std_logic_vector(5 downto 0);
			zero : out std_logic;
			func : out std_logic_vector(5 downto 0);
			DEBUG : out std_logic_vector(23 downto 0)
		);
	end component;

begin
	dp : datapath
	port map
	(
		clk=>clk, reset=>reset, IorD=>IorD, memWrite=>memWrite, memRead=>memRead, memToReg=>memToReg, 
		IRWrite=>IRWrite, PCSource=>PCSOurce, regDst=>regDst, regWrite=>regWrite, PCSel=>PCSel,
		ALUSrcA=>ALUSrcA, ALUSrcB=>ALUSrcB, ALUCtrl=>ALUCtrl, op=>op, zero=>zero, func=>func, DEBUG=>DEBUG
	);

	ctrl : entity work.control(behave)
		port map (
			clk => clk,
			rst => reset,
			Z => zero,
			Op => Op,
			IorD => IorD,
			MemWrite => MemWrite,
			MemRead => MemRead,
			MemtoReg => MemtoReg,
			IRWrite => IRWrite,
			PCSource => PCSource,
			RegDst => RegDst,
			RegWrite => RegWrite,
			ALUSrcA => ALUSrcA,
			PCSel => PCSel,
			ALUOp => ALUOp,
			ALUSrcB => ALUSrcB,
			DEBUG_STATE => DEBUG_STATE
		);

	alu_control: entity work.alu_control(behave)
		port map (ALUop, func, ALUCtrl);
		
	ALUMirror <= ALUCtrl;
	Z <= zero;

end architecture;

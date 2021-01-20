use WORK.all;
library ieee;
use IEEE.std_logic_1164.all;

entity CONTROL_TEST_BENCH is
end CONTROL_TEST_BENCH;

architecture TEST of CONTROL_TEST_BENCH is
	signal IorD, MemWrite, MemRead,
	MemtoReg, IRWrite, PCSource,
	RegDst, RegWrite, ALUSrcA,
	PCSel                 : std_logic;

	signal clk            : std_logic := '0';
	signal rst, Z         : std_logic;
	signal Op             : std_logic_vector(5 downto 0);
	signal ALUOp, ALUSrcB : std_logic_vector(1 downto 0);

begin
	control : entity work.control(behave)
	      port map (
		      clk => clk,
		      rst => rst,
		      Z => Z,
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
		      ALUSrcB => ALUSrcB
		    );

	process(clk) begin
		clk <= not clk after 1 ns;
	end process;


	-- run for 52 ns
	process begin
		wait for 1 ns;
		rst <= '1';
		wait for 1 ns;
		rst <= '0';
		Op <= "100011";
		Z <= '0';
		wait for 10 ns; -- 5 clk pulses - max 
		Op <= "101011";
		wait for 10 ns;
		Op <= "000000";
		wait for 10 ns;
		Op <= "000100";
		wait for 10 ns;
		rst <= '1';
		wait for 10 ns;
		wait;
	end process;
end TEST;

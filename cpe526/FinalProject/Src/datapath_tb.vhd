use WORK.all;
library ieee;
use IEEE.std_logic_1164.all;

entity DATAPATH_TEST_BENCH is
end DATAPATH_TEST_BENCH;

architecture TEST of DATAPATH_TEST_BENCH is
	signal IorD, MemWrite, MemRead,
	MemtoReg, IRWrite, PCSource,
	RegDst, RegWrite, ALUSrcA,
	PCSel                 : std_logic;

	signal clk            : std_logic := '0';
	signal rst, Z         : std_logic;
	signal Op, func       : std_logic_vector(5 downto 0);
	signal ALUOp, ALUSrcB : std_logic_vector(1 downto 0);
	signal ALUCtrl        : std_logic_vector(3 downto 0);1

begin
  --control: entity work.alu_control(behave)
  --         port map (Op, functField, aluOp);

	dp : entity work.datapath(behave)
	     port map (
				clk=>clk, reset=>rst, IorD=>IorD, memWrite=>memWrite, memRead=>memRead, memToReg=>memToReg, 
				IRWrite=>IRWrite, PCSource=>PCSOurce, regDst=>regDst, regWrite=>regWrite, PCSel=>PCSel,
				ALUSrcA=>ALUSrcA, ALUSrcB=>ALUSrcB, ALUCtrl=>ALUCtrl, op=>Op, zero=>Z, func=>func
			);

	-- instantiate clk
	process(clk) begin
		clk <= not clk after 1 ns;
	end process;


	-- run for 52 ns
	process begin
		wait for 1 ns;
		rst <= '1';
		wait for 1 ns;
		rst <= '0';
		IorD = '1'; -- address gets aluOut
		IRWrite <= '1';
		
		wait for 2 ns; -- 5 clk pulses - max 
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

use WORK.all;
library ieee;
use IEEE.std_logic_1164.all;

entity PROGRAM_COUNTER_TEST_BENCH is
end PROGRAM_COUNTER_TEST_BENCH;

architecture TEST of PROGRAM_COUNTER_TEST_BENCH is
	signal clk       : std_logic := '0';
	signal reset     : std_logic;
  signal PCsel     : std_logic;
  signal PCSource  : std_logic;
  signal ALUResult : std_logic_vector(31 downto 0);
  signal ALUOut    : std_logic_vector(31 downto 0);
  signal PC        : std_logic_vector(7 downto 0);

begin
  --control: entity work.alu_control(behave)
  --         port map (Op, functField, aluOp);

	pc_inst : entity work.program_counter(behave)
	     port map (
	      clk=>clk, reset=>reset, PCSel=>PCSel,
	      PCSource=>PCSource, ALUResult=>ALUResult,
	      ALUOut=>ALUOut, PC=>PC
	    );

	-- instantiate clk
	process(clk) begin
		clk <= not clk after 1 ns;
	end process;

	ALUResult <= x"0000000a";
	ALUOut    <= x"0000000b";

	process begin
		reset <= '1';
		wait for 2 ns;
		reset <= '0';
		PCsel <= '1';
		PCSource <= '0';
		wait for 4 ns;
		PCsel <= '1'; -- address gets aluOut
		PCSource <= '1';
		wait for 4 ns;
		PCsel <= '0';
		wait for 4 ns;
		reset <= '1';
		wait;
	end process;
end TEST;

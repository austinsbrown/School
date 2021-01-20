library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity mips_tb is
end mips_tb;

architecture testbench of mips_tb is
    signal clk : std_logic := '0';
	signal reset : std_logic;

    component mips
    port
        (
            clk : in std_logic;
            reset : in std_logic
        );
    end component;
begin

    dut : mips port map (clk=>clk, reset=>reset);

    process(clk)
    begin
        clk <= not clk after 5 ns;
    end process;
    
    stimuli : process
	begin
        reset <= '1';
        wait for 10 ns;
        reset <= '0';
        wait;
	end process;
end testbench;

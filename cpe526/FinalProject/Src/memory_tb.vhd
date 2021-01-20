library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.numeric_std.all;

entity memory_tb is
end memory_tb;

architecture test of memory_tb is
    signal clk : std_logic := '0';
    signal reset : std_logic;
    signal memWrite : std_logic;
    signal memRead : std_logic;
    signal address : std_logic_vector(7 downto 0);
    signal B : std_logic_vector(31 downto 0);
    signal memData : std_logic_vector(31 downto 0);

begin
    dut : entity work.memory(behave)
    port map
    (
        clk=>clk, reset=>reset, memWrite=>memWrite,
        memRead=>memRead, address=>address, B=>B,
        memData=>memData
    );

    process(clk) begin
		clk <= not clk after 1 ns;
	end process;

    process begin
        memRead <= '1';
        address <= x"80";
        memWrite <= '0';
        reset <= '0';
        B <= x"00000000";
        wait for 5 ns;

        reset <= '1';
        wait for 5 ns;

        reset <= '0';
        wait for 5 ns;

        memRead <= '0';
        address <= x"00";
        memWrite <= '1';
        B <= x"FFFFFFFF";
        wait for 5 ns;

        memRead <= '1';
        memWrite <= '0';
        wait for 5 ns;

        memRead <= '0';
        address <= x"48"; -- 72
        memWrite <= '1';
        B <= x"0000FFFF";
        wait for 5 ns;

        memRead <= '1';
        memWrite <= '0';
        wait;
    end process;
end test;
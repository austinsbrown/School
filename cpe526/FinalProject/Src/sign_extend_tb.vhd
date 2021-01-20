library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.numeric_std.all;

entity sign_extend_tb is
end sign_extend_tb;

architecture test of sign_extend_tb is
    component sign_extend
        port 
        (
            in_bits : in std_logic_vector(15 downto 0);
            out_bits : out std_logic_vector(31 downto 0)
        );
    end component;

    signal in_bits : std_logic_vector(15 downto 0);
    signal out_bits : std_logic_vector(31 downto 0);

begin
    uut : sign_extend 
    port map
    (
        in_bits => in_bits, 
        out_bits => out_bits
    );

    process begin
        in_bits <= x"0001";

        wait for 1 ns;
        in_bits <= x"FFFF";

        wait for 1 ns;
        in_bits <= "1000000000000000";

        wait for 1 ns;
        
        wait;
    end process;
end test;
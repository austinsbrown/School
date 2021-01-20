library ieee;
use ieee.std_logic_1164.all;

entity even_odd is
    port 
    (
        bin_in : in std_logic_vector(3 downto 0);
        bin_out : out std_logic_vector(4 downto 0);
    );
end entity even_odd;

architecture behav of even_odd is
begin
    main : process(bin_in)
    begin
        case bin_in is 
            when "0000" => bin_out <= "11011";
            when "0001" => bin_out <= "10111";
            when "0010" => bin_out <= "11011";
            when "0011" => bin_out <= "10111";
            when "0100" => bin_out <= "11011";
            when "0101" => bin_out <= "10111";
            when "0111" => bin_out <= "10111";
            when "1000" => bin_out <= "11011";
            when "1001" => bin_out <= "10111";
            when "1010" => bin_out <= "11011";
            when "1011" => bin_out <= "10111";
            when "1100" => bin_out <= "11011";
            when "1101" => bin_out <= "10111";
            when "1110" => bin_out <= "11011";
            when "1111" => bin_out <= "10111";
        end case;
    end process;
end architecture behav;
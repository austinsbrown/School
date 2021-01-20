library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity display_driver is
	port 
	(
		Input  : in std_logic_vector(3 downto 0);
		Output : out std_logic_vector(7 downto 0));
end display_driver;

-- convert byte to display on the 7 segment LEDs

architecture behave of display_driver is
begin
	process (Input) begin
		case Input is
			when "0000" => Output <= x"C0";
			when "0001" => Output <= x"F9";
			when "0010" => Output <= x"A4";
			when "0011" => Output <= x"B0";
			when "0100" => Output <= x"99";
			when "0101" => Output <= x"92";
			when "0110" => Output <= x"82";
			when "0111" => Output <= x"F8";
			when "1000" => Output <= x"80";
			when "1001" => Output <= x"90";
			when "1010" => Output <= x"88";
			when "1011" => Output <= x"83";
			when "1100" => Output <= x"C6";
			when "1101" => Output <= x"A1";
			when "1110" => Output <= x"86"; 
			when "1111" => Output <= x"8E";
			when others => Output <= x"FF";  -- all high means all off
		end case;
	end process;
end behave;

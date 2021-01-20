library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.numeric_std.all;

entity alu is
	port 
	(
		opA, opB : in  std_logic_vector(31 downto 0); -- the inputs
		aluOp : in  std_logic_vector(3  downto 0); -- what operation to perform
		result : out std_logic_vector(31 downto 0) -- the end result
		-- maybe add zero flag
	);
end entity alu;

architecture behave of alu is begin
	process(aluOp, opA, opB) begin
		case aluOp is
			when "0000" => result <= opA and opB; -- and
			when "0001" => result <= opA or opB; -- or
			when "0010" => result <= std_logic_vector(to_signed(to_integer(signed(opA)) + to_integer(signed(opB)), 32)); -- add
			when "0110" => result <= std_logic_vector(to_signed(to_integer(signed(opA)) - to_integer(signed(opB)), 32)); -- subtract
			when "0111" =>
				if(opA < opB) then 
					result <= "11111111111111111111111111111111"; -- set on less than
					else result <= "00000000000000000000000000000000"; 
				end if;
			when "1100" => result <= not (opA or opB); -- branch if equal
			when others => result <= "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
		end case;
	end process;
end behave;

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.numeric_std.all;

entity program_counter is
    generic(PCSTART : integer := 128);
    port 
    (
        clk : in std_logic;
        reset : in std_logic;
        PCsel : in std_logic;
        PCSource : in std_logic;
        ALUResult : in std_logic_vector(31 downto 0);
        ALUOut : in std_logic_vector(31 downto 0);
        PC : out std_logic_vector(7 downto 0)
    );
end program_counter;

architecture behave of program_counter is
begin
    process(clk) begin
        if rising_edge(clk) then
            if(reset = '1') then
                PC <= std_logic_vector(to_unsigned(PCSTART, PC'length)); -- go back to the original instruction
            else
                if(PCsel = '1') then
                    case(PCSource) is
                        when '0' => PC <= ALUResult(7 downto 0); -- direct line from alu
                        when '1' => PC <= ALUOut(7 downto 0);    -- intermediate register
                        when others => PC <= "XXXXXXXX";
                    end case;
                end if;
            end if;
        end if;
    end process;
end architecture;
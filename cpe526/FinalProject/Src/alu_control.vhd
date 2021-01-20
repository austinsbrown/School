library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.numeric_std.all;
entity alu_control is
port (
    Op         : in std_logic_vector(1 downto 0);
    functField : in std_logic_vector(5 downto 0);
    aluCtrl    : out std_logic_vector(3 downto 0)
);
end alu_control;

architecture behave of alu_control is begin
    process(Op, functField)
        variable Op_Field : std_logic_vector(7 downto 0);
    begin
        Op_Field := Op & functField;

        case? Op_Field is
            when "1---0000" => aluCtrl <= "0010"; -- add 
            when "1---0010" => aluCtrl <= "0110"; -- sub
            when "1---0100" => aluCtrl <= "0000"; -- and
            when "1---0101" => aluCtrl <= "0001"; -- or
            when "1---1010" => aluCtrl <= "0111"; -- slt
            when "00------" => aluCtrl <= "0010"; -- lw and sw (does not go to alu)
            when "01------" => aluCtrl <= "1100"; -- beq
            when others => aluCtrl <= "XXXX"; -- 0101 ? 
        end case?;
    end process;
end behave; 
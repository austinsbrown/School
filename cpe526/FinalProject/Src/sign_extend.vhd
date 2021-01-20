library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.numeric_std.all;

entity sign_extend is -- sign extend for 16 to 32 bits
    port 
    (
        in_bits : in std_logic_vector(15 downto 0);
        out_bits : out std_logic_vector(31 downto 0)
    );
end sign_extend;

architecture behav of sign_extend is
begin
    out_bits <= std_logic_vector(resize(signed(in_bits), out_bits'length)); 
end architecture;
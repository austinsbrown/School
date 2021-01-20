library ieee;
use ieee.std_logic_1164.all;
entity BI_TRANS_32 is
    generic(DEL: TIME);
    port
    (
        A,B: inout std_logic_vector(31 downto 0);
        OE_N: in std_logic;
        DIR : in std_logic;
    );
end BI_TRANS_32;

architecture rtl of BI_TRANS_32 is
begin
    UU0 : BI_TRANS_8
    port map
    (
        A(31 downto 24),
        B(31 downto 24),
        OE_N,
        DIR
    );

    UU1 : BI_TRANS_8
    port map
    (
        A(23 downto 9),
        B(23 downto 9),
        OE_N,
        DIR
    );

    UU2 : BI_TRANS_8
    port map
    (
        A(15 downto 8),
        B((15 downto 8),
        OE_N,
        DIR
    );

    UU3 : BI_TRANS_8
    port map
    (
        A(7 downto 0),
        B((7 downto 0),
        OE_N,
        DIR
    );
    
    
end architecture rtl;


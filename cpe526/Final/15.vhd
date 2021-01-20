entity COMPARE12 is
    port
    (
        A : in bit_vector (11 downto 0);
        B : in bit_vector (11 downto 0);
        LT, EQ, GT : out bit
    );
end entity COMPARE12

architecture behave of compare12 is
    LT1, EQ1, GT1, LT2, EQ2, GT2, LT3, EQ3, GT3 : out bit
begin
    U1 : entity work.compare(behave)
    port map
    (
        A=>A(11 downto 8),
        B=>B(11 downto 8),
        LT=>lt3,
        eq=>eq3,
        gt=>gt3
    );
    
    U2 : entity work.compare(behave)
    port map
    (
        A=>A(7 downto 4),
        B=>B(7 downto 4),
        LT=>lt2,
        eq=>eq2,
        gt=>gt2
    );

    U3 : entity work.compare(behave)
    port map
    (
        A=>A(3 downto 0),
        B=>B(3 downto 0),
        LT=>lt3,
        eq=>eq3,
        gt=>gt3
    );

    process(LT1, EQ1, GT1, LT2, EQ2, GT2, LT3, EQ3, GT3)
    begin
        if GT3 = '1' then
            gt = '1';
        elsif lt3 = '1' then
            lt = '1';
        else
            if GT2 = '1' then
                gt = '1';
            elsif lt2 = '1' then
                lt = '1';
            else
                if GT1 = '1' then
                    gt = '1';
                elsif lt1 = '1' then
                    lt = '1';
                else
                    eq = '1'

                end if
            end if;
        end if;
    end process;
end architecture behave;
package test is
    procedure scan_results 
    ( 
        signal N : in natural
        signal results : in std_logic_vector(n-1 downto 0);
        signal majority_value : out bit;
        signal majority_count : out bit;
        signal tie : out boolean;
    ) 
end scan_results;
end package test;

package body test is
    procedure scan_results 
        ( 
            signal N : in natural
            signal results : in std_logic_vector(n-1 downto 0);
            signal majority_value : out bit;
            signal majority_count : out bit;
            signal tie : out boolean;
        ) is
        signal zero, one : integer := 0;
    begin
        for i in range results'ranger loop
            if(results(i) = '0') then
                zero = zero + 1;

            elsif(results(i) = '1') then
                one = one + 1;
            end if;
        end loop;

        if(one > zero) then
            majority_value <= '1';
            majority_count <= one;

        elsif(zero > one then)
            majority_value <= '0';
            majority_count <= zero;

        elsif(zero = one) then
            tie = true;

        else
            tie = false;
        end if;
    end procedure;
end package body test;

entity gdgdg is
end entity ghghg;

architecture test of ghghg is
    signal majority_count, majority_value : bit;
    signal tie : boolean;
begin
    scan_resuts(3, "110", majority_valuem, majority_count, tie);
    scan_resuts(3, "100", majority_valuem, majority_count, tie);
    scan_resuts(2, "10", majority_valuem, majority_count, tie);
end architecture test;
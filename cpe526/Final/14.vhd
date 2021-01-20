architecture behave  of euclid is
    type state_type is (idle, load, calc, finish);
    registers x(15:0), y(15:0);
    signal state : state_type;
begin
    process(clk, reset)
    begin
        if(reset = '1') then
            state <= idle;

        elsif rising_edge(clk) then
            if(start = '1') then
                state <= load;

            elsif state = load then
                X <= Xi;
                Y <= Yi;
                state <= calc;

            elsif state = calc then
                while (X /= Y) loop
                    if (X < Y) then
                        Y <= Y -X
                    else
                        X <= X –Y
                    end loop
                state <= finish;
            
            elsif state = finsih then
                if done = '1' then
                    state = idle;
                end if; 
            end if;
            
        end if;
    end process;
    
    
end architecture behave ;
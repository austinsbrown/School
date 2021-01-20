library ieee;
use ieee.std_logic_1164.all;

entity SHIFTER is
    port
    (
        DATA_IN: in BIT_VECTOR(3 downto 0);
        SR,SL: in BIT; 
        IL,IR: in BIT;
        ASR : in BIT
        DATA_OUT: out BIT_VECTOR(3 downto 0));
    end SHIFTER;
    
architecture  ALG of SHIFTER is
    begin
    process(SR,SL,DATA_IN,IL,IR)
        variable CON: BIT_VECTOR(0 to 1);
        begin
        CON := SR&SL;
        if(ASR = '1') then 
            case CON is 
                when "00" => DATA_OUT <= DATA_IN;
                when "01" => DATA_OUT <= DATA_IN(2 downto0) & IL;
                when "10" => DATA_OUT <= DATA_IN(3) & DATA_IN(3 downto 1);
                when "11" => DATA_OUT <= DATA_IN;
            end case;
        elsif(ASR = '0') then
            case CON is 
                when "00" => DATA_OUT <= DATA_IN;
                when "01" => DATA_OUT <= DATA_IN(2 downto 0) & IL;
                when "10" => DATA_OUT <= IR & DATA_IN(3 downto 1);
                when "11" => DATA_OUT <= DATA_IN;
            end case;
        end if;
    end process;
end ALG;

architecture concurrent of SHIFTER  is
    signal temp : BIT_VECTOR(3 down to 0);
begin
    if(ASR = '1') then
        temp <= DATA_IN when CON = "00" else
                DATA_IN(2 downto0) & IL; when CON = "01" else
                DATA_IN(3) & DATA_IN(3 downto 1) when CON = "10" else
                DATA_IN when CON = "11" else
        temp;

    elsif(ASR = '0')
        temp <= DATA_IN when CON = "00" else
            DATA_IN(2 downto0) & IL; when CON = "01" else
            IR & DATA_IN(3 downto 1) when CON = "10" else
            DATA_IN when CON = "11" else
        temp;
    end if;
    
    
end architecture concurrent;
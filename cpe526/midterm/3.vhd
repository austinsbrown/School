library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;

entity jk is
    generic(tphl, tplh : time);
    port
        ( 
            J,K: in  std_logic;
            reset: in std_logic;
            clk_enable: in std_logic;
            clk: in std_logic;
            q: out std_logic;
            qn : out std_logic
        );
end jk;

architecture behav of jk is
    
   signal temp: std_logic;
begin
   process (clk) 
   begin
    if rising_edge(clk) then 
        if(reset = '1') then 
            temp <= '0';
        end if
    elsif falling_edge(clk) then                 
         if clk_enable ='1' then
            if (J='0' and K='0') then
               temp <= temp;
            elsif (J='0' and K='1') then
               temp <= '0'after tphl;
            elsif (J='1' and K='0') then
               temp <= '1' after tplh;
            elsif (J='1' and K='1') then
               temp <= not (temp);
            end if;
        end if;
    end if;
   end process;
   q <= temp;
   qn <= not temp;
end behav;
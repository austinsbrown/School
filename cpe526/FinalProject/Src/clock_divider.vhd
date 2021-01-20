library IEEE;
 use IEEE.STD_LOGIC_1164.ALL;
 use IEEE.numeric_std.all;

 entity clock_divider is
    Port (
          clk_in   : in std_logic;
          clk_out  : out std_logic
    );
 end clock_divider;


 architecture behave of clock_divider is
    constant max_count : natural := 1000000; -- 1 mhz clk in, so count this many times to get to 1hz
 begin

  process(clk_in)
        variable count : natural range 0 to max_count;

    begin
        if rising_edge(clk_in) then
            if count < (max_count/2)-1 then
                count := count + 1;
                clk_out <= '1';
            elsif count < max_count-1 then
                count := count + 1;
                clk_out <= '0';
            else
                count := 0;
                clk_out <= '1';
            end if;
     end if;
  end process;
 end behave;
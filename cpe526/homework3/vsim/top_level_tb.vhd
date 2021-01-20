use WORK.all;
library ieee;
use IEEE.std_logic_1164.all;
use ieee.numeric_std.all;
use IEEE.std_logic_textio.all;
use std.TEXTIO.all;

entity top_level_tb is
end top_level_tb;

library ieee;
use IEEE.std_logic_1164.all;

architecture  TEST of top_level_tb is
    signal RST, S, R, R_Correct, Y, Y_Correct, G, G_Correct : std_logic;

    component stop_light_logic
        port
        (
            reset : in std_logic;
            start : in std_logic;
            clock : in std_logic;

            red : out std_logic;
            yellow : out std_logic;
            green : out std_logic
        );
    end component;

    component clock_divider
        port 
        (
            clk   : in std_logic;
            clk_out  : out std_logic
        );
    end component;

  signal CLK : std_logic := '0';
  signal DIVIDED_CLK : std_logic := '0';
  signal delay_clk : std_logic := '0';

begin
-- create clock
  process(CLK)
  begin
    CLK <= not CLK after 1000 ns;
  end process;

  U1: CLOCK_DIVIDER port map (clk, DIVIDED_CLK); -- divide clock
  U2: stop_light_logic port map (RST, S, delay_clk, R, Y, G); -- create light entity

  process
    variable counter : natural := 0;
    variable vline : LINE;
    variable V : std_logic_vector (5 downto 0); -- 6 bits
    variable VSPACE : character;
    file invect : TEXT is "stimulus.txt";

  begin
    readline(invect, vline); -- discard first line
    readline(invect, vline);
    read(vline, V(1 downto 0));
    read(vline, VSPACE);
    read(vline, V(4 downto 2));
    RST <= V(1);
    S <= V(0);
    R_Correct <= V(4);
    Y_Correct <= V(3);
    G_Correct <= V(2);

    while not(ENDFILE(invect)) loop -- while loop

      wait until DIVIDED_CLK = '1';
      readline(invect, vline);
      read(vline, V(1 downto 0));
      read(vline, VSPACE);
      read(vline, V(4 downto 2));
      --report "vline: " & vline.all;
      RST <= V(1);
      S <= V(0);
      R_Correct <= V(4);
      Y_Correct <= V(3);
      G_Correct <= V(2);

      delay_clk <= DIVIDED_CLK;

      wait until DIVIDED_CLK = '0'; -- wait until next high clock
      delay_clk <= DIVIDED_CLK;
      wait for 200 ns;

    end loop;
    wait;
  end process;
end TEST;


use WORK.all;
library ieee;
use IEEE.std_logic_1164.all;

entity ALU_TEST_BENCH is
end ALU_TEST_BENCH;

architecture  TEST of ALU_TEST_BENCH is
  -- alu
  signal op1, op2 : std_logic_vector(31 downto 0);
  signal aluOp    : std_logic_vector(3  downto 0);
  signal result   : std_logic_vector(31 downto 0);
  signal zeroFlag : std_logic;
  -- alu control
  signal Op         : std_logic_vector(1 downto 0);
  signal functField : std_logic_vector(5 downto 0);

begin
  alu : entity work.alu(behave)
        port map (op1, op2, aluOp, result);
  control: entity work.alu_control(behave)
           port map (Op, functField, aluOp);

    process begin
      -- initialize alu operations
      op1 <= "00000000000000000000000000000011";
      op2 <= "00000000000000000000000000001010";

      -- test alu control ( run for 11 ns )

      wait for 1 ns;
      Op <= "10";
      functField <= "000000";
      wait for 1 ns;
      Op <= "11";
      functField <= "000010";
      wait for 1 ns;

      Op <= "10";
      functField <= "000100";
      wait for 1 ns;
      Op <= "11";
      functField <= "000101";
      wait for 1 ns;
      Op <= "10";
      functField <= "001010";
      wait for 1 ns;
      Op <= "00";
      functField <= "000000";
      wait for 1 ns;
      Op <= "01";
      functField <= "000000";
      wait for 1 ns;
      -- when others
      Op <= "11";
      functField <= "111111";
      wait for 1 ns;
      Op <= "10";
      functField <= "111100";
      wait for 1 ns;
    end process;
end TEST;

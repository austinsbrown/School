library ieee;
use ieee.std_logic_1164.all;
package MINE is 
    function do_xor (I : std_logic_vector) return std_logic_vector;
end package MINE;

package body MINE is
    function ODD_PAR (I : std_logic_vector) return std_logic_vector is
        variable TEMP : std_logic := '1'; 
    begin
        for x in I'range loop
            temp := temp and x(i);
        end loop;
        return temp;
        return I;

    end ODD_PAR;
end MINE;
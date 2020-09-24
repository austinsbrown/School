//- bin_to_ascii Module----------------------------------------
// simple 4-bit binary to 8-bit ASCII code
// code should convert from the 4-bit code coming from the
// keypad interface into an 8-bit ASCII code that has the same
// symbol that is on the corresponding key of the keypad
// Input: 
//    I[3:0] -- 4-bit input value
//    O[7:0] -- 8-bit ASCII Code that corresponds to key
//

module bin_to_ascii(output reg [7:0] O,input [3:0] I);
   
   always @ (I)
         case (I)
         //input        ASCII output
         //value        value
         0     :    O <= 8'h30;
         1     :    O <= 8'h31;
         2     :    O <= 8'h32;
         3     :    O <= 8'h33;
         4     :    O <= 8'h34;
         5     :    O <= 8'h35;
         6     :    O <= 8'h36;
         7     :    O <= 8'h37;
         8     :    O <= 8'h38;
         9     :    O <= 8'h39;
         10    :    O <= 8'h41;
         11    :    O <= 8'h42;
         12    :    O <= 8'h43;
         13    :    O <= 8'h44;
         14    :    O <= 8'h45;
         15    :    O <= 8'h46;
   endcase
endmodule

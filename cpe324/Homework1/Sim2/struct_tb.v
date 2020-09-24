`timescale 1ns/100 ps
`include "struct.v"

module struct_tb();
wire OUT;
reg A, B, clk = 0;

struct uut
(
    .OUT(OUT),
    .A(A),
    .B(B),
    .clk(clk)
);

initial
begin

    $dumpfile("dump.vcd");
    $dumpvars(0, struct_tb);

    A = 0;                                      // add 0 and 0
    B = 0;
    #10;

    A = 1;                                      // add 1 and 0
    B = 0;
    #10;

    A = 0;                                      // add 0 and 1
    B = 1;
    #10;

    A = 1;                                      // test transition to carry state
    B = 1;
    #10;

    A = 1;                                      // test staying in carry state
    B = 0;
    #10;

    A = 1;
    B = 1;
    #10;

    A = 0;                                      // test exiting from the carry state
    B = 0;
    #10;

    A = 1;
    B = 0;
    #10;

    A = 0;
    B = 0;
    #10;

end

always
    #5  clk = ! clk; 

initial 
    #100  $finish; 

endmodule
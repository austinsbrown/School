`timescale 1s/100ms
`include "mealy.v"

module mealy_tb();
wire OUT, STATE;
reg A, B;

mealy uut
(
    .OUT(OUT),
    .STATE(STATE),
    .A(A),
    .B(B)
);

initial
begin

    $dumpfile("dump.vcd");
    $dumpvars(0, mealy_tb);

    A = 0;                                      // add 0 and 0
    B = 0;
    #1;

    A = 1;                                      // add 1 and 0
    B = 0;
    #1;

    A = 0;                                      // add 0 and 1
    B = 1;
    #1;

    A = 1;                                      // test transition to carry state
    B = 1;
    #1;

    A = 1;                                      // test staying in carry state
    B = 0;
    #1;

    A = 1;
    B = 1;
    #1;

    A = 0;                                      // test exiting from the carry state
    B = 0;
    #1;

    A = 1;
    B = 0;
    #1;

    A = 0;
    B = 0;
    #1;

end
endmodule
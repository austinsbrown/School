interface req_if(input bit clk); // create interface for ease of use
    int REQ_TIME0, REQ_TIME1, REQ_TIME2, REQ_TIME3;
    logic [3:0] GEN_REQ, REQUEST, GRANT;
    logic RESET;
	
	clocking cb @(posedge clk); // these inputs and outputs are clocked
        input REQUEST;
        output GEN_REQ, RESET; 
        output REQ_TIME0, REQ_TIME1, REQ_TIME2, REQ_TIME3;
	endclocking

	modport TEST (clocking cb);
endinterface

module top;
    bit clk;
    always #5 clk = ~clk;

	req_if reqif(clk);

    arbiter A // instantiation for arbiter
    (
        .CLK(clk),
        .REQ(reqif.REQUEST),
        .GRANT(reqif.GRANT),
        .RESET(reqif.RESET)
    );

    // instantiate all of the tests
    REQ_DEV dut0
    (
        .CLK      (clk),
        .GEN_REQ (reqif.GEN_REQ[0]),
        .REQ_TIME (reqif.REQ_TIME0),
        .REQUEST  (reqif.REQUEST[0]),
        .GRANT    (reqif.GRANT[0]),
        .RESET    (reqif.RESET)
    );

    REQ_DEV dut1
    (
        .GEN_REQ (reqif.GEN_REQ[1]),
        .REQ_TIME (reqif.REQ_TIME1),
        .REQUEST  (reqif.REQUEST[1]),
        .GRANT    (reqif.GRANT[1]),
        .RESET    (reqif.RESET),
        .CLK      (clk)
    );

    REQ_DEV dut2
    (
        .GEN_REQ (reqif.GEN_REQ[2]),
        .REQ_TIME (reqif.REQ_TIME2),
        .REQUEST  (reqif.REQUEST[2]),
        .GRANT    (reqif.GRANT[2]),
        .RESET    (reqif.RESET),
        .CLK      (clk)
    );

    REQ_DEV dut3
    (
        .GEN_REQ (reqif.GEN_REQ[3]),
        .REQ_TIME (reqif.REQ_TIME3),
        .REQUEST  (reqif.REQUEST[3]),
        .GRANT    (reqif.GRANT[3]),
        .RESET    (reqif.RESET),
        .CLK      (clk)
    );


    test0 t0(reqif); 
    test1 t1(reqif);
    test2 t2(reqif);
    test3 t3(reqif);

    reset_test resetTest(reqif); // generate resets at random


endmodule : top

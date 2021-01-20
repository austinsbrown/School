interface alarm_if(input bit clk); 
    int clk, fs, ms, r, c, fm, mm;
	
	clocking cb @(posedge clk); 
        input fs, ms, r, c;
        output fm, mm;
	endclocking

	modport TEST (clocking cb);
endinterface

module top;
    bit clk;
    always #5 clk = ~clk;

    test t0(alram_if); 
endmodule : top;
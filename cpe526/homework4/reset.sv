import mine::*;
module reset_test(req_if.TEST reqif);
    int seed = 300;
    Packet p;

    initial begin
        repeat(200)
        begin
            p = new();
            p.randomize();
            //reqif.cb.RESET <= 1'b0; // make reset low by default
            
            repeat (p.rst_low) @(reqif.cb);      // delay until reset
            reqif.cb.RESET <= 1'b1;              // reset goes high
            repeat (p.rst_high) @(reqif.cb);     // length of reset
            reqif.cb.RESET <= 1'b0;
        end
    end
endmodule : reset_test

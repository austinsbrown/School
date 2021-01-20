import mine::*;
module test0(req_if.TEST reqif);
  int seed = 300;
  Packet p;

  initial begin
    repeat(200)
    begin
        p = new();
        p.randomize();

	    reqif.cb.GEN_REQ[0] <= 1'b0;
        repeat (p.req_low) @(reqif.cb); // wait a random number of cycles
        reqif.cb.REQ_TIME0 <= p.req_high; // how long that the request is high
        @(reqif.cb);
        reqif.cb.GEN_REQ[0] <= 1'b1; // go to fill state
        @(posedge reqif.cb.REQUEST);
            reqif.cb.GEN_REQ[0] <= 1'b0;  // set Gen_REQ to low
    end
    $stop;
  end
endmodule : test0	

module test1(req_if.TEST reqif);
    int seed = 300;
    Packet p;

    initial begin
        repeat(200)
        begin
            p = new();
            p.randomize();
	        p.randomize();

	        reqif.cb.GEN_REQ[1] <= 1'b0;
            repeat (p.req_low) @(reqif.cb);     
            reqif.cb.REQ_TIME1 <= p.req_high;     
            @(reqif.cb);
            reqif.cb.GEN_REQ[1] <= 1'b1;           
            @(posedge reqif.cb.REQUEST);
            reqif.cb.GEN_REQ[1] <= 1'b0;
        end
        $stop;
    end
endmodule : test1

module test2(req_if.TEST reqif);
    int seed = 300;
    Packet p;

    initial begin
        repeat(200)
        begin
            p = new();
            p.randomize();
            p.randomize();
            p.randomize();

	        reqif.cb.GEN_REQ[2] <= 1'b0;
            repeat (p.req_low) @(reqif.cb);      // wait for random # of cycles
	        reqif.cb.REQ_TIME2 <= p.req_high;     // length that request is high
	        @(reqif.cb);
	        reqif.cb.GEN_REQ[2] <= 1'b1;            // assert start - go to fill state
	        @(posedge reqif.cb.REQUEST);
            reqif.cb.GEN_REQ[2] <= 1'b0;
      
        end
        $stop;
    end
endmodule : test2

module test3(req_if.TEST reqif);
    int seed = 300;
    Packet p;

    initial begin
        repeat(200)
        begin
            p = new();
            p.randomize();
            p.randomize();
            p.randomize();
            p.randomize();

	        reqif.cb.GEN_REQ[3] <= 1'b0;
            repeat (p.req_low) @(reqif.cb);      
            reqif.cb.REQ_TIME3 <= p.req_high;    
            @(reqif.cb);
            reqif.cb.GEN_REQ[3] <= 1'b1;           
            @(posedge reqif.cb.REQUEST);
            reqif.cb.GEN_REQ[3] <= 1'b0;
     
        end
        $stop;
    end
endmodule : test3

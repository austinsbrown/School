module test(alarm_if)
    repeat(500)
    begin
        p = new();
        p.randomize();

	    @(posedge alarm_if.clk);
            alarm_if.cb.reset <= 1'b1; // assert for cycle

        @(posedge alarm_if.clk);
            alarm_if.cb.reset <= 1'b0;  // deasert

        repeat (p.frontgate_t) @(alarm_if.cb); // wait random number of cycles
        alarm_if.cb.frontgate_t <= 1'b1;
        repeat (p.request_t) @(alarm_if.cb); // wait random number of cycles
        repeat (alarm_if.fm) @(alarm_if.cb);
    end
    $stop;
  end
endmodule : test;
module struct(OUT, A, B, clk);
  input A, B, clk;
  output OUT;
  wire cout, qt_bar;

  FullAdder   C1(OUT, cout, A, B, qt);
  d_ff        C2(qt, qt_bar, cout, clk);

endmodule 

module FullAdder(SUM, C_OUT, A, B, C_IN);
  output SUM, C_OUT;
  input A, B, C_IN;
  wire w1, w2, w3;

  xor   (SUM, A, B);
  and   (w2, A, B);
  and   (w1, w2, C_IN);
  and   (w3, w2, A);
  or    (w2, w2, w3);
endmodule 


module d_ff(output qt, output qt_bar, input d, input clk);

  wire qt, qt_bar;
  wire d, clk;
  
  wire w1, w2, w3;

  nand    (w1, d, clk);
  not     (w2, d);
  nand    (w3, w2, clk);

  nand    (qt, w1, qt_bar);
  nand    (qt_bar, qt, w3);
endmodule 

// Behavioral Representation of Adder/Subtractor Module
// presented in Part II of Laboratory 2 Assignment
// B. Earl Wells -- University of Alabama Huntsville, 2017
// Single -- Top-Level Module
module Lab2B(D_S,B_COUT,A,B,B_CIN,SUB_ADD);
   output reg [7:0] D_S;
   output reg B_COUT;
   input [7:0] A,B;
   input B_CIN,SUB_ADD;

   reg [8:0] Cbuf;
	
   always @(A or B or B_CIN or SUB_ADD) begin
      if (SUB_ADD) begin
         Cbuf = A - B - B_CIN;
      end
      else begin
         Cbuf = A + B + B_CIN;
      end
      D_S = Cbuf[7:0];
      B_COUT = Cbuf[8];
   end
	 
endmodule

// lab7 Template
// Waveform Generation using Pulse Density Modulation

`timescale 1ns/1ps


module Lab7_Part_a (input clk,  input [7:0] vol, output reg d_bit);


//   reg en;
	reg signed [1:-14] wave_out;

   // 16 bit signed integer 50 point
	// lookup table for wave function	
   reg signed [1:-14] out_table[0:100035];

	initial
	   begin:wave_table_init
		
		$readmemh("uah_fight_song_8_offset.txt", out_table);
		
		end

   always @(posedge clk)
      begin:Audio_Out
		   // declaring local variables to
			// named section clock_en
			reg[18:0] index;
	      reg [19:0] count;
			reg [19:0] base_count;
			
 			base_count = 6250;
			if (count)
				begin
				count = count - 20'd1;
				end
			else
				begin
				count = base_count;	
				if (index>=17'd100036) index = 6'd0;
				else index = index + 6'd1;
				// for 16-bit audio recording
//				wave_out = out_table[index];

				// for 8-bit audio recording
				wave_out[1:-6] = out_table[index];
				end
		end
				
   always @ (posedge clk)
      begin:DtoA_convert
		   // declaring local variable to
			// named section DtoA_convert
         reg signed [3:-28] ge; // error term	
			
	      pdm(d_bit, wave_out,{2'b00,vol,6'd0},ge);
		end

	        
   // Pulse Density Modulation Task
   task pdm(output d_out, input signed [1:-14] x, scale, 
	   inout signed [3:-28] ge);
		
      // 32-bit fixed point encoding of 1.0 assuming a
      // signed 3 bit mantisa and a 28 bit fraction
      `define ONE_32 {1'b0,3'b001,28'b0} 

      // 32 bit fixed-point holder of x * scale data
      reg signed [3:-28] x_total; 

      begin

      x_total = x*scale; // signal multiplication		

      if (x_total >= ge)
         begin
         d_out = 1;
         ge = ge + (`ONE_32 - x_total);
         end
      else
         begin
         d_out = 0;
         ge = ge - (`ONE_32 + x_total); 
         end
      end
   endtask
	
endmodule	
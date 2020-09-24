module mealy(A, B, OUT, STATE);

    input A, B;                                                 // inputs to add             
    output reg OUT;                                             // sum of the inputs
    output reg CARRY = 0;                                       // carry bit
    output reg STATE = 0;                                       // current state

    always @(A or B)
    begin
        if (A == 1 & B == 1)                                    // if A and B are one 
        begin
            OUT = CARRY + A + B;                                // sum everything up
            CARRY = 1;                                          // carry bit is now 1
            STATE = 1;                                          // state bit is now one
        end

        else if(A == 0 & B == 0)                                // if A and B are both 0
        begin
            OUT = CARRY + A + B;                                // handle the carry
            CARRY = 0;                                          // set carry bit to 0
            STATE = 0;                                          // go to state 0
        end

        else
        begin
            OUT = A + B + CARRY;                                // sum everything up
        end
    end

endmodule 

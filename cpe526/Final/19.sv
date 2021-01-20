package mine;
    class something;
        rand bit clk;
        rand bit reset;
        rand bit [4:0] src1;
        rand bit [4:0] src2;
        rand bit [31:0] imm;
        rand bit [2:0] operation;
        rand bit immp_regn;
        rand bit [31:0] mem_data_read_in;
        rand bit [31:0] ALUOut;
        rand bit carry;

        constraint c
        {
            Src1 dist
            {
                [5'b00010] : [5'b00000] :/40,
                [5'b10111] :/10,
                [5'b11111] : [5'b11000] :/50,
                [5'b10110] : [5'b00011] :/50;
            }
        }
    endclass : something

endpackage : mine

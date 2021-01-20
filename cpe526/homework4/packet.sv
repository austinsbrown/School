package mine;
    class Packet;
    
        rand int req_low, req_high, rst_low, rst_high; // delcare the random variable
        constraint c 
        {
            req_low < 299; req_low > 101;
            req_high < 100; req_high > 1;
            rst_low < 499; rst_low > 301;
            rst_high > 4; rst_high < 9;
        } 
    endclass : Packet
endpackage : mine

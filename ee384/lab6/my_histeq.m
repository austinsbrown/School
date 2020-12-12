function final = my_histeq(A, L)
    FreqPix = imhist(A);
    Cumhist = cumsum(FreqPix);
    CDFPix = Cumhist/L;
    Valrep = CDFPix(double(A)+1);
    final = uint8(Valrep);
end
function [demod, b, a] = my_amdemod(ym, carrier, fx, fc, fs)
    wp = (2*fx)/fs;
    ws = (2*fc)/fs;
    Rp = 3;
    Rs = 40;
    
    demod = ym .*carrier;
    
    [Ord, Wn] = buttord(wp, ws, Rp, Rs);
    [b,a] = butter(Ord, Wn, 'low');
end
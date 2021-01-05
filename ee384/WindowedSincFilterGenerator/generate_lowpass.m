function h = generate_lowpass(fs, fc, b)
    fc = fc/fs;                                                        
    N = ceil(4/b);
    n = 1:N;
    h = sinc(2*fc*(n-(N-1)/2));                                          
    w = 0.42-0.5*cos(2*pi*n/(N-1)) + 0.08*cos(4*pi*n(N-1));               
    h = h.*w;
    
    h = h/sum(h);
end
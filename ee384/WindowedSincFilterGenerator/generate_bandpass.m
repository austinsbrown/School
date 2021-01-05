function h = generate_bandpass(fs, fl, fh, b)
    fl = fl/fs;
    fh = fh/fs;
    
    N = ceil(4/b);
    n = 1:N;
    
    hlpf = sinc(2*fh*(n-(N-1)/2));
    w = 0.42-0.5*cos(2*pi*n/(N-1)) + 0.08*cos(4*pi*n(N-1));
    hlpf = hlpf.*w;
    hlpf = hlpf/sum(hlpf);
    
    hhpf = sinc(2*fl*(n-(N-1)/2));
    hhpf = hhpf.*w;
    hhpf = hhpf/sum(hhpf);
    hhpf = hhpf*-1;
    hhpf(ceil(end/2)) = hhpf(ceil(end/2))+1;
    
    h = convolute(hlpf, hhpf);
end
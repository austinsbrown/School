function h = generate_highpass(fs, fc, b)
    fc = fc / fs;
    N = ceil(4/b);
    n = 1:N;
    h = sinc(2*fc*(n-(N-1)/2));                                            % compute sinc filter
    w = 0.42-0.5*cos(2*pi*n/(N-1)) + 0.08*cos(4*pi*n(N-1));                % compute blackman window  

    h = h.*w;
    h = h/sum(h);

    h = h.*-1;                                                             % convert to highpass filter
    h(ceil(end/2)) = h(ceil(end/2)) + 1;
end
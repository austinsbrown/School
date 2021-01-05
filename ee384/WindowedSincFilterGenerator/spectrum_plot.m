function spectrum_plot(y, fs)
    l = length(y);
    n = pow2(nextpow2(l));
    y_dft = fft(y, n);
    y_s = fftshift(y_dft);
    f = (-n/2:n/2-1)*(fs/n);
    plot(f, abs(y_s)/n);
end
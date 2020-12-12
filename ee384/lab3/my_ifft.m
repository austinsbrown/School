function y = my_ifft(x)
    N = length(x);
    W = exp(-1i*(2*pi/N));
    y = zeros(1, N);
    
    for n = 0:N-1
        for k = 0:N-1
            y(n+1) = real(y(n+1) + (1/N)*(x(k+1) * W^(-k*n)));
        end
    end
end
function y = convolution(x, h)
    y = zeros(1,length(x) + length(h));
    for i = 1:length(x)
        for j = 1:length(h)
            y(i+j) = y(i+j) + x(i) * h(j);
        end
    end
        
end
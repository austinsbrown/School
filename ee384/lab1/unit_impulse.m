function [x,y] = unit_impulse(n_p, n1, n2)
    x = n1:1:n2;
    for i = 1:length(x)
        if x(i) == n_p
            y(i) = 1;
        else
            y(i) = 0;
        end
    end
end
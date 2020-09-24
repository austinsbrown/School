function G = my_grayscale(a)
    G = 0.3*a(:,:,1) + 0.6*a(:,:,2) + 0.1*a(:,:,3);
end
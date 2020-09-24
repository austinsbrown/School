syms t                                              % declare symbols

a = 5*exp(-2*t)*cos(8*t)*heaviside(t);              % set a to function 1
b = 5*exp(-2*t)*cos(8*t)*heaviside(t);              % set b to function 2

x1lplace = laplace(a);                              % find the laplace
x2laplace = laplace(b);

figure                                              % generate graph of a
hold on
title('Poles and Zeroes of a')
splane([5 10], [1 4 68])
saveas(gcf, 'problem5a.png')
hold off

figure                                              % generate graph of b
hold on
title('Poles and Zeroes of b')
splane([5 20], [1 8 80])
saveas(gcf, 'problem5b.png')
hold off
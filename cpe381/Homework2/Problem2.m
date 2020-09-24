f = 400;                                            % frequency
fs = 11025;                                         % sampling frequncy
ts = 1/11015;                               
t = 0:ts:1;                                         % time array

x = exp(-t) .* sin(2 * pi * f * t);                 % x values

X1 = exp(-t) .* sin(2 * pi * f * (t - 0.2));        % first function
X2 = exp(-t) .* sin(2 * pi * f * (t - 0.4));        % second function

y = x + .4 * X1 + 0.2 * X2;                         % main function

subplot(211)                                        % plot the function
plot(t,y)
title('x(t)')
subplot(212)
plot(t,y)
title('y(t)')
saveas(gcf, 'problem2.png')

sound(y)                                            % generate a sound
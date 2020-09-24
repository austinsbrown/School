t = 0:.05:2;
a = 4;
f = 2;

y = a * exp(-1 * t) .* cos(t * pi * f);

stem(t, y)
grid
xlabel('time (seconds)')
ylabel('f(x)')

saveas(gcf,'dampedSinusoid.png')
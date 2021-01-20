threads = [1 2 4 8 16 32 64];
timeS = [.00143 .00199 .00143 .00199 .00222 .003020 .0036600];
timeP = [.0035 .00157 .0016 .00214 .00308 .00224 .00335];

hold on
plot(threads, timeS);
plot(threads, timeP);
hold off
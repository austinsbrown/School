interval = [1000, 10000, 100000];
timeP = [.0002335, .000697, .0030532];
timeS = [.000504, .0005179, .005281];
hold on
plot(interval, timeP);
plot(interval, timeS);
xlabel('Intervals')
ylabel('Time')
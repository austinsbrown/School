%% 1.1, 1.2, 1.3
x = load('SAMPLE_ECG.mat');
x = x.ECG_Data;

windowSize = 3; 
h = (1/windowSize)*ones(1,windowSize);
a = 1;

y = filter(h,a,x);

figure
subplot(2,1,1)
plot(x)
axis([0 2000 100 220])
title('Unfiltered')

subplot(2,1,2)
plot(y)
axis([0 2000 100 220])
title('Filtered')
sgtitle('Problem 1.1')

h = [1/3, 1/3, 1/3];
yc = conv(x, h);

figure
subplot(2,1,1)
plot(y)
axis([0 2000 100 220])
title('Filter Function')

subplot(2,1,2)
plot(yc)
axis([0 2000 100 220])
title('Convolution')
sgtitle('Problem 1.2')

yf = convolution(x, h);

figure
subplot(2,1,1)
plot(y)
axis([0 2000 100 220])
title('Built In Convolution Function')

subplot(2,1,2)
plot(yc)
axis([0 2000 100 220])
title('My Convolution Function')
sgtitle('Problem 1.3')

%% 2
fs = 50;
t = 0:1/fs:1;
f1 = 10;
f2 = 60;

y1 = sin(2*pi*f1.*t);
y2 = sin(2*pi*f2.*t);

figure
subplot(2,1,1)
plot(t, y1)
title('10 Hz Rate')
grid('on')

subplot(2,1,2)
plot(t, y2, 'r')
title('60 Hz Rate')
grid('on')
sgtitle('Problem 2')

% The plots are slightly different because they have different frequncies

%% 3.1
fs = 50000;
f = 2000;
t = 0:1/fs:1;

y = sin(2*pi*f*t);

figure
plot(t, y)
xlim([0,.1])
title('Problem 3.1'), xlabel('Time'), ylabel('Output')
sound(y, fs)

%% 3.2
fs = 50000;
f = 6000;
t = 0:1/fs:1;

y = sin(2*pi*f*t);

figure
plot(t, y)
xlim([0,.1])
title('Problem 3.2'), xlabel('Time'), ylabel('Output')
sound(y, fs)

% The sound is higher pitched

%% 3.3
fs = 50000;
f = 25000;
t = 0:1/fs:1;

y = sin(2*pi*f*t);

figure
plot(t, y)
xlim([0,.1])
title('Problem 3.3'), xlabel('Time'), ylabel('Output')
sound(y, fs)

% I can no longer hear the sound
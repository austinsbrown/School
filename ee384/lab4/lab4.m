%% 1
fs = 8000;
t = 0:1/fs:0.05;
f1 = 1206;
f2 = 1336;

y = cos(2*pi*f1*t) + cos(2*pi*f2*t);

figure
sgtitle('1.1')
subplot(2,1,1)
plot(t,y)
title('Time Domain'), xlabel('Time'), ylabel('Output')

subplot(2,1,2)
spectrum_plot(y, fs)
title('Frequency Domain'), xlabel('Frequency'), ylabel('Output')

% part b
Wp = (2*f1)/fs;
Ws = (2*f2)/fs;
Rp = 3;
Rs = 40;

[Ord, Wn] = buttord(Wp, Ws, Rp, Rs);
[b,a] = butter(Ord, Wn, 'low');
yf = filter(b, a, y);

figure
sgtitle('1.2')
subplot(2,1,1)
plot(t,yf)
title('Time Domain'), xlabel('Time'), ylabel('Output')

subplot(2,1,2)
spectrum_plot(yf, fs)
title('Frequency Domain'), xlabel('Frequency'), ylabel('Output')

figure
n = 512;
freqz(b, a, n, fs);
title('1.2')

% part c

Wp = (2*f2)/fs;
Ws = (2*f1)/fs;
Rp = 3;
Rs = 40;

[Ord, Wn] = buttord(Wp, Ws, Rp, Rs);
[b,a] = butter(Ord, Wn, 'high');
yf = filter(b, a, y);

figure
sgtitle('1.3')
subplot(2,1,1)
plot(t,yf)
title('Time Domain'), xlabel('Time'), ylabel('Output')

subplot(2,1,2)
spectrum_plot(yf, fs)
title('Frequency Domain'), xlabel('Frequency'), ylabel('Output')

figure
n = 512;
freqz(b, a, n, fs);
title('1.3 Response')

% part d


Wp = [1150, 1250];
Ws = [1100, 1290];
Wp = (2.*Wp)/fs;
Ws = (2.*Ws)/fs;

Rp = 3;
Rs = 40;

[Ord, Wn] = buttord(Wp, Ws, Rp, Rs);
[b,a] = butter(Ord, Wn, 'bandpass');
yf = filter(b, a, y);

figure
sgtitle('1.4')
subplot(2,1,1)
plot(t, yf)
title('Time Domain'), xlabel('Time'), ylabel('Output')

subplot(2,1,2)
spectrum_plot(yf, fs)
title('Frequncy Domain'), xlabel('Hz')

figure
n = 512;
freqz(b, a, n, fs);
title('1.4 Response')
%% 2
x = load('SAMPLE_ECG.mat');
x = x.ECG_Data;
fs = 512;
t = 0:1/fs:(length(x)-1) / fs;

figure
sgtitle('2.1 and 2.2')
subplot(2,1,1)
plot(t, x)
title('Time Domain'), xlabel('Time in Seconds'), ylabel('ECG Output')

subplot(2,1,2)
spectrum_plot(x, fs)
title('Frequency Domain'), xlabel('Frequency'), ylabel('Output')

Wp = (2*.5)/fs;
Ws = (2*.2)/fs;
Rp = 3;
Rs = 40;

[Ord, Wn] = buttord(Wp, Ws, Rp, Rs);
[b,a] = butter(Ord, Wn, 'high');
yf = filter(b, a, x);

figure
sgtitle('2.3')
subplot(2,1,1)
plot(t, yf)
title('Time Domain'), xlabel('Time in Seconds'), ylabel('ECG Output')

subplot(2,1,2)
spectrum_plot(yf, fs)
title('Frequency Domain'), xlabel('Frequency'), ylabel('Output')

%% 3
fs = 500;
t = 0:1/fs:1;
y = sin(2*pi*t*10);

figure 
plot(t, y)
title('3.1'), xlabel('Time'), ylabel('Message Signal')
 
% part b

c = sin(2*pi*t*100);
ym = my_ammod(y, c);

figure
plot(t, ym)
title(3.2), xlabel('Time'), ylabel('Modulated Signal')

% part c

figure
sgtitle('3.3')
subplot(2,1,1)
spectrum_plot(y, fs)
title('Message Signal'), xlabel('Frequency')

subplot(2,1,2)
spectrum_plot(ym, fs)
title('Modulated Signal'), xlabel('Frequency')

% The modulated signal has to frequency components. 
% It has one for the carrier and one for the message.

% part d

fx = 10;
fc = 100;

[demod, b, a] = my_amdemod(ym, c, fx, fc, fs);
yf = filter(b, a, demod);

figure
sgtitle('3.4')
subplot(2,1,1)
plot(t, yf)
title('Time Domain'), xlabel('Time in Seconds'), ylabel('ECG Output')

subplot(2,1,2)
spectrum_plot(yf, fs)
title('Frequency Domain'), xlabel('Frequency'), ylabel('Output')

figure
hold on
plot(t, y), plot(t,yf)
xlabel('Time'), ylabel('Output'), title('Original Signal and Decoded Signal')
legend('Original', 'Recieved')
hold off

figure
hold on
spectrum_plot(y, fs), spectrum_plot(yf, fs)
xlabel('Time'), ylabel('Output'), title('Spectrum of Original and Decoded Signal')
legend('Original', 'Recieved')
hold off

figure
n = 512;
freqz(b, a, n, fs);
title('3.4 Response')







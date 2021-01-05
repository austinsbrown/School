close all; clear;

fs = 25000;
t = 0:1/fs:0.05;
f1 = 1000;
f2 = 5000;

x = cos(2*pi*f1*t) + cos(2*pi*f2*t);

figure
spectrum_plot(x, fs)
title('Spectrum of Original Signal')
ylabel('Magnitude'), xlabel('Frequncy')

h = csvread('filter.csv');
y = convolute(x, h);

figure
spectrum_plot(y, fs)
title('Spectrum of Filtered Signal')
ylabel('Magnitude'), xlabel('Frequncy')
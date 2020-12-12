%% 1.1
x = [1,2,3,4,5,6,7,8];
X = fft(x);

figure
plot(abs(X))
title('1.1'), xlabel('Sample'), ylabel('DFT Values')
%% 1.2
x = ifft(X);
figure
plot(abs(x))
title('1.2'), xlabel('Sample'), ylabel('Inverse DFT')

%% 1.3
x = [1,2,3,4,5,6,7,8];

X = my_fft(x);
y = my_ifft(X);
plot(x, y)
title('1.3'), xlabel('Sample'), ylabel('Inverse DFT')

%% 2
fs = 8000;
f1 = 697;
f2 = 1209;
dt = 1/fs;
t = 0:dt:1-dt;

y = sin(2*pi*f1*t) + sin(2*pi*f2*t);

figure
plot(t, y)
title('2.1'), xlabel('sample'), ylabel('signal') 

y_psd = periodogram(y);
plot(10*log10(y_psd));
title('2.2'), xlabel('frequncy'), ylabel('db')
text(697, 10*log10(y_psd(697)), '697 Hz \rightarrow', 'HorizontalAlignment', 'right')
text(1209, 10*log10(y_psd(697)), '1209 Hz \rightarrow', 'HorizontalAlignment', 'right')

l = length(y);
n = pow2(nextpow2(l));
y_dft = fft(y, n);
y_s = fftshift(y_dft);
f = (-n/2:n/2-1)*(fs/n);

figure
plot(f, abs(y_s)/n);
title('2.4'), xlabel('Hz')



















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
%y = my_ifft(X);
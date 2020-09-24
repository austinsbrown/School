clear all;

x=wavread('/home/berocs/Documents/MATLAB/bero_christopher-csb_mod.wav');

Fs=44100;
%t = 0:1/Fs:1-(1/Fs);

%x=14*cos(200*pi*t-pi/3);
xdft=(1/length(x))*fft(x);

fsx=(Fs/length(x));

freq=-(length(x)/2):fsx:(length(x)/2)-(fsx);

spectrum=abs(fftshift(xdft));

%plot(freq,spectrum);



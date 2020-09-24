function [w,Hm,Ha]=freqresp_s(b,a,wmax) 
w=0:0.01:wmax; 
H=freqs(b,a,w); 
Hm=abs(H); 
Ha=angle(H)*180/pi; 
figure 
subplot(311) 
plot(w,Hm) 
subplot(312) 
plot(w,Ha) 
subplot(313) 
splane(b,a) 
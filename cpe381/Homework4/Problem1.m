num=[1 -3 3+pi^2 -(1+pi^2)]; 
den=[1 3 3+pi^2 (1+pi^2)];  
w=20; 
freqresp_s(num,den,w); 
num1=[0 1 0 pi^2]; 
den1=den;  
freqresp_s(num1,den1,w); 
num2=[0 0 1 -1]; 
den2=den;  
freqresp_s(num2,den2,w); 
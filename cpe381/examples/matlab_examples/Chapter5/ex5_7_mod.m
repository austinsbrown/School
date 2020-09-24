% Example 5.7
%clear all;clf
syms t w 
ind=input('part 1 or 2?   ')
if ind==1.
    %y1=exp(-abs(t))
    %y1=y1*0.5*exp(-j*10*t)+y1*0.5*exp(j*10*t)
    y1=mod;
    Y1=fft(y1);
    
    figure(1)
    
    subplot(221)
    plot(y1,[-6,6]);
    grid;
    axis([-6 6 -1.2 1.2]); 
    title(' '); xlabel('t'); ylabel('y_1(t)')
    
    subplot(223)
    ezplot(abs(Y1),[-20,20]); 
    grid; 
    axis([-20 20 -0.1 1.5]);
    title(' '); xlabel('\Omega'); ylabel('|Y_1(\Omega)|')
    
    subplot(224)
    ezplot(atan(imag(Y1)/real(Y1)),[-20,20]); 
    grid; 
    title(' '); xlabel('\Omega'); ylabel('<Y_1(\Omega)')
    axis([-20 20 -1.5 1.5]);
    %xlabel('\Omega')
else
    m=heaviside(t+5)-heaviside(t)
    m1=heaviside(t)-heaviside(t-5);
    x2=(t+5)*m+m1*(-t+5);x2=x2/5;
    x=x2*exp(-j*10*t)/2;
    y=x2*exp(+j*10*t)/2;
    Y=Afourier(y,5)
    X=Afourier(x,5)
    X2=Afourier(x2,5)

    figure(2)
    subplot(221)
    ezplot(x2,[-6,6]);grid;axis([-6 6 -0.2 1.2]); title(' '); xlabel('t'); ylabel('x_2(t)')
    subplot(222)
    ezplot(x+y,[-6,6]);grid;axis([-6 6 -1.2 1.2]); title(' '); xlabel('t'); ylabel('y_2(t)=x_2(t) \cos(10t)')
    subplot(223)
    ezplot(abs(X2),[-8,8]); grid; axis([-8 8 -0.1 5.5]); title(' ')
    xlabel('\Omega'); ylabel('|X_2(\Omega)')
    subplot(224)
    ezplot(abs(X)+abs(Y),[-20,20]); grid; axis([-20 20 -0.1 5.5]); title(' ')
    xlabel('\Omega'); ; ylabel('|Y_2(\Omega)')
end
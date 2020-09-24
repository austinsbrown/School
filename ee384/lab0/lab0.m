%% Problem 1.1
a = [2; 5; 8];
b = [3; 13; 8;];

a + b
%a * b produces an error due invalid dim.
a .* b

%% Problem 1.2
a = [1,2,-3; 2,1,2; 4,-2,1;];
b = [3; 13; 8;];

a + b
a * b
a .* b
%% problem 2
ta = 0:1:50;
tb = 0:.01:50;

y1a = cos(ta);
y1b = sin(ta);
y2a = cos(tb);
y2b = sin(tb);

figure
plot(ta, y1a)
hold on
plot(ta, y1b)
title('Part 1')
xlabel('x axis') 
ylabel('Sine and Cosine Values') 
legend({'y = sin(x)','y = cos(x)'})
hold off

figure
plot(tb, y2a)
hold on
plot(tb, y2b)
title('Part 2')
xlabel('x axis') 
ylabel('Sine and Cosine Values')
legend({'y = sin(x)','y = cos(x)'})
hold off

% the signals are way smoother when you increase the step
%% problem 3
%{
a0 = input('Enter the value for a (equation 0) :');
b0 = input('Enter the value for b (equation 0) :');
c0 = input('Enter the value for c (equation 0) :');
d0 = input('Enter the value for d (equation 0) :');

a1 = input('Enter the value for a (equation 1) :');
b1 = input('Enter the value for b (equation 1) :');
c1 = input('Enter the value for c (equation 1) :');
d1 = input('Enter the value for d (equation 1) :');

a2 = input('Enter the value for a (equation 2) :');
b2 = input('Enter the value for b (equation 2) :');
c2 = input('Enter the value for c (equation 2) :');
d2 = input('Enter the value for d (equation 2) :');
%}

a0 = 2;
b0 = 3;
c0 = 1;
d0 = 3;

a1 = 1;
b1 = 3;
c1 = -1;
d1 = 6;

a2 = 2;
b2 = 2;
c2 = 0;
d2 = 7;

A = [a0,b0,c0; 
     a1,b1,c1;
     a2,b2,c2;];

b = [d0; d1; d2];

AI = inv(A);
AI * b
%% problem 4
%x = input('Enter the value(s) for x: ');
%u = input('Enter the value for u: ');

x = 0:.01:1;
u = 255;

num = log(1 + u.*abs(x));
den = log(1+u);

final = (num/den).*sign(x);

figure
plot(x,final)
title('Problem 4 Plot')
xlabel('Input Values')
ylabel('Output')
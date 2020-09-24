%% 1.1
n_s = 0;
n1 = -5;
n2 = 5;

[x,y] = unit_impulse(n_s, n1, n2);                                         

figure
stem(x,y), xlabel('n'), ylabel('y(n)'), title('Unit Step')
% unit impuls code is at the bottom

%% 1.2
n_s = 0;
n1 = -5;
n2 = 5;

[x,y] = unit_step(n_s, n1, n2);                                         

figure
stem(x,y), xlabel('n'), ylabel('y(n)'), title('Unit Impulse')
% unit step code is at the bottom

%% 2.1
n = -5:.1:5;
x = sin(n);
n_d = -2;

[y, m] = time_shift(x, n, n_d);

figure
plot(n, x, m, y, 'r')
title('Shifting'), xlabel('Input'), ylabel('Output')
legend('Original', 'Shifted')

%% 2.2

n = -10:10;
x = 2*n + 3;
n_d = 3;

[y, m] = time_shift(x, n, n_d);

figure
plot(n, x, m, y, 'r', -1*n, x, 'g')
title('Problem 2.2'), xlabel('Input'), ylabel('output')
legend('Original', 'Delayed', 'Time Revesrsed')

%% 2.3
n = -10:10;

[x, y] = unit_impulse(4, min(n), max(n));
y = y .* 5;

[tx, ty] = unit_impulse(-2, min(n), max(n));
ty= ty .* 2;

y = y - ty;

figure
stem(n,y), title('Problem 2.3'), xlabel('Input'), ylabel('Output')

%% 2.4

%% 3.1
x = load('SAMPLE_ECG');
figure
plot(x.ECG_Data), title('x(n)'), xlabel('Sample Index'), ylabel('Power')

%% 3.2 and 3.3
x = load('SAMPLE_ECG');

for i = 1:length(x.ECG_Data) - 3
    y(i) = 0;
    for j=0:3
        y(i) = y(i) + x.ECG_Data(i+j);
    end
    y(i) = y(i) / 3;
end

figure
subplot(2,1,1)
plot(x.ECG_Data)
axis([0 2000 100 220])
title('x(n)')

subplot(2,1,2)
plot(y)
title('y(n)')

%% 3.4
% y(n) is smoother than x(n)

















clear
[y, fs] = audioread('Brown_A_org.wav');                                         % load audio
data = audioinfo('Brown_A_org.wav');

x = data.SampleRate*10;                                                         % get data
i=1;

while i < x+1                                                                   % load first ten seconds into array
    lessThan10(i) = y(i,1);
    i=i+1;
end

i = 1;
while x < data.TotalSamples                                                     % loa remainder into array
    greaterThan10(i) = y(x,1);
    i=i+1;
    x=x+1;
end


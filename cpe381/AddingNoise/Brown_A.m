[y,Fs] = audioread('Brown_A_org.wav');                                          % read in audio file
ten_sec = Fs*10;                                                                % find the ten second mark

for i = ten_sec:length(y)                                                       % iterate through the file and add sine noise at to seconds
    y(i,1) = 0.1*sin(2*pi*2500*(i-ten_sec)/Fs + pi/6);
    y(i,2) = 0.1*sin(2*pi*2500*(i-ten_sec)/Fs + pi/6);
end
audiowrite("Brown_A_mod_matlab.wav",y,Fs);                                      % generate a new audio file

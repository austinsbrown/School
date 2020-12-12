%% Classwork 10 - Helper
% By: Krishna Patel
% Due Date: 10/26/2020

clear all; close all; clc

PII = (6:15);
SNR = [];
for i = 1:10
    SNR(i) = MRM_plotter10();
end

figure
plot(PII, SNR, '--');
xlabel('PII from 6-15')
ylabel('SNR')
title('SNR vs PII Plot')
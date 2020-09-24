

function Line_Spectra(fk,Xk,mode,linetype)
% Line_Spectra(fk,Xk,range,linetype)
%
% Plot Two-sided Line Spectra for Real Signals
%----------------------------------------------------
% fk = vector of real sinusoid frequencies
% Xk = magnitude and phase at each positive frequency in fk
% mode = 'mag' => a magnitude plot, 'phase' => a phase
% plot in radians
% linetype = line type per MATLAB definitions
%
% Mark Wickert, September 2006; modified February 2009
if nargin < 4
linetype = 'b';
end
my_linewidth = 2.0;
switch lower(mode) % not case sensitive
case {'mag','magnitude'} % two choices work
k = 1;
if fk(k) == 0
plot([fk(k) fk(k)],[0 abs(Xk(k))],linetype,...
'LineWidth',my_linewidth);
hold on
else
Xk(k) = Xk(k)/2;
plot([fk(k) fk(k)],[0 abs(Xk(k))],linetype,...
'LineWidth',my_linewidth);
hold on
plot([-fk(k) -fk(k)],[0 abs(Xk(k))],linetype,...
'LineWidth',my_linewidth);
end
for k=2:length(fk)
if fk(k) == 0
plot([fk(k) fk(k)],[0 abs(Xk(k))],linetype,...
'LineWidth',my_linewidth);
else
Xk(k) = Xk(k)/2;
plot([fk(k) fk(k)],[0 abs(Xk(k))],linetype,...
'LineWidth',my_linewidth);
plot([-fk(k) -fk(k)],[0 abs(Xk(k))],linetype,...
'LineWidth',my_linewidth);
end
end
grid
axis([-1.2*max(fk) 1.2*max(fk) 0 1.05*max(abs(Xk))])
ylabel('Magnitude')
xlabel('Frequency (Hz)')
hold off
case 'phase'
k = 1;
if fk(k) == 0
plot([fk(k) fk(k)],[0 angle(Xk(k))],linetype,...
'LineWidth',my_linewidth);
hold on
else
plot([fk(k) fk(k)],[0 angle(Xk(k))],linetype,...
'LineWidth',my_linewidth);
plot([-fk(k) -fk(k)],[0 -angle(Xk(k))],linetype,...
'LineWidth',my_linewidth);
hold on
end
for k=2:length(fk)
if fk(k) == 0
plot([fk(k) fk(k)],[0 angle(Xk(k))],linetype,...
'LineWidth',my_linewidth);
else

plot([fk(k) fk(k)],[0 angle(Xk(k))],linetype,...
'LineWidth',my_linewidth);
plot([-fk(k) -fk(k)],[0 -angle(Xk(k))],...
linetype,'LineWidth',my_linewidth);
end
end
grid
plot(1.2*[-max(fk) max(fk)], [0 0],'k');
axis([-1.2*max(fk) 1.2*max(fk)
-1.1*max(abs(angle(Xk))) 1.1*max(abs(angle(Xk)))])
ylabel('Phase (rad)')
xlabel('Frequency (Hz)')
hold off
otherwise
error('mode must be mag or phase')
end

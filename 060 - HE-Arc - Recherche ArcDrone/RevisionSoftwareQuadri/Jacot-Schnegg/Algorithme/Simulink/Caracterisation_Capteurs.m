%% Script to plot and do few computations on data logged (Gyro & Accelerometers) 
% Developped with Matlab 2008a

%% uncomment 1 line to analyze the corresponding .mat file
%load Simulink_Dynamic_Calibration
%load Simulink_Dynamic_Calibration2
load Simulink_Dynamic_Calibration3
%load Simulink_Static
%load Simulink_Static_60s

%% extract datas
T = datas(1,:);
Gyro_y = datas(2,:);
Accel_y = datas(3,:);
Accel_z = datas(4,:);
Gyro_x = datas(5,:);
Accel_x = datas(6,:);

%% Calibration

Gyro_y = Gyro_y * 80/2048*6.55 - 18;
Gyro_x = Gyro_x * 80/2048*2.35 + 13;

Accel_y = Accel_y - 9027;
Accel_x = Accel_x - 13054;
Accel_z = Accel_z - 13632;

%% Temporal Analysis
figure(2);

subplot(2,1,1)
plot(T,Gyro_x,'.',T,Gyro_y,'.','MarkerSize',1); axis tight;
ylabel('Rate Gyro (deg/s)');
hlegend = legend('Gyro x','Gyro y')
xlabel('time (s)')
ylim([-130 130]);   % to adapt (or remove) for different set of datas

a = get(hlegend,'Children')
for i=1:length(a)
    set(a(i),'LineStyle','-')
    set(a(i),'LineWidth',2)
end

subplot(2,1,2);
plot(T,Accel_x,'.',T,Accel_y,'.',T,Accel_z,'.','MarkerSize',1); axis tight;
ylabel('Accelerometers (raw data)');
hlegend = legend('Accel x','Accel y','Accel z')
xlabel('time (s)')
ylim([-900 900]);   % to adapt (or remove) for different set of datas

a = get(hlegend,'Children')
for i=1:length(a)
    set(a(i),'LineStyle','-')
    set(a(i),'LineWidth',2)
end

%% Frequency Analysis
figure(1);
subplot(2,2,1)
Hs = spectrum.periodogram;
msspectrum(Hs,Gyro_x,'Fs',1000);
ylim([-100 10]);
ylabel('Gyro x - Power (dB)');
set(get(gca,'XLabel'),'Visible','off');

subplot(2,2,3);
Hs = spectrum.periodogram;
msspectrum(Hs,Gyro_y,'Fs',1000);
ylim([-100 10]);
ylabel('Gyro y - Power (dB)');
set(get(gca,'Title'),'Visible','off');
set(get(gca,'Children'),'Color',[0 .5 0]);

subplot(3,2,2)
Hs = spectrum.periodogram;
msspectrum(Hs,Accel_x,'Fs',1000);
ylim([-100 10]);
ylabel('Accel x (dB)');
set(get(gca,'XLabel'),'Visible','off');

subplot(3,2,4)
Hs = spectrum.periodogram;
msspectrum(Hs,Accel_y,'Fs',1000);
ylim([-100 10]);
ylabel('Accel y (dB)');
set(get(gca,'Title'),'Visible','off');
set(get(gca,'XLabel'),'Visible','off');
set(get(gca,'Children'),'Color',[0 .5 0]);

subplot(3,2,6)
Hs = spectrum.periodogram;
msspectrum(Hs,Accel_z,'Fs',1000);
ylim([-100 10]);
ylabel('Accel z (dB)');
set(get(gca,'Title'),'Visible','off');
set(get(gca,'Children'),'Color',[1 0 0]);

%% Export data
figure(1);
print('-dpng','-r200','dataSpectralAnalysis.png');
figure(2);
print('-dpng','-r200','dataTemporal.png');
break;

plot(T,Gyro_y);
hold on;
plot(T,Gyro_x,'k');
legend('Gyro y','Gyro x');
xlabel('Time (s)')
ylabel('deg/s')


%% bean
break;
fftGyro_y = fft(Gyro_y)./length(Gyro_y);
Tfft = linspace(0,1e3,length(Gyro_y));
plot(Tfft,abs(fftGyro_y));
axis tight;
xlim([0 500]);
ylim([0 .4]);



figure(2);

subplot(2,2,1)
plot(T,Gyro_y); axis tight;
ylabel('Gyro y (deg/s)');

subplot(2,2,3);
plot(T,Gyro_x); axis tight;
ylabel('Gyro x (deg/s)');
xlabel('time (s)')

subplot(3,2,2)
plot(T,Accel_x); axis tight;
ylabel('Accel x (not scaled)');

subplot(3,2,4)
plot(T,Accel_y); axis tight;
ylabel('Accel y (not scaled)');

subplot(3,2,6)
plot(T,Accel_z); axis tight;
ylabel('Accel z (not scaled)');
xlabel('time (s)')

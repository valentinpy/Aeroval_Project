
%% Load Static datas
% load RAwDatas_Static_15s.mat
% FirstIdx = find(R==55);  % find first signature byte
% R = R(FirstIdx(1):end);
%% Load Dynamic Datas
% load RawDatas_Dynamic_Calibration_40sd.mat %% start at idx 4000 (4s)
% FirstIdx = find(R==55);  % find first signature byte
% R = R(FirstIdx(3300):end);
%% Load Dynamic Datas
% load RawDatas_Dynamic_Calibration_40sa.mat %% start at idx 4000 (4s)
% FirstIdx = find(R==55);  % find first signature byte
% R = R(FirstIdx(1000):end);
%% Load Dynamic Datas
% load RawDatas_Static_60s.mat %% start at idx 4000 (4s)
% FirstIdx = find(R==55);  % find first signature byte
% R = R(FirstIdx(13000):end);
%%
load RawDatas_Dynamic_Calibration_40se.mat %% start at idx 4000 (4s)
FirstIdx = find(R==55);  % find first signature byte
R = R(FirstIdx(1):end);
%% Extract raw data
n = length(R);
n = floor(n/11);    % 11 datas for each time step

R = R(1:n*11);  % remove last uncomplete data received
R = reshape(R,11,n); % reshape : from vector to a matrix of 11 column
idxError = find(R(1,:) ~= 55)  % Check data integrity
if ~isempty(idxError)
    error('Data corrupted')
end

%% Reconstruct Raw data as received through the SPI bus
RawGyro_Y = R(2,:)*2^8 + R(3,:);
RawAccel_Y = R(4,:)*2^8 + R(5,:);
RawAccel_Z = R(6,:)*2^8 + R(7,:);
RawGyro_X = R(8,:)*2^8 + R(9,:);
RawAccel_X = R(10,:)*2^8 + R(11,:);
T = [0:.001:(length(RawGyro_Y)-1)*.001];
%%

RawGyro_Y = RawGyro_Y - 2048;
RawGyro_X = RawGyro_X - 2048;

RawAccel_X = bitand(RawAccel_X,4095);
RawAccel_Y = bitand(RawAccel_Y,4095);
RawAccel_Z = bitand(RawAccel_Z,4095);


%% filtering
F0 = 5;    %5Hz;
fftRawGyro_Y = fft(RawGyro_Y);
fftRawGyro_Y(floor(length(RawGyro_Y)*F0/1000):end) = 0;
Filter_RawGyro_Y = ifft(fftRawGyro_Y,'symmetric');

fftRawGyro_X = fft(RawGyro_X);
fftRawGyro_X(floor(length(RawGyro_X)*F0/1000):end) = 0;
Filter_RawGyro_X = ifft(fftRawGyro_X,'symmetric');

fftRawAccel_X = fft(RawAccel_X);
fftRawAccel_X(floor(length(RawAccel_X)*F0/1000):end) = 0;
Filter_RawAccel_X = ifft(fftRawAccel_X,'symmetric');

fftRawAccel_Z = fft(RawAccel_Z);
fftRawAccel_Z(floor(length(RawAccel_Z)*F0/1000):end) = 0;
Filter_RawAccel_Z = ifft(fftRawAccel_Z,'symmetric');

fftRawAccel_Y = fft(RawAccel_Y);
fftRawAccel_Y(floor(length(RawAccel_Y)*F0/1000):end) = 0;
Filter_RawAccel_Y = ifft(fftRawAccel_Y,'symmetric');
%%

%ploting
subplot(2,1,1)
plot(T,RawGyro_Y,':',T,RawGyro_X,':'); axis tight; hold on;
plot(T,Filter_RawGyro_Y,T,Filter_RawGyro_X); axis tight;
xlabel('Time (s)'); ylabel('Raw data') ; legend('Gyro Y','Gyro Y');
subplot(2,1,2)
plot(T,RawAccel_Y,':',T,RawAccel_Z,':',T,RawAccel_X,':'); axis tight ; hold on;
plot(T,Filter_RawAccel_Y,T,Filter_RawAccel_Z,T,Filter_RawAccel_X); axis tight ;

xlabel('Time (s)'); ylabel('Raw data') ; legend('Accel Y','Accel Z','Accel X');

%% Sava in .mat file for Simulink
 datas = [T;RawGyro_Y;RawAccel_Y;RawAccel_Z;RawGyro_X;RawAccel_X];
% save Simulink_Dynamic_Calibration.mat datas;
% save Simulink_Dynamic_Calibration2.mat datas;
% save Simulink_Dynamic_Calibration3.mat datas;
% save Simulink_Static.mat datas;
% save Simulink_Static_60s.mat datas;

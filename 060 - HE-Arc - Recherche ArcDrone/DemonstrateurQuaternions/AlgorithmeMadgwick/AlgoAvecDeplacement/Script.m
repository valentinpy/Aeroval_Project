clear; close all; home;
addpath('Quaternions');

%% -------------------------------------------------------------------------
% DEP - part 1 : selection of the data and the computation method

%Selection of the data set
select_data = 0;
if select_data == 0
    startTime = 6;
    stopTime = 26;
    %filename = 'data_StraightLine.csv';
    filename = 'TrajectoirePied_Escalier1.csv';
elseif select_data == 1
    startTime = 5;
    stopTime = 53;
    filename = 'data_StairsAndCorridor.csv';
elseif select_data == 2
    startTime = 4;
    stopTime = 47;
    filename = 'data_SpiralStairs.csv';
else
    error('Sélection inconnue')
end

%Selection of the computation method (least squares or PID)
C_DO_NOTHING = 0;
C_GYROSCOPE_ONLY = 1;
C_LEASTSQUARE = 2;
C_PID = 3;
select_method = C_DO_NOTHING;
%select_method = C_GYROSCOPE_ONLY;
%select_method = C_LEASTSQUARE;
%select_method = C_PID;

% -------------------------------------------------------------------------
% Import data
samplePeriod = 1/256;
xIMUdata = csvread(filename);
gyrX = xIMUdata(:,1);
gyrY = xIMUdata(:,2);
gyrZ = xIMUdata(:,3);
accX = xIMUdata(:,4);
accY = xIMUdata(:,5);
accZ = xIMUdata(:,6);
%magX = xIMUdata(:,7);
%magY = xIMUdata(:,8);
%magZ = xIMUdata(:,9);
time = (0:length(gyrX)-1)'.*samplePeriod;
clear('xIMUdata');

% -------------------------------------------------------------------------
% Manually frame data
indexSel = find(sign(time-startTime)+1, 1) : find(sign(time-stopTime)+1, 1);
time = time(indexSel);
gyrX = gyrX(indexSel, :);
gyrY = gyrY(indexSel, :);
gyrZ = gyrZ(indexSel, :);
accX = accX(indexSel, :);
accY = accY(indexSel, :);
accZ = accZ(indexSel, :);

%% ---------------------------------------------------------------------
% DEP - part 2 : norm-computation and acceleration filtering in 
% two steps. The first highpass rejects the DC factor and the
% second lowpass rejects the frequencies above 5Hz.
% At the end the stationary-areas are determined (vector stationary).

% -------------------------------------------------------------------------
% Detect stationary periods

% Compute accelerometer magnitude
acc_mag = sqrt(accX.*accX + accY.*accY + accZ.*accZ);

% HP filter accelerometer data
filtCutOff = 0.001;
[b, a] = butter(1, (2*filtCutOff)/(1/samplePeriod), 'high');
acc_magFilt = filtfilt(b, a, acc_mag);

% Compute absolute value
acc_magFilt = abs(acc_magFilt);

% LP filter accelerometer data
filtCutOff = 5;
[b, a] = butter(1, (2*filtCutOff)/(1/samplePeriod), 'low');
acc_magFilt = filtfilt(b, a, acc_magFilt);

% Threshold detection
stationary = acc_magFilt < 0.05;

% -------------------------------------------------------------------------
% Plot data raw sensor data and stationary periods

figure('Position', [900 600 900 600], 'Number', 'off', 'Name', 'Sensor Data');
ax(1) = subplot(2,1,1);
    hold on;
    plot(time, gyrX, 'r');
    plot(time, gyrY, 'g');
    plot(time, gyrZ, 'b');
    title('Gyroscope');
    xlabel('Time (s)');
    ylabel('Angular velocity (^\circ/s)');
    legend('X', 'Y', 'Z');
    hold off;
ax(2) = subplot(2,1,2);
    hold on;
    plot(time, accX, 'r');
    plot(time, accY, 'g');
    plot(time, accZ, 'b');
    plot(time, acc_magFilt, ':k');
    plot(time, stationary, 'k', 'LineWidth', 2);
    title('Accelerometer');
    xlabel('Time (s)');
    ylabel('Acceleration (g)');
    legend('X', 'Y', 'Z', 'Filtered', 'Stationary');
    hold off;
linkaxes(ax,'x');

%% -------------------------------------------------------------------------
% DEP - part 3 : computation of the orientation. The resulz is quat
% An estimation of the initial quaternion is performed with the data 
% of the first 2 seconds.

%Initialisation of the object public variables
quat = zeros(length(time), 4);
AHRSalgorithm = AHRS('SamplePeriod', 1/256, 'Kp', 1, 'KpInit', 1, 'Beta', 0.1);

% Initialisation of the first quaternion
initPeriod = 2;
indexSel = 1 : find(sign(time-(time(1)+initPeriod))+1, 1);
for i = 1:2000
    AHRSalgorithm.UpdateIMU_PID([0 0 0], [mean(accX(indexSel)) mean(accY(indexSel)) mean(accZ(indexSel))]);
end

if select_method == C_DO_NOTHING
    quat(:,1) = ones(length(time), 1);
elseif select_method == C_GYROSCOPE_ONLY
    %Only gyroscopic data
    AHRSalgorithm.Beta = 0;
    for t = 1:length(time)
        AHRSalgorithm.UpdateIMU_LS(deg2rad([gyrX(t) gyrY(t) gyrZ(t)]), [accX(t) accY(t) accZ(t)]);
        quat(t,:) = AHRSalgorithm.Quaternion;
    end
elseif select_method == C_LEASTSQUARE
    %Least squares method
    for t = 1:length(time)
        if(stationary(t))
            AHRSalgorithm.Beta = 0.1;
        else
            AHRSalgorithm.Beta = 0;
        end
        AHRSalgorithm.UpdateIMU_LS(deg2rad([gyrX(t) gyrY(t) gyrZ(t)]), [accX(t) accY(t) accZ(t)]);
        quat(t,:) = AHRSalgorithm.Quaternion;
    end
elseif select_method == C_PID
    %PID method
    for t = 1:length(time)
        if(stationary(t))
            AHRSalgorithm.Kp = 0.5;
        else
            AHRSalgorithm.Kp = 0;
        end
        AHRSalgorithm.UpdateIMU_PID(deg2rad([gyrX(t) gyrY(t) gyrZ(t)]), [accX(t) accY(t) accZ(t)]);
        quat(t,:) = AHRSalgorithm.Quaternion;
    end
    quat = quaternConj(quat);
else
    error('Méthode inconnue !')
end

%% -------------------------------------------------------------------------
% DEP - part 4 : acceleration correction.

% -------------------------------------------------------------------------
% Compute translational accelerations
% -------------------------------------------------------------------------

% Rotate body accelerations to Earth frame
acc = quaternRotate([accX accY accZ], quat);

% % Remove gravity from measurements
% acc = acc - [zeros(length(time), 2) ones(length(time), 1)];     % unnecessary due to velocity integral drift compensation

%% -------------------------------------------------------------------------
% DEP - part 5 : double integration. The velocity-drift is compensated

% Convert acceleration measurements to m/s/s
acc = acc * 9.81;

% Plot translational accelerations
figure('Position', [9 900 900 300], 'Number', 'off', 'Name', 'Accelerations');
hold on;
plot(time, acc(:,1), 'r');
plot(time, acc(:,2), 'g');
plot(time, acc(:,3), 'b');
title('Acceleration');
xlabel('Time (s)');
ylabel('Acceleration (m/s/s)');
legend('X', 'Y', 'Z');
hold off;

% -------------------------------------------------------------------------
% Compute translational velocities

acc(:,3) = acc(:,3) - 9.81;

% Integrate acceleration to yield velocity
vel = zeros(size(acc));
for t = 2:length(vel)
    vel(t,:) = vel(t-1,:) + acc(t,:) * samplePeriod;
    if(stationary(t) == 1)
        vel(t,:) = [0 0 0];     % force zero velocity when foot stationary
    end
end

% Compute integral drift during non-stationary periods
velDrift = zeros(size(vel));
stationaryStart = find([0; diff(stationary)] == -1);
stationaryEnd = find([0; diff(stationary)] == 1);
for i = 1:numel(stationaryEnd)
    driftRate = vel(stationaryEnd(i)-1, :) / (stationaryEnd(i) - stationaryStart(i));
    enum = 1:(stationaryEnd(i) - stationaryStart(i));
    drift = [enum'*driftRate(1) enum'*driftRate(2) enum'*driftRate(3)];
    velDrift(stationaryStart(i):stationaryEnd(i)-1, :) = drift;
end

% Plot translational velocity
figure('Position', [9 100 900 300], 'Number', 'off', 'Name', 'Velocity with no drift correction');
hold on;
plot(time, vel(:,1), 'r');
plot(time, vel(:,2), 'g');
plot(time, vel(:,3), 'b');
plot(time, velDrift(:,1), 'r');
plot(time, velDrift(:,2), 'g');
plot(time, velDrift(:,3), 'b');
title('Velocity with no drift correction');
xlabel('Time (s)');
ylabel('Velocity (m/s)');
legend('X', 'Y', 'Z','DriftX','DriftY','DriftZ');
hold off;

% Remove integral drift
vel = vel - velDrift;

% Plot translational velocity
figure('Position', [900 100 900 300], 'Number', 'off', 'Name', 'Corrected velocity');
hold on;
plot(time, vel(:,1), 'r');
plot(time, vel(:,2), 'g');
plot(time, vel(:,3), 'b');
title('Corrected velocity');
xlabel('Time (s)');
ylabel('Velocity (m/s)');
legend('X', 'Y', 'Z');
hold off;

% -------------------------------------------------------------------------
% Compute translational position

% Integrate velocity to yield position
pos = zeros(size(vel));
for t = 2:length(pos)
    pos(t,:) = pos(t-1,:) + vel(t,:) * samplePeriod;    % integrate velocity to yield position
end

% Plot translational position
figure('Position', [9 39 900 600], 'Number', 'off', 'Name', 'Position');
hold on;
plot(time, pos(:,1), 'r');
plot(time, pos(:,2), 'g');
plot(time, pos(:,3), 'b');
title('Position');
xlabel('Time (s)');
ylabel('Position (m)');
legend('X', 'Y', 'Z');
hold off;

% -------------------------------------------------------------------------
% Plot 3D foot trajectory

% % Remove stationary periods from data to plot
% posPlot = pos(find(~stationary), :);
% quatPlot = quat(find(~stationary), :);
posPlot = pos;
quatPlot = quat;

% Extend final sample to delay end of animation
extraTime = 20;
onesVector = ones(extraTime*(1/samplePeriod), 1);
posPlot = [posPlot; [posPlot(end, 1)*onesVector, posPlot(end, 2)*onesVector, posPlot(end, 3)*onesVector]];
quatPlot = [quatPlot; [quatPlot(end, 1)*onesVector, quatPlot(end, 2)*onesVector, quatPlot(end, 3)*onesVector, quatPlot(end, 4)*onesVector]];

% Create 6 DOF animation
SamplePlotFreq = 4;
Spin = 120;
SixDofAnimation(posPlot, quatern2rotMat(quatPlot), ...
                'SamplePlotFreq', SamplePlotFreq, 'Trail', 'All', ...
                'Position', [9 39 1280 768], 'View', [(100:(Spin/(length(posPlot)-1)):(100+Spin))', 10*ones(length(posPlot), 1)], ...
                'AxisLength', 0.1, 'ShowArrowHead', false, ...
                'Xlabel', 'X (m)', 'Ylabel', 'Y (m)', 'Zlabel', 'Z (m)', 'ShowLegend', false, ...
                'CreateAVI', false, 'AVIfileNameEnum', false, 'AVIfps', ((1/samplePeriod) / SamplePlotFreq));

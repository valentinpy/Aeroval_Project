% Script to compute g ain of the non adaptive Kalman filter (Alpha Beta
% Filter)

disp('continuous')
A = [0 -1; 0 0];
B = [1 0]';
C = [1 0];

K = [1 -1]';

Poles_s = eig(A-K*C)


%% Discret
disp('Discrete')
Ts = .001;

Az = [1 -Ts ;0 1];
Bz = [Ts 0]';
Cz = [1 0];


if ( exist('acmker') == 2)    % if toolbox containing acker function is not present
    PlacementPolesObs = exp([-1/5 -1/5] * Ts );
    Kz = acker(Az',Cz',PlacementPolesObs');

    Poles_z = log(eig(Az-Kz'*Cz))/Ts


    Kz = Kz';
else
    Kz = 1e-3*[.4 ; -.04];  % set the result
end
%Kz = Kz*0;
figure(50);
idx = find(Rn > 65535 / 2);
Rn(idx)= Rn(idx)-65536;

subplot(2,1,1);
plot(t_Rn,Rn(:,[1 2])./100);
axis tight;
ylabel('Angle (°)');

subplot(2,1,2);
plot(t_Rn,Rn(:,3)./19999*.001*1e3,'+'); 
axis tight; ylim([0 1]);
ylabel('Time (ms)');

%% Beep each time there is a time violation
idxTimeViolation = find(Rn(:,3) > 19999);
if ~isempty(idxTimeViolation)
    beep;
    warning('Real-Time Violation')
end

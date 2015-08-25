

% On charge le nouveau set de donn�es
dataset = csvread('C:\Users\Matthieu\Desktop\DatasetQuaternions.csv');
disp('Dataset loaded')

% Plot des quaternions x, y et z
figure(1)
plot3(dataset(:,1),dataset(:,2),dataset(:,3))
axis tight
axis equal

% Lecture des �chelles automatique du plot
%Plot3Scale = [4 2];
% Lecture �chelle axe X
 %Plot3Scale(1,:) = get(gca,'XLim');
 %Plot3Scale(2,:) = get(gca,'YLim');
 %Plot3Scale(3,:) = get(gca,'ZLim');
 % On cherche l'�chelle max
 %Plot3Scale(4,1) = max(abs(Plot3Scale(:,1)));
 % On cherche l'�chelle max
 %Plot3Scale(4,2) = max(abs(Plot3Scale(:,2)));
 
 Plot3Scale
clear; home; close all
format short g;

T=0.58;
a=0.98;
b=1-a;
dt=T*(1-a)/a

%premier ordre
numPb=[b,0];
denPb=[1,-a];

numPh=[1,-1]*a;
denPh=[1,-a];

fvtool(numPb,denPb,numPh,denPh);

%deuxième ordre

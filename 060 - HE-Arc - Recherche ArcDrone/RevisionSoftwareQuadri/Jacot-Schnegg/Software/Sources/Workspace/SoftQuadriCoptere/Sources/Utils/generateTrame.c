#include "generateTrame.h"

void generateTrame(kTrameDestEnum aCapteur, kTrameTypeEnum aType, UInt8 aData[kNbCapteursMax][kNbDigitsMax], UInt8 aTrame[kMaxTrameLength], UInt8 aNbCapteurs)
{
	UInt8 i = 0;
	UInt8 j = 0;
	UInt8 k = 0;
	
	aTrame[k++] = kStartByte;
	aTrame[k++] = aCapteur;
	aTrame[k++] = aType;
	for(i = 0; i < aNbCapteurs; i++)
	{
		j = 0;
		while(aData[i][j] != '\0' && j < kNbDigitsMax)
		{
			aTrame[k++] = aData[i][j];
			j++;
		}
		aTrame[k++] = '|';
	}
	k--;	// Pas de '|' après la dernière valeur
	aTrame[k++] = kStopByte;
	aTrame[k++] = '\r';
	aTrame[k++] = '\n';
	aTrame[k++] = '\0';
}
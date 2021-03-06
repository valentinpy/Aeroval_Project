#ifndef GENERATETRAME_H_
#define GENERATETRAME_H_

#include "def.h"

#define kNbCapteursMax	4	// Nombre max de capteurs � envoyer en une trame (m�me graphique)
#define kNbDigitsMax	10	// Nombre max de digit qu'un r�sultat de capteur peut prendre + 1 pour le z�ro terminal
#define kMaxTrameLength	(kNbCapteursMax * (kNbDigitsMax + 1)) + 6	// Longueur max de la trame  1 pour le z�ro terminal

typedef enum{
	kStartByte = 'A',
	kStopByte = 'Z'
}kTrameStartStopByteEnum;

typedef enum
{
	kDestAccel = 'B',
	kDestGyro = 'C',
	kDestPression = 'D',
	kDestTemperature = 'E',
	kDestMagn = 'F',
	kDestAltitude = 'G',
	kDestTensionAccu='H',
	kDestCourantAccu='I',
	kDestDutyCyclePwm='J',
	kDestAngle='K',
}kTrameDestEnum;

typedef enum
{
	kUInt16 = 'I',
	kFloat = 'F',
}kTrameTypeEnum;

void generateTrame(kTrameDestEnum aCapteur, kTrameTypeEnum aType, UInt8 aData[kNbCapteursMax][kNbDigitsMax], UInt8 aTrame[kMaxTrameLength], UInt8 aNbCapteurs);

#endif /* GENERATETRAME_H_ */

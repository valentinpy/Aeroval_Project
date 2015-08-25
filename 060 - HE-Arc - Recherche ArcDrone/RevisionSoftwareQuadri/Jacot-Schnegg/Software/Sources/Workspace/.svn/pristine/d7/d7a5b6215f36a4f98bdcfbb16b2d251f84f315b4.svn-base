#ifndef MCAPTEURACCELMAGN_H_
#define MCAPTEURACCELMAGN_H_

#include "def.h"

typedef enum
{
	LowPowerModeEnable=0x08,
	ZEnable=0x04,
	YEnable=0x02,
	XEnable=0x01
}CapteurAccelEnum;

typedef enum
{
	kAccelAxe_X=0x28,
	kAccelAxe_Y=0x2A,
	kAccelAxe_Z=0x2C
}AccelAxeEnum;

typedef enum
{
	kMagnAxe_X=0x03,
	kMagnAxe_Y=0x05,
	kMagnAxe_Z=0x07
}MagnAxeEnum;

typedef enum
{
	kAccelAddr=0x19,
	kMagnAddr=0x1E,
}AccelMagnAddrEnum;

//------------------------------------------------------------
// Setup
//------------------------------------------------------------
void mCapteurAccelMagn_Setup(void);

//------------------------------------------------------------
// Open
//------------------------------------------------------------
void mCapteurAccelMagn_Open(void);

//------------------------------------------------------------
// Close
//------------------------------------------------------------
void mCapteurAccelMagn_Close(void);

//------------------------------------------------------------
// Lecture de tous les axes de l'accéléromètre
//------------------------------------------------------------
bool mCapteurAccelMagn_ReadAllAccelAxes(UInt16 *tabReturn);

//------------------------------------------------------------
// Lecture de tous les axes du magnétomètre
//------------------------------------------------------------
bool mCapteurAccelMagn_ReadAllMagnAxes(UInt16 *tabReturn);

#endif /* MCAPTEURACCELMAGN_H_ */

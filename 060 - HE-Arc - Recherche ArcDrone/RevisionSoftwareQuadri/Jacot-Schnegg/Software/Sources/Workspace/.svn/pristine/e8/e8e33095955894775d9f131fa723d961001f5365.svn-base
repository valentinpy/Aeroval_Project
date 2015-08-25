/*
------------------------------------------------------------
Copyright 2003-2013 Haute Ecole ARC Ingénierie,
Switzerland. All rights reserved
------------------------------------------------------------
Nom du fichier : 	gMbox.h
Auteurs:			Alexandre Schnegg
					Guillaume Jacot
Date:				23.01.13
But :	Gestionnaire de communication inter-gestionnaires
------------------------------------------------------------
*/

#ifndef GMBOX_H_
#define GMBOX_H_

#include "def.h"
#include "generateTrame.h"

#define kToleranceZero (UInt16)3438 // (% + 100) / 2000 * FTM0_MOD -> 10%

//-----------------------------------------------------------------------------
// Structure du gestionnaire Input
//-----------------------------------------------------------------------------

typedef struct
{
	//Data capteurs
	UInt16 captAccelData[3];
	UInt16 captMagnData[3];
	UInt16 captGyroData[3];
	float captTempData;
	float captPressionData;
	float captTensionData;
	float captCourantData;
	UInt16 captPWMData[4];
	
	//Lecture OK
	bool captAccelOK;
	bool captMagnOK;
	bool captTempPressionOK;
} InputStruct;

extern InputStruct gInput;

//-----------------------------------------------------------------------------
// Structure du gestionnaire Compute
//-----------------------------------------------------------------------------

typedef struct
{
	float angles[3];
	UInt16 commandesMoteurs[4];
	bool regulationAcvtive;
} ComputeStruct;

extern ComputeStruct gCompute;

#endif

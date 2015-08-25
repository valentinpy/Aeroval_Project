/*
------------------------------------------------------------
Copyright 2003-2013 Haute Ecole ARC Ing�nierie,
Switzerland. All rights reserved
------------------------------------------------------------
Nom du fichier :	gCompute.c
Auteurs:			Alexandre Schnegg
					Guillaume Jacot
Date:				23.01.13
Description dans le fichier gCompute.h
------------------------------------------------------------
*/

#include "gMBox.h"
#include "gCompute.h"
#include "generateTrame.h"
#include "mOrientationProcessing.h"
#include "mRegulation.h"
#include "mLeds.h"
#include "mPwm.h"

static float sRaccTab[3];
static float sGyroTab[3];
static float sATab[3];
static Int16 sNumTempo;
static float sAngleTab[3];

static void gCompute_OrientationProcessing(filterOrderEnum aOrder);
static void gCompute_Regulation();

//-----------------------------------------------------------------------------
// Configuration du gestionnaire
//-----------------------------------------------------------------------------
void gCompute_Setup(void)
{
	sNumTempo = -1;
	gCompute.angles[0] = 0;
	gCompute.angles[1] = 0;
	gCompute.angles[2] = 0;
	gCompute.commandesMoteurs[0] = kToleranceZero;
	gCompute.commandesMoteurs[1] = kToleranceZero;
	gCompute.commandesMoteurs[2] = kToleranceZero;
	gCompute.commandesMoteurs[3] = kToleranceZero;
	gCompute.regulationAcvtive = false;
}

//-----------------------------------------------------------------------------
// Ex�cution du gestionnaire
//-----------------------------------------------------------------------------
void gCompute_Execute(void)
{
	if (gCompute.regulationAcvtive)
	{
		if ((gInput.captPWMData[0] > kToleranceZero) || (gInput.captPWMData[1] > kToleranceZero) || (gInput.captPWMData[2] > kToleranceZero) || (gInput.captPWMData[3] > kToleranceZero))
		{
			gCompute.regulationAcvtive = false;
			mLeds_WriteLed(kLed7, kLedOff);
		}
	}
	else
	{
		if ((gInput.captPWMData[0] <= kToleranceZero) && (gInput.captPWMData[1] <= kToleranceZero) && (gInput.captPWMData[2] <= kToleranceZero) && (gInput.captPWMData[3] <= kToleranceZero))
		{
			gCompute.regulationAcvtive = true;
			mLeds_WriteLed(kLed7, kLedOn);
		}
	}
}

//-----------------------------------------------------------------------------
// Ex�cution du gestionnaire dans Interruotion
//-----------------------------------------------------------------------------
void gCompute_ExecuteInt(void)
{
	//if (gCompute.regulationAcvtive)
	//{
		gCompute_OrientationProcessing(kFirstOrder);
		gCompute_Regulation();
	//}
}

//-----------------------------------------------------------------------------
// Filtrage et calcul de l'orientation
//-----------------------------------------------------------------------------
static void gCompute_OrientationProcessing(filterOrderEnum aOrder)
{
	mOrientationProcessing_computeSensor(gInput.captAccelData, gInput.captGyroData, sRaccTab, sGyroTab);
	mOrientationProcessing_convertToGyroSystem(sRaccTab,sATab);

	if (aOrder == kFirstOrder)
	{
		mOrientationProcessing_FilterFirstOrder(sATab, sGyroTab, gCompute.angles);
	}
	else if (aOrder == kSecondOrder)
	{
		mOrientationProcessing_FilterSecondOrder(sATab, sGyroTab, gCompute.angles);
	}
}

//-----------------------------------------------------------------------------
// R�gulation
//-----------------------------------------------------------------------------
static void gCompute_Regulation(void)
{
	float aErreurXZ;
	float aErreurYZ;
	float aRegulXZ;
	float aRegulYZ;

	float aConsigneXZ = 0;
	float aConsigneYZ = 0;
	
	float x;
	UInt16 x2;

	aErreurXZ = mRegulation_getError(aConsigneXZ, gCompute.angles[0]);
	aErreurYZ = mRegulation_getError(aConsigneYZ, gCompute.angles[2]);

	aRegulXZ = mRegulation_regulate(aErreurXZ, kGAINPXZ, kGAINIXZ);
	aRegulYZ = mRegulation_regulate(aErreurYZ, kGAINPYZ, kGAINIYZ);
	
	gCompute.commandesMoteurs[0] = mPwm_convertPercentToCmd(kOFFSETMOTEUR + aRegulXZ);
	gCompute.commandesMoteurs[1] = mPwm_convertPercentToCmd(kOFFSETMOTEUR - aRegulYZ);
	gCompute.commandesMoteurs[2] = mPwm_convertPercentToCmd(kOFFSETMOTEUR - aRegulXZ);
	gCompute.commandesMoteurs[3] = mPwm_convertPercentToCmd(kOFFSETMOTEUR + aRegulYZ);
}

/*
------------------------------------------------------------
Copyright 2003-2013 Haute Ecole ARC Ingénierie,
Switzerland. All rights reserved
------------------------------------------------------------
Nom du fichier :	mRegulation.c
Auteurs:			Alexandre Schnegg
					Guillaume Jacot
Date:				23.01.13
Description dans le fichier mRegulation.h
------------------------------------------------------------
*/

#include "mRegulation.h"
#include "MK10DZ10.h"
#include "mPwm.h"
#include "stringConvert.h"
#include "mRfInterface.h"
#include "generateTrame.h"

/**
 * Retourne l'erreur en fonction de la mesure et de la consigne
 */
float mRegulation_getError(float aConsigne, float aMesure)
{
	return aConsigne - aMesure;
}

/**
 * Régulateur P
 */
float mRegulation_regulateP(float aErreur, float aGainP)
{
	return aErreur * aGainP / kANGLEMAX;
}

/**
 * Retourne le duty cycle à appliquer au moteur en fonction de l'erreur et des gains des régulateurs (compris entre 0 et 1)
 */
float mRegulation_regulate(float aErreur, float aGainP, float aGainI)
{
	return kDELTAMOTEUR * (mRegulation_regulateP(aErreur, aGainP) + mmRegulation_regulateI(aErreur) * aGainI);
}

/**
 * Régulateur I
 */
float mmRegulation_regulateI(float aErreur)
{
	static float sSum = 0;

	if (sSum <= kANGLEMAX && sSum >= -kANGLEMAX)
	{
		sSum += aErreur;
	}
	return sSum / kANGLEMAX;
}
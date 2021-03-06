/*
 ------------------------------------------------------------
 Copyright 2003-2013 Haute Ecole ARC Ingénierie,
 Switzerland. All rights reserved
 ------------------------------------------------------------
 Nom du fichier :	mOrientationProcessing.c
 Auteurs:			Alexandre Schnegg
 Guillaume Jacot
 Date:				23.01.13
 Description dans le fichier mOrientationProcessing.h
 ------------------------------------------------------------
 */

#include "def.h"
#include "mCapteurGyro.h"
#include "mCapteurAccelMagn.h"
#include <cmath>
#include "generateTrame.h"
#include "def.h"
#include "mCapteurAccelMagn.h"
#include "mCapteurGyro.h"
#include "mOrientationProcessing.h"
#include "stringConvert.h"
#include "mRegulation.h"

/**
 * Configuration de mOrientationProcessing
 */
void mOrientationProcessing_setup(void)
{
	// PIT0 setup
	iPit_Config(kPit1, (UInt16) (kDt * 1000));
}

/**
 * Open de mOrientationProcessing
 */
void mOrientationProcessing_open(void)
{
	// PIT0 setup
	iPit_StartPit(kPit1);
}

/**
 * Calcul les valeurs des capteurs en fonction des données brute (accélération en g et vitesse angulaire en rad/s
 * aRacc=Racc={Rx,Ry,Rz}
 */
void mOrientationProcessing_computeSensor(UInt16 *aAccelTabIn, UInt16 *aGyroTabIn, float *aRacc, float *aGyroTab)
{
	UInt8 i;

	//Mise en forme accel
	for (i = 0; i < 4; i++)
	{
		aRacc[i] = (float) ((Int16) aAccelTabIn[i] - kAccOffset) / kAccScale;
	}

	//Mise en forme gyro	
	aGyroTab[0] = (float) ((Int16) aGyroTabIn[0] - kGyroOffsetX) / kGyroScale; //Correspond Ayz
	aGyroTab[1] = (float) ((Int16) aGyroTabIn[1] - kGyroOffsetY) / kGyroScale; //Correspond Axz
	aGyroTab[2] = (float) ((Int16) aGyroTabIn[2] - kGyroOffsetZ) / kGyroScale; //Correspond Ayx
}

/**
 * Convertis le vecteur d'accélération en angles dans le référentiel du gyroscope
 * aA={Axz,Axy,Ayz}
 */
void mOrientationProcessing_convertToGyroSystem(float *aRacc, float *aA)
{
	aA[0] = atan2(-aRacc[1], aRacc[2]); //Axz gyro == A-yz accel
	aA[1] = atan2(-aRacc[0], -aRacc[1]); //Axy gyro == A-x-y accel
	aA[2] = atan2(-aRacc[0], aRacc[2]); //Ayz gyro == A-xz accel

	aA[0] = mOrientationProcessing_RadToDeg(aA[0]);
	aA[1] = mOrientationProcessing_RadToDeg(aA[1]);
	aA[2] = mOrientationProcessing_RadToDeg(aA[2]);
}

/**
 * Filtre complémentaire du premier ordre
 */
void mOrientationProcessing_FilterFirstOrder(float *aAngle, float *aAngleRate, float *aResult)
{
	static float sResult_n1[] = { 0, 0, 0 };
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		aResult[i] = kA * (sResult_n1[i] + aAngleRate[i] * kDt) + kB * aAngle[i];
		sResult_n1[i] = aResult[i];
	}
}

/**
 * Filtre complémentaire du second ordre
 */
void mOrientationProcessing_FilterSecondOrder(float *aAngle, float *aAngleRate, float *aResult)
{
	uint8_t i = 0;
	static float sResult_n1[] = { 0, 0, 0 };
	static float sResult_n2[] = { 0, 0, 0 };
	static float sAngle_n1[] = { 0, 0, 0 };
	static float sAngleRate_n1[] = { 0, 0, 0 };
	for (i = 0; i < 3; i++)
	{
		aResult[i] = 2 * kA * sResult_n1[i] - kA * kA * sResult_n2[i] + (1 - kA * kA) * aAngle[i] - 2 * kA * kB * sAngle_n1[i] + kA * kA * kTau * (aAngleRate[i] - sAngleRate_n1[i]);
		sResult_n2[i] = sResult_n1[i];
		sResult_n1[i] = aResult[i];
		sAngle_n1[i] = aAngle[i];
		sAngleRate_n1[i] = aAngleRate[i];
	}
}

/**
 * Convertis les angles en radians en degrés
 */
double mOrientationProcessing_RadToDeg(float aRad)
{
	return aRad * (180 / PI);
}


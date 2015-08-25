/*
------------------------------------------------------------
Copyright 2003-2013 Haute Ecole ARC Ing�nierie,
Switzerland. All rights reserved
------------------------------------------------------------
Nom du fichier : 	mRegulation.h
Auteurs:			Alexandre Schnegg
					Guillaume Jacot
Date:				23.01.13
But :	R�guler l'orientation du quadricopt�re
------------------------------------------------------------
*/

#ifndef MREGULATION_H_
#define MREGULATION_H_

#define kGAINPXZ 0.2f
#define kGAINPYZ 0.2f
#define kGAINIXZ 0.0f
#define kGAINIYZ 0.0f
#define kOFFSETMOTEUR 0.70f
#define kDELTAMOTEUR 0.30f
#define kANGLEMAX 25.0f

/**
 * Retourne l'erreur en fonction de la mesure et de la consigne
 */
float mRegulation_getError(float aConsigne,float aMesure);

/**
 * Retourne le duty cycle � appliquer au moteur en fonction de l'erreur et des gains des r�gulateurs (compris entre 0 et 1)
 */
float mRegulation_regulate(float aErreur,float aGainP,float aGainI);

/**
 * R�gulateur I
 */
float mmRegulation_regulateI(float aErreur);

/**
 * R�gulateur P
 */
float mRegulation_regulateP(float aErreur, float aGainP);

#endif /* MREGULATION_H_ */

/*
 * mCapteurPression.h
 *
 *  Created on: 3 juil. 2012
 *      Author: favrebm1
 */

#ifndef MCAPTEURPRESSION_H_
#define MCAPTEURPRESSION_H_

#include "def.h"
#include "derivative.h"

//-----------------------------------------------------------------------------
// capteur pression module setup
//-----------------------------------------------------------------------------
void mCapteurPression_Setup(void);

//-----------------------------------------------------------------------------
// capteur pression module setup
//-----------------------------------------------------------------------------
void mCapteurPression_Open(void);

//-----------------------------------------------------------------------------
// Lecture des valeurs et calcul de la pression
// ATTENTION, doit toujours être exécuté avant la lecture des valeur pour les avoir à jour
//-----------------------------------------------------------------------------
bool mCapteurPression_Compute(void);

//-----------------------------------------------------------------------------
// Lecture la température mesurée
//-----------------------------------------------------------------------------
float mCapteurPression_ReadTemperature(void);

//-----------------------------------------------------------------------------
// Lecture de la pression mesurée
//-----------------------------------------------------------------------------
float mCapteurPression_ReadPression(void);

//-----------------------------------------------------------------------------
// Lecture de l'altitude
//-----------------------------------------------------------------------------
float mCapteurPression_ReadAltitude(void);

//-----------------------------------------------------------------------------
// Lecture de la pression au niveau de la mer
//-----------------------------------------------------------------------------
float mCapteurPression_ReadSeaPression(void);

#endif /* MCAPTEURPRESSION_H_ */

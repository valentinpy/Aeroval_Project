/*
 * mMesureAlimentation.c
 *
 *  Created on: 11 juil. 2012
 *      Author: favrebm1
 */

#include "mMesureAlimentation.h"
#include "iAd.h"

void mMesureAlimentation_Setup(void)
{
}

//-----------------------------------------------------------------------------
// Retourne la tension d'alimentation de la batterie
//-----------------------------------------------------------------------------
float mMesureAlimentation_TensionBatterie(void)
{
	float aRetVal=0;
	
	//Selection du cannal � convertir
	iAd_SelectChannel(kAdc0,kAdcCh5);
	//Attente de la fin de la conversion
	while(1!=iAd_GetCompleteConvStatus(kAdc0));
	//Lecture de la valeur convertie
	aRetVal=iAd_GetResult(kAdc0);
	
	//Calcul de la tension d'alimentation
	aRetVal=aRetVal*(20.0/4095);
	
	return aRetVal;
}

//-----------------------------------------------------------------------------
// Retourne du courant d'alimentation de la batterie
//-----------------------------------------------------------------------------
float mMesureAlimentation_CourantBatterie(void)
{
	float aRetVal=0;
	
	//Selection du cannal � convertir
	iAd_SelectChannel(kAdc0,kAdcCh4);
	//Attente de la fin de la conversion
	while(1!=iAd_GetCompleteConvStatus(kAdc0));
	//Lecture de la valeur convertie
	aRetVal=iAd_GetResult(kAdc0);
	
	//Calcul du courant d'alimentation v=(r*i)*facMult -> i=v/(r*facMult) -> i=3.3/(0.003*20)=55
	aRetVal=aRetVal*(55.0/4095);
	
	return aRetVal;
}
			
			
			
			
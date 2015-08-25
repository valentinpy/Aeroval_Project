/*
------------------------------------------------------------
Copyright 2003-2010 Haute école ARC Ingéniérie, Switzerland. 
All rights reserved.
------------------------------------------------------------
File name : 	iFlextimer.h	
Author and date :	Monnerat Serge 1 mars 2012

Goal : 

-----------------------------------------------------------------------------
History:
-----------------------------------------------------------------------------

$History: $


-----------------------------------------------------------------------------
*/
#ifndef __iFlextimer__
#define __iFlextimer__

#include "def.h"

// Pwm enum
typedef enum
{
	kPwm0,
	kPwm1,
	kPwm2
}PwmEnum;

// Pwm channels enum
typedef enum
{
	kPwmCh0,
	kPwmCh1,
	kPwmCh2,
	kPwmCh3,
	kPwmCh4,
	kPwmCh5,
	kPwmCh6,
	kPwmCh7
}PwmChannelEnum;


//------------------------------------------------------------
// Flextimer setup
//------------------------------------------------------------
void iFlextimer_Config(void);

//------------------------------------------------------------
// Open des interfaces FTM
//------------------------------------------------------------
void iFlextimer_Open(PwmEnum aPwm);

//------------------------------------------------------------
// Close des interfaces FTM
//------------------------------------------------------------
void iFlextimer_Close(PwmEnum aPwm);

//------------------------------------------------------------
// Set PWM duty
//------------------------------------------------------------
void iFlextimer_UpdatePWM(PwmEnum aPwm, PwmChannelEnum aChannel, float aDuty);

//------------------------------------------------------------
// Set PWM pour les signaux de la télécommande
//------------------------------------------------------------
void iFlextimer_UpdateTelecommandePWM(PwmChannelEnum aChannel, UInt16 aEcart);

//------------------------------------------------------------
// Read PWM duty
//------------------------------------------------------------
float iFlextimer_ReadPWM(PwmEnum aPwm, PwmChannelEnum aChannel);

//------------------------------------------------------------
// Read PWM pour les signaux de la télécommande
//------------------------------------------------------------
UInt16 iFlextimer_ReadTelecommandePWM(PwmChannelEnum aChannel);

#endif

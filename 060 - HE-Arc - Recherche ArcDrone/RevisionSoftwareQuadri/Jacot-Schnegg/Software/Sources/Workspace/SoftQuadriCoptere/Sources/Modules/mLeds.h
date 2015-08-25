/*
 * mLeds.h
 *
 *  Created on: 26 juin 2012
 *      Author: favrebm1
 */

#ifndef MLEDS_H_
#define MLEDS_H_

typedef enum
{
	kLed2,
	kLed3,
	kLed4,
	kLed5,
	kLed6,
	kLed7,
	kLed8
}ledsEnum;

typedef enum
{
	kLedOn,
	kLedOff
}ledStateEnum;

//------------------------------------------------------------
// Setup leds module
//------------------------------------------------------------
void mLeds_Setup(void);

//------------------------------------------------------------
// Set and reset leds
//------------------------------------------------------------
void mLeds_WriteLed(ledsEnum aLed,ledStateEnum aState);

#endif /* MLEDS_H_ */

/*
 * mLeds.c
 *
 *  Created on: 26 juin 2012
 *      Author: favrebm1
 */
#include "mLeds.h"
#include "iDio.h"

//------------------------------------------------------------
// Setup leds module
//------------------------------------------------------------
void mLeds_Setup(void)
{
	//Configuration des I/O
	iDio_SetPortDirection(kPortD,kMaskIo3,kIoOutput);
	iDio_SetPortDirection(kPortD,kMaskIo2,kIoOutput);
	iDio_SetPortDirection(kPortD,kMaskIo1,kIoOutput);
	iDio_SetPortDirection(kPortD,kMaskIo0,kIoOutput);
	iDio_SetPortDirection(kPortC,kMaskIo9,kIoOutput);
	iDio_SetPortDirection(kPortC,kMaskIo8,kIoOutput);
	iDio_SetPortDirection(kPortC,kMaskIo0,kIoOutput);
	
	//Write leds to 0
	iDio_SetPort(kPortD,kMaskIo3,kIoOff);
	iDio_SetPort(kPortD,kMaskIo2,kIoOff);
	iDio_SetPort(kPortD,kMaskIo1,kIoOff);
	iDio_SetPort(kPortD,kMaskIo0,kIoOff);
	iDio_SetPort(kPortC,kMaskIo9,kIoOff);
	iDio_SetPort(kPortC,kMaskIo8,kIoOff);
	iDio_SetPort(kPortC,kMaskIo0,kIoOff);
}

//------------------------------------------------------------
// Set and reset leds
//------------------------------------------------------------
void mLeds_WriteLed(ledsEnum aLed,ledStateEnum aState)
{
	switch(aLed)
	{
	case kLed3:
		if(kLedOn==aState)
		{
			iDio_SetPort(kPortD,kMaskIo3,kIoOn);
		}
		else if(kLedOff==aState)
		{
			iDio_SetPort(kPortD,kMaskIo3,kIoOff);
		}
		break;
	case kLed2:
			if(kLedOn==aState)
			{
				iDio_SetPort(kPortD,kMaskIo2,kIoOn);
			}
			else if(kLedOff==aState)
			{
				iDio_SetPort(kPortD,kMaskIo2,kIoOff);
			}		
		break;
	case kLed4:
			if(kLedOn==aState)
			{
				iDio_SetPort(kPortD,kMaskIo1,kIoOn);
			}
			else if(kLedOff==aState)
			{
				iDio_SetPort(kPortD,kMaskIo1,kIoOff);
			}	
		break;
	case kLed5:
				if(kLedOn==aState)
				{
					iDio_SetPort(kPortD,kMaskIo0,kIoOn);
				}
				else if(kLedOff==aState)
				{
					iDio_SetPort(kPortD,kMaskIo0,kIoOff);
				}	
		break;
	case kLed6:
				if(kLedOn==aState)
				{
					iDio_SetPort(kPortC,kMaskIo9,kIoOn);
				}
				else if(kLedOff==aState)
				{
					iDio_SetPort(kPortC,kMaskIo9,kIoOff);
				}	
		break;
	case kLed7:
				if(kLedOn==aState)
				{
					iDio_SetPort(kPortC,kMaskIo8,kIoOn);
				}
				else if(kLedOff==aState)
				{
					iDio_SetPort(kPortC,kMaskIo8,kIoOff);
				}	
		break;
	case kLed8:
				if(kLedOn==aState)
				{
					iDio_SetPort(kPortC,kMaskIo0,kIoOn);
				}
				else if(kLedOff==aState)
				{
					iDio_SetPort(kPortC,kMaskIo0,kIoOff);
				}	
		break;
	}
}




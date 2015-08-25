/*
 * I2C.c
 *
 *  Created on: 21 juin 2012
 *      Author: favrebm1
 */


#include "iI2C.h"

#define BUSSPEED 50000000
#define I2CBAUDRATE 400000




//------------------------------------------------------------
// I2C module setup
//------------------------------------------------------------
void iI2C_Setup(void)
{
	//Setup I2C0
	//Baud rate speed
	I2C0_F|=I2C_F_ICR(0x1F)|I2C_F_MULT(0x4);
	//I2C interrupt enable
	I2C0_C1|=I2C_C1_IICIE_MASK;

	//Setup I2C1
	//Baud rate speed
	I2C1_F|=I2C_F_ICR(0x1F)|I2C_F_MULT(0x4);
	//I2C interrupt enable
	I2C1_C1|=I2C_C1_IICIE_MASK;
}

//------------------------------------------------------------
// I2C module Open
//------------------------------------------------------------
void iI2C_Open(void)
{

		//I2C0 enable
		I2C0_C1|=I2C_C1_IICEN_MASK;

		//I2C1 enable
		I2C1_C1|=I2C_C1_IICEN_MASK;

}

//------------------------------------------------------------
// I2C module Close
//------------------------------------------------------------
void iI2C_Close(void)
{

		//I2C0 enable
		I2C0_C1&=~I2C_C1_IICEN_MASK;

		//I2C1 enable
		I2C1_C1&=~I2C_C1_IICEN_MASK;
		
}

//------------------------------------------------------------
// Génération d'un start
// I2CnEnum aI2C: le channel i2c en question
//------------------------------------------------------------
void iI2C_GenerateStart(I2CnEnum aI2C)
{
	switch(aI2C)
			{
			case kI2C0:
				{
					//Génération start
					I2C0_C1|=I2C_C1_MST_MASK;
					break;
				}
			case kI2C1:
				{
					//Génération start
					I2C1_C1|=I2C_C1_MST_MASK;
					break;
				}
			}
}

//------------------------------------------------------------
// Envoi d'une donnée
// I2CnEnum aI2C: le channel i2c en question
// UInt8 aData: Envoi de la data (8 bits) ou de l'adresse du destinataire (7bits)
// RdWrModeEnum aRdWr: Sense de communication (écriture, lecture, ou rien)
//------------------------------------------------------------
void iI2C_SendData(I2CnEnum aI2C, UInt8 aData, RdWrModeEnum aRdWr)
{
	switch(aI2C)
	{
		UInt8 aSendData=0;
		case kI2C0:
			//Transmit mode select
			if(kWrite==aRdWr)
			{
				aSendData=(aData<<1)&(~0x1);	
			}
			else if (kRead==aRdWr)
			{
				aSendData=(aData<<1)|0x1;
			}
			else if (kNoRW==aRdWr)
			{
				aSendData=aData;
			}
			
			//Send addr and rw mode
			I2C0_D=aSendData;
			break;
			
		case kI2C1:
			//Transmit mode select
			if(kWrite==aRdWr)
			{
				aSendData=(aData<<1)&(~0x1);	
			}
			else if (kRead==aRdWr)
			{
				aSendData=(aData<<1)|0x1;
			}
			else if (kNoRW==aRdWr)
			{
				aSendData=aData;
			}
			
			//Send addr and rw mode
			I2C1_D=aSendData;
			break;
	}
}

//------------------------------------------------------------
// Attente de la bonne réception ou du bon envoi d'un byte
//------------------------------------------------------------
void i2c_Wait(I2CnEnum aI2C)
{

	switch(aI2C)
		{
		case kI2C0:
			{ 
				while((I2C0_S & I2C_S_IICIF_MASK)==0);
				// Clear the interrupt flag
				I2C0_S |= I2C_S_IICIF_MASK;
				break;
			}
		case kI2C1:
			{
				while((I2C1_S & I2C_S_IICIF_MASK)==0);
				// Clear the interrupt flag
				I2C1_S |= I2C_S_IICIF_MASK;
				break;
			}
		}
}

//------------------------------------------------------------
// Génération d'un repeated start
// I2CnEnum aI2C: le channel i2c en question
//------------------------------------------------------------
void iI2C_GenerateRepeatedStart(I2CnEnum aI2C)
{
	switch(aI2C)
			{
			case kI2C0:
				{ 
					//Génération repeated start
					I2C0_C1|=I2C_C1_RSTA_MASK;
					break;
				}
			case kI2C1:
				{
					//Génération repeated start
					I2C1_C1|=I2C_C1_RSTA_MASK;
					break;
				}
			}
}

//------------------------------------------------------------
// Sélection du mode d'émission ou de réception
// I2CnEnum aI2C: le channel i2c en question
// I2CTransmiteModeEnum aMode: le mode choisi
//------------------------------------------------------------
void iI2C_TransmiteModeSelect(I2CnEnum aI2C, I2CTransmiteModeEnum aMode)
{
	switch(aI2C)
			{
			case kI2C0:
				{ 
					if(kTxMode==aMode)
					{
						//Transmite mode select
						I2C0_C1|=I2C_C1_TX_MASK;
					}
					else if(kRxMode==aMode)
					{
						//Transmite mode select
						I2C0_C1&=~I2C_C1_TX_MASK;
					}
					break;
				}
			case kI2C1:
				{
					if(kTxMode==aMode)
					{
						//Transmite mode select
						I2C1_C1|=I2C_C1_TX_MASK;
					}
					else if(kRxMode==aMode)
					{
						//Transmite mode select
						I2C1_C1&=~I2C_C1_TX_MASK;
					}
					break;
				}
			}
}



//------------------------------------------------------------
// Generate ack or nack
// I2CnEnum aI2C: le channel i2c en question
//------------------------------------------------------------
void iI2C_GenerateAck(I2CnEnum aI2C,I2CAckEnum aAck)
{
	switch(aI2C)
				{
				case kI2C0:
					{ 
						if(aAck==kAck)
						{
							//ACK bit selected
							I2C0_C1&=~I2C_C1_TXAK_MASK;
						}
						else if(aAck==kNack)
						{
							//NACK bit selected
							I2C0_C1|=I2C_C1_TXAK_MASK;
						}
						break;
					}
				case kI2C1:
					{
						if(aAck==kAck)
						{
							//ACK bit selected
							I2C1_C1&=~I2C_C1_TXAK_MASK;
						}
						else if(aAck==kNack)
						{
							//NACK bit selected
							I2C1_C1|=I2C_C1_TXAK_MASK;
						}
						break;
					}
				}
}

//------------------------------------------------------------
// Generate clock for receiving
// I2CnEnum aI2C: le channel i2c en question
//------------------------------------------------------------
void iI2C_GenerateClk(I2CnEnum aI2C)
{
	UInt8 aTemp=0;
	switch(aI2C)
				{
				case kI2C0:
					{ 
						//Read dummy byte
						aTemp=I2C0_D;
						break;
					}
				case kI2C1:
					{
						//Read dummy byte
						aTemp=I2C1_D;
						break;
					}
				}
}


//------------------------------------------------------------
// lecture des données
// I2CnEnum aI2C: le channel i2c en question
//------------------------------------------------------------
UInt8 iI2C_ReadData(I2CnEnum aI2C)
{
	UInt8 aReturnData=0;
	switch(aI2C)
		{
		case kI2C0:
			{ 
				//Read data
				aReturnData=I2C0_D;
				break;
			}
		case kI2C1:
			{
				//Read data
				aReturnData=I2C1_D;
				break;
			}
		}
	return aReturnData;
}

//------------------------------------------------------------
// Finir une transmission
// I2CnEnum aI2C: le channel i2c en question
//------------------------------------------------------------
void iI2C_GenerateStop(I2CnEnum aI2C)
{
	switch(aI2C)
	{
	case kI2C0:
		{
			//Master mode select, generate stop
			I2C0_C1&=~I2C_C1_MST_MASK;
			break;
		}
	case kI2C1:
		{
			//Master mode select, generate stop
			I2C1_C1&=~I2C_C1_MST_MASK;
			break;
		}
	}
}


//------------------------------------------------------------
// lire les status
// I2CnEnum aI2C: le channel i2c en question
// I2CStatusEnum aStatus: le status
//------------------------------------------------------------
bool iI2C_ReadStatus(I2CnEnum aI2C, I2CStatusEnum aStatus)
{
	bool aReturn=0;
	UInt32 aTmp;
	
	switch(aI2C)
	{
		case kI2C0:
		{
			switch (aStatus)
			{
			case kTransferComplete:
				{
					aReturn=(I2C0_S&I2C_S_TCF_MASK)==I2C_S_TCF_MASK;
					break;
				}
			case InterruptFlag:
				{
					aReturn=(I2C0_S&I2C_S_IICIF_MASK)==I2C_S_IICIF_MASK;
					break;
				}
			case RxAK:
				{
					aReturn=((I2C0_S&I2C_S_RXAK_MASK)==I2C_S_RXAK_MASK);
					break;
				}
			case kBUSY:
				{
					aReturn=((I2C0_S&I2C_S_BUSY_MASK)==I2C_S_BUSY_MASK);
					break;
				}
			}
			break;
		}
		case kI2C1:
		{
			switch (aStatus)
			{
			case kTransferComplete:
				{
					aTmp   = I2C1_S;
					aTmp >>= I2C_S_TCF_SHIFT;
					aReturn = aTmp & 1;
					break;
				}
			case InterruptFlag:
				{
					aReturn=(I2C1_S>>I2C_S_TCF_SHIFT)&0x01;
					break;
				}
			case RxAK:
				{
					aReturn=(I2C1_S>>I2C_S_RXAK_SHIFT)&0x01;
					break;
				}
			}
			break;
		}
	}
		return (aReturn);
}
	 
//------------------------------------------------------------
// Active l'ack automatique à la reception
//------------------------------------------------------------

void iI2C_EnableTxAck(void)
{
	I2C0_C1 &= ~I2C_C1_TXAK_MASK;
}

//------------------------------------------------------------
// Désactive l'ack automatique à la reception
//------------------------------------------------------------

void iI2C_DisableTxAck(void)
{
	I2C0_C1 |= I2C_C1_TXAK_MASK;
}
	








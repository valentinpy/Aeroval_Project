/*
 * I2C.h
 *
 *  Created on: 21 juin 2012
 *      Author: favrebm1
 */

#include "derivative.h"
#include "def.h"

#ifndef I2C_H_
#define I2C_H_


typedef enum{
	kWrite,
	kRead,
	kNoRW
}RdWrModeEnum;

typedef enum{
	kI2C0,
	kI2C1
}I2CnEnum;

typedef enum{
	kAck,
	kNack
}I2CAckEnum;

typedef enum{
	kTransferComplete,
	InterruptFlag,
	RxAK,
	kBUSY
}I2CStatusEnum;

typedef enum{
	kTxMode,
	kRxMode
}I2CTransmiteModeEnum;

//------------------------------------------------------------
// I2C module setup
//------------------------------------------------------------
void iI2C_Setup(void);

//------------------------------------------------------------
// I2C module Open
//------------------------------------------------------------
void iI2C_Open(void);

//------------------------------------------------------------
// I2C module Close
//------------------------------------------------------------
void iI2C_Close(void);

//------------------------------------------------------------
// Génération d'un start
// I2CnEnum aI2C: le channel i2c en question
//------------------------------------------------------------
void iI2C_GenerateStart(I2CnEnum aI2C);

//------------------------------------------------------------
// Sélection du mode d'émission ou de réception
// I2CnEnum aI2C: le channel i2c en question
// I2CTransmiteModeEnum aMode: le mode choisi
//------------------------------------------------------------
void iI2C_TransmiteModeSelect(I2CnEnum aI2C, I2CTransmiteModeEnum aMode);

//------------------------------------------------------------
// Envoi d'une donnée
// I2CnEnum aI2C: le channel i2c en question
// UInt8 aData: Envoi de la data (8 bits) ou de l'adresse du destinataire (7bits)
// RdWrModeEnum aRdWr: Sense de communication (écriture, lecture, ou rien)
//------------------------------------------------------------
void iI2C_SendData(I2CnEnum aI2C, UInt8 aData, RdWrModeEnum aRdWr);

//------------------------------------------------------------
// Attente de la bonne réception ou du bon envoi d'un byte
//------------------------------------------------------------
void i2c_Wait(I2CnEnum aI2C);

//------------------------------------------------------------
// Génération d'un repeated start
// I2CnEnum aI2C: le channel i2c en question
//------------------------------------------------------------
void iI2C_GenerateRepeatedStart(I2CnEnum aI2C);

//------------------------------------------------------------
// Generate ack or nack
// I2CnEnum aI2C: le channel i2c en question
//------------------------------------------------------------
void iI2C_GenerateAck(I2CnEnum aI2C,I2CAckEnum aAck);

//------------------------------------------------------------
// Generate clock for receiving
// I2CnEnum aI2C: le channel i2c en question
//------------------------------------------------------------
void iI2C_GenerateClk(I2CnEnum aI2C);

//------------------------------------------------------------
// lecture des données
// I2CnEnum aI2C: le channel i2c en question
//------------------------------------------------------------
UInt8 iI2C_ReadData(I2CnEnum aI2C);

//------------------------------------------------------------
// Finir une transmission
// I2CnEnum aI2C: le channel i2c en question
//------------------------------------------------------------
void iI2C_GenerateStop(I2CnEnum aI2C);

//------------------------------------------------------------
// lire les status
// I2CnEnum aI2C: le channel i2c en question
// I2CStatusEnum aStatus: le status
//------------------------------------------------------------
bool iI2C_ReadStatus(I2CnEnum aI2C, I2CStatusEnum aStatus);

//------------------------------------------------------------
// Active l'ack automatique à la reception
//------------------------------------------------------------

void iI2C_EnableTxAck(void);
//------------------------------------------------------------
// Désactive l'ack automatique à la reception
//------------------------------------------------------------

void iI2C_DisableTxAck(void);



#endif /* I2C_H_ */

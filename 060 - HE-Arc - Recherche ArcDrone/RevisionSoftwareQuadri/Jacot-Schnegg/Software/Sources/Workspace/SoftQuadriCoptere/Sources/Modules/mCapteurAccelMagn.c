#include "mCapteurAccelMagn.h"
#include "iI2C.h"
#include "iDio.h"

//------------------------------------------------------------
// Ecriture d'un registre de l'accéléromètre/Magnétomètre
//------------------------------------------------------------
bool mCapteurAccelMagn_WriteByte(AccelMagnAddrEnum aAddrModule, UInt8 aAddrReg, UInt8 aData);

//------------------------------------------------------------
// Lecture d'un registre de l'accéléromètre/Magnétomètre
//------------------------------------------------------------
UInt8 mCapteurAccelMagn_ReadByte(AccelMagnAddrEnum aAddrModule, UInt8 aAddrReg);

//------------------------------------------------------------
// Lecture de n registres de l'accéléromètre/Magnétomètre
//------------------------------------------------------------
bool mCapteurAccelMagn_ReadAllAxes(AccelMagnAddrEnum aAddrModule, UInt8 aAddrReg, UInt8 n, UInt8 *tabReturn);

//------------------------------------------------------------
// Setup
//------------------------------------------------------------
void mCapteurAccelMagn_Setup(void)
{
	//Set des I/O
	iDio_SetPortDirection(kPortB, kMaskIo0, kIoOutput);
	iDio_SetPortDirection(kPortB, kMaskIo1, kIoOutput);

	//Configuration accelerometre
	// Data rate selection: 25 Hz
	// Power mode: normal mode
	// Enable axes: X enable, Y enable, Z enable
	mCapteurAccelMagn_WriteByte(kAccelAddr, 0x20, 0x37);
	// Full-scale selection: +- 2G
	mCapteurAccelMagn_WriteByte(kAccelAddr, 0x23, 0x00);

	//Configuration Magnétomètre
	//Data output rate magnétomètre: 30 Hz
	mCapteurAccelMagn_WriteByte(kMagnAddr, 0x00, 0x14);
	//Set gain: 1100 (980), +-1.3 Gauss
	mCapteurAccelMagn_WriteByte(kMagnAddr, 0x01, 0x20);
	//Set acquisition mode: Continous mode
	mCapteurAccelMagn_WriteByte(kMagnAddr, 0x02, 0x00);
}

//------------------------------------------------------------
// Open
//------------------------------------------------------------
void mCapteurAccelMagn_Open(void)
{

}

//------------------------------------------------------------
// Close
//------------------------------------------------------------
void mCapteurAccelMagn_Close(void)
{
}

//------------------------------------------------------------
// Ecriture d'un registre  de l'accéléromètre/Magnétomètre
//------------------------------------------------------------
bool mCapteurAccelMagn_WriteByte(AccelMagnAddrEnum aAddrModule, UInt8 aAddrReg, UInt8 aData)
{
	while (iI2C_ReadStatus(kI2C0, kBUSY) == true)
		;

	iI2C_TransmiteModeSelect(kI2C0, kTxMode);

	iI2C_GenerateStart(kI2C0);

	iI2C_SendData(kI2C0, aAddrModule, kWrite);
	i2c_Wait(kI2C0);
	if (iI2C_ReadStatus(kI2C0, RxAK) == true)
	{
		return false;
	}

	iI2C_SendData(kI2C0, aAddrReg, kNoRW);
	i2c_Wait(kI2C0);
	if (iI2C_ReadStatus(kI2C0, RxAK) == true)
	{
		return false;
	}

	iI2C_SendData(kI2C0, aData, kNoRW);
	i2c_Wait(kI2C0);
	if (iI2C_ReadStatus(kI2C0, RxAK) == true)
	{
		return false;
	}

	iI2C_GenerateStop(kI2C0);

	return true;
}

//------------------------------------------------------------
// Lecture d'un registre de l'accéléromètre/Magnétomètre
//------------------------------------------------------------
UInt8 mCapteurAccelMagn_ReadByte(AccelMagnAddrEnum aAddrModule, UInt8 aAddrReg)
{
	UInt8 aRetVal = 0;

	while (iI2C_ReadStatus(kI2C0, kBUSY) == true)
		;

	iI2C_TransmiteModeSelect(kI2C0, kTxMode);

	iI2C_GenerateStart(kI2C0);

	iI2C_SendData(kI2C0, aAddrModule, kWrite);
	i2c_Wait(kI2C0);
	if (iI2C_ReadStatus(kI2C0, RxAK) == true)
	{
		return 0;
	}

	iI2C_SendData(kI2C0, aAddrReg, kNoRW);
	i2c_Wait(kI2C0);
	if (iI2C_ReadStatus(kI2C0, RxAK) == true)
	{
		return 0;
	}

	iI2C_GenerateRepeatedStart(kI2C0);

	iI2C_SendData(kI2C0, aAddrModule, kRead);
	i2c_Wait(kI2C0);
	if (iI2C_ReadStatus(kI2C0, RxAK) == true)
	{
		return 0;
	}

	iI2C_TransmiteModeSelect(kI2C0, kRxMode);

	iI2C_DisableTxAck();

	iI2C_ReadData(kI2C0);
	i2c_Wait(kI2C0);

	iI2C_GenerateStop(kI2C0);

	return iI2C_ReadData(kI2C0);
}

//------------------------------------------------------------
// Lecture de n registres de l'accéléromètre/Magnétomètre
//------------------------------------------------------------
bool mCapteurAccelMagn_ReadAllAxes(AccelMagnAddrEnum aAddrModule, UInt8 aAddrReg, UInt8 n, UInt8 *tabReturn)
{
	UInt8 i = 0;

	// Attente que le bus soit libre
	while (iI2C_ReadStatus(kI2C0, kBUSY) == true)
		;

	// Mode envoi
	iI2C_TransmiteModeSelect(kI2C0, kTxMode);

	// Génération du start
	iI2C_GenerateStart(kI2C0);

	// Envoi de l'adresse du module (écriture)
	iI2C_SendData(kI2C0, aAddrModule, kWrite);
	i2c_Wait(kI2C0);
	if (iI2C_ReadStatus(kI2C0, RxAK) == true) // Test ACK
	{
		return false;
	}

	// Envoi de l'adresse du registre
	iI2C_SendData(kI2C0, 0x80 + aAddrReg, kNoRW); // MSB à 1 pour activer l'auto-incrément de l'adresse
	i2c_Wait(kI2C0);
	if (iI2C_ReadStatus(kI2C0, RxAK) == true)
	{
		return false;
	}

	// Génération du repeated start
	iI2C_GenerateRepeatedStart(kI2C0);

	// Envoi de l'adresse du module (lecture)
	iI2C_SendData(kI2C0, aAddrModule, kRead);
	i2c_Wait(kI2C0);
	if (iI2C_ReadStatus(kI2C0, RxAK) == true)
	{
		return false;
	}

	// Mode réception
	iI2C_TransmiteModeSelect(kI2C0, kRxMode);

	// ACK automatique activé
	iI2C_EnableTxAck();

	// Lecture des n-1 premiers registres + ACK
	iI2C_ReadData(kI2C0); // Génération du signal d'horloge pour pouvoir ensuite lire le 1er octet
	i2c_Wait(kI2C0);
	for (i = 0; i < n - 1; i++)
	{
		tabReturn[i] = iI2C_ReadData(kI2C0);
		i2c_Wait(kI2C0);
	}

	// ACK automatique désactivé
	iI2C_DisableTxAck();

	// Lecture du dernier registre + NACK
	tabReturn[i] = iI2C_ReadData(kI2C0);
	i2c_Wait(kI2C0);

	// Génération du stop
	iI2C_GenerateStop(kI2C0);

	// Génération du signal d'horloge pour bien arrêter le bus
	iI2C_ReadData(kI2C0);

	return true;
}

//------------------------------------------------------------
// Lecture de tous les axes de l'accéléromètre
//------------------------------------------------------------
bool mCapteurAccelMagn_ReadAllAccelAxes(UInt16 *tabReturn)
{
	UInt8 tempTab[6];
	bool result;

	if (mCapteurAccelMagn_ReadByte(kAccelAddr, 0x27) & 0x08) // Test si ZYXDA = 1
	{
		result = mCapteurAccelMagn_ReadAllAxes(kAccelAddr, kAccelAxe_X, 6, tempTab); // kAccelAxe_X = 1er des 6 registres !

		if (result)
		{
			tabReturn[0] = (((UInt16) tempTab[1]) << 8) + ((UInt16) tempTab[0]);
			tabReturn[1] = (((UInt16) tempTab[3]) << 8) + ((UInt16) tempTab[2]);
			tabReturn[2] = (((UInt16) tempTab[5]) << 8) + ((UInt16) tempTab[4]);
		}

		return result;
	}
	else
	{
		return false;
	}
}

//------------------------------------------------------------
// Lecture de tous les axes du magnétomètre
//------------------------------------------------------------
bool mCapteurAccelMagn_ReadAllMagnAxes(UInt16 *tabReturn)
{
	UInt8 tempTab[6];
	bool result;

	if (mCapteurAccelMagn_ReadByte(kMagnAddr, 0x09) & 0x01) // Test si DRDY = 1
	{
		result = mCapteurAccelMagn_ReadAllAxes(kMagnAddr, kMagnAxe_X, 6, tempTab); // kMagnAxe_X = 1er des 6 registres !

		if (result)
		{
			tabReturn[0] = (((UInt16) tempTab[0]) << 8) + ((UInt16) tempTab[1]);
			tabReturn[1] = (((UInt16) tempTab[2]) << 8) + ((UInt16) tempTab[3]);
			tabReturn[2] = (((UInt16) tempTab[4]) << 8) + ((UInt16) tempTab[5]);
		}

		if (mCapteurAccelMagn_ReadByte(kMagnAddr, 0x09) & 0x02) // Test si LOCK = 1
		{
			// Reconfiguration du mode -> Permet de remettre LOCK à 0
			// Normalement fait une fois qu'on a lu les 6 valeurs (pas de blocage s'il y a un bug)
			mCapteurAccelMagn_WriteByte(kMagnAddr, 0x02, 0x00);
		}

		return result;
	}
	else
	{
		return false;
	}
}

/*
 * mRfInterface.h
 *
 *  Created on: 3 juil. 2012
 *      Author: favrebm1
 */

#ifndef MRFINTERFACE_H_
#define MRFINTERFACE_H_

//------------------------------------------------------------
// UART setup de la communication RF
//------------------------------------------------------------
void mRfInterface_Setup(void);

//------------------------------------------------------------
// Open module RF
//------------------------------------------------------------
void mRfInterface_Open();

//------------------------------------------------------------
// Close module RF
//------------------------------------------------------------
void mRfInterface_Close();

//------------------------------------------------------------
// Envoi d'un byte par le module RF
//------------------------------------------------------------
void mRfInterface_SendByte(UInt8 aData);

//------------------------------------------------------------
// Envoi d'un tableau de donnée par le module RF
// UInt8 aArray[]: Un pointeur sur le tableau de donnée
// UInt8 lengthArray: La taille du tableau
//------------------------------------------------------------
void mRfInterface_SendArray(UInt8 aArray[],UInt8 lengthArray);

//------------------------------------------------------------
// Envoi d'une chaine de caractères au module RF
// UInt8 *aString: Un pointeur sur une chaine de caratères
//------------------------------------------------------------
void mRfInterface_SendString(UInt8 *aString);

//------------------------------------------------------------
// Lecture d'un byte dans le buffer de réception
// UInt8 *aRetPtr: pointeur sur la variable de retour
//Renvoie l'état de la donnée: true donnée valide/ false donnée invalide
//------------------------------------------------------------
bool mRfInterface_ReadByteFromBuffer(UInt8 *aRetPtr);

//------------------------------------------------------------
// Lecture d'une trame de x bytes dans le buffer de réception
// UInt8 aTrame[]: pointeur sur le tableau de retour
// UInt8 lengthTrame: Taille de la trame attendue
//Attention, la fonction est bloquante lorsqu'elle ne reçois pas le bon nombre de bytes
//------------------------------------------------------------
void mRfInterface_ReadTrameFromBuffer(UInt8 aTrame[],UInt8 lengthTrame);


#endif /* MRFINTERFACE_H_ */

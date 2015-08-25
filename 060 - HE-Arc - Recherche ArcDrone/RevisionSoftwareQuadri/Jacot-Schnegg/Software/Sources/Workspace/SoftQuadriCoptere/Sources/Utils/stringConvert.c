#include "stringConvert.h"
#include <stdio.h>

//------------------------------------------------------------
// conversion d'un UInt16 en chaine de caract�re
//------------------------------------------------------------
void stringConvert_UInt16ToChar(UInt16 aUInt16, UInt8 *aString)
{
	sprintf((char*)aString,"%d",aUInt16);	
}

//------------------------------------------------------------
// conversion d'un float en chaine de caract�re
//------------------------------------------------------------
void stringConvert_FloatToChar(float aFloat, UInt8* aString)
{
	sprintf((char*)aString,"%.3f",aFloat);
}

/*
------------------------------------------------------------
Copyright 2003-2012 Haute école ARC Ingéniérie, Switzerland. 
All rights reserved.
------------------------------------------------------------
File name :	iDio.c
Author and date :	Monnerat Serge 23 févr. 2012

Description in the header (.h)

-----------------------------------------------------------------------------
History:
-----------------------------------------------------------------------------

$History: $

-----------------------------------------------------------------------------
*/

#include "iDio.h"
#include "derivative.h"

//-----------------------------------------------------------------------------
// IO ports direction setup
// aPort: which IO port
// aMask: which port pin(s) to configure
// aDir:  input or output
//-----------------------------------------------------------------------------
void iDio_SetPortDirection(PortIOEnum aPort,IoMaskEnum aMask,IoDirectionEnum aDir)
{
	UInt32 *aPortPtr;
  
  // Port Data Direction Register (GPIOx_PDDR)
	// K10 Sub-Family Reference Manual, Rev. 6, Nov 2011 page 1528
  switch(aPort)
    {
      // GPIOA_PDDR
      case kPortA:
        aPortPtr=(UInt32 *)&GPIOA_PDDR;
      break;
      
      // GPIOB_PDDR
      case kPortB:
        aPortPtr=(UInt32 *)&GPIOB_PDDR;
      break;
      
      // GPIOC_PDDR
			case kPortC:
				aPortPtr=(UInt32 *)&GPIOC_PDDR;
			break;
			
			// GPIOD_PDDR
			case kPortD:
				aPortPtr=(UInt32 *)&GPIOD_PDDR;
			break;
      // GPIOE_PDDR
      case kPortE:
        aPortPtr=(UInt32 *)&GPIOE_PDDR;
      break;
    }
    
  // IO direction setup 
  if(kIoOutput==aDir)
    {
      *aPortPtr|=aMask;
    }
  else if(kIoInput==aDir)
    {
      *aPortPtr &=~aMask;
    }
}

//-----------------------------------------------------------------------------
// Output pin set state
// aPort: which IO port
// aMask: which port pin(s) to configure
// aState:  output pin state
//-----------------------------------------------------------------------------
void iDio_SetPort(PortIOEnum aPort,IoMaskEnum aMask,IoStateEnum aState)
{
	UInt32 *aPortSetPtr;
	UInt32 *aPortClrPtr;
  
	// Port Data Output Register (GPIOx_PDOR)
	// Port Clear Output Register (GPIOx_PCOR)
	// K10 Sub-Family Reference Manual, Rev. 6, Nov 2011 page 1528
	switch(aPort)
		{
			// GPIOA_PDOR & GPIOA_PCOR
			case kPortA:
				aPortSetPtr=(UInt32 *)&GPIOA_PDOR;
				aPortClrPtr=(UInt32 *)&GPIOA_PCOR;
			break;
			
			// GPIOB_PDOR & GPIOB_PCOR
			case kPortB:
				aPortSetPtr=(UInt32 *)&GPIOB_PDOR;
				aPortClrPtr=(UInt32 *)&GPIOB_PCOR;
			break;
			
			// GPIOC_PDOR & GPIOC_PCOR
			case kPortC:
				aPortSetPtr=(UInt32 *)&GPIOC_PDOR;
				aPortClrPtr=(UInt32 *)&GPIOC_PCOR;
			break;
			
			// GPIOD_PDOR & GPIOD_PCOR
			case kPortD:
				aPortSetPtr=(UInt32 *)&GPIOD_PDOR;
				aPortClrPtr=(UInt32 *)&GPIOD_PCOR;
			break;
			// GPIOE_PDOR & GPIOE_PCOR
			case kPortE:
				aPortSetPtr=(UInt32 *)&GPIOE_PDOR;
				aPortClrPtr=(UInt32 *)&GPIOE_PCOR;
			break;
		}
    
  // Set or reset the output
  if(kIoOn==aState)
    {
      *aPortSetPtr|=aMask;
    }
  else if(kIoOff==aState)
    {
      *aPortClrPtr|=aMask;
    }
}

//-----------------------------------------------------------------------------
// Read input pin state
// aPort: which IO port
// aMask: which port pin(s) to configure 
// return:  input pin state
//-----------------------------------------------------------------------------
bool iDio_GetPort(PortIOEnum aPort, IoMaskEnum aMask)
{
  bool  aRet=false;
  UInt32 *aPortPtr;
  
  // Port Data Input Register (GPIOx_PDIR)
	// K10 Sub-Family Reference Manual, Rev. 6, Nov 2011 page 1528
	switch(aPort)
		{
			// GPIOA_PDIR
			case kPortA:
				aPortPtr=(UInt32 *)&GPIOA_PDIR;
			break;
			
			// GPIOB_PDIR
			case kPortB:
				aPortPtr=(UInt32 *)&GPIOB_PDIR;
			break;
			
			// GPIOC_PDIR
			case kPortC:
				aPortPtr=(UInt32 *)&GPIOC_PDIR;
			break;
			
			// GPIOD_PDIR
			case kPortD:
				aPortPtr=(UInt32 *)&GPIOD_PDIR;
			break;
			// GPIOE_PDIR
			case kPortE:
				aPortPtr=(UInt32 *)&GPIOE_PDIR;
			break;
		}
    
  // Input pin state
  aRet=(bool)((*aPortPtr&aMask)==aMask);
  
  return aRet;
}

//-----------------------------------------------------------------------------
// Set PORTA interrupt
// aPinNumber: portA pin number 
// aPriority: interrupt priority
// aMode: state, rising or falling edge 
//-----------------------------------------------------------------------------
bool iDio_SetPortAInt(UInt16 aPinNumber, UInt16 aPriority,IOIrqModeEnum aMode)
{
	UInt32 aTmp;
	
	// K10 Sub-Family Reference Manual, Rev. 6, Nov 2011 page 1018
	// Pin Control Register n (PORTx_PCRn)
	// Enable & setup PTA0 interrupt
	PORTA_PCR(aPinNumber)&=(~PORT_PCR_IRQC_MASK);
	PORTA_PCR(aPinNumber)|=PORT_PCR_IRQC(aMode);

	// IRQ bit offset in the following registers
	aTmp=87%32;
	// DUI0553A_cortex_m4_dgug.pdf page page 222 
	// Interrupt Clear-pending Registers
	// Clear prending interrupt
	NVICICPR2|=(1<<aTmp);
	// DUI0553A_cortex_m4_dgug.pdf page page 220
	// Interrupt Set-enable Registers
	// Interrupt enable
	NVICISER2|=(1<<aTmp);
	// DUI0553A_cortex_m4_dgug.pdf page page 223
	// Interrupt Priority Registers
	// Set interrupt priority
	NVIC_IP(87)=aPriority;
}

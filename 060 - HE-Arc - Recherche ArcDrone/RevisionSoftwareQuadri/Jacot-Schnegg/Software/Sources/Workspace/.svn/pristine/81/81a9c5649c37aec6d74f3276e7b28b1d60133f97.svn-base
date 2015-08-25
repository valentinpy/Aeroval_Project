/*
------------------------------------------------------------
Copyright 2003-2012 Haute école ARC Ingéniérie, Switzerland. 
All rights reserved.
------------------------------------------------------------
File name :	iUart.c
Author and date :	Monnerat Serge 5 mars 2012

Description in the header (.h)

-----------------------------------------------------------------------------
History:
-----------------------------------------------------------------------------

$History: $

-----------------------------------------------------------------------------
*/

#include "iUart.h"
#include "derivative.h"

#define kUart0BaudRate 9600

// 50 bytes buffer
#define kSciRecBufSize ((UInt8)(200)) 


// RX buffer control struct
static struct
{
	Int8     SciRecBuf[kSciRecBufSize];
	UInt16 	  InIndex;
	UInt16 	  OutIndex;
	UInt16    ByteCount;
	bool      BufferIsFull;
}sSciRecBufStruct;

//-----------------------------------------------------------------------
// UART 2 module configuration
//-----------------------------------------------------------------------
void iUart_Config(void)
{
	UInt16 aSbr;
	UInt8 aTmp;
	UInt16 aBrfa;
	
	// UART Control Register 2 (UARTx_C2)
	// K10 Sub-Family Reference Manual, Rev. 6, Nov 2011 page 1266
	// Disable TX & RX before setup
	UART0_C2&= ~(UART_C2_TE_MASK|UART_C2_RE_MASK );
	
	// IRQ Config
	// IRQ bit offset in the following registers
	aTmp=45%32;
	// DUI0553A_cortex_m4_dgug.pdf page page 222 
	// Interrupt Clear-pending Registers
	// Clear prending interrupt
	NVICICPR1|=(1<<aTmp);
	// DUI0553A_cortex_m4_dgug.pdf page page 220
	// Interrupt Set-enable Registers
	// Interrupt enable
	NVICISER1|=(1<<aTmp);
	// DUI0553A_cortex_m4_dgug.pdf page page 223
	// Interrupt Priority Registers
	// Set interrupt priority
	NVICIP45=kUart0_IntPriority;
	
	// UART Control Register 1 (UARTx_C1)
	// K10 Sub-Family Reference Manual, Rev. 6, Nov 2011 page 1263
	// Loop Mode Select=0,Normal operation 
	// UARTSWAI=0, UART clock continues to run in wait mode
	// RSRC=0,Selects internal loop back mode and receiver input is internally connected to transmitter output
	// M=0, Normal - start + 8 data bits (MSB/LSB first as determined by MSBF) + stop
	// WAKE=0,Idle-line wakeup
	// ILT=0,Idle character bit count starts after start bit
	// PE=0,Parity function disabled
	// PT=0,Even parity 
	UART0_C1= 0;	/* We need all default settings, so entire register is cleared */
	
//LSB FIRST
	UART0_S2&=~UART_S2_MSBF_MASK;
	
	// UART Baud Rate Registers:High (UARTx_BDH)
	// UART Baud Rate Registers: Low (UARTx_BDL)
	// K10 Sub-Family Reference Manual, Rev. 6, Nov 2011 page 1262
	// Calculate baud rate settings
	aSbr = (UInt16)((kClockCpukHz*1000)/(kUart0BaudRate * 16));		
	// Save off the current value of the UARTx_BDH except for the SBR field
	aTmp = UART0_BDH & ~(UART_BDH_SBR(0x1F));
	UART0_BDH= aTmp |  UART_BDH_SBR(((aSbr & 0x1F00) >> 8));
	UART0_BDL= (UInt8)(aSbr & UART_BDL_SBR_MASK);
	
	// UART Control Register 4 (UARTx_C4)
	// K10 Sub-Family Reference Manual, Rev. 6, Nov 2011 page 1276
	// BRFA, Baud Rate Fine Adjust
	// Determine if a fractional divider is needed to get closer to the baud rate
	aBrfa = (((kClockCpukHz*32000)/(kUart0BaudRate * 16)) - (aSbr * 32));
	// Save off the current value of the UARTx_C4 register except for the BRFA field */
	aTmp = UART0_C4 & ~(UART_C4_BRFA(0x1F));
	UART0_C4= aTmp | UART_C4_BRFA(aBrfa);    
	
	// UART FIFO Parameters (UARTx_PFIFO)
	// K10 Sub-Family Reference Manual, Rev. 6, Nov 2011 page 1281
	// TXFE=1,Transmit FIFO is enabled. Buffer is depth indicted by TXFIFOSIZE
	// TXFIFOSIZE=3,Transmit FIFO/Buffer Depth = 16 Datawords 
	UART0_PFIFO=0;
	UART0_PFIFO|=(UART_PFIFO_TXFE_MASK|UART_PFIFO_TXFIFOSIZE(3));
	
	// UART FIFO Control Register (UARTx_CFIFO)
	// K10 Sub-Family Reference Manual, Rev. 6, Nov 2011 page 1283
	// Flush RX & TX fifo
	UART0_CFIFO|=(UART_CFIFO_TXFLUSH_MASK|UART_CFIFO_RXFLUSH_MASK);
	
	// UART Control Register 2 (UARTx_C2)
	// K10 Sub-Family Reference Manual, Rev. 6, Nov 2011 page 1265
	// TIE=0, TDRE interrupt and DMA transfer requests disabled
	// TCIE=0, TC interrupt requests disabled
	// RIE=1,RDRF interrupt or DMA transfer requests enabled
	// ILIE=0,IDLE interrupt requests disabled
	// TE & RE =1, Enable receiver and transmitter
	UART0_C2=0;
	UART0_C2|= (UART_C2_TE_MASK|UART_C2_RE_MASK|UART_C2_RIE_MASK);
	
	
}

//------------------------------------------------------------
// Ouverture des ports de l'uart
//------------------------------------------------------------
void iUart_Open(void)
{
	//Enable Rx & Tx
	UART0_C2|= (UART_C2_TE_MASK|UART_C2_RE_MASK );
}

//------------------------------------------------------------
// Fermeture des ports de l'uart
//------------------------------------------------------------
void iUart_Close(void)
{
	//Enable Rx & Tx
	UART0_C2&= ~(UART_C2_TE_MASK|UART_C2_RE_MASK );
}


//------------------------------------------------------------
// Get Uart2 flags state
// aStatus: which flag to read
// retour	: flag state
//------------------------------------------------------------
bool iUart_GetStatus(UartStatusEnum aStatus)
{
	// UART Status Register 1 (UARTx_S1)
	// K10 Sub-Family Reference Manual, Rev. 6, Nov 2011 page 1267
	return ((UART0_S1&aStatus)==aStatus);
}

//------------------------------------------------------------
// Get Uart2 fifo flags state
// aStatus: which flag to read
// retour	: flag state
//------------------------------------------------------------
bool iUart_GetFifoStatus(UartFifoStatusEnum aStatus)
{
	// UART Status Register 1 (UARTx_S1)
	// K10 Sub-Family Reference Manual, Rev. 6, Nov 2011 page 1267
	return ((UART0_SFIFO&aStatus)==aStatus);
}


//------------------------------------------------------------
// Uart2 Data register write
// aData: datas to transmit
//------------------------------------------------------------
void iUart_SetData(UInt8 aData)
{
	// UART Data Register (UARTx_D)
	// K10 Sub-Family Reference Manual, Rev. 6, Nov 2011 page 1274
	UART0_D=aData;
}

//------------------------------------------------------------
// Check if the buffer is empty
// Return : true --> buffer empty, false --> buffer not empty
//------------------------------------------------------------
bool iUart_IsBufferEmpty(void)
{
	bool aRet=false;
	
	if(sSciRecBufStruct.ByteCount==0)
		{
			aRet=true;
		}
	else
		{
			aRet=false;
		}

	return aRet;
}

//------------------------------------------------------------
// Byte read in the RX buffer
// Return : oldest byte in the buffer
//------------------------------------------------------------
Int8 iUart_GetCharFromBuffer(void)
{
  Int8 aChar=0;
	
	// Byte read
	aChar=sSciRecBufStruct.SciRecBuf[sSciRecBufStruct.OutIndex];
	
	// Index inc
	sSciRecBufStruct.OutIndex++;
	
	// Turning buffer
	if(sSciRecBufStruct.OutIndex>=kSciRecBufSize)
		{
			sSciRecBufStruct.OutIndex=0;
		}
	
	// Byte counter dec
	sSciRecBufStruct.ByteCount--;
	 
	// Retourne un byte du buffer
	return aChar;
}

//---------------------------------------------------------------------------
// RX interrupt 
//---------------------------------------------------------------------------
void iUart0_INTRx(void)
{
	Int8 aVal;
	static UInt8 aRxStatus;
	
	// Read the status register to clear the RDRF flag
	aRxStatus=UART0_S1;
	
	// Read the RX byte
	aVal=UART0_D;

	if(sSciRecBufStruct.ByteCount>=kSciRecBufSize)
	  {
	    // Buffer full flag
	    sSciRecBufStruct.BufferIsFull=true;
	  }
	else
	  {
	    // Buffer not full flag
	    sSciRecBufStruct.BufferIsFull=false;
	    
	    // Save received data
	    sSciRecBufStruct.SciRecBuf[sSciRecBufStruct.InIndex]=aVal;
	    
	    // Index inc
	    sSciRecBufStruct.InIndex++;
	    
	    // Bytes counter inc	
	    sSciRecBufStruct.ByteCount++;
	
	    // Turning buffer
	    if(sSciRecBufStruct.InIndex>=kSciRecBufSize)
	      {
	        sSciRecBufStruct.InIndex=0;
	      }
	  }	
}



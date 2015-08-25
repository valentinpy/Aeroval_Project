/*
------------------------------------------------------------
Copyright 2003-2012 Haute �cole ARC Ing�ni�rie, Switzerland. 
All rights reserved.
------------------------------------------------------------
Nom du fichier :	iSpi.c
Auteur et Date :	Monnerat Serge 24.11.2012

Description dans le fichier d'ent�te (.h)

-----------------------------------------------------------------------------
Historique:
-----------------------------------------------------------------------------

$History: $

-----------------------------------------------------------------------------
*/

#include "iSpi.h"
#include "derivative.h"

//-------------------------------------------------------------------------
// Constants
//-------------------------------------------------------------------------

//-----------------------------------------------------------------------
// SPI module configuration
// aSpi:which SPI (0,1 or 2)
//-----------------------------------------------------------------------
void iSpi_ConfigSPIModule(SPIEnum aSpi)
{
	switch(aSpi)
			{
				case kSpi0:
					// DSPI Module Configuration Register (SPIx_MCR)
					// K10 Sub-Family Reference Manual, Rev. 6, Nov 2011 page 1171
					// Master/Slave Mode Select --> master
					// Continuous SCK Enable --> disabled
					// DSPI Configuration --> SPI
					// Freeze --> Do not halt serial transfers in debug mode
					// Modified Timing Format Enable --> Modified SPI transfer format disabled
					// Peripheral Chip Select Strobe Enable --> PCS[5]/PCSS is used as the Peripheral Chip Select[5] signal
					// Receive FIFO Overflow Overwrite Enable --> Incoming data is ignored
					// Peripheral Chip Select x Inactive State --> The inactive state of PCSx is high
					// Doze Enable --> Doze mode has no effect on DSPI
					// Module Disable --> Enable DSPI clocks
					// Disable Transmit FIFO --> Tx FIFO is enabled
					// Disable Receive FIFO --> Rx FIFO is enabled
					// Clear TX FIFO --> Do not clear the Tx FIFO counter 
					// Flushes the RX FIFO --> Do not clear the Rx FIFO counter
					// Sample Point --> 0 system clocks between SCK edge and SIN sample
					// Halt --> Stop transfers.
					// Reset fields
					SPI0_MCR&=0x0000000;
					SPI0_MCR|=((SPI_MCR_MSTR_MASK)|(SPI_MCR_PCSIS(7))|(SPI_MCR_HALT_MASK));
					
					
				break;
				case kSpi1:
					// DSPI Module Configuration Register (SPIx_MCR)
					// K10 Sub-Family Reference Manual, Rev. 6, Nov 2011 page 1171
					// Master/Slave Mode Select --> master
					// Continuous SCK Enable --> disabled
					// DSPI Configuration --> SPI
					// Freeze --> Do not halt serial transfers in debug mode
					// Modified Timing Format Enable --> Modified SPI transfer format disabled
					// Peripheral Chip Select Strobe Enable --> PCS[5]/PCSS is used as the Peripheral Chip Select[5] signal
					// Receive FIFO Overflow Overwrite Enable --> Incoming data is ignored
					// Peripheral Chip Select x Inactive State --> The inactive state of PCSx is high
					// Doze Enable --> Doze mode has no effect on DSPI
					// Module Disable --> Enable DSPI clocks
					// Disable Transmit FIFO --> Tx FIFO is enabled
					// Disable Receive FIFO --> Rx FIFO is enabled
					// Clear TX FIFO --> Do not clear the Tx FIFO counter 
					// Flushes the RX FIFO --> Do not clear the Rx FIFO counter
					// Sample Point --> 0 system clocks between SCK edge and SIN sample
					// Halt --> Stop transfers.
					// Reset fields
					SPI1_MCR&=0x0000000;
					SPI1_MCR|=((SPI_MCR_MSTR_MASK)|(SPI_MCR_PCSIS(7))|(SPI_MCR_HALT_MASK));	
				break;
				case kSpi2:
					// DSPI Module Configuration Register (SPIx_MCR)
					// K10 Sub-Family Reference Manual, Rev. 6, Nov 2011 page 1171
					// Master/Slave Mode Select --> master
					// Continuous SCK Enable --> disabled
					// DSPI Configuration --> SPI
					// Freeze --> Do not halt serial transfers in debug mode
					// Modified Timing Format Enable --> Modified SPI transfer format disabled
					// Peripheral Chip Select Strobe Enable --> PCS[5]/PCSS is used as the Peripheral Chip Select[5] signal
					// Receive FIFO Overflow Overwrite Enable --> Incoming data is ignored
					// Peripheral Chip Select x Inactive State --> The inactive state of PCSx is high
					// Doze Enable --> Doze mode has no effect on DSPI
					// Module Disable --> Enable DSPI clocks
					// Disable Transmit FIFO --> Tx FIFO is enabled
					// Disable Receive FIFO --> Rx FIFO is enabled
					// Clear TX FIFO --> Do not clear the Tx FIFO counter 
					// Flushes the RX FIFO --> Do not clear the Rx FIFO counter
					// Sample Point --> 0 system clocks between SCK edge and SIN sample
					// Halt --> Stop transfers.
					// Reset fields
					SPI2_MCR&=0x0000000;
					SPI2_MCR|=((SPI_MCR_MSTR_MASK)|(SPI_MCR_PCSIS(0))|(SPI_MCR_HALT_MASK));					
				break;
			}
}

//-----------------------------------------------------------------------
// SPI clock and transfert configuration
// aSpi:which SPI (0,1 or 2)
// aCfg:which config register (CTAR0 or CTAR1)
//-----------------------------------------------------------------------
void iSpi_ConfigClockAndTransfert(SPIEnum aSpi,SpiCfgRegisterEnum aCfg)
{
	// K10 Sub-Family Reference Manual, Rev. 6, Nov 2011 page 1174
	// DSPI Clock and Transfer Attributes Register
	switch(aSpi)
		{
			case kSpi0:
				if(kCTAR0==aCfg)
					{
						// Fields reset
						SPI0_CTAR0&=0x00000000;
						// Double Baud Rate --> The baud rate is computed normally with a 50/50 duty cycle
						// Frame Size --> 8 bits 
						// Clock Polarity --> The inactive state value of SCK is low
						// Clock Phase --> Data is captured on the leading edge of SCK and changed on the following edge
						// LBS First --> Data is transferred MSB first
						// PCSSCK: PCS to SCK Delay Prescaler --> PCS to SCK Prescaler value is 1
						// PASC:After SCK Delay Prescaler --> Delay after Transfer Prescaler value is 1 
						// PDT:Delay after Transfer Prescaler --> Delay after Transfer Prescaler value is 1
						// CSSCK:PCS to SCK Delay Scaler --> tCSC = (1/fSYS) x PCSSCK x CSSCK --> (1/50MHz)*1*2 
						// ASC: After SCK Delay Scaler --> tASC = (1/fSYS) x PASC x ASC --> (1/50MHz)*1*1
						// DT:Delay After Transfer Scaler --> tDT = (1/fSYS) x PDT x DT --> (1/50MHz)*1*1  
						// Baud Rate config
						// SCK baud rate = (fSYS/PBR) x [(1+DBR)/BR]
						// with fsys=fbus=50MHz
						// PBR = 0 div by 2
						// DBR = 0 (50% duty cycle)
						// BR = 0 --> div by 2
						// SPI Clock = (50MHz/2) * (1/2)=12.5MHz
						SPI0_CTAR0|=((SPI_CTAR_FMSZ(7))|(SPI_CTAR_ASC(1))|(SPI_CTAR_DT(1))|(SPI_CTAR_PBR(2))|(SPI_CTAR_BR(0)));
					}
				else if(kCTAR1==aCfg)
					{
						// Fields reset
						SPI0_CTAR1&=0x00000000;
						// Double Baud Rate --> The baud rate is computed normally with a 50/50 duty cycle
						// Frame Size --> 8 bits 
						// Clock Polarity --> The inactive state value of SCK is low
						// Clock Phase --> Data is captured on the leading edge of SCK and changed on the following edge
						// LBS First --> Data is transferred MSB first
						// PCSSCK: PCS to SCK Delay Prescaler --> PCS to SCK Prescaler value is 1
						// PASC:After SCK Delay Prescaler --> Delay after Transfer Prescaler value is 1 
						// PDT:Delay after Transfer Prescaler --> Delay after Transfer Prescaler value is 1
						// CSSCK:PCS to SCK Delay Scaler --> tCSC = (1/fSYS) x PCSSCK x CSSCK --> (1/50MHz)*1*2 
						// ASC: After SCK Delay Scaler --> tASC = (1/fSYS) x PASC x ASC --> (1/50MHz)*1*1
						// DT:Delay After Transfer Scaler --> tDT = (1/fSYS) x PDT x DT --> (1/50MHz)*1*1  
						// Baud Rate config
						// SCK baud rate = (fSYS/PBR) x [(1+DBR)/BR]
						// with fsys=fbus=50MHz
						// PBR = 0 div by 2
						// DBR = 0 (50% duty cycle)
						// BR = 0 --> div by 2
						// SPI Clock = (50MHz/2) * (1/2)=12.5MHz
						SPI0_CTAR1|=((SPI_CTAR_FMSZ(7))|(SPI_CTAR_ASC(1))|(SPI_CTAR_DT(1))|(SPI_CTAR_PBR(2))|(SPI_CTAR_BR(0)));
					}
			break;
			case kSpi1:
				if(kCTAR0==aCfg)
					{
						// Fields reset
						SPI1_CTAR0&=0x00000000;
						// Double Baud Rate --> The baud rate is computed normally with a 50/50 duty cycle
						// Frame Size --> 16 bits 
						// Clock Polarity --> The inactive state value of SCK is low
						// Clock Phase --> Data is captured on the leading edge of SCK and changed on the following edge
						// LBS First --> Data is transferred MSB first
						// PCSSCK: PCS to SCK Delay Prescaler --> PCS to SCK Prescaler value is 1
						// PASC:After SCK Delay Prescaler --> Delay after Transfer Prescaler value is 1 
						// PDT:Delay after Transfer Prescaler --> Delay after Transfer Prescaler value is 1
						// CSSCK:PCS to SCK Delay Scaler --> tCSC = (1/fSYS) x PCSSCK x CSSCK --> (1/50MHz)*1*2 
						// ASC: After SCK Delay Scaler --> tASC = (1/fSYS) x PASC x ASC --> (1/50MHz)*1*1
						// DT:Delay After Transfer Scaler --> tDT = (1/fSYS) x PDT x DT --> (1/50MHz)*1*1  
						// Baud Rate config
						// SCK baud rate = (fSYS/PBR) x [(1+DBR)/BR]
						// with fsys=fbus=50MHz
						// PBR = 0 div by 2
						// DBR = 0 (50% duty cycle)
						// BR = 0 --> div by 2
						// SPI Clock = (50MHz/2) * (1/2)=12.5MHz
						SPI1_CTAR0|=((SPI_CTAR_FMSZ(7))|(SPI_CTAR_ASC(0))|(SPI_CTAR_DT(0))|(SPI_CTAR_PBR(0))|(SPI_CTAR_BR(0x7))|SPI_CTAR_CSSCK(0x6));
					}
				else if(kCTAR1==aCfg)
					{
						// Fields reset
						SPI1_CTAR1&=0x00000000;
						// Double Baud Rate --> The baud rate is computed normally with a 50/50 duty cycle
						// Frame Size --> 8 bits 
						// Clock Polarity --> The inactive state value of SCK is low
						// Clock Phase --> Data is captured on the leading edge of SCK and changed on the following edge
						// LBS First --> Data is transferred MSB first
						// PCSSCK: PCS to SCK Delay Prescaler --> PCS to SCK Prescaler value is 1
						// PASC:After SCK Delay Prescaler --> Delay after Transfer Prescaler value is 1 
						// PDT:Delay after Transfer Prescaler --> Delay after Transfer Prescaler value is 1
						// CSSCK:PCS to SCK Delay Scaler --> tCSC = (1/fSYS) x PCSSCK x CSSCK --> (1/50MHz)*1*2 
						// ASC: After SCK Delay Scaler --> tASC = (1/fSYS) x PASC x ASC --> (1/50MHz)*1*1
						// DT:Delay After Transfer Scaler --> tDT = (1/fSYS) x PDT x DT --> (1/50MHz)*1*1  
						// Baud Rate config
						// SCK baud rate = (fSYS/PBR) x [(1+DBR)/BR]
						// with fsys=fbus=50MHz
						// PBR = 0 div by 2
						// DBR = 0 (50% duty cycle)
						// BR = 0 --> div by 2
						// SPI Clock = (50MHz/2) * (1/2)=12.5MHz
						SPI1_CTAR1|=((SPI_CTAR_FMSZ(7))|(SPI_CTAR_ASC(1))|(SPI_CTAR_DT(1))|(SPI_CTAR_PBR(2))|(SPI_CTAR_BR(0)));
					}
			break;					
	
			case kSpi2:
				if(kCTAR0==aCfg)
					{
						// Fields reset
						SPI2_CTAR0&=0x00000000;
						// Double Baud Rate --> The baud rate is computed normally with a 50/50 duty cycle
						// Frame Size --> 8 bits 
						// Clock Polarity --> The inactive state value of SCK is low
						// Clock Phase --> Data is changed on the leading edge of SCK and captured on the following edge
						// LBS First --> Data is transferred MSB first
						// PCSSCK: PCS to SCK Delay Prescaler --> PCS to SCK Prescaler value is 1
						// PASC:After SCK Delay Prescaler --> Delay after Transfer Prescaler value is 1 
						// PDT:Delay after Transfer Prescaler --> Delay after Transfer Prescaler value is 1
						// CSSCK:PCS to SCK Delay Scaler --> tCSC = (1/fSYS) x PCSSCK x CSSCK --> (1/50MHz)*1*2 
						// ASC: After SCK Delay Scaler --> tASC = (1/fSYS) x PASC x ASC --> (1/50MHz)*1*1
						// DT:Delay After Transfer Scaler --> tDT = (1/fSYS) x PDT x DT --> (1/50MHz)*1*1  
						// Baud Rate config
						// SCK baud rate = (fSYS/PBR) x [(1+DBR)/BR]
						// with fsys=fbus=50MHz
						// PBR = 0 div by 2
						// DBR = 0 (50% duty cycle)
						// BR = 0 --> div by 2
						// SPI Clock = (50MHz/2) * (1/2)=12.5MHz
						SPI2_CTAR0|=((SPI_CTAR_FMSZ(7))|SPI_CTAR_CPHA_MASK|(SPI_CTAR_ASC(0))|(SPI_CTAR_DT(0))|(SPI_CTAR_PBR(0))|(SPI_CTAR_BR(0)));
					}
				else if(kCTAR1==aCfg)
					{
						// Fields reset
						SPI2_CTAR1&=0x00000000;
						// Double Baud Rate --> The baud rate is computed normally with a 50/50 duty cycle
						// Frame Size --> 8 bits 
						// Clock Polarity --> The inactive state value of SCK is low
						// Clock Phase --> Data is captured on the leading edge of SCK and changed on the following edge
						// LBS First --> Data is transferred MSB first
						// PCSSCK: PCS to SCK Delay Prescaler --> PCS to SCK Prescaler value is 1
						// PASC:After SCK Delay Prescaler --> Delay after Transfer Prescaler value is 1 
						// PDT:Delay after Transfer Prescaler --> Delay after Transfer Prescaler value is 1
						// CSSCK:PCS to SCK Delay Scaler --> tCSC = (1/fSYS) x PCSSCK x CSSCK --> (1/50MHz)*1*2 
						// ASC: After SCK Delay Scaler --> tASC = (1/fSYS) x PASC x ASC --> (1/50MHz)*1*1
						// DT:Delay After Transfer Scaler --> tDT = (1/fSYS) x PDT x DT --> (1/50MHz)*1*1  
						// Baud Rate config
						// SCK baud rate = (fSYS/PBR) x [(1+DBR)/BR]
						// with fsys=fbus=50MHz
						// PBR = 0 div by 2
						// DBR = 0 (50% duty cycle)
						// BR = 0 --> div by 2
						// SPI Clock = (50MHz/2) * (1/2)=12.5MHz
						SPI2_CTAR1|=((SPI_CTAR_FMSZ(7))|(SPI_CTAR_ASC(1))|(SPI_CTAR_DT(1))|(SPI_CTAR_PBR(2))|(SPI_CTAR_BR(0)));
					}
			break;
		}
}

//-----------------------------------------------------------------------
// SPI config interrupt & DMA
// aSpi:which SPI (0,1 or 2)
//-----------------------------------------------------------------------
void iSpi_ConfigInterrupAndDMA(SPIEnum aSpi)
{
	// K10 Sub-Family Reference Manual, Rev. 6, Nov 2011 page 1183
	// DSPI DMA/Interrupt Request Select and Enable Register(SPIx_RSER)
	switch(aSpi)
		{
			case kSpi0:
				// Transmission Complete Request Enable --> TCF interrupt requests are disabled
				// DSPI Finished Request Enable --> EOQF interrupt requests are disabled
				// Transmit FIFO Underflow Request Enable --> TFUF interrupt requests are disabled
				// Transmit FIFO Fill Request Enable --> TFFF interrupts or DMA requests are disabled
				// Transmit FIFO Fill DMA or Interrupt Request Select --> TFFF flag generates interrupt requests
				// Receive FIFO Overflow Request Enable --> RFOF interrupt requests are disabled
				// Receive FIFO Drain Request Enable --> RFDF interrupt or DMA requests are disabled
				// Receive FIFO Drain DMA or Interrupt Request Select --> Interrupt request
				// Field reset
				SPI0_RSER&=0x00000000;
				//SPI0_RSER|=();
			break;					
				
			case kSpi1:
				// Transmission Complete Request Enable --> TCF interrupt requests are disabled
				// DSPI Finished Request Enable --> EOQF interrupt requests are disabled
				// Transmit FIFO Underflow Request Enable --> TFUF interrupt requests are disabled
				// Transmit FIFO Fill Request Enable --> TFFF interrupts or DMA requests are disabled
				// Transmit FIFO Fill DMA or Interrupt Request Select --> TFFF flag generates interrupt requests
				// Receive FIFO Overflow Request Enable --> RFOF interrupt requests are disabled
				// Receive FIFO Drain Request Enable --> RFDF interrupt or DMA requests are disabled
				// Receive FIFO Drain DMA or Interrupt Request Select --> Interrupt request
				// Field reset
				SPI0_RSER&=0x00000000;
				//SPI0_RSER|=();
			break;
			
			case kSpi2:
				// Transmission Complete Request Enable --> TCF interrupt requests are disabled
				// DSPI Finished Request Enable --> EOQF interrupt requests are disabled
				// Transmit FIFO Underflow Request Enable --> TFUF interrupt requests are disabled
				// Transmit FIFO Fill Request Enable --> TFFF interrupts or DMA requests are disabled
				// Transmit FIFO Fill DMA or Interrupt Request Select --> TFFF flag generates interrupt requests
				// Receive FIFO Overflow Request Enable --> RFOF interrupt requests are disabled
				// Receive FIFO Drain Request Enable --> RFDF interrupt or DMA requests are disabled
				// Receive FIFO Drain DMA or Interrupt Request Select --> Interrupt request
				// Field reset
				SPI0_RSER&=0x00000000;
				//SPI0_RSER|=();
			break;
		}
}

//-----------------------------------------------------------------------
// SPI clock phase configuration
// aSpi:which SPI (0,1 or 2)
// aCfg:which config register (CTAR0 or CTAR1)
//-----------------------------------------------------------------------
void iSpi_ConfigClockPhase(SPIEnum aSpi,SpiCfgRegisterEnum aCfg,ClockPhaseEnum aPhase)
{
	// K10 Sub-Family Reference Manual, Rev. 6, Nov 2011 page 1174
	// DSPI Clock and Transfer Attributes Register
	switch(aSpi)
		{
			case kSpi0:
				if(kCTAR0==aCfg)
					{
						switch(aPhase)
							{
								case kCaptureLeadingEdge:
									SPI0_CTAR0&=(~SPI_CTAR_CPHA_MASK);
								break;
								case kDataChangeLeadingEdge:
									SPI0_CTAR0|=SPI_CTAR_CPHA_MASK;
								break;
							}
					}
				else if(kCTAR1==aCfg)
					{
						switch(aPhase)
							{
								case kCaptureLeadingEdge:
									SPI0_CTAR1&=(~SPI_CTAR_CPHA_MASK);
								break;
								case kDataChangeLeadingEdge:
									SPI0_CTAR1|=SPI_CTAR_CPHA_MASK;
								break;
							}
					}
			break;
			case kSpi1:
				if(kCTAR0==aCfg)
					{
						switch(aPhase)
							{
								case kCaptureLeadingEdge:
									SPI1_CTAR0&=(~SPI_CTAR_CPHA_MASK);
								break;
								case kDataChangeLeadingEdge:
									SPI1_CTAR0|=SPI_CTAR_CPHA_MASK;
								break;
							}
					}
				else if(kCTAR1==aCfg)
					{
						switch(aPhase)
							{
								case kCaptureLeadingEdge:
									SPI1_CTAR1&=(~SPI_CTAR_CPHA_MASK);
								break;
								case kDataChangeLeadingEdge:
									SPI1_CTAR1|=SPI_CTAR_CPHA_MASK;
								break;
							}
					}
			break;					
	
			case kSpi2:
				if(kCTAR0==aCfg)
					{
						switch(aPhase)
							{
								case kCaptureLeadingEdge:
									SPI2_CTAR0&=(~SPI_CTAR_CPHA_MASK);
								break;
								case kDataChangeLeadingEdge:
									SPI2_CTAR0|=SPI_CTAR_CPHA_MASK;
								break;
							}
					}
				else if(kCTAR1==aCfg)
					{
						switch(aPhase)
							{
								case kCaptureLeadingEdge:
									SPI2_CTAR1&=(~SPI_CTAR_CPHA_MASK);
								break;
								case kDataChangeLeadingEdge:
									SPI2_CTAR1|=SPI_CTAR_CPHA_MASK;
								break;
							}
					}
			break;
		}
}

//-----------------------------------------------------------------------
// Clear TX FIFO
// aSpi:		which SPI
//-----------------------------------------------------------------------
void iSpi_ClearTxFifo(SPIEnum aSpi)
{
	// K10 Sub-Family Reference Manual, Rev. 6, Nov 2011 page 1171
	// DSPI Module Configuration Register (SPIx_MCR)
	switch(aSpi)
		{
			case kSpi0:
				SPI0_MCR|=SPI_MCR_CLR_TXF_MASK;	
			break;
			case kSpi1:
				SPI1_MCR|=SPI_MCR_CLR_TXF_MASK;	
			break;
			case kSpi2:
				SPI2_MCR|=SPI_MCR_CLR_TXF_MASK;	
			break;
		}
}

//-----------------------------------------------------------------------
// Flush RX FIFO
// aSpi:		which SPI
//-----------------------------------------------------------------------
void iSpi_FlushRXFifo(SPIEnum aSpi)
{
	// K10 Sub-Family Reference Manual, Rev. 6, Nov 2011 page 1171
	// DSPI Module Configuration Register (SPIx_MCR)
	switch(aSpi)
		{
			case kSpi0:
				SPI0_MCR|=SPI_MCR_CLR_RXF_MASK;	
			break;
			case kSpi1:
				SPI1_MCR|=SPI_MCR_CLR_RXF_MASK;	
			break;
			case kSpi2:
				SPI2_MCR|=SPI_MCR_CLR_RXF_MASK;	
			break;
		}
}

//-----------------------------------------------------------------------
// Start TX
// aSpi:which SPI
//-----------------------------------------------------------------------
void iSpi_StartTX(SPIEnum aSpi)
{
	// K10 Sub-Family Reference Manual, Rev. 6, Nov 2011 page 1171
	// DSPI Module Configuration Register (SPIx_MCR)
	switch(aSpi)
		{
			case kSpi0:
				SPI0_MCR&=(~SPI_MCR_HALT_MASK);
			break;
			case kSpi1:
				SPI1_MCR&=(~SPI_MCR_HALT_MASK);	
			break;
			case kSpi2:
				SPI2_MCR&=(~SPI_MCR_HALT_MASK);	
			break;
		}
}

//-----------------------------------------------------------------------
// Stop TX
// aSpi:which SPI
//-----------------------------------------------------------------------
void iSpi_StopTX(SPIEnum aSpi)
{
	// K10 Sub-Family Reference Manual, Rev. 6, Nov 2011 page 1171
	// DSPI Module Configuration Register (SPIx_MCR)
	switch(aSpi)
		{
			case kSpi0:
				SPI0_MCR|=(SPI_MCR_HALT_MASK);
			break;
			case kSpi1:
				SPI1_MCR|=(SPI_MCR_HALT_MASK);	
			break;
			case kSpi2:
				SPI2_MCR|=(SPI_MCR_HALT_MASK);	
			break;
		}
}

//-----------------------------------------------------------------------------
// Get SPI status 
// aSpi:which SPI
// aStatus: which status flag
// return	: flag state
//-----------------------------------------------------------------------------
bool iSpi_GetStatus(SPIEnum aSpi,SpiStatusEnum aStatus)
{
	bool aRet;
		
	// K10 Sub-Family Reference Manual, Rev. 6, Nov 2011 page 1180
	// DSPI Status Register (SPIx_SR)
	switch(aSpi)
		{
			case kSpi0:
				aRet=((SPI0_SR&aStatus)==aStatus);
			break;
			case kSpi1:
				aRet=((SPI1_SR&aStatus)==aStatus);
			break;
			case kSpi2:
				aRet=((SPI2_SR&aStatus)==aStatus);
			break;
		}

	return aRet;
}

//-----------------------------------------------------------------------------
// Get TX FIFO counter 
// aSpi:which SPI
// return	: Tx fifo counter
//-----------------------------------------------------------------------------
UInt8 iSpi_GetTxFifoCounter(SPIEnum aSpi)
{
	UInt8 aRet;
		
	// K10 Sub-Family Reference Manual, Rev. 6, Nov 2011 page 1180
	// DSPI Status Register (SPIx_SR)
	switch(aSpi)
		{
			case kSpi0:
				aRet=(UInt8)((SPI0_SR&SPI_SR_TXCTR_MASK)>>SPI_SR_TXCTR_SHIFT);
			break;
			case kSpi1:
				aRet=(UInt8)((SPI1_SR&SPI_SR_TXCTR_MASK)>>SPI_SR_TXCTR_SHIFT);
			break;
			case kSpi2:
				aRet=(UInt8)((SPI2_SR&SPI_SR_TXCTR_MASK)>>SPI_SR_TXCTR_SHIFT);
			break;
		}

	return aRet;
}

//-----------------------------------------------------------------------------
// Get TX FIFO next pointer 
// aSpi:which SPI
// return	: Tx fifo next pointer
//-----------------------------------------------------------------------------
UInt8 iSpi_GetTxFifoNextPointer(SPIEnum aSpi)
{
	UInt8 aRet;
		
	// K10 Sub-Family Reference Manual, Rev. 6, Nov 2011 page 1180
	// DSPI Status Register (SPIx_SR)
	switch(aSpi)
		{
			case kSpi0:
				aRet=(UInt8)((SPI0_SR&SPI_SR_TXNXTPTR_MASK)>>SPI_SR_TXNXTPTR_SHIFT);
			break;
			case kSpi1:
				aRet=(UInt8)((SPI1_SR&SPI_SR_TXNXTPTR_MASK)>>SPI_SR_TXNXTPTR_SHIFT);
			break;
			case kSpi2:
				aRet=(UInt8)((SPI2_SR&SPI_SR_TXNXTPTR_MASK)>>SPI_SR_TXNXTPTR_SHIFT);
			break;
		}

	return aRet;
}

//-----------------------------------------------------------------------------
// Get RX FIFO Counter 
// aSpi:which SPI
// return	: Rx fifo counter
//-----------------------------------------------------------------------------
UInt8 iSpi_GetRxFifoCounter(SPIEnum aSpi)
{
	UInt8 aRet;
		
	// K10 Sub-Family Reference Manual, Rev. 6, Nov 2011 page 1180
	// DSPI Status Register (SPIx_SR)
	switch(aSpi)
		{
			case kSpi0:
				aRet=(UInt8)((SPI0_SR&SPI_SR_RXCTR_MASK)>>SPI_SR_RXCTR_SHIFT);
			break;
			case kSpi1:
				aRet=(UInt8)((SPI1_SR&SPI_SR_RXCTR_MASK)>>SPI_SR_RXCTR_SHIFT);
			break;
			case kSpi2:
				aRet=(UInt8)((SPI2_SR&SPI_SR_RXCTR_MASK)>>SPI_SR_RXCTR_SHIFT);
			break;
		}

	return aRet;
}

//-----------------------------------------------------------------------------
// Get RX FIFO pop next pointer 
// aSpi:which SPI
// return	: Rx fifo pop next pointer
//-----------------------------------------------------------------------------
UInt8 iSpi_GetRxFifoNextPointer(SPIEnum aSpi)
{
	UInt8 aRet;
		
	// K10 Sub-Family Reference Manual, Rev. 6, Nov 2011 page 1180
	// DSPI Status Register (SPIx_SR)
	switch(aSpi)
		{
			case kSpi0:
				aRet=(UInt8)((SPI0_SR&SPI_SR_POPNXTPTR_MASK)>>SPI_SR_POPNXTPTR_SHIFT);
			break;
			case kSpi1:
				aRet=(UInt8)((SPI1_SR&SPI_SR_POPNXTPTR_MASK)>>SPI_SR_POPNXTPTR_SHIFT);
			break;
			case kSpi2:
				aRet=(UInt8)((SPI2_SR&SPI_SR_POPNXTPTR_MASK)>>SPI_SR_POPNXTPTR_SHIFT);
			break;
		}

	return aRet;
}

//-----------------------------------------------------------------------------
// Spi status flag reset
// aSpi:which SPI
// aStatus: which flag to reset
//-----------------------------------------------------------------------------
void iSpi_ResetStatus(SPIEnum aSpi,SpiStatusEnum aStatus)
{
	// K10 Sub-Family Reference Manual, Rev. 6, Nov 2011 page 1180
	// DSPI Status Register (SPIx_SR)
	switch(aSpi)
		{
			case kSpi0:
				SPI0_SR|=aStatus;
			break;
			case kSpi1:
				SPI1_SR|=aStatus;
			break;
			case kSpi2:
				SPI2_SR|=aStatus;
			break;
		}
}

//-----------------------------------------------------------------------------
// Push Data & Config into the TX FIFO
// aSpi:which SPI
// aCfg:which config register (CTAR0 or CTAR1)
// aCont: CS remain asserted?
// aLastQueueData: is this frame the last in the queue?
// aCs: which CS to use
// aData: data to transmit
//-----------------------------------------------------------------------------
void iSpi_PushDataIntoFifo(	SPIEnum aSpi,SpiCfgRegisterEnum aCfg,
														CSContinuousModeEnum aCont, bool aLastQueueData,
														CsEnum aCs,UInt16 aData)
{
	UInt32 aTmp=0;
	// K10 Sub-Family Reference Manual, Rev. 6, Nov 2011 page 1185
	// DSPI PUSH TX FIFO Register In Master Mode (SPIx_PUSHR)
	aTmp=aCont|aCfg|aCont|(((UInt32)aLastQueueData)<<27)|aCs|((UInt32)aData);
	
	switch(aSpi)
		{
			case kSpi0:
				SPI0_PUSHR=aTmp;
			break;
			case kSpi1:
				SPI1_PUSHR=aTmp;
			break;
			case kSpi2:
				SPI2_PUSHR=aTmp;
			break;
		}
}

//-----------------------------------------------------------------------------
// Read a Data from the RX queue
// aSpi:which SPI
//-----------------------------------------------------------------------------
UInt32 iSpi_ReadData(SPIEnum aSpi)
{
	UInt32 aRet;
	
	// K10 Sub-Family Reference Manual, Rev. 6, Nov 2011 page 1187
	// DSPI POP RX FIFO Register (SPIx_POPR)
	switch(aSpi)
			{
				case kSpi0:
					aRet=SPI0_POPR;
				break;
				case kSpi1:
					aRet=SPI1_POPR;
				break;
				case kSpi2:
					aRet=SPI2_POPR;
				break;
			}
	
	return aRet;
}

//-----------------------------------------------------------------------------
// Setup spi
//-----------------------------------------------------------------------------
void iSpi_Setup(void)
{
	//Configuration du clock et des param�tres de transfert pour le capteur de pression
	iSpi_ConfigClockAndTransfert(kSpi1,kCTAR0);
	//Configuration du module spi1
	iSpi_ConfigSPIModule(kSpi1);
	//Configuration des interruptions et du DMA: disable
	iSpi_ConfigInterrupAndDMA(kSpi1);
	//Communication des donn�es au flanc montant
	iSpi_ConfigClockPhase(kSpi1,kCTAR0,kCaptureLeadingEdge);
}

//-----------------------------------------------------------------------------
// Open module spi
//-----------------------------------------------------------------------------
void iSpi_Open(void)
{
	iSpi_StartTX(kSpi1);
}

//-----------------------------------------------------------------------------
// Close module spi
//-----------------------------------------------------------------------------
void iSpi_Close(void)
{
	iSpi_StopTX(kSpi1);
}








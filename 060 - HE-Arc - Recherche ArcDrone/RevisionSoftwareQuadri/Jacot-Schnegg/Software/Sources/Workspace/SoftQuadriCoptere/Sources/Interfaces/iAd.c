/*
------------------------------------------------------------
Copyright 2003-2012 Haute école ARC Ingéniérie, Switzerland. 
All rights reserved.
------------------------------------------------------------
File name :	iAd.c
Author and date :	Monnerat Serge 28 févr. 2012

Description in the header (.h)

-----------------------------------------------------------------------------
History:
-----------------------------------------------------------------------------

$History: $

-----------------------------------------------------------------------------
*/

#include "iAd.h"
#include "derivative.h"



//------------------------------------------------------------
// ADC 0 & 1 setup
//------------------------------------------------------------
void iAd_Config(void)
{
	// ADC status and control registers 1 (ADCx_SC1n)
	// K10 Sub-Family Reference Manual, Rev. 6, Nov 2011 page 754
	// AIEN=0,Conversion complete interrupt disabled
	// DIFF=0,Differential mode enable -> Single-ended conversions and input channels are selected
	// ADCH=0x1f,Input channel select -> Module disabled
	ADC0_SC1A=0;
	ADC0_SC1A|=(ADC_SC1_ADCH(0x1f));
	
	// ADC configuration register 1 (ADCx_CFG1)
	// K10 Sub-Family Reference Manual, Rev. 6, Nov 2011 page 757
	// ADLPC=0, Normal power configuration 
	// ADIV=1,The divide ratio is 2 and the clock rate is (input clock)/8
	// ADLSMP=1,Long sample time
	// MODE=01,It is single-ended 12-bit conversion
	// ADICLK=1,Bus clock divided by 2
	ADC0_CFG1=0;
	ADC0_CFG1|=(ADC_CFG1_ADIV(1)|ADC_CFG1_MODE(1)|ADC_CFG1_ADICLK(1)|ADC_CFG1_ADLSMP_MASK);
	
	// Configuration register 2 (ADCx_CFG2)
	// K10 Sub-Family Reference Manual, Rev. 6, Nov 2011 page 759
	// MUXSEL=0,ADxxa channels are selected
	// ADACKEN=0,Asynchronous clock output disabled
	// ADHSC=0,Normal conversion sequence selected
	// ADLSTS=0,Default longest sample time (20 extra ADCK cycles; 24 ADCK cycles total)
	// AD clock = Bus clock / 4 = 50Mhz/4=12.5 MHz
	// One channel converison time = 1/12.5MHz * 24 = 1.92 us
	ADC0_CFG2=0;
	
	// Status and control register 2 (ADCx_SC2)
	// K10 Sub-Family Reference Manual, Rev. 6, Nov 2011 page 762
	// ADTRG=0,Software trigger selected
	// ACFE=0,Compare function disabled
	// ACFGT=0,Configures less than threshold, outside range not inclusive and inside range not inclusive functionality
	// based on the values placed in the CV1 and CV2 registers
	// ACREN=0,Range function disabled. Only the compare value 1 register (CV1) is compared
	// DMAEN=0,DMA is disabled
	// REFSEL=0,Default voltage reference pin pair (external pins VREFH and VREFL) 
	ADC0_SC2=0;
	ADC0_SC2|=ADC_SC2_REFSEL(0);
	
	// Status and control register 2 (ADCx_SC3)
	// K10 Sub-Family Reference Manual, Rev. 6, Nov 2011 page 764
	// ADCO=0, One conversion or one set of conversions if the hardware average function is enabled (AVGE=1) after initiating a conversion.
	// AVGE=0, Hardware average function disabled
	// AVGS=0, 4 samples averaged
	ADC0_SC3=0;
	
	
	// ADC status and control registers 1 (ADCx_SC1n)
	// K10 Sub-Family Reference Manual, Rev. 6, Nov 2011 page 754
	// AIEN=0,Conversion complete interrupt disabled
	// DIFF=0,Differential mode enable -> Single-ended conversions and input channels are selected
	// ADCH=0x1f,Input channel select -> Module disabled
	ADC1_SC1A=0;
	ADC1_SC1A|=(ADC_SC1_ADCH(0x1f));
	
	// ADC configuration register 1 (ADCx_CFG1)
	// K10 Sub-Family Reference Manual, Rev. 6, Nov 2011 page 757
	// ADLPC=0, Normal power configuration 
	// ADIV=1,The divide ratio is 2 and the clock rate is (input clock)/2
	// ADLSMP=1,Long sample time
	// MODE=01,It is single-ended 12-bit conversion
	// ADICLK=1,Bus clock divided by 2
	ADC1_CFG1=0;
	ADC1_CFG1|=(ADC_CFG1_ADIV(1)|ADC_CFG1_MODE(1)|ADC_CFG1_ADICLK(1)|ADC_CFG1_ADLSMP_MASK);
	
	// Configuration register 2 (ADCx_CFG2)
	// K10 Sub-Family Reference Manual, Rev. 6, Nov 2011 page 759
	// MUXSEL=0,ADxxa channels are selected
	// ADACKEN=0,Asynchronous clock output disabled
	// ADHSC=0,Normal conversion sequence selected
	// ADLSTS=0,Default longest sample time (20 extra ADCK cycles; 24 ADCK cycles total)
	// AD clock = Bus clock / 16 = 50Mhz/16=3.125 MHz
	// One channel converison time = 1/3.125MHz * 24 = 7.7 us
	ADC1_CFG2=0;
	
	// Status and control register 2 (ADCx_SC2)
	// K10 Sub-Family Reference Manual, Rev. 6, Nov 2011 page 762
	// ADTRG=0,Software trigger selected
	// ACFE=0,Compare function disabled
	// ACFGT=0,Configures less than threshold, outside range not inclusive and inside range not inclusive functionality
	// based on the values placed in the CV1 and CV2 registers
	// ACREN=0,Range function disabled. Only the compare value 1 register (CV1) is compared
	// DMAEN=0,DMA is disabled
	// REFSEL=0,Default voltage reference pin pair (external pins VREFH and VREFL) 
	ADC1_SC2=0;
	ADC1_SC2|=ADC_SC2_REFSEL(0);
	
	// Status and control register 2 (ADCx_SC3)
	// K10 Sub-Family Reference Manual, Rev. 6, Nov 2011 page 764
	// ADCO=0, One conversion or one set of conversions if the hardware average function is enabled (AVGE=1) after initiating a conversion.
	// AVGE=0, Hardware average function disabled
	// AVGS=0, 4 samples averaged
	ADC1_SC3=0;
}

//------------------------------------------------------------
// ADC 0 & 1 get conversion
// aAd: which ADC
//------------------------------------------------------------
UInt16 iAd_GetResult(ADCEnum aAd)
{
	UInt16 aVal;
	switch(aAd)
		{
			case kAdc0:
				aVal=ADC0_RA;
			break;
			
			case kAdc1:
				aVal=ADC1_RA;
			break;
		}

	return aVal;
}

//------------------------------------------------------------
// ADC 0 & 1 get conversion
// aAd: which ADC
// aCh: which ADC channel
//------------------------------------------------------------
void iAd_SelectChannel(ADCEnum aAd,ADCChannelEnum aCh)
{
	UInt16 aVal;
	switch(aAd)
		{
			case kAdc0:
				// Clear ADCH field
				ADC0_SC1A&=(~ADC_SC1_ADCH_MASK);
				// To clear the flag COCO after reseting ADCH 
				aVal=ADC0_RA;
				ADC0_SC1A|=(ADC_SC1_ADCH(aCh));
			break;
			
			case kAdc1:
				// Clear ADCH field
				ADC1_SC1A&=(~ADC_SC1_ADCH_MASK);
				// To clear the flag COCO after reseting ADCH 
				aVal=ADC1_RA;
				ADC1_SC1A|=(ADC_SC1_ADCH(aCh));
			break;
		}
}

//------------------------------------------------------------
// ADC 0 & 1 get conversion complete flag
// aAd: which ADC
//------------------------------------------------------------
bool iAd_GetCompleteConvStatus(ADCEnum aAd)
{
	bool aRet;
	switch(aAd)
		{
			case kAdc0:
				aRet=(ADC0_SC1A&ADC_SC1_COCO_MASK)==ADC_SC1_COCO_MASK;
			break;
			
			case kAdc1:
				aRet=(ADC1_SC1A&ADC_SC1_COCO_MASK)==ADC_SC1_COCO_MASK;
			break;
		}
	return aRet;
}

//------------------------------------------------------------
// ADC 0 & 1 calibration
//------------------------------------------------------------
bool iAd_Cal(ADCEnum aAd)
{
  UInt16 aCalVar=0;
  bool aRet;
  
  switch(aAd)
  		{
  			case kAdc0:
  				
  				// Max ADC clock -> 4MHz
  				ADC0_CFG1&=((~ADC_CFG1_ADIV_MASK)&(~ADC_CFG1_ADICLK_MASK));
  				ADC0_CFG1|=(ADC_CFG1_ADIV(3)|ADC_CFG1_MODE(1)|ADC_CFG1_ADICLK(1)|ADC_CFG1_ADLSMP_MASK);
  				
  				// Enable Software Conversion Trigger for Calibration Process
					ADC0_SC2&=(~ADC_SC2_ADTRG_MASK);
					// Set single conversion, clear avgs bitfield for next writing
					ADC0_SC3&= ((~ADC_SC3_ADCO_MASK) & (~ADC_SC3_AVGS_MASK)); 
					// Turn averaging ON and set at max value ( 32 )
					ADC0_SC3|= (ADC_SC3_AVGE_MASK | ADC_SC3_AVGS(3) );  
					// Start CAL
					ADC0_SC3 |= ADC_SC3_CAL_MASK ;      
					// Wait calibration end
					while ( (ADC0_SC1A & ADC_SC1_COCO_MASK ) == false ); 
					
					// Check for Calibration fail error and return
					if ((ADC0_SC3&ADC_SC3_CALF_MASK) == ADC_SC3_CALF_MASK)
						{  
							aRet=false;     
						}
					else
						{
							// Calculate plus-side calibration
							aCalVar = 0x00;
							
							aCalVar =  ADC0_CLP0; 
							aCalVar += ADC0_CLP1;
							aCalVar += ADC0_CLP2;
							aCalVar += ADC0_CLP3;
							aCalVar += ADC0_CLP4;
							aCalVar += ADC0_CLPS;
							aCalVar = aCalVar/2;
							aCalVar |= 0x8000; // Set MSB
							ADC0_PG= ADC_PG_PG(aCalVar);
						
							// Calculate minus-side calibration
							aCalVar = 0x00;
						
							aCalVar =  ADC0_CLM0; 
							aCalVar += ADC0_CLM1;
							aCalVar += ADC0_CLM2;
							aCalVar += ADC0_CLM3;
							aCalVar += ADC0_CLM4;
							aCalVar += ADC0_CLMS;
							aCalVar = aCalVar/2;
							aCalVar |= 0x8000; // Set MSB
							ADC0_MG = ADC_MG_MG(aCalVar); 
							
							// Clear CAL bit
							ADC0_SC3&= (~ADC_SC3_CAL_MASK); 
							
							// Return OK
							aRet=true;  
						}
  			break;
  			
  			case kAdc1:
  				// Max ADC clock -> 4MHz
					ADC1_CFG1&=((~ADC_CFG1_ADIV_MASK)&(~ADC_CFG1_ADICLK_MASK));
					ADC1_CFG1|=(ADC_CFG1_ADIV(3)|ADC_CFG1_MODE(1)|ADC_CFG1_ADICLK(1)|ADC_CFG1_ADLSMP_MASK);
					// Enable Software Conversion Trigger for Calibration Process
					ADC1_SC2&=(~ADC_SC2_ADTRG_MASK);
					// Set single conversion, clear avgs bitfield for next writing
					ADC1_SC3&= ((~ADC_SC3_ADCO_MASK) & (~ADC_SC3_AVGS_MASK)); 
					// Turn averaging ON and set at max value ( 32 )
					ADC1_SC3|= (ADC_SC3_AVGE_MASK | ADC_SC3_AVGS(3) );  
					// Start CAL
					ADC1_SC3 |= ADC_SC3_CAL_MASK ;      
					// Wait calibration end
					while ( (ADC1_SC1A & ADC_SC1_COCO_MASK ) == false ); 
					
					// Check for Calibration fail error and return
					if ((ADC1_SC3&ADC_SC3_CALF_MASK) == ADC_SC3_CALF_MASK)
						{  
							aRet=false;     
						}
					else
						{
							// Calculate plus-side calibration
							aCalVar = 0x00;
							
							aCalVar =  ADC1_CLP0; 
							aCalVar += ADC1_CLP1;
							aCalVar += ADC1_CLP2;
							aCalVar += ADC1_CLP3;
							aCalVar += ADC1_CLP4;
							aCalVar += ADC1_CLPS;
							aCalVar = aCalVar/2;
							aCalVar |= 0x8000; // Set MSB
							ADC1_PG= ADC_PG_PG(aCalVar);
						
							// Calculate minus-side calibration
							aCalVar = 0x00;
						
							aCalVar =  ADC1_CLM0; 
							aCalVar += ADC1_CLM1;
							aCalVar += ADC1_CLM2;
							aCalVar += ADC1_CLM3;
							aCalVar += ADC1_CLM4;
							aCalVar += ADC1_CLMS;
							aCalVar = aCalVar/2;
							aCalVar |= 0x8000; // Set MSB
							ADC1_MG = ADC_MG_MG(aCalVar); 
							
							// Clear CAL bit
							ADC1_SC3&= (~ADC_SC3_CAL_MASK); 
							
							// Return OK
							aRet=true;  
						}
  			break;
  		}
  	
  return aRet;
  
}

#include "include.h"
//void Calibration_data_reset(void)
//{
//	int i=0;
//	strcpy(Calibration.CAL.CAL_Serial_number,"999999999");
//	Calibration.CAL.CAL_pvref = C_PVREF_FINETURN;//2vУ????
//	Calibration.CAL.CAL_afeda1 = (((unsigned int)C_DAC_400_H)<<8 | C_DAC_400_L)>>4;//0.4vУ????	
//	Calibration.CAL.CAL_temp_offset = 0;//???У?	
//	Calibration.CAL.CAL_AD = 0X0FA5;	
//	Calibration.CAL.k_value = 1.0;//0.75;	
//	Calibration.CAL.CH_SUM = 0;
//	for(i=0;i<20;i++)
//	{
//		Calibration.CAL.CH_SUM+=Calibration.CAL_bytes[i];
//	}
//
//}
//--------------------------------------------------------------------------
//void Fill_Test_Calibration_data(void)
//{
//	Calibration_data_reset();
//	Write_EEPROMBuf(0, Calibration.CAL_bytes, sizeof(Calibration.CAL_bytes));
//}

//--------------------------------------------------------------------------
/**
 * @brief 開啟DACn 輸出
 *
 * @param DACn =1/2
 * @param PowerOnOff = POWERON/POWEROFF
 * @note DACnO 輸出值默認從EEPROM載入 EEPROM_DAC1  EEPROM_DAC2
 * @warning  DACn 電源來自 Voreg 若需使用 DACVREF 必須開啟 Voreg
 *
 */
 //--------------------------------------------------------------------------
void fun_DACnInit(unsigned char DACn , enum DACnOuput_t PowerOnOff)
{
//    DACnODISABLE = 0, //!< Disable, output in a high-impedance state
//    DACnOEnable = 1,  //!< Enable, Output with DAC data;
//    DACnOGND = 2,     //!< Disable, output in a ground state		
	
	if(DACn == 1)
	{
		if (PowerOnOff == DACnOEnable)
		{
			SET_DACn_VOLTAGE(1,DACnOEnable);
		}
		else if(PowerOnOff == DACnODISABLE)
		{
			SET_DACn_VOLTAGE(1,DACnODISABLE);
		}
		else if(PowerOnOff == DACnOGND)
		{
			SET_DACn_VOLTAGE(1,DACnOGND);
		}
	}
	
	if(DACn == 2)
	{
		if (PowerOnOff == DACnOEnable)
		{
			SET_DACn_VOLTAGE(2,DACnOEnable);
		}
		else if(PowerOnOff == DACnODISABLE)
		{
			SET_DACn_VOLTAGE(2,DACnODISABLE);
		}
		else if(PowerOnOff == DACnOGND)
		{
			SET_DACn_VOLTAGE(2,DACnOGND);
		}
	}
}

//--------------------------------------------------------------------------
unsigned char Load_VrefDaco_Vaule(void)
{
	unsigned char count;
volatile	unsigned int  checksum,Ibuf0;	

	
	Read_EEPROMBuf(0, (unsigned char*)Calibration.bytes, sizeof(Calibration.bytes));
	checksum=0;
	for(count=0;count<sizeof(Calibration)-2;count++)
	{
		checksum+=Calibration.bytes[count];
	}
	if(checksum == Calibration.CAL.CH_SUM && checksum != 0)
	{
		_pvref=Calibration.CAL.pvref_2_0V;
		
		Ibuf0=Calibration.CAL.afeda1_0_35V<<4;				
		_afeda1l = Ibuf0%256;
		_afeda1h = Ibuf0/256;
										
				
		return 0;	
	}
	else
	{
		
		Read_EEPROMBuf(0x20, (unsigned char*)Calibration.bytes, sizeof(Calibration.bytes))	;
		checksum=0;
		for(count=0;count<sizeof(Calibration)-2;count++)
		{
			checksum+=Calibration.bytes[count];
		}
		if(checksum == Calibration.CAL.CH_SUM && checksum != 0)
		{
			_pvref=Calibration.CAL.pvref_2_0V;			
			Ibuf0=Calibration.CAL.afeda1_0_35V<<4;				
			_afeda1l = Ibuf0%256;
			_afeda1h = Ibuf0/256;	
			 Write_EEPROMBuf(0, (unsigned char*)Calibration.bytes, sizeof(Calibration.bytes));															
			return 0;	
		}
		else
		{					
			_pvref = C_PVREF_FINETURN;
			//--- set daco
			_afeda1l = C_DAC_350_L;
			_afeda1h = C_DAC_350_H;			
			return 1;			
		}		
		
		
		

	}	
		
	
}

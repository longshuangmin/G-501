//////--- FLASH ROM address data MAP
////-- ROM Area
////-- 0x6000 ~ 0x603f for system record
//#define	 C_EEP_SignificantAdr       	0x00
//#define	 C_EEP_SignificantCode  		0x4db2		//adr 6000h => 0x4d (high byte)
//
////-- Flash Adr 02h
//#define	 C_EEP_GM_RecordAdr				0x02
////-- Flash Adr 04h
//#define	 C_EEP_GM_Current_RecordAdr		0x04
////-- Flash Adr 6005h
//#define	 C_EEP_Unit_Adr         		0x06
////-- Flash Adr 6005h
//#define	 C_EEP_Timeformat_Adr         	0x07
//
//#define	 C_EEP_Beep_Adr				0x08
//
//#define	 C_EEP_GmHi_Adr					0x09
//
//#define	 C_EEP_GmLow_Adr				0x0a
//
//#define	 C_EEP_Dateformat_Adr			0x0d

//#define	 C_EEP_MealEn_Adr				0x0e

#define FLASH_CHECK_MASK 				0X55

//-- Flash Adr 6005h	
#define	 C_EEP_BandGapAdr       		0x00
#define	 C_EEP_confirmCodeValue			0xbd	
#define	 C_EEP_RtcTime      			0x41




#define	 C_EEP_VoltageAdr       		0x02  	//


#define	 Beili_Adr       				0x04 	//


//G777
#define  C_PVREF_FINETURN				0xEE	//;;for fineturn bankgap 2.0V
#define  C_DAC_350_H					0x32	//;(0.425V) 	BIT0~7
#define  C_DAC_350_L					0xB0	//;(0.441V)     BIT4~7;00	




#define	 C_EEP_CalLircAdr       		0x04
#define	 C_EEP_CalHircAdr       		0x08

#define	 C_EEP_Cal10KAdr       			0x0a
#define	 C_EEP_Cal100KAdr       		0x0c


#define	 C_EEP_FactoryMode_Adr       	0x7f//ÎÞÎÂ²¹Ä£Ê½¡£

//#define	 C_EEP_Region_Adr       		0x14	//1byte
//#define	 C_EEP_Coden_Adr       			0x15	//1byte
//#define	 C_EEP_Speaker_Adr       		0x16	//1byte
//#define	 C_EEP_SerialNumber_Adr       	0x17	//6byte
//
//
//
////-- Flash Adr 6003h
//#define	 C_EEP_Alarm1_EN_Adr			0x20
////-- Flash Adr 6004h
//#define	 C_EEP_Alarm1_Hr_Adr     		0x21
////-- Flash Adr 6004h
//#define	 C_EEP_Alarm1_Min_Adr		    0x22
////-- Flash Adr 6003h
//#define	 C_EEP_Alarm2_EN_Adr			0x23
////-- Flash Adr 6004h
//#define	 C_EEP_Alarm2_Hr_Adr     		0x24
////-- Flash Adr 6004h
//#define	 C_EEP_Alarm2_Min_Adr		    0x25
////-- Flash Adr 6003h
//#define	 C_EEP_Alarm3_EN_Adr			0x26
////-- Flash Adr 6004h
//#define	 C_EEP_Alarm3_Hr_Adr     		0x27
////-- Flash Adr 6004h
//#define	 C_EEP_Alarm3_Min_Adr		    0x28
////-- Flash Adr 6003h
//#define	 C_EEP_Alarm4_EN_Adr			0x29
////-- Flash Adr 6004h
//#define	 C_EEP_Alarm4_Hr_Adr     		0x2a
////-- Flash Adr 6004h
//#define	 C_EEP_Alarm4_Min_Adr		    0x2b
////-- Flash Adr 6003h
//#define	 C_EEP_Time_EN_Adr				0x2c
////-- Flash Adr 6004h
//#define	 C_EEP_Time_Hr_Adr     			0x2d
////-- Flash Adr 6004h
//#define	 C_EEP_Time_Min_Adr		    	0x2e
//
//#define	 C_EEP_FactorySign_Adr			0x2f	//1B
//
//#define	 C_EEP_FlashLifeCount_Adr		0x30	//4B



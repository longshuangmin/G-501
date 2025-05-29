#include "include.h"

const unsigned int R103KT_TABLE[51]={
  12080 ,//0
  11752 ,//1
  11430 ,//2
  11114 ,//3
  10804 ,//4
  10501 ,//5
  10203 ,//6
  9912 ,//7
  9627 ,//8
  9349 ,//9
  9077 ,//10
  8812 ,//11
  8553 ,//12
  8301 ,//13
  8054 ,//14
  7815 ,//15
  7581 ,//16
  7354 ,//17
  7133 ,//18
  6917 ,//19
  6708 ,//20
  6505 ,//21
  6307 ,//22
  6115 ,//23
  5929 ,//24
  5748 ,//25
  5573 ,//26
  5403 ,//27
  5238 ,//28
  5077 ,//29
  4922 ,//30
  4772 ,//31
  4626 ,//32
  4484 ,//33
  4348 ,//34
  4215 ,//35
  4087 ,//36
  3962 ,//37
  3842 ,//38
  3725 ,//39
  3612 ,//40
  3503 ,//41
  3397 ,//42
  3295 ,//43
  3196 ,//44
  3099 ,//45
  3007 ,//46
  2917 ,//47
  2830 ,//48
  2746 ,//49
  2664 ,//50
 
};
//--------------------------------------------------------------------------
/**
 * @brief 開啟ADC電源并開始ADC轉換
 * @note 默認使用中斷方式獲取ADC數據
 * @warning 調用此函數前請完成ADC採樣率、放大倍率、採樣通道等配置
 * 調用此函數后會開啟全局中斷 emi
 *
 */
void fun_ADCStart(void)
{
	SET_ADC_INPUT_SHORT(DISABLE);;
	SET_ADCPOWER(POWERON);
	SET_ADCINTERRUPT_ENABLE();
	SET_ADC_STARTCONVERT();
	SDKADCSourceData.SamplingCnt = 0;
	SDKADCSourceData.flag.b.IsReady = 0;
}

//--------------------------------------------------------------------------
/**
 * @brief 停止ADC轉換并關閉ADC電源
 *
 */
void fun_ADCStop(void)
{
	SDKADCSourceData.flag.b.IsReady = 0;
	SDKADCSourceData.SamplingCnt = 0;
	SET_ADCPOWER(POWEROFF);
}

//--------------------------------------------------------------------------------
/**
 * @brief 斷開所有試紙電極,按對應試紙模式設置相關參數
 *
 * @note 以下配置為悠健測試試紙配置
 */
void fun_StripModuleAllOpen (void)
{
    SET_PIN_SINI_OPEN();
    SET_PIN_SINO1_OPEN();
    SET_PIN_SINO2_OPEN();
    
    SET_PIN_OP1N1_OPEN();
    SET_PIN_OP1N2_OPEN();
    SET_PIN_OP1S0_OPEN();
    SET_PIN_OP1S1_OPEN();
    SET_PIN_OP1N2_OPEN();
    SET_PIN_OP2N_OPEN();
    
    SET_PIN_VG1_OPEN();
    //SET_PIN_VG0_OPEN();
    
}

/**
 * @brief 斷開所有試紙電??按對應試紙模式設置相關參??
 *
 * @note 以下配置為悠健測試試紙配??
 */
void fun_StripModuleAllOpen2 (void)
{
    fun_StripModuleAllOpen();
    SET_PIN_VG0_OPEN();
    
}


//--------------------------------------------------------------------------
void InitADC_Op1n1_Op1s1 (void) 
{
    //**************
    //***Switch set
    //**************
    //--- all switch set floating
    fun_StripModuleAllOpen();
//    SET_PIN_OP1N2_OPEN();
//    SET_PIN_OP2N_OPEN();
    //---set VG0
    //SET_PIN_VG1_GND();
    SET_PIN_VG0_GND();
    
    //---set HDL SW
 //   P_HDL_SW =1;
    //---set Op1n
    SET_PIN_OP1N1_OP1N();
    SET_PIN_OP1S1_OP1O();
    SET_PIN_OPnP_DAC1O(1);
    
    SET_OPAn_POWER(1,POWERON);
    
		_pac3 = 1;  		
		_papu3=0;//去掉血糖检测端上拉，否则有电流??
		
		up_pin4 =0;//血糠试纸插入脚拉?		
		strips_pin4_dir = 1;  
		

#if 0
		strips_pin8_dir=1;//in--strips pin8
		up_pin8=0;
		strips_pin8=0;
		
		strips_pin7_dir=1;//in--strips pin7
		up_pin7=0;
		strips_pin7=0;
		
		
		strips_pin6_dir=1;//in--strips pin6
		up_pin6=0;
		strips_pin6=0;	
		
		
		_papu1 =0;//--strips pin6--G35改到此脚！！		
		_pac1 = 1;  		
		
#endif        
    // adc
    //SET_ADC_CHANNEL_P_DAC1O();
    SET_ADC_CHANNEL_N_OP1N1();
    //SET_ADC_CHANNEL_N_DAC1O();
    SET_ADC_CHANNEL_P_OP1S1();
    SET_VREF_GAIN_1();
    SET_PGA_BYPASS_WITHBUF();
    //SET_PGA_BYPASS_WITHOUTBUF();
    SET_ADC_GAIN_1();
    SET_ADC_DCSET_0V();
    //SET_ADC_DATARATE_10HZ();
    //SET_ADC_DATARATE_40HZ();
    //SET_ADC_DATARATE_64HZ();
  //  SET_ADC_DATARATE_80HZ();
      SET_ADC_DATARATE_160HZ();
   // SET_ADC_DATARATE_512HZ();
}

//--------------------------------------------------------------------------
void InitADC_Op1n2_Op1s0 (void)
{
    //**************
    //***Switch set
    //**************
    //--- all switch set floating
    fun_StripModuleAllOpen();
    SET_PIN_OP1N1_OPEN();
    SET_PIN_OP2N_OPEN();
    //---set VG0
 //   SET_PIN_VG1_GND();
    SET_PIN_VG0_GND();
    //---set Op1n
    SET_PIN_OP1N2_OP1N();
    SET_PIN_OP1S0_OP1O();
    SET_PIN_OPnP_DAC1O(1);
    
    SET_OPAn_POWER(1,POWERON);
		_pac3 = 1;  		
		_papu3=0;//去掉血糖检测端上拉，否则有电流??
		
		up_pin4 =0;//血糠试纸插入脚拉?		
		strips_pin4_dir = 1;  
		

#if 0
		strips_pin8_dir=1;//in--strips pin8
		up_pin8=0;
		strips_pin8=0;
		
		strips_pin7_dir=1;//in--strips pin7
		up_pin7=0;
		strips_pin7=0;
		
		
		strips_pin6_dir=1;//in--strips pin6
		up_pin6=0;
		strips_pin6=0;	  
		
		_papu1 =0;//--strips pin6--G35改到此脚！！		
		_pac1 = 1;  		
#endif				  
    // adc
    //SET_ADC_CHANNEL_P_DAC1O();
    SET_ADC_CHANNEL_N_OP1N2();
    //SET_ADC_CHANNEL_N_DAC1O();
    SET_ADC_CHANNEL_P_OP1S0();
    SET_VREF_GAIN_1();
    SET_PGA_BYPASS_WITHBUF();
    //SET_PGA_BYPASS_WITHOUTBUF();
    SET_ADC_GAIN_1();
    SET_ADC_DCSET_0V();
    //SET_ADC_DATARATE_10HZ();
    //SET_ADC_DATARATE_40HZ();
    //SET_ADC_DATARATE_64HZ();
    //SET_ADC_DATARATE_80HZ();
    SET_ADC_DATARATE_512HZ();
}

//--------------------------------------------------------------------------
void InitADC_Op1n1_Avss (void)
{
    //**************
    //***Switch set
    //**************
    //--- all switch set floating
    fun_StripModuleAllOpen();
    SET_PIN_OP1N2_OPEN();
    SET_PIN_OP2N_OPEN();
    //---set VG0
    SET_PIN_VG1_GND();
    SET_PIN_VG0_GND();
    //---set Op1n
    SET_PIN_OP1N1_OP1N();
    SET_PIN_OP1S1_OP1O();
    SET_PIN_OPnP_DAC1O(1);
    
		_pac3 = 1;  		
		_papu3=0;//去掉血糖检测端上拉，否则有电流??
		
		up_pin4 =0;//血糠试纸插入脚拉?		
		strips_pin4_dir = 1;  
		

#if 0
							
		strips_pin8_dir=1;//in--strips pin8
		up_pin8=0;
		strips_pin8=0;
		
		strips_pin7_dir=1;//in--strips pin7
		up_pin7=0;
		strips_pin7=0;
		
		
		strips_pin6_dir=1;//in--strips pin6
		up_pin6=0;
		strips_pin6=0;	
	    
 		_papu1 =0;//--strips pin6--G35改到此脚！！		
		_pac1 = 1;  		
		   
 #endif   
    
    
    SET_OPAn_POWER(1,POWERON);
    
    // adc
    //SET_ADC_CHANNEL_P_DAC1O();
    //SET_ADC_CHANNEL_N_OP1N1();
    SET_ADC_CHANNEL_N_AVSS();
    //SET_ADC_CHANNEL_N_DAC1O();
    SET_ADC_CHANNEL_P_OP1S1();
    SET_VREF_GAIN_1();
    SET_PGA_BYPASS_WITHBUF();
    //SET_PGA_BYPASS_WITHOUTBUF();
    SET_ADC_GAIN_1();
    SET_ADC_DCSET_0V();
    //SET_ADC_DATARATE_10HZ();
    //SET_ADC_DATARATE_40HZ();
    //SET_ADC_DATARATE_64HZ();
    //SET_ADC_DATARATE_80HZ();
    SET_ADC_DATARATE_512HZ();
}

//--------------------------------------------------------------------------
void InitADC_Op1n2_Avss (void)
{
    //**************
    //***Switch set
    //**************
    //--- all switch set floating
    fun_StripModuleAllOpen();
    SET_PIN_OP1N1_OPEN();
    SET_PIN_OP2N_OPEN();
    //---set VG0
    //SET_PIN_VG1_GND();
    SET_PIN_VG0_GND();
    //---set Op1n
    SET_PIN_OP1N2_OP1N();
    SET_PIN_OP1S0_OP1O();
    SET_PIN_OPnP_DAC1O(1);
    
    SET_OPAn_POWER(1,POWERON);
    
    // adc
    //SET_ADC_CHANNEL_P_DAC1O();
    //SET_ADC_CHANNEL_N_OP1N1();
    SET_ADC_CHANNEL_N_AVSS();
    //SET_ADC_CHANNEL_N_DAC1O();
    SET_ADC_CHANNEL_P_OP1S0();
    SET_VREF_GAIN_1();
    SET_PGA_BYPASS_WITHBUF();
    //SET_PGA_BYPASS_WITHOUTBUF();
    SET_ADC_GAIN_1();
    SET_ADC_DCSET_0V();
    //SET_ADC_DATARATE_10HZ();
    //SET_ADC_DATARATE_40HZ();
    //SET_ADC_DATARATE_64HZ();
    //SET_ADC_DATARATE_80HZ();
    SET_ADC_DATARATE_512HZ();
}

//--------------------------------------------------------------------------
void InitADC_Op2n_Op2o (void)
{
    //--- all switch set floating
    fun_StripModuleAllOpen2();
    SET_PIN_OP1N1_OPEN();
    SET_PIN_OP1N2_OPEN();
    SET_PIN_OP1S0_OPEN();
    SET_PIN_OP1S1_OPEN();

    //---set VG0
    //SET_PIN_VG1_GND();
    //SET_PIN_VG0_GND();
    
    //--- set io
    SCLC =0;
    SCL =1;
    
    _pa3 =0;
    _pac3 =0;

    //---set Op1n
	SET_PIN_OP2N_OP2N();
	SET_PIN_OP2O_OP2O();
	SET_PIN_OPnP_DAC1O(2);
	
    
    SET_OPAn_POWER(2,POWERON);
    
    // adc
    SET_ADC_CHANNEL_N_OP2N();
	SET_ADC_CHANNEL_P_OP2O();
    SET_VREF_GAIN_1();
    SET_PGA_BYPASS_WITHBUF();
    //SET_PGA_BYPASS_WITHOUTBUF();
    SET_ADC_GAIN_1();
    SET_ADC_DCSET_0V();
    //SET_ADC_DATARATE_10HZ();
    //SET_ADC_DATARATE_40HZ();
    //SET_ADC_DATARATE_64HZ();
    //SET_ADC_DATARATE_80HZ();
    SET_ADC_DATARATE_512HZ();
}

//--------------------------------------------------------------------------
void InitADC_Op2n_Avss (void)
{
    //--- all switch set floating
    fun_StripModuleAllOpen();
    SET_PIN_OP1N1_OPEN();
    SET_PIN_OP1N2_OPEN();
    SET_PIN_OP1S0_OPEN();
    SET_PIN_OP1S1_OPEN();

    //---set VG0
    //SET_PIN_VG1_GND();
    SET_PIN_VG0_GND();
    //---set Op1n
	SET_PIN_OP2N_OP2N();
	SET_PIN_OP2O_OP2O();
	SET_PIN_OPnP_DAC1O(2);
	
		_pac3 = 1;  		
		_papu3=0;//去掉血糖检测端上拉，否则有电流??
		
		up_pin4 =0;//血糠试纸插入脚拉?		
		strips_pin4_dir = 1;  
		

#if 0

							
		strips_pin8_dir=1;//in--strips pin8
		up_pin8=0;
		strips_pin8=0;
		
		strips_pin7_dir=1;//in--strips pin7
		up_pin7=0;
		strips_pin7=0;
		
		
		strips_pin6_dir=1;//in--strips pin6
		up_pin6=0;
		strips_pin6=0;	
	
		_papu1 =0;//--strips pin6--G36改到此脚！！		
		_pac1 = 1;  		
#endif	    

    SET_OPAn_POWER(2,POWERON);
    
    // adc
    SET_ADC_CHANNEL_N_AVSS();
	SET_ADC_CHANNEL_P_OP2O();
    SET_VREF_GAIN_1();
    SET_PGA_BYPASS_WITHBUF();
    //SET_PGA_BYPASS_WITHOUTBUF();
    SET_ADC_GAIN_1();
    SET_ADC_DCSET_0V();
    //SET_ADC_DATARATE_10HZ();
    //SET_ADC_DATARATE_40HZ();
    //SET_ADC_DATARATE_64HZ();
    //SET_ADC_DATARATE_80HZ();
    SET_ADC_DATARATE_512HZ();
}



//--------------------------------------------------------------------------
unsigned int Measurement_Temp (void)
{
	volatile unsigned char count,temp;
	volatile unsigned int  adc_buf;
	volatile unsigned int  Ibuf0,Ibuf1;
	
    //--- Dacvref Enable
    fun_DACVREFInit(POWERON);	
	
	//--- PC Pin-shared Functions
	_pcs0 |= 0b00110000;				
			//Bit 7~6 PCS07~PCS06: PC3 Pin-Shared function selection
			//00/01/10: PC3/PTCK2
			//11: AN1
			//Bit 5~4 PCS05~PCS04: PC2 Pin-Shared function selection
			//00: PC2/PTP2I
			//01: PTP2
			//10: PC2/PTP2I
			//11: AN0
			//Bit 3~2 PCS03~PCS02: PC1 Pin-Shared function selection
			//00/01: PC1/PTCK1
			//10: PTP0
			//11: AN3
			//Bit 1~0 PCS01~PCS00: PC0 Pin-Shared function selection
			//00/01: PC0/PTP1I/INT5
			//10: PTP1
			//11: AN2	
	
	//--- set adc channel
    SET_ADC_CHANNEL_N_AVSS();
    SET_ADC_CHANNEL_P_AN0();
    //--- set gain
    SET_VREF_GAIN_1();
    //--- set pga buffer
    SET_PGA_BYPASS_WITHBUF();
    //SET_PGA_BYPASS_WITHOUTBUF();
    //--- set adc gain
    SET_ADC_GAIN_1();
    //--- set dcset
    SET_ADC_DCSET_0V();
    //--- set data rate
    //SET_ADC_DATARATE_10HZ();
    //SET_ADC_DATARATE_40HZ();
    //SET_ADC_DATARATE_64HZ();
    SET_ADC_DATARATE_512HZ();
 
 	for(count =0; count <50;count++)
	{
		GCC_CLRWDT();
		GCC_DELAY(1000);
	}    
    
    //--- start adc
    fun_ADCStart();
    
    //--- wait adc ready
    temp =1;
   	while(temp)
   	{
   		if(SDKADCSourceData.flag.b.IsReady ==1)
   				temp =0;
		GCC_CLRWDT();
   	}
   	//--- stop adc
    fun_ADCStop();
    
   	adc_buf = SDKADCSourceData.data.ADCData >> 16;
   	
   	//--- read temp table
   	for(count =0;count <=51;count++)
   	{
   		if(adc_buf > R103KT_TABLE[count])
   			break;
   	}
   	
   	// adc[count-1] - current adc
   	//----------------------------- + (count-1)
   	// adc[count-1] - adc[count]

	Ibuf0 = R103KT_TABLE[count -1] - adc_buf;
	Ibuf1 = R103KT_TABLE[count -1] - R103KT_TABLE[count];
	Ibuf0 *= 100;
	Ibuf0 /= Ibuf1;
	Ibuf1 = (count-1) * 100;
	Ibuf0 +=  Ibuf1;
	Ibuf0 += 5;
	Ibuf0 /= 10;
	
	
	
	return	Ibuf0;
}

//--------------------------------------------------------------------------
unsigned int Measurement_Battery (void)
{
	unsigned int count,temp;
	volatile unsigned int  adc_buf;
//	volatile unsigned long  Lbuf0;

    //--- Dacvref Enable
    fun_DACVREFInit(POWERON);
	
//	P_IOPower =1;
	
	//--- PC Pin-shared Functions
	_pcs0 |= 0b11000000;				
			//Bit 7~6 PCS07~PCS06: PC3 Pin-Shared function selection
			//00/01/10: PC3/PTCK2
			//11: AN1
			//Bit 5~4 PCS05~PCS04: PC2 Pin-Shared function selection
			//00: PC2/PTP2I
			//01: PTP2
			//10: PC2/PTP2I
			//11: AN0
			//Bit 3~2 PCS03~PCS02: PC1 Pin-Shared function selection
			//00/01: PC1/PTCK1
			//10: PTP0
			//11: AN3
			//Bit 1~0 PCS01~PCS00: PC0 Pin-Shared function selection
			//00/01: PC0/PTP1I/INT5
			//10: PTP1
			//11: AN2
	
	//--- set adc channel
    SET_ADC_CHANNEL_N_AN1();
    SET_ADC_CHANNEL_P_AVSS();
    //--- adc channel change
    _inx0 =1;
    _inx1 =1;
    //--- set gain
    SET_VREF_GAIN_1();
    //--- set pga buffer
    SET_PGA_BYPASS_WITHBUF();
    //SET_PGA_BYPASS_WITHOUTBUF();
    //--- set adc gain
    SET_ADC_GAIN_1();
    //--- set dcset
    SET_ADC_DCSET_0V();
    //--- set data rate
    //SET_ADC_DATARATE_10HZ();
    //SET_ADC_DATARATE_40HZ();
    //SET_ADC_DATARATE_64HZ();
    SET_ADC_DATARATE_128HZ();
  //  SET_ADC_DATARATE_512HZ();
    
	for(count =0; count <500;count++)
	{
		GCC_CLRWDT();
		GCC_DELAY(1000);
	}    
    
    //--- start adc
    fun_ADCStart();
    
    //--- wait adc ready
    temp =1;
   	while(temp)
   	{
   		if(SDKADCSourceData.flag.b.IsReady ==1)
   				temp =0;
		GCC_CLRWDT();
   	}
    //--- adc channel change
    _inx0 =0;
    _inx1 =0;
   	//--- stop adc
    fun_ADCStop();
    
//    SET_ADC_CHANNEL_N_AVSS();
//    SET_ADC_CHANNEL_P_AVSS();
    //--- Dacvref Enable
//    fun_DACVREFInit(POWEROFF);
    
    _pcs0 &= ~0b11000000;
    
//    P_IOPower =0;
    
   	adc_buf = SDKADCSourceData.data.ADCData >> 16;
//   	//--- 算電量百分比
//   	if(adc_buf > 19660)
//   	{
//		Lbuf0 = adc_buf;
//		Lbuf0 -= 19660;
//		Lbuf0 *= 100;
//		//--- 3V/2 = 1.5V
//		//--- (1.5/2)* 8388608 = 6291456 = 00600000h
//		//--- 00600000h >> 8 = 6000h = 24576
//	
//		//--- 2.4V/2 = 1.2V
//		//--- (1.2/2)* 8388608 = 5033165 = 004ccccdh
//		//--- 004ccccdh >> 8 = 4ccch = 19660
//		
//		//24576 - 19660 = 4916
//		//adc_buf - 19660 = x
//		//x * 100 = y / 4916 = z%
//			
//		
//		Lbuf0 /= 4916;
//		
//		if(Lbuf0 > 100)
//			Lbuf0 = 100;
//   	}
//   	else
//   		Lbuf0 =0;

	return	adc_buf;
	
}

//--------------------------------------------------------------------------
unsigned int Measurement_Daco (void)
{
	unsigned char temp;
	volatile unsigned int  Ibuf0;
	
    //**************
    //***Switch set
    //**************
    //--- Dacvref Enable
    fun_DACVREFInit(POWERON);
    
    // adc chnanel
    SET_ADC_CHANNEL_P_DAC1O();
    SET_ADC_CHANNEL_N_AVSS();

    SET_VREF_GAIN_1();
    SET_PGA_BYPASS_WITHBUF();
    //SET_PGA_BYPASS_WITHOUTBUF();
    SET_ADC_GAIN_1();
    SET_ADC_DCSET_0V();
    //SET_ADC_DATARATE_10HZ();
    //SET_ADC_DATARATE_40HZ();
    //SET_ADC_DATARATE_64HZ();
    //SET_ADC_DATARATE_80HZ();
    SET_ADC_DATARATE_512HZ();
    fun_ADCStart();
    F_ReadAdc_Start =1;
    
    temp =1;
   	while(temp)
   	{
   		if(SDKADCSourceData.flag.b.IsReady)
   			temp =0;
		GCC_CLRWDT();
   	}
   	
   	//--- stop adc
    fun_ADCStop();
    
    Ibuf0 = SDKADCSourceData.data.ADCData >> 16;
   	
   	//Ibuf0 = ADCtoCurrent_Convert(SDKADCSourceData.data.ADCData/4096/16);
   	
   	return 	Ibuf0;
}
#if 0
//--------------------------------------------------------------------------
unsigned int Measurement_Op1n1_VG0 (void)
{
	unsigned char temp;
	volatile unsigned int  Ibuf0;
	
    //**************
    //***Switch set
    //**************
	InitADC_Op1n1_Avss();
	
    fun_ADCStart();
    F_ReadAdc_Start =1;
    
    temp =1;
   	while(temp)
   	{
   		if(SDKADCSourceData.flag.b.IsReady)
   			temp =0;
		GCC_CLRWDT();
   	}
   	
   	//--- stop adc
    fun_ADCStop();
    
    Ibuf0 = SDKADCSourceData.data.ADCData >> 16;
   	
   	//Lbuf0 = ADCtoCurrent_Convert(SDKADCSourceData.data.ADCData/4096/16);
   	
   	return 	Ibuf0;
}

//--------------------------------------------------------------------------
unsigned int Measurement_Op1n2_VG0 (void)
{
	unsigned char temp;
	volatile unsigned int  Ibuf0;
	
    //**************
    //***Switch set
    //**************
	InitADC_Op1n2_Avss();
	
    fun_ADCStart();
    F_ReadAdc_Start =1;
    
    temp =1;
   	while(temp)
   	{
   		if(SDKADCSourceData.flag.b.IsReady)
   			temp =0;
		GCC_CLRWDT();
   	}
   	
   	//--- stop adc
    fun_ADCStop();
    
    Ibuf0 = SDKADCSourceData.data.ADCData >> 16;
   	
   	//Lbuf0 = ADCtoCurrent_Convert(SDKADCSourceData.data.ADCData/4096/16);
   	
   	return 	Ibuf0;
}
#endif
//--------------------------------------------------------------------------
unsigned int Measurement_Op1n1_Op1s1 (void)
{
	unsigned char temp;
	volatile unsigned int  Ibuf0;
	
    //**************
    //***Switch set
    //**************
	InitADC_Op1n1_Op1s1();
	
	
    fun_ADCStart();
    F_ReadAdc_Start =1;
    
    temp =1;
   	while(temp)
   	{
   		if(SDKADCSourceData.flag.b.IsReady)
   			temp =0;
		GCC_CLRWDT();
   	}
   	
   	//--- stop adc
    fun_ADCStop();
    
    Ibuf0 = SDKADCSourceData.data.ADCData >> 16;
    
	return 	Ibuf0;
}




#if 0

//--------------------------------------------------------------------------
unsigned int Measurement_Op2n_VG0 (void)
{
	unsigned char temp;
	volatile unsigned int  Ibuf0;
	
    //**************
    //***Switch set
    //**************
	InitADC_Op2n_Avss();
	SET_PIN_VG1_GND();
	GCC_CLRWDT();
	GCC_CLRWDT();
    fun_ADCStart();
    F_ReadAdc_Start =1;
    
    temp =1;
   	while(temp)
   	{
   		if(SDKADCSourceData.flag.b.IsReady)
   			temp =0;
		GCC_CLRWDT();
   	}
   	
   	//--- stop adc
    fun_ADCStop();
    
    Ibuf0 = SDKADCSourceData.data.ADCData >> 16;
   	
   	//Lbuf0 = ADCtoCurrent_Convert(SDKADCSourceData.data.ADCData/4096/16);
   	
   	return 	Ibuf0;	
}

//--------------------------------------------------------------------------
unsigned int Measurement_Op2n_Op2o (void)
{
	unsigned char temp;
	volatile unsigned int  Ibuf0;
	
    //**************
    //***Switch set
    //**************
	InitADC_Op2n_Op2o();
	
    fun_ADCStart();
    F_ReadAdc_Start =1;
    
    temp =1;
   	while(temp)
   	{
   		if(SDKADCSourceData.flag.b.IsReady)
   			temp =0;
		GCC_CLRWDT();
   	}
   	
   	//--- stop adc
    fun_ADCStop();
   	
   	Ibuf0 = SDKADCSourceData.data.ADCData >> 16;
   	Ibuf0 = ADCtoCurrent_Convert(Ibuf0,C_ResOP2N);
    
	return 	Ibuf0;
}
#endif
//--------------------------------------------------------------------------
void Set_HCT_Adc_Channel (unsigned char mode)
{
	fun_ADCStop();
	switch(mode)
	{
		//---HCT_RF1_R
		case 0:
		{						
			SET_PIN_SINI_OP3N();
            SET_PIN_RF1_OP3O();
            SET_PIN_RF2_OPEN();
            SET_PIN_OPA4_RF1();
            SET_ADC_CHANNEL_N_MOD1ON();
            SET_ADC_CHANNEL_P_MOD1OP();
            //SET_ADC_DATARATE_40HZ();
            SET_ADC_DATARATE_160HZ();
            //SET_ADC_DATARATE_320HZ();
            //SET_ADC_GAIN_1();
            fun_ADCStart();
            
//			SET_PIN_OP1N1_OP1N();
//			SET_PIN_OP1S0_OPEN();
//			SET_PIN_SINI_OP3N();
////			SET_PIN_SINO1_SINOUT();
////			fun_SineWaveInit(M_SinFreq);
//			
//			
//            SET_PIN_RF1_OP3O();
//            SET_PIN_RF2_OPEN();
//            
//            SET_PIN_OPA4_RF1();
//            SET_OPA4_GAIN_2_33();
//            SET_OPA34_POWER(1);
//            
//            SET_VREF_GAIN_1();
//            SET_PGA_GAIN_1();
//            SET_ADC_GAIN_1();
//            SET_ADC_DCSET_0V();
//            
//            
//            SET_ADC_CHANNEL_N_MOD1ON();
//            SET_ADC_CHANNEL_P_MOD1OP();
//            //SET_ADC_DATARATE_40HZ();
//            //SET_ADC_DATARATE_160HZ();
//            SET_ADC_DATARATE_320HZ();
//			SET_PIN_OPA4_RF1();
//            fun_ADCStart();
            
			break;
		}
		
		//---HCT_RF1_I
		case 1:
		{
			SET_PIN_SINI_OP3N();
            SET_PIN_RF1_OP3O();
            SET_PIN_RF2_OPEN();
            SET_PIN_OPA4_RF1();
            SET_ADC_CHANNEL_N_MOD2ON();
            SET_ADC_CHANNEL_P_MOD2OP();
            //SET_ADC_DATARATE_40HZ();
            SET_ADC_DATARATE_160HZ();
            //SET_ADC_DATARATE_320HZ();
            //SET_ADC_GAIN_1();
            fun_ADCStart();
            
			break;
		}
		
		//---HCT_RX1_R
		case 2:
		{
			SET_PIN_SINI_OP3N();
            SET_PIN_RF1_OP3O();
            SET_PIN_RF2_OPEN();
            SET_PIN_OPA4_RX1();
            SET_ADC_CHANNEL_N_MOD1ON();
            SET_ADC_CHANNEL_P_MOD1OP();
            //SET_ADC_DATARATE_40HZ();
            SET_ADC_DATARATE_160HZ();
            //SET_ADC_DATARATE_320HZ();
            //SET_ADC_GAIN_1();
            fun_ADCStart();
            
//			SET_PIN_OP1N1_OP1N();
//			SET_PIN_OP1S0_OPEN();
//			SET_PIN_SINI_OP3N();
////			SET_PIN_SINO1_SINOUT();
////			fun_SineWaveInit(M_SinFreq);
//			
//			
//            SET_PIN_RF1_OP3O();
//            SET_PIN_RF2_OPEN();
//            
//            SET_PIN_OPA4_RX1();
//            SET_OPA4_GAIN_2_33();
//            SET_OPA34_POWER(1);
//            
//            SET_VREF_GAIN_1();
//            SET_PGA_GAIN_1();
//            SET_ADC_GAIN_1();
//            SET_ADC_DCSET_0V();
//            
//            
//            SET_ADC_CHANNEL_N_MOD1ON();
//            SET_ADC_CHANNEL_P_MOD1OP();
//            //SET_ADC_DATARATE_40HZ();
//            //SET_ADC_DATARATE_160HZ();
//            SET_ADC_DATARATE_320HZ();
//			SET_PIN_OPA4_RX1();
//            fun_ADCStart();
            
			break;
		}
		
		//---HCT_RX1_I
		case 3:
		{
			SET_PIN_SINI_OP3N();
            SET_PIN_RF1_OP3O();
            SET_PIN_RF2_OPEN();
            SET_PIN_OPA4_RX1();
            SET_ADC_CHANNEL_N_MOD2ON();
            SET_ADC_CHANNEL_P_MOD2OP();
            //SET_ADC_DATARATE_40HZ();
            SET_ADC_DATARATE_160HZ();
            //SET_ADC_DATARATE_320HZ();
            //SET_ADC_GAIN_1();
            fun_ADCStart();
            
			break;
		}
		
		//---HCT_RF2_R
        case 4:
        {
            SET_PIN_RF1_OPEN();
            SET_PIN_RF2_OP3O();
            SET_PIN_OPA4_RF2();
            SET_ADC_CHANNEL_N_MOD1ON();
            SET_ADC_CHANNEL_P_MOD1OP();
            //SET_ADC_DATARATE_40HZ();
            SET_ADC_DATARATE_160HZ();
            fun_ADCStart();
            
            break;
        }
        
        //--- HCT_RF2_I
        case 5:
        {
            SET_PIN_RF1_OPEN();
            SET_PIN_RF2_OP3O();
            SET_PIN_OPA4_RF2();
            SET_ADC_CHANNEL_N_MOD2ON();
            SET_ADC_CHANNEL_P_MOD2OP();
            //SET_ADC_DATARATE_40HZ();
            SET_ADC_DATARATE_160HZ();
            fun_ADCStart();
            
            break;
        }
        
        //--- HCT_RX2_R
        case 6:
        {
            SET_PIN_RF1_OPEN();
            SET_PIN_RF2_OP3O();
            SET_PIN_OPA4_RX1();
            SET_ADC_CHANNEL_N_MOD1ON();
            SET_ADC_CHANNEL_P_MOD1OP();
            //SET_ADC_DATARATE_40HZ();
            SET_ADC_DATARATE_160HZ();
            fun_ADCStart();
            
            break;
        }
        
        //--- HCT_RX2_I
        case 7:
        {
            SET_PIN_RF1_OPEN();
            SET_PIN_RF2_OP3O();
            SET_PIN_OPA4_RX1();
            SET_ADC_CHANNEL_N_MOD2ON();
            SET_ADC_CHANNEL_P_MOD2OP();
            //SET_ADC_DATARATE_40HZ();
            SET_ADC_DATARATE_160HZ();
            fun_ADCStart();
            
            break;
        }
		
        default:
            break;
	}
	
}
#if 0
double Pythagoreantheorem(signed int *bimBuf)
{
//    double z;
//    z = (double)re*re+(double)im*im;
//    z = sqrt(z);
//    return z;
	volatile double RF1_RE,RF1_I,RX1_RE,RX1_I;
	volatile double Ibuf0,Ibuf1,Impedance;
	
	RF1_RE = bimBuf[0];
	RF1_I = bimBuf[1];
	RX1_RE = bimBuf[2];
	RX1_I = bimBuf[3];	
		

	Ibuf0 =RF1_RE*RF1_RE;//pow(RF1_RE, 2);
	Ibuf0 += RF1_I*RF1_I;//pow(RF1_I, 2);
	Ibuf0=sqrt(Ibuf0);
	
	
	Ibuf1 = RX1_RE*RX1_RE;//pow(RX1_RE, 2);
	Ibuf1 +=RX1_I*RX1_I; pow(RX1_I, 2);
	Ibuf1=sqrt(Ibuf1);
	
	Impedance =  Ibuf1 / Ibuf0;
	Impedance *= (double)3.28;	
	
	return Impedance;


}

//--------------------------------------------------------------------------
//double Impedance_Compute(signed int *bimBuf)
//{
//	volatile double RF1_RE,RF1_I,RX1_RE,RX1_I;
//	volatile double Ibuf0,Ibuf1,Impedance;
//	
//	RF1_RE = bimBuf[0];
//	RF1_I = bimBuf[1];
//	RX1_RE = bimBuf[2];
//	RX1_I = bimBuf[3];	
//		
//
//	Ibuf0 =RF1_RE*RF1_RE;//pow(RF1_RE, 2);
//	Ibuf0 += RF1_I*RF1_I;//pow(RF1_I, 2);
//	Ibuf0=sqrt(Ibuf0);
//	
//	
//	Ibuf1 = RX1_RE*RX1_RE;//pow(RX1_RE, 2);
//	Ibuf1 +=RX1_I*RX1_I; pow(RX1_I, 2);
//	Ibuf1=sqrt(Ibuf1);
//	
//	Impedance =  Ibuf1 / Ibuf0;
//	
////G777G	
////	Impedance *= (double)3.28;	
//
////G35
//	Impedance *= (double)10.0;
//
//		
////	Impedance = RX1_RE * 3;
////	Impedance /= RF1_RE;
////	GCC_NOP();
//	
//	
//	return Impedance;
//}
/*????????????迹?ж????????????
????????????????????????????????????????????????迹??????*/
double Impedance_Compute1(signed int *bimBuf)
{
 volatile double RF1_RE,RF1_I,RX1_RE,RX1_I;
 volatile double Ibuf0,Ibuf1,Impedance;
 
 RF1_RE = bimBuf[0];
 RF1_I = bimBuf[1];
 RX1_RE = bimBuf[2];
 RX1_I = bimBuf[3]; 
  

// Ibuf0 =pow(RF1_RE, 2);
 Ibuf0 =(signed long)RF1_RE*RF1_RE;
 
 
// Ibuf0 += pow(RF1_I, 2);
 
 Ibuf0 +=(signed long)RF1_I*RF1_I; 
 
// Ibuf0=sqrt(Ibuf0);
 
 
// Ibuf1 = pow(RX1_RE, 2);
 Ibuf1 = (signed long)RX1_RE*RX1_RE; 
 
 
// Ibuf1 +=pow(RX1_I, 2);
 Ibuf1 +=(signed long)RX1_I*RX1_I; 
 
// Ibuf1=sqrt(Ibuf1);
// Ibuf1=sqrt(Ibuf1);
 Impedance =  (10.7584*Ibuf1 / Ibuf0);//3.28*3.28=10.7584
 
// Impedance =  sqrt(10.7584*Ibuf1 / Ibuf0); 
 
 
//#ifdef G777G_TEST 
////G777G +
// Impedance *= (double)3.28; 
//#endif
//
//#ifdef G35 
////G35
// Impedance *= (double)3.28;
//#endif
//  
// Impedance = RX1_RE * 3;
// Impedance /= RF1_RE;
// GCC_NOP();
 
 return Impedance;
}

//--------------------------------------------------------------------------
double Theta_Compute(signed int *bimBuf)
{
	volatile double RF1_RE,RF1_I,RX1_RE,RX1_I;
	volatile double Ibuf0,Ibuf1,Theta;
	
	RF1_RE = bimBuf[0];
	RF1_I = bimBuf[1];
	RX1_RE = bimBuf[2];
	RX1_I = bimBuf[3];	
		

	Ibuf0=atan2(RF1_I,RF1_RE);
	
	Ibuf0 /= 3.14;
	Ibuf0 *= 180;
	if(Ibuf0 < 0)
		Ibuf0 += 360;
		
	
	Ibuf1=atan2(RX1_I,RX1_RE);
	
	Ibuf1 /= 3.14;
	Ibuf1 *= 180;
	if(Ibuf1 < 0)
		Ibuf1 += 360;
		
	if((Ibuf1 - Ibuf0) > 180)
	{
		Theta = Ibuf1 - Ibuf0;
		Theta -= 360;
	}
	else
		Theta = Ibuf1 - Ibuf0;
	
	return Theta;
}
#endif
double Impedance_Compute(signed int *bimBuf)
{
	volatile double RF1_RE,RF1_I,RX1_RE,RX1_I;
	volatile double Ibuf0,Ibuf1,Impedance;
	
	RF1_RE = bimBuf[0];
	RF1_I = bimBuf[1];
	RX1_RE = bimBuf[2];
	RX1_I = bimBuf[3];	
		

	Ibuf0 =pow(RF1_RE, 2);
	Ibuf0 += pow(RF1_I, 2);
	Ibuf0=sqrt(Ibuf0);
	
	
	Ibuf1 = pow(RX1_RE, 2);
	Ibuf1 +=pow(RX1_I, 2);
	Ibuf1=sqrt(Ibuf1);
	
	Impedance =  Ibuf1 / Ibuf0;
	Impedance *= (double)3.28;	
		
//	Impedance = RX1_RE * 3;
//	Impedance /= RF1_RE;
//	GCC_NOP();
	
	
	return Impedance;
}

//--------------------------------------------------------------------------
double atan2(double y,double  x)
{
    double v;
    if(fabs(x) >= fabs(y)) 
    {
            v = atan(y/x);
            if( x < 0.0)
            {
                    if(y >= 0.0)
                            v += M_PI;
                    else
                            v -= M_PI;
            }
            return v;
    }
    v = -atan(x/y);
    if(y < 0.0)
            v -= M_PI_2;
    else
            v += M_PI_2; 
              
    return v;
}

//--------------------------------------------------------------------------
//unsigned int ADCtoCurrent_Convert (unsigned long AdcCount) by Gary
 double ADCtoCurrent_Convert (signed long AdcCount,double Res)
{
	volatile  double Lbuf0;

	if(AdcCount >=0)
	{
		Lbuf0 = AdcCount * 2000;
		Lbuf0 /= 32768;
		Lbuf0 *=1000;
		Lbuf0 /= Res;
	}
	else
		Lbuf0 =0;
	
		
	return Lbuf0;
}

unsigned int Current_to_AD_Convert (unsigned int Current,double Res)
 {
	 volatile  double Lbuf0;
 
 
		 Lbuf0 = Current;
		 Lbuf0 *= Res;
		 Lbuf0 *=0.016384;
		 if(Lbuf0<0)
			Lbuf0=0;
	 
		 
	 return Lbuf0;
 }
#if 0
//--------------------------------------------------------------------------
signed int Cal_MeasCurr( unsigned int AdcCount )
{
 volatile double Curr_X1,Curr_Y1;
 volatile double Curr_X2,Curr_Y2;
 volatile double Current;

 Curr_X1 = M_Cal_10K_Adc ;
 Curr_Y1 = 4000;
 Curr_Y1 /=10000;
 Curr_Y1 /=10000;
 //
 Curr_X2 = M_Cal_100K_Adc ;
 Curr_Y2 = 4000;
 Curr_Y2 /=10000;
 Curr_Y2 /=100000;
 //
 Current = ((Curr_Y2-Curr_Y1) * AdcCount) / (Curr_X2 - Curr_X1);
 Current += ((Curr_Y1*Curr_X2)-(Curr_Y2*Curr_X1))/(Curr_X2-Curr_X1);
 Current *= 100000000;
 return Current;
}
#endif

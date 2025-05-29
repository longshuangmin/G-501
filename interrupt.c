#include "include.h"
#include "AP_STARTUP_OPTION.h"

//==========================================================//
//------ interrupt program in here -------------------------//
//==========================================================//
//void __attribute((interrupt(0x04))) _Int0_funinterrupt(void)
__attribute__((interrupt(0x04),reg_acc(0x80),isr_at(AP_Start_Address+0x04)))
void Int0_funinterrupt(void)
{
	_int0f = 0;
}

//==========================================================//
//------ interrupt program in here -------------------------//
//==========================================================//
//void __attribute((interrupt(0x08))) _Int1_funinterrupt(void)
__attribute__((interrupt(0x08),reg_acc(0x81),isr_at(AP_Start_Address+0x08))) 
void Int1_funinterrupt(void)
{
	_int1f = 0;
}

//==========================================================//
//------ interrupt program in here -------------------------//
//==========================================================//
//void __attribute((interrupt(0x0c))) _Adc_funinterrupt(void)
__attribute__((interrupt(0x0c),reg_acc(0x82),isr_at(AP_Start_Address+0x0c)))
void Adc_funinterrupt(void)
{
	_adf = 0;
	
	if (_eoc == 1)
	{ //ADC 轉換完成
		//SDKADCSourceData.SamplingCnt++;
		//前三筆數據丟掉，第四筆才開始處理
		if (SDKADCSourceData.SamplingCnt > 3)
		//if (SDKADCSourceData.SamplingCnt > 7)
		//if (SDKADCSourceData.SamplingCnt > 15)
		{
			// Read current ADC
			_adcdl = 1;
			SDKADCSourceData.data.byte.ByteLow  = _adrl;
			SDKADCSourceData.data.byte.ByteMid  = _adrm;
			SDKADCSourceData.data.byte.ByteHigh = _adrh;
			SDKADCSourceData.data.byte.ByteRes  = 0x00;
			//SDKADCSourceData.data.ADCData /= 256;
			_adcdl = 0; //數據讀取完成，取消鎖存
			SDKADCSourceData.flag.b.IsReady = 1;
		}
		else
			SDKADCSourceData.SamplingCnt++;	
			
		_eoc = 0;
	}
}

//==========================================================//
//------ interrupt program in here -------------------------//
//==========================================================//
//--- interrupt 10-bit TM0 program in here (1ms @ 4Mhz)---//
//void __attribute((interrupt(0x10))) _Multi0_funinterrupt(void)
__attribute__((interrupt(0x10),reg_acc(0x83),isr_at(AP_Start_Address+0x10)))
void Multi0_funinterrupt(void)
{
	_mf0f = 0;
	_ptm0af = 0;	
	
//	//---暫定 Beep
//	if(F_Beep_Act)
//		P_VoiceBuz =~P_VoiceBuz;
//	else
//		P_VoiceBuz =0;	
	//_pd6=~_pd6;//LED	
	//--- main loop timer
#if ACFG_OSC_EN == 0
	M_Main_cnt++;
	if(M_Main_cnt>= 80)
#endif
	{
		M_Main_cnt = 0;
		F_MainTimerOut=1;    //10ms	
		work_time++;		
		if(F_MeasureStart)
		{				
//	  		//---Dec Count
//	  		if(M_Ibuf0 !=0)
//	  			M_Ibuf0--;
//			
//			if(M_Ibuf0 == 400)
//			{
//				//--- Daco1 Enable
//		        fun_DACnInit(1,DACnOEnable);
////				//--- Init OPA1
////				Initnal_OPA1_Gpio(1);
////			    //---set Op1n
////			    SET_PIN_OP1N1_OP1N();
////			    SET_PIN_OP1S0_OP1O();
////			    SET_PIN_OPnP_DAC1O(1);
////			    
////			    SET_OPAn_POWER(1,POWERON);
//			    
//				//--- Init adc
//				InitADC_Op1n1_Op1s1();
//			    //--- Start adc
//			    fun_ADCStart();		
//			}
//			else if(M_Ibuf0 ==0)
//			{
//				if(!C_LCD4V_Enable)
//					//--- dacvref off
//					fun_DACVREFInit(POWEROFF);	
//				//--- set daco1 to gnd
//				fun_DACnInit(1,DACnOGND);
//				//--- clear flag
//				F_MeasureStart =0;
//
//				
////				_phc6 =0;
////				_ph6 =~_ph6;
//			}

		}
	}


//	//--- Check UART RX timeout
	if(F_UartRxBegin ==1)
	{
		M_UARTRxTimeOut++;

		if(M_UARTRxTimeOut>= 100)  //4M =>160 //base 250us 20ms for timeout
	    {
	    	M_UARTRxTimeOut = 0;
	    	F_UartRxBegin =0;
	    	F_UartDataComing =1;
	    	//M_UART_RxIndex =0;
		}
	}
	else
		M_UARTRxTimeOut = 0;

}

//==========================================================//
//------ interrupt program in here -------------------------//
//==========================================================//
//void __attribute((interrupt(0x14))) _Multi1_funinterrupt(void)
__attribute__((interrupt(0x14),reg_acc(0x84),isr_at(AP_Start_Address+0x14)))
void Multi1_funinterrupt(void)
{
	_mf1f = 0;
}

//==========================================================//
//------ interrupt program in here -------------------------//
//==========================================================//
//void __attribute((interrupt(0x18))) _Multi2_funinterrupt(void)
__attribute__((interrupt(0x18),reg_acc(0x85),isr_at(AP_Start_Address+0x18)))
void Multi2_funinterrupt(void)
{
	_mf2f = 0;
}

//==========================================================//
//------ interrupt program in here -------------------------//
//==========================================================//
//void __attribute((interrupt(0x1c))) _Ovp_funinterrupt(void)
__attribute__((interrupt(0x1c),reg_acc(0x86),isr_at(AP_Start_Address+0x1c)))
void Ovp_funinterrupt(void)
{
	_ovpf = 0;
}

//==================================================//
//--- interrupt RTC program in here (0.5sec once)---//
//void __attribute((interrupt(0x20))) _TimeBase0_funinterrupt(void)
__attribute__((interrupt(0x20),reg_acc(0x87),isr_at(AP_Start_Address+0x20)))
void TimeBase0_funinterrupt(void)
{
	unsigned char M_DaysLimit,count,temp;
	
	_tb0f=0;	

	F_500ms_RTC = ~F_500ms_RTC;
	
	F_500ms_LCD =1;
	//_pd6=~_pd6;//LED
	if(M_Task != C_RTCModeSettingMode)
	{	
		//--- counting for RTC 2012~2099-----
		//--- 2012 1 /1 = sun (7)
		//M_Second,M_Minutes,M_Hour,M_Days,M_Week,M_Month,M_Year;
		M_Second_buf++;
		
		if(M_Second_buf >= 2)
		{	
			if(wait_sec)
			   wait_sec--;
			
			M_Second_buf =0;           //1sec
		    M_Second++;
   
		    if(M_Second >= 60)
		    {
		    	M_Second = 0;          //60sec
		    	F_LcdUpdateBuf =0;
		    //	if(gsm_time)
		    //		gsm_time--;
		    	M_Minutes++;
		    	if(M_Minutes >= 60)
		    	{
		    		M_Minutes = 0;         //60 minutes
		    	  
		    	  	M_Hour++;
		    	  	if(M_Hour >=24)
		    	  	{
		    	  		M_Hour = 0;
		    	  	
		    	  		//--- read days limit
		    	  		M_DaysLimit = Month_TABLE1[M_Month-1];
		    	  	
		    	  		//--- check leap year in February
		    	  		if(M_Month == 2)
		    	  		{
		    	  			//--- leap year check
		    	  			for(count=0; count<=22; count++)
		    	  			{
		    	  		  		temp = LeapYear_TABLE[count];
		    	  		  		if(temp == M_Year)
		    	  		  			M_DaysLimit++;
		    	  		  		if(temp > M_Year)
		    	  		  			break;
		    	  	  		}
		    	  		}
		    	  	
		    	  		M_Days++;
		    	  		if(M_Days > M_DaysLimit)
		    	  		{
		    	  			M_Days = 1;
		    	  		
		    	  			M_Month++;
		    	  			if(M_Month >12)
		    	  			{
		    	  				M_Month = 1;       //12=>1
		    	  			
		    	  				M_Year++;
		    	  				if(M_Year > 99)
		    	  				{
		    	  					M_Year = 12;    //2099~2012
		    	  				}
		    	  			}		
		    	  		}
		    	  	} 
		    	}
		    }
		}
	}


	//--- check ALARM mode if Enable??
	//--- Alarm1 check
	if(M_Task == C_StandByMode)
	{		
		if(M_Second ==0)
		{
			//--- Alarm1 check
			if((F_Alarm1_Enable) && (M_Alarm1_HR ==M_Hour) && (M_Alarm1_MIN ==M_Minutes))
				F_Alarm1_TimeUp_ACT = 1;
			//--- Alarm2 check
			else if((F_Alarm2_Enable) && (M_Alarm2_HR ==M_Hour) && (M_Alarm2_MIN ==M_Minutes))
				F_Alarm2_TimeUp_ACT = 1;
			//--- Alarm3 check
			else if((F_Alarm3_Enable) && (M_Alarm3_HR ==M_Hour) && (M_Alarm3_MIN ==M_Minutes))
				F_Alarm3_TimeUp_ACT = 1;
			//--- Alarm4 check
			else if((F_Alarm4_Enable) && (M_Alarm4_HR ==M_Hour) && (M_Alarm4_MIN ==M_Minutes))
				F_Alarm4_TimeUp_ACT = 1;
		}
	}
}

//==========================================================//
//------ interrupt program in here -------------------------//
//==========================================================//
//void __attribute((interrupt(0x24))) _TimeBase1_funinterrupt(void)
__attribute__((interrupt(0x24),reg_acc(0x88),isr_at(AP_Start_Address+0x24)))
void TimeBase1_funinterrupt(void)
{
	_tb1f = 0;
}

//==========================================================//
//------ interrupt program in here -------------------------//
//==========================================================//
//void __attribute((interrupt(0x28))) _Int2_funinterrupt(void)
__attribute__((interrupt(0x28),reg_acc(0x89),isr_at(AP_Start_Address+0x28)))
void Int2_funinterrupt(void)
{
	_int2f = 0;
}

//==========================================================//
//------ interrupt program in here -------------------------//
//==========================================================//
//void __attribute((interrupt(0x2c))) _Int3_funinterrupt(void)
__attribute__((interrupt(0x2c),reg_acc(0x8a),isr_at(AP_Start_Address+0x2c)))
void Int32_funinterrupt(void)
{
	_int3f = 0;
}

//==========================================================//
//--------- interrupt UART in here -------------------------//
//==========================================================//
//void __attribute((interrupt(0x30))) _Uart0_funinterrupt(void)
__attribute__((interrupt(0x30),reg_acc(0x8b),isr_at(AP_Start_Address+0x30)))
void Uart0_funinterrupt(void)
{
	volatile unsigned char temp;
	
	_ur0f =0;
	
	//clear urf flag
	if(_perr0 || _nf0 || _ferr0 || _oerr0)		// error found?
	{
	   temp = _u0sr;				//read USR to clear error flag 
	   temp = _txr_rxr0;				//read USR to clear error flag 	   	       
	    temp = temp;
	}
	else									// no error found
	{
		if(_rxif0)							//RXR	data register has available	data
		{
			F_UartRxBegin =1;
			M_UARTRxTimeOut =0;
		
			M_UART_RxFIFO[M_UART_RxIndex] =_txr_rxr0;
		    M_UART_RxIndex++;
		}
		
		//--- max 20 bytes
	    if(M_UART_RxIndex >= 127)
	    {
	    	F_UartRxBegin =0;
	    	M_UARTRxTimeOut = 0;
	    	//M_UART_RxIndex =0;
	    	F_UartDataComing =1;    //bytes =8
	    }
	    
		if(_txif0)
		{	 
			M_UART_TxIndex++; 		
			if(M_UART_TxIndex < M_UART_TxLength)
			{
				//temp = _usr;		//read USR to clear error flag 
		   		_txr_rxr0= M_UART_TxFIFO[M_UART_TxIndex];	
			}
			else
				temp = _u0sr;		//read USR to clear error flag 	
		}	
	}
}

//==========================================================//
//------ interrupt program in here -------------------------//
//==========================================================//
//void __attribute((interrupt(0x34))) _Sim_funinterrupt(void)
__attribute__((interrupt(0x34),reg_acc(0x8c),isr_at(AP_Start_Address+0x34)))
void Sim_funinterrupt(void)
{
	_simf = 0;
}

//==========================================================//
//------ interrupt program in here -------------------------//
//==========================================================//
//void __attribute((interrupt(0x38))) _Spi_funinterrupt(void)
__attribute__((interrupt(0x38),reg_acc(0x8d),isr_at(AP_Start_Address+0x38)))
void Spi_funinterrupt(void)
{
	_spif = 0;
}

//==========================================================//
//--------- interrupt UART in here -------------------------//
//==========================================================//
//void __attribute((interrupt(0x3c))) _Uart1_funinterrupt(void)
__attribute__((interrupt(0x3c),reg_acc(0x8e),isr_at(AP_Start_Address+0x3c)))
void Uart1_funinterrupt(void)
{

	unsigned char temp;
	
	//clear urf flag
	if(_perr1 || _nf1 || _ferr1 || _oerr1)		// error found?
	{
	   temp = _u1sr;				//read USR to clear error flag 
	   temp = _txr_rxr1;			//read USR to clear error flag 	   	       
		temp = temp;
	}
//	else									// no error found
//	{
		if(_rxif1)							//RXR	data register has available	data
		{
			F_UartRxBegin =1;
			M_UARTRxTimeOut =0;
		
			M_UART_RxFIFO[M_UART_RxIndex] =_txr_rxr1;
		    M_UART_RxIndex++;
		}
		
		//--- max 20 bytes
	    if(M_UART_RxIndex >= 32)
	    {
	    	F_UartRxBegin =0;
	    	M_UARTRxTimeOut = 0;
	    	F_UartDataComing =1;    //bytes =8
	    }
	    
		//if(_txif1 && _tidle1)
		if(_txif1)
		{	 
			M_UART_TxIndex++; 		
			if(M_UART_TxIndex < M_UART_TxLength)
			{
		   		_txr_rxr1= M_UART_TxFIFO[M_UART_TxIndex];	
			}
			else
				temp = _u1sr;		//read USR to clear error flag 	
		}	
//	}
	
	_ur1f =0; 	
}
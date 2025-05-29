#include "include.h"
#include "AP_STARTUP_OPTION.h"
//#include "BH67F2485.h"

//--- main
unsigned char 			M_Task,M_TaskBuf0,M_TaskBuf1,M_Error_Task;
unsigned char  			M_Halt_Cnt,M_ErrorCount;;
unsigned int			M_RTC_display;
volatile unsigned int   M_No_Active_Cnt,M_GM_data_Record,M_GM_Record_current,M_GM_SendRecord,M_GM_data_Record_buf;
signed int 				M_GM_data;
unsigned char			M_Unit;
unsigned char  			M_Cbuf0,M_Cbuf1;
unsigned int   			M_Ibuf0,M_Ibuf1,M_Ibuf2;
unsigned long  			M_Lbuf0;
unsigned char 			M_FlashPage;
unsigned int			M_WaitCount,M_LogCount,M_Log,M_LogCount_Switch;
unsigned char 			M_ACTurnOn,M_DCTurnOff,M_DCTurnOn;

//--- strip
unsigned char 			M_Strip_Type;

//--- key
unsigned int 			M_MKey_Hold_CNT,M_SKey_Hold_CNT;
unsigned int			M_MSKey_Hold_CNT;
unsigned char			M_Inc_Cnt,M_Hold_cnt;
unsigned char			M_KeyDebounce;

//--- int
volatile unsigned char 	M_Main_cnt,M_Main_Cal_Cnt,M_Main_Cal,M_Main_Cnt_6s;
//volatile unsigned int	M_Main_cnt_1s,M_Cal_Lirc_Cnt;

//--- daco
unsigned char			M_Daco1L,M_Daco1H,M_Daco2L,M_Daco2H;

//--- RTC
volatile unsigned char  M_Second_buf,M_DaysLimit;
volatile unsigned char	M_Second,M_Minutes,M_Hour,M_Days,M_Month,M_Year;

//--- system
unsigned int			M_GM_Range_Hi,M_GM_Range_Low;

//--- Beep
unsigned int 			M_Beep_Cnt;
unsigned char 			M_BeepMode;

//--- Uart
volatile unsigned char 	M_UARTRxTimeOut,M_UART_RxIndex,M_UART_TxLength,M_UART_TxIndex,M_Length,M_UartInsertCnt;
unsigned char 			M_UART_TxIndex_Old,M_UART_Tx_ErrorCnt;

//---Adc
volatile ADCSource_t 	SDKADCSourceData;

//--- Measurement
unsigned int  			M_Excitation_Voltage;
signed char				M_Excitation_Offset,M_OPA_Offset;
unsigned int 			M_Temperature,M_Current,M_CurrentX10,M_BackCurrent;//M_Temperature（温度值）     M_Current（电流值）
unsigned int			M_Avg_16bit_result;
unsigned int			M_TriggerCurrent_Adc ;
unsigned int			M_StripUsedCurrent_Adc ;
unsigned int			M_DropCurrent_Adc ;

//--- data avg
unsigned long 			M_7days_datasum,M_14days_datasum,M_28days_datasum,M_30days_datasum,M_60days_datasum,M_90days_datasum;
unsigned int 			M_7daysNumber,M_14daysNumber,M_28daysNumber,M_30daysNumber,M_60daysNumber,M_90daysNumber;
#ifdef G777G_TEST
unsigned int 			M_Current_use_log,M_Current_start_log,M_Current_full_log;

#endif

//--- Alarm
volatile unsigned char 	M_Alarm1_HR,M_Alarm1_MIN;
volatile unsigned char 	M_Alarm2_HR,M_Alarm2_MIN;
volatile unsigned char 	M_Alarm3_HR,M_Alarm3_MIN;
volatile unsigned char 	M_Alarm4_HR,M_Alarm4_MIN;

//--- Battery
unsigned int			M_BAT_Energy;

//--- sin
unsigned char 			M_SinFreq;
unsigned char			M_SinGain;

//---bootload
unsigned char 			ReceiveFlag,Command;

//--- AC
double 					M_Impedance,M_Theta;
double					M_ImpedanceBuf[2];
signed int 				M_HCT_ADCData[4];

//--- IAP
unsigned int 			M_PageAddress;
unsigned char			M_PageIndex;

unsigned char 			FlashTimeFlag;
unsigned char 			FlashTimeCon;

//--- calbration
//volatile unsigned int			M_Cal_Licr_ObjCnt,M_Cal_Hicr_ObjCnt;
//volatile signed char			M_Cal_Licr_ObjVaule,M_Cal_Hicr_ObjVaule;
unsigned int					M_Cal_10K_Adc,M_Cal_100K_Adc;	

//---Flag
bit_type Flag1;
bit_type Flag2;
bit_type Flag3;
bit_type Flag4;
bit_type Flag5;
bit_type Flag6;
bit_type Flag7;
bit_type Flag8;

//--- for Month day limit table
                                   // 1  2  3  4  5  6  7  8  9 10 11 12
const unsigned char Month_TABLE1[12]={31,28,31,30,31,30,31,31,30,31,30,31};
const unsigned char Month_TABLE2[12]={31,29,31,30,31,30,31,31,30,31,30,31};

//--- for Leap year table
const unsigned char LeapYear_TABLE[22]={12,16,20,24,28,32,36,40,44,48,52,56,60,64,68,72,76,80,84,88,92,96};




//--------------------------------------------------------------------------
void delay (volatile unsigned char n)       //1ms for base
{                   
    unsigned char i, j;

    while(n--)
    {
        for(i=0; i<10; i++)
            for(j=0; j<45; j++);
    } 
}
//--------------------------------------------------------------------------
void delay_ms (volatile unsigned int n)       //1ms for base
{                   
    volatile unsigned int i, j;

    while(n--)
    {
        for(i=0; i<2; i++)
            for(j=0; j<39; j++);
    } 
}

void keyinti(void)
{
 memkey=0;
 memkey_time=0;

 setkey =0;
 setkey_time =0;
 
 setkeydown =0;
 setkeydown_time =0;
}

unsigned char Is_strip_in_sleep_wakeup(void)// 0:strip out  1:strip int
{
		volatile unsigned int  con;
		volatile unsigned char result;

		con = 20;

		while(--con)
		{
			if((P_StripIn ==0)/* &&(P_UA_StripIn ==0)*/)
			{					
			}
			else
			break;
			delay(1);
		}
		if(con==0)
		result = 1;
		else
		result = 0;
		
		return result;
}

//--------------------------------------------------------------------------
__attribute__((at(AP_Main_Address)))  



//__attribute__((at(0X440)))
void main_AP(void)
{
//	//unsigned char buf[128];
//	unsigned char buf[6];
	volatile unsigned char  temp;
//	volatile unsigned int  mycount;
//	volatile unsigned char  strip_in_flag;

//			unsigned int test;
//	testf=0.1123456789;		

	//--- osc initial
	Initial_SysClock();
	//--- hirc stable check
	
//	while(!_lxtf)
//		GCC_CLRWDT();
	keyinti();	
	for(M_Cbuf0 =0; M_Cbuf0 <=150;M_Cbuf0++)
	{
		GCC_CLRWDT();
		delay(250);          //1ms for base
	}
	//UART_init();

	
	
	//--- mcu initial	
	Initial_Sys();
	//--- initnal system ram
	SystemRAM_clear();
	//--- clrar system ram
	LCD_Clear(OFF);
	
	LCD_Par_init();
	//--- lvd Enable
	_lvden =1;
	lcd_scan_index = 0;
	
//	for(M_Cbuf0 =0; M_Cbuf0 <=100;M_Cbuf0++)
//		delay(250);          //1ms for base
		
	while(_lvdo)
	{
		GCC_CLRWDT();
		//--Lcd turn on
		_lcden =1;

		//--- display col flash
		if(F_500ms_LCD)
		{
//			if(lcd.meas.Bit.Battery != 0)
//				LCD_BitSetOut( LcdBit_Meas_Battery, OFF) ;
//			else
//				LCD_BitSetOut( LcdBit_Meas_Battery, ON ) ;

			F_500ms_LCD =0;
		}
	}

	//--- system initial
	Load_System_Vaule();	
	//--- Vref & daco initial
//	Load_VrefDaco_Vaule();
//	//--- Calibration initial
//	Load_Calibration_Vaule();
	Load_VrefDaco_Vaule();//????????????	AD??????	
	Load_StripMeas_Vaule();	
	Load_RtcTime_Vaule();
//	//--- lvd Enable
//	_lvden =1;
	//--- Stm Enable
	_pt0on =1;
	//--- Tb0 Enable
	_tb0on =1;
	//--- Interrupt Enatble
	_emi =1;
	//--- Lcd Enatble
	_lcden =1;

	//---Main initnal
	//M_Task = C_StandByMode;
	//M_Task = C_OffMode;
	M_Task = C_PwrOnMode;
	if((P_M_KEY ==0) /*|| (P_S_KEY ==0)*/)
		M_Task = C_TestingMode;	

	F_Battery_checked = 0;
	F_Low_battery_Act=0;
	F_Set_Transmit = 0;
	F_Set_No_Tempera_Comp = 0;
	M_RTC_display =0;
	M_TaskBuf0 =0;
	M_TaskBuf1 =0;
	M_Log=0;
	M_No_Active_Cnt =0;
	
	//--- Date initnal
//	M_Second =1;
//	M_Minutes =0;
//	M_Hour =12;
//	M_Days =14;
//	M_Month =6;
//	M_Year =23;
//	
//	
	Read_EEPROMBuf(C_EEP_FactoryMode_Adr, (unsigned char*)&set_temp_25, 1);

	M_SinFreq =10;  //100 SINE WARE
	M_SinGain = 100;
	
	//--- opa initial
	fun_AFEPoweronInit();
	fun_CalOPAOffset();
	//--- set vg1
    SET_PIN_VG1_GND();

	M_BAT_Energy=32286;
	batlevel=3;


//	//============================
//	//--- IAP read flash test
//	for(temp =0; temp <= 63; temp++)
//		M_FlashBuf[temp] = Drv_ReadFlashRom(IAPWRSTARTADDRESS + temp);
//	//============================	
//	//--- IAP erase flash test
//	Drv_Erase_Page(IAPWRSTARTADDRESS,64);
//	//============================	
//	//--- IAP writer flash test
//	for(temp =0; temp <= 63; temp++)
//		M_FlashBuf[temp] = 0xaa00 + temp;
//	Drv_WriteFlashRom(IAPWRSTARTADDRESS,64);

//	fun_UART0PowerOnInit();
//
//
//#if defined(keruikang)
//#else
//	M_Unit=M_Unit | 0x01;//mmol	
//#endif
//	while(1)
//	{
//		GCC_CLRWDT();
//		
//		GCC_CLRWDT();
//	
//		if(F_MainTimerOut)
//		{
//			//	_pd6=~_pd6;//LED
//			
//			F_MainTimerOut =0;			
//
//    	//	print_unint(12345);	
//    		print_double(-0.01515);
//    		_emi=1;
//		}
//	}
#if (testmode ==1)
	// Fill_Test_Calibration_data();
#endif
//	Initial_SysGpio();



	while(1)
	{
		GCC_CLRWDT();
		
		GCC_CLRWDT();
		#if 1
		if(F_LcdUpdate && Start_Detection_flag)
		{
			LCD_ScanOut1();
			if(lcd_scan_index >= LcdMappingSize)
			{
				lcd_scan_index = 0;
				F_LcdUpdate = 0;
			}
		}
		#endif
		if(F_MainTimerOut)
		{
			//	_pd6=~_pd6;//LED
			
			F_MainTimerOut =0;
			
			//--- ScanKeyProcess
		//	ScanKeyProcess();
			ScanKey();
			//--- BeepProcess
			BeepProcess();
			//--- BatteryProcess
			if(M_Task==C_NormalMode && M_TaskBuf0 > e_ckfull_blood)
			{
			}
			else
			{
				BatteryCheckProcess();
			}
			//--- Lcd update
			if(F_LcdUpdate && Start_Detection_flag==0)
			{
				F_LcdUpdate =0;
				LCD_ScanOut();
			}
			if(twokey==2)
			{
				twokey = 0;
//				Show_BigString("TTT");
//				LCD_ScanOut();
//				delay_ms(500);
//				GCC_CLRWDT();
//				delay_ms(500);
//				set_temp_25 = 1;
				keyinti();	
			}
			switch(M_Task)
			{
	    		//============================
	    		//---- C_PwrOnMode Mode ----
				case C_PwrOnMode:
				{
					PwrOnMode();
//		    		if(M_TaskBuf0 >1)
//		    			Error_meassage_process();
					break;
				}
				
	    		//============================
	    		//---- C_StandByMode Mode ----
				case C_StandByMode:
				{

		    		if(F_KeyHold_IntoHalt ==0 )         //after measure strip do not release
		    		{
		    				    		    
	    		    	M_Strip_Type =0;
	    		    	if(blood_strips_pin4==0)
	    		    	{
	    		    		M_Strip_Type =glucose_Type ;//??????????
	    		    	}
	    		    	#if 0
	    		    	else if(_pa3==0)  //3.	??????
	    		    	{
	    		    		M_Strip_Type =code_Type;
	    		    	}
	    		    	else if(strips_pin6==1 && strips_pin7==0 && strips_pin8==1)//PIN6,PIN7,PIN8
	    		    	{
	    		    		M_Strip_Type =ketone_Type ;//???????
	    		    		
	    		    	}
	    		    	else if(strips_pin6==1 && strips_pin7==0 && strips_pin8==0)
	    		    	{
	    		    		M_Strip_Type =Urea_Type ;//??????	
	    		    	}
	    		    	else if(strips_pin6==0 && strips_pin7==0 && strips_pin8==1)
	    		    	{
	    		    		M_Strip_Type =Chol_Type ;//	????????
	    		    	}
	    		    	#endif
	    		    	if(M_Strip_Type)
	    		    	{
	    		    		if(M_Strip_Type==code_Type)
	    		    		{}
	    		    		else
	    		    		{
			    		    	M_Task = C_NormalMode;
	
			    		    		
					    	    M_TaskBuf0 =0;
					    	    M_TaskBuf1 =0;
					    	    M_RTC_display =0;
					    	    M_No_Active_Cnt=0;	    			
			    	            
			    	            //--- Dacvref Enable
			    	            if(C_LCD4V_Enable)		        
			        				fun_DACVREFInit(POWERON);
								//--- Lcd All off
								LCD_Clear(OFF);
								//--Lcd turn on
								_lcden =1;
	    		    		}	    		    		
	    		    		
	    		    	}
	    		    	
	    		    	
		    		
	    		        if(memkey==1 || memkey==2)
	    		        {
	    		        	//memkey=0;
	    		        	
//							M_MKey_Hold_CNT =0;
//							F_MKeyHoldCheck =1;
						   	//-- into C_MemoryMode
							M_Task = C_MemoryMode;
							M_TaskBuf0 = 0;
							M_TaskBuf1 =0;
							M_RTC_display =0;
							M_No_Active_Cnt=0;

		    	            //--- Dacvref Enable
		    	            if(C_LCD4V_Enable)		        
		        				fun_DACVREFInit(POWERON);
							//--- Lcd All off
							LCD_Clear(OFF);
							//--Lcd turn on
							_lcden =1;	    		        	
	    		        	
	    		        }
	    		        if(setkey==2)
	    		        {
	    		        	setkey=0;
	    		        	
//									M_SKey_Hold_CNT =0;
//									F_SKeyHoldCheck =1;
								   	//-- into C_MemoryMode
									M_Task = C_RTCModeSettingMode;
									M_TaskBuf0 = 0;
									M_TaskBuf1 =0;
									M_RTC_display =0;
									M_No_Active_Cnt=0;
									
									//F_StripInsert =0;
									
				    	            //--- Dacvref Enable
				    	            if(C_LCD4V_Enable)		        
				        				fun_DACVREFInit(POWERON);
									//--- Lcd All off
									LCD_Clear(OFF);
									//--Lcd turn on
									_lcden =1;	    		        	
	    		        }
					
					    //----------------------------------
					    //--- check F_L_KEY_TOGGLE 3sec ----
					    //--- into adjust MemoryMode

		    		}
		    		
		    		
					if(F_Alarm1_TimeUp_ACT || F_Alarm2_TimeUp_ACT || F_Alarm3_TimeUp_ACT|| 
						F_Alarm4_TimeUp_ACT)
		    		{
						//-- into C_AlarmMode
						M_Task = C_AlarmMode;
						M_TaskBuf0 = 0;
						M_TaskBuf1 =0;
						M_RTC_display =0;
						M_No_Active_Cnt=0;
						
						//F_StripInsert =0;
						
//	    	            //--- Beep ON
//	    	            F_Beep_Actx1_Long =1; 
						//--- Lcd All off
						LCD_Clear(OFF);
						//--Lcd turn on
						_lcden =1;
		    		}	
					
		    		if(P_BAT_CHRR ==0)
		    		{
						//-- into C_AlarmMode
						M_Task = C_ChargerMode;
						M_TaskBuf0 = 0;
						M_TaskBuf1 =0;
						M_RTC_display =0;
						M_No_Active_Cnt=0;
						
						//F_StripInsert =0;
						
//	    	            //--- Beep ON
//	    	            F_Beep_Actx1_Long =1; 
						//--- Lcd All off
						LCD_Clear(OFF);
						//--Lcd turn on
						_lcden =1;
		    		}	
					
					break;
				}
							
	    		//============================
	    		//--- Normal Measure Mode ----
				case C_NormalMode:
				{
					Normal_Measurement_Mode();
					//Ble_Process();
//		    		if(M_TaskBuf0 >1)
//		    			Error_meassage_process();
					break;
				}
				
//	    		//--- C_AVGMode  Mode     ----
//				case C_AVGMode:
//				{
//	    			Data_AVG_Mode();
////		   	    	if(M_Error_Task ==0)
////	    				Ble_Process();
//	    			if(M_TaskBuf0 >0)
//	    				Error_meassage_process();
//					break;
//				}
				
	    		//============================
	    		//--- C_MemoryMode  Mode     ----
				case C_MemoryMode:
				{
	    			MemoryMode();
//		   	    	if(M_Error_Task ==0)
//	    				Ble_Process();
	    			if(M_TaskBuf0 >1)
	    				Error_meassage_process();
	    				
    		    	if(blood_strips_pin4==0)
    		    	{
    		    		memkey = 0;
						setkey = 0;
    		    		M_Task = C_StandByMode;
    		    	}
					break;
				}
				
//	    		//============================
//	    		//--- C_MemoryMode  Mode     ----
//				case C_CodeCardMode:
//				{
//	    			CodeCardModeMode();
////		   	    	if(M_Error_Task ==0)
////	    				Ble_Process();
//	    			if(M_TaskBuf0 >1)
//	    				Error_meassage_process();
//					break;
//				}
				
				//=========================
	    		//--- RTC setting Mode ----
	    		case C_RTCModeSettingMode:
	    		{
		   	    	RTC_Mode_Setting_Process();
//		   	    	if(M_Error_Task ==0)	
//		   	    		Ble_Process();
		   	    	if(M_TaskBuf0 >0)	    			
		    			Error_meassage_process();
	    			
	    		break;  //RTC Mode Setting Mode END
	    		}
	    		
	    		//=========================
	    		//--- Alarm Mode ----
				case C_AlarmMode:
				{
					Alarm_Check_Process();
					break;
				}
				
	    		//=========================
	    		//--- Pc link Mode ----
				case C_PCLINKMode:
				{
//					PCLINKMode_Process();
					
		   	    	if(M_TaskBuf0 >0)	    			
		    			Error_meassage_process();
					break;
				}
	    			    		
	    		//=========================
	    		//--- Testing Mode ----
				case C_TestingMode:
				{
					TestingMode();
					
		   	    	if(M_TaskBuf0 >0)	    			
		    			Error_meassage_process();
					break;
				}
				
	    		//=========================
	    		//----- Charger Mode -----
				case C_ChargerMode:
				{
					ChargerProcess();
					break;
				}
				
	    		//=========================
	    		//----- Off mode Mode -----
				case C_OffMode:
				{
					OffMoedProcess();
					break;
				}
				
	    		//=========================
	    		//----- Other   -----
				default:
				{
			    	M_Task = C_OffMode;
				    M_TaskBuf0 =0;
				    M_TaskBuf1 =1;
				    M_Log =0;
				    M_RTC_display =0;
				    M_No_Active_Cnt=0;	    			
					//--- Lcd All off
					LCD_Clear(OFF);
					break;
				}
			}
			
			//====================================
			//--------- check into halt ----------
			M_Halt_Cnt++;
			
			if(M_Task != C_StandByMode)			//in measurement mode check
				M_Halt_Cnt =0;
				
			if((P_M_KEY ==0) || (P_S_KEY ==0) ||P_S_KEY_DOWN ==0)
			   M_Halt_Cnt =0;
			   
			_pac1 = 0; 			
			_pa1 =0;		   

			if(M_Halt_Cnt >=4)
			{
				M_Halt_Cnt =0;

				LCD_Clear(OFF);			//Lcd all off
				
				M_Error_Task=0;
				
				M_No_Active_Cnt = 0;    //reset counter

				Initial_HaltSys();
				fun_StripModuleAllOpen();
				SET_ADCPOWER(POWEROFF);
				SET_SINE_OFF();
				SET_VOREG_POWER(POWEROFF);
				
				//SET_PGA_BYPASS_WITHOUTBUF();
				SET_PGA_GAIN_1();
				
				SET_DACVREF_POWER(POWEROFF);
				SET_DACn_VOLTAGE(1, DACnODISABLE);
				SET_DACn_VOLTAGE(2, DACnODISABLE);
				
				SET_PIN_OPnP_OPEN(1);
				SET_PIN_OPnP_OPEN(2);
				
				SET_OPAn_POWER(1,POWEROFF);
				SET_OPAn_POWER(2,POWEROFF);
				SET_OPA34_POWER(POWEROFF);
				
				SET_PIN_VG1_GND();
				SET_PIN_VG0_GND();
				//??????????????
				up_pin4 =1;//?????????		
				strips_pin4_dir = 1;  
#if 0				
				strips_pin7_dir=1;//in--strips pin7
				up_pin7=0;
				strips_pin7=0;		
		
									
				strips_pin8_dir=1;//in--strips pin8
				up_pin8=0;
				strips_pin8=0;
				
#endif	

				//??6?(???)??????
			
				//GD777
				strips_pin6_dir=1;//in--strips pin6---STDBY/VCC
				up_pin6=1;
				_pac1 = 1; 			
				_papu1 =0;			

				#ifdef G35 	
				//G36
				_pac1 = 1; 			
				_papu1 =1;//--strips pin6--G36????!!		
 	
	            #endif 	
	            
				_pac1 = 0;
				_pa1 = 0;
				
				_pcc3=0;//???????????,???????!
				_pcpu3 =0;//
				_pc3=1;
								
//				_pac3=0;
//				_pa3=0;			
				
//				strips_pin4_dir=0;
//				blood_strips_pin4=0;					
				
//				_pgac0 =0;
//				_pgac1 =0;
//				_pgacs =0;
				//--- Lcd disable
				_uarten1 =0;
				//--- Lcd disable
				_lcden =0;
				//--- ptm disable
				_pt0on =0;
//				//--- wtd disable
//				_wdtc = 0b10101101;
				//--- Interrupt Enatble
				_emi =1;
				
				
				_fhiden =0;				//High frequency oscillator control disable
				_fsiden =1;          	//Low frequency oscillator control enable
				
				temp =1;
				LED=0;
				
				
//			fun_UART0PowerOnInit();	
//			SET_UARTn_WAKEUP_ENABLE(0);
				
			if((P_M_KEY ==0) || (P_S_KEY ==0) || (P_StripIn ==0) || (P_UA_StripIn ==0))
            	F_KeyHold_IntoHalt =1;    //strip do not release				
				
				//--- into system halt
				while(temp)
				{
					GCC_CLRWDT();
					_fhiden =0;				//High frequency oscillator control disable
					_fsiden =1;          	//Low frequency oscillator control enable
					
					GCC_HALT();	
//					_fhiden =1;				//High frequency oscillator control disable
//					_fsiden =1;
					//_pd6=~_pd6;//LED				
					
					//Save_RtcTime();
					//-- check I/O
					if(F_KeyHold_IntoHalt ==0)
					{
						//--- key or strip insert wakeup
						//--- detect	
						if((P_StripIn ==0)/* || (P_UA_StripIn ==0)*/)
							temp = 0;
						if((P_M_KEY ==0) || (P_S_KEY ==0))
							temp = 0;
//						if(P_UartInsert ==0)
//							temp = 0;
							
					}
					
					//--- check ALARM mode if Enable??
					if(F_Alarm1_TimeUp_ACT || F_Alarm2_TimeUp_ACT || F_Alarm3_TimeUp_ACT|| 
						F_Alarm4_TimeUp_ACT)	
						temp = 0;
					
										
					//-- strip release
					if((P_M_KEY) && (P_S_KEY) && (P_StripIn) && (P_UA_StripIn))
					
				//	if((P_M_KEY) && (P_S_KEY)/* && (P_StripIn) && (P_UA_StripIn)*/)
					{
		            	F_KeyHold_IntoHalt =0;    //strip do not release
//		            	F_SKeyHoldCheck =0;
					}
					if(_pc0==0)//??
					  	temp = 0;
					
					
					if(temp ==0)	//system wake up go to main loop
					{	
						
						_fhiden =1;			//High frequency oscillator control enable
						_fsiden =1;          	//Low frequency oscillator control enable
						#if (ACFG_OSC_EN == 0)								
						//--- osc initial
						Initial_SysClock();
						
						//--- hirc stable check
						while(!_hircf)
							GCC_CLRWDT();
						#endif	
						//--- mcu initial
						Initial_Sys();
						
//						//--- uart initial
//						fun_UART1PowerOnInit();
//						
						//--- opa initial
						fun_AFEPoweronInit();
//						
//						fun_StripModuleAllOpen();
//						SET_ADCPOWER(POWEROFF);
//						SET_SINE_OFF();
//						SET_VOREG_POWER(POWEROFF);
//						
//						SET_DACVREF_POWER(POWEROFF);
//						SET_DACn_VOLTAGE(1, DACnODISABLE);
//						SET_DACn_VOLTAGE(2, DACnODISABLE);
//						
//						SET_OPAn_POWER(1,POWEROFF);
//						SET_OPAn_POWER(2,POWEROFF);
//						SET_OPA34_POWER(POWEROFF);
//						
//						//--- lvd Enable
//						_lvden =1;
						//--- ptm Enable
						_pt0on =1;
//						//--- Tb0 Enable
//						_tb0on =1;
						//--- Interrupt Enatble
						_emi =1;
						
//						//--- Lcd Enatble
//						_lcden =1;
////						Lcd_AllOn();
//						F_Battery_checked = 0;
//						Battery_Check_Process();
//						while(1)
//							GCC_CLRWDT();


						F_Battery_checked = 0;
						F_Low_battery_Act=0;
						M_RTC_display =0;
						M_TaskBuf0 =0;
						M_TaskBuf1 =0;
						M_Log =0;
						F_BatFull =0;
						M_No_Active_Cnt =0;
						 memkey=0;
						 setkey =0;		
						 twokey = 0;
						
					}
				}
			}		
		}
	}

}

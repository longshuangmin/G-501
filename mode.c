#include "include.h"

//--------------------------------------------------------------------------
void PwrOnMode (void)
{
	//unsigned int 	Ibuf0;
	//unsigned char 	Cbuf0;
	static unsigned char 	distime=80;
			M_RTC_display++;
			
			if(M_RTC_display ==1)
			{
				//--- display H/W Ver
			//	ShowDec_BigNum(C_FwVersion / 100);
				
				lcd.BigNum[0] = charTab['U'] ;	
				lcd.BigNum[1] = HexTab[bl_Version/100/10] ;	  			
	  			lcd.BigNum[2] = HexTab[bl_Version/100%10] ;				
				
		
				distime=80;
				lcd.meas.Bit.BigNum_DP =1;
				
				F_LcdUpdate =1;
			}
			if(memkey || setkey)
			{
				memkey=0;
				setkey=0;
				distime=200;
				lcd.min[0] = HexTab[bl_Version%100/10] ;	  			
				lcd.min[1] = HexTab[bl_Version%100%10] ;
				F_LcdUpdate =1;
			}
			if(M_RTC_display >=distime)
			{
				//--- into setting task
					M_Task = C_OffMode;
					M_TaskBuf0 =0;			
					M_TaskBuf1 =0;
				    M_Error_Task =0;
				    M_RTC_display = 0;
					M_No_Active_Cnt = 0;
		     	//--- Lcd All off
		     	//LCD_Clear(OFF);
			}
}

//--------------------------------------------------------------------------
void OffMoedProcess (void)
{
	switch (M_TaskBuf0)
	{
		case 0:
		{
			if(P_BAT_CHRR ==0)
			{
				M_RTC_display =0;
				M_TaskBuf0 =1;
				M_TaskBuf1 =0;
				break;
			}

			//--- Lcd All off
		    LCD_Clear(OFF);

			M_RTC_display =0;
	     	M_TaskBuf0 =1;
	     	M_TaskBuf1 =0;
	     	//M_MealMode =0;
	     	M_Error_Task =0;
	     	M_No_Active_Cnt =0;
	     	//--- display off
	     	Show_BigString( "OFF" ) ;
			//Lcd_Display_OFF();
			
			F_LcdUpdate =1;
			
			
			
			if((P_M_KEY ==0) || (P_S_KEY ==0) || (P_S_KEY_DOWN ==0) || (P_StripIn ==0) || (P_UA_StripIn ==0))
            	F_KeyHold_IntoHalt =1;    //strip do not release
            	
			break;
		}
		
		case 1:
		{
			M_RTC_display++;
					
			if(M_RTC_display >=50)
			{
				M_RTC_display =0;
				M_Task = C_StandByMode;
				keyinti();
		     	M_TaskBuf0 =0;
		     	M_TaskBuf1 =0;
		     	//M_MealMode =0;
		     	M_Error_Task =0;
		     	M_No_Active_Cnt =0;
		     	//--- Clear LCD RAM
		     	LCD_Clear(OFF);
				_lcden =0;

			}
				
			
			break;
		}
		
	  	default:
	  	{
			M_RTC_display++;
			if(M_RTC_display >=8)
			{
			    M_RTC_display = 0;
				M_No_Active_Cnt = 0;
				M_Task = C_OffMode;
				M_TaskBuf0 =0;			
				M_TaskBuf1 =0;
			    //F_Beep_Shortx1 =1;
			    M_Error_Task =0;
			    //--- Lcd All off
			    LCD_Clear(OFF);
			}
			break;
	  	}
	}
	
}
//ÄÖÁå´¦Àí³ÌÐò
//--------------------------------------------------------------------------
void Alarm_Check_Process(void)
{
	switch(M_TaskBuf0)
	{
		case 0:
		{
			M_RTC_display ++;
			
			if(M_RTC_display >=10)
			{			
			    M_RTC_display = 0;
			    M_TaskBuf0 =1;
			    M_TaskBuf1 =0;
			    M_Error_Task =0;
				F_Beep_Alarm =1;
			    M_Ibuf1 = 0;
				M_Ibuf2 = 0;
				//--- Lcd All off
				LCD_Clear(OFF);	
			}					
			break;
		}
		
		case 1:
		{
			//--- display date & time
			if(F_LcdUpdateBuf ==0)
			{
				//--- display Month & Day
				//Lcd_Month_Day_Process(M_Month,M_Days);
				//--- display Hour & Minutes
				//Lcd_Clock_Process(M_Hour,M_Minutes);

				F_LcdUpdateBuf =1;
				F_LcdUpdate =1;
			}			
			
			M_RTC_display++;
			if(M_RTC_display ==1)
			{
				//--- display "ALn"
				lcd.alarm.Bit.Alarm = 1;
				lcd.strip.Bit.StripBase = 1;
				if(F_Alarm1_TimeUp_ACT)	  
					lcd.alarm.Bit.Alarm_seg1 = 1;
					//Show_BigString( "AL1" ) ;

				else if(F_Alarm2_TimeUp_ACT)
					lcd.alarm.Bit.Alarm_seg2 = 1;
					//Show_BigString( "AL2" ) ;

				else if(F_Alarm3_TimeUp_ACT)
					lcd.alarm.Bit.Alarm_seg3 = 1;
					//Show_BigString( "AL3" ) ;

				else if(F_Alarm4_TimeUp_ACT)
					lcd.alarm.Bit.Alarm_seg4 = 1;

					//Show_BigString( "AL4" ) ;
					//M_Ibuf1++;
					//if(M_Ibuf1%2 == 0)
					{
						lcd.unit.Bit.TimeColon = 1;
						Lcd_Clock_Process(M_Hour,M_Minutes);
					}
					F_LcdUpdate =1;
			}
			else if(M_RTC_display ==50)
			{
				//Show_BigString( "   " ) ;
				
				lcd.alarm.Bit.Alarm = 0;
				lcd.strip.Bit.StripBase = 0;
				F_LcdUpdate =1;
				//M_Ibuf2++;
				//if(M_Ibuf2%2 == 0)
				{
					lcd.unit.Bit.TimeColon = 0;
					lcd.unit.Bit.AM = 0;
					lcd.unit.Bit.PM = 0;
					Lcd_Month_Day_Process(M_Month,M_Days);
				}
			}
			else if(M_RTC_display >=100)
				M_RTC_display =0;
			
			
			//--- display col flash
			//if(F_500ms_LCD)
			//{
			//	if(lcd.unit.Bit.TimeColon != 0)
			//		LCD_BitSetOut( LcdBit_Unit_TimeColon, OFF) ;
			//	else
			//		LCD_BitSetOut( LcdBit_Unit_TimeColon, ON ) ;
			//		
			//	F_500ms_LCD =0;
			//}
			
			//--- M + S_key Fucntion
			if((setkey) || (memkey) || (blood_strips_pin4==0))
			{
				memkey=0;
				setkey=0;		
				M_TaskBuf0 =9;
				M_TaskBuf1 = 0;
			    M_RTC_display = 0;
			    
				//--- Lcd All off
				LCD_Clear(OFF);	
			}
			
//			//--- check strip insert	
//	    	if(blood_strips_pin4==0)
//	    	{
//	    		//--- Strip check
//				M_Strip_Type =1;
//	    		M_Task = C_NormalMode;
//		    		
//	    	    M_TaskBuf1 =0;
//	    	    M_RTC_display =0;
//	    	    M_No_Active_Cnt=0;	    			
//	            
//				//--- Lcd All off
//				LCD_Clear(OFF);
//	    	}
			
			break;
		}
		
	  	//---------------------------------
      	//--- Quit Data Avg mode  ----
      	case 9:
	  	{
			//-- quit Data_AVG_Mode
			if(F_Alarm1_TimeUp_ACT)
				F_Alarm1_TimeUp_ACT =0;				
			if(F_Alarm2_TimeUp_ACT)
				F_Alarm2_TimeUp_ACT =0;
			if(F_Alarm3_TimeUp_ACT)
				F_Alarm3_TimeUp_ACT =0;
			if(F_Alarm4_TimeUp_ACT)
				F_Alarm4_TimeUp_ACT =0;			
			
			if(P_M_KEY ==0 || P_S_KEY ==0 || P_S_KEY_DOWN ==0)
			{
				F_KeyHold_IntoHalt =1;

			}
			if(blood_strips_pin4 ==0)
			{
				//--- Strip check
				M_Strip_Type =1;
	    		M_Task = C_NormalMode;
			}
			else
			{
				M_Task = C_OffMode;
			}				
		
			M_TaskBuf0 =0;
			M_TaskBuf1 =0;
			M_Error_Task =0;
			M_RTC_display =0;
			M_No_Active_Cnt = 0;
			
			//--- Lcd All off
			LCD_Clear(OFF);
			
			//--- beep off
			F_Beep_Alarm =0;        //enable beep
			M_Beep_Cnt =0;	

	  		break;
	  	}
	  	
	  	default:
	  	{
			M_Task = C_OffMode;
			M_TaskBuf0 =0;
			M_TaskBuf1 =0;
			M_Error_Task =0;
			M_RTC_display =0;
			M_No_Active_Cnt = 0;
			
			//--- Lcd All off
			LCD_Clear(OFF);
			
			//--- beep off
			F_Beep_Alarm =0;        //enable beep
			M_Beep_Cnt =0;
			
			break;		  
	  	}
	  	
	}
			
	//-------- counting time out 60sec Process  -------------
	M_No_Active_Cnt++;
	if(M_No_Active_Cnt >= 6000)//base time 10ms =>60 sec
	{
		M_No_Active_Cnt = 0;
		M_TaskBuf0 =9;
	}

}

//--------------------------------------------------------------------------
void ChargerProcess(void)
{
	if(P_BAT_CHRR ==0)
	{
//		if(_pa1==1)
//		{
//			//Charg finish
//			M_Task = C_OffMode;
//			M_TaskBuf0 =0;
//			M_TaskBuf1 =0;
//			M_Error_Task =0;
//			M_RTC_display =0;
//			M_No_Active_Cnt = 0;
//			
//			//--- Lcd All off
//			LCD_Clear(OFF);
//			
//			//--- beep off
//			F_Beep_Alarm =0;        //enable beep
//			M_Beep_Cnt =0;
//			
//			//---  set  Battery full
//			F_BatFull =1;
//		}
//		else
		{
			//Charging
			M_RTC_display++;
			if(M_RTC_display ==1)
			{
				Lcd_Bat(0);
				F_LcdUpdate =1;
			}
			else if(M_RTC_display ==50)
			{
				Lcd_Bat(1);
				F_LcdUpdate =1;
			}
			else if(M_RTC_display ==100)
			{
				Lcd_Bat(2);
				F_LcdUpdate =1;
			}
			else if(M_RTC_display ==150)
			{
				Lcd_Bat(3);
				F_LcdUpdate =1;
			}
			else if(M_RTC_display ==200)
				M_RTC_display =0;
		}
		
	}
	else
	{
		//--- remover usb cable
		M_Task = C_OffMode;
		M_TaskBuf0 =0;
		M_TaskBuf1 =0;
		M_Error_Task =0;
		M_RTC_display =0;
		M_No_Active_Cnt = 0;
		
		//--- Lcd All off
		LCD_Clear(OFF);
		
		//--- beep off
		F_Beep_Alarm =0;        //enable beep
		M_Beep_Cnt =0;
	}
}

//--------------------------------------------------------------------------

//--------------------------------------------------------------------------


//--------------------------------------------------------------------------


//--------------------------------------------------------------------------


//--------------------------------------------------------------------------

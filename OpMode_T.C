#include "include.h"

#include <string.h>

void RTC_Mode_Setting_Process (void)
{
	//unsigned char buf[4];
	unsigned char Cbuf0,Cbuf1,Cbuf2;	
	//long press memory key goto off
	if(memkey==2)
	{
		memkey = 0;
		M_TaskBuf0 = C_Set_out;
	}
	
//	--- check strip insert	
	if(blood_strips_pin4==0)
	{
		//--- Strip check
		M_Strip_Type =1;
		M_Task = C_NormalMode;
		M_TaskBuf0=0;	
		M_TaskBuf1 =0;
		M_RTC_display =0;
		M_No_Active_Cnt=0;					
		
		//--- Lcd All off
		LCD_Clear(OFF);
		return;
	}

	
	switch (M_TaskBuf0)
	{
		case C_Set_the_DisplayAllOn:
		{
			imp = 0;
			M_RTC_display++;
			if(M_RTC_display ==1)
	      		//---Lcd All on
	      		LCD_Clear(ON);
				
			else if(M_RTC_display >=100)
			{
				if(F_Low_battery_Act)
					M_Error_Task = 6;
				
				if(M_Error_Task == 0)
				{
					//--- into setting task
					M_RTC_display =0;
			     	M_TaskBuf0 =C_Set_the_Year;
			     	M_TaskBuf1 =0;
			     	M_No_Active_Cnt =0;
			     	
					//--- move data
					M_Cbuf0  = M_Year;
			     	
		      		//---Lcd All off
		      		LCD_Clear(OFF);
		      		
		      		//---lcd update flag clear
					F_LcdUpdateBuf =0;
					F_LcdUpdate =0;
					F_Beep_Shortx1 =1;
				}
				else
				{
					//--- into error task
					//M_Error_Task = 6;
					M_RTC_display =0;
			     	M_TaskBuf0 = C_Set_the_Error;
			     	M_TaskBuf1 =0;
			     	//M_MealMode =0;
			     	M_No_Active_Cnt =0;
			     	//--- Lcd All off
			     	LCD_Clear(OFF);
			     	
	      			//--- lcd update clear flag
					F_LcdUpdateBuf =0;
					F_LcdUpdate =0;
				}
			}

			break;
		}
		
	    //===================================
    	//--- Adjustment Year --------------
	    //--- C_Set_the_Year
		case C_Set_the_Year:
		{
	        //--- Display all time & flash
		    M_RTC_display++;
			
		    if(M_RTC_display ==1)						//base 31.25ms
		    {
		    	//--- display year
				//Lcd_Year_Process(M_Cbuf0);
				ShowDec_BigNum(M_Cbuf0);
				
	      	    //--- display date & time
				Lcd_Month_Day_Process(M_Month,M_Days);
				//Lcd_Clock_Process(M_Hour,M_Minutes);
				//lcd.unit.Bit.TimeColon =1;
				//--- display unit
				//Lcd_Unit(); 
				
				F_LcdUpdate =1;				              
		    }
			else if(M_RTC_display ==50)
			{
				//Clr_MonthString();
				Clr_BigString();
				//Clr_DayString();
				F_LcdUpdate =1;	
			}	
			else if(M_RTC_display >=100)
      	        M_RTC_display =0;
      	        
      	    if(setkey)
      	    {
      	       setkey=0;
        		M_RTC_display = 0;					//for press hold display
        		M_No_Active_Cnt =0;     	       	
				//--- check YEAR over 2050
				M_Cbuf0++;
				if(M_Cbuf0 > 50)
					M_Cbuf0 = 23;               //return to default 2021   
				F_Beep_Shortx1 =1;	    	    	
      	    }
			else  if(setkeydown)
      	    {
      	       setkeydown=0;
        		M_RTC_display = 0;					//for press hold display
        		M_No_Active_Cnt =0;     	       	
				//--- check YEAR over 2050
				if(M_Cbuf0>23)
				M_Cbuf0--;
				else
				M_Cbuf0 = 50;            //return to default 2021   
				F_Beep_Shortx1 =1;	    	    	
      	    }    
      	        

	        
	    	//---------------------------------
			//--- check F_S_KEY_TOGGLE ---
			//--- into Month mode	    		
	    	if(memkey==1)
	    	{
	    		memkey=0;
	    		M_RTC_display =0;
				M_No_Active_Cnt = 0;
				//--- Next task
				M_TaskBuf0 = C_Set_the_Month;	
				M_TaskBuf1 = 0;
				//--- move data
				M_Year = M_Cbuf0;
				M_Cbuf0 = M_Month;	
				M_Error_Task =0;
				F_Beep_Shortx1 =1;			    
	    	}
	       	//--- check Month over limit
			//--- read days limit
			Cbuf2 = Month_TABLE1[M_Month-1];
				  	
			//--- check leap year in February
			//--- M_Cbuf0 = M_Year
			if(M_Month == 2)
			{
				//--- leap year check
				for(Cbuf0=0; Cbuf0<=22; Cbuf0++)
				{
			  	    Cbuf1 = LeapYear_TABLE[Cbuf0];
			  	    if(Cbuf1 == M_Cbuf0)
			  	    {
			        	Cbuf2++;
					    if(M_Days >Cbuf2)
					    	M_Days = Cbuf2;
			  	    }
			        if(Cbuf1 > M_Cbuf0)
			        {
			        	Cbuf0 = 100;                     	//quit for loop
						if(M_Days >Cbuf2)
							M_Days = Cbuf2;
			        }	
		        }
		    }
			else
			{
				if(M_Days >Cbuf2)
					M_Days = Cbuf2;		
			}		        

			break;
		}		
	    //===================================
    	//--- Adjustment Month --------------
	    //--- C_Set_the_Month
	    case C_Set_the_Month:
	    {
	        //--- Display all time & flash
		    M_RTC_display++;
			
		    if(M_RTC_display ==1)							//time base 10ms
		    {
		    	//--- display year
				//Lcd_Year_Process(M_Year);
				ShowDec_BigNum(M_Year);
	      	    //--- display date & Month
				Lcd_Month_Day_Process(M_Cbuf0,M_Days);
				//Lcd_Clock_Process(M_Hour,M_Minutes);
				//lcd.unit.Bit.DateSlash =1;
				//--- display unit
				//Lcd_Unit(); 
				
				F_LcdUpdate =1;					              
		    }
			else if(M_RTC_display ==50)
			{
				Clr_MonthString();
				//Clr_DayString();
				F_LcdUpdate =1;	
			}	
			else if(M_RTC_display >=100)
      	        M_RTC_display =0;
      	        
	    	
	    	//---------------------------------
			//--- check F_S_KEY_TOGGLE ---
			//--- into adjust Year Vaule	    		
			//Seting Month	
			
      	    if(setkey)
      	    {
      	        setkey=0;
        		M_RTC_display = 0;					//for press hold display
        		M_No_Active_Cnt =0;     	       	
			    //--- check M_Month over 12
			    M_Cbuf0++;
			    if(M_Cbuf0 > 12)
			    	M_Cbuf0 = 1;
				F_Beep_Shortx1 =1;    	    	    	
      	    }   			
			else if(setkeydown)
      	    {
      	        setkeydown=0;
        		M_RTC_display = 0;					//for press hold display
        		M_No_Active_Cnt =0;     	       	
			    //--- check M_Month over 1
			    if(M_Cbuf0 > 1)
			    M_Cbuf0--;
			    else 
				M_Cbuf0 = 12;
				F_Beep_Shortx1 =1;    	    	    	
      	    }

	 	       	//--- check Month over limit
			//--- read days limit
			Cbuf2 = Month_TABLE1[M_Cbuf0-1];
				  	
			//--- check leap year in February
			//--- M_Cbuf0 = M_Month
			if(M_Cbuf0 == 2)
			{
				//--- leap year check
				for(Cbuf0=0; Cbuf0<=22; Cbuf0++)
				{
			  	    Cbuf1 = LeapYear_TABLE[Cbuf0];
			  	    if(Cbuf1 == M_Year)
			  	    {
			        	Cbuf2++;
					    if(M_Days >Cbuf2)
					    	M_Days = Cbuf2;
			  	    }
			        if(Cbuf1 > M_Year)
			        {
			        	Cbuf0 = 100;                       	//quit for loop
						if(M_Days >Cbuf2)
							M_Days = Cbuf2;
			        }
		        }
		    }
			else
			{
				if(M_Days >Cbuf2)
					M_Days = Cbuf2;		
			}	       
	    	//---------------------------------
			//--- check F_S_KEY_TOGGLE ---
			//--- into dat mode	    		
	    	if(memkey==1)
	    	{
	    		memkey=0;
			    M_RTC_display = 0;
				M_No_Active_Cnt = 0;
				//--- Next task
				M_TaskBuf0 = C_Set_the_Day;	
				M_TaskBuf1 = 0;	
				M_Error_Task =0;
				
				//--- move data
				M_Month = M_Cbuf0;
				M_Cbuf0 = M_Days;
				
		       	//--- check Month over limit
				//--- read days limit
				M_Cbuf1 = Month_TABLE1[M_Month-1];
					  	
				//--- check leap year in February
				if(M_Month == 2)
				{
					//--- leap year check
					for(Cbuf0=0; Cbuf0<=22; Cbuf0++)
					{
				  	    Cbuf1 = LeapYear_TABLE[Cbuf0];
				  	    if(Cbuf1 == M_Year)
				        	M_Cbuf1++;
				        else if(Cbuf1 > M_Year)
				        	break;

			        }
			    }
			    F_Beep_Shortx1 =1;			    
	    	}
	    	        	        

	    	break;
	    }
	    	    	    
	    //===================================
    	//--- Adjustment DAYs --------------
	    //--- C_Set_the_Day
	    case C_Set_the_Day:
	    {
	        //--- Display all time & flash
		    M_RTC_display++;
			
		    if(M_RTC_display ==1)							//time base 10ms
		    {
		    	//--- display year
				//Lcd_Year_Process(M_Cbuf0);
	      	    //--- display date & time
				Lcd_Month_Day_Process(M_Month,M_Cbuf0);
				//Lcd_Clock_Process(M_Hour,M_Minutes);
				//lcd.unit.Bit.TimeColon =1;
				//--- display unit
				//Lcd_Unit(); 
				
				F_LcdUpdate =1;					              
		    }
			else if(M_RTC_display ==50)
			{
				//Clr_MonthString();
				Clr_DayString();
				F_LcdUpdate =1;	
			}	
			else if(M_RTC_display >=100)
      	        M_RTC_display =0;

	    	//---------------------------------
			//--- check F_S_KEY_TOGGLE ---
			//--- into adjust Year Vaule	    		
			//Seting day
			
      	    if(setkey)
      	    {
      	        setkey=0;
        		M_RTC_display = 0;					//for press hold display
        		M_No_Active_Cnt =0;     	       	
			    //--- check M_Days over M_Cbuf0
	            M_Cbuf0++;
			    if(M_Cbuf0 >M_Cbuf1)
			    	M_Cbuf0 = 1; 
				F_Beep_Shortx1 =1;	    		    	
      	    }  
			else  if(setkeydown)
      	    {
      	        setkeydown=0;
        		M_RTC_display = 0;					//for press hold display
        		M_No_Active_Cnt =0;     	       	
			    //--- check M_Days over 1
			    if(M_Cbuf0>1)
	            M_Cbuf0--;
			    else
			    M_Cbuf0 = M_Cbuf1; 
				F_Beep_Shortx1 =1;	    		    	
      	    }  			
			
			

	        
	    	//---------------------------------
			//--- check F_S_KEY_TOGGLE ---
			//--- into hour mode	    		
	    	if(memkey==1)
	    	{
	    		memkey=0;
			    M_RTC_display = 0;
				M_No_Active_Cnt = 0;
				Show_BigString("   ");
				//--- Next task
				M_TaskBuf0 =C_Set_the_Hour;
				M_TaskBuf1 =0;	
				M_Error_Task =0;
				//--- move data
				M_Days = M_Cbuf0;
				M_Cbuf0 = M_Hour;
				F_Beep_Shortx1 =1;		    
	    	}	        

	    	break;
	    }
	    	    		
	    //===================================
	  	//--- Adjustment  Hour --------------
	    //--- C_Set_the_Hour
	    case C_Set_the_Hour:
	    {
	        //--- Display all time & flash
		    M_RTC_display++;
			
		    if(M_RTC_display ==1)							//time base 10ms
		    {
		    	//--- display year
				//Lcd_Year_Process(M_Cbuf0);
	      	    //--- display date & time
				//Lcd_Month_Day_Process(M_Month,M_Days);
				Lcd_Clock_Process(M_Cbuf0,M_Minutes);
				lcd.unit.Bit.TimeColon =1;
				//--- display unit
				//Lcd_Unit(); 
				
				F_LcdUpdate =1;					              
		    }
			else if(M_RTC_display ==50)
			{
				Clr_HourString();
				//Clr_MinString();
				F_LcdUpdate =1;	
			}	
			else if(M_RTC_display >=100)
      	        M_RTC_display =0;

	    	//---------------------------------
			//--- check F_S_KEY_TOGGLE ---
			//--- into adjust Year Vaule	    		
			//Seting Hour
      	    if(setkey)
      	    {
      	        setkey=0;
        		M_RTC_display = 0;					//for press hold display
        		M_No_Active_Cnt =0;     	       	
	            //--- check M_Hour over 24
	            M_Cbuf0++;
				if(M_Cbuf0 > 23)
					M_Cbuf0 =0; 
				F_Beep_Shortx1 =1;			 	    	
      	    }   
			else  if(setkeydown)
      	    {
      	        setkeydown=0;
        		M_RTC_display = 0;					//for press hold display
        		M_No_Active_Cnt =0;     	       	
	            //--- check M_Hour over 24
	            if(M_Cbuf0 > 0)
	            M_Cbuf0--;
				else
				M_Cbuf0 =23; 
				F_Beep_Shortx1 =1;			 	    	
      	    } 			
						
			

	    	//---------------------------------
			//--- check F_S_KEY_TOGGLE ---
			//--- into adjust Year Vaule	    		
	    	if(memkey==1)
	    	{
	    		memkey=0;
			    M_RTC_display = 0;
				M_No_Active_Cnt = 0;
				//--- Next task
				M_TaskBuf0 = C_Set_the_Minute;	
				M_TaskBuf1 = 0;
				M_Error_Task =0;
				
				//--- move data
				M_Hour = M_Cbuf0;
				M_Cbuf0 = M_Minutes;
				F_Beep_Shortx1 =1;
	    	}
			break;
	    }
	    
		//===================================
	  	//--- Adjustment  Minute ------------
	    //--- C_Set_the_Minute
	    case C_Set_the_Minute:
		{
	        //--- Display all time & flash
		    M_RTC_display++;
			
		    if(M_RTC_display ==1)							//time base 10ms
		    {
		    	//--- display year
				//Lcd_Year_Process(M_Cbuf0);
	      	    //--- display date & time
				//Lcd_Month_Day_Process(M_Month,M_Days);
				Lcd_Clock_Process(M_Hour,M_Cbuf0);
				lcd.unit.Bit.TimeColon =1;
				//--- display unit
				//Lcd_Unit(); 
				
				F_LcdUpdate =1;					              
		    }
			else if(M_RTC_display ==50)
			{
				//Clr_HourString();
				Clr_MinString();
				F_LcdUpdate =1;	
			}	
			else if(M_RTC_display >=100)
      	        M_RTC_display =0;

	    	//---------------------------------
			//--- check F_S_KEY_TOGGLE ---
			//--- into adjust Year Vaule	    		
			//Seting M_Minutes
			
      	    if(setkey)
      	    {
      	       setkey=0;
        		M_RTC_display = 0;					//for press hold display
        		M_No_Active_Cnt =0;     	       	
    		    //--- check M_Minutes over 60
    		    M_Cbuf0++;
				if(M_Cbuf0 > 59)
					M_Cbuf0 =0;	   
				F_Beep_Shortx1 =1;			 	
      	    } 
			else  if(setkeydown)
      	    {
      	       setkeydown=0;
        		M_RTC_display = 0;					//for press hold display
        		M_No_Active_Cnt =0;     	       	
    		    //--- check M_Minutes over 0
    		    if(M_Cbuf0 > 0)
    		    M_Cbuf0--;
				else
				M_Cbuf0 =59;	   
				F_Beep_Shortx1 =1;			 	
      	    }			
			

	        
	    	//---------------------------------
			//--- check F_S_KEY_TOGGLE ---
			//--- into adjust Year Vaule	    		
	    	if(memkey==1)
	    	{
	    		memkey=0;
			    M_RTC_display = 0;
				M_No_Active_Cnt = 0;
				//--- Next task
				//M_TaskBuf0 = C_Set_the_Unit;
				M_TaskBuf0 = C_Set_the_DeleteMemory;
				M_TaskBuf1 =0;
				M_Error_Task =0;
				
				LCD_Clear(OFF);
				//--- move data
				M_Minutes = M_Cbuf0;
				M_Second =0;
				//M_Cbuf0 = M_Unit;
				F_Beep_Shortx1 =1;
	    	}

	    	break;
		}
		
		//===================================
	  	//--- Adjustment  Unit ------------
	    //--- C_Set_the_Unit
	    //--- 0x00 fix mgdl;
	    //--- 0x01 fix mmol;
	    //--- 0x02 change mgdl;
	    //--- 0x03 change mmol;
		case C_Set_the_Unit:
		{
		    //--- Display all time limit 500ms
		    M_RTC_display++;
		    
		    if(M_RTC_display ==1)							//time base 10ms
		    {
		    	//--- display year
				//Lcd_Year_Process(M_Cbuf0);
	      	    //--- display date & time
				//Lcd_Month_Day_Process(M_Month,M_Days);
				//Lcd_Clock_Process(M_Hour,M_Cbuf0);
				//lcd.unit.Bit.TimeColon =1;
				//--- display unit
				Lcd_Unit(); 
				
				F_LcdUpdate =1;					              
		    }
			else if(M_RTC_display ==50)
			{
				//Clr_Unit();
				F_LcdUpdate =1;	
			}
		    else if(M_RTC_display >=100)						//time base 10ms
				M_RTC_display =0;
				

	    	//---------------------------------
			//--- check F_S_KEY_TOGGLE ---
			//--- into adjust Year Vaule	    		
			//Seting Year
//	        if(M_MKey_Hold_CNT <= 10)					//time base 10ms
//	        {
      	    if(setkey==2 || setkeydown==2)
      	    {
      	        setkey=0;
				setkeydown=0;
        		M_RTC_display = 0;					//for press hold display
        		M_No_Active_Cnt =0;     	       	
		        //--- set unit
				M_Unit ++;
				if(M_Unit >3)
					M_Unit =2; 
				F_Beep_Shortx1 =1;			  	
      	    }	
	

	        
	    	//---------------------------------
			//--- check F_S_KEY_TOGGLE ---
			//--- into adjust Year Vaule	    		
	    	if(memkey==1)
	    	{
	    		memkey=0;
				//--- Svav system vaule to flash
				Store_SetVauletoFlash();
//	    		ReadPage_flash(C_EEP_Significant);
//				M_FlashBuf0[C_Flash_UnitAdr + 0x00] = M_Unit;
//				M_FlashBuf0[C_Flash_UnitAdr + 0x10] = M_Unit;				
//				M_FlashBuf0[C_Flash_UnitAdr + 0x20] = M_Unit;				
//				M_FlashBuf0[C_Flash_UnitAdr + 0x30] = M_Unit;
//				Significant_Checksum();
//				WritePage_flash(C_EEP_Significant);	
				
				//--- Next task
			    M_RTC_display = 0;
				M_No_Active_Cnt = 0;
				//--- Next task
				M_TaskBuf0 = C_set_the_Alarm;
			//	M_TaskBuf0 = C_Set_the_DeleteMemory;
				M_TaskBuf1 =0;
				M_Error_Task =0;
				
				//--- move data
				M_Minutes = M_Cbuf0;
				M_Cbuf0 =0;
				M_Cbuf1 =0;
				//M_Cbuf0 = M_Unit;
	      		//---Lcd All off
	      		LCD_Clear(OFF);
	      		F_Beep_Shortx1 =1;
	      		
	    	}
			break;
		}
		
		//===================================
	  	//--- Adjustment  Alarm ------------
	    //--- C_set_the_Alarm
		case C_set_the_Alarm:
		{
			switch(M_TaskBuf1)
			{
				//===================================
			  	//--- Adjustment  Alarm X EN    ---
				case 0:
				{
				    //--- Display all time limit 1000ms
				    M_RTC_display++;
					
				    if(M_RTC_display ==1)				    
					{		      	    
						//--- display "ALn"						
						lcd.alarm.Bit.Alarm = 1;
						if(M_Cbuf1 ==0)
						{	   
							//show alarm1 icon
							lcd.alarm.Bit.Alarm_seg1 = 1;
							lcd.alarm.Bit.Alarm_seg2 = 0;
							lcd.alarm.Bit.Alarm_seg3 = 0;
							lcd.alarm.Bit.Alarm_seg4 = 0;
							//show alarm1 hour and min
							Lcd_Clock_Process(M_Alarm1_HR,M_Alarm1_MIN);
							
							//--- display "on & off"
							if(F_Alarm1_Enable)
								Show_BigString(" ON");
							else
								Show_BigString("OFF");
						}
						else if(M_Cbuf1 ==1)
						{	
							//show alarm1 icon
							lcd.alarm.Bit.Alarm_seg1 = 0;
							lcd.alarm.Bit.Alarm_seg2 = 1;
							lcd.alarm.Bit.Alarm_seg3 = 0;
							lcd.alarm.Bit.Alarm_seg4 = 0;

							//show alarm1 hour and min
							Lcd_Clock_Process(M_Alarm2_HR,M_Alarm2_MIN);
							
							//--- display "on & off"
							if(F_Alarm2_Enable)
								Show_BigString(" ON");
							else
								Show_BigString("OFF");
						}
						else if(M_Cbuf1 ==2)
						{	
							//show alarm1 icon
							lcd.alarm.Bit.Alarm_seg1 = 0;
							lcd.alarm.Bit.Alarm_seg2 = 0;
							lcd.alarm.Bit.Alarm_seg3 = 1;
							lcd.alarm.Bit.Alarm_seg4 = 0;

							//show alarm3 hour and min
							Lcd_Clock_Process(M_Alarm3_HR,M_Alarm3_MIN);
							//--- display "on & off"
							if(F_Alarm3_Enable)
								Show_BigString(" ON");
							else
								Show_BigString("OFF");
						}
						else if(M_Cbuf1 ==3)
						{	
							//show alarm1 icon
							lcd.alarm.Bit.Alarm_seg1 = 0;
							lcd.alarm.Bit.Alarm_seg2 = 0;
							lcd.alarm.Bit.Alarm_seg3 = 0;
							lcd.alarm.Bit.Alarm_seg4 = 1;
							//show alarm3 hour and min
							Lcd_Clock_Process(M_Alarm4_HR,M_Alarm4_MIN);
							//--- display "on & off"
							if(F_Alarm4_Enable)
								Show_BigString(" ON");
							else
								Show_BigString("OFF");
						}
						lcd.unit.Bit.TimeColon =1;
						F_LcdUpdate =1;
					}
				    else if(M_RTC_display ==50)
				    {
				    	//---- clear display
						 Clr_BigString();
						F_LcdUpdate =1;
				    }
				    else if(M_RTC_display >=100)						//time base 10ms
						M_RTC_display =0;


	    			//---------------------------------
					//--- check F_M_KEY_TOGGLE ---
					//--- long  key 1.5sec 	into "main menu"
					//--- short key 		into "memory mode"
		      	    if(setkey || setkeydown)
		      	    {
		      	        setkey=0;
						setkeydown = 0;
		      	       	if(M_Cbuf1 ==0)
							F_Alarm1_Enable = ~F_Alarm1_Enable;
						else if(M_Cbuf1 ==1)
							F_Alarm2_Enable = ~F_Alarm2_Enable;
						else if(M_Cbuf1 ==2)
							F_Alarm3_Enable = ~F_Alarm3_Enable;	
						else if(M_Cbuf1 ==3)
							F_Alarm4_Enable = ~F_Alarm4_Enable;	
						
						M_Error_Task =0;
						M_RTC_display =0;
						M_No_Active_Cnt = 0;
						F_Beep_Shortx1 =1;
					}
					

			        
			    	//---------------------------------
					//--- check F_S_KEY_TOGGLE ---
					//--- into Next task	    		
			    	if(memkey==1)
			    	{
			    		memkey=0;
						//--- Next task set alarm hour
						M_TaskBuf0 = C_set_the_Alarm;
						
						//--- move data
						if((M_Cbuf1 ==0) && (F_Alarm1_Enable))
						{
							M_TaskBuf1 =1;
							M_Cbuf0 = M_Alarm1_HR;
						}
						else if((M_Cbuf1 ==1) && (F_Alarm2_Enable))
						{
							M_TaskBuf1 =1;
							M_Cbuf0 = M_Alarm2_HR;
						}
						else if((M_Cbuf1 ==2) && (F_Alarm3_Enable))
						{
							M_TaskBuf1 =1;
							M_Cbuf0 = M_Alarm3_HR;
						}
						else if((M_Cbuf1 ==3) && (F_Alarm4_Enable))
						{
							M_TaskBuf1 =1;
							M_Cbuf0 = M_Alarm4_HR;
						}
						else
							M_Cbuf1++;
							
						if(M_Cbuf1 >=4)
						{
							//--- Next task
							M_TaskBuf0 = C_Set_out;
							
							//--- Svav system vaule to flash
							Store_SetVauletoFlash();
						}	
							
						
						M_Error_Task =0;
						M_RTC_display =0;
						M_No_Active_Cnt = 0;
						
						//--- Lcd update flag clear
						F_LcdUpdate =0;
						F_500ms_LCD =0;
			      		//---Lcd All off
			      		//LCD_Clear(OFF);
			      		F_Beep_Shortx1 =1;
			    	}
			    	
					break;
				}
				
				//===================================
			  	//--- Adjustment  Alarm X HR   ---
				case 1:
				{
				    //--- Display all time limit 1000ms
				    M_RTC_display++;
					
				    if(M_RTC_display ==1)				    
					{		
						//alarm is on in come to this step 
						Show_BigString(" ON");
						//--- display "ALn"
						if(M_Cbuf1 ==0)
						{	      	    
							lcd.alarm.Bit.Alarm_seg1 = 1;
							lcd.alarm.Bit.Alarm_seg2 = 0;
							lcd.alarm.Bit.Alarm_seg3 = 0;
							lcd.alarm.Bit.Alarm_seg4 = 0;
							//Show_BigString( "AL1" ) ;
							//--- display "Hour & Minutes"
							Lcd_Clock_Process(M_Cbuf0,M_Alarm1_MIN);
						}
						else if(M_Cbuf1 ==1)
						{	
							lcd.alarm.Bit.Alarm_seg1 = 0;
							lcd.alarm.Bit.Alarm_seg2 = 1;
							lcd.alarm.Bit.Alarm_seg3 = 0;
							lcd.alarm.Bit.Alarm_seg4 = 0;
							//Show_BigString( "AL2" ) ;
							//--- display "Hour & Minutes"
							Lcd_Clock_Process(M_Cbuf0,M_Alarm2_MIN);
						}
						else if(M_Cbuf1 ==2)
						{	
							lcd.alarm.Bit.Alarm_seg1 = 0;
							lcd.alarm.Bit.Alarm_seg2 = 0;
							lcd.alarm.Bit.Alarm_seg3 = 1;
							lcd.alarm.Bit.Alarm_seg4 = 0;
							//Show_BigString( "AL3" ) ;
							//--- display "Hour & Minutes"
							Lcd_Clock_Process(M_Cbuf0,M_Alarm3_MIN);
						}
						else if(M_Cbuf1 ==3)
						{	
							lcd.alarm.Bit.Alarm_seg1 = 0;
							lcd.alarm.Bit.Alarm_seg2 = 0;
							lcd.alarm.Bit.Alarm_seg3 = 0;
							lcd.alarm.Bit.Alarm_seg4 = 1;
							//Show_BigString( "AL4" ) ;
							//--- display "Hour & Minutes"
							Lcd_Clock_Process(M_Cbuf0,M_Alarm4_MIN);
						}

						lcd.unit.Bit.TimeColon =1;
						
						F_LcdUpdate =1;
					}
				    else if(M_RTC_display ==50)
				    {
				    	//---- clear display
						Clr_HourString();
						F_LcdUpdate =1;
				    }
				    else if(M_RTC_display >=100)						//time base 10ms
						M_RTC_display =0;
						
			    	//---------------------------------
					//--- check F_S_KEY_TOGGLE ---
					//--- into adjust Year Vaule	    		
					//Seting Hour
					
		      	    if(setkey)
		      	    {
		      	        setkey=0;
		        		M_RTC_display = 0;					//for press hold display
		        		M_No_Active_Cnt =0;     	       	
			            //--- check M_Hour over 24
			            M_Cbuf0++;
						if(M_Cbuf0 > 23)
							M_Cbuf0 =0;  
						F_Beep_Shortx1 =1;			
		      	    } 
					else if(setkeydown)
		      	    {
		      	        setkeydown=0;
		        		M_RTC_display = 0;					//for press hold display
		        		M_No_Active_Cnt =0;     	       	
			            //--- check M_Hour over 0
			            if(M_Cbuf0>0)
			            M_Cbuf0--;
						else
						M_Cbuf0 =23;  
						F_Beep_Shortx1 =1;			
		      	    }					
							
					

			        
			    	//---------------------------------
					//--- check F_S_KEY_TOGGLE ---
					//--- into adjust Year Vaule	    		
			    	if(memkey==1)
			    	{
			    		memkey=0;
					    M_RTC_display = 0;
						M_No_Active_Cnt = 0;
						//--- Next task set alarm minr
						M_TaskBuf0 = C_set_the_Alarm;
						M_TaskBuf1 =2;
						M_Error_Task =0;
						
						//--- move data
						if((M_Cbuf1 ==0) && (F_Alarm1_Enable))
						{
							M_Alarm1_HR = M_Cbuf0;
							M_Cbuf0 = M_Alarm1_MIN;
						}
						else if((M_Cbuf1 ==1) && (F_Alarm2_Enable))
						{
							M_Alarm2_HR = M_Cbuf0;
							M_Cbuf0 = M_Alarm2_MIN;
						}
						else if((M_Cbuf1 ==2) && (F_Alarm3_Enable))
						{
							M_Alarm3_HR = M_Cbuf0;
							M_Cbuf0 = M_Alarm3_MIN;
						}
						else if((M_Cbuf1 ==3) && (F_Alarm4_Enable))
						{
							M_Alarm4_HR = M_Cbuf0;
							M_Cbuf0 = M_Alarm4_MIN;
						}
						
						F_Beep_Shortx1 =1;
			    	}
						
					
					break;
				}
				
				//===================================
			  	//--- Adjustment  Alarm X Min   ---
				case 2:
				{
				    //--- Display all time limit 1000ms
				    M_RTC_display++;
					
				    if(M_RTC_display ==1)				    
					{		      	    
						//--- display "ALn"
						if(M_Cbuf1 ==0)
						{	      	    
							lcd.alarm.Bit.Alarm_seg1 = 1;
							lcd.alarm.Bit.Alarm_seg2 = 0;
							lcd.alarm.Bit.Alarm_seg3 = 0;
							lcd.alarm.Bit.Alarm_seg4 = 0;
							//Show_BigString( "AL1" ) ;
							//--- display "Hour & Minutes"
							Lcd_Clock_Process(M_Alarm1_HR,M_Cbuf0);
						}
						else if(M_Cbuf1 ==1)
						{	
							lcd.alarm.Bit.Alarm_seg1 = 0;
							lcd.alarm.Bit.Alarm_seg2 = 1;
							lcd.alarm.Bit.Alarm_seg3 = 0;
							lcd.alarm.Bit.Alarm_seg4 = 0;
							//Show_BigString( "AL2" ) ;
							//--- display "Hour & Minutes"
							Lcd_Clock_Process(M_Alarm2_HR,M_Cbuf0);
						}
						else if(M_Cbuf1 ==2)
						{	
							lcd.alarm.Bit.Alarm_seg1 = 0;
							lcd.alarm.Bit.Alarm_seg2 = 0;
							lcd.alarm.Bit.Alarm_seg3 = 1;
							lcd.alarm.Bit.Alarm_seg4 = 0;
							//Show_BigString( "AL3" ) ;
							//--- display "Hour & Minutes"
							Lcd_Clock_Process(M_Alarm3_HR,M_Cbuf0);
						}
						else if(M_Cbuf1 ==3)
						{	
							lcd.alarm.Bit.Alarm_seg1 = 0;
							lcd.alarm.Bit.Alarm_seg2 = 0;
							lcd.alarm.Bit.Alarm_seg3 = 0;
							lcd.alarm.Bit.Alarm_seg4 = 1;
							//Show_BigString( "AL4" ) ;
							//--- display "Hour & Minutes"
							Lcd_Clock_Process(M_Alarm4_HR,M_Cbuf0);
						}
						lcd.unit.Bit.TimeColon =1;
						
						F_LcdUpdate =1;
					}
				    else if(M_RTC_display ==50)
				    {
				    	//---- clear display
						Clr_MinString();
						F_LcdUpdate =1;
				    }
				    else if(M_RTC_display >=100)						//time base 10ms
						M_RTC_display =0;
						
			    	//---------------------------------
					//--- check F_S_KEY_TOGGLE ---
					//--- into adjust Year Vaule	    		
					//Seting Year
					
		      	    if(setkey)
		      	    {
		      	        setkey=0;
		        		M_RTC_display = 0;					//for press hold display
		        		M_No_Active_Cnt =0;     	       	
		    		    //--- check M_Minutes over 60
		    		    M_Cbuf0++;
						if(M_Cbuf0 > 59)
							M_Cbuf0 =0;
						F_Beep_Shortx1 =1;	
		      	    }
					else  if(setkeydown)
		      	    {
		      	        setkeydown=0;
		        		M_RTC_display = 0;					//for press hold display
		        		M_No_Active_Cnt =0;     	       	
		    		    //--- check M_Minutes over 60
		    		    if(M_Cbuf0 > 0)
		    		    M_Cbuf0--;
						else
						M_Cbuf0 =59;
						F_Beep_Shortx1 =1;	
		      	    }						
			    	//---------------------------------
					//--- check F_S_KEY_TOGGLE ---
					//--- into adjust Year Vaule	    		
			    	if(memkey==1)
			    	{
			    		memkey=0;
			    		
		    			//--- Next task set alarm hour
						M_TaskBuf0 = C_set_the_Alarm;
						M_TaskBuf1 =0;
						
						//--- move data
						if((M_Cbuf1 ==0) && (F_Alarm1_Enable))
						M_Alarm1_MIN = M_Cbuf0;
						else if((M_Cbuf1 ==1) && (F_Alarm2_Enable))
						M_Alarm2_MIN = M_Cbuf0;
						else if((M_Cbuf1 ==2) && (F_Alarm3_Enable))
						M_Alarm3_MIN = M_Cbuf0;
						else if((M_Cbuf1 ==3) && (F_Alarm4_Enable))
						M_Alarm4_MIN = M_Cbuf0;
			    		
			    		M_Cbuf1++;
						if(M_Cbuf1 >=4)
						{		
							//--- Next task
							M_TaskBuf0 = C_Set_out;
							
							//--- Svav system vaule to flash
							Store_SetVauletoFlash();
						}	
						
						
					    M_RTC_display = 0;
						M_No_Active_Cnt = 0;
						M_Error_Task =0;
						//--- Lcd update flag clear
						F_LcdUpdate =0;
						F_500ms_LCD =0;
			      		//---Lcd All off
			      		LCD_Clear(OFF);
			      		F_Beep_Shortx1 =1;
			    	}
					
					break;
				}

			}
			
			break;
		} 
		
		
		//===================================
	  	//--- Adjustment  Unit ------------
	    //--- C_Set_the_Unit
		case C_Set_the_DeleteMemory:
		{
			switch(M_TaskBuf1)
			{
				case 0:
				{
				    //--- Display all time limit 1000ms
				    M_RTC_display++;
					
				    if(M_RTC_display ==1)				    
					{	
					
						if(imp)//按下M键后显示yes，有语音不用不用显示yes
						{
							//--- display "DEL"
							Show_BigString( "YES" ) ;
						}
						else
						{
							Show_BigString( "DEL" ) ;
						}
						//Lcd_Display_DEL();
						//--- display "Mem"
						lcd.mem.Bit.Memory =1;
						
						F_LcdUpdate =1;
					}
				    else if(M_RTC_display ==50)
				    {
						//--- display "Mem"
						lcd.mem.Bit.Memory =0;
						
						F_LcdUpdate =1;
					
						
				    }
				    else if(M_RTC_display >=100)						//time base 10ms
						M_RTC_display =0;


	    			//---------------------------------
					//--- check P_M_KEY ---
					//--- long key 3sec into "main menu"
					//--- short key 	into "memory mode"
						
		      	    if(setkey || setkeydown)
		      	    {
		      	    	 setkey=0;
		      	    	 setkeydown=0;
						//--- into next task 
						//if(memkey==2)
						if(imp==0)
						{
							 imp++;	

							M_Error_Task =0;
							M_No_Active_Cnt = 0;

							LCD_Clear(OFF);
							Show_BigString( "YES" ) ;	
							F_LcdUpdate =1;
							F_Beep_Shortx1 =1;

						}
						else
						{
							M_TaskBuf1 =1;
							M_Error_Task =0;
							M_RTC_display =0;
							M_No_Active_Cnt = 0;
										
				      		//---Lcd All off
				      		LCD_Clear(OFF);
							
							//--- Lcd update flag clear
							F_LcdUpdate =0;
							F_500ms_LCD =1;
							F_Beep_Shortx1 =1;
						}
						
		      	      						
						
		      	    } 						
					

			        
			    	//---------------------------------
					//--- check F_S_KEY_TOGGLE ---
					//--- into adjust Year Vaule	    		
			    	if(memkey==1)
			    	{
			    		memkey=0;
						//--- Next task
					    M_RTC_display = 0;
						M_No_Active_Cnt = 0;
						//M_Task = C_set_the_Alarm;
						//M_TaskBuf0 =0;	
						#ifdef UNIT_ADJUST
						M_TaskBuf0 = C_Set_the_Unit;
						#else
						M_TaskBuf0 = C_set_the_Alarm;
						#endif
						M_TaskBuf1 =0;
						M_Cbuf1 = 0;
					    //F_Beep_Shortx1 =1;
					    M_Error_Task =0;
			      		//---Lcd All off
			      		LCD_Clear(OFF);
			      		F_Beep_Shortx1 =1;
					 }
					break;
				}
				
				//--- delete record
				case 1:
				{
					if(F_500ms_LCD)
					{
					
						Show_BigString( "---" ) ;
						//Lcd_Display_dash();
						if(lcd.mem.Bit.Memory)
							//--- display off "M"
							lcd.mem.Bit.Memory =0;
						else
							//--- display on "M"
							lcd.mem.Bit.Memory =1;
						
						F_500ms_LCD =0;
						F_LcdUpdate =1;
					}
					
				    //--- Display all time limit 1000ms
				    M_RTC_display++;
				    
				    if(M_RTC_display ==1)
				    {
				    	M_GM_data_Record =0;
				    	M_GM_Record_current =0;
				    	
						//--- Svav system vaule to flash
						Store_SetVauletoFlash();
						
						
						set_temp_25=0;
						Write_EEPROMBuf(C_EEP_FactoryMode_Adr,(unsigned char*)&set_temp_25,1);						
				    	
//				    	ReadPage_flash(C_EEP_Significant);
//				    	
//						M_FlashBuf0[C_Flash_RecordAdr + 0x00] = M_GM_data_Record;  //load M_GM_data_Record 3D81
//						M_FlashBuf0[C_Flash_Current_RecordAdr + 0x00] = M_GM_Record_current;  //load M_GM_Record_current 3D82
//					
//						M_FlashBuf0[C_Flash_RecordAdr + 0x10] = M_GM_data_Record;  //load M_GM_data_Record 3D81
//						M_FlashBuf0[C_Flash_Current_RecordAdr + 0x10] = M_GM_Record_current;  //load M_GM_Record_current 3D82
//						
//						M_FlashBuf0[C_Flash_RecordAdr + 0x20] = M_GM_data_Record;  //load M_GM_data_Record 3D81
//						M_FlashBuf0[C_Flash_Current_RecordAdr + 0x20] = M_GM_Record_current;  //load M_GM_Record_current 3D82
//						
//						M_FlashBuf0[C_Flash_RecordAdr + 0x30] = M_GM_data_Record;  //load M_GM_data_Record 3D81
//						M_FlashBuf0[C_Flash_Current_RecordAdr + 0x30] = M_GM_Record_current;  //load M_GM_Record_current 3D82
//						
//						Significant_Checksum();	
//						// Write flash area for special  record 3D80~3D85
//						WritePage_flash(C_EEP_Significant);
						
				    }
				    else if(M_RTC_display >=100)						//time base 10ms
				    {
						//--- Next task
					    M_RTC_display = 0;
						M_No_Active_Cnt = 0;
						//M_Task = C_set_the_Alarm;
						#ifdef UNIT_ADJUST
						M_TaskBuf0 = C_Set_the_Unit;
						#else
						M_TaskBuf0 = C_set_the_Alarm;
						#endif		
						M_TaskBuf1 =0;
						M_Cbuf1 = 0;
					    //F_Beep_Shortx1 =1;
					    M_Error_Task =0;
					    	setkey=0;
					    	memkey=0;
					    
			      		//---Lcd All off
			      		LCD_Clear(OFF);
				    }
					
					break;	
				}
			}
	    	
			break;
		}
		
	
		 //--- Error task ----
	  	case C_Set_the_Error:
	  	{
			//--- display date & time
//			if(F_LcdUpdateBuf ==0)
//			{
//				//--- display Month & Day
//				Lcd_Month_Day_Process(M_Month,M_Days);
//				//--- display Hour & Minutes
//				Lcd_Clock_Process(M_Hour,M_Minutes);
//				
//				F_LcdUpdateBuf =1;
//				F_LcdUpdate =1;
//			}
//			
//			//--- display col flash
			if(F_500ms_LCD)
			{
//				if(lcd.unit.Bit.TimeColon != 0)
//					LCD_BitSetOut( LcdBit_Unit_TimeColon, OFF) ;
//				else
//					LCD_BitSetOut( LcdBit_Unit_TimeColon, ON ) ;
//					
//				F_500ms_LCD =0;
				F_LcdUpdate =1;
			}
//	  		
	  		M_RTC_display++;	  		
	  		if((F_Low_battery_Act==0 && M_RTC_display > 300 )||( F_Low_battery_Act && M_RTC_display > 50 ))
	  		{
			    M_TaskBuf0 = C_Set_out;
	  			
	  		}

			break; 
	  	}

	  	case C_Set_out:
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
	      		//---Lcd All off
	      		LCD_Clear(OFF);
			}
			break;
	  	}
	}

//	if(F_StripInsert)
//	{
//	    M_RTC_display = 0;
//		M_No_Active_Cnt = 0;
//		M_Task = C_NormalMode;
//		M_TaskBuf0 =1;			
//		M_TaskBuf1 =0;
//		
//		F_Battery_checked = 0;
//		F_Low_battery_Act=0;
//		
//		//--- Lcd All off
//		LCD_Clear(OFF);
//
//	}

	
	//-------- counting time out 60sec Process  -------------
	M_No_Active_Cnt++;
	if(M_No_Active_Cnt >= 6000)	      //base time 31.25ms =>60 sec
	{
		M_No_Active_Cnt = 0;
		//-- quit MemoryMode mode
	    M_Task = C_OffMode;           //quit MemoryMode mode
	    M_TaskBuf0 =0;
		M_TaskBuf1 =0;
		M_Error_Task =0;
	    M_RTC_display = 0; 
	}	    		    	
}



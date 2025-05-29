#include "include.h"
#include "typedef.h"
#include <string.h>
enum {
	mem_init=0,
    mem_memselect,
    mem_nodata,	
    mem_look,
    mem_avgselect,	
    mem_avglook,    
    mem_memdelete,
    mem_err,
    mem_out,

}memmode;


void MemoryMode (void)
{
	unsigned char 	buf[6];
	unsigned char  	Cbuf1=0;
	volatile unsigned int	Ibuf0,Ibuf1;
	volatile unsigned long	Lbuf0,Lbuf1;	
	
	//v_key_int=0;
    switch (M_TaskBuf0)
	{
		//---------------------------------
		//--- Read Memory data record  ----
		case mem_init:
		{
			M_RTC_display++;
			if(M_RTC_display ==1)
			{
				//--- display all on
				LCD_Clear(ON);
#if voice_en
				voice_reset();
				M_LCD_RAM[0] |= 0x08;//	F_LabaShow = 1;			
#else

#endif
	      		//Clr_Bat();
	      		//M_LCD_RAM[6]&=~(1<<3);//dis show beat
	
				M_7days_datasum =0;
				M_14days_datasum =0;
				M_28days_datasum =0;

				M_7daysNumber =0;
				M_14daysNumber =0;
				M_28daysNumber =0;
				
				M_30days_datasum=0;
				M_30daysNumber=0;				
				M_60days_datasum=0;
				M_60daysNumber=0;					
				M_90days_datasum=0;
				M_90daysNumber=0;			
				//--- get current time
				buf[5] = M_Year;
				buf[4] = M_Month;// = 5;
				buf[3] = M_Days;// = 1;
				buf[2] = M_Hour;// = 12;
				buf[1] = M_Minutes;// = 0;
				buf[0] = M_Second;// = 0;
				M_Lbuf0 = DateToSecond(buf);   //change to second
//				key_lock=0;
//				memkey_bk=memkey;
//				memkey=0;
				//F_UpdateFlag=0;
#if ACFG_BT_EN
					bt_init();
#endif
				//---- read data from eeprom max 500x6 bytes
				for(M_GM_data_Record_buf =1 ; M_GM_data_Record_buf <= M_GM_data_Record ; M_GM_data_Record_buf++)
				{
					GCC_CLRWDT();
	     			//-- load start address
	     			
	     			//--- 31.25 ms for main loop ----
					if(F_MainTimerOut ==1)				//check 31.25ms Flag
					{
						F_MainTimerOut =0;
						M_RTC_display++;
					}
	     			//-- load start address
	     			Ibuf1 = ((M_GM_data_Record_buf - 1) * 4); 
		         	Ibuf1 += C_FlashDataOffset;     //add flash offset addrss = save current data address
		         	
					//ReadPage_flash(C_FlashDataOffset);
					
					Ibuf0 =Flash_Store_Read_Process(Ibuf1 +3);
		         	if(Ibuf0 != 0xffff)
		         	{
				     	//-- load time recordH
				     	Ibuf0 = Flash_Store_Read_Process(Ibuf1);  //buf1/buf0/buf3/buf2
				     	Lbuf0=Ibuf0;
			         	Lbuf0 <<=16;
			        
			         	//--- load time recordL
			         	Ibuf1++;
			         	Ibuf0 = Flash_Store_Read_Process(Ibuf1);  //buf1/buf0/buf3/buf2
						Lbuf0 +=Ibuf0;
			 	 	 	//--- load Glucose data
					 	Ibuf1++;
			         	M_GM_data = Flash_Store_Read_Process(Ibuf1);  //buf1/buf0/buf3/buf2	
			         	
	
						//if(F_ControlOption ==0)
						{
						//	if((M_GM_data >= lo) && (M_GM_data <= hi))
							{
								//--- find data type 7 days 604800 sec
								Lbuf1 = M_Lbuf0 - 604800;
								if((Lbuf1 <= Lbuf0) && (Lbuf0 <= M_Lbuf0))
								{
									//--- 一??
									M_7days_datasum += M_GM_data;
									M_7daysNumber++;
								}
								
								//--- find data type 14 days 1209600 sec
								Lbuf1 = M_Lbuf0 - 1209600;
								if((Lbuf1 <= Lbuf0) && (Lbuf0 <= M_Lbuf0))
								{
									//--- 一??
									M_14days_datasum += M_GM_data;
									M_14daysNumber++;	
								}
								
								//--- find data type 28 days 2419200 sec
								Lbuf1 = M_Lbuf0 - 2419200;
								if((Lbuf1 <= Lbuf0) && (Lbuf0 <= M_Lbuf0))
								{
									//--- 一??
									M_28days_datasum += M_GM_data;
									M_28daysNumber++;	
								}
								
								//--- find data type 30 days 2419200 sec
						        Lbuf1 = M_Lbuf0 - 2592000;
						        if((Lbuf1 <= Lbuf0) && (Lbuf0 <= M_Lbuf0))
						        {
										M_30days_datasum += M_GM_data;
										M_30daysNumber++;	
						        }
						        //--- find data type 60 days 2419200 sec
						        Lbuf1 = M_Lbuf0 - 5184000;
						        if((Lbuf1 <= Lbuf0) && (Lbuf0 <= M_Lbuf0))
						        {
										M_60days_datasum += M_GM_data;
										M_60daysNumber++;	
						        }
						                
						        //--- find data type 90 days 2419200 sec
						        Lbuf1 = M_Lbuf0 - 7776000;
						        if((Lbuf1 <= Lbuf0) && (Lbuf0 <= M_Lbuf0))
						        {
										M_90days_datasum += M_GM_data;
										M_90daysNumber++;	
								}
							}
						}
		         	}
				}
			}

			else if(M_RTC_display >=100)
			{
				//F_LabaShow = 0;
				if(F_Low_battery_Act)
					M_Error_Task = 6;
				if(M_Error_Task == 0)
				{
					M_RTC_display =0;
					if(memkey==1)
					  M_TaskBuf0=mem_memselect;
					else
					  M_TaskBuf0=mem_avgselect;
					memkey=0;					
					

			     	M_TaskBuf1 =0;
			     	M_Cbuf0 =0;
			     	F_ControlOption =0;
			     	M_No_Active_Cnt =0;
			     	
			     	
    	            //--- Beep ON
    	            F_Beep_Shortx1 =1;
			     	//--- display all off
			     	LCD_Clear(OFF);
			     	
	      			//--- lcd update clear flag
					F_LcdUpdateBuf =0;
					F_LcdUpdate =0;	


				}
				else
				{
					M_RTC_display =0;
			     	M_TaskBuf0 =mem_err;
			     	M_TaskBuf1 =0;
			     	M_No_Active_Cnt =0;
		            //--- Beep ON
		            F_Beep_Shortx2 =1;
			     	//--- Lcd All off
			     	LCD_Clear(OFF);
			     	
	      			//--- lcd update clear flag
					F_LcdUpdateBuf =0;
					F_LcdUpdate =0;	
				}
			}

			
			break;
		}
//----------------------------------------------------			
		//--- mem menu		
		case mem_memselect:
		{	
		
			M_RTC_display++;
					   		
	   		if(M_RTC_display >=200)						//time base 10ms
				M_RTC_display =0;
	   		
			if(M_RTC_display ==1)
			{
				Lcd_Clock_Process(M_Hour,M_Minutes);
				lcd.unit.Bit.TimeColon =1;
				
				lcd.mem.Bit.Memory =1;
				//if(memkey_bk==2)
				 // lcd.mem.Bit.Average =1;
				
				F_LcdUpdate =1;				              
			}
			else if(M_RTC_display ==100)
		    {
				//--- display "Mem"
				lcd.mem.Bit.Memory =0;				
				lcd.unit.Bit.TimeColon =0;
				lcd.unit.Bit.AM =0;
				lcd.unit.Bit.PM =0;
				
				Lcd_Month_Day_Process(M_Month,M_Days);
				//if(memkey_bk==2)
				//  lcd.mem.Bit.Average =0;							
				F_LcdUpdate =1;
	    	}
			#if 0
	    	if(F_UpdateFlag==0)
	    	{
	    		if(M_RTC_display==20)
	    		{
		    	//	vice_addr2(30);//请按M??进入查看记忆模式
		    	//v_key_int=0;
				#if (voice_en==1)
				vice_addr(30);
				#endif
		    	F_UpdateFlag=1;
	    		}
	    	}
	    	#endif
	    	
	    	if(memkey==1)
	    	{
	    		memkey=0;
	    		
		    	if(M_GM_data_Record ==0)
				{
	
				    M_RTC_display = 0;
					M_TaskBuf0 =mem_nodata;			
					M_TaskBuf1 =0;
					work_time = 0;
				}
				else
				{
					
					M_TaskBuf0 = mem_look;//mem
					//--- into memory mode

					M_TaskBuf1 =0;
					M_Error_Task =0;
					M_RTC_display =0;
					M_No_Active_Cnt = 0;
					
					//--- Lcd All off
					LCD_Clear(OFF);
					
		    		F_Beep_Shortx1 =1;
					//--- read record
					F_read_eeprom =1;
					M_GM_data_Record_buf = 	M_GM_Record_current;
					M_Ibuf0 =1;		
				
				}			    		
	    		
	    	}
	    	if(memkey==2)
	    	{
	    			setkey=0;
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
		
		//--- show Memory data number  ----
		case mem_look:
		{
			//--- display "M"
		//	M_LCD_RAM[4] |= 0x01;

		lcd.mem.Bit.Memory = 1; // on "Men"
		if (M_RTC_display <= 100)
			M_RTC_display++;

		if (M_RTC_display == 1)
		{
#if ACFG_BT_EN
			bt_init();
#endif
			//				Lcd1_11_DisplayOff(1);
			//				Lcd1_11_DisplayOff(2);
			//				Lcd1_11_DisplayOff(3);
			while (F_read_eeprom)
			{
				GCC_CLRWDT();
				//-- load start address
				Ibuf1 = ((M_GM_data_Record_buf - 1) * 4);
				Ibuf1 += C_FlashDataOffset; // add flash offset addrss = save current data address

				Ibuf0 = Flash_Store_Read_Process(Ibuf1 + 3);
				if (Ibuf0 != 0xffff)
				{
					//-- load time recordH
					Ibuf0 = Flash_Store_Read_Process(Ibuf1); // buf1/buf0/buf3/buf2
					Lbuf0 = Ibuf0;
					Lbuf0 <<= 16;

					//--- load time recordL
					Ibuf1++;
					Ibuf0 = Flash_Store_Read_Process(Ibuf1); // buf1/buf0/buf3/buf2
					Lbuf0 += Ibuf0;
					//--- load Glucose data
					Ibuf1++;
					M_GM_data = Flash_Store_Read_Process(Ibuf1); // buf1/buf0/buf3/buf2
					//--- load Glucose data
					Ibuf1++;
					meals = Flash_Store_Read_Process(Ibuf1); // buf1/buf0/buf3/buf2

					//---?@??????????
					//--- Clear lcd 9,10,11
					// Clr_BigString();
					LCD_Clear_Buff(OFF);

					//--- display "M"
					lcd.mem.Bit.Memory = 1; // on "Men"

					//--- which Number display
					Ibuf0 = M_Ibuf0;
					Lcd_ShowAvgNum(Ibuf0);

					Lcd_Glucose(M_GM_data);

					lcd.meas.Bit.AftMeal = 0;
					lcd.meas.Bit.BefMeal = 0;
					lcd.meas.Bit.ControlSoultion = 0;
					if(M_GM_data > 240)//酮体显示
					{
						lcd.unit.Bit.Ketone=1;
					}
					if (meals == 1) //???
					{
						lcd.meas.Bit.AftMeal = 0;
						lcd.meas.Bit.BefMeal = 1;
					}
					else if (meals == 2) //???
					{
						lcd.meas.Bit.AftMeal = 1;
						lcd.meas.Bit.BefMeal = 0;
					}
					else
					{
						lcd.meas.Bit.AftMeal = 0;
						lcd.meas.Bit.BefMeal = 0;
					}
					//--- clear read flag
					F_read_eeprom = 0;

					//--- Lcd update
					F_LcdUpdate =1;
				}
			}
		}
		else if (M_RTC_display == 100)
		{
					
			        //---顯示紀??????
			        SecondToDate(Lbuf0,buf);	
					M_RTC_display = 2;
					if(FlashTimeFlag)
					{
						FlashTimeFlag = 0;
						//--- display Month & Day
						Lcd_Month_Day_Process(buf[4],buf[3]);
						lcd.unit.Bit.TimeColon =0;
						lcd.unit.Bit.AM =0;
						lcd.unit.Bit.PM =0;
					}
					else
					{
						FlashTimeFlag=1;
						//--- display clock
						Lcd_Clock_Process(buf[2],buf[1]);
						lcd.unit.Bit.DateSlash =0;
						lcd.unit.Bit.TimeColon =1;
					}
				  	//--- display col
				  	Lcd_Bat(batlevel);
				 // 	BatteryCheckProcess ();
				  //	LCD_ScanOut() ;
					//--- Lcd update
					F_LcdUpdate =1;
				}
				
	
		    	//---------------------------------
				//--- check P_M_KEY ---
				//--- long key 3sec into "main menu"
				//--- short key 	into "memory mode"	 
				if(P_M_KEY && key_lock==0) 
				{
				  key_lock=1;	
				  keyinti();				 
				}  
				#if 1
	      	    if((setkey==1 || memkey==1)&& key_lock)
	      	    {
					setkey = 0;
					memkey = 0;
					M_No_Active_Cnt = 0;
					
					//--- Lcd All off
					// LCD_Clear(OFF);
					F_Beep_Shortx1 = 1;
					//--- next reord
					F_read_eeprom = 1;
					M_Ibuf0++;

					if(M_Ibuf0 > M_GM_data_Record)
					{
						M_Ibuf0 = 1;
						M_GM_data_Record_buf = M_GM_data_Record;
						
						F_read_eeprom_Up_Down = 0;
						M_RTC_display = 0;


#if 0				
					    M_RTC_display = 0;
						M_No_Active_Cnt = 0;
						M_Task = C_OffMode;
						M_TaskBuf0 =0;			
						M_TaskBuf1 =0;
					    M_Error_Task =0;
				     	LCD_Clear(OFF);
						//--- update bat lcd
						Lcd_Bat(batlevel);
						//--- display "M"
						lcd.mem.Bit.Memory =1;	//on "Men"
						
						//--- display "---"
						Show_BigString( "END" ) ;
						//Lcd_Display_dash();
						
		      			//--- lcd update
						F_LcdUpdate =1;	
						
						for(M_RTC_display=0;M_RTC_display<30;M_RTC_display++)
						{
						  	LCD_ScanOut();
						  	GCC_CLRWDT();
						}
#endif	
	     	
					}
					else
					{
						if (M_GM_data_Record_buf != 0)
							M_GM_data_Record_buf--;
						if (M_GM_data_Record_buf == 0)
							M_GM_data_Record_buf = M_GM_data_Record;
						F_read_eeprom_Up_Down = 0;
						M_RTC_display = 0;
					}
		}
#endif


		// ??????????
		if (setkeydown == 1)
		{
			setkeydown = 0;
			M_No_Active_Cnt = 0;
			//--- Lcd All off
			// LCD_Clear(OFF);
			F_Beep_Shortx1 = 1;
			//--- next reord
			F_read_eeprom = 1;
			if (M_Ibuf0 == 1)
			{
				M_GM_data_Record_buf = 1;
				M_Ibuf0 = M_GM_data_Record;
			}
			else
			{
				M_Ibuf0--;
				M_GM_data_Record_buf++;
			}

			F_read_eeprom_Up_Down = 0;
			M_RTC_display = 0;
		}
		else if (setkey == 2)
		{
			setkey = 0;
			M_TaskBuf0 = mem_memdelete;
			M_TaskBuf1 = 0;
			M_RTC_display = 0;
			M_No_Active_Cnt = 0;
			//---Lcd All off
			LCD_Clear(OFF);
		}
		if (memkey == 2)
		{

					memkey=0;	
				    M_RTC_display = 0;
					M_No_Active_Cnt = 0;
					M_Task = C_OffMode;
					M_TaskBuf0 =0;			
					M_TaskBuf1 =0;
				    M_Error_Task =0;
	
		            //--- Beep ON
		            F_Beep_Shortx1 =1;
	//		     	--- display all off
			     	LCD_Clear(OFF);		    
	     }						



			//	BatteryCheckProcess ();
//				if(F_500ms_LCD)
//				{					
//				    LCD_Update(1);	
//					F_500ms_LCD =0;		
//				}		
				
				break;   //case 2 end
		}		
	
//----------------------------------------------------			
		case mem_nodata:
		{
			
					M_RTC_display++;
					if(M_RTC_display==1)
					{					
						LCD_Clear(OFF);
						//--- display "M"
						lcd.mem.Bit.Memory =1;	//on "Men"
						//--- display col
				  		Lcd_Bat(batlevel);
						//--- display "---"
						Show_BigString( "---" ) ;
						F_LcdUpdate=1;
					}
					if(M_RTC_display==2)
					{
						#if (voice_en==1)
						vice_addr2(0x28);//无测量???录
						#endif
					}			
					else if(M_RTC_display >= 30*100 || (M_RTC_display >=2&&memkey))
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
//----------------------------------------------------			
		//--- AVG menu		
		case mem_avgselect:
		{	
		
			M_RTC_display++;
					   		
	   		if(M_RTC_display >=40)						//time base 10ms
				M_RTC_display =0;
	   		
			if(M_RTC_display ==1)
			{
//				Lcd_Month_Day_Process(M_Month,M_Days);
//				Lcd_Clock_Process(M_Hour,M_Minutes);
//				lcd.unit.Bit.TimeColon =1;
				
				lcd.mem.Bit.Memory =1;

			    lcd.mem.Bit.Average =1;

				lcd.mem.Bit.Day =1;
				
				F_LcdUpdate =1;				              
			}
			else if(M_RTC_display ==20)
		    {
				//--- display "Mem"

				lcd.mem.Bit.Average =0;	
				lcd.mem.Bit.Day =0;
				F_LcdUpdate =1;
	    	}


	    	if(P_M_KEY)
	    	{
	    		if(M_GM_data_Record ==0)
				{
	
				    M_RTC_display = 0;
					M_TaskBuf0 =mem_nodata;			
					M_TaskBuf1 =0;
					work_time = 0;
				}
				else
				{
					M_TaskBuf0 = mem_avglook;//AVG 
					M_TaskBuf1 =0;
					M_Cbuf0 = 1;
					M_RTC_display =0;
					M_No_Active_Cnt=0;
				}
				F_Beep_Shortx1 =1;
//	    	            //--- Beep ON
//	    	            F_Beep_Shortx1 =1;
		     	//--- display all off
		     	LCD_Clear(OFF);
      			//--- lcd update clear flag
				F_LcdUpdateBuf =0;
				F_LcdUpdate =0;	
		     	
				//--- read avg record
				F_read_eeprom =1; 			    		
	    		
	    	}

				
			break;
		}
		

				



		//---------------------------
		//--- XXXX days display -----
		case mem_avglook:
		{		

				if(F_read_eeprom)
				{
					//---??示???糖數??
			     	//--- Clear lcd 9,10,11
			     	Clr_BigString();
			  		
//					//--- display Month & Day
//					Lcd_Month_Day_Process(M_Month,M_Days);
//					//--- display Hour & Minutes
//					Lcd_Clock_Process(M_Hour,M_Minutes);
					//--- display "M"
					lcd.mem.Bit.Memory =1;	//on "Men"
					//--- display "AVG"			
					lcd.mem.Bit.Average =1;	//on "AVG"
					
					lcd.mem.Bit.Day =1;
					//--- clear flag
					F_read_eeprom =0;
					
					if(M_Cbuf0  ==1)          //for AVG mode
					{
						//--- 一??7 days
						Lbuf0 = M_7days_datasum;
						Lbuf1 = M_7daysNumber;
						Cbuf1 = 7;
					}
					else if(M_Cbuf0  ==2)
					{	
						//--- 一??14 days
						Lbuf0 = M_14days_datasum;
						Lbuf1 = M_14daysNumber;
						Cbuf1 = 14;
					}
					else if(M_Cbuf0  == 3)
					{		
						//--- ???28 days
						Lbuf0 = M_30days_datasum;
						Lbuf1 = M_30daysNumber;
						Cbuf1 = 30;
					}
					else if(M_Cbuf0  == 4)
					{		
						//--- ???28 days
						Lbuf0 = M_60days_datasum;
						Lbuf1 = M_60daysNumber;
						Cbuf1 = 60;
					}
					else if(M_Cbuf0  == 5)
					{		
						//--- ???28 days
						Lbuf0 = M_90days_datasum;
						Lbuf1 = M_90daysNumber;
						Cbuf1 = 90;
					}
					
					//--- which days display
					Ibuf0 = Lbuf1;					

					//Lcd_ShowAvgDay(Ibuf0);
					
					//--- which Number display
					Ibuf0 = Cbuf1;
					Lcd_ShowAvgNum(Ibuf0);
					LCD_ScanOut() ;	
	
					//--- display AVG blood value
					if(Lbuf0 !=0)
					{
						Ibuf1 = ((Lbuf0*10) / Lbuf1);
						Ibuf0 = Ibuf1 / 10;
						//--- check 4????
						Ibuf1 %= 100;
						Ibuf1 %= 10;
						if(Ibuf1 >=5)
							Ibuf0++;
					}
					else
						Ibuf0 =0;
						
					M_GM_data = Ibuf0;

//					if(M_GM_data != 0)
//					{

						if(M_GM_data > 240)
							LCD_BitSetOut( LcdBit_Unit_Ketone, ON) ;
						else
							LCD_BitSetOut( LcdBit_Unit_Ketone, OFF) ;
							

						if(M_Cbuf0  ==1)          //for AVG mode
						{
	
							Cbuf1 = 0x20;
						}
						else if(M_Cbuf0  ==2)
						{	
	
							Cbuf1 = 0x21;
						}
						else if(M_Cbuf0  == 3)
						{		
	
							Cbuf1 = 0x23;
						}
						else if(M_Cbuf0  == 4)
						{		
	
							Cbuf1 = 0x24;
						}
						else if(M_Cbuf0  == 5)
						{		
	
							Cbuf1 = 0x25;
						}	
						
						if(Lbuf0 && M_GM_data!=0)
						   Lcd_Glucose(M_GM_data);	
					  	else
					  		Show_BigString( "---" ) ;
					  	LCD_ScanOut() ;							
							
#if (voice_en==1)
						if(voice_value)
						{
							vice_addr(Cbuf1);
							if(Lbuf0 && M_GM_data!=0)
							{									
						  		voice_AVGBlood_glucose(M_GM_data);
							}
						  	else
						  	{	
						  		vice_addr(0x28);//无测量???录
						  	}
																       							
						}			    											
#endif			
				//	}
//					else                     // no record in range
//					{
//						//--- display "---"
//						Show_BigString( "---" ) ;
//						//Lcd_Display_dash();
//					}
//					
					//--- Lcd update
					F_LcdUpdate =1;	
				}
			
		

			

	    	//---------------------------------
			//--- check P_M_KEY ---
			//--- long key 3sec into "main menu"
			//--- short key 	into "memory mode"	 
      	    if(memkey==1)
      	    {
       			//setkey=0;
       			//setkeydown=0;
       			memkey=0;
       			M_No_Active_Cnt=0;
						//--- next reord
				F_read_eeprom =1; 	
				M_Cbuf0++;	
				#if 1
				if(M_Cbuf0 > 5)
				{
//					//--- into memory mode
//					M_TaskBuf0 =3;
//					M_TaskBuf1 =0;
//					M_Error_Task =0;
//					M_RTC_display =0;
//					M_No_Active_Cnt = 0;
//					
//					//--- Lcd All off
//					LCD_Clear(OFF);
//					
//					//--- read record
//					F_read_eeprom =1;
//					M_GM_data_Record_buf = 	M_GM_Record_current;
//					M_Ibuf0 =1;

					setkey=0;	
				    M_RTC_display = 0;
					M_No_Active_Cnt = 0;
					M_Task = C_OffMode;
					M_TaskBuf0 =0;			
					M_TaskBuf1 =0;
				    M_Error_Task =0;
				    F_Beep_Shortx1 =1;
		
			     	//--- display all off
			     	LCD_Clear(OFF);
				}
				#endif
				F_Beep_Shortx1 =1;
	    	
      	    }   		    
		    	
		    //----------------------------------
		    //--- check P_S_KEY ----
		    //--- into RTCModeSettingMode
	    	if(memkey==2)
	    	{
				memkey=0;	
			    M_RTC_display = 0;
				M_No_Active_Cnt = 0;
				M_Task = C_OffMode;
				M_TaskBuf0 =0;			
				M_TaskBuf1 =0;
			    M_Error_Task =0;
			    F_Beep_Shortx1 =1;
	
		     	//--- display all off
		     	LCD_Clear(OFF);		    
	    	}			
			   		


			
			break;
			
		}
	
     case mem_memdelete:
	{
		// --- check strip insert
		if(blood_strips_pin4 == 0)
		{
			M_Strip_Type = glucose_Type;
			M_Task = C_NormalMode;
			M_TaskBuf0 = 0;
			M_TaskBuf1 = 0;
			M_RTC_display = 0;
			M_No_Active_Cnt = 0;

			//--- Lcd All off
			LCD_Clear(OFF);
			break;
		}

		switch (M_TaskBuf1)
		{
			case 0:
			{
			    M_RTC_display++;
			    if(M_RTC_display % 100 == 1)
				{
					//--- display "DEL"
					Show_BigString( "DEL" ) ;
					//Lcd_Display_DEL();
					//--- display "Mem"
					lcd.mem.Bit.Memory = 1;

					F_LcdUpdate = 1;
				}
			    else if(M_RTC_display % 100 == 50)
			    {
					//--- display "Mem"
					lcd.mem.Bit.Memory =0;

					F_LcdUpdate = 1;
			    }
			    else if (M_RTC_display >= 300)
			    {
			    	M_TaskBuf0 = mem_out;
					M_RTC_display = 0;
			    }

	      	    if (setkeydown)
	      	    {
					//--- into next task
					M_TaskBuf1 =1;
					M_Error_Task =0;
					M_RTC_display =0;
					M_No_Active_Cnt = 0;

		      		//---Lcd All off
		      		LCD_Clear(OFF);

					//--- Lcd update flag clear
					F_LcdUpdate =0;
					F_500ms_LCD =0;
					F_Beep_Shortx1 =1;

					setkeydown = 0;
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

			    if (M_RTC_display == 1)
			    {
			    	M_GM_data_Record = 0;
			    	M_GM_Record_current = 0;

					//--- Svav system vaule to flash
					Store_SetVauletoFlash();

					set_temp_25 = 0;
					Write_EEPROMBuf(C_EEP_FactoryMode_Adr, (unsigned char*)&set_temp_25, 1);
			    }
			    else if (M_RTC_display >= 100) //time base 10ms
			    {
					M_TaskBuf0 = mem_out;
					M_RTC_display = 0;
			    }
				break;
			}
		}
		break;
	}
		//---------------------------------

		
	  	//--- Error task ----
	  	case mem_err:
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
			
	  		M_RTC_display++;	  		
	  		if((F_Low_battery_Act==0 && M_RTC_display > 300) || (F_Low_battery_Act && M_RTC_display > 50) )
	  		{
//
//			    M_RTC_display = 0;
//				M_No_Active_Cnt = 0;
//				M_Task = C_OffMode;
//				M_TaskBuf0 =0;			
//				M_TaskBuf1 =0;
//			    //F_Beep_Shortx1 =1;
//			    M_Error_Task =0;
//			    //--- Lcd All off
//			    LCD_Clear(OFF);
//				M_ErrorCount=0;//time start

			    M_TaskBuf0 = mem_out;
	  			
	  		}

			break; 
	  	}
	  	case mem_out:	
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
//			--- check strip insert	
//	if(blood_strips_pin4==0)
//	{
//		//--- Strip check
//		M_Strip_Type =1;
//		M_Task = C_NormalMode;
//    	M_TaskBuf0=0;	
//	    M_TaskBuf1 =0;
//	    M_RTC_display =0;
//	    M_No_Active_Cnt=0;	    			
//        
//		//--- Lcd All off
//		LCD_Clear(OFF);
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
	
//----------------------------------------------------					
	
	
	
	
}

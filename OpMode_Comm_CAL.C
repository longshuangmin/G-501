#include "include.h" 
#define CALIB_BY_KEY 0
enum {
	bd_idle=0,
    bd_send_sys,
    bd_OAG_2V0,	
    bd_OAG_0V35,
    bd_OAG_0V6,	
    bd_res_HI,
    bd_temptrue,
    bd_ck_impedance,
	bd_save_sys,
    bd_sleep_Current,	
    bd_over,
    err_mode,
	bd_out,	
}bdmode;


void uart_order()
{	 
	volatile	unsigned int  Ibuf0; 		
	if(M_UART_RxIndex>0)
	{
		if(M_UART_RxFIFO[0]!=0xAA)
		{
			M_UART_RxIndex=0;
		}
		else
		{
			if(M_UART_RxIndex>2 && M_UART_RxIndex >=M_UART_RxFIFO[1])
			{

		  		Ibuf0=0;							       	
	  			for(mi=0;mi<M_UART_RxFIFO[1]-2;mi++)
	  			    Ibuf0+=M_UART_RxFIFO[mi];
	  			if(Ibuf0 !=0 && Ibuf0%256 == M_UART_RxFIFO[M_UART_RxFIFO[1]-2] && Ibuf0/256 == M_UART_RxFIFO[M_UART_RxFIFO[1]-1])    
		  		{	   								

		  		}
		  		else
		  		{
		  			M_UART_RxFIFO[2]=0xee;
		  		}
				uar_en=1;
				_emi=0;

					
		    } 				
			
		}
		
		
	}	  		
}
#if (CALIB_BY_KEY==1)
unsigned char Set_Mode=0;
void CalibByKey(void)
{
	if(setkey||memkey)
	{
		if(Set_Mode ==0)
		{	
			memkey = 0;
			setkey = 0;
			Set_Mode = 1;//
			
			LCD_Clear(OFF);
			Show_BigString( "PC2"  ) ;
			F_LcdUpdate =1;	
		}
	}
	if(setkey == 1)
	{
		setkey = 0;
		if(Set_Mode ==1) //AA 06 01 02 00 00   2V+
		{
			memset((unsigned char *)M_UART_RxFIFO,0,sizeof(M_UART_RxFIFO));
			M_UART_RxFIFO[0] = 0xAA;
			M_UART_RxFIFO[1] = 0x06;
			M_UART_RxFIFO[2] = 0x02;
			M_UART_RxFIFO[3] = 0x02;
			M_UART_RxFIFO[4] = 0x00;
			M_UART_RxFIFO[5] = 0x00;
			uar_en = 1;
		}
		else if(Set_Mode ==2) //AA 06 02 02 00 00   0.35V+
		{
			memset((unsigned char *)M_UART_RxFIFO,0,sizeof(M_UART_RxFIFO));
			M_UART_RxFIFO[0] = 0xAA;
			M_UART_RxFIFO[1] = 0x06;
			M_UART_RxFIFO[2] = 0x03;
			M_UART_RxFIFO[3] = 0x02;
			M_UART_RxFIFO[4] = 0x00;
			M_UART_RxFIFO[5] = 0x00;
			uar_en = 1;
		}
		
	}
	else if(memkey == 1)
	{
		memkey = 0;
		if(Set_Mode ==1) //AA 06 01 01 00 00   2V-
		{
			memset((unsigned char *)M_UART_RxFIFO,0,sizeof(M_UART_RxFIFO));
			M_UART_RxFIFO[0] = 0xAA;
			M_UART_RxFIFO[1] = 0x06;
			M_UART_RxFIFO[2] = 0x02;
			M_UART_RxFIFO[3] = 0x01;
			M_UART_RxFIFO[4] = 0x00;
			M_UART_RxFIFO[5] = 0x00;
			uar_en = 1;
		}
		else if(Set_Mode ==2) //AA 06 02 01 00 00   0.35V-
		{
			memset((unsigned char *)M_UART_RxFIFO,0,sizeof(M_UART_RxFIFO));
			M_UART_RxFIFO[0] = 0xAA;
			M_UART_RxFIFO[1] = 0x06;
			M_UART_RxFIFO[2] = 0x03;
			M_UART_RxFIFO[3] = 0x01;
			M_UART_RxFIFO[4] = 0x00;
			M_UART_RxFIFO[5] = 0x00;
			uar_en = 1;
		}
	}
	else  if(memkey == 2)
	{
		memkey = 0;
		LCD_Clear(OFF);
		if(Set_Mode ==1)
		{
			Set_Mode =2;
			Show_BigString( "PC4"  ) ;
		}
		//else if(Set_Mode ==2)
		//{
		//	Set_Mode =3;
		//	Show_BigString( "PCC"  ) ;
		//}
		else if(Set_Mode ==2)
		{
			Set_Mode =1;
			Show_BigString( "PC2"  ) ;
		}
		F_LcdUpdate =1;	
		memset((unsigned char *)M_UART_RxFIFO,0,sizeof(M_UART_RxFIFO)); //AA 01 06  save data
		M_UART_RxFIFO[0] = 0xAA;
		M_UART_RxFIFO[1] = 0x01;
		M_UART_RxFIFO[2] = 0x08;
		M_UART_RxFIFO[3] = 0x00;
		M_UART_RxFIFO[4] = 0x00;
		M_UART_RxFIFO[5] = 0x00;
		uar_en = 1;
	}
	else  if(setkey == 2)//CLEAR EEPRO
	{
		setkey =0;
		if(Set_Mode ==3)
		{
			//M_UART_RxFIFO[0] = 0xAA;
			//M_UART_RxFIFO[1] = 0x01;
			//M_UART_RxFIFO[2] = 0x08;
			//M_UART_RxFIFO[3] = 0x00;
			//M_UART_RxFIFO[4] = 0x00;
			//M_UART_RxFIFO[5] = 0x00;
			uar_en = 1;
		}

	}
}
#endif

void TestingMode (void)
{
//	unsigned char buf[8];
	unsigned char Cbuf0;
	unsigned int  Ibuf0;
	//volatile unsigned long  Lbuf0;
	
	switch(M_TaskBuf0)
	{
		case 0:
		{
//			if(F_Low_battery_Act ==0)
 	  		{
 	  			
				_pac3 =0;//
				_pa3 =0;//
				
  				_pac3 =1;//
				_papu3 =0;
  				_pac4 =0;//
  				_pa4 =0;//
				_papu4 =0;										    
		//	    set_code_intput_nopapu();				
				
					  			
 	  			Load_VrefDaco_Vaule() ;
#if (CALIB_BY_KEY==1)				
 	  		//---------calbykey-------------------
			Calibration.CAL.k_value=1.0;
			Calibration.CAL.temp_offset=0;
			_pvref = C_PVREF_FINETURN;
			//--- set daco
			_afeda1l = C_DAC_350_L;
			_afeda1h = C_DAC_350_H;		
#endif
			//-----------------------------	
			Calibration.CAL.pvref_2_0V=_pvref;
			
			Calibration.CAL.afeda1_0_35V=_afeda1h;
			Calibration.CAL.afeda1_0_35V*=256;
			Calibration.CAL.afeda1_0_35V+=_afeda1l;
			Calibration.CAL.afeda1_0_35V>>=4;
			
			
			Calibration.CAL.afeda1_0_6V=Calibration.CAL.afeda1_0_35V+10;


			//--- set daco

 	  			//
				//--- initial uart0
				fun_UART0PowerOnInit();
				
	            //--- Dacvref Enable		        
    			fun_DACVREFInit(POWERON);
		        //--- Daco1 Enable
		        fun_DACnInit(1,DACnOEnable);
				
//				//--- Init OPA1
//				Initnal_OPA1_Gpio(1);
//				//--- Init OPA2
//				Initnal_OPA2_Gpio(1);
				//--- Init OPA2
//				//--- initial uart0
//				fun_UART0PowerOnInit();

				//--- opa calibration offset
				fun_CalOPA1Offset();
				fun_CalOPA2Offset();
				fun_CalOPA3Offset();
				
	            //--- Dacvref Enable		        
    			fun_DACVREFInit(POWERON);
		        //--- Daco1 Enable
		        fun_DACnInit(1,DACnOEnable);
//				//--- Init OPA1
//				Initnal_OPA1_Gpio(1);
//				//--- Init OPA2
//				Initnal_OPA2_Gpio(0);
				
				LCD_Clear(OFF);
				
				LCD_Clear(OFF);
				
				SET_PIN_OP1N2_OPEN();
				
			    SET_PIN_OP1N1_OP1N();
			    SET_PIN_OP1S0_OP1O();
			    SET_PIN_OPnP_DAC1O(1);
			    Measurement_Op1n1_Op1s1();//DC

			    
			    SET_OPAn_POWER(1,POWERON);
				
				
			//	m_pvref=_pvref;
				
				M_TaskBuf1 =0;
				M_Cbuf0 =0;
				M_RTC_display =0;
				M_No_Active_Cnt =0;
				
				memkey=0;
				setkey=0;				
				uar_en=0;
				test_mode=0;
					M_TaskBuf0++;			
	            //--- Beep ON
	            F_Beep_Shortx1 =1;
	            uar_en=1;
	            								
				//M_Unit=0;											
				memset((unsigned char *)&lcd,0,sizeof(lcd));
				Show_BigString( "P20"  ) ;
				Lcd_Clock_Process(Calibration.CAL.pvref_2_0V/100,Calibration.CAL.pvref_2_0V%100);
				F_LcdUpdate =1;	
//	F_LcdUpdate =1;	
 	  		}

 	  							
			break;
		}
		
		case 1:
		{	
  		    uart_order();
			#if (CALIB_BY_KEY==1)	
			CalibByKey();
			#endif
  		    if(uar_en)
  		    {
  		    	M_No_Active_Cnt=0;
			    switch(M_UART_RxFIFO[2])
			    {
					case bd_send_sys://get  CAL_Serial_number
						{
					       	Cbuf0 =0;
				  			M_UART_TxFIFO[Cbuf0++] = 0x55;
				  			M_UART_TxFIFO[Cbuf0++] = 7;
							
							for(mi=0;mi<9;mi++)
								Calibration.CAL.Serial_number[mi]=M_UART_RxFIFO[3+mi];						  		
				  			
				  			M_UART_TxFIFO[Cbuf0++] = M_UART_RxFIFO[2];
						}
						break;
						
					case bd_OAG_2V0://2.00v						
						{
							if(M_UART_RxFIFO[3]==1)
							{	
								Calibration.CAL.pvref_2_0V++;							
							}
							
							if(M_UART_RxFIFO[3]==2)
							{	
								Calibration.CAL.pvref_2_0V--;				
							}
						    _pvref=Calibration.CAL.pvref_2_0V;			
														
							M_Unit=0;											
							memset((unsigned char *)&lcd,0,sizeof(lcd));
							Show_BigString( "P20"  ) ;
							Lcd_Clock_Process(Calibration.CAL.pvref_2_0V/100,Calibration.CAL.pvref_2_0V%100);
						//		updata_lcd( );	
							F_LcdUpdate =1;	
							
							Cbuf0 =0;
							M_UART_TxFIFO[Cbuf0++] = 0x55;
							M_UART_TxFIFO[Cbuf0++] = 0x07;
							
							M_UART_TxFIFO[Cbuf0++] = M_UART_RxFIFO[2];
							
							M_UART_TxFIFO[Cbuf0++] =  _pvref;
							M_UART_TxFIFO[Cbuf0++]   = 0;
							
							M_UART_TxFIFO[Cbuf0++]   = 0;								
							M_UART_TxFIFO[Cbuf0++]   = 0;
							
							
																	
							break;
						}
						
						case bd_OAG_0V35://0.4v
							{
							
								if(M_UART_RxFIFO[3]==1)
								{							
									Calibration.CAL.afeda1_0_35V--;							
								}
								
								if(M_UART_RxFIFO[3]==2)
								{						
								    Calibration.CAL.afeda1_0_35V++;
								}
								
								Ibuf0=Calibration.CAL.afeda1_0_35V<<4;				
								_afeda1l = Ibuf0%256;
								_afeda1h = Ibuf0/256;
								Calibration.CAL.afeda1_0_6V=Calibration.CAL.afeda1_0_35V;				
								Calibration.CAL.afeda1_0_6V+=Calibration.CAL.afeda1_0_35V>>1;									

								M_Unit=0;

								memset((unsigned char *)&lcd,0,sizeof(lcd));
								Show_BigString( "P04"  ) ;
								Lcd_Clock_Process(Calibration.CAL.afeda1_0_35V/100,Calibration.CAL.afeda1_0_35V%100);
							
								F_LcdUpdate =1;	
																
								Cbuf0 =0;
								M_UART_TxFIFO[Cbuf0++] = 0x55;
								M_UART_TxFIFO[Cbuf0++] = 0x07;
								M_UART_TxFIFO[Cbuf0++] = M_UART_RxFIFO[2];
								M_UART_TxFIFO[Cbuf0++] = Calibration.CAL.afeda1_0_35V;
								M_UART_TxFIFO[Cbuf0++] = Calibration.CAL.afeda1_0_35V>>8;
								M_UART_TxFIFO[Cbuf0++] = 0;								
								M_UART_TxFIFO[Cbuf0++] = 0;
																	
								break;						
							
							}
							
						case bd_OAG_0V6://0.6v
							{
							
								if(M_UART_RxFIFO[3]==1)
								{							
									Calibration.CAL.afeda1_0_6V--;							
								}
								
								if(M_UART_RxFIFO[3]==2)
								{						
								    Calibration.CAL.afeda1_0_6V++;
								}
								
								Ibuf0=Calibration.CAL.afeda1_0_6V<<4;				
								_afeda1l = Ibuf0%256;
								_afeda1h = Ibuf0/256;
									

								M_Unit=0;

								memset((unsigned char *)&lcd,0,sizeof(lcd));
								Show_BigString( "P06"  ) ;
								Lcd_Clock_Process(Calibration.CAL.afeda1_0_6V/100,Calibration.CAL.afeda1_0_6V%100);
							
								F_LcdUpdate =1;	
																
								Cbuf0 =0;
								M_UART_TxFIFO[Cbuf0++] = 0x55;
								M_UART_TxFIFO[Cbuf0++] = 0x07;
								M_UART_TxFIFO[Cbuf0++] = M_UART_RxFIFO[2];
								M_UART_TxFIFO[Cbuf0++] = Ibuf0=Calibration.CAL.afeda1_0_6V;
								M_UART_TxFIFO[Cbuf0++] = Ibuf0=Calibration.CAL.afeda1_0_6V>>8;
								M_UART_TxFIFO[Cbuf0++] = 0;								
								M_UART_TxFIFO[Cbuf0++] = 0;
																	
								break;						
							
							}							
							
							
						case bd_res_HI://read AD
							{					  			
								switch(test_mode)
								{
								  	case 0://这里不清除缓冲数据，就会重复收到 uar_en=1；
								  		{
											auto_code=M_UART_RxFIFO[4];
											auto_code<<=8;
											auto_code+=M_UART_RxFIFO[3];
//									  		Ibuf0=M_UART_RxFIFO[4];
//									  		Ibuf0*=256;
//									  		Ibuf0+=M_UART_RxFIFO[3];
									  		_emi=1;																  	
								  		//	Load_VrefDaco_Vaule() ;
								  			//
											//--- initial uart0
											Ibuf0=Calibration.CAL.afeda1_0_35V<<4;				
											_afeda1l = Ibuf0%256;
											_afeda1h = Ibuf0/256;											
											
											fun_UART0PowerOnInit();
											
								            //--- Dacvref Enable		        
											fun_DACVREFInit(POWERON);
									        //--- Daco1 Enable
									        fun_DACnInit(1,DACnOEnable);
											
								//				//--- Init OPA1
								//				Initnal_OPA1_Gpio(1);
								//				//--- Init OPA2
								//				Initnal_OPA2_Gpio(1);
											//--- Init OPA2
								//				//--- initial uart0
								//				fun_UART0PowerOnInit();
								
											//--- opa calibration offset
											fun_CalOPA1Offset();
											fun_CalOPA2Offset();
											fun_CalOPA3Offset();
											
								            //--- Dacvref Enable		        
											fun_DACVREFInit(POWERON);
									        //--- Daco1 Enable
									        fun_DACnInit(1,DACnOEnable);	  		
								
								  		
											fun_ADCStop();
											SET_SINE_OFF();
											SET_OPA34_POWER(POWEROFF);
											fun_StripModuleAllOpen();
											SET_PIN_OPnP_OPEN(1);
											SET_PIN_OPnP_OPEN(2);
											SET_PIN_OP3P_OPEN();
											SET_PIN_RF1_OPEN();
											SET_PIN_SINI_OPEN();
											
											//---
											strips_pin4_dir =1;//血糖试纸侦测脚设置输入
											up_pin4 =0;//上接使能
											
											_papu3 =0;
											
//											strips_pin8_dir=1;//in--strips pin8
//											up_pin8=0;
//											strips_pin8=0;
//											
//											strips_pin7_dir=1;//in--strips pin7
//											up_pin7=0;
//											strips_pin7=0;
//											
//											
//											strips_pin6_dir=1;//in--strips pin6
//											up_pin6=0;
//											strips_pin6=0;	
											
								//				fun_CalOPA1Offset();
								//				fun_CalOPA2Offset();
								//				fun_CalOPA3Offset();			
								//			
																	
											
											InitADC_Op1n1_Op1s1();
											//--- set vg0
											SET_PIN_VG0_GND();
											//--- Start adc
											fun_ADCStart();	
											//--- set vg0
											SET_PIN_VG0_GND();
											SET_PIN_VG1_GND();
								//		GCC_DELAY(1000);			
											
												            //--- Beep ON
									//        F_Beep_Shortx1 =1;	
										//	M_TaskBuf0=5;								
											test_mode++;
											uar_en=0;	//不发送
											imp=0;
											break;	
										}									
							
																											
									case 1:
									  	{
									  		uar_en=0;	//不发送
									  		_emi=1;	
									  		while(1)
									  		{
									  			GCC_CLRWDT();
												if(SDKADCSourceData.flag.b.IsReady)//---给个采样缓冲
												{
													DC_data_buf[imp%64]= SDKADCSourceData.data.ADCData >> 16;
													imp++;
													if(imp>200)
													{
													    imp=0;						   
													   	mi=0;
													   		
													 // fun_ADCStop();
													//	M_TaskBuf0++;
													    test_mode++;
													  
														break;						   
													}
													SDKADCSourceData.flag.b.IsReady=0;
											      								
												}
									  		}
																		      	
									  	break;
									  	}								
									case 2:
									  	{
										   	mi=0;
										    M_Impedance_buf[0]=0;
										    for(mi=0;mi<64;mi++)
										       M_Impedance_buf[0]+=DC_data_buf[mi];						
											M_Impedance_buf[0] /= 64;
											Calibration.CAL.CAL_AD=M_Impedance_buf[0];																							
				

											Calibration.CAL.k_value=M_Impedance_buf[0]/auto_code;//=68K/24.29k	
																
								  			Cbuf0 =0;
								  			M_UART_TxFIFO[Cbuf0++] = 0x55;
								  			M_UART_TxFIFO[Cbuf0++] = 0x09;
								  			M_UART_TxFIFO[Cbuf0++] = M_UART_RxFIFO[2];
								  			
								  			Ibuf0=Calibration.CAL.k_value*1000;
								  			
								  			M_UART_TxFIFO[Cbuf0++]   = Ibuf0%256;
								  			M_UART_TxFIFO[Cbuf0++]   = Ibuf0/256;
								  			
											M_UART_TxFIFO[Cbuf0++]   = Calibration.CAL.CAL_AD%256;								
											M_UART_TxFIFO[Cbuf0++]   = Calibration.CAL.CAL_AD/256;
											
											M_UART_TxFIFO[Cbuf0++]   = 0;								
											M_UART_TxFIFO[Cbuf0++]   = 0;											
																			  				
								  			
												
												_emi=1;	
											Lcd_Clock_Process(Ibuf0/100,Ibuf0%100);
												F_LcdUpdate =1;		  		
									
										    break;							      	
							
								    	}				
									
								}
							 	break;								
							}							
													
									    
						case bd_temptrue://read Temp_oC
							{	
								
								M_Temperature = Measurement_Temp();	
						  		LCD_Clear_Buff(OFF) ;								
								Lcd_Clock_Process(M_Temperature/100,M_Temperature%100);	
																				
					  			Cbuf0 =0;
					  			M_UART_TxFIFO[Cbuf0++] = 0x55;
					  			M_UART_TxFIFO[Cbuf0++] = 7;
					  			
					  			M_UART_TxFIFO[Cbuf0++] = M_UART_RxFIFO[2];
					  			#if (NO_TEMPER_CORR==0)
					  			M_UART_TxFIFO[Cbuf0++] = M_Temperature%256;
					  			M_UART_TxFIFO[Cbuf0++] = M_Temperature/256;
					  			#else
								M_UART_TxFIFO[Cbuf0++] = M_UART_RxFIFO[3];
								M_UART_TxFIFO[Cbuf0++] = M_UART_RxFIFO[4];
								#endif
								M_UART_TxFIFO[Cbuf0++]   = 0;								
								M_UART_TxFIFO[Cbuf0++]   = 0;
								
						  		avg_ad=M_UART_RxFIFO[4];
						  		avg_ad*=256;
						  		avg_ad+=M_UART_RxFIFO[3];
						  		
						  		avg_ad2=M_Temperature;	
						  							  		
						  		Calibration.CAL.temp_offset=avg_ad2-avg_ad;
						  		
						  		
								M_Temperature = Measurement_Temp();
													  		
								if(Calibration.CAL.temp_offset>0)
								  	M_Temperature-=	Calibration.CAL.temp_offset;	  			
								else
								    M_Temperature+= abs(Calibration.CAL.temp_offset);						  		
						  								  		
						  		Ibuf0 = M_Temperature;						  		
						  		
						  		ShowDec_BigNum(Ibuf0);						  								  		
						  		lcd.meas.Bit.BigNum_DP =1;
						  		
						  		
						  		
						  		_emi=1;	
						  		F_LcdUpdate =1;
						  		

						  							  			
						    	break;					  									
							} 						
						
						case bd_ck_impedance://read z
							{	
								
							    intit_Impedance();	
							    up_pin4 =1;//血糠试纸插入脚拉?	
							    SET_PIN_VG1_GND();						
								M_Cbuf0 =0;	
								imp=0;
								Set_HCT_Adc_Channel(M_Cbuf0);
														
								//--- AC量測+取阻抗 
								while(1)
								{
									GCC_CLRWDT();
									if(SDKADCSourceData.flag.b.IsReady)
									{
										SDKADCSourceData.flag.b.IsReady =0;
										//---												
										M_Impedance_data[imp++] = SDKADCSourceData.data.ADCData >> 16;
						
										M_Cbuf0++;
										if(M_Cbuf0 >3)	
										{
											M_Cbuf0 =0;	
									//		work_time_buf[count++]=work_time;//记录时间
									//		work_time=0;
											
				//							M_Impedance = Impedance_Compute(&M_Impedance_data[0]);//---------------------Impedance	
				//						    M_Lbuf0 = M_Impedance * 1000;
				//						    _emi=0;
				//							print_bcd2(M_Lbuf0);
				//							print_str("\r\n");	
				//							_emi=1;														
				//							imp=0;	
											break;
				
											
										//	GPIO_led=~GPIO_led;//_pd6----test time--about 160ms						  
										}		
										Set_HCT_Adc_Channel(M_Cbuf0);
										    
									}
								
								}
								
								M_Impedance = Impedance_Compute((signed int *)&M_Impedance_data[0]);//---------------------Impedance								
					  			Cbuf0 =0;
					  			M_UART_TxFIFO[Cbuf0++] = 0x55;
					  			M_UART_TxFIFO[Cbuf0++] = 7;
					  			M_UART_TxFIFO[Cbuf0++] = M_UART_RxFIFO[2];
					  			M_Lbuf0 = M_Impedance * 1000;
					  			M_UART_TxFIFO[Cbuf0++] = M_Lbuf0 % 256;
					  			M_UART_TxFIFO[Cbuf0++] = M_Lbuf0 / 256;
					  			
								M_UART_TxFIFO[Cbuf0++]   = 0;								
								M_UART_TxFIFO[Cbuf0++]   = 0;
																					
								_emi=1;
										

							    break;					  		
							
							}
						case bd_save_sys://save data
							{	
								

														
								Calibration.CAL.CH_SUM=0;
								for(imp=0;imp<sizeof(Calibration.bytes)-2;imp++)
								{
									Calibration.CAL.CH_SUM+=Calibration.bytes[imp];
								}
								
								Write_EEPROMBuf(0, (unsigned char *)&Calibration.bytes, sizeof(Calibration.bytes));
								Write_EEPROMBuf(0x20, (unsigned char *)&Calibration.bytes, sizeof(Calibration.bytes));//back
								set_temp_25=0x55;
								Write_EEPROMBuf(C_EEP_FactoryMode_Adr,(unsigned char*)&set_temp_25,1);
								memset((unsigned char *)&Calibration.bytes,0,sizeof(Calibration.bytes));
								Read_EEPROMBuf(0x20, (unsigned char *)&Calibration.bytes, sizeof(Calibration.bytes))	;
								
					  			Cbuf0 =0;
					  			M_UART_TxFIFO[Cbuf0++] = 0x55;
					  			M_UART_TxFIFO[Cbuf0++] = 3+sizeof(Calibration.bytes);
					  			M_UART_TxFIFO[Cbuf0++] = M_UART_RxFIFO[2];
					  			
					  			for(mi=0;mi<sizeof(Calibration.bytes);mi++)//copy
					  				M_UART_TxFIFO[Cbuf0++] = Calibration.bytes[mi];
					  			
								M_UART_TxFIFO[Cbuf0++]   = 0;								
								M_UART_TxFIFO[Cbuf0++]   = 0;
																			
								_emi=1;							

							    break;					  		
							
							} 
							
						case bd_sleep_Current://get  CAL_Serial_number
						    {
					  			Cbuf0 =0;
					  			M_UART_TxFIFO[Cbuf0++] = 0x55;
					  			M_UART_TxFIFO[Cbuf0++] = 7;
					  			M_UART_TxFIFO[Cbuf0++] = M_UART_RxFIFO[2];
					  			M_UART_TxFIFO[Cbuf0++] = 0;
					  			M_UART_TxFIFO[Cbuf0++] = 0;
					  			
								M_UART_TxFIFO[Cbuf0++]   = 0;								
								M_UART_TxFIFO[Cbuf0++]   = 0;						    
						    
								_papu1=1;			 				
								M_Task = C_OffMode;
								M_TaskBuf0 =0;			
								M_TaskBuf1 =0;
							    //F_Beep_Shortx1 =1;
							    M_Error_Task =0;
							    //--- Lcd All off
							    LCD_Clear(OFF);
							    M_Unit=M_Unit | 0x01;//mmol
									_emi=1;				
						    }
							break;
						case 0xee://get  CAL_Serial_number
						   { 
					  			Cbuf0 =0;
					  			M_UART_TxFIFO[Cbuf0++] = 0x55;
					  			M_UART_TxFIFO[Cbuf0++] = 7;
					  			M_UART_TxFIFO[Cbuf0++] = M_UART_RxFIFO[2];
					  			M_UART_TxFIFO[Cbuf0++] = 0;
					  			M_UART_TxFIFO[Cbuf0++] = 0;
					  			
								M_UART_TxFIFO[Cbuf0++]   = 0;								
								M_UART_TxFIFO[Cbuf0++]   = 0;
									_emi=1;							    
	
						   }
							break;														

			    }
			    
				if(uar_en)
				{
						_emi=1;	
					test_mode=0;
		  			Ibuf0=0;//sum
		  			for(mi=0;mi<M_UART_TxFIFO[1]-2;mi++)
		  			    Ibuf0+=M_UART_TxFIFO[mi];
		  			M_UART_TxFIFO[M_UART_TxFIFO[1]-2]   = Ibuf0%256;    																
					M_UART_TxFIFO[M_UART_TxFIFO[1]-1]   = Ibuf0/256;  
					
					M_UART_TxLength =M_UART_TxFIFO[1];//长度
					M_UART_TxIndex =0;
					_txr_rxr0= M_UART_TxFIFO[0];		  		    	
    	
					M_UART_RxIndex=0;
					memset((unsigned char *)&M_UART_RxFIFO,0,128);						
					uar_en=0;						
			
					
				}			    

		    }
			break;
		}
	}
	M_No_Active_Cnt++;
	if(M_No_Active_Cnt >= 6000)	      //base time 31.25ms =>120 sec
	{
		M_No_Active_Cnt = 0;
		M_Task = C_OffMode;           //quit TestingMode
		M_TaskBuf0 =0;
		M_TaskBuf1 =0;
		M_RTC_display = 0;    

	
	}	
	
}


//-------------------------------------------------------------------------- 
void Error_meassage_process (void)
{
	if(M_Error_Task !=0)
	{
	//	M_ErrorCount ++;
	//	F_LcdUpdate =1;
		switch(M_Error_Task)
		{
			
		 case 1:
				//--- display "E"
				lcd.BigNum[0] = charTab['E'] ;	
				//--- display "-"	
				lcd.BigNum[1] = charTab['-'] ;	
				lcd.BigNum[2] = charTab['U'] ;	 
		 
		 	break;	
			
		 case 2:
		 		Show_BigString( "L-b" ) ;
		 
		 	break;				
			
		 case 3:
				//--- display "E"
				lcd.BigNum[0] = charTab['E'] ;	
				//--- display "-"	
				lcd.BigNum[1] = charTab['-'] ;			 
		 		lcd.BigNum[2] = charTab['3'] ;
		 	break;	
		 	
		 case 4:
				//--- display "E"
				lcd.BigNum[0] = charTab['E'] ;	
				//--- display "-"	
				lcd.BigNum[1] = charTab['-'] ;			 
					//--- display "t"
					lcd.BigNum[2] = charTab['t'] ;
		 	break;		 	
		 case 5:
				//--- display "E"
				lcd.BigNum[0] = charTab['E'] ;	
				//--- display "-"	
				lcd.BigNum[1] = charTab['-'] ;			 
					//--- display "t"
				lcd.BigNum[2] = charTab['5'] ;		 

		 	break;	
		 	
		 case 6:
				Show_BigString( "E-b" ) ;
		 	break;	
		 	
		 case 7:
				//--- display "E"
				lcd.BigNum[0] = charTab['E'] ;	
				//--- display "-"	
				lcd.BigNum[1] = charTab['-'] ;
				lcd.BigNum[2] = charTab['C'] ;	
				
		 	break;			 			 			 				
			
		}
	}
}
		
		
		

#include "include.h"

#include <string.h>
#if 0


#if defined(lanhang)
	const unsigned	char  OPEN_URL[]="http://gray.gongwei666.cn/api/ch/data/sugar/v2/upload?data=";//lan-han				
#elif defined(hefa)
	const unsigned	char  OPEN_URL[]="http://www.lianuoy.com/hefa/api/devices/data/bioland/bs?data=";//合发医疗
#else
	const unsigned	char  OPEN_URL[]="http://tf.ydjk5.com/gprs/receive/api/data?data="; //云渡健康 查看后台数据网址 http://tf.ydjk5.com/vivedateListBioland.html#

#endif



struct gsm_data_st
{
	const char* at;         		  
	const char  repeap_time;	       
	const char  delay_time;
	const char* back_ok;
	const char* back_err;
};


void testlcd()
{
    		
				//--- display Month & Day
				//Lcd_Month_Day_Process(M_Month,M_Days);
				//--- display Hour & Minutes
				//Lcd_Clock_Process(M_Hour,M_Minutes);
				#if 0
    		   // _emi = 0;
				//--- display Month & Day
				//Lcd_Month_Day_Process1(12,19);
				//--- display Hour & Minutes
				//Lcd_Clock_Process(10,42);
				//_emi = 1;
				#endif
					
				lcd.unit.Bit.TimeColon =~lcd.unit.Bit.TimeColon ;



//				 if(lcd.send.Bit.OK==0 && lcd.send.Bit.Fail==0)
//				 {
//				   lcd.send.Bit.Ing=~lcd.send.Bit.Ing;	
//				 }
//				 else
//				   lcd.send.Bit.Ing=0;



				lcd.ant.Bit.Ant=~lcd.ant.Bit.Ant;                 
                lcd.ant.Byte&=1;          	               					
				if(lcd.ant.Bit.Ant)
				{
  
					setRssi();			  

				}					
			    LCD_ScanOut();	
					
	
	
}


//const struct  gsm_data_st s1[] = 
// {
//
// 	{"AT+CPIN?\r\n", 30,20,"OK","ERROR"},
// 	{"AT+CIMI\r\n", 3,20,"OK","ERROR"},
// 	{"AT+CGSN\r\n", 3,20,"OK","ERROR"},
// 	{"AT+QHTTPCFG=\"contextid\",1\r\n", 3,20,"OK","ERROR"}, 	
// 	{"AT+QHTTPCFG=\"requestheader\",0\r\n", 3,20,"OK","ERROR"},
// 	{"AT+QICSGP=1,1,\"CMNET\",\"\",\"\",0\r\n", 3,20,"OK","ERROR"}, 	
//  	{"AT+QIACT=1\r\n", 2,30,"OK","ERROR"},
// 	{"AT+QIACT?\r\n", 2,20,"OK","ERROR"},
// 	{"AT+CREG?;+CEREG?;+CGREG?\r\n", 30,20,"OK","ERROR"}, 
// 	{"AT+COPS?\r\n", 2,20,"OK","ERROR"},
// 	{"AT+QNWINFO\r\n", 2,20,"OK","ERROR"},
// 	{"AT+CSQ\r\n", 40,20,"OK","ERROR"},	
//	
//	
// 	
// };
unsigned char HEX_TO_Char(unsigned char Hex)
{
	switch(Hex)
	{
		case	0x00:	return	'0';
		case	0x01:	return	'1';
		case	0x02:	return	'2';
		case	0x03:	return	'3';
		case	0x04:	return	'4';
		case	0x05:	return	'5';
		case	0x06:	return	'6';
		case	0x07:	return	'7';
		case	0x08:	return	'8';
		case	0x09:	return	'9';
		case	0x0A:	return	'A';
		case	0x0B:	return	'B';
		case	0x0C:	return	'C';
		case	0x0D:	return	'D';
		case	0x0E:	return	'E';
		case	0x0F:	return	'F';
		default:		return	'*';
	}
}

 
void goto_next_case(void)
{
	_emi=0;
	M_RTC_display =0;						    		
	gsm_loop=0;
	memset((unsigned char *)&M_UART_RxFIFO,0,128);			    					      	
  	M_TaskBuf1++;
  	M_UART_RxIndex=0;
  	_emi=1;		
}
void wait_loop_time(signed int time)
{
	
	M_RTC_display=0;
	gsm_loop++;
	if(gsm_loop>=time)
	{
	  // goto_next_case();	
//	  	M_RTC_display =0;
	 //  M_TaskBuf1=gsm_pown_off;
	 
//	   lcd.send.Bit.Fail=1;
//	   lcd.send.Bit.Ing=0;
	   back=M_TaskBuf1;
	   mi=0;
	}
}

 uchar getCIMI(char *str,uchar len)
{
	uchar ret = 0;
//	uchar hlen = 0;
	uchar i = 0;
	char *PA = str;
	if(PA != 0)
	{
		for(i=0;i<len;i++)
		{
			if(PA[i]>='0'&& PA[i]<='9')
			{
				memset((unsigned char *)CIMI,0,sizeof(CIMI));
				memcpy((unsigned char *)CIMI,&PA[i],15);//15是IMEI号长??
				if(CIMI[0]>='0'&& CIMI[0]<='9' && CIMI[14]>='0'&& CIMI[14]<='9')
				{
					ret = 1;
					break;
				}
				else
				   memset((unsigned char *)str,0,len);								
			}
		}	   
	}

	
	return ret;
}
uchar getIMEI(uchar *str,uchar len)
{
	uchar ret = 0;
//	uchar hlen = 0;
	uchar i = 0;
	uchar *PA = str;
	if(PA != 0)
	{
		for(i=0;i<len;i++)
		{		
			if(PA[i]>='0'&& PA[i]<='9')
			{
				memset((unsigned char *)IMEI,0,sizeof(IMEI));
				memcpy((unsigned char *)IMEI,&PA[i],15);//15是IMEI号长??
				if(IMEI[0]>='0'&& IMEI[0]<='9' && IMEI[14]>='0'&& IMEI[14]<='9')
				{
					ret = 1;
					break;
				}
				else
				   memset((unsigned char *)str,0,len);								
			}
		}		

	}

	
	return ret;
}
//用creg,cereg,cgreg查询网络状??
uchar Check_NetReg(char *pdatain)
{
	char *PA;
	char ret = 0;
	uchar i = 0;
	uchar temp[3] = {0,};

//	PA = strchr(pdatain, ',');
//	temp[0] = atoi(++PA);
//	if((temp[0] == 1)||(temp[0] == 5))
//	{
//		ret = 1;
//	}

	PA = strchr(pdatain, ',');
	temp[0] = atoi(++PA);
	PA = strchr(PA, ',');
	temp[1] = atoi(++PA);
	PA = strchr(PA, ',');
	temp[2] = atoi(++PA);
	for (i = 0; i < 3; i++)
	{
		if ((temp[i] == 1) || (temp[i] == 5))
		{
			ret = 1;
			break;
		}
	}
	return ret;
}


const uchar data_time2[]={0,31,28,31,30,31,30,31,31,30,31,30,31};


uchar getServerCallback(uchar *str,uchar len)
{
	uchar ret = 0;
	uchar *PA = str;

	if(strstr((const char *)PA,(const char *)"200"))
		ret = 0;
	else if(strstr((const char *)PA,(const char *)"40"))//40时候的错误
		ret = 1;
	else if(strstr((const char *)PA,(const char *)"ERROR"))//70出现错误
		ret = 2;
	else 
		ret = 6;
	return ret;
}
unsigned char Char_TO_HEX(unsigned char Hex)
{
	switch(Hex)
	{
		case	'0':	return	0x00;
		case	'1':	return	0x01;
		case	'2':	return	0x02;
		case	'3':	return	0x03;
		case	'4':	return	0x04;
		case	'5':	return	0x05;
		case	'6':	return	0x06;
		case	'7':	return	0x07;
		case	'8':	return	0x08;
		case	'9':	return	0x09;
		
		case	'a':	return	0x0A;
		case	'b':	return	0x0B;
		case	'c':	return	0x0C;
		case	'd':	return	0x0D;
		case	'e':	return	0x0E;
		case	'f':	return	0x0F;		
		
		case	'A':	return	0x0A;
		case	'B':	return	0x0B;
		case	'C':	return	0x0C;
		case	'D':	return	0x0D;
		case	'E':	return	0x0E;
		case	'F':	return	0x0F;
		default:		return	Hex-48;
	}
}
void getServerTime(char *str)
{
//	char *PA = 0;
//	char *PB = 0;
	UCHAR i,j;

//	PA = strstr(str,"+IP");
//  	if(!PA)
//  	{
//  		ret = 9;
//		return ret;
//  	}
    imp = 0;
  	for(i=0;i<125;i++)
  	{
  		if(M_UART_RxFIFO[i]=='+'&& M_UART_RxFIFO[i+1]=='I' && M_UART_RxFIFO[i+2]=='P')
  		{
  	        for(j=0;j<12;j++,i++)
  	        {
  	        	TIME[j]=M_UART_RxFIFO[i+17];  	        	
  	        }
		 	for(i=0;i<6;i++)
			{
				server_data[0]=Char_TO_HEX(TIME[i*2]);
				server_data[1]=Char_TO_HEX(TIME[i*2+1]);	
				
				data[i] = server_data[0];
				data[i] *= 16;		
				data[i] += server_data[1];		
				
			}	
		
		    if(data[0]>20 && data[0]<99)
		    {
		    	imp++;
		      	if(data[1]>0 && data[1]<13)	
		      	{
		      		imp++;
		      	  	if(data[2]>0 && data[2]<32)	
		      	  	{
		      	  		imp++;
		      	  	  	if(data[3]<24)
		      	  	  	{
		      	  	  	   imp++;	
		      	  	  	   if(data[4]<60)
		      	  	  	   {
		      	  	  	   		imp++;
								_emi=0;
								M_Year=data[0];
								M_Month=data[1];
								M_Days=data[2];
								M_Hour=data[3];
								M_Minutes=data[4];
							//	M_Second=data[5];		
								_emi=1;					
							//	ret = 1;
							    send_ok++;
							
							    	  	  	   	
		      	  	  	   	}
		      	  	  	}
		      	  	}
		    	
		      	}
		    } 
		    break;			
  		}

  		
  	}
//	PB = PA+17;	
//	memset(TIME,0,sizeof(TIME));
//	memcpy(TIME,PB,12);//15是IMEI号长??
//	for(i=0;i<6;i++)
//	{
//
//	
//		server_data[0]=Char_TO_HEX(TIME[i*2]);
//		server_data[1]=Char_TO_HEX(TIME[i*2+1]);	
//		
//		data[i] = server_data[0];
//		data[i] *= 16;		
//		data[i] += server_data[1];		
//		
//		
//	}	



//    if(data[0]>20 && data[0]<99)
//    {
//    	ret++;
//      	if(data[1]>0 && data[1]<13)	
//      	{
//      		ret++;
//      	  	if(data[2]>0 && data[2]<32)	
//      	  	{
//      	  		ret++;
//      	  	  	if(data[3]<24)
//      	  	  	{
//      	  	  	   ret++;	
//      	  	  	   if(data[4]<60)
//      	  	  	   {
//      	  	  	   		ret++;
//						_emi=0;
//						M_Year=data[0];
//						M_Month=data[1];
//						M_Days=data[2];
//						M_Hour=data[3];
//						M_Minutes=data[4];
//					//	M_Second=data[5];		
//						_emi=1;					
//					//	ret = 1;
//					    send_ok++;
//					    	  	  	   	
//      	  	  	   	}
//      	  	  	}
//      	  	}
//    	
//      	}
//    }

 	
	  

}

void setRssi(void)
{
  if(GSM_Signal>9)
	  lcd.ant.Bit.Lv0 = 1;
   if(GSM_Signal>15)
	  lcd.ant.Bit.Lv1 = 1;               	             
   if(GSM_Signal>18)
	  lcd.ant.Bit.Lv2 = 1;             	               	
   if(GSM_Signal>25)
	  lcd.ant.Bit.Lv3 = 1; 		
	
}


uchar getRssi(uchar *str,uchar len)
{
	uchar i = 0,j=0,k=0;
	uchar flag = 0;
	uchar ret = 0xFF;
	uchar rssiArray[2] = {0x00,0x00};
	_emi=0;
	for (i = 0; i < len; i++)
	{
		if ((str[i] >= '0') && ((str[i] <= '9')))
		{
			if (j == (i - 1))
				rssiArray[k] = rssiArray[k] * 10 + (str[i] - 0x30);
			else
				rssiArray[k] = str[i] - 0x30;
			j = i;
			flag = 1;
		}
		else
		{
			if (flag == 1)
			{
				flag = 0;
				k++;
			}
		}
	}

	if((rssiArray[0] >= 1)&&(rssiArray[0] <= 31))
	{
	//	if(rssiArray[1] == 99)
		{
			ret = 0;
		}
	}
	else 
	{
		ret = 1;
	}
	GSM_Signal = rssiArray[0];
	_emi=1;
	return ret;
}
/*
加密方法是字符对应的10进制和0x05做异或 得到的值对应的16进制字符
如：字符'C'对应的10进制是12 12与0x05异或得到9 则加密后得到的字符是'9'
	字符'1'对应的10进制是1 1与0x05异或得到4 则加密后得到的字符是'4'
20240920 注因为序列号的月份用字母A-L来对应1-12月，超过F的值不做加密处理

*/

uchar encrypt(uchar data)
 {
 	switch(data)
	{
		case	'0':	return	'5';
		case	'1':	return	'4';
		case	'2':	return	'7';
		case	'3':	return	'6';
		case	'4':	return	'1';
		case	'5':	return	'0';
		case	'6':	return	'3';
		case	'7':	return	'2';
		case	'8':	return	'D';
		case	'9':	return	'C';
		case	'A':	return	'F';
		case	'B':	return	'E';
		case	'C':	return	'9';
		case	'D':	return	'8';
		case	'E':	return	'B';
		case	'F':	return	'A';
		default:		return	data;
	}
 	
 }

//-------------------------------------------------------
signed char starting_gsm(void)//启动模组
{
//  unsigned char k,b,loop,delay,repeat;
 // unsigned char ret;
     back=0;
     mi=1;
	 M_RTC_display =0;
	 gsm_time=180;
	 while(mi && gsm_time)
	 {
			GCC_CLRWDT();
			_emi=1;
			if(F_500ms_LCD)
			{					
				testlcd();	
				F_500ms_LCD =0;	
			}			
			if(F_MainTimerOut)
			{	
				F_MainTimerOut =0;
				M_RTC_display++;
			    switch(M_TaskBuf1)
			    {
			      case 0://pown on
			        if(M_RTC_display == 1)
			        {
						//--- display Month & Day
						Lcd_Month_Day_Process(M_Month,M_Days);
						//--- display Hour & Minutes
						Lcd_Clock_Process(M_Hour,M_Minutes);
						LCD_ScanOut();
					}
			         if(M_RTC_display>300)
			         {
					      	_pb3=0; //rest
		
						goto_next_case();				         	
			         	
			         }
			         else if(M_RTC_display>200)
			         {
			         		_pb3=1; //rest
			         }
			         else
			         {
					      _pb2=1;//powern
					      _pb3=0; //rest			         	
			         	
			         }
			         

//				     if(M_RTC_display==200)
//				     {
//				      		_pb3=1; //rest
//				     }
//				     else if(M_RTC_display==300)
//				     {
//					      	_pb3=0; //rest
//		
//						goto_next_case();	
//				     }
//				     else
//				     {
//					      _pb2=1;//powern
//					      _pb3=0; //rest				     	
//				     	
//				     }					      
//			        
			         
			         break;
		//--------------------------------------------		        
			      case 1://wait RDY
			      
					if(strstr((const char *)&M_UART_RxFIFO,(const char *)"RDY\r\n"))
					{
						goto_next_case();					
					}				      
					if(M_RTC_display>1000)
					{	    					      	
					    M_TaskBuf1++;						
					}
		//						wait_loop_time(1000);				        
			        
			        break;				        
		//--------------------------------------------					        	
			      case 2://print CPIN
					if(M_RTC_display==1)
					{
						print_str("AT+CPIN?\r\n");																		
					    _emi=1;		
					}
					else if(M_RTC_display>50)
					{
						wait_loop_time(20);
					
		
					}							     				
					if(strstr((const char *)M_UART_RxFIFO,(const char *)"OK\r\n"))
					{
		
						  goto_next_case();					      	
				
					}				        
			        
			        break;
					
		//--------------------------------------------					        	
			      case 3://CIMI
					if(M_RTC_display==1)
					{
						print_str("AT+CIMI\r\n");																		
					    _emi=1;		
					}
					else if(M_RTC_display>50)
					{
						wait_loop_time(5);
						M_UART_RxIndex=0;								
		
					}							     				
					if(strstr((const char *)M_UART_RxFIFO,(const char *)"OK\r\n"))
					{
						if(getCIMI((char *)M_UART_RxFIFO,sizeof(M_UART_RxFIFO)))
						   goto_next_case();					    						
					}
									        			        
			        break;
		//--------------------------------------------					        				    	
			      case 4://PRINT CGSN
					if(M_RTC_display==1)
					{
						print_str("AT+CGSN\r\n");																		
					    _emi=1;		
					}
					else if(M_RTC_display>50)
					{
						wait_loop_time(5);
						M_UART_RxIndex=0;								
		
					}							     				
					if(strstr((const char *)M_UART_RxFIFO,(const char *)"OK\r\n"))
					{
						if(getIMEI((uchar *)&M_UART_RxFIFO,sizeof(M_UART_RxFIFO)))
						   goto_next_case();					    						
					}
								        
		
			        break;	
		//--------------------------------------------					        
			      case 5://AT+QHTTPCFG=\"contextid
					if(M_RTC_display==1)
					{
						print_str("AT+QHTTPCFG=\"contextid\",1\r\n");																		
					    _emi=1;		
					}
					else if(M_RTC_display>30)
					{							
						wait_loop_time(5);
		
					}							     				
					if(strstr((const char *)M_UART_RxFIFO,(const char *)"OK\r\n"))
					{
						goto_next_case();	
					}	
			        break;	
		//--------------------------------------------					        
			      case 6://AT+QHTTPCFG=\"requestheader\",0\r\n
					if(M_RTC_display==1)
					{
						print_str("AT+QHTTPCFG=\"requestheader\",0\r\n");																		
					    _emi=1;		
					}
					else if(M_RTC_display>30)
					{
						wait_loop_time(5);
		
					}							     				
					if(strstr((const char *)M_UART_RxFIFO,(const char *)"OK\r\n"))
					{
						goto_next_case();	
					}	
			        break;
		//--------------------------------------------					        
			      case 7://AT+QICSGP=1,1,\"CMNET\",\"\",\"\",0\r\n
					if(M_RTC_display==1)
					{
						print_str("AT+QICSGP=1,1,\"CMNET\",\"\",\"\",0\r\n");																		
					    _emi=1;		
					}
					else if(M_RTC_display>30)
					{
						wait_loop_time(5);
		
					}							     				
					if(strstr((const char *)M_UART_RxFIFO,(const char *)"OK\r\n"))
					{
						goto_next_case();	
					}	
			        break;
		//--------------------------------------------					        
			      case 8://
					if(M_RTC_display==1)
					{
						print_str("AT+QIACT=1\r\n");	
						gsm_test=0;																		
					    _emi=1;		
					}

					if(M_RTC_display%50==0)
					{							     				
							if(strstr((const char *)M_UART_RxFIFO,(const char *)"OK\r\n"))
							{
								goto_next_case();	
							}
							else if(strstr((const char *)M_UART_RxFIFO,(const char *)"ERROR\r\n"))
							{
		   		
								M_UART_RxIndex=0;
								memset((unsigned char *)&M_UART_RxFIFO,0,128);							
								print_str("AT+QIACT=1\r\n");		
								 _emi=1;	
								
							}
							else 
							{  
								if(gsm_test++>20)
								{
									gsm_test=0;
									print_str("AT+QIACT=1\r\n");																		
								    _emi=1;	
								}								
								
							}	
					}
					if(M_RTC_display>60*100)
					{
						wait_loop_time(1);
		
					}					
											
						
			        break;
		//--------------------------------------------					        
			      case 9://AT+QIACT?\r\n
					if(M_RTC_display==1)
					{
						print_str("AT+QIACT?\r\n");																		
					    _emi=1;		
					}
					else if(M_RTC_display>30)
					{
						wait_loop_time(2);
		
					}							     				
					if(strstr((const char *)&M_UART_RxFIFO,(const char *)"OK\r\n"))
					{
						goto_next_case();	
					}
				
						
			        break;
		//--------------------------------------------					        
			      case 10://
					if(M_RTC_display==1)
					{
						print_str("AT+CREG?;+CEREG?;+CGREG?\r\n");																		
					    _emi=1;		
					}
					else if(M_RTC_display>30)
					{
						wait_loop_time(50);	
					
					}							     				
					if(strstr((const char *)M_UART_RxFIFO,(const char *)"OK\r\n"))
					{
						goto_next_case();				      						
					}	
			        break;
		//--------------------------------------------					        
			      case 11:
					if(M_RTC_display==1)
					{
						print_str("AT+COPS?\r\n");																		
					    _emi=1;		
					}
					else if(M_RTC_display>30)
					{
						wait_loop_time(50);	
				
					}							     				
					if(strstr((const char *)M_UART_RxFIFO,(const char *)"OK\r\n"))
					{
						goto_next_case();				      	
				
					}	
			        break;
		//--------------------------------------------					        
			      case 12://AT+QNWINFO\r\n
					if(M_RTC_display==1)
					{
						print_str("AT+QNWINFO\r\n");																		
					    _emi=1;		
					}
					else if(M_RTC_display>30)
					{
						wait_loop_time(2);
					
					}							     				
					if(strstr((const char *)M_UART_RxFIFO,(const char *)"OK\r\n"))
					{
						goto_next_case();				      						
					}	
			        break;
		//--------------------------------------------					        
			      case 13://AT+CSQ\r\n
					if(M_RTC_display==1)
					{
						print_str("AT+CSQ\r\n");																		
					    _emi=1;		
					}
					else if(M_RTC_display>30)
					{
						wait_loop_time(50);	
					
					}							     				
					if(strstr((const char *)M_UART_RxFIFO,(const char *)"OK\r\n"))
					{
						if(getRssi((uchar *)&M_UART_RxFIFO,sizeof(M_UART_RxFIFO))==0)
					    	goto_next_case();
					    	gsm_test=0;			      	
				
					}	
			        break;
		//--------------------------------------------					        
			      case 14:
			      
			        mi=0;		
			        break;				        
		    				        				        				        				        				        				        				        			        			    	
		//--------------------------------------------					    	
			    }	
							
					
			}	


	}
	return back;

}

//----------------------------------------------------------
signed char send_gsm_data(void)
{
	UCHAR b, i=0;
	signed int	Pub_temp;
	UCHAR buf[6];	
     back=0;
     mi=1;
	 while(mi)
	 { 
		GCC_CLRWDT();
		_emi=1;
		if(F_500ms_LCD)
		{		
			testlcd();	
			F_500ms_LCD =0;		
		}		
		if(F_MainTimerOut)
		{	
			F_MainTimerOut =0;
			M_RTC_display++;

			switch (M_TaskBuf1)
			{
					case 0:
	
						if(M_RTC_display==1)
						{
						 	memset((unsigned char *)buf,0,sizeof(buf));
	                        buf[4]=sizeof(OPEN_URL)-1+85;//计算URL长度 	                        
	                        if(buf[4]>99)
	                        {
	                          buf[0]=HEX_TO_Char(buf[4]/100);	
	                          buf[1]=HEX_TO_Char(buf[4]/10%10);
	                          buf[2]=HEX_TO_Char(buf[4]%10);	
	                        }
	                        else
	                        {
	                          	
	                          buf[0]=HEX_TO_Char(buf[4]/10);
	                          buf[1]=HEX_TO_Char(buf[4]%10);	
	                        }                        
							print_str("AT+QHTTPURL=");	
							print_str((char *)buf);	
							print_str(",80\r\n");																
						    _emi=1;
						}
						if(strstr((const char *)M_UART_RxFIFO,(const char *)"CONNECT"))
						{
							goto_next_case();			    					      	
						}
						else if(strstr((const char *)M_UART_RxFIFO,(const char *)"ERROR"))
						{	
							wait_loop_time(1);
						}
								 
						if(M_RTC_display>30*100)//重启处理
						{
							wait_loop_time(1);
						}			                        
					    break;	
	//------------------------------------------------------------------
				
					case 1:
						if(M_RTC_display==1)
						{					
						    memset((unsigned char *)GSM_data,0,sizeof(GSM_data));
						    for(i=0;i<85;i++)//IMEI 861681050308878
								GSM_data[i]='F';
						    i=0;
							GSM_data[i++]='5';//起始??
							GSM_data[i++]='A';
								
							GSM_data[i++]='2';//版本??
							GSM_data[i++]='7';
							
							GSM_data[i++]='5';//用户??
					
							
							GSM_data[i++]='2';//客戶??
							GSM_data[i++]='2';
							
							GSM_data[i++]='7';//机型代码 
							GSM_data[i++]='7';//机型代码				
							
							GSM_data[i++]='0';//机种??
							GSM_data[i++]='2';//
						//	系列??
	//						GSM_data[i++]=(unsend_data[k].year/10)+'0';	//year
	//						GSM_data[i++]=(unsend_data[k].year%10)+'0';
	//							
	//						GSM_data[i++]=BLOOD_Package.bytes[5]+0x40;	//month//IP_address[5]+0x40;//月份A表示1???
	//						
	//						GSM_data[i++]=Project_Sequence/100000%10+ '0';//查看序列	
	//						GSM_data[i++]=Project_Sequence/10000%10+ '0';									
	//						GSM_data[i++]=Project_Sequence/1000%10+ '0';
	//						GSM_data[i++]=Project_Sequence/100%10+ '0';
	//						GSM_data[i++]=Project_Sequence/10%10+ '0';
	//						GSM_data[i++]=Project_Sequence%10+ '0';
#if 1	

							GSM_data[i++]=Calibration.CAL.Serial_number[0];	//year
							GSM_data[i++]=Calibration.CAL.Serial_number[1];
								
							GSM_data[i++]=Calibration.CAL.Serial_number[2];
				
							GSM_data[i++]=Calibration.CAL.Serial_number[3];//查看序列								
							GSM_data[i++]=Calibration.CAL.Serial_number[4];									
							GSM_data[i++]=Calibration.CAL.Serial_number[5];
							
							GSM_data[i++]=Calibration.CAL.Serial_number[6];
							GSM_data[i++]=Calibration.CAL.Serial_number[7];
							GSM_data[i++]=Calibration.CAL.Serial_number[8];
#else  //下面这个sn号 可以从后台查看
							GSM_data[i++]='2';	//year
							GSM_data[i++]='3';
								
							GSM_data[i++]='A';
							
							GSM_data[i++]='0';//查看序列								
							GSM_data[i++]='6';									
							GSM_data[i++]='1';
							
							GSM_data[i++]='6';
							GSM_data[i++]='2';
							GSM_data[i++]='6';
#endif					
							
							GSM_data[i++]='0';//預留3
							GSM_data[i++]='0';//			
							GSM_data[i++]='0';//			
							
									
							GSM_data[i++]=unsend_data[index].second/10 + '0';//??
							GSM_data[i++]=unsend_data[index].second%10 + '0';//??
							meals=unsend_data[index].month>>6;
							GSM_data[i++]=meals + '0';//餐前后标??							

							
							GSM_data[i++]=unsend_data[index].sg/100+'0';//血糖??
							GSM_data[i++]=unsend_data[index].sg/10%10+'0';//				
							GSM_data[i++]=unsend_data[index].sg%10+'0';//
							
							
							
							GSM_data[i++]=unsend_data[index].year/10 + '0';//??
							GSM_data[i++]=unsend_data[index].year%10 + '0';//
							
												
							
							unsend_data[index].month&=0b00111111;//去掉餐前后标志??			
							
							GSM_data[i++]=unsend_data[index].month/10 + '0';//??
							GSM_data[i++]=unsend_data[index].month%10 + '0';//
							
							GSM_data[i++]=unsend_data[index].day/10 + '0';//??			
							GSM_data[i++]=unsend_data[index].day%10 + '0';//												
											
							GSM_data[i++]=unsend_data[index].hour/10 + '0';//??
							GSM_data[i++]=unsend_data[index].hour%10 + '0';//								
							
							GSM_data[i++]=unsend_data[index].min/10 + '0';//??
							GSM_data[i++]=unsend_data[index].min%10 + '0';//	
							
							Pub_temp=0;
							for(b=0;b<39;b++)
							{
								Pub_temp+=GSM_data[b];	
							}			
							
							GSM_data[i++]=HEX_TO_Char(Pub_temp>>12&0x0f);//SUM
							GSM_data[i++]=HEX_TO_Char(Pub_temp>>8&0x0f);											
							GSM_data[i++]=HEX_TO_Char(Pub_temp>>4&0x0f);
							GSM_data[i++]=HEX_TO_Char(Pub_temp&0x0f);	
							
							GSM_data[i++]='_';//连接??
										
							for(b=0;b<15;b++)//IMSI 460043019913642
							  GSM_data[i++]=CIMI[b];//'F';//	
							  		
							GSM_data[i++]='_';//连接??
							
							for(b=0;b<15;b++)//IMEI 861681050308878
							  GSM_data[i++]=IMEI[b];
							i=85;  
							GSM_data[i++]='\r';  
							GSM_data[i++]='\n'; 
					
							
							memset((unsigned char *)GSM_data2,0,sizeof(GSM_data2));
							imp=0;				
							for(i=0;i<43;i++,imp++)	
							{																				
					        	GSM_data2[imp]=encrypt(GSM_data[imp]);
							}
							
							GSM_data2[imp++]='_';//连接符  	
														
							for(i=0;i<15;i++,imp++)	
							{																				
					        	GSM_data2[imp]=encrypt(GSM_data[imp]);
							}
							GSM_data2[imp++]='_';//连接符
							
							for(;imp<85;imp++)	
							{																				
					        	GSM_data2[imp]=encrypt(GSM_data[imp]);
							}
							GSM_data2[imp++]='\r';					
							GSM_data2[imp++]='\n';
								
							GCC_CLRWDT();
						    print_str((char*)OPEN_URL);	
																												
#ifdef lanhang														
							print_str((char*)GSM_data2);
#else
								
																			
																											
							print_str((char*)GSM_data);
#endif							

							
							

					
							
						    
						
		               //     print_str("http://tf.ydjk5.com/gprs/receive/api/data?data=5A27001010220J537820000001074210226142707CF_FFFFFFFFFFFFFFF_FFFFFFFFFFFFFFFFFFFFFFFF2\r\n");						
							_emi=1;
						}
						if(strstr((const char *)M_UART_RxFIFO,(const char *)"OK\r\n"))
						 {
						 	

						 	
							goto_next_case();
							gsm_test=0;				      						
						 }						
						if(M_RTC_display>50)//
						{
							wait_loop_time(1);
				
						}							
		 
					 
					 break;	
	//------------------------------------------------------------------						 		
	//发送HTTP GET 请求，最大响应时间为80 秒??						
					case 2:
						 if(M_RTC_display==1)
						 {
	
							print_str("AT+QHTTPGET=80\r\n");																
						    _emi=1;
						 }
						 if(M_RTC_display%30==0)
						 {
//								if(strstr(M_UART_RxFIFO,","))
								{
									if(strstr((const char *)M_UART_RxFIFO,(const char *)"716")||strstr((const char *)M_UART_RxFIFO,(const char *)"719"))
									{
										memset((unsigned char *)&M_UART_RxFIFO,0,128);			    					      										  
									  	M_UART_RxIndex=0;									
										print_str("AT+QHTTPGET=80\r\n");
										 _emi=1;

									}
									else
									{
										imp = getServerCallback((uchar *)M_UART_RxFIFO,sizeof(M_UART_RxFIFO));				
										if(imp == 0)
										{
											goto_next_case();
											//gsm_test=0;	
										}
										else if(imp != 6)//收到错误的时??
										{					
											wait_loop_time(3);
										}									
									}	
									
								}
						 }						
						
							 
						if(M_RTC_display>30*100)//重启处理
						{
							wait_loop_time(1);
						}							 
					 
					 break;
	//------------------------------------------------------------------						 
					 
					case 3:
						 if(M_RTC_display==1)
						 {
							print_str("AT+QHTTPREAD=80\r\n");																
						    _emi=1;
						 }
						if(strstr((const char *)M_UART_RxFIFO,(const char *)"OK\r\n"))
						 {
							getServerTime((char *)&M_UART_RxFIFO);				
							if(imp==5)
							{
								goto_next_case();

								unsend_data[index].is_send=0;
								mi=0;//out
	
									
							}
							else
							{
								 gsm_test++;
								 if(gsm_test>3)	
								 	wait_loop_time(1);
								 else
								   {
								   	
									_emi=0;
									M_RTC_display =0;						    											
									memset((unsigned char *)&M_UART_RxFIFO,0,128);			    					      										  
								  	M_UART_RxIndex=0;
								  	M_TaskBuf1--;
								  	_emi=1;									   	
								   	
								   	
								   	}	
							 
							}			      						
						 }							 					 
								 
						if(M_RTC_display>15*100)
						{
								 gsm_test++;
								 if(gsm_test>2)	
								 	wait_loop_time(1);
								 else
								   {
								   	
									_emi=0;
									M_RTC_display =0;						    											
									memset((unsigned char *)&M_UART_RxFIFO,0,128);			    					      										  
								  	M_UART_RxIndex=0;
								  	M_TaskBuf1--;
								  	_emi=1;									   	
								   	
								   	
								   	}
						
						}							 
					 
					 break;
	//------------------------------------------------------------------				 
					 			 
					case 4:
			      
					        mi=0;		
					        break;				      
					 
					 break;			          	
	//------------------------------------------------------------------		          	
	        }
	        
		 			
		}		
					
	 }
	return back;  	 	
}
#else
void goto_next_case(void)
{
	_emi=0;
	M_RTC_display =0;						    		
	gsm_loop=0;
	memset((unsigned char *)&M_UART_RxFIFO,0,128);			    					      	
  	M_TaskBuf1++;
  	M_UART_RxIndex=0;
  	_emi=1;		
}
signed char starting_gsm(void)//启动模组
{
	return 0;
}

signed char send_gsm_data(void)
{
	return 0;
}

void setRssi(void)
{
	M_TaskBuf1 = M_TaskBuf1;
}

#endif


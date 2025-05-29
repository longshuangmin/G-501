#include "include.h"

//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
//--- reference 2000 / 1 / 1 / am12 : 00 : "00" ----------------------------
//--- input year / month / days / hours / minutes / second
//---       buf5    buf4    buf3   buf2    buf1       buf0
unsigned long DateToSecond (unsigned char *buf)
{
	unsigned long Lbuf0,Lbuf1;
	unsigned char Cbuf0;
	unsigned char count;
	//--- check how many leap year
	Cbuf0 = (((buf[5]-1)/4)+1);                    //for leap yaer=> + days
	                  //+1 for 2000
	
	//--- yaer to days , 1year=365 days
	Lbuf1 = buf[5];
	Lbuf0 = (Lbuf1 * 365) + Cbuf0;
	
	//--- month to days
	Cbuf0 = (buf[5]%4);          //current yaer = leap year ?? leap year =0
	
	//--- buf4 = month
	for(count =1 ; count < buf[4] ; count++)
	{
		if(Cbuf0 == 0)          //read leap year month table
			Lbuf0 += Month_TABLE2[count-1];
		else                   //read normal year month table
			Lbuf0 += Month_TABLE1[count-1];
	}
	
	//--- days to days
	Lbuf0 += (buf[3]-1);
	
	//--- days to second , 1days = 24hr x 60 x 60 =86400
	Lbuf0 *= 86400;
	
	//--- hour to second
	Lbuf1 = buf[2];
	Lbuf0 += (Lbuf1 * 3600);
	
	//--- minutes to second
	Lbuf1 = buf[1];
	Lbuf0 += (Lbuf1 * 60);
	
	//--- second to second
	Lbuf0 += buf[0];
	
	return Lbuf0;
	
}

//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
//--- reference 2000 / 1 / 1 / am12 : 00 : "00" ----------------------------
//--- input M_32bitBuf1 for second
//---
//--- output year / month / days / hours / minutes / second
//---        buf5    buf4    buf3   buf2    buf1       buf0
void SecondToDate (unsigned long Second,unsigned char *buf)
{
	unsigned long Lbuf0,Lbuf1;
	unsigned int Ibuf0;
	unsigned char Cbuf0,Cbuf1,Cbuf2;
	
	Lbuf1 = Second % 3600; 				//3?Uhour
	Ibuf0 = Lbuf1;
	buf[0] = Ibuf0 % 60;				//load seconds 
	buf[1] = Ibuf0 / 60;				//load minutes
	
	Lbuf1 = Second / 3600; 				//hour
	buf[2] = Lbuf1 % 24;				//load hours
	
	Lbuf0 = Lbuf1 / 24;     			//days
	
	for(buf[5] =0; Lbuf0 >365 ;buf[5]++)	//load years
	{
		Lbuf0 -= 365;
		Cbuf0 = buf[5] % 4;
		if(Cbuf0 ==0)
			Lbuf0--;               		//leap year -1
	}
	
	Ibuf0 = Lbuf0;
	Cbuf2 = 1;
	Cbuf1 = buf[5] % 4;                   	//current yaer = leap ?? leap year =0
	Cbuf0 = 31;
	for(buf[4] =1; Ibuf0 > Cbuf0 ; buf[4]++)
	{
		if(Cbuf1 == 0)       //read leap year month table
		{
			Ibuf0 -= Month_TABLE2[buf[4] - 1];
			Cbuf0 = Month_TABLE2[Cbuf2];
		}
		else                   //read normal year month table
		{
			Ibuf0 -= Month_TABLE1[buf[4] - 1];
			Cbuf0 = Month_TABLE1[Cbuf2];
		}
		
		Cbuf2++;
	}

	buf[3] = Ibuf0;
	buf[3]++;
	
	//---over month limit
	if(buf[3] > Cbuf0)
	{
		buf[3] =1; //date
		buf[4]++; //month+1
		if(buf[4] >12)
		{
			buf[5]++;        //year
			buf[4] =1;       //month
		}
	}
}



////--------------------------------------------------------------------------
//void Lcd_Alarm_Process (void)
//{
//	unsigned char cbuf0,M_Alarm_HR,M_Alarm_MIN;
//	//--- Lcd 4/5/6/7
//	//--- time " : " flash
//	M_LCD_RAM[9] |= 0x08;
//	
//	//--- AM / PM 
//	M_LCD_RAM[13] &= ~0x08; //clear PM icon
//	M_LCD_RAM[11] &= ~0x08; //clear AM icon
//	
////	//---- 12hr process
////	#if C24hr_process1
////	{
////		if(M_Alarm_HR >=12)
////			M_LCD_RAM[13] |= 0x08;	//PM
////		else
////			M_LCD_RAM[11] |= 0x08;	//AM
////		
////		//--- hour ---
////		if(M_Alarm_HR >12)
////		{
////			cbuf0 = M_Alarm_HR -12;
////		}
////		//if(M_Hour <=12)
////		else
////		{
////			cbuf0 = M_Alarm_HR;
////			
////			if(M_Alarm_HR ==0)				 // = 0:00 23->24
////				cbuf0 = 12;
////		}
////	}
////	#else   //---- 24hr process
////	{
////		cbuf0 = M_Alarm_HR;
////	}
////	#endif
//	
////	Lcd45_Display(cbuf0,2);
//	
//	Lcd67_Display(M_Alarm_MIN,2);
//
//
//}

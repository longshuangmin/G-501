
#include "include.h"


#define lcd_A     LcdSeg_S3
#define lcd_B     LcdSeg_S3
#define lcd_C     LcdSeg_S1
#define lcd_D     LcdSeg_S0

#define lcd_E     LcdSeg_S1
#define lcd_F     LcdSeg_S2
#define lcd_G     LcdSeg_S2

#define lcd3_B     4
#define lcd3_C     2
#define lcd3_D     1

#define lcd3_A     8
#define lcd3_G     2

#define lcd3_F     4
#define lcd3_E     2

enum
{
    CHAR_0=0,
    CHAR_1,
    CHAR_2,
    CHAR_3,
    CHAR_4,
    CHAR_5,
    CHAR_6,
    CHAR_7,
    CHAR_8,
    CHAR_9,
    CHAR_A,
    CHAR_B,
    CHAR_C,
    CHAR_D,
    CHAR_E,
    CHAR_F,   
    CHAR_Y, 
    CHAR_T,
    CHAR_L,             
    CHAR_U,
    CHAR_P, 
    CHAR_N,    
    CHAR__, 
    CHAR_H,    
    CHAR_i,
    CHAR_o,    
    
           
};

const unsigned char number_12[][2]=
{
 
 	//BCG-ADEF
	lcd_B+lcd_C,lcd_A+lcd_D+lcd_E+lcd_F,//0	
	lcd_B+lcd_C,0,//1	
	lcd_B+lcd_G,lcd_A+lcd_D+lcd_E,//2
	lcd_B+lcd_C+lcd_G,lcd_A+lcd_D,//3	
	lcd_B+lcd_C+lcd_G,lcd_F,//4	
	lcd_C+lcd_G,lcd_A+lcd_D+lcd_F,//5	
	lcd_A+lcd_C+lcd_D,lcd_E+lcd_F+lcd_G,//6	
	lcd_A+lcd_B+lcd_C,0,//7	
	lcd_A+lcd_B+lcd_C+lcd_D,lcd_E+lcd_F+lcd_G,//8
	lcd_A+lcd_B+lcd_C+lcd_D,lcd_F+lcd_G,//9
//	0b00001110,0b00000111,//a	
//	0b00001110,0b00001100,//b	
//	0b00001010,0b00001001,//c
//	0b00001100,0b00001110,//d	
//	0b00001110,0b00001001,//e	
//	0b00001110,0b00000001,//f	
//	0b00000110,0b00001110,//Y	
//	0b00001110,0b00001000,//T	
//	0b00001010,0b00001000,//L
//	0b00001010,0b00001110,//U	
//	0b00001110,0b00000011,//P
//	0b00001010,0b00000111,//N	
//	0b00000100,0b00000000,//-
//	0b00001110,0b00000110,//H	
//	0b00001010,0b00000000,//i
//	0b00001100,0b00001100,//o
					
	
};


#if 0



const unsigned char number_3[][3]=
{
 
 	//xBCD-AxGx-xFEx
	lcd3_B+lcd3_C+lcd3_D,lcd3_A,lcd3_F+lcd3_E,//,//0	
	
	lcd3_B+lcd3_C,0,0,////1	
	
	lcd3_B+lcd3_D,lcd3_A+lcd3_G,lcd3_E,////2
	lcd3_B+lcd3_C+lcd3_D,lcd3_A+lcd3_G,0,//,//3	
	lcd3_B+lcd3_C,lcd3_G,lcd3_F,//,//4	
	lcd3_C+lcd3_D,lcd3_A+lcd3_G,lcd3_F,//,//5	
	lcd3_C+lcd3_D,lcd3_A+lcd3_G,lcd3_E+lcd3_F,//,//6	
	lcd3_B+lcd3_C,lcd3_A,0,//,//7	
	
	lcd3_B+lcd3_C+lcd3_D,lcd3_A+lcd3_G,lcd3_E+lcd3_F,//8
	
	lcd3_B+lcd3_C+lcd3_D,lcd3_A+lcd3_G,lcd3_F,//9

					
	
};
#endif
void dis_nub1(unsigned char i)
{

	if(i<0 || i>15)
	return;
	lcd.BigNum[0] = HexTab[i] ;
	lcd.BigNum[1] = 0 ;
    lcd.BigNum[2] = 0 ;
	LCD_ScanOut();


}

void dis_nub2(unsigned char i)
{	
	M_LCD_RAM[14]=number_12[i][0];
	M_LCD_RAM[15]=number_12[i][1];
	#if 0
	if(i<0 || i>15)
	return;
	lcd.BigNum[0] = 0 ;
	lcd.BigNum[1] = HexTab[i] ;
    lcd.BigNum[2] = 0 ;
	LCD_ScanOut();
	#endif
}

void dis_beat(void)
{
	Lcd_Bat(batlevel);
	if(lcd.meas.Bit.Bat)//BatLv0
	  M_LCD_RAM[2]|=LcdSeg_S5;
	else
	  M_LCD_RAM[2]&=~LcdSeg_S5;
}

#if 0
void dis_nub3(unsigned char i)
{

	if(i<0 || i>15)
	return;
	lcd.BigNum[0] = 0 ;
	lcd.BigNum[1] = 0 ;
    lcd.BigNum[2] = HexTab[i] ;
	LCD_ScanOut();

}


void dis_123(unsigned int  date)
{
//	dis_nub1(date/100);
//	dis_nub2(date/10%10);	
//	dis_nub3(date%10);
//	
	
	if(date>99)
	    lcd.BigNum[0] = date/100;

    lcd.BigNum[1] = date/10%10;
    lcd.BigNum[2] = date%10;	

}

void dis_unit(void)
{
	if((M_Unit & 0x01) !=0)
	{
		M_LCD_RAM[16] |=4;	//on "mmol"

	}
	else
	{
		M_LCD_RAM[16] |=8;	//on "mgdl"
	}

}

void dis_contr(unsigned char i)
{
	if((F_ControlOption) !=0)
	{
	//	M_LCD_RAM[16] |=4;	//on "mmol"
		lcd.meas.Bit.ControlSoultion =1;	

	}
	else
	{

		lcd.meas.Bit.ControlSoultion =0;	
	}

}

void dis_beat(void)
{
	Lcd_Bat(batlevel);
	if(lcd.meas.Bit.Bat_Low)//BatLv0
	M_LCD_RAM[2] |= (1<<5);
	else
	M_LCD_RAM[2] &= ~(1<<5);
	//  M_LCD_RAM[17]|=8;	 //µç³ØÍâ¿ò  
	//if(lcd.meas.Bit.BatLv0)//BatLv0
	//  M_LCD_RAM[1]|=1;
	//if(lcd.meas.Bit.BatLv1)//BatLv1
	//  M_LCD_RAM[5]|=1;
	//if(lcd.meas.Bit.BatLv2)//BatLv2	
	//  M_LCD_RAM[8]|=1;	
	
}

//--------------------------------------------------------------------------

void updata_lcd(void )
{
	UCHAR i;
	UCHAR dis_buf[32];
	for(i=0;i<32;i++)
	   dis_buf[i]=0;
	   
	dis_buf[22]=number_12[lcd.BigNum[0]][0];//1
	dis_buf[23]=number_12[lcd.BigNum[0]][1];	
	
	dis_buf[20]=number_12[lcd.BigNum[1]][0];//2
	dis_buf[21]=number_12[lcd.BigNum[1]][1];	
		
	dis_buf[17]=number_3[lcd.BigNum[2]][0];//3
	dis_buf[18]=number_3[lcd.BigNum[2]][1];
	dis_buf[19]=number_3[lcd.BigNum[2]][2];	
	

    if(lcd.LitNum[0]==1)//4
	   dis_buf[13]=6;
    if(lcd.LitNum[0]==2)	   
	   dis_buf[13]=13;	   
	dis_buf[11]=number_12[lcd.LitNum[1]][0];//5
	dis_buf[12]=(number_12[lcd.LitNum[1]][1])<<1;	
	
	
			
	dis_buf[9]=number_12[lcd.LitNum[2]][0];//6
	dis_buf[10]=(number_12[lcd.LitNum[2]][1])<<1;	
	dis_buf[7]=number_12[lcd.LitNum[3]][0];//7
	dis_buf[8]=(number_12[lcd.LitNum[3]][1])<<1;	
	
	
    if(lcd.LitNum[0]==1)//8
	   dis_buf[6]=6;
    if(lcd.LitNum[0]==2)	   
	   dis_buf[6]=13;	 		
	dis_buf[4]=number_12[lcd.LitNum[1]][0];//9
	dis_buf[5]=(number_12[lcd.LitNum[1]][1])<<1;	
	

	dis_buf[2]=number_12[lcd.LitNum[2]][0];//10
	dis_buf[3]=(number_12[lcd.LitNum[2]][1])<<1;	
	dis_buf[0]=number_12[lcd.LitNum[3]][0];//11
	dis_buf[1]=(number_12[lcd.LitNum[3]][1])<<1;
	
	if(lcd.strip.Bit.Blood)//ÑªµÎ·û
	  dis_buf[21]|=8;		
	if(lcd.strip.Bit.StripBase)//ÊÔÖ½??
	  dis_buf[19]|=8;
	  
	  		   
	if(lcd.unit.Bit.mmoL)	//"mmol"
	  dis_buf[16]|=4;			
	if(lcd.unit.Bit.mgdL)	//"mgdl"
	  dis_buf[16]|=8;	  
	if(lcd.unit.Bit.Ketone)	//"Ketone"
	  dis_buf[16]|=2;
	if(lcd.unit.Bit.DateSlash)	//DateSlash
	  dis_buf[10]|=1;	  	  	  	  
	if(lcd.unit.Bit.TimeColon)	//TimeColon
	  dis_buf[3]|=1;	  
	  
	if(lcd.mem.Bit.Average)	//Average
	  dis_buf[3]|=1;	  	  	  	  
	if(lcd.mem.Bit.Memory)	//Memory
	  dis_buf[14]|=8;
	  
	if(lcd.meas.Bit.BigNum_DP)
	  dis_buf[19]|=1;	  	
	if(lcd.meas.Bit.Bat_Low)//µçÁ¿µÍµç??
	  dis_buf[17]|=8;	   
	//if(lcd.meas.Bit.BatLv0)//BatLv0
	//  dis_buf[1]|=1;
	//if(lcd.meas.Bit.BatLv1)//BatLv1
	//  dis_buf[5]|=1;
	//if(lcd.meas.Bit.BatLv2)//BatLv2	
	//  dis_buf[8]|=1;
	if(lcd.meas.Bit.BefMeal)//AftMeal	
	  dis_buf[16]|=1;	  
	if(lcd.meas.Bit.AftMeal)//AftMeal	
	  dis_buf[13]|=1;		  
	  
	if(lcd.send.Bit.BLE)	//BLE
	  dis_buf[18]|=1;
	//if(lcd.send.Bit.Ing)	//Ing
	//  dis_buf[15]|=1;
	//if(lcd.send.Bit.OK)		//OK
	//  dis_buf[15]|=2;	  	  
	//if(lcd.send.Bit.Fail)	//Fail
	//  dis_buf[15]|=4;	  	  
	  	  
  

	  
	  	
	if(lcd.ant.Bit.Ant)   //Ant
	   	  dis_buf[23]|=8;                     				  
	if(lcd.ant.Bit.Lv0)	  //Lv0	
	       dis_buf[15]|=8;  
	if(lcd.ant.Bit.Lv1)   //Lv1
	       dis_buf[14]|=1;  	             	             
	if(lcd.ant.Bit.Lv2)   //Lv2
	       dis_buf[14]|=2;  	          	               	
	//if(lcd.ant.Bit.Lv3)   //Lv3
	//       dis_buf[14]|=4;  							  
						  	
	
	for(i=0;i<32;i++)
	   M_LCD_RAM[i] =dis_buf[i];
	
	
}


//
//	while(1)
//	{
//		GCC_CLRWDT();
////		if(F_MainTimerOut)
////		{
////			F_MainTimerOut=0;
////				temp=0;
////			M_UART_TxFIFO[temp++] = 0xca;
////			M_UART_TxFIFO[temp++] = 0x01;
////			M_UART_TxFIFO[temp++] = 0;
////			M_UART_TxFIFO[temp++] = 0;
////			M_UART_TxFIFO[temp]   = _pvref;
////			
////			M_UART_TxLength =5;
////			M_UART_TxIndex =0;
////			_txr_rxr0= M_UART_TxFIFO[M_UART_TxIndex];
////		}	
//		
//
//			if(F_500ms_LCD)
//			{
//			   test++;
//			   lcd.BigNum[0]=test/100;
//			   lcd.BigNum[1]=test/10%10;
//			   lcd.BigNum[2]=test%10;
//			   
//			   lcd.LitNum[1]=test%10;	
//
//			   lcd.LitNum[2]=test%10;			   
//			   lcd.LitNum[3]=test%10;
//			   
//			   lcd.LitNum[0]=test%10;			   
//			   lcd.LitNum[1]=test%10;
//			   
//			   lcd.LitNum[2]=test%10;			   
//			   lcd.LitNum[3]=test%10;	
//			   
//			   lcd.unit.Bit.mmoL=1;
//			   lcd.mem.Bit.Memory=1;
//			   lcd.meas.Bit.BefMeal=1;
//			   lcd.mem.Bit.Memory=1;
//				lcd.strip.Bit.Blood=~lcd.strip.Bit.Blood;
//				lcd.unit.Bit.TimeColon=~lcd.unit.Bit.TimeColon;
//				lcd.send.Bit.BLE=~lcd.send.Bit.BLE;
//				lcd.ant.Bit.Ant=~lcd.ant.Bit.Ant;			   		   			   
//			   			   		   
//				//testlcd();
//               GSM_Signal++;
//               if(GSM_Signal>20)
//               {
//				 GSM_Signal=0;             	               	
//               }                 
//         	               	
//				
//         	               	
//				lcd.ant.Byte&=1;
//				if(lcd.ant.Bit.Ant)
//				{
//                 	   
//		               lcd.ant.Bit.Ant=1;                           				  
//		               if(GSM_Signal>3)
//						  lcd.ant.Bit.Lv0 = 1;
//		               if(GSM_Signal>5)
//						  lcd.ant.Bit.Lv1 = 1;               	             
//		               if(GSM_Signal>8)
//						  lcd.ant.Bit.Lv2 = 1;             	               	
//		               if(GSM_Signal>15)
//						  lcd.ant.Bit.Lv3 = 1;    				  
//				  
//				  
//				}
//				
//
//
//
//				updata_lcd();
////	LED=~LED;		
//					
//				F_500ms_LCD =0;
//
//			}		
//			
//
//	}

#endif

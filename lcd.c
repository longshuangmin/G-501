#if 0
#include "include.h"


//--- for LCD number table
const unsigned char Lcd_Number_Table[16] ={0b00111111,0b00000110,0b01011011,	//0,1,2
                                           0b01001111,0b01100110,0b01101101,	//3,4,5
                                           0b01111101,0b00100111,0b01111111,	//6,7,8
                                           0b01101111,0b01110111,0b01111100,	//9,A,b
                                           0b00111001,0b01011110,0b01111001,	//C,d,E
                                           0b01110001	//F
                                          };
                                          
                                          
//--------------------------------------------------------------------------
void Lcd_AllOn (void)
{
	_mp1h = 4;
	_mp1l = 0x00;
	
	for(_tblp = 0x00;_tblp < 32;_tblp++)
	{
//		if((M_Unit & 0x02) != 0)
			_iar1 = 0xff;
//		else
//		{
//			if((M_Unit & 0x01) != 0)
//			{
//				_iar1 = 0xff;
//				if(_tblp ==7)
//					_iar1 &= ~0x01;		
//			}
//			else
//			{
//				_iar1 = 0xff;
//				if(_tblp ==5)
//					_iar1 &= ~0x01;		
//			}
//		}	
		 _mp1l++;
	}

	_mp1h = 0;
	_mp1l = 0x80;	
}

//--------------------------------------------------------------------------
void Lcd_AllOff (void)
{
	_mp1h = 4;
	_mp1l = 0x00;
	
	for(_tblp = 0x00;_tblp < 32;_tblp++)
	{
//		if((M_Task != C_OffMode) && ((_tblp >=9) && (_tblp <=10)))
//		{
//			if(_tblp ==9)
//				_iar1 &= 0x03;
//			else
//				_iar1 &= 0x01;
//		}
//		else
			_iar1 = 0;
			
		 _mp1l++;
	}

	_mp1h = 0;
	_mp1l = 0x80;		
}
//--------------------------------------------------------------------------
void Lcd1_Display (unsigned char Lcd_buf)
{
	//--- NO.1
	if((Lcd_buf >=1) && (Lcd_buf <=2))
	{
		if(Lcd_buf ==1)
		{
			M_LCD_RAM[2] |= 0x0a;
			M_LCD_RAM[2] &= ~0x04;
		}
		else if(Lcd_buf ==2)
		{
			M_LCD_RAM[2] |= 0x0c;
			M_LCD_RAM[2] &= ~0x02;
		}
	}
}

//--------------------------------------------------------------------------
void Lcd2_Display (unsigned char Lcd_buf)
{
	unsigned char cbuf3;
	
	//--- Lcd RAM used No.2
	cbuf3 = Lcd_Number_Table[Lcd_buf];
	
	//--- NO.2 3seg
	M_LCD_RAM[3] &=0b00000000;
	
    if((cbuf3 & 0b00001000) !=0x00 )
    	M_LCD_RAM[3] |= 0b00000001;			//D
    	
    if((cbuf3 & 0b00010000) !=0x00 )
    	M_LCD_RAM[3] |= 0b00000010;			//E
    	
    if((cbuf3 & 0b01000000) !=0x00 )
    	M_LCD_RAM[3] |= 0b00000100;			//G
    	
    if((cbuf3 & 0b00100000) !=0x00 )
    	M_LCD_RAM[3] |= 0b00001000;			//F
	
	//--- NO.2 4seg
	M_LCD_RAM[4] &=0b00001000;    	
    	
    if((cbuf3 & 0b00000100) !=0x00 )
    	M_LCD_RAM[4] |= 0b00000010;			//C
    	
    if((cbuf3 & 0b00000010) !=0x00 )
    	M_LCD_RAM[4] |= 0b00000100;			//B 
    	
    if((cbuf3 & 0b00000001) !=0x00 )
    	M_LCD_RAM[4] |= 0b00001000;			//A 	 
}

//--------------------------------------------------------------------------
void Lcd3_Display (unsigned char Lcd_buf)
{
	unsigned char cbuf3;
	
	//--- Lcd RAM used No.3
	cbuf3 = Lcd_Number_Table[Lcd_buf];
	
	//--- NO.3 5seg
	M_LCD_RAM[5] &=0b00000000;
	
    if((cbuf3 & 0b00001000) !=0x00 )
    	M_LCD_RAM[5] |= 0b00000001;			//D
    	
    if((cbuf3 & 0b00010000) !=0x00 )
    	M_LCD_RAM[5] |= 0b00000010;			//E
    	
    if((cbuf3 & 0b01000000) !=0x00 )
    	M_LCD_RAM[5] |= 0b00000100;			//G
    	
    if((cbuf3 & 0b00100000) !=0x00 )
    	M_LCD_RAM[5] |= 0b00001000;			//F
	
	//--- NO.3 6seg
	M_LCD_RAM[6] &=0b00001000;    	
    	
    if((cbuf3 & 0b00000100) !=0x00 )
    	M_LCD_RAM[6] |= 0b00000010;			//C
    	
    if((cbuf3 & 0b00000010) !=0x00 )
    	M_LCD_RAM[6] |= 0b00000100;			//B 
    	
    if((cbuf3 & 0b00000001) !=0x00 )
    	M_LCD_RAM[6] |= 0b00001000;			//A 
}

//--------------------------------------------------------------------------
void Lcd4_Display (unsigned char Lcd_buf)
{
	unsigned char cbuf3;
		
	//--- Lcd RAM used No.4
	cbuf3 = Lcd_Number_Table[Lcd_buf];
	
	//--- NO.4 7seg
	M_LCD_RAM[7] &=0b00000000;
	
    if((cbuf3 & 0b00001000) !=0x00 )
    	M_LCD_RAM[7] |= 0b00000001;			//D
    	
    if((cbuf3 & 0b00010000) !=0x00 )
    	M_LCD_RAM[7] |= 0b00000010;			//E
    	
    if((cbuf3 & 0b01000000) !=0x00 )
    	M_LCD_RAM[7] |= 0b00000100;			//G
    	
    if((cbuf3 & 0b00100000) !=0x00 )
    	M_LCD_RAM[7] |= 0b00001000;			//F
	
	//--- NO.4 8seg
	M_LCD_RAM[8] &=0b00001000;    	
    	
    if((cbuf3 & 0b00000100) !=0x00 )
    	M_LCD_RAM[8] |= 0b00000010;			//C
    	
    if((cbuf3 & 0b00000010) !=0x00 )
    	M_LCD_RAM[8] |= 0b00000100;			//B 
    	
    if((cbuf3 & 0b00000001) !=0x00 )
    	M_LCD_RAM[8] |= 0b00001000;			//A 
}

//--------------------------------------------------------------------------
void Lcd5_Display (unsigned char Lcd_buf)
{
	unsigned char cbuf3;
		
	//--- Lcd RAM used No.5
	cbuf3 = Lcd_Number_Table[Lcd_buf];
	
	//--- NO.5 9seg
	M_LCD_RAM[9] &=0b00000000;
	
    if((cbuf3 & 0b00001000) !=0x00 )
    	M_LCD_RAM[9] |= 0b00000001;			//D
    	
    if((cbuf3 & 0b00010000) !=0x00 )
    	M_LCD_RAM[9] |= 0b00000010;			//E
    	
    if((cbuf3 & 0b01000000) !=0x00 )
    	M_LCD_RAM[9] |= 0b00000100;			//G
    	
    if((cbuf3 & 0b00100000) !=0x00 )
    	M_LCD_RAM[9] |= 0b00001000;			//F
	
	//--- NO.5 10seg
	M_LCD_RAM[10] &=0b00001000;    	
    	
    if((cbuf3 & 0b00000100) !=0x00 )
    	M_LCD_RAM[10] |= 0b00000010;		//C
    	
    if((cbuf3 & 0b00000010) !=0x00 )
    	M_LCD_RAM[10] |= 0b00000100;		//B 
    	
    if((cbuf3 & 0b00000001) !=0x00 )
    	M_LCD_RAM[10] |= 0b00001000;		//A 
}

//--------------------------------------------------------------------------
void Lcd6_Display (unsigned char Lcd_buf)
{
	unsigned char cbuf3;
	
	//--- Lcd RAM used No.6
	cbuf3 = Lcd_Number_Table[Lcd_buf];
	
	//--- NO.6 11seg
	M_LCD_RAM[11] &=0b00000000;
	
    if((cbuf3 & 0b00001000) !=0x00 )
    	M_LCD_RAM[11] |= 0b00000001;			//D
    	
    if((cbuf3 & 0b00010000) !=0x00 )
    	M_LCD_RAM[11] |= 0b00000010;			//E
    	
    if((cbuf3 & 0b01000000) !=0x00 )
    	M_LCD_RAM[11] |= 0b00000100;			//G
    	
    if((cbuf3 & 0b00100000) !=0x00 )
    	M_LCD_RAM[11] |= 0b00001000;			//F
	
	//--- NO.6 12seg
	M_LCD_RAM[12] &=0b00001000;    	
    	
    if((cbuf3 & 0b00000100) !=0x00 )
    	M_LCD_RAM[12] |= 0b00000010;		//C
    	
    if((cbuf3 & 0b00000010) !=0x00 )
    	M_LCD_RAM[12] |= 0b00000100;		//B 
    	
    if((cbuf3 & 0b00000001) !=0x00 )
    	M_LCD_RAM[12] |= 0b00001000;		//A 
}

//--------------------------------------------------------------------------
void Lcd7_Display (unsigned char Lcd_buf)
{
	unsigned char cbuf3;
	
	//--- Lcd RAM used No.7
	cbuf3 = Lcd_Number_Table[Lcd_buf];
	
	//--- NO.7 13seg
	M_LCD_RAM[13] &=0b00000000;
	
    if((cbuf3 & 0b00001000) !=0x00 )
    	M_LCD_RAM[13] |= 0b00000001;			//D
    	
    if((cbuf3 & 0b00010000) !=0x00 )
    	M_LCD_RAM[13] |= 0b00000010;			//E
    	
    if((cbuf3 & 0b01000000) !=0x00 )
    	M_LCD_RAM[13] |= 0b00000100;			//G
    	
    if((cbuf3 & 0b00100000) !=0x00 )
    	M_LCD_RAM[13] |= 0b00001000;			//F
	
	//--- NO.7 21seg
	M_LCD_RAM[21] &=0b00001000;    	
    	
    if((cbuf3 & 0b00000100) !=0x00 )
    	M_LCD_RAM[21] |= 0b00000010;		//C
    	
    if((cbuf3 & 0b00000010) !=0x00 )
    	M_LCD_RAM[21] |= 0b00000100;		//B 
    	
    if((cbuf3 & 0b00000001) !=0x00 )
    	M_LCD_RAM[21] |= 0b00001000;		//A 
}

//--------------------------------------------------------------------------
void Lcd8_Display (unsigned char Lcd_buf)
{
	unsigned char cbuf3;
	
	//--- Lcd RAM used No.8
	cbuf3 = Lcd_Number_Table[Lcd_buf];
	
	//--- NO.8 22seg
	M_LCD_RAM[22] &=0b00000000;
	
    if((cbuf3 & 0b00001000) !=0x00 )
    	M_LCD_RAM[22] |= 0b00000001;			//D
    	
    if((cbuf3 & 0b00010000) !=0x00 )
    	M_LCD_RAM[22] |= 0b00000010;			//E
    	
    if((cbuf3 & 0b01000000) !=0x00 )
    	M_LCD_RAM[22] |= 0b00000100;			//G
    	
    if((cbuf3 & 0b00100000) !=0x00 )
    	M_LCD_RAM[22] |= 0b00001000;			//F
	
	//--- NO.8 23seg
	M_LCD_RAM[23] &=0b00001000;    	
    	
    if((cbuf3 & 0b00000100) !=0x00 )
    	M_LCD_RAM[23] |= 0b00000010;		//C
    	
    if((cbuf3 & 0b00000010) !=0x00 )
    	M_LCD_RAM[23] |= 0b00000100;		//B 
    	
    if((cbuf3 & 0b00000001) !=0x00 )
    	M_LCD_RAM[23] |= 0b00001000;		//A 
}

//--------------------------------------------------------------------------
void Lcd9_Display (unsigned char Lcd_buf)
{
	unsigned char cbuf3;
	
	//--- Lcd RAM used No.9
	cbuf3 = Lcd_Number_Table[Lcd_buf];
	
	//--- NO.9 29seg
	M_LCD_RAM[29] &=0b00000000;
	
    if((cbuf3 & 0b00000001) !=0x00 )
    	M_LCD_RAM[29] |= 0b00000001;		//A
    	
    if((cbuf3 & 0b00000010) !=0x00 )
    	M_LCD_RAM[29] |= 0b00000010;		//B
    	
    if((cbuf3 & 0b00000100) !=0x00 )
    	M_LCD_RAM[29] |= 0b00000100;		//C
    	
    if((cbuf3 & 0b00001000) !=0x00 )
    	M_LCD_RAM[29] |= 0b00001000;		//D 
    	
   	//--- NO.9 30seg
	M_LCD_RAM[30] &=0b00001000;
    	
    if((cbuf3 & 0b00100000) !=0x00 )
    	M_LCD_RAM[30] |= 0b00000001;		//F

    if((cbuf3 & 0b01000000) !=0x00 )
    	M_LCD_RAM[30] |= 0b00000010;		//G
    	
    if((cbuf3 & 0b00010000) !=0x00 )
    	M_LCD_RAM[30] |= 0b00000100;		//E  
}

//--------------------------------------------------------------------------
void Lcd10_Display (unsigned char Lcd_buf)
{
	unsigned char cbuf3;
	
	//--- Lcd RAM used No.10
	cbuf3 = Lcd_Number_Table[Lcd_buf];
	
	//--- NO.10 27seg
	M_LCD_RAM[27] &=0b00000000;
	
    if((cbuf3 & 0b00000001) !=0x00 )
    	M_LCD_RAM[27] |= 0b00000001;		//A
    	
    if((cbuf3 & 0b00000010) !=0x00 )
    	M_LCD_RAM[27] |= 0b00000010;		//B
    	
    if((cbuf3 & 0b00000100) !=0x00 )
    	M_LCD_RAM[27] |= 0b00000100;		//C
    	
    if((cbuf3 & 0b00001000) !=0x00 )
    	M_LCD_RAM[27] |= 0b00001000;		//D 
    	
   	//--- NO.10 28seg
	M_LCD_RAM[28] &=0b00001000;
    	
    if((cbuf3 & 0b00100000) !=0x00 )
    	M_LCD_RAM[28] |= 0b00000001;		//F

    if((cbuf3 & 0b01000000) !=0x00 )
    	M_LCD_RAM[28] |= 0b00000010;		//G
    	
    if((cbuf3 & 0b00010000) !=0x00 )
    	M_LCD_RAM[28] |= 0b00000100;		//E  
}

//--------------------------------------------------------------------------
void Lcd11_Display (unsigned char Lcd_buf)
{
	unsigned char cbuf3;
	
	//--- Lcd RAM used No.11
	cbuf3 = Lcd_Number_Table[Lcd_buf];
	
	//--- NO.11 25seg
	M_LCD_RAM[25] &=0b00000000;
	
    if((cbuf3 & 0b00000001) !=0x00 )
    	M_LCD_RAM[25] |= 0b00000001;		//A
    	
    if((cbuf3 & 0b00000010) !=0x00 )
    	M_LCD_RAM[25] |= 0b00000010;		//B
    	
    if((cbuf3 & 0b00000100) !=0x00 )
    	M_LCD_RAM[25] |= 0b00000100;		//C
    	
    if((cbuf3 & 0b00001000) !=0x00 )
    	M_LCD_RAM[25] |= 0b00001000;		//D 
    	
   	//--- NO.11 26seg
	M_LCD_RAM[26] &=0b00001000;
    	
    if((cbuf3 & 0b00100000) !=0x00 )
    	M_LCD_RAM[26] |= 0b00000001;		//F

    if((cbuf3 & 0b01000000) !=0x00 )
    	M_LCD_RAM[26] |= 0b00000010;		//G
    	
    if((cbuf3 & 0b00010000) !=0x00 )
    	M_LCD_RAM[26] |= 0b00000100;		//E 
}


//--------------------------------------------------------------------------
void Lcd1234_Display (unsigned int Lcd_buf,unsigned char Lcd_Unit)
{
	unsigned char cbuf0,cbuf1,cbuf2,cbuf3;
	unsigned int Ibuf0;

    cbuf0 = Lcd_buf / 1000;
    Ibuf0 = Lcd_buf % 1000;
    
    cbuf1 = Ibuf0 / 100;
    Ibuf0 = Ibuf0 % 100;
    
    cbuf2 = Ibuf0 / 10;
    cbuf3 = Ibuf0 % 10;     
    
	//               gfedcba
	//number"0" = 0b00111111
	//--- Lcd RAM used
	if(Lcd_Unit ==4)
		Lcd1_Display(cbuf0);
	else
		Lcd1_11_DisplayOff(1);
	
	if(Lcd_Unit >=3)
		Lcd2_Display(cbuf1);
	else
		Lcd1_11_DisplayOff(2);
		
	if(Lcd_Unit >=2)
		Lcd3_Display(cbuf2);
	else
		Lcd1_11_DisplayOff(3);
		
	if(Lcd_Unit >=1)
		Lcd4_Display(cbuf3);
}

//--------------------------------------------------------------------------
void Lcd5648_Display (unsigned int Lcd_buf,unsigned char Lcd_Unit)
{
	unsigned char cbuf0,cbuf1,cbuf2,cbuf3;
	unsigned int Ibuf0;

    cbuf0 = Lcd_buf / 1000;
    Ibuf0 = Lcd_buf % 1000;
    
    cbuf1 = Ibuf0 / 100;
    Ibuf0 = Ibuf0 % 100;
    
    cbuf2 = Ibuf0 / 10;
    cbuf3 = Ibuf0 % 10;     
    
	//               gfedcba
	//number"0" = 0b00111111
	//--- Lcd RAM used
	if(Lcd_Unit ==4)
		Lcd5_Display(cbuf0);
	else
		Lcd1_11_DisplayOff(5);
	
	if(Lcd_Unit >=3)
		Lcd6_Display(cbuf1);
	else
		Lcd1_11_DisplayOff(6);
		
	if(Lcd_Unit >=2)
		Lcd7_Display(cbuf2);
	else
		Lcd1_11_DisplayOff(7);
		
	if(Lcd_Unit >=1)
		Lcd8_Display(cbuf3);
}

//--------------------------------------------------------------------------
void Lcd234_Display (unsigned int Lcd_buf,unsigned char Lcd_Unit)
{
	unsigned char cbuf0,cbuf1,cbuf2;
	unsigned int Ibuf0;

    cbuf0 = Lcd_buf / 100;
    Ibuf0 = Lcd_buf %100;
    
    cbuf1 = Ibuf0 / 10;
    cbuf2 = Ibuf0 % 10; 
    
	//               gfedcba
	//number"0" = 0b00111111
	//--- Lcd RAM used

	if(Lcd_Unit ==3)
		Lcd2_Display(cbuf0);
	else
		Lcd1_11_DisplayOff(2);
	
	if(Lcd_Unit >=2)
		Lcd3_Display(cbuf1);
	else
		Lcd1_11_DisplayOff(3);
		
	if(Lcd_Unit >=1)
		Lcd4_Display(cbuf2);	
}


//--------------------------------------------------------------------------
void Lcd91011_Display (unsigned int Lcd_buf,unsigned char Lcd_Unit)
{
	unsigned char cbuf0,cbuf1,cbuf2;
	unsigned int Ibuf0;

    cbuf0 = Lcd_buf / 100;
    Ibuf0 = Lcd_buf %100;
    
    cbuf1 = Ibuf0 / 10;
    cbuf2 = Ibuf0 % 10; 
    
	//               gfedcba
	//number"0" = 0b00111111
	//--- Lcd RAM used

	if(Lcd_Unit ==3)
		Lcd9_Display(cbuf0);
	else
		Lcd1_11_DisplayOff(9);
	
	if(Lcd_Unit >=2)
		Lcd10_Display(cbuf1);
	else
		Lcd1_11_DisplayOff(10);
		
	if(Lcd_Unit >=1)
		Lcd11_Display(cbuf2);
}

//--------------------------------------------------------------------------
void Lcd1_2_Display (unsigned char Lcd_buf,unsigned char Lcd_Unit)
{
	unsigned char cbuf0,cbuf1;
      
    cbuf1 = Lcd_buf /10;
    cbuf0 = Lcd_buf %10;
    
	//               gfedcba
	//number"0" = 0b00111111
	//--- Lcd RAM used
	if(Lcd_Unit ==2)
		Lcd1_Display(cbuf1);
	else
		Lcd1_11_DisplayOff(1);
	
	if(Lcd_Unit >=1)
		Lcd2_Display(cbuf0);
}

//--------------------------------------------------------------------------
void Lcd34_Display (unsigned char Lcd_buf,unsigned char Lcd_Unit)
{
	unsigned char cbuf0,cbuf1;
      
    cbuf1 = Lcd_buf /10;
    cbuf0 = Lcd_buf %10;
    
	//               gfedcba
	//number"0" = 0b00111111
	//--- Lcd RAM used
	if(Lcd_Unit ==2)
		Lcd3_Display(cbuf1);
	else
		Lcd1_11_DisplayOff(3);
	
	if(Lcd_Unit >=1)
		Lcd4_Display(cbuf0);
}

//--------------------------------------------------------------------------
void Lcd56_Display (unsigned char Lcd_buf,unsigned char Lcd_Unit)
{
	unsigned char cbuf0,cbuf1;
      
    cbuf1 = Lcd_buf /10;
    cbuf0 = Lcd_buf %10;
    
	//               gfedcba
	//number"0" = 0b00111111
	//--- Lcd RAM used
	if(Lcd_Unit ==2)
		Lcd5_Display(cbuf1);
	else
		Lcd1_11_DisplayOff(5);
	
	if(Lcd_Unit >=1)
		Lcd6_Display(cbuf0);
}

//--------------------------------------------------------------------------
void Lcd78_Display (unsigned char Lcd_buf,unsigned char Lcd_Unit)
{
	unsigned char cbuf0,cbuf1;
      
    cbuf1 = Lcd_buf /10;
    cbuf0 = Lcd_buf %10;
    
	//               gfedcba
	//number"0" = 0b00111111
	//--- Lcd RAM used
	if(Lcd_Unit ==2)
		Lcd7_Display(cbuf1);
	else
		Lcd1_11_DisplayOff(7);
	
	if(Lcd_Unit >=1)
		Lcd8_Display(cbuf0);
}

//--------------------------------------------------------------------------
void Lcd910_Display (unsigned char Lcd_buf,unsigned char Lcd_Unit)
{
	unsigned char cbuf0,cbuf1;
      
    cbuf1 = Lcd_buf /10;
    cbuf0 = Lcd_buf %10;
    
	//               gfedcba
	//number"0" = 0b00111111
	//--- Lcd RAM used
	if(Lcd_Unit ==2)
		Lcd9_Display(cbuf1);
	else
		Lcd1_11_DisplayOff(9);
	
	if(Lcd_Unit >=1)
		Lcd10_Display(cbuf0);	
}

//--------------------------------------------------------------------------
void Lcd1_11_DisplayOff (unsigned char Lcd_buf)
{
	unsigned char cbuf0,cbuf1,cbuf2,cbuf3;
	
	if(Lcd_buf ==1)
	{
		cbuf0 =2;
	}
	else if(Lcd_buf ==2)
	{
		cbuf0 =3;
		cbuf1 =4;
	}
	else if(Lcd_buf ==3)
	{
		cbuf0 =5;
		cbuf1 =6;	
	}
	else if(Lcd_buf ==4)
	{
		cbuf0 =7;
		cbuf1 =8;	
	}
	else if(Lcd_buf ==5)
	{
		cbuf0 =9;
		cbuf1 =10;
	}
	else if(Lcd_buf ==6)
	{
		cbuf0 =11;
		cbuf1 =12;	
	}
	else if(Lcd_buf ==7)
	{
		cbuf0 =13;
		cbuf1 =21;
	}
	else if(Lcd_buf ==8)
	{
		cbuf0 =22;
		cbuf1 =23;		
	}
	else if(Lcd_buf ==9)
	{
		cbuf0 =29;
		cbuf1 =30;
	}
	else if(Lcd_buf ==10)
	{
		cbuf0 =27;
		cbuf1 =28;
	}
	else if(Lcd_buf ==11)
	{
		cbuf0 =25;
		cbuf1 =26;	
	}

	if(Lcd_buf ==1)
	{
		M_LCD_RAM[cbuf0] &= ~0b00001110;
	}	
	else if((Lcd_buf >=2) && (Lcd_buf <=8))
	{
		M_LCD_RAM[cbuf1] &= ~0b00001110;
		M_LCD_RAM[cbuf0] &= ~0b00001111;
	}
	else if((Lcd_buf >=9) && (Lcd_buf <=11))
	{
		M_LCD_RAM[cbuf0] &= ~0b00001111;
		M_LCD_RAM[cbuf1] &= ~0b00000111;
	}	
}

////--------------------------------------------------------------------------
//void Lcd_Year_Process (unsigned char Year)
//{
//	Lcd56_Display(20,2);
//	Lcd78_Display(Year,2);
//}
//
////--------------------------------------------------------------------------
//void Lcd_Clock_Process (unsigned char Hour,unsigned char Minutes)
//{
//	unsigned char Cbuf0;
//	unsigned int  Ibuf0;
//	//--- time " : " flash
//	if((M_Task == C_RTCModeSettingMode) || ((M_Task == C_MemoryMode) && (M_TaskBuf0 == 3)))
//	{
//		M_LCD_RAM[6] |= 0x01;		//"col" on	
//	}
//	else
//	{
//		if(F_500ms_RTC)
//			M_LCD_RAM[6] |= 0x01;		//"col" on
//		else
//			M_LCD_RAM[6] &= ~0x01;		//"col" off
//	}
//		
//
//	//--- Lcd 5/6/7/8
//	if(C_TimeMode)
//	{
//		//---12H
//		if(Hour >= 12)
//		{
//			M_LCD_RAM[8] &= ~0x01;		//"AM" off
//			M_LCD_RAM[10] |= 0x01;		//"PM" on
//			if((Hour - 12) ==0)			// = 0:00 23->24
//				Cbuf0 = 12;
//			else
//				Cbuf0 = Hour - 12;
//		}
//		else
//		{
//			M_LCD_RAM[8] |= 0x01;		//"AM" on
//			M_LCD_RAM[10] &= ~0x01;		//"PM" off
//			if(Hour ==0)				// = 0:00 23->24
//				Cbuf0 = 12;
//			else
//				Cbuf0 = Hour;
//
//		}
//
//	  	//--- display Hour
//	  	Ibuf0 = Cbuf0;
//		if(Ibuf0 > 9)
//			Cbuf0 = 2;
//		else
//			Cbuf0 = 1;
//		Lcd1_2_Display(Ibuf0,Cbuf0);	
//	}
//	else
//	{
//		M_LCD_RAM[8] &= ~0x01;		//"AM" off
//		M_LCD_RAM[10] &= ~0x01;		//"PM" off
//		
//		//---24H
//	  	//--- display Hour
//	  	Ibuf0 = Hour;
//		if(Ibuf0 > 9)
//			Cbuf0 = 2;
//		else
//			Cbuf0 = 1;
//		Lcd1_2_Display(Ibuf0,Cbuf0);	
//	}
//	
//	//--- display Minutes
//	Lcd34_Display(Minutes,2);	
//
//}
//
//////--------------------------------------------------------------------------
//void Lcd_Month_Day_Process (unsigned char Month,unsigned char Days)
//{
//	unsigned char Cbuf0;
//	unsigned int  Ibuf0;
//	
//	//--- DD - MM
//	if(C_DateMode)
//	{
//		M_LCD_RAM[21] |= 0x01;		//"p2" on
//		
//	  	//--- display Day
//	  	Ibuf0 = Days;
//		if(Ibuf0 > 9)
//			Cbuf0 = 2;
//		else
//			Cbuf0 = 1;
//		Lcd56_Display(Ibuf0,Cbuf0);
//		
//	  	//--- display Month
//	  	Ibuf0 = Month;
//		if(Ibuf0 > 9)
//			Cbuf0 = 2;
//		else
//			Cbuf0 = 1;
//		Lcd78_Display(Ibuf0,Cbuf0);
//	}
//	//--- MM - DD
//	else
//	{
//		M_LCD_RAM[21] |= 0x01;		//"p2" on	
//		
//	  	//--- display Month
//	  	Ibuf0 = Month;
//		if(Ibuf0 > 9)
//			Cbuf0 = 2;
//		else
//			Cbuf0 = 1;
//		Lcd56_Display(Ibuf0,Cbuf0);
//		
//	  	//--- display Day
//	  	Ibuf0 = Days;
//		if(Ibuf0 > 9)
//			Cbuf0 = 2;
//		else
//			Cbuf0 = 1;
//		Lcd78_Display(Ibuf0,Cbuf0);
//	}		
//	
//	
//}
	
////--------------------------------------------------------------------------
//void Lcd_Display_Bat (void)
//{
//	if(M_BatCnt	==0)	
//		M_LCD_RAM[17] = 0x0f;		//"bat" on
//	if(M_BatCnt	==1)	
//		M_LCD_RAM[17] = 0x09;		//"bat" on
//	if(M_BatCnt	==2)	
//		M_LCD_RAM[17] = 0x08;		//"bat" on	
//}
////--------------------------------------------------------------------------
//void Lcd_Display_Hi (void)
//{
//	//--- display "H"
//	M_LCD_RAM[29] |= 0x06;
//	M_LCD_RAM[30] |= 0x07;
//	
//	//--- display "i"
//	M_LCD_RAM[28] |= 0x05;
//	//M_LCD_RAM[27] |= 0x00;
//}
//
////--------------------------------------------------------------------------
//void Lcd_Display_Lo (void)
//{
//	//--- display "L"
//	M_LCD_RAM[29] |= 0x08;
//	M_LCD_RAM[30] |= 0x05;
//		
//	//--- display "o"
//	M_LCD_RAM[27] |= 0x0c;
//	M_LCD_RAM[28] |= 0x06;		
//}
//
////--------------------------------------------------------------------------
//void Lcd_Display34_Hi (void)
//{
//	//--- display "H"
//	M_LCD_RAM[6] |= 0x06;
//	M_LCD_RAM[5] |= 0x0e;
//	
//	//--- display "i"
//	M_LCD_RAM[7] |= 0x0a;
//}
//
////--------------------------------------------------------------------------
//void Lcd_Display34_Lo (void)
//{
//	//--- display "L"
//	M_LCD_RAM[5] |= 0x0b;
//		
//	//--- display "o"
//	M_LCD_RAM[8] |= 0x02;
//	M_LCD_RAM[7] |= 0x07;	
//}
////--------------------------------------------------------------------------
//void Lcd_Display_DEL (void)
//{
//	//--- display "d"
//	Lcd9_Display(0x0d);
//	//--- display "E"
//	Lcd10_Display(0x0e);
//	//--- display "L"
//	M_LCD_RAM[25] |= 0x08;
//	M_LCD_RAM[26] |= 0x05;
//}
//
////--------------------------------------------------------------------------
//void Lcd_Display_PC (void)
//{
//	M_LCD_RAM[22] = 0xf8;
//
//	//--- display "C"
//	Lcd3_Display(0x0c);
//	
//	Lcd1_11_DisplayOff(1);
//	Lcd1_11_DisplayOff(4);
//}
//
////--------------------------------------------------------------------------
//void Lcd_Display_Tes (void)
//{
//	//--- display "t"
//	M_LCD_RAM[29] |= 0x08;
//	M_LCD_RAM[30] |= 0x07;
//	//--- display "E"
//	Lcd10_Display(0x0e);
//	//--- display "s"
//	Lcd11_Display(0x05);			
//}

////--------------------------------------------------------------------------
//void Lcd_Display_Load (void)
//{
//	//--- display "L"
//	M_LCD_RAM[21] = 0x4a;
//	//--- display "o"
//	Lcd2_Display(0);
//	//--- display "a"
//	Lcd3_Display(0x0a);
//	//--- display "d"
//	Lcd4_Display(0x0d);		
//}
//
////--------------------------------------------------------------------------
//void Lcd_Display_OFF (void)
//{
//	//--- display "0"
//	Lcd9_Display(0);
//	//--- display "F"
//	Lcd10_Display(0x0f);
//	//--- display "F"
//	Lcd11_Display(0x0f);	
//}
//
////--------------------------------------------------------------------------
//void Lcd_Unit (void)
//{
//	//--- display mmol or mgdl
//	if((M_Unit & 0x01) !=0)
//	{
//		M_LCD_RAM[24] |= 0x08;	//on "mmol"
//		M_LCD_RAM[24] &= ~0x04;	//off "mgdl"
//	}
//	else
//	{
//		M_LCD_RAM[24] &= ~0x08;	//off "mmol"
//		M_LCD_RAM[24] |= 0x04;	//on "mgdl"
//	}
//}
//
////--------------------------------------------------------------------------
//void Lcd_Display_Fln (void)
//{
//	//--- display "F"
//	Lcd9_Display(0x0f);
//	//--- display "l"
//	M_LCD_RAM[28] |= 0x05;
//	//--- display "n"
//	M_LCD_RAM[25] |= 0x04;
//	M_LCD_RAM[26] |= 0x06;	
//}

//--------------------------------------------------------------------------
void Lcd_GmRangeCheck(void)
{
	if(M_GM_data >M_GM_Range_Hi)
		M_LCD_RAM[26] |= 0x08;
	else if(M_GM_data <M_GM_Range_Low)
		M_LCD_RAM[31] |= 0x08;
	else
		M_LCD_RAM[30] |= 0x08;		
}

////--------------------------------------------------------------------------
//void Lcd_Glucose(unsigned int data)
//{
//	unsigned char Cbuf0;
//	unsigned int  Ibuf0,Ibuf1;
//	
//	if((M_Unit & 0x01) !=0)
//	{
//		//---mmol
//		Ibuf1 = data;	
//		Ibuf1 *= 100;
//		Ibuf1 /= 18;
//		Ibuf0 = Ibuf1 / 10;
//		Ibuf1 %= 10;
//		//---four out five in
//		if(Ibuf1 >=5)
//			Ibuf0 ++;
//				
//    	M_LCD_RAM[28] |= 0x08;     //on "P4"
//    	
//    	if(Ibuf0 > 99)
//    		Cbuf0 = 3;
//		else if(Ibuf0 > 9)
//			Cbuf0 = 2;
//		else
//			Cbuf0 = 2;
//		
//		Lcd91011_Display(Ibuf0,Cbuf0);
//	}
//	else
//	{
//		//---mgdl
//		Ibuf0 = data;
//		
//    	if(Ibuf0 > 99)
//    		Cbuf0 = 3;
//		else if(Ibuf0 > 9)
//			Cbuf0 = 2;
//		else
//			Cbuf0 = 1;
//		
//		Lcd91011_Display(Ibuf0,Cbuf0);	
//	}
//}
#endif

#include "include.h"
//---- command
const unsigned char Table_Glucose[]={"Glucose\r\n"};
const unsigned char Table_Hi[]={"Hi."};
const unsigned char Table_Lo[]={"Lo."};
const unsigned char Table_mgdl[]={"mg_dL\r\n"};
const unsigned char Table_mmol[]={"mmo_L\r\n"};
const unsigned char Table_BootLoad[]={"BootLoad"};
const unsigned char Table_OK[]={"OK"};





//--------------------------------------------------------------------------
//unsigned char DataCompare (unsigned char *Targetdata,unsigned char *Sourcedata,unsigned char length)
//{
//	unsigned char count,feedback;
//	
//	feedback =1;
//	for(count =0 ;count < length ;count++)
//	{
//		if(Targetdata[count] != Sourcedata[count])
//			feedback =0;	
//	}
//	
//	return feedback;
//}

//--------------------------------------------------------------------------
//unsigned char ChecksumCompare (unsigned char *Sourcedata,unsigned char start,unsigned char length)
//{
//	unsigned char count,checksum,feedback,temp;
//	
//	feedback =1;
//	
//	checksum =0;
//	for(count =0; count < length; count++)
//		checksum ^=Sourcedata[start + count];
//	
//	//--- move source data
//	if(Sourcedata[start + count] > '9')
//		temp  = (Sourcedata[start + count] -0x41 + 10) << 4;
//	else
//		temp  = (Sourcedata[start + count] -0x30) << 4;
//	
//	if(Sourcedata[start + count + 1] > '9')
//		temp  |= Sourcedata[start + count + 1] -0x41 + 10;
//	else
//		temp  |= Sourcedata[start + count + 1] -0x30;	
//		
//		
//	if(checksum != temp)
//		feedback =0;
//	
//	return feedback;
//}

////--------------------------------------------------------------------------
//void MoveData (const unsigned char *Targetdata,const unsigned char *Sourcedata,unsigned char start,unsigned char length)
//{
//	unsigned char count;
//	
//	for(count =0 ;count <= length ;count++)
//		Sourcedata[start + count] = Targetdata[count];
//}
//
////--------------------------------------------------------------------------
//unsigned char HexToAscii(unsigned char data)
//{
//	unsigned char feedback;
//	if(data < 10)
//		feedback = data + 0x30;
//	else
//		feedback = (data - 10) + 0x41;
//		
//	return feedback;
//}
//
////--------------------------------------------------------------------------
//unsigned char AsciiToHex(unsigned char data)
//{
//	unsigned char feedback;
//	
//	if(data <= '9')
//		feedback = data - 0x30;
//	else
//		feedback = (data - 0x41) + 10 ;
//		
//	return feedback;
//}

////--------------------------------------------------------------------------
//void Send_Ack (void)
//{
//	unsigned char temp,index;
//	
//	MoveData(&Table_at_ack[0],&M_UART_TxFIFO[0],0,6);
//	index =6;
//	MoveData(&Table_end[0],&M_UART_TxFIFO[0],index,5);
//	index +=5;
//	
//	M_UART_TxLength =index;
//	M_UART_TxIndex =0;				
//	_utxr_rxr= M_UART_TxFIFO[0];
//	
//	temp =1;
//	do
//	{
//		GCC_CLRWDT();
//		if(M_UART_TxIndex >= M_UART_TxLength)
//			temp =0;
//	}
//	while(temp);	
//}
//
////--------------------------------------------------------------------------
//void Send_Nak (void)
//{
//	unsigned char temp,index;
//	
//	MoveData(&Table_at_nak[0],&M_UART_TxFIFO[0],0,6);
//	index =6;
//	MoveData(&Table_end[0],&M_UART_TxFIFO[0],index,5);
//	index +=5;
//	
//	M_UART_TxLength =index;
//	M_UART_TxIndex =0;				
//	_utxr_rxr= M_UART_TxFIFO[0];
//	
//	temp =1;
//	do
//	{
//		GCC_CLRWDT();
//		if(M_UART_TxIndex >= M_UART_TxLength)
//			temp =0;
//	}
//	while(temp);	
//}
//
////--------------------------------------------------------------------------
//void Send_Repeat (void)
//{
//	unsigned char temp,index;
//	
//	MoveData(&Table_at_repeat[0],&M_UART_TxFIFO[0],0,9);
//	index =9;
//	MoveData(&Table_end[0],&M_UART_TxFIFO[0],index,5);
//	index +=5;
//	
//	M_UART_TxLength =index;
//	M_UART_TxIndex =0;				
//	_utxr_rxr= M_UART_TxFIFO[0];
//	
//	temp =1;
//	do
//	{
//		GCC_CLRWDT();
//		if(M_UART_TxIndex >= M_UART_TxLength)
//			temp =0;
//	}
//	while(temp);	
//}
//
////--------------------------------------------------------------------------
//void Send_Waitfeedback (void)
//{
//	unsigned char temp,index;
//	
//	MoveData(&Table_at_[0],&M_UART_TxFIFO[0],0,4);
//	index =4;
//	MoveData(&Table_end[0],&M_UART_TxFIFO[0],index,5);
//	index +=5;
//	
//	M_UART_TxLength =index;
//	M_UART_TxIndex =0;				
//	_utxr_rxr= M_UART_TxFIFO[0];
//	
//	temp =1;
//	do
//	{
//		GCC_CLRWDT();
//		if(M_UART_TxIndex >= M_UART_TxLength)
//			temp =0;
//	}
//	while(temp);	
//}
//
////--------------------------------------------------------------------------
//void Send_Nothing (void)
//{
//	unsigned char temp,index;
//	
//	MoveData(&Table_at_nothing[0],&M_UART_TxFIFO[0],0,10);
//	index =10;
//	MoveData(&Table_end[0],&M_UART_TxFIFO[0],index,5);
//	index +=5;
//	
//	M_UART_TxLength =index;
//	M_UART_TxIndex =0;				
//	_utxr_rxr= M_UART_TxFIFO[0];
//	
//	temp =1;
//	do
//	{
//		GCC_CLRWDT();
//		if(M_UART_TxIndex >= M_UART_TxLength)
//			temp =0;
//	}
//	while(temp);	
//}

//--------------------------------------------------------------------------
//unsigned char MoveDataToDec (volatile unsigned char *Targetdata, unsigned char index, unsigned int data)
//{
//	
//    data %= 10000 ;
//    
//    if((data / 1000) !=0)
//    {
//    	Targetdata[index] = AsciiTab[data/1000];
//    	index++;
//    	
//    	data %= 1000 ;
//    	Targetdata[index] = AsciiTab[data/100];
//    	index++;
//    	
//    	data %= 100 ;
//    	Targetdata[index] = AsciiTab[data/10];
//    	index++;
//    	
//	    data %= 10 ;
//		Targetdata[index] = AsciiTab[data];
//		index++;
//		
//		return index;	
//    }
//    
//    data %= 1000 ;
//    
//    if((data / 100) !=0)
//    {
//    	Targetdata[index] = AsciiTab[data/100];
//    	index++;
//    	
//    	data %= 100 ;
//    	Targetdata[index] = AsciiTab[data/10];
//    	index++;
//    	
//	    data %= 10 ;
//		Targetdata[index] = AsciiTab[data];
//		index++;
//		
//		return index;	
//    }
//    
//    data %= 100 ;
//    
//    if((data / 10) !=0)
//    {
//    	Targetdata[index] = AsciiTab[data/10];
//    	index++;
//    	
//	    data %= 10 ;
//		Targetdata[index] = AsciiTab[data];
//		index++;
//		
//		return index;	
//    }
//    
//    data %= 10 ;
//	Targetdata[index] = AsciiTab[data];
//	index++;
//	
//	return index;
//}

//--------------------------------------------------------------------------
//unsigned char chechsum_check (volatile unsigned char *data,unsigned char Length)
//{
//	volatile unsigned char checksum,count;
//	
//	checksum =0;
//	for(count =0; count < (Length -1); count++)
//		checksum += data[count];
//		
//	if(checksum == (data[count]))
//		return 1;
//	else
//		return 0;
//}


//--------------------------------------------------------------------------
//void PCLINKMode_Process (void)
//{
//	unsigned char	buf[6];
//	unsigned char	checksum,index;
//	unsigned char  	Cbuf0,Cbuf1,count,count1;
//	
//	unsigned int	Ibuf0,Ibuf1;
//	unsigned long	Lbuf0;
//		
//	switch (M_TaskBuf0)
//	{
//		//---------------------------------
//		//--- display  "PC"       ----
//		case 0:
//		{
//	      	M_RTC_display++;		//base 10ms
//	      	
//			if(M_RTC_display ==1)
//			{
//	      		//---Lcd All on
//	      		LCD_Clear(ON);				     	
//			}
//			else if(M_RTC_display >=300)
//			{
//				if(F_Low_battery_Act ==0)
//	 	  		{
//					M_RTC_display =0;
//			     	M_TaskBuf0 =1;
//			     	M_TaskBuf1 =0;
//			     	M_No_Active_Cnt =0;
//			     	
//					//--- initial uart0
//					fun_UART0PowerOnInit();
//					//---Lcd All off
//		      		LCD_Clear(OFF);
//	 	  		}
//	 	  		else
//	 	  		{
//					M_Error_Task = 6;
//					M_RTC_display =0;
//			     	M_TaskBuf0 = 8;
//			     	M_TaskBuf1 =0;
//			     	//M_MealMode =0;
//			     	M_No_Active_Cnt =0;
//					//---Lcd All off
//		      		LCD_Clear(OFF);
//		      		
//	      			//--- lcd update clear flag
//					F_LcdUpdateBuf =0;
//					F_LcdUpdate =0;
//	 	  		}
//	 	  		
//			}
//			
//			break;   //case 0 end
//		}
//      
//
//		case 1:
//		{
//			if(M_RTC_display <2)
//				M_RTC_display++;
//			if(M_RTC_display ==1)
//			{
//				Show_BigString( "LnK" ) ;
//				//Lcd_Display_LNK();
//				//--- update lcd
//				F_LcdUpdate =1;	
//			}
//
//			//--- uart receive
//			if(F_UartDataComing)
//			{
//				F_UartDataComing =0;
//				
//				if(M_UART_RxFIFO[0] == 0x05)
//				{
//					if(M_GM_data_Record !=0)
//					{
//						M_RTC_display =0; 
//						M_TaskBuf0 =2;
//						M_TaskBuf1 =0;
//						//---Lcd All off
//			      		LCD_Clear(OFF);
//			      		//--- display PC
//			      		Show_BigString( "PC " ) ;
//						//Lcd_Display_PC();
//						//--- update lcd
//						F_LcdUpdate =1;	
//					}
//					else
//					{
//						//--- No record
//						Cbuf1 =0;
//						
//						M_UART_TxFIFO[Cbuf1] = 0x04;
//						Cbuf1++;
//						
//						M_UART_TxLength =Cbuf1;
//				  		M_UART_TxIndex =0;				
//						_txr_rxr0= M_UART_TxFIFO[0];
//						
//						Cbuf0 =1;
//						do
//						{
//							GCC_CLRWDT();
//							if(M_UART_TxIndex >= M_UART_TxLength)
//								Cbuf0 =0;
//						}
//						while(Cbuf0);
//						
//						M_UartInsertCnt = 250;
//						
//						M_No_Active_Cnt = 0;
//						//-- quit pclink mode
//					    M_Task = C_OffMode;           //quit MemoryMode mode
//					    M_TaskBuf0 =0;
//						M_TaskBuf1 =0;
//						M_Error_Task =0;
//					    M_RTC_display = 0;  
//	
//					}
//					
//				}
//				//--- writer Serial Number
//				else if(M_UART_RxFIFO[0] == 0x56)
//				{
//					if(M_UART_RxFIFO[1] <= 0x10)
//					{
//						M_Length = M_UART_RxFIFO[1];
//						//*********************
//						//--- send Ready 0x57
//						Cbuf1 =0;
//						M_UART_TxFIFO[Cbuf1] = 0x57;
//						Cbuf1++;
//						
//						M_UART_TxLength =Cbuf1;
//				  		M_UART_TxIndex =0;				
//						_txr_rxr0= M_UART_TxFIFO[0];
//						
//						Cbuf0 =1;
//						do
//						{
//							GCC_CLRWDT();
//							if(M_UART_TxIndex > M_UART_TxLength)
//								Cbuf0 =0;
//						}
//						while(Cbuf0);
//						
//						M_UartInsertCnt = 250;
//						
//						M_RTC_display =0; 
//						M_TaskBuf0 =3;
//						M_TaskBuf1 =0;
//						
//					}
//					else
//					{
//						//*********************
//						//--- send fail 0xff
//						Cbuf1 =0;
//						M_UART_TxFIFO[Cbuf1] = 0xff;
//						Cbuf1++;
//						
//						M_UART_TxLength =Cbuf1;
//				  		M_UART_TxIndex =0;				
//						_txr_rxr0= M_UART_TxFIFO[0];
//						
//						Cbuf0 =1;
//						do
//						{
//							GCC_CLRWDT();
//							if(M_UART_TxIndex > M_UART_TxLength)
//								Cbuf0 =0;
//						}
//						while(Cbuf0);
//						
//						M_UartInsertCnt = 250;
//					}
//						
//				}
//				//--- read Serial Number
//				else if(M_UART_RxFIFO[0] == 0x58)
//				{
//					if(chechsum_check(&SerialNumber_Table[1],&SerialNumber_Table[0]))
//					{
//						for(count =0; count <= SerialNumber_Table[0]; count++)
//						{
//							M_UART_TxFIFO[count] = SerialNumber_Table[count];	
//							Cbuf1++;
//						}
//						
//					}
//					else
//					{
//						if(chechsum_check(&SerialNumber_Table[1 + 0x20],SerialNumber_Table[0 + 0x20]))
//						{
//							for(count =0; count <= SerialNumber_Table[0 + 0x20]; count++)
//							{
//								M_UART_TxFIFO[count] = SerialNumber_Table[count + 0x20];	
//								Cbuf1++;
//							}
//						}
//						else
//						{
//							//*********************
//							//--- send fail 0xff
//							Cbuf1 =0;
//							M_UART_TxFIFO[Cbuf1] = 0xff;
//							Cbuf1++;	
//						}
//						
//					}
//					
////					M_Length = SerialNumber_Table[0];
////					Cbuf1 =0;
////					checksum =0;
////					for(count =0; count <= M_Length -1; count++)
////					{
////						M_UART_TxFIFO[count] = SerialNumber_Table[count];
////						if(count >0)
////							checksum += SerialNumber_Table[count];
////							
////						Cbuf1++;
////						
////					}
////					
////					M_UART_TxFIFO[count] = checksum;
////					Cbuf1++;
//					
//					M_UART_TxLength =Cbuf1;
//			  		M_UART_TxIndex =0;				
//					_txr_rxr0= M_UART_TxFIFO[0];
//					
//					Cbuf0 =1;
//					do
//					{
//						GCC_CLRWDT();
//						if(M_UART_TxIndex > M_UART_TxLength)
//							Cbuf0 =0;
//					}
//					while(Cbuf0);
//					
//					M_UartInsertCnt = 250;	
//					
//				}
//				else if(DataCompare(&Table_BootLoad[0],&M_UART_RxFIFO[0],8))
//				{
//					Flash_Store_PageErase_Process(0x7fc0);
//					
//					//--- Send "OK"
//					Cbuf1 =0;
//					MoveData(&Table_OK[0],&M_UART_TxFIFO[0],Cbuf1,2);
//					Cbuf1 +=2;
//					
//					M_UART_TxLength =Cbuf1;
//			  		M_UART_TxIndex =0;				
//					_txr_rxr0= M_UART_TxFIFO[0];
//					
//					Cbuf0 =1;
//					do
//					{
//						GCC_CLRWDT();
//						if(M_UART_TxIndex >= M_UART_TxLength)
//							Cbuf0 =0;
//					}
//					while(Cbuf0);
//
//					//--- Go to watchdog time out
//					while(1);
//				}
//							
//				
//				M_UART_RxIndex =0;
//			}
//			
//			break;
//		}
//		
//		case 2:
//		{		
//			//*********************
//			//--- send head code
//			Cbuf1 =0;
//			M_UART_TxFIFO[Cbuf1] = 0x01;
//			Cbuf1++;
//			
//			MoveData(&Table_Glucose[0],&M_UART_TxFIFO[0],Cbuf1,9);
//			Cbuf1 +=9;
//			
//			M_UART_TxFIFO[Cbuf1] = 0x02;
//			Cbuf1++;
//			
//			M_UART_TxLength =Cbuf1;
//	  		M_UART_TxIndex =0;				
//			_txr_rxr0= M_UART_TxFIFO[0];
//			
//			Cbuf0 =1;
//			do
//			{
//				GCC_CLRWDT();
//				if(M_UART_TxIndex > M_UART_TxLength)
//					Cbuf0 =0;
//			}
//			while(Cbuf0);
//			
//			M_UartInsertCnt = 250;
//			
//			
//			M_GM_data_Record_buf = M_GM_Record_current;
//			for(count =1; count < M_GM_data_Record + 1; count++)
//			{
//				GCC_CLRWDT();
//					
////				if(M_GM_data_Record != M_GM_Record_current)
////				{
////					if(Ibuf0 <= M_GM_Record_current)
////						M_GM_data_Record_buf = (M_GM_Record_current - Ibuf0) +1;
////					else
////						M_GM_data_Record_buf = (M_GM_data_Record + M_GM_Record_current) - Ibuf0 +1;
////				}
////				else
////					M_GM_data_Record_buf = M_GM_Record_current - Ibuf0 +1;
//			
//	 			//-- load start address
//	 			Ibuf1 = ((M_GM_data_Record_buf - 1) * 4); 
//	         	Ibuf1 += C_FlashDataOffset;     //add flash offset addrss = save current data address
//	
//		     	//-- load time recordH
//		     	Lbuf0 = Flash_Store_Read_Process(Ibuf1);  		//buf1/buf0/buf3/buf2
//	         	Lbuf0 <<=16;
//	        
//	         	//--- load time recordL
//	         	Ibuf1++;
//	         	Lbuf0 |= Flash_Store_Read_Process(Ibuf1);  		//buf1/buf0/buf3/buf2
//	
//	 	 	 	//--- load Glucose data
//			 	Ibuf1++;
//	         	M_GM_data = Flash_Store_Read_Process(Ibuf1);  //buf1/buf0/buf3/buf2	
//	
//		        //---秒數轉日�?
//		        SecondToDate(Lbuf0,buf);
//			
//				Cbuf1 =0;
//				//*********************
//				//--- load record
//				Cbuf1 = MoveDataToDec(&M_UART_TxFIFO[0],Cbuf1,count);				
//				M_UART_TxFIFO[Cbuf1] = ',';
//				Cbuf1++;
//				
//				//*********************
//				//--- load year
//				Cbuf1 = MoveDataToDec(&M_UART_TxFIFO[0],Cbuf1,(buf[5] + 2000));
//				M_UART_TxFIFO[Cbuf1] = ',';
//				Cbuf1++;
//				
//				//*********************
//				//--- load month
//				Cbuf1 = MoveDataToDec(&M_UART_TxFIFO[0],Cbuf1,buf[4]);
//				M_UART_TxFIFO[Cbuf1] = ',';
//				Cbuf1++;
//				
//				//*********************
//				//--- load day
//				Cbuf1 = MoveDataToDec(&M_UART_TxFIFO[0],Cbuf1,buf[3]);
//				M_UART_TxFIFO[Cbuf1] = ',';
//				Cbuf1++;
//				
//				//*********************
//				//--- load hour
//				Cbuf1 = MoveDataToDec(&M_UART_TxFIFO[0],Cbuf1,buf[2]);
//				M_UART_TxFIFO[Cbuf1] = ',';
//				Cbuf1++;
//				
//				//*********************
//				//--- load min
//				Cbuf1 = MoveDataToDec(&M_UART_TxFIFO[0],Cbuf1,buf[1]);
//				M_UART_TxFIFO[Cbuf1] = ',';
//				Cbuf1++;
//				
//				//*********************
//				//--- load Glucose vaule
//				if((M_GM_data >= 20) && (M_GM_data <= 600))
//				{
//					if((M_Unit & 0x01) !=0)
//					{
//						//---mmol
//						Ibuf1 = M_GM_data;	
//						Ibuf1 *= 100;
//						Ibuf1 /= 18;
//						Ibuf0 = Ibuf1 / 10;
//						Ibuf1 %= 10;
//						//---four out five in
//						if(Ibuf1 >=5)
//							Ibuf0 ++;
//							
//						Cbuf1 = MoveDataToDec(&M_UART_TxFIFO[0],Cbuf1,(Ibuf0 / 10));
//						M_UART_TxFIFO[Cbuf1] = '.';
//						Cbuf1++;
//						Cbuf1 = MoveDataToDec(&M_UART_TxFIFO[0],Cbuf1,(Ibuf0 % 10));
//						M_UART_TxFIFO[Cbuf1] = ',';
//						Cbuf1++;
//
//					}
//					else
//					{
//						//---mgdl
//						Cbuf1 = MoveDataToDec(&M_UART_TxFIFO[0],Cbuf1,M_GM_data);
//						M_UART_TxFIFO[Cbuf1] = ',';
//						Cbuf1++;	
//					}
//					
//				}
//				else if(M_GM_data < 20)
//				{
//					MoveData(&Table_Lo[0],&M_UART_TxFIFO[0],Cbuf1,3);
//					Cbuf1 +=3;
//				}
//				else if(M_GM_data > 600)
//				{
//					MoveData(&Table_Hi[0],&M_UART_TxFIFO[0],Cbuf1,3);
//					Cbuf1 +=3;
//				}
//				
//				//*********************
//				//--- load unit
//				if((M_Unit & 0x01) !=0)
//				{
//					MoveData(&Table_mmol[0],&M_UART_TxFIFO[0],Cbuf1,7);
//					Cbuf1 +=7;	
//				}
//				else
//				{
//					MoveData(&Table_mgdl[0],&M_UART_TxFIFO[0],Cbuf1,7);
//					Cbuf1 +=7;	
//				}
//				
//				M_UART_TxLength =Cbuf1;
//		  		M_UART_TxIndex =0;				
//				_txr_rxr0= M_UART_TxFIFO[0];
//				
//				Cbuf0 =1;
//				do
//				{
//					GCC_CLRWDT();
//					if(M_UART_TxIndex >= M_UART_TxLength)
//						Cbuf0 =0;
//				}
//				while(Cbuf0);
//				
//				GCC_DELAY(10000);
//				
//				//--- Next record data
//				if(M_GM_data_Record_buf == 0)
//				{
//					M_GM_data_Record_buf = M_GM_data_Record;
//				}
//				else
//					M_GM_data_Record_buf --;
//			}
//			
//			
//			//*********************
//			//--- send end code
//			Cbuf1 =0;
//			M_UART_TxFIFO[Cbuf1] = 0x03;
//			Cbuf1++;
//			
//			M_UART_TxFIFO[Cbuf1] = 0x04;
//			Cbuf1++;
//			
//			M_UART_TxLength =Cbuf1;
//	  		M_UART_TxIndex =0;				
//			_txr_rxr0= M_UART_TxFIFO[0];
//			
//			Cbuf0 =1;
//			do
//			{
//				GCC_CLRWDT();
//				if(M_UART_TxIndex > M_UART_TxLength)
//					Cbuf0 =0;
//			}
//			while(Cbuf0);
//			
//			M_UartInsertCnt = 250;
//			
//			M_No_Active_Cnt = 0;
//			//-- quit MemoryMode mode
//		    M_Task = C_OffMode;           //quit MemoryMode mode
//		    M_TaskBuf0 =0;
//			M_TaskBuf1 =0;
//			M_Error_Task =0;
//		    M_RTC_display = 0; 
//		    
//			//---Lcd All off
//      		LCD_Clear(OFF); 
//			
//			
//
//			break;
//		}
//		
//		//--- 
//		case 3:
//		{
//			//--- uart receive
//			if(F_UartDataComing)
//			{
//				F_UartDataComing =0;
//
//				if(chechsum_check(&M_UART_RxFIFO[count],M_Length))
//				{
//			    	//ReadPage_flash(C_EEP_SerialNumber);
//			    	
//			    	count1 =0;
//			    	
//			    	M_FlashBuf0[count1] = M_Length;
//			    	M_FlashBuf0[count1 + 0x20] = M_Length;
//			    	for(count =0; count < M_Length; count++)
//			    	{
//			    		if((count % 2) == 0)
//			    		{
//			    			M_FlashBuf0[count1] |= M_UART_RxFIFO[count] << 8;
//			    			M_FlashBuf0[count1 + 0x20] |= M_UART_RxFIFO[count] << 8;
//							count1++;
//			    		}
//			    		else
//			    		{
//			    			M_FlashBuf0[count1] = M_UART_RxFIFO[count];
//			    			M_FlashBuf0[count1 + 0x20] = M_UART_RxFIFO[count];
//			    			
//			    		}
//			    			
//			    	}
//					// Write flash area for special  record 3D80~3D85
//					WritePage_flash(C_EEP_SerialNumber);
//					
//					//*********************
//					//--- send finish
//					Cbuf1 =0;
//					M_UART_TxFIFO[Cbuf1] = 0x59;
//					Cbuf1++;
//					
//					M_UART_TxLength =Cbuf1;
//			  		M_UART_TxIndex =0;				
//					_txr_rxr0= M_UART_TxFIFO[0];
//					
//					Cbuf0 =1;
//					do
//					{
//						GCC_CLRWDT();
//						if(M_UART_TxIndex > M_UART_TxLength)
//							Cbuf0 =0;
//					}
//					while(Cbuf0);
//					
//					M_UartInsertCnt = 250;
//				}
//				else
//				{
//					//*********************
//					//--- send fail 0xff
//					Cbuf1 =0;
//					M_UART_TxFIFO[Cbuf1] = 0xff;
//					Cbuf1++;
//					
//					M_UART_TxLength =Cbuf1;
//			  		M_UART_TxIndex =0;				
//					_txr_rxr0= M_UART_TxFIFO[0];
//					
//					Cbuf0 =1;
//					do
//					{
//						GCC_CLRWDT();
//						if(M_UART_TxIndex > M_UART_TxLength)
//							Cbuf0 =0;
//					}
//					while(Cbuf0);
//					
//					M_UartInsertCnt = 250;	
//				}
//				
//				M_RTC_display =0; 
//				M_TaskBuf0 =1;
//				M_TaskBuf1 =0;
//				
//				M_UART_RxIndex =0;
//			}
//			
//			break;
//		}		
//		
//			
////		case 2:
////		{
////			if(M_RTC_display <1)
////				M_RTC_display++;
////			if(M_RTC_display ==1)
////			{
////				Lcd_Display_PC();
////				//--- update lcd
////				F_LcdUpdate =1;	
////			}
////			
////			//--- uart receive
////			if(F_UartDataComing)
////			{
////				F_UartDataComing =0;
////				
////				//--- get partnumber
////				if(DataCompare(&Table_at_meter[0],&M_UART_RxFIFO[0],8))
////				{
////					MoveData(&Table_at_meter[0],&M_UART_TxFIFO[0],0,8);
////					Cbuf1 =8;
////					M_UART_TxFIFO[Cbuf1] = '=';
////					Cbuf1++;
////					
////					checksum =0;
////					for(count =0; count < 3; count++)
////					{
////						M_UART_TxFIFO[Cbuf1] = Table_partnumber[C_EEP_Partnumber + count];
////						checksum ^=Table_partnumber[count];
////						Cbuf1++;
////					}
////					
////					M_UART_TxFIFO[Cbuf1] = HexToAscii(checksum >>4);
////					Cbuf1++;
////					
////					M_UART_TxFIFO[Cbuf1] = HexToAscii(checksum & 0x0f);
////					Cbuf1++;
////					
////					MoveData(&Table_end[0],&M_UART_TxFIFO[0],Cbuf1,5);
////					Cbuf1 +=5;
////					
////					M_UART_TxLength =Cbuf1;
////			  		M_UART_TxIndex =0;				
////					_txr_rxr0= M_UART_TxFIFO[0];
////					
////					Cbuf0 =1;
////					do
////					{
////						GCC_CLRWDT();
////						if(M_UART_TxIndex >= M_UART_TxLength)
////							Cbuf0 =0;
////					}
////					while(Cbuf0);
////				}
////				//--- get firmware version
////				else if(DataCompare(&Table_at_ver[0],&M_UART_RxFIFO[0],6))
////				{
////					MoveData(&Table_at_ver[0],&M_UART_TxFIFO[0],0,6);
////					Cbuf1 =6;
////					M_UART_TxFIFO[Cbuf1] = '=';
////					Cbuf1++;
////					
////					checksum =0;
////					for(count =0; count < 3; count++)
////					{
////						M_UART_TxFIFO[Cbuf1] = Table_FirmwareVer[count];
////						checksum ^=Table_FirmwareVer[count];
////						Cbuf1++;
////					}
////					
////					M_UART_TxFIFO[Cbuf1] = HexToAscii(checksum >>4);
////					Cbuf1++;
////					
////					M_UART_TxFIFO[Cbuf1] = HexToAscii(checksum & 0x0f);
////					Cbuf1++;
////					
////					MoveData(&Table_end[0],&M_UART_TxFIFO[0],Cbuf1,5);
////					Cbuf1 +=5;
////					
////					M_UART_TxLength =Cbuf1;
////			  		M_UART_TxIndex =0;				
////					_txr_rxr0= M_UART_TxFIFO[0];
////					
////					Cbuf0 =1;
////					do
////					{
////						GCC_CLRWDT();
////						if(M_UART_TxIndex >= M_UART_TxLength)
////							Cbuf0 =0;
////					}
////					while(Cbuf0);
////				}
////				//--- get meter status
////				else if(DataCompare(&Table_at_sta[0],&M_UART_RxFIFO[0],6))
////				{
////					MoveData(&Table_at_sta[0],&M_UART_TxFIFO[0],0,6);
////					Cbuf1 =6;
////					M_UART_TxFIFO[Cbuf1] = '=';
////					Cbuf1++;
////					
////					checksum =0;
////					read_eeprom(C_EEP_FactorySign_Adr,1,buf);
////					
////					if(buf[0] != 'A')
////					{
////						M_UART_TxFIFO[Cbuf1] = 'B';
////						checksum ^= 'B';
////						Cbuf1++;
////						
////						M_UART_TxFIFO[Cbuf1] = 'F';
////						checksum ^= 'F';
////						Cbuf1++;
////					}
////					else
////					{
////						M_UART_TxFIFO[Cbuf1] = 'A';
////						checksum ^= 'A';
////						Cbuf1++;
////						
////						M_UART_TxFIFO[Cbuf1] = 'F';
////						checksum ^= 'F';
////						Cbuf1++;
////					}
////
////					
////					M_UART_TxFIFO[Cbuf1] = HexToAscii(checksum >>4);
////					Cbuf1++;
////					
////					M_UART_TxFIFO[Cbuf1] = HexToAscii(checksum & 0x0f);
////					Cbuf1++;
////					
////					MoveData(&Table_end[0],&M_UART_TxFIFO[0],Cbuf1,5);
////					Cbuf1 +=5;
////					
////					M_UART_TxLength =Cbuf1;
////			  		M_UART_TxIndex =0;				
////					_txr_rxr0= M_UART_TxFIFO[0];
////					
////					Cbuf0 =1;
////					do
////					{
////						GCC_CLRWDT();
////						if(M_UART_TxIndex >= M_UART_TxLength)
////							Cbuf0 =0;
////					}
////					while(Cbuf0);
////				}
////				//--- set.get serial
////				else if(DataCompare(&Table_at_serial[0],&M_UART_RxFIFO[0],9))
////				{
////					//--- set serial
////					if(M_UART_RxFIFO[9] == '=')
////					{
////						if(ChecksumCompare(&M_UART_RxFIFO[0],10,10))
////						{
////							//--- read flash to data
////							ReadPage_flash(C_EEP_ParameterTable_Adr);
////							
////							//--- move data
////							index =10;
////		  	      			//--- move data to flash buf
////		    				for(count =0; count < 5;count++)
////		    				{
////		    					M_FlashBuf[C_EEP_Partnumber + count] = M_UART_RxFIFO[index + (count * 2)];
////		    					M_FlashBuf[C_EEP_Partnumber + count] |= M_UART_RxFIFO[index + (count * 2 +1)] << 8;	
////		    				}
////	
////							//--- writer data to flash
////	    					//Flash_Store_PageErase_Process(C_EEP_ParameterTable_Adr);
////	    					WritePage_flash(C_EEP_ParameterTable_Adr,1);
////	    					
////	    					//--- writer Factory Sign
////	    					buf[0] = 'A';
////							write_eeprom(C_EEP_FactorySign_Adr,1,buf);
////							M_MeterStaus = 'A';
////							
////							//--- send ack
////							Send_Ack();
////						}
////						//--- send nak
////						else
////							Send_Nak();
////					}
////					//--- get serialserial
////					else
////					{
////						MoveData(&Table_at_serial[0],&M_UART_TxFIFO[0],0,9);
////						Cbuf1 =9;
////						M_UART_TxFIFO[Cbuf1] = '=';
////						Cbuf1++;
////						
////						checksum =0;
////						for(count =0; count < 10; count++)
////						{
////							M_UART_TxFIFO[Cbuf1] = Parameter_Table[C_EEP_Partnumber + count];
////							checksum ^=Parameter_Table[C_EEP_Partnumber + count];;
////							Cbuf1++;
////						}
////						
////						M_UART_TxFIFO[Cbuf1] = HexToAscii(checksum >>4);
////						Cbuf1++;
////						
////						M_UART_TxFIFO[Cbuf1] = HexToAscii(checksum & 0x0f);
////						Cbuf1++;
////						
////						MoveData(&Table_end[0],&M_UART_TxFIFO[0],Cbuf1,5);
////						Cbuf1 +=5;
////						
////						M_UART_TxLength =Cbuf1;
////				  		M_UART_TxIndex =0;				
////						_txr_rxr0= M_UART_TxFIFO[0];
////						
////						Cbuf0 =1;
////						do
////						{
////							GCC_CLRWDT();
////							if(M_UART_TxIndex >= M_UART_TxLength)
////								Cbuf0 =0;
////						}
////						while(Cbuf0);
////					}
////				}
////				//--- set date & time
////				else if(DataCompare(&Table_at_settime[0],&M_UART_RxFIFO[0],10))
////				{
////					//--- set serial
////					if(M_UART_RxFIFO[10] == '=')
////					{
////						if(ChecksumCompare(&M_UART_RxFIFO[0],11,10))
////						{
////							//--- set year
////							Cbuf0 = AsciiToHex(M_UART_RxFIFO[11]) *10;
////							Cbuf0 += AsciiToHex(M_UART_RxFIFO[12]);
////							M_Year = Cbuf0;
////							
////							//--- set month
////							Cbuf0 = AsciiToHex(M_UART_RxFIFO[13]) *10;
////							Cbuf0 += AsciiToHex(M_UART_RxFIFO[14]);
////							M_Month = Cbuf0;
////							
////							//--- set day
////							Cbuf0 = AsciiToHex(M_UART_RxFIFO[15]) *10;
////							Cbuf0 += AsciiToHex(M_UART_RxFIFO[16]);
////							M_Days = Cbuf0;
////							
////							//--- set hour
////							Cbuf0 = AsciiToHex(M_UART_RxFIFO[17]) *10;
////							Cbuf0 += AsciiToHex(M_UART_RxFIFO[18]);
////							M_Hour = Cbuf0;
////							
////							//--- set minutes
////							Cbuf0 = AsciiToHex(M_UART_RxFIFO[19]) *10;
////							Cbuf0 += AsciiToHex(M_UART_RxFIFO[20]);
////							M_Minutes = Cbuf0;
////							
////							//--- set second
////							M_Second =0;
////							
////							//--- send ack
////							Send_Ack();
////						}
////						//--- send nak
////						else
////							Send_Nak();
////					}
////				}
////				//--- get record
////				else if(DataCompare(&Table_at_total[0],&M_UART_RxFIFO[0],8))
////				{
////					MoveData(&Table_at_total[0],&M_UART_TxFIFO[0],0,8);
////					Cbuf1 =8;
////					M_UART_TxFIFO[Cbuf1] = '=';
////					Cbuf1++;
////					
////					Ibuf0 = M_GM_data_Record;
////					checksum =0;
////					Cbuf0 = Ibuf0 / 1000;
////					Ibuf0 = Ibuf0 % 1000;
////					M_UART_TxFIFO[Cbuf1] = HexToAscii(Cbuf0);
////					checksum ^=HexToAscii(Cbuf0);
////					Cbuf1++;
////					
////					Cbuf0 = Ibuf0 / 100;
////					Ibuf0 = Ibuf0 % 100;
////					M_UART_TxFIFO[Cbuf1] = HexToAscii(Cbuf0);
////					checksum ^=HexToAscii(Cbuf0);
////					Cbuf1++;
////					
////					Cbuf0 = Ibuf0 / 10;
////					Ibuf0 = Ibuf0 % 10;
////					M_UART_TxFIFO[Cbuf1] = HexToAscii(Cbuf0);
////					checksum ^=HexToAscii(Cbuf0);
////					Cbuf1++;
////					
////					M_UART_TxFIFO[Cbuf1] = HexToAscii(Ibuf0);
////					checksum ^=HexToAscii(Ibuf0);
////					Cbuf1++;
////					
////					//--- checksum
////					M_UART_TxFIFO[Cbuf1] = HexToAscii(checksum >>4);
////					Cbuf1++;
////					
////					M_UART_TxFIFO[Cbuf1] = HexToAscii(checksum & 0x0f);
////					Cbuf1++;
////					
////					MoveData(&Table_end[0],&M_UART_TxFIFO[0],Cbuf1,5);
////					Cbuf1 +=5;
////					
////					M_UART_TxLength =Cbuf1;
////			  		M_UART_TxIndex =0;				
////					_txr_rxr0= M_UART_TxFIFO[0];
////					
////					Cbuf0 =1;
////					do
////					{
////						GCC_CLRWDT();
////						if(M_UART_TxIndex >= M_UART_TxLength)
////							Cbuf0 =0;
////					}
////					while(Cbuf0);
////				}
////				//--- get record data
////				else if(DataCompare(&Table_at_data[0],&M_UART_RxFIFO[0],7))
////				{
////					if(M_UART_RxFIFO[7] == '=')
////					{
////						if(ChecksumCompare(&M_UART_RxFIFO[0],8,4))
////						{
////							Ibuf0 = AsciiToHex(M_UART_RxFIFO[8]) * 1000;
////							Ibuf0 += AsciiToHex(M_UART_RxFIFO[9]) * 100;
////							Ibuf0 += AsciiToHex(M_UART_RxFIFO[10]) * 10;
////							Ibuf0 += AsciiToHex(M_UART_RxFIFO[11]);
////							M_Ibuf0 = Ibuf0;
////							
////							
////							if(M_GM_data_Record != M_GM_Record_current)
////							{
////								if(Ibuf0 <= M_GM_Record_current)
////									M_GM_data_Record_buf = (M_GM_Record_current - Ibuf0) +1;
////								else
////									M_GM_data_Record_buf = (M_GM_data_Record + M_GM_Record_current) - Ibuf0 +1;
////							}
////							else
////								M_GM_data_Record_buf = M_GM_Record_current - Ibuf0 +1;
////							
////			     			//-- load start address
////			     			Ibuf1 = ((M_GM_data_Record_buf - 1) * 8); 
////				         	Ibuf1 += C_FlashDataOffset;     //add flash offset addrss = save current data address
////			
////					     	//-- load time recordH
////					     	Lbuf0 = Flash_Store_Read_Process(Ibuf1);  //buf1/buf0/buf3/buf2
////				         	Lbuf0 <<=16;
////				        
////				         	//--- load time recordL
////				         	Ibuf1++;
////				         	Lbuf0 |= Flash_Store_Read_Process(Ibuf1);  //buf1/buf0/buf3/buf2
////				
////				 	 	 	//--- load Glucose data
////						 	Ibuf1++;
////				         	M_GM_data = Flash_Store_Read_Process(Ibuf1);  //buf1/buf0/buf3/buf2	
////				         	
////				 	 	 	//--- load Temperature
////						 	Ibuf1++;
////				         	M_Temperature = Flash_Store_Read_Process(Ibuf1);  //buf1/buf0/buf3/buf2
////				         	
////				 	 	 	//--- load AutoCodeNB
////						 	Ibuf1++;
////				         	M_AutoCodeNB = Flash_Store_Read_Process(Ibuf1);  //buf1/buf0/buf3/buf2
////				         	
////				 	 	 	//--- load meal & F_ControlOption
////						 	Ibuf1++;
////				         	Ibuf0 = Flash_Store_Read_Process(Ibuf1);  //buf1/buf0/buf3/buf2
////				         	M_Meal = Ibuf0 & 0x0003;
////				         	F_ControlOption =0;
////				         	if(Ibuf0 & 0x0004)
////				         		F_ControlOption =1;
////			
////			
////					        //---Εγ�??φ??RΙ??
////					        SecondToDate(Lbuf0,buf);
////			
//////							//--- display Month & Day
//////						  	Lcd_Month_Day_Process(buf[4],buf[3]);
//////						  	
//////						  	//--- display clock
//////						  	Lcd_Clock_Process(buf[2],buf[1]);
////							
////							
////							//*********************
////							//--- load at command
////							MoveData(&Table_at_data[0],&M_UART_TxFIFO[0],0,7);
////							Cbuf1 =7;
////							M_UART_TxFIFO[Cbuf1] = '=';
////							Cbuf1++;
////							
////							//*********************
////							//--- load record
////							Ibuf0 = M_Ibuf0;
////							checksum =0;
////							Cbuf0 = Ibuf0 / 1000;
////							Ibuf0 = Ibuf0 % 1000;
////							M_UART_TxFIFO[Cbuf1] = HexToAscii(Cbuf0);
////							checksum ^=HexToAscii(Cbuf0);
////							Cbuf1++;
////							
////							Cbuf0 = Ibuf0 / 100;
////							Ibuf0 = Ibuf0 % 100;
////							M_UART_TxFIFO[Cbuf1] = HexToAscii(Cbuf0);
////							checksum ^=HexToAscii(Cbuf0);
////							Cbuf1++;
////							
////							Cbuf0 = Ibuf0 / 10;
////							Ibuf0 = Ibuf0 % 10;
////							M_UART_TxFIFO[Cbuf1] = HexToAscii(Cbuf0);
////							checksum ^=HexToAscii(Cbuf0);
////							Cbuf1++;
////							
////							Cbuf0 = Ibuf0;
////							M_UART_TxFIFO[Cbuf1] = HexToAscii(Cbuf0);
////							checksum ^=HexToAscii(Cbuf0);
////							Cbuf1++;
////							
////							//*********************
////							//--- load Temperature
////							Ibuf0 = M_Temperature;
////							Cbuf0 = Ibuf0 / 100;
////							Ibuf0 = Ibuf0 % 100;
////							M_UART_TxFIFO[Cbuf1] = HexToAscii(Cbuf0);
////							checksum ^=HexToAscii(Cbuf0);
////							Cbuf1++;
////							
////							Cbuf0 = Ibuf0 / 10;
////							Ibuf0 = Ibuf0 % 10;
////							M_UART_TxFIFO[Cbuf1] = HexToAscii(Cbuf0);
////							checksum ^=HexToAscii(Cbuf0);
////							Cbuf1++;
////							
////							Cbuf0 = Ibuf0;
////							M_UART_TxFIFO[Cbuf1] = HexToAscii(Cbuf0);
////							checksum ^=HexToAscii(Cbuf0);
////							Cbuf1++;
////
////							//*********************
////							//--- load year
////							Cbuf0 = buf[5] / 10;
////							Ibuf0 = buf[5] % 10;
////							M_UART_TxFIFO[Cbuf1] = HexToAscii(Cbuf0);
////							checksum ^=HexToAscii(Cbuf0);
////							Cbuf1++;
////
////							Cbuf0 = Ibuf0;
////							M_UART_TxFIFO[Cbuf1] = HexToAscii(Cbuf0);
////							checksum ^=HexToAscii(Cbuf0);
////							Cbuf1++;
////							//*********************
////							//--- load month
////							Cbuf0 = buf[4] / 10;
////							Ibuf0 = buf[4] % 10;
////							M_UART_TxFIFO[Cbuf1] = HexToAscii(Cbuf0);
////							checksum ^=HexToAscii(Cbuf0);
////							Cbuf1++;
////
////							Cbuf0 = Ibuf0;
////							M_UART_TxFIFO[Cbuf1] = HexToAscii(Cbuf0);
////							checksum ^=HexToAscii(Cbuf0);
////							Cbuf1++;
////							
////							//*********************
////							//--- load day
////							Cbuf0 = buf[3] / 10;
////							Ibuf0 = buf[3] % 10;
////							M_UART_TxFIFO[Cbuf1] = HexToAscii(Cbuf0);
////							checksum ^=HexToAscii(Cbuf0);
////							Cbuf1++;
////
////							Cbuf0 = Ibuf0;
////							M_UART_TxFIFO[Cbuf1] = HexToAscii(Cbuf0);
////							checksum ^=HexToAscii(Cbuf0);
////							Cbuf1++;
////							
////							//*********************
////							//--- load hour
////							Cbuf0 = buf[2] / 10;
////							Ibuf0 = buf[2] % 10;
////							M_UART_TxFIFO[Cbuf1] = HexToAscii(Cbuf0);
////							checksum ^=HexToAscii(Cbuf0);
////							Cbuf1++;
////
////							Cbuf0 = Ibuf0;
////							M_UART_TxFIFO[Cbuf1] = HexToAscii(Cbuf0);
////							checksum ^=HexToAscii(Cbuf0);
////							Cbuf1++;
////							
////							//*********************
////							//--- load Minutes
////							Cbuf0 = buf[1] / 10;
////							Ibuf0 = buf[1] % 10;
////							M_UART_TxFIFO[Cbuf1] = HexToAscii(Cbuf0);
////							checksum ^=HexToAscii(Cbuf0);
////							Cbuf1++;
////
////							Cbuf0 = Ibuf0;
////							M_UART_TxFIFO[Cbuf1] = HexToAscii(Cbuf0);
////							checksum ^=HexToAscii(Cbuf0);
////							Cbuf1++;
////							
////							//*********************
////							//--- load Second
////							Cbuf0 = buf[0] / 10;
////							Ibuf0 = buf[0] % 10;
////							M_UART_TxFIFO[Cbuf1] = HexToAscii(Cbuf0);
////							checksum ^=HexToAscii(Cbuf0);
////							Cbuf1++;
////
////							Cbuf0 = Ibuf0;
////							M_UART_TxFIFO[Cbuf1] = HexToAscii(Cbuf0);
////							checksum ^=HexToAscii(Cbuf0);
////							Cbuf1++;
////							
////							//*********************
////							//--- load AutoCodeNB
////							Ibuf0 = M_AutoCodeNB;
////							Cbuf0 = Ibuf0 / 10;
////							Ibuf0 = Ibuf0 % 10;
////							M_UART_TxFIFO[Cbuf1] = HexToAscii(Cbuf0);
////							checksum ^=HexToAscii(Cbuf0);
////							Cbuf1++;
////
////							Cbuf0 = Ibuf0;
////							M_UART_TxFIFO[Cbuf1] = HexToAscii(Cbuf0);
////							checksum ^=HexToAscii(Cbuf0);
////							Cbuf1++;
////							
////							//*********************
////							//--- load Control
////							if(F_ControlOption)
////								Cbuf0 = 1;
////							else
////								Cbuf0 = 0;
////							M_UART_TxFIFO[Cbuf1] = HexToAscii(Cbuf0);
////							checksum ^=HexToAscii(Cbuf0);
////							Cbuf1++;
////							
////							//*********************
////							//--- load meal
////							Ibuf0 = M_Meal;
////							Cbuf0 = Ibuf0 / 10;
////							Ibuf0 = Ibuf0 % 10;
////							M_UART_TxFIFO[Cbuf1] = HexToAscii(Cbuf0);
////							checksum ^=HexToAscii(Cbuf0);
////							Cbuf1++;
////
////							Cbuf0 = Ibuf0;
////							M_UART_TxFIFO[Cbuf1] = HexToAscii(Cbuf0);
////							checksum ^=HexToAscii(Cbuf0);
////							Cbuf1++;
////							
////							//*********************
////							//--- load glucose value
////							Ibuf0 = M_GM_data;
////							Cbuf0 = Ibuf0 / 100;
////							Ibuf0 = Ibuf0 % 100;
////							M_UART_TxFIFO[Cbuf1] = HexToAscii(Cbuf0);
////							checksum ^=HexToAscii(Cbuf0);
////							Cbuf1++;
////							
////							Cbuf0 = Ibuf0 / 10;
////							Ibuf0 = Ibuf0 % 10;
////							M_UART_TxFIFO[Cbuf1] = HexToAscii(Cbuf0);
////							checksum ^=HexToAscii(Cbuf0);
////							Cbuf1++;
////							
////							Cbuf0 = Ibuf0;
////							M_UART_TxFIFO[Cbuf1] = HexToAscii(Cbuf0);
////							checksum ^=HexToAscii(Cbuf0);
////							Cbuf1++;
////
////							//*********************
////							//--- checksum
////							M_UART_TxFIFO[Cbuf1] = HexToAscii(checksum >>4);
////							Cbuf1++;
////							
////							M_UART_TxFIFO[Cbuf1] = HexToAscii(checksum & 0x0f);
////							Cbuf1++;
////							
////							MoveData(&Table_end[0],&M_UART_TxFIFO[0],Cbuf1,5);
////							Cbuf1 +=5;
////							
////							M_UART_TxLength =Cbuf1;
////					  		M_UART_TxIndex =0;				
////							_txr_rxr0= M_UART_TxFIFO[0];
////							
////							Cbuf0 =1;
////							do
////							{
////								GCC_CLRWDT();
////								if(M_UART_TxIndex >= M_UART_TxLength)
////									Cbuf0 =0;
////							}
////							while(Cbuf0);
////						}
////					}
////					//--- send nak
////					else
////						Send_Nak();
////				}
////				//--- get total record
////				else if(DataCompare(&Table_at_t_cnt[0],&M_UART_RxFIFO[0],8))
////				{
////					MoveData(&Table_at_t_cnt[0],&M_UART_TxFIFO[0],0,8);
////					Cbuf1 =8;
////					M_UART_TxFIFO[Cbuf1] = '=';
////					Cbuf1++;
////					
////					Lbuf0 = M_FlashLifeCount;
////					checksum =0;
////					Cbuf0 = Lbuf0 / 10000;
////					Ibuf0 = Lbuf0 % 10000;
////					M_UART_TxFIFO[Cbuf1] = HexToAscii(Cbuf0);
////					checksum ^=HexToAscii(Cbuf0);
////					Cbuf1++;
////					
////					Cbuf0 = Ibuf0 / 1000;
////					Ibuf0 = Ibuf0 % 1000;
////					M_UART_TxFIFO[Cbuf1] = HexToAscii(Cbuf0);
////					checksum ^=HexToAscii(Cbuf0);
////					Cbuf1++;
////					
////					Cbuf0 = Ibuf0 / 100;
////					Ibuf0 = Ibuf0 % 100;
////					M_UART_TxFIFO[Cbuf1] = HexToAscii(Cbuf0);
////					checksum ^=HexToAscii(Cbuf0);
////					Cbuf1++;
////					
////					Cbuf0 = Ibuf0 / 10;
////					Ibuf0 = Ibuf0 % 10;
////					M_UART_TxFIFO[Cbuf1] = HexToAscii(Cbuf0);
////					checksum ^=HexToAscii(Cbuf0);
////					Cbuf1++;
////					
////					M_UART_TxFIFO[Cbuf1] = HexToAscii(Ibuf0);
////					checksum ^=HexToAscii(Ibuf0);
////					Cbuf1++;
////					
////					//--- checksum
////					M_UART_TxFIFO[Cbuf1] = HexToAscii(checksum >>4);
////					Cbuf1++;
////					
////					M_UART_TxFIFO[Cbuf1] = HexToAscii(checksum & 0x0f);
////					Cbuf1++;
////					
////					MoveData(&Table_end[0],&M_UART_TxFIFO[0],Cbuf1,5);
////					Cbuf1 +=5;
////					
////					M_UART_TxLength =Cbuf1;
////			  		M_UART_TxIndex =0;				
////					_txr_rxr0= M_UART_TxFIFO[0];
////					
////					Cbuf0 =1;
////					do
////					{
////						GCC_CLRWDT();
////						if(M_UART_TxIndex >= M_UART_TxLength)
////							Cbuf0 =0;
////					}
////					while(Cbuf0);
////				}
////				//--- set total record
////				else if(DataCompare(&Table_at_delete[0],&M_UART_RxFIFO[0],9))
////				{
////					
////					M_GM_data_Record =0;
////					M_GM_Record_current =0;
////					
////					ReadPage_flash(C_EEP_Significant);
////					
////					M_FlashBuf[0x01] = M_GM_data_Record;  //load M_GM_data_Record 3D81
////					M_FlashBuf[0x02] = M_GM_Record_current;  //load M_GM_Record_current 3D82
////					
////					M_FlashBuf[0x11] = M_GM_data_Record;  //load M_GM_data_Record 3D81
////					M_FlashBuf[0x12] = M_GM_Record_current;  //load M_GM_Record_current 3D82
////					
////					M_FlashBuf[0x21] = M_GM_data_Record;  //load M_GM_data_Record 3D81
////					M_FlashBuf[0x22] = M_GM_Record_current;  //load M_GM_Record_current 3D82
////					
////					M_FlashBuf[0x31] = M_GM_data_Record;  //load M_GM_data_Record 3D81
////					M_FlashBuf[0x32] = M_GM_Record_current;  //load M_GM_Record_current 3D82
////					
////					
////					
////					WritePage_flash(C_EEP_Significant,2);					
//////			    	//--- clear record
//////					buf[0] = 0;
//////					buf[1] = 0;
//////					write_eeprom(C_EEP_GM_RecordAdr,2,buf);
//////					M_GM_data_Record =0;
//////					GCC_CLRWDT();
//////					
//////					//--- Writer record current
//////					buf[0] = 0;
//////					buf[1] = 0;
//////					write_eeprom(C_EEP_GM_Current_RecordAdr,2,buf);
//////					M_GM_Record_current =0;
////					
////					Send_Ack();
////				}
////				//--- set.get QC data
////				else if(DataCompare(&Table_at_qcdata[0],&M_UART_RxFIFO[0],9))
////				{
////					//--- set QC data
////					if(M_UART_RxFIFO[9] == '=')
////					{
//////						if(ChecksumCompare(&M_UART_RxFIFO[0],10,16))
//////						{
//////							//--- read flash to data
//////							ReadPage_flash(C_EEP_ParameterTable_Adr);
//////							
//////							//--- move data
//////							index =10;
//////		  	      			//--- move data to flash buf
//////		    				for(count =0; count < 8;count++)
//////		    				{
//////		    					M_FlashBuf[(C_EEP_QC_Data >>1) + count] = M_UART_RxFIFO[index + (count * 2)];
//////		    					M_FlashBuf[(C_EEP_QC_Data >>1) + count] |= M_UART_RxFIFO[index + (count * 2 +1)] << 8;	
//////		    				}
//////	
//////							//--- writer data to flash
//////	    					Flash_Store_PageErase_Process(C_EEP_ParameterTable_Adr);
//////	    					WritePage_flash(C_EEP_ParameterTable_Adr);
//////							
//////							//--- send ack
//////							Send_Ack();
//////						}
//////						//--- save Resistance & hi temp & low temp
//////						else 
////						if(ChecksumCompare(&M_UART_RxFIFO[0],10,10))
////						{
////							//--- read flash to data
////							ReadPage_flash(C_EEP_ParameterTable_Adr);
////							
////							//--- save qc data
////							Ibuf0 = M_GM_data;
////							Cbuf0 = Ibuf0 / 100;
////							Ibuf0 = Ibuf0 % 100;
////							M_FlashBuf[C_EEP_QC_Data >>1] = HexToAscii(Cbuf0);
////							
////							Cbuf0 = Ibuf0 / 10;
////							Ibuf0 = Ibuf0 % 10;
////							M_FlashBuf[C_EEP_QC_Data >>1] |= HexToAscii(Cbuf0) << 8;
////
////							Cbuf0 = Ibuf0;
////							M_FlashBuf[(C_EEP_QC_Data >>1) +1] = HexToAscii(Cbuf0);
////
////							//--- save qc temperture
////							Ibuf0 = M_Temperature;
////							Cbuf0 = Ibuf0 / 100;
////							Ibuf0 = Ibuf0 % 100;
////							M_FlashBuf[(C_EEP_QC_Data >>1) +1] |= HexToAscii(Cbuf0) << 8;
////							
////							Cbuf0 = Ibuf0 / 10;
////							Ibuf0 = Ibuf0 % 10;
////							M_FlashBuf[(C_EEP_QC_Data >>1) +2] = HexToAscii(Cbuf0);
////							
////							Cbuf0 = Ibuf0;
////							M_FlashBuf[(C_EEP_QC_Data >>1) +2] |= HexToAscii(Cbuf0) << 8;
////							
////							//--- move data
////							index =10;
////		  	      			//--- move data to flash buf
////		    				for(count =0; count < 5;count++)
////		    				{
////		    					M_FlashBuf[(C_EEP_QC_Resistance >>1) + count] = M_UART_RxFIFO[index + (count * 2)];
////		    					M_FlashBuf[(C_EEP_QC_Resistance >>1) + count] |= M_UART_RxFIFO[index + (count * 2 +1)] << 8;	
////		    				}
////	
////							//--- writer data to flash
////	    					//Flash_Store_PageErase_Process(C_EEP_ParameterTable_Adr);
////	    					WritePage_flash(C_EEP_ParameterTable_Adr,1);
////							
////							//--- send ack
////							Send_Ack();
////							
////						}
////						//--- send nak
////						else
////							Send_Nak();
////					}
////					//--- get QC data
////					else
////					{
////						MoveData(&Table_at_qcdata[0],&M_UART_TxFIFO[0],0,9);
////						Cbuf1 =9;
////						M_UART_TxFIFO[Cbuf1] = '=';
////						Cbuf1++;
////						
//////						M_GM_data_Record_buf = M_GM_Record_current;
//////		     			//-- load start address
//////		     			Ibuf1 = ((M_GM_data_Record_buf - 1) * 8); 
//////			         	Ibuf1 += C_FlashDataOffset;     //add flash offset addrss = save current data address
//////		
//////				     	//-- load time recordH
//////				     	Lbuf0 = Flash_Store_Read_Process(Ibuf1);  //buf1/buf0/buf3/buf2
//////			         	Lbuf0 <<=16;
//////			        
//////			         	//--- load time recordL
//////			         	Ibuf1++;
//////			         	Lbuf0 |= Flash_Store_Read_Process(Ibuf1);  //buf1/buf0/buf3/buf2
//////			
//////			 	 	 	//--- load Glucose data
//////					 	Ibuf1++;
//////			         	M_GM_data = Flash_Store_Read_Process(Ibuf1);  //buf1/buf0/buf3/buf2	
//////			         	
//////			 	 	 	//--- load Temperature
//////					 	Ibuf1++;
//////			         	M_Temperature = Flash_Store_Read_Process(Ibuf1);  //buf1/buf0/buf3/buf2
//////			         	
//////			 	 	 	//--- load AutoCodeNB
//////					 	Ibuf1++;
//////			         	M_AutoCodeNB = Flash_Store_Read_Process(Ibuf1);  //buf1/buf0/buf3/buf2
//////			         	
//////			 	 	 	//--- load meal & F_ControlOption
//////					 	Ibuf1++;
//////			         	Ibuf0 = Flash_Store_Read_Process(Ibuf1);  //buf1/buf0/buf3/buf2
//////			         	M_Meal = Ibuf0 & 0x0003;
//////			         	F_ControlOption =0;
//////			         	if(Ibuf0 & 0x0004)
//////			         		F_ControlOption =1;
//////			         	
//////						//*********************
//////						//--- load Temperature
//////						checksum =0;
//////						Ibuf0 = M_Temperature;
//////						Cbuf0 = Ibuf0 / 100;
//////						Ibuf0 = Ibuf0 % 100;
//////						M_UART_TxFIFO[Cbuf1] = HexToAscii(Cbuf0);
//////						checksum ^=HexToAscii(Cbuf0);
//////						Cbuf1++;
//////						
//////						Cbuf0 = Ibuf0 / 10;
//////						Ibuf0 = Ibuf0 % 10;
//////						M_UART_TxFIFO[Cbuf1] = HexToAscii(Cbuf0);
//////						checksum ^=HexToAscii(Cbuf0);
//////						Cbuf1++;
//////						
//////						Cbuf0 = Ibuf0;
//////						M_UART_TxFIFO[Cbuf1] = HexToAscii(Cbuf0);
//////						checksum ^=HexToAscii(Cbuf0);
//////						Cbuf1++;
//////			         		
//////						//*********************
//////						//--- load glucose value
//////						Ibuf0 = M_GM_data;
//////						Cbuf0 = Ibuf0 / 100;
//////						Ibuf0 = Ibuf0 % 100;
//////						M_UART_TxFIFO[Cbuf1] = HexToAscii(Cbuf0);
//////						checksum ^=HexToAscii(Cbuf0);
//////						Cbuf1++;
//////						
//////						Cbuf0 = Ibuf0 / 10;
//////						Ibuf0 = Ibuf0 % 10;
//////						M_UART_TxFIFO[Cbuf1] = HexToAscii(Cbuf0);
//////						checksum ^=HexToAscii(Cbuf0);
//////						Cbuf1++;
//////						
//////						Cbuf0 = Ibuf0;
//////						M_UART_TxFIFO[Cbuf1] = HexToAscii(Cbuf0);
//////						checksum ^=HexToAscii(Cbuf0);
//////						Cbuf1++;
////						
////						checksum =0;						
////						for(count =0; count < 16; count++)
////						{
////							M_UART_TxFIFO[Cbuf1] = Parameter_Table[C_EEP_QC_Data + count];
////							checksum ^=Parameter_Table[C_EEP_QC_Data + count];;
////							Cbuf1++;
////						}
////						
////						M_UART_TxFIFO[Cbuf1] = HexToAscii(checksum >>4);
////						Cbuf1++;
////						
////						M_UART_TxFIFO[Cbuf1] = HexToAscii(checksum & 0x0f);
////						Cbuf1++;
////						
////						MoveData(&Table_end[0],&M_UART_TxFIFO[0],Cbuf1,5);
////						Cbuf1 +=5;
////						
////						M_UART_TxLength =Cbuf1;
////				  		M_UART_TxIndex =0;				
////						_txr_rxr0= M_UART_TxFIFO[0];
////						
////						Cbuf0 =1;
////						do
////						{
////							GCC_CLRWDT();
////							if(M_UART_TxIndex >= M_UART_TxLength)
////								Cbuf0 =0;
////						}
////						while(Cbuf0);
////					}
////				}
////				//--- set.get QC current
////				else if(DataCompare(&Table_at_current[0],&M_UART_RxFIFO[0],10))
////				{
////					//--- QC current
////					if(M_UART_RxFIFO[10] == '=')
////					{
////						if(ChecksumCompare(&M_UART_RxFIFO[0],11,8))
////						{
////							//--- read flash to data
////							ReadPage_flash(C_EEP_ParameterTable_Adr);
////							
////							//--- move data
////							index =11;
////		  	      			//--- move data to flash buf
////		    				for(count =0; count < 4;count++)
////		    				{
////		    					M_FlashBuf[(C_EEP_QC_IdelCurrent >>1) + count] = M_UART_RxFIFO[index + (count * 2)];
////		    					M_FlashBuf[(C_EEP_QC_IdelCurrent >>1) + count] |= M_UART_RxFIFO[index + (count * 2 +1)] << 8;	
////		    				}
////	
////							//--- writer data to flash
////	    					//Flash_Store_PageErase_Process(C_EEP_ParameterTable_Adr);
////	    					WritePage_flash(C_EEP_ParameterTable_Adr,1);
////							
////							//--- send ack
////							Send_Ack();
////						}
////						//--- send nak
////						else
////							Send_Nak();
////					}
////					//--- get current
////					else
////					{
////						MoveData(&Table_at_current[0],&M_UART_TxFIFO[0],0,10);
////						Cbuf1 =10;
////						M_UART_TxFIFO[Cbuf1] = '=';
////						Cbuf1++;
////						
////						checksum =0;
////						for(count =0; count < 8; count++)
////						{
////							M_UART_TxFIFO[Cbuf1] = Parameter_Table[C_EEP_QC_IdelCurrent + count];
////							checksum ^=Parameter_Table[C_EEP_QC_IdelCurrent + count];;
////							Cbuf1++;
////						}
////						
////						M_UART_TxFIFO[Cbuf1] = HexToAscii(checksum >>4);
////						Cbuf1++;
////						
////						M_UART_TxFIFO[Cbuf1] = HexToAscii(checksum & 0x0f);
////						Cbuf1++;
////						
////						MoveData(&Table_end[0],&M_UART_TxFIFO[0],Cbuf1,5);
////						Cbuf1 +=5;
////						
////						M_UART_TxLength =Cbuf1;
////				  		M_UART_TxIndex =0;				
////						_txr_rxr0= M_UART_TxFIFO[0];
////						
////						Cbuf0 =1;
////						do
////						{
////							GCC_CLRWDT();
////							if(M_UART_TxIndex >= M_UART_TxLength)
////								Cbuf0 =0;
////						}
////						while(Cbuf0);
////					}
////				}
////				//--- set.get QC MeasureRange
////				else if(DataCompare(&Table_at_qcrange[0],&M_UART_RxFIFO[0],10))
////				{
////					//--- QC MeasureRange
////					if(M_UART_RxFIFO[10] == '=')
////					{
////						if(ChecksumCompare(&M_UART_RxFIFO[0],11,6))
////						{
////							//--- read flash to data
////							ReadPage_flash(C_EEP_ParameterTable_Adr);
////							
////							//--- move data
////							index =11;
////		  	      			//--- move data to flash buf
////		    				for(count =0; count < 3;count++)
////		    				{
////		    					M_FlashBuf[(C_EEP_QC_MeasureRangeMin >>1) + count] = M_UART_RxFIFO[index + (count * 2)];
////		    					M_FlashBuf[(C_EEP_QC_MeasureRangeMin >>1) + count] |= M_UART_RxFIFO[index + (count * 2 +1)] << 8;	
////		    				}
////	
////							//--- writer data to flash
////	    					//Flash_Store_PageErase_Process(C_EEP_ParameterTable_Adr);
////	    					WritePage_flash(C_EEP_ParameterTable_Adr,1);
////							
////							//--- send ack
////							Send_Ack();
////						}
////						//--- send nak
////						else
////							Send_Nak();
////					}
////					//--- get QC MeasureRange
////					else
////					{
////						MoveData(&Table_at_qcrange[0],&M_UART_TxFIFO[0],0,10);
////						Cbuf1 =10;
////						M_UART_TxFIFO[Cbuf1] = '=';
////						Cbuf1++;
////						
////						checksum =0;
////						for(count =0; count < 6; count++)
////						{
////							M_UART_TxFIFO[Cbuf1] = Parameter_Table[C_EEP_QC_MeasureRangeMin + count];
////							checksum ^=Parameter_Table[C_EEP_QC_MeasureRangeMin + count];;
////							Cbuf1++;
////						}
////						
////						M_UART_TxFIFO[Cbuf1] = HexToAscii(checksum >>4);
////						Cbuf1++;
////						
////						M_UART_TxFIFO[Cbuf1] = HexToAscii(checksum & 0x0f);
////						Cbuf1++;
////						
////						MoveData(&Table_end[0],&M_UART_TxFIFO[0],Cbuf1,5);
////						Cbuf1 +=5;
////						
////						M_UART_TxLength =Cbuf1;
////				  		M_UART_TxIndex =0;				
////						_txr_rxr0= M_UART_TxFIFO[0];
////						
////						Cbuf0 =1;
////						do
////						{
////							GCC_CLRWDT();
////							if(M_UART_TxIndex >= M_UART_TxLength)
////								Cbuf0 =0;
////						}
////						while(Cbuf0);
////					}
////				}
////				//--- set.get Type
////				else if(DataCompare(&Table_at_type[0],&M_UART_RxFIFO[0],7))
////				{
////					//--- set Type
////					if(M_UART_RxFIFO[7] == '=')
////					{
////						if(ChecksumCompare(&M_UART_RxFIFO[0],8,1))
////						{
////							//--- read flash to data
////							ReadPage_flash(C_EEP_ParameterTable_Adr);
////							
////							
////							if(M_UART_RxFIFO[8] == '1')
////							{
////			  	      			//--- move data to flash buf
////			    				M_FlashBuf[(C_EEP_Type >>1)] = 'B';
////							}
////							else
////							{
////			  	      			//--- move data to flash buf
////			    				M_FlashBuf[(C_EEP_Type >>1)] = 'A';	
////							}
////
////							//--- writer data to flash
////	    					//Flash_Store_PageErase_Process(C_EEP_ParameterTable_Adr);
////	    					WritePage_flash(C_EEP_ParameterTable_Adr,1);
////	    					
////	    					//M_MeterStaus = Parameter_Table[C_EEP_Type];
////							
////							//--- send ack
////							Send_Ack();
////						}
////						//--- send nak
////						else
////							Send_Nak();
////					}
////					//--- get type
////					else
////					{
////						MoveData(&Table_at_type[0],&M_UART_TxFIFO[0],0,7);
////						Cbuf1 =7;
////						M_UART_TxFIFO[Cbuf1] = '=';
////						Cbuf1++;
////						
////						checksum =0;
////						if(Parameter_Table[C_EEP_Type] =='A')
////						{
////							M_UART_TxFIFO[Cbuf1] = '0';
////							checksum ^= '0';
////							Cbuf1++;
////						}
////						else
////						{
////							M_UART_TxFIFO[Cbuf1] = '1';
////							checksum ^= '1';
////							Cbuf1++;
////						}
////
////						
////						M_UART_TxFIFO[Cbuf1] = HexToAscii(checksum >>4);
////						Cbuf1++;
////						
////						M_UART_TxFIFO[Cbuf1] = HexToAscii(checksum & 0x0f);
////						Cbuf1++;
////						
////						MoveData(&Table_end[0],&M_UART_TxFIFO[0],Cbuf1,5);
////						Cbuf1 +=5;
////						
////						M_UART_TxLength =Cbuf1;
////				  		M_UART_TxIndex =0;				
////						_txr_rxr0= M_UART_TxFIFO[0];
////						
////						Cbuf0 =1;
////						do
////						{
////							GCC_CLRWDT();
////							if(M_UART_TxIndex >= M_UART_TxLength)
////								Cbuf0 =0;
////						}
////						while(Cbuf0);
////					}
////				}
////				//--- set unit
////				else if(DataCompare(&Table_at_unit[0],&M_UART_RxFIFO[0],7))
////				{
////					//--- set.get Type
////					if(M_UART_RxFIFO[7] == '=')
////					{
////						if(ChecksumCompare(&M_UART_RxFIFO[0],8,1))
////						{		
////							M_Unit = M_UART_RxFIFO[8] - 0x30;	
////							//--- save data to eeprom	
////							buf[0] = M_Unit;
////								
////							write_eeprom(C_EEP_Unit_Adr,1,buf);
////
////							//--- send ack
////							Send_Ack();
////						}
////						//--- send nak
////						else
////							Send_Nak();
////					}
////					//--- get type
////					else
////					{
////						MoveData(&Table_at_unit[0],&M_UART_TxFIFO[0],0,7);
////						Cbuf1 =7;
////						M_UART_TxFIFO[Cbuf1] = '=';
////						Cbuf1++;
////						
////						checksum =0;
////						M_UART_TxFIFO[Cbuf1] = M_Unit + 0x30;
////						checksum ^= M_Unit + 0x30;
////						Cbuf1++;
////
////						
////						M_UART_TxFIFO[Cbuf1] = HexToAscii(checksum >>4);
////						Cbuf1++;
////						
////						M_UART_TxFIFO[Cbuf1] = HexToAscii(checksum & 0x0f);
////						Cbuf1++;
////						
////						MoveData(&Table_end[0],&M_UART_TxFIFO[0],Cbuf1,5);
////						Cbuf1 +=5;
////						
////						M_UART_TxLength =Cbuf1;
////				  		M_UART_TxIndex =0;				
////						_txr_rxr0= M_UART_TxFIFO[0];
////						
////						Cbuf0 =1;
////						do
////						{
////							GCC_CLRWDT();
////							if(M_UART_TxIndex >= M_UART_TxLength)
////								Cbuf0 =0;
////						}
////						while(Cbuf0);
////					}
////				}
////				//--- set.svae data to meter
////				else if(DataCompare(&Table_at_sample[0],&M_UART_RxFIFO[0],9))
////				{
////					//--- set.svae data
////					if(M_UART_RxFIFO[9] == '=')
////					{
////						if(ChecksumCompare(&M_UART_RxFIFO[0],10,3))
////						{
////							M_GM_data = AsciiToHex(M_UART_RxFIFO[10]) *100;
////							M_GM_data += AsciiToHex(M_UART_RxFIFO[11])*10;
////							M_GM_data += AsciiToHex(M_UART_RxFIFO[12]);
////							
////							M_AutoCodeNB =47;
////							M_Temperature = 230;
////							M_Meal =0;
////							F_ControlOption =0;
////							
////							if(M_GM_data_Record < C_GMDataSaveIndex)     //total memory record max=500
////								M_GM_data_Record++;
////			             
////							if(M_GM_Record_current >= C_GMDataSaveIndex)
////			               		M_GM_Record_current =0;        //memory full restart record 1
////							M_GM_Record_current++;
////							
////							if(M_FlashLifeCount < 99999)     //total memory record max=500
////								M_FlashLifeCount++;
////			              
////							//--- Writer record
////							buf[0] = (M_GM_data_Record & 0xff00) >>8;
////							buf[1] = M_GM_data_Record & 0x00ff;
////							write_eeprom(C_EEP_GM_RecordAdr,2,buf);
////							
////							//--- Writer record current
////							buf[0] = (M_GM_Record_current & 0xff00) >>8;
////							buf[1] = M_GM_Record_current & 0x00ff;
////							write_eeprom(C_EEP_GM_Current_RecordAdr,2,buf);
////							
////							//--- Writer Flash Life Count
////							buf[0] = M_FlashLifeCount >>24;
////							buf[1] = M_FlashLifeCount >>16;
////							buf[2] = M_FlashLifeCount >>8;
////							buf[3] = M_FlashLifeCount;
////							write_eeprom(C_EEP_FlashLifeCount_Adr,4,buf);
////		
////							//--- Save data Glucose & date to flash ---
////							//--- get address (data package 8 bytes , but only used 6 bytes)
////							M_Ibuf0 = ((M_GM_Record_current-1)*8); 
////							M_Ibuf0 += C_FlashDataOffset;          //add flash offset addrss = save current data address
////							
////							Ibuf1 = C_FlashDataOffset;
////							//--- get erase point read Flash data record (bbuf1 = data section)
////							//--- M_Ibuf0 =>Current address
////							//--- 
////							for(Cbuf0= 0 ; Cbuf0<= 64 ; Cbuf0++)
////							{
////								Ibuf1 += 0x40;
////								M_FlashPage = Cbuf0;
////								if(Ibuf1 > M_Ibuf0)
////								{
////									Ibuf1 -= 0x40;
////									M_Ibuf2 = Ibuf1;
////									break;
////								}
////							}
////							
////							ReadPage_flash(M_Ibuf2);
////							//Flash_Store_PageErase_Process(M_Ibuf2);
////		                  
////							//--- get time year/month/day/hour/minutes/second
////							//- get time
////							
////							
////							buf[5] = M_Year;
////							buf[4] = M_Month;// = 5;
////							buf[3] = M_Days;// = 1;
////							buf[2] = M_Hour;// = 12;
////							buf[1] = M_Minutes;// = 0;
////							buf[0] = M_Second;// = 0;
////							M_Lbuf0 = DateToSecond(buf);   //change to second
////							
////							//-- load time to RAM
////							Cbuf0 = M_Ibuf0 - M_Ibuf2;              //load save current data adr
////							// Load Data 2/1					
////							M_FlashBuf[Cbuf0] = (M_Lbuf0 & 0xffff0000) >>16;
////							Cbuf0++;
////							// Load Data 4/3
////							M_FlashBuf[Cbuf0] = M_Lbuf0 & 0x0000ffff;
////							Cbuf0++;
////							// Load GM data
////							M_FlashBuf[Cbuf0] = M_GM_data;
////							Cbuf0++;
////							// Load GM Temperature
////							M_FlashBuf[Cbuf0] = M_Temperature;
////							Cbuf0++;
////							// Load GM AutoCodeNB
////							M_FlashBuf[Cbuf0] = M_AutoCodeNB;
////							Cbuf0++;
////							// Load GM meal & Control
////							M_FlashBuf[Cbuf0] =M_Meal;
////							if(F_ControlOption)
////								M_FlashBuf[Cbuf0] |=0x0004;
////							//-- save to Flash Rom
////							WritePage_flash(M_Ibuf2,0);
////							
////							//--- send ack
////							Send_Ack();
////						}
////						//--- send nak
////						else
////							Send_Nak();
////					}
////					else
////						Send_Nak();
////
////				}					
////				//--- set BF
////				else if(DataCompare(&Table_at_gobf[0],&M_UART_RxFIFO[0],7))
////				{
//////					//--- set.get Type
//////					if(ChecksumCompare(&M_UART_RxFIFO[0],7,1))
//////					{
////						//--- Writer Factory Sign
////						buf[0] = 'B';
////						write_eeprom(C_EEP_FactorySign_Adr,1,buf);
////						M_MeterStaus = 'B';
////						//--- send ack
////						Send_Ack();
//////					}
//////					//--- send nak
//////					else
//////						Send_Nak();
////				}				
////				//--- get strip type
////				else if(DataCompare(&Table_at_strip[0],&M_UART_RxFIFO[0],8))
////				{
////					//--- set.svae data
////					if(M_UART_RxFIFO[8] == '=')
////					{
////						//--- send ack
////						Send_Ack();
////					}
////					else
////					{
////						MoveData(&Table_at_strip[0],&M_UART_TxFIFO[0],0,8);
////						Cbuf1 =8;
////						M_UART_TxFIFO[Cbuf1] = '=';
////						Cbuf1++;
////						
////						checksum =0;
////						M_UART_TxFIFO[Cbuf1] = '0';
////						checksum ^='0';
////						Cbuf1++;
////						
////						M_UART_TxFIFO[Cbuf1] = HexToAscii(checksum >>4);
////						Cbuf1++;
////						
////						M_UART_TxFIFO[Cbuf1] = HexToAscii(checksum & 0x0f);
////						Cbuf1++;
////						
////						MoveData(&Table_end[0],&M_UART_TxFIFO[0],Cbuf1,5);
////						Cbuf1 +=5;
////						
////						M_UART_TxLength =Cbuf1;
////				  		M_UART_TxIndex =0;				
////						_txr_rxr0= M_UART_TxFIFO[0];
////						
////						Cbuf0 =1;
////						do
////						{
////							GCC_CLRWDT();
////							if(M_UART_TxIndex >= M_UART_TxLength)
////								Cbuf0 =0;
////						}
////						while(Cbuf0);
////					}
////				}
//////				else
//////					Send_Nak();
////
////				M_UART_RxIndex =0;				
////			}
////			
//
////		
////			break;   //case 1 end
////		}
////
////		 //--- Error task ----
//	  	case 8:
//	  	{
//			//--- display date & time
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
//			if(F_500ms_LCD)
//			{
//				if(lcd.unit.Bit.TimeColon != 0)
//					LCD_BitSetOut( LcdBit_Unit_TimeColon, OFF) ;
//				else
//					LCD_BitSetOut( LcdBit_Unit_TimeColon, ON ) ;
//					
//				F_500ms_LCD =0;
//			}
//	  		
//	  		if(F_Low_battery_Act ==0)
//	  		{
//	  			M_RTC_display++;
//	  			if(M_RTC_display > 300)
//	  			{
//				    M_RTC_display = 0;
//					M_No_Active_Cnt = 0;
//					M_Task = C_OffMode;
//					M_TaskBuf0 =0;			
//					M_TaskBuf1 =0;
//				    //F_Beep_Shortx1 =1;
//				    M_Error_Task =0;
//				    //--- Lcd All off
//				    LCD_Clear(OFF);	
//				}
//	  		}
//	  		else
//	  		{
//	  			M_RTC_display++;
//	  			if(M_RTC_display > 1000)
//	  			{
//				    M_RTC_display = 0;
//					M_No_Active_Cnt = 0;
//					M_Task = C_OffMode;
//					M_TaskBuf0 =0;			
//					M_TaskBuf1 =0;
//				    //F_Beep_Shortx1 =1;
//				    M_Error_Task =0;
//				    //--- Lcd All off
//				    LCD_Clear(OFF);
//	  			}
//	  		}
//
//			break; 
//	  	}
//	
//	  	default:
//	  	{
//			M_RTC_display++;
//			if(M_RTC_display >=8)
//			{
//			    M_RTC_display = 0;
//				M_No_Active_Cnt = 0;
//				M_Task = C_OffMode;
//				M_TaskBuf0 =0;			
//				M_TaskBuf1 =0;
//			    //F_Beep_Actx1 =1;
//			    M_Error_Task =0;
//				//---Lcd All off
//	      		LCD_Clear(OFF);
//			}
//			break;
//	  	}	  
//	}
//	
//	//--- remover usb cable
//	if(M_UartInsertCnt !=0)
//		M_UartInsertCnt--;
//	
//	if(M_UartInsertCnt ==0 && M_TaskBuf0 > 0)
//	{
//		M_No_Active_Cnt = 0;
//		//-- quit MemoryMode mode
//	    M_Task = C_OffMode;           //quit MemoryMode mode
//	    M_TaskBuf0 =0;
//		M_TaskBuf1 =0;
//		M_Error_Task =0;
//	    M_RTC_display = 0; 
//	    
//		//---Lcd All off
//  		LCD_Clear(OFF);
//	}
//}

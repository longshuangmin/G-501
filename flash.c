#include "include.h"

//--------------------------------------------------------------------------
unsigned char WritePage_flash (unsigned int address)
{
	unsigned char Status;
	
	Status =1;
	
	if((address >= C_EEP_SerialNumber) && (address <= (C_FlashDataOffset +4096)))
	{
		if(Drv_Erase_Page(address,1) !=1)
			 Status=0;
			
		if(Drv_WriteFlashRom(address,128) !=1)
			Status=0;
	}
	return Status;
}

//--------------------------------------------------------------------------
void ReadPage_flash (unsigned int address)
{
	unsigned char temp;

	//============================
	//--- IAP read flash test
	for(temp =0; temp < 128; temp++)
	{
		if(temp < 64)
			M_FlashBuf0[temp] = Drv_ReadFlashRom(address + temp);
		else
			M_FlashBuf1[temp - 64] = Drv_ReadFlashRom(address + temp);
	}
}

//--------------------------------------------------------------------------
unsigned int Flash_Store_Read_Process (unsigned int address)
{
	unsigned int Ibuf0;
	//_mfi0 = 0b00000010;
	_emi =0;
	
	//-- initail _fc0
	_fmod0 =1;
	_fmod1 =1;
	_fmod2 =0;
	
	_frden =1;
	
	//--- Load Flash Address
	_farl = address %256;
	_farh = address /256;

	
	//--- enable read
	_frd =1;
	
	//--- waiting for read finish
	while(_frd)
	GCC_CLRWDT();
	
	Ibuf0 = _fd0h << 8;
	Ibuf0 |= _fd0l;

	
	_frden =0;           //disable read
	
	//_mfi0 = 0b00000010;
	_emi =1;
	
	
	return Ibuf0;
}

//--------------------------------------------------------------------------
unsigned char Flash_Store_Write_Process (unsigned int address,unsigned int data)
{
	unsigned int timeout;
	unsigned char temp;		
	//_mfi0 = 0b00000010;
	_emi =0;
	temp =0;
	if(_lvdo ==0)
	{
		if((address >= C_EEP_SerialNumber) && (address <= (C_FlashDataOffset +4095)))
		{
			//-- initail _fc0
			//-- write Enable
			_fmod0 =0;
			_fmod1 =1;
			_fmod2 =1;
			
			_fwpen =1;
			//-- load key code
			_fd1l = 0x00;
			_fd1h = 0x04;
			_fd2l = 0x0d;
			_fd2h = 0x09;
			_fd3l = 0xc3;
			_fd3h = 0x40;
			
			timeout =0;
			while(!_cfwen)   //danny test
			{
				GCC_CLRWDT();
				timeout++;
				if(timeout > 1000)
				{
					temp = 1;
					goto Flash_Store_Write_Exit;
				}
			}
			
			timeout =0;
			while(_fwpen)
			{
				GCC_CLRWDT();
				timeout++;
				if(timeout > 1000)
				{
					temp = 1;
					goto Flash_Store_Write_Exit;	
				}
			}
			
		
			_fc2=0x01;		//!!!!clear Write Buffer process!!!!
			timeout =0;
			while(_clwb)
			{
				GCC_CLRWDT();
				timeout++;
				if(timeout > 1000)
				{
					temp = 1;
					goto Flash_Store_Write_Exit;	
				}
			}
			//----------------------------
			//--- Write command '000'  ---
			_fmod0 =0;
			_fmod1 =0;
			_fmod2 =0;
			
			_cfwen =1;
			
			//--- Load Flash Address
			_farl = address %256;
			_farh = address /256;
			
			
			//--- load data
			_fd0l = data & 0x00ff;    		//load data L
			_fd0h = (data & 0xff00)>>8;    	//load data H
			
			//--- enable
			_fwt =1;
			
			//--- waiting for Write finish
			timeout =0;
			while(_fwt)
			{
				GCC_CLRWDT();
				timeout++;
				if(timeout > 1000)
				{
					temp = 1;
					goto Flash_Store_Write_Exit;	
				}
			}	
			_cfwen =0;
		}
		else
		{
			temp = 1;
		}
	}
	else
	{
		_lvden =0;
		_lvden =1;
		temp = 1;	
	}

Flash_Store_Write_Exit:	
	_farl = 0xc0;
	_farh = 0x7f;	
	//_mfi0 = 0b00000010;
	_emi =1;
	
	return temp;		//finish
	
}

//--------------------------------------------------------------------------
unsigned char Flash_Store_PageErase_Process (unsigned int address)
{
	unsigned int timeout;
	unsigned char temp;	
	
	temp =0;
	_emi =0;
	if(_lvdo ==0)
	{
		if((address >= C_EEP_SerialNumber) && ((address <= (C_FlashDataOffset +4095)) || 0x7fc0))
		{
			//-- initail _fc0
			//-- FWEN (Flash ROM Write Enable ) mode
			_fmod0 =0;
			_fmod1 =1;
			_fmod2 =1;
			
			_fwpen =1;
			//-- load key code
		
			_fd1l = 0x00;
			_fd1h = 0x04;
			_fd2l = 0x0d;
			_fd2h = 0x09;
			_fd3l = 0xc3;
			_fd3h = 0x40;
			
			timeout =0;
			while(_fwpen)
			{
				GCC_CLRWDT();
				timeout++;
				if(timeout > 1000)
				{
					temp = 1;
					goto Flash_Store_PageErase_Exit;	
				}
			}
				
			_cfwen =1;
		
		
			//--- erase command
			_fmod0 =1;
			_fmod1 =0;
			_fmod2 =0;
			
			
			
			//--- Load Flash Address
			_farl = address %256;
			_farh = address /256;
		
			
			//--- enable
			_fwt =1;
			
			//--- waiting for read finish
			
			timeout =0;
			while(_fwt)
			{
				GCC_CLRWDT();
				timeout++;
				if(timeout > 1000)
				{
					temp = 1;
					goto Flash_Store_PageErase_Exit;	
				}	
			}	
			_cfwen =0;
		}
		else
			temp = 1;
	}
	else
	{
		_lvden =0;
		_lvden =1;
		temp = 1;	
	}	
	
Flash_Store_PageErase_Exit:
	_farl = 0xc0;
	_farh = 0x7f;
	_emi =1;		
	
	return temp;		//finish	
}
# define SENDMAX   10
//--------------------------------------------------------------------------
void Store_measurement_data (void)
{
//	volatile unsigned int 	Ibuf1;
//	volatile unsigned char 	Cbuf0;
	unsigned char 	buf[6],i;	
	
   //--- save data record to eeprom----
   //--- data address = M_GM_Record_current*8
   //-- record +1
	if(M_GM_data_Record < C_GMDataSaveIndex)     //total memory record max=500
		M_GM_data_Record++;
 
	if(M_GM_Record_current >= C_GMDataSaveIndex)
   		M_GM_Record_current =0;        //memory full restart record 1
	M_GM_Record_current++;
	
	//--- Svav system vaule to flash
	Store_SetVauletoFlash();
		
//	ReadPage_flash(C_EEP_Significant);
//	
//	M_FlashBuf0[0x00] = M_GM_data_Record;  //load M_GM_data_Record 3D81
//	M_FlashBuf0[0x01] = M_GM_Record_current;  //load M_GM_Record_current 3D82
//
//	M_FlashBuf0[0x10] = M_GM_data_Record;  //load M_GM_data_Record 3D81
//	M_FlashBuf0[0x11] = M_GM_Record_current;  //load M_GM_Record_current 3D82
//	
//	M_FlashBuf0[0x20] = M_GM_data_Record;  //load M_GM_data_Record 3D81
//	M_FlashBuf0[0x21] = M_GM_Record_current;  //load M_GM_Record_current 3D82
//	
//	M_FlashBuf0[0x30] = M_GM_data_Record;  //load M_GM_data_Record 3D81
//	M_FlashBuf0[0x31] = M_GM_Record_current;  //load M_GM_Record_current 3D82
//	
//	Significant_Checksum();	
//	// Write flash area for special  record 3D80~3D85
//	WritePage_flash(C_EEP_Significant);
//  
//	//--- Writer record
//	buf[0] = (M_GM_data_Record & 0xff00) >>8;
//	buf[1] = M_GM_data_Record & 0x00ff;
//	write_eeprom(C_EEP_GM_RecordAdr,2,buf);
//	
//	//--- Writer record current
//	buf[0] = (M_GM_Record_current & 0xff00) >>8;
//	buf[1] = M_GM_Record_current & 0x00ff;
//	write_eeprom(C_EEP_GM_Current_RecordAdr,2,buf);
//	
//	//--- Writer Flash Life Count
//	buf[0] = M_FlashLifeCount >>24;
//	buf[1] = M_FlashLifeCount >>16;
//	buf[2] = M_FlashLifeCount >>8;
//	buf[3] = M_FlashLifeCount;
//	write_eeprom(C_EEP_FlashLifeCount_Adr,4,buf);

//	//--- Save data Glucose & date to flash ---
//	//--- get address (data package 8 bytes , but only used 6 bytes)
//	M_Ibuf0 = ((M_GM_Record_current-1)*4); 
//	M_Ibuf0 += C_FlashDataOffset;          //add flash offset addrss = save current data address
//	
//	Ibuf1 = C_FlashDataOffset;
//	//--- get erase point read Flash data record (bbuf1 = data section)
//	//--- M_Ibuf0 =>Current address
//	//--- 
//	for(Cbuf0= 0 ; Cbuf0<= 64 ; Cbuf0++)
//	{
//		M_FlashPage = Cbuf0;
//		Ibuf1 += 0x40;
//		if(Ibuf1 > M_Ibuf0)
//		{
//			Ibuf1 -= 0x40;
//			M_Ibuf2 = Ibuf1;
//			break;
//		}
//	}

	//============================
	//---計算記憶位置與頁面
	//Address = IAPWRSTARTADDRESS + ((M_Record-1) * 8);
	M_PageAddress = ((M_GM_Record_current-1) / 32) * 0x80;
	M_PageAddress += C_FlashDataOffset;
	M_PageIndex = ((M_GM_Record_current-1) % 32);
	
	ReadPage_flash(M_PageAddress);
  
	//--- get time year/month/day/hour/minutes/second
	//- get time
	
	
	buf[5] = M_Year;
	buf[4] = M_Month;// = 5;
	buf[3] = M_Days;// = 1;
	buf[2] = M_Hour;// = 12;
	buf[1] = M_Minutes;// = 0;
	buf[0] = M_Second;// = 0;
	M_Lbuf0 = DateToSecond(buf);   //change to second
	
	if(unsend_data[10].sg!=0x55aa)//init data record
	{
		unsend_data[10].sg=0x55aa;
		unsend_data[10].year=0;
		unsend_data[10].month=0;		
	}
	i=unsend_data[10].month;
	

	  unsend_data[i]. year=buf[5];
	  unsend_data[i].month=buf[4];
	  unsend_data[i].month |= meals<<6;//在月份高两位加入餐前后标志
	  unsend_data[i].day=buf[3];
	 
	  unsend_data[i].hour=buf[2];
	  unsend_data[i].min=buf[1];  
	  unsend_data[i].second=buf[0];
	  unsend_data[i].sg=M_GM_data;	
	  unsend_data[i].is_send=1;
	  
	  unsend_data[10].month++;//个数加1
	  if(unsend_data[10].month>=SENDMAX)
	  {
	     unsend_data[10].month=0;//to next
	     unsend_data[10].year=1;//over
	  }
	
	
//	//-- load time to RAM
//	Cbuf0 = M_Ibuf0 - M_Ibuf2;              //load save current data adr
	// Load Data 2/1
	if(M_PageIndex < 16)
	{			
		M_FlashBuf0[(M_PageIndex *4)] = (M_Lbuf0 & 0xffff0000) >>16;
		M_FlashBuf0[(M_PageIndex *4) + 1] = M_Lbuf0 & 0x0000ffff;
		M_FlashBuf0[(M_PageIndex *4) + 2] = M_GM_data;
		M_FlashBuf0[(M_PageIndex *4) + 3] = meals;		
		
	}
	else
	{
		M_FlashBuf1[((M_PageIndex - 16) *4)] = (M_Lbuf0 & 0xffff0000) >>16;
		M_FlashBuf1[((M_PageIndex - 16) *4) + 1] = M_Lbuf0 & 0x0000ffff;
		M_FlashBuf1[((M_PageIndex - 16) *4) + 2] = M_GM_data;
		M_FlashBuf1[((M_PageIndex - 16) *4) + 3] = meals;		
	}
//	Cbuf0++;
	// Load GM Temperature
//	M_FlashBuf[Cbuf0] = M_StripType;
//	Cbuf0++;
//	// Load GM AutoCodeNB
//	M_FlashBuf[Cbuf0] = M_StripType;
//	Cbuf0++;
//	// Load GM meal & Control
//	M_FlashBuf[Cbuf0] =M_Meal;
//	if(F_ControlOption)
//		M_FlashBuf[Cbuf0] |=0x0004;
//	Cbuf0++;
//		
//	M_FlashBuf[Cbuf0] = 0x0000;
//	Cbuf0++;
//	M_FlashBuf[Cbuf0] = 0x0000;		
		
	//-- save to Flash Rom
	WritePage_flash(M_PageAddress);
}

////--------------------------------------------------------------------------
//unsigned char LoadingParameterVaule (unsigned char Type)
//{
//	unsigned char address,count;
//
//}

//--------------------------------------------------------------------------
void Significant_Checksum (void)
{
	unsigned int checksum;
	unsigned char count;
	
	//--- checksum
	checksum =0;
	for(count =0 ;count <15 ; count++)
		checksum += M_FlashBuf0[0x00 +count];
	M_FlashBuf0[0x0f] = checksum;
	
	//--- checksum
	checksum =0;
	for(count =0 ;count <15 ; count++)
		checksum += M_FlashBuf0[0x10 + count];
	M_FlashBuf0[0x1f] = checksum;
	
	//--- checksum
	checksum =0;
	for(count =0 ;count <15 ; count++)
		checksum += M_FlashBuf0[0x20 + count];
	M_FlashBuf0[0x2f] = checksum;
	
	//--- checksum
	checksum =0;
	for(count =0 ;count <15 ; count++)
		checksum += M_FlashBuf0[0x30 + count];
	M_FlashBuf0[0x3f] = checksum;
}

//--------------------------------------------------------------------------
void Store_SetVauletoFlash (void)
{
	unsigned char count,address;
	ReadPage_flash(C_EEP_Significant);
	for(count =0; count <4; count++)
	{
		address = ((unsigned char)count * 0x10);
		M_FlashBuf0[address + C_Flash_RecordAdr] = M_GM_data_Record;
		M_FlashBuf0[address + C_Flash_Current_RecordAdr] = M_GM_Record_current;
		M_FlashBuf0[address + C_Flash_Send_RecordAdr] = M_GM_SendRecord;
		M_FlashBuf0[address + C_Flash_UnitAdr] = M_Unit;
		
		if(F_Alarm1_Enable)
			M_FlashBuf0[address + C_Flash_Alarm1Adr] = 0x8000;
		else
			M_FlashBuf0[address + C_Flash_Alarm1Adr] = 0x0000;
			
		if(F_Alarm2_Enable)
			M_FlashBuf0[address + C_Flash_Alarm2Adr] = 0x8000;
		else
			M_FlashBuf0[address + C_Flash_Alarm2Adr] = 0x0000;
			
		if(F_Alarm3_Enable)
			M_FlashBuf0[address + C_Flash_Alarm3Adr] = 0x8000;
		else
			M_FlashBuf0[address + C_Flash_Alarm3Adr] = 0x0000;
			
		if(F_Alarm4_Enable)
			M_FlashBuf0[address + C_Flash_Alarm4Adr] = 0x8000;
		else
			M_FlashBuf0[address + C_Flash_Alarm4Adr] = 0x0000;
			
		M_FlashBuf0[address + C_Flash_Alarm1Adr] |= M_Alarm1_HR << 6;
		M_FlashBuf0[address + C_Flash_Alarm1Adr] |= M_Alarm1_MIN;
		
		M_FlashBuf0[address + C_Flash_Alarm2Adr] |= M_Alarm2_HR << 6;
		M_FlashBuf0[address + C_Flash_Alarm2Adr] |= M_Alarm2_MIN;
		
		M_FlashBuf0[address + C_Flash_Alarm3Adr] |= M_Alarm3_HR << 6;
		M_FlashBuf0[address + C_Flash_Alarm3Adr] |= M_Alarm3_MIN;
		
		M_FlashBuf0[address + C_Flash_Alarm4Adr] |= M_Alarm4_HR << 6;
		M_FlashBuf0[address + C_Flash_Alarm4Adr] |= M_Alarm4_MIN;
	}	
	Significant_Checksum();	
	// Write flash area for special  record 3D80~3D85
	WritePage_flash(C_EEP_Significant);
}

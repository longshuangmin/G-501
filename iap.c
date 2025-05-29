#include "include.h"



/********************************************************************
Function: Flash存儲器寫使能
INPUT	: None
OUTPUT	: IAPEnableIsOk,1 Enable Ok,0 Enable Fail
NOTE	:
********************************************************************/
unsigned char Drv_Enable_FWEN(void)
{
	unsigned char EMIStatus,IAPEnableIsOk;
	IAPEnableIsOk = 1;
	EMIStatus = _emi;
	_emi = 0;
	GCC_CLRWDT();
	_fc0 = ENABLE_FWEN_MODE; // 寫功能使能模式,start a 300us counter
	_fd1l = 0x00;			 // 按順序將固定模式數據序列寫入對應的暫存器
	_fd1h = 0x04;
	_fd2l = 0x0D;
	_fd2h = 0x09;
	_fd3l = 0xC3;
	_fd3h = 0x40;
	_emi = EMIStatus;
	while(_fwpen);			// 寫使能成功后此位硬件自動清零
	if(!_cfwen)	
	{
		IAPEnableIsOk = 0x00;	// 讀CFWEN 確認狀態
	}
	return IAPEnableIsOk;
}
/********************************************************************
Function: 擦除Flash存儲器目標地址頁
INPUT	: Flash_Addr
OUTPUT	: ErasePageIsOk,1 ErasePage Ok, 0 ErasePage Fail
NOTE	:
*********************************************************************/
unsigned char Drv_Erase_Page(unsigned int EPage_Addr,unsigned char EPage_Length)
{
	unsigned char ErasePageIsOk,i;
	unsigned int  Check_Buff;
	ErasePageIsOk = 1;
	_emi = 0;
	GCC_CLRWDT();
	if(!Drv_Enable_FWEN())
	{
		ErasePageIsOk = 0x00;
	}
	
	_fc0 = PAGE_ERASE_MODE;			// 頁擦除模式
	_clwb = 1;		
	_farl = (unsigned char)(EPage_Addr&0xff);
	_farh = (unsigned char)(EPage_Addr>>8);	
	
	for(i=0;i<EPage_Length;i++)
	{
		_fd0h=0x00;				//標記地址
	}
	_fwt=1;						// 激活一個寫週期
	while(_fwt)					// 等待 Flash ROM 擦除完成
	{
		GCC_CLRWDT();
	}						
	for(i=0;i<EPage_Length;i++)
	{
		Check_Buff=Drv_ReadFlashRom(EPage_Addr);
		EPage_Addr++;
		if(Check_Buff!=0x00)		//確認是否擦除成功
		{
			ErasePageIsOk=0;
		}	
	}
	_cfwen = 0;					// Flash ROM 写除能
	_emi=1;					
	return ErasePageIsOk;
}
/********************************************************************
Function: 寫目標地址FLASH ROM 數據
INPUT	: FlashAddr,FlashLength
OUTPUT	: WriteFlashIsOk,1 WriteFlash Ok, 0 WriteFlash Fail
NOTE	:
*********************************************************************/
unsigned char Drv_WriteFlashRom(unsigned int FlashAddr,unsigned char FlashLength)
{
//	if(!Drv_Erase_Page(IAPWRSTARTADDRESS,FlashLength))
//	{
//		Drv_Erase_Page(IAPWRSTARTADDRESS,FlashLength); // 未擦除成功,處理
//	}
	unsigned char WriteFlashIsOk;
	unsigned int  Check_Buff;
	WriteFlashIsOk = 1;
	GCC_CLRWDT();
	if(!Drv_Enable_FWEN())
	{
		WriteFlashIsOk = 0x00;
	}
	_clwb = 1;					// write Initiate clear write buffer process
	while(_clwb);

	_fc0 = WRITE_FLASH_MODE;	//寫入模式

	_farl = (unsigned char)(FlashAddr&0xff);
	_farh = (unsigned char)(FlashAddr>>8) ;
	unsigned char i;
	for ( i = 0; i < FlashLength; i++)
	{
		if(i < 64)
		{
			_fd0l = (unsigned char)(M_FlashBuf0[i] & 0xff);
			_fd0h = (unsigned char)((M_FlashBuf0[i] >> 8)&0xff);
		}
		else
		{
			_fd0l = (unsigned char)(M_FlashBuf1[i - 64] & 0xff);
			_fd0h = (unsigned char)((M_FlashBuf1[i - 64] >> 8)&0xff);	
		}
	}
	_fwt = 1;					// 啟動寫入
	while(_fwt);
	
	for(i=0;i<FlashLength;i++)
	{
		Check_Buff=Drv_ReadFlashRom(FlashAddr+i);
		if(i < 64)
		{
			if(Check_Buff!=M_FlashBuf0[i])		//確認是否寫入成功
			{
				//--- fail
				WriteFlashIsOk = 0x00;
			}
		}
		else
		{
			if(Check_Buff!=M_FlashBuf1[i - 64])		//確認是否寫入成功
			{
				//--- fail
				WriteFlashIsOk = 0x00;
			}	
		}	
	}
	_cfwen = 0;					// 結束寫入，關閉寫使能
	return WriteFlashIsOk;
}
/********************************************************************
Function: 讀取目標地址FLASH ROM 數據
INPUT	: None
OUTPUT	: None
NOTE	:
*********************************************************************/
unsigned int Drv_ReadFlashRom(unsigned int RPage_Addr)
{
	
	volatile unsigned int   Read_Data=0xff;
	_emi = 0;
	GCC_CLRWDT();
	_fc0 = READ_FLASH_MODE;	
	_farl = (unsigned char)(RPage_Addr&0xff);
	_farh = (unsigned char)(RPage_Addr>>8);
	_frd=1;					// 啟動讀入
	while(_frd);
	Read_Data = (unsigned int)((Read_Data&_fd0h)<<8);
	Read_Data = (unsigned int)(Read_Data|_fd0l);
	_frden=0;
	_emi=1;
	return Read_Data;
}


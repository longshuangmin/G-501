#include "include.h"
#define MAX_EEPROM_ADDR	128//64

//--------------------------------------------------------------------------
/**
 * @brief 讀一個 Byte EEPROM 數據
 *
 * @param addr 地址(0~MAX_DATA_LEN)
 * @param 需要??据的?度
 * @return unsigned char
 */
 //--------------------------------------------------------------------------
enum STATUS_t Read_EEPROMByte(unsigned char addr, unsigned char *data)
{
	if (addr > MAX_EEPROM_ADDR)
	{
		return ERROR;
	}
	else
	{
		_eea = addr;
		_mp1h = 1;
		_mp1l = 0x40;
		asm("set [0x02].1");	// RDEN
		asm("set [0x02].0");	// RD
		asm("sz  [0x02].0");	// RD
		asm("jmp $-1");
		_iar1 = 0;
		*data = _eed;
		return SUCCESS;
	}
}
enum STATUS_t Read_EEPROMBuf(unsigned char addr, unsigned char* buf, unsigned char len)
{
    if((addr+len) > MAX_EEPROM_ADDR)
    {
        return ERROR;
    }
    unsigned char i = 0;
    for(i = 0; i<len; i++)
    {
        if(Read_EEPROMByte(addr, buf) != SUCCESS)
        {
        	return ERROR;
        }
        addr++;
        buf++;
    }
    return SUCCESS;
}
//--------------------------------------------------------------------------
/**
 * @brief 寫一個 byte EEPROM 數據
 *
 * @param addr
 * @param WriteData
 * @warning WREN 和 WR 必須連續兩個指令寫入，所以必須關閉中斷，防止中斷打斷
 */
 //--------------------------------------------------------------------------
enum STATUS_t Write_EEPROMByte(unsigned char addr, unsigned char WriteData)
{
	if (addr > MAX_EEPROM_ADDR)
	{
		return ERROR;
	}
	else
	{
		unsigned char readData;
		bit EMI_Protect;
		EMI_Protect = _emi;
		_emi = 0;
		_mp1h = 1;
		_mp1l = 0x40;
		_eea = addr;
		_eed = WriteData;
		//_WREN與_WR需在連續的兩個指令週期內完成
		asm("set [0x02].3");	// WREN
		asm("set [0x02].2");	// WR
		asm("sz  [0x02].2");	// WR
		asm("jmp $-1");
		_iar1 = 0; //disable WREN
		_emi = EMI_Protect;
		if (Read_EEPROMByte(addr, &readData) != SUCCESS)
		{
			return ERROR;
		}
		if (readData != WriteData)
		{
			return ERROR;
		}
		else
		{
			return SUCCESS;
		}
	}
}
enum STATUS_t Write_EEPROMBuf(unsigned char addr, unsigned char * buf, unsigned char len)
{
	if((addr+len) > MAX_EEPROM_ADDR)
	{
		return ERROR;
	}
	unsigned char i= 0;
	for(i= 0; i<len; i++)
	{
		if(Write_EEPROMByte(addr, *buf) != SUCCESS)
		{
			return ERROR;
		}
		addr++;
		buf++;
	}
	return SUCCESS;
}

#if 0
enum STATUS_t clear_EEPROMBuf(unsigned char addr, unsigned char len)
{
	if((addr+len) > MAX_EEPROM_ADDR)
	{
		return ERROR;
	}
	unsigned char i= 0;
	for(i= 0; i<len; i++)
	{
		if(Write_EEPROMByte(addr, 0xff) != SUCCESS)
		{
			return ERROR;
		}
		addr++;
	}
	return SUCCESS;
}

//--------------------------------------------------------------------------
void EepromCalibartion_Checksum (void)
{
	unsigned int checksum;
	unsigned char count,buf[2];
	
	//--- checksum
	checksum =0;
	for(count =0 ;count <14 ; count++)
	{
		Read_EEPROMByte((0x00 + count),buf);
		checksum += buf[0];
	}
	buf[0] = checksum >> 8;
	buf[1] = checksum;
	Write_EEPROMBuf(0x0e,buf,2);
	
	//--- checksum
	checksum =0;
	for(count =0 ;count <14 ; count++)
	{
		Read_EEPROMByte((0x00 + count),buf);
		checksum += buf[0];
	}
	buf[0] = checksum >> 8;
	buf[1] = checksum;
	Write_EEPROMBuf(0x1e,buf,2);
	
	//--- checksum
	checksum =0;
	for(count =0 ;count <14 ; count++)
	{
		Read_EEPROMByte((0x00 + count),buf);
		checksum += buf[0];
	}
	buf[0] = checksum >> 8;
	buf[1] = checksum;
	Write_EEPROMBuf(0x2e,buf,2);
	
	//--- checksum
	checksum =0;
	for(count =0 ;count <14 ; count++)
	{
		Read_EEPROMByte((0x00 + count),buf);
		checksum += buf[0];
	}
	buf[0] = checksum >> 8;
	buf[1] = checksum;
	Write_EEPROMBuf(0x3e,buf,2);
}
#endif
//
//
////--------------------------------------------------------------------------
//void write_eeprom_byte(unsigned char address,unsigned char data)
//{
//		_eea=address;
//		_eed=data;
//		_emi=0;
//
//
//		asm("set [04h].0");
//		asm("mov a,40h");
//		asm("mov [03h],a");
//		asm("set [02h].3");
//		asm("set [02h].2");				
//		_emi=1;
//		while(_wr)	
//			GCC_NOP();		
//		_wren=0;			
//	
//}
//
////--------------------------------------------------------------------------
//unsigned char read_eeprom_byte(unsigned char address)
//{
//		_eea=address;		
//		_emi=0;
//		_rden=1;
//		_rd=1;
//		_emi=1;		
//		while(_rd)
//			GCC_NOP();
//		_rden=0;		
//		return _eed;	
//}
//
////--------------------------------------------------------------------------
//void write_eeprom(unsigned char address,unsigned char lenght,unsigned char *buf)
//{
//	unsigned char count;
//
//	for(count = 0 ;count < lenght ;count++)
//	 	write_eeprom_byte((address+count),buf[count]);
//}
////--------------------------------------------------------------------------
//void read_eeprom(unsigned char address,unsigned char lenght,unsigned char *buf)
//{
//	unsigned char count;
//
//	for(count = 0 ;count < lenght ;count++)
//	 	buf[count] = read_eeprom_byte(address+count);
//}
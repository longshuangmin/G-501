#if 0
#include "include.h"

//**********************************
//I2C start signal
//**********************************
void i2cStart(void)
{
	SDAC=0;//set SDA as output
	SCLC=0;//set SCL as output
	SDA=1;GCC_DELAY(50);//SDA=1
	SCL=1;GCC_DELAY(50);//SCL=1
	SDA=0;GCC_DELAY(50);//SDA=0
	SCL=0;GCC_DELAY(50);//SCL=0	
}

//**********************************
//I2C stop signal
//**********************************
void i2cStop(void)
{
	SDAC=0;//set SDA as output
	SCLC=0;//set SCL as output
	SDA=0;GCC_DELAY(50);//SDA=0
	SCL=1;GCC_DELAY(50);//SCL=1
	SDA=1;GCC_DELAY(50);//SDA=1
	SCL=0;GCC_DELAY(50);//SCL=0
		
}
//**********************************
//ACK(0) signal
//**********************************
void Ack(void)
{
	SDAC=0;//set SDA as output
	SCLC=0;//set SCL as output
	SDA=0;GCC_DELAY(50);//SDA=0
	SCL=1;GCC_DELAY(50);//SCL=1
	SCL=0;GCC_DELAY(50);//SCL=0
	SDA=1;GCC_DELAY(50);//SDA=1
}
//**********************************
//NoAck(1) signal
//**********************************
void NoAck(void)
{
	SDAC=0;//set SDA as output
	SCLC=0;//set SCL as output
	SDA=1;GCC_DELAY(50);//SDA=1
	SCL=1;GCC_DELAY(50);//SCL=1
	SCL=0;GCC_DELAY(50);//SCL=0
}
//**********************************
//master check ack signal
//0:ACK complete，1 no complete
//**********************************
_Bool TestAck(void)
{	_Bool Ack_Bit;//define ack bit
	SDAC=1;//set SDA as input
	SCLC=0;//set SCL as output
	//SDA=1;_delay(30);//SDA=1
	SCL=1;GCC_DELAY(50);//SCL=1
	Ack_Bit=SDA;GCC_DELAY(50);//read back ACK
	SCL=0;GCC_DELAY(50);//SCL=0
	SDAC=0;
	return Ack_Bit;
}
//**********************************
//master write data
//**********************************
void i2cWrite(unsigned char Data)
{
	unsigned char count=8;
	SDAC=0;//set SDA as output
	SCLC=0;//set SCL as output
	while(count--)
	{
		SDA=(_Bool)(Data & 0x80);//bit7 sent to SDA pin
		GCC_DELAY(50);
		SCL=1;GCC_DELAY(50);//sent clock
		SCL=0;GCC_DELAY(50);
		Data=Data<<1;//Data shift left 1 bit
	}
}
//**********************************
//master read data
//**********************************
unsigned char i2cRead(void)
{
	unsigned char count=8,Data=0;
	SDAC=1;//set SDA as input
	SCLC=0;//set SCL as output
	while(count--)
	{
		SCL=1;GCC_DELAY(50);
		Data=Data<<1;//Data shift left 1 bit
		Data=Data|((unsigned char)(SDA));//read data and save in Data
		SCL=0;GCC_DELAY(50);
	}	
	return(Data);
}

//**********************************
//master read data
//**********************************
_Bool WriterEeprom(unsigned char Address,unsigned char Length,unsigned char *buf)
{
	unsigned char Data=0,count,count1;
	
//	P_EepromPpwer =1;
//	SCLPU =0;
//	SDAPU =0;	
	GCC_DELAY(50);
	
	i2cStart();
	i2cWrite(C_DeviceAddr);
	count1 =255;
	while(TestAck())
	{
		count1--;
		if(count1 ==0)
			return 1;
	}
	i2cWrite(Address);
	count1 =255;
	while(TestAck())
	{
		count1--;
		if(count1 ==0)
			return 1;
	}
	
	for(count =0;count < Length;count++)				//write data form 0~255
	{
		Data = buf[count];
		i2cWrite(Data);	
		count1 =255;
		while(TestAck())
		{
			count1--;
			if(count1 ==0)
				return 1;
		}
	}
	i2cStop();
	
//	P_EepromPpwer =0;
//	SCLPU =0;
//	SDAPU =0;
	
	return 0;		
}

//**********************************
//master read data
//**********************************
_Bool ReadEeprom(unsigned char Address,unsigned char Length,unsigned char *buf)
{
	unsigned char Data=0,count;
	
	//P_EepromPpwer =1;
//	SCLPU =0;
//	SDAPU =0;
	GCC_DELAY(50);
	
	i2cStart();
	i2cWrite(C_DeviceAddr);
	count =255;
	while(TestAck())
	{
		//GCC_DELAY(1000);
		count--;
		if(count ==0)
			return 1;
	}
	i2cWrite(Address);
	count =255;
	while(TestAck())
	{
		//GCC_DELAY(1000);
		count--;
		if(count ==0)
			return 1;
	}
//	i2cWrite(Address);
//	count =255;
//	while(TestAck())
//	{
//		//GCC_DELAY(1000);
//		count--;
//		if(count ==0)
//			return 1;
//	}
	
	i2cStart();
	i2cWrite(C_DeviceAddr+1);
	count =255;
	while(TestAck())
	{
		//GCC_DELAY(5000);
		count--;
		if(count ==0)
			return 1;
	}
	for(count =0;count < Length;count++)
	{
		Data =i2cRead();
		buf[count] = Data;
		if(count+1 != Length)
			Ack();
	}
	NoAck();
	i2cStop();
	
	//P_EepromPpwer =0;
//	SCLPU =0;
//	SDAPU =0;
	return 0;	
}

//**********************************
//Load_EepromVaule
//**********************************
void Load_EepromVaule(void)
{
//	F_I2cError =0;
//	F_I2cError = ReadEeprom(0,18,&M_UART_TxFIFO);
//			
//	if(F_I2cError ==0)
//	{
//		
//		
//		
//	}	
}
//
//void flash_test(void)
//{
//	code_buf.code_Chol_Typ.a1=-111.155646;//填充总胆固醇参数到M_FlashBuf0
//	code_buf.code_Chol_Typ.b1=-2222.155646;	
//	code_buf.code_Chol_Typ.c1=-33333.155646;		
//	for(temp=0;temp<64;temp++)
//	{
//		M_FlashBuf0[temp]=code_buf.adc_buff[temp];
//	}
//	
//	code_buf.code_Urea_Type.a1=-456.155646;//填充尿酸 参数到M_FlashBuf1
//	code_buf.code_Urea_Type.b1=-567.155646;	
//	code_buf.code_Urea_Type.c1=-789.155646;	
//	for(temp=0;temp<64;temp++)
//	{
//		M_FlashBuf1[temp]=code_buf.adc_buff[temp];
//	}	
//
//	WritePage_flash(0xaf80);//一次写入8行（8*26	=128 WORD=512bye)
//	WritePage_flash(0xb000);
//	WritePage_flash(0xb080);	
//	WritePage_flash(0xb100);
//}	
#endif
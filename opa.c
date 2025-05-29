#include "include.h"

//--------------------------------------------------------------------------
/**
 * @brief 開啟 DACVREF&OPA1&DACO1 並校準Vos 校準完成後 關閉 OPA1&DACVREF&DACO1
 *
 * @warning  OPA1 電源來自 Voreg 若需使用 DACVREF 必須開啟 Voreg
 * @note 為了最好的校準效果 建議 DACO1 值設置為實際應用下的值
 */
//--------------------------------------------------------------------------
void fun_CalOPA1Offset(void)
{
	volatile bit OPAStatus;
	volatile unsigned char i, OPAData0 , OPAData1;

	SET_DACVREF_POWER(POWERON);
	SET_DACn_VOLTAGE(1, DACnOEnable);
	SET_PIN_OPnP_DAC1O(1);

	SET_OPAn_MODE_CALOFFSET(1);
	SET_OPAn_POWER(1,POWERON);

	_opa1c = _opa1c & 0xE0;
	GCC_DELAY(1000);
	if (_op1do)	{ OPAStatus = 0x01;	}
	else		{ OPAStatus = 0x00;	}
	for (i = 0; i < 32; i++)
	{
		_opa1c++;
		GCC_DELAY(1000);
		GCC_CLRWDT();
		if (_op1do != OPAStatus)
		{ OPAData0 = _opa1c & 0x1f;	break;}
	}

	_opa1c |= 0x1F;
	GCC_DELAY(1000);
	if (_op1do) { OPAStatus = 0x01;	}
	else		{ OPAStatus = 0x00;	}
	for (i = 0; i < 32; i++)
	{
		_opa1c--;
		GCC_DELAY(1000);
		GCC_CLRWDT();
		if (_op1do != OPAStatus)
		{	OPAData1 = _opa1c & 0x1f;	break;}
	}
	_opa1c = (OPAData0 + OPAData1)/2;
	SET_OPAn_POWER(1,POWEROFF);
	SET_DACVREF_POWER(POWEROFF);
	SET_DACn_VOLTAGE(1, DACnODISABLE);
}

//--------------------------------------------------------------------------
/**
 * @brief 開啟 DACVREF&OPA2&DACO1 並校準Vos 校準完成後 關閉 OPA1&DACVREF&DACO2
 *
 * @warning  OPA2 電源來自 Voreg 若需使用 DACVREF 必須開啟 Voreg
 * @note 為了最好的校準效果 建議 DACO1 值設置為實際應用下的值
 */
 //--------------------------------------------------------------------------
void fun_CalOPA2Offset(void)
{
	volatile bit OPAStatus;
	volatile unsigned char i, OPAData0 , OPAData1;

	SET_DACVREF_POWER(POWERON);
	SET_DACn_VOLTAGE(1, DACnOEnable);
	SET_PIN_OPnP_DAC1O(1);

	SET_OPAn_MODE_CALOFFSET(2);
	SET_OPAn_POWER(2,POWERON);

	_opa2c &= 0xE0;
	GCC_DELAY(1000);
	if (_op2do)	{ OPAStatus = 0x01;	}
	else		{ OPAStatus = 0x00;	}
	for (i = 0; i < 32; i++)
	{
		_opa2c++;
		GCC_DELAY(1000);
		GCC_CLRWDT();
		if (_op2do != OPAStatus)
		{ OPAData0 = _opa2c & 0x1f;	break;}
	}

	_opa2c |= 0x1F;
	GCC_DELAY(1000);
	if (_op2do) { OPAStatus = 0x01;	}
	else		{ OPAStatus = 0x00;	}
	for (i = 0; i < 32; i++)
	{
		_opa2c--;
		GCC_DELAY(1000);
		GCC_CLRWDT();
		if (_op2do != OPAStatus)
		{	OPAData1 = _opa2c & 0x1f;	break;}
	}
	_opa2c = (OPAData0 + OPAData1)/2;
	SET_OPAn_POWER(1,POWEROFF);
	SET_DACVREF_POWER(POWEROFF);
	SET_DACn_VOLTAGE(1, DACnODISABLE);
}

//--------------------------------------------------------------------------
/**
 * @brief 開啟 DACVREF&OPA1&BREN 並校準Vos 校準完成後 關閉 OPA1&DACVREF&BREN
 *
 * @warning  OPA3 電源來自 Voreg 若需使用 DACVREF 必須開啟 Voreg
 */
 //--------------------------------------------------------------------------
 
void fun_CalOPA3Offset(void)
{
	volatile bit OPAStatus;
	volatile unsigned char i, OPAData0 , OPAData1;

	SET_DACVREF_POWER(POWERON);
	SET_DACn_VOLTAGE(1, DACnOEnable);
	SET_PIN_OP3P_0_5AVDD();

	SET_OPA3_MODE_CALOFFSET();
	SET_OPA34_POWER(POWERON);

	_bopac1 &= 0xE0;
	GCC_DELAY(1000);
	if (_op3do)	{ OPAStatus = 0x01;	}
	else		{ OPAStatus = 0x00;	}
	for (i = 0; i < 32; i++)
	{
		_bopac1++;
		GCC_DELAY(1000);
		GCC_CLRWDT();
		if (_op3do != OPAStatus)
		{ OPAData0 = _bopac1 & 0x1f;	break;}
	}

	_bopac1 |= 0x1F;
	GCC_DELAY(1000);
	if (_op3do) { OPAStatus = 0x01;	}
	else		{ OPAStatus = 0x00;	}
	for (i = 0; i < 32; i++)
	{
		_bopac1--;
		GCC_DELAY(1000);
		GCC_CLRWDT();
		if (_op3do != OPAStatus)
		{	OPAData1 = _bopac1 & 0x1f;	break;}
	}
	_bopac1 = (OPAData0 + OPAData1)/2;
	SET_OPA34_POWER(POWEROFF);
	SET_DACVREF_POWER(POWEROFF);
	SET_DACn_VOLTAGE(1, DACnODISABLE);
	SET_PIN_OP3P_OPEN();
}

////--------------------------------------------------------------------------
//void Initnal_OPA1_Gpio (unsigned char En)
//{
//	if(En ==1)
//	{
//		_pcc2 = 1;
//		_pc2 =0;
//		_pcpu2 = 0;
//	}
//	else
//	{
//		_pcc2 = 0;
//		_pc2 =0;
//		_pcpu2 = 0;
//	}					
//}
////--------------------------------------------------------------------------
//void Initnal_OPA2_Gpio (unsigned char En)
//{
//	if(En ==1)
//	{
//		//--- set pb1 io
//		_pbc1 =1;
//		_pb1 =0;
//		_pbpu1 =0;
//
//	}
//	else
//	{
//		//--- set pb1 io
//		_pbc1 =1;
//		_pb1 =0;
//		_pbpu1 =0;
//
//	}					
//}
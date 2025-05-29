#include "include.h"

const unsigned char Table_Bootload[]={"Bootload"};

#define UART_OK		0x00;
#define UART_OVER	0x02;
////--------------------------------------------------------------------------
void fun_UART0PowerOnInit(void)
{
	SET_UARTn_Format_D8_NONE_S1(0); // 數據傳輸格式設定
//	SET_UARTn_BAUDRATE_19200(0);	// 波特率設定
	SET_UARTn_BAUDRATE_9600(0);
	SET_UARTn_ADDRESS_DISABLE(0);
	SET_UARTn_RECEIVER_IE_ENABLE(0);
	SET_UARTn_TRANSMITTER_IE_ENABLE(0);
	SET_UARTn_TRANSMITTER_EMPTY_ENABLE(0);
	SET_UARTn_ENABLE(0);
	// UART0 IO
	SET_UART0_PIN_PD4PD5();
	//lu8v_Rx0BufLength = 5;
}

////--------------------------------------------------------------------------
void fun_UART1PowerOnInit(void)
{

	SET_UARTn_Format_D8_NONE_S1(1);	// 數據傳輸格式設定
	SET_UARTn_BAUDRATE_19200(1);	// 波特率設定
	SET_UARTn_ADDRESS_DISABLE(1);
	SET_UARTn_RECEIVER_IE_ENABLE(1);
	SET_UARTn_TRANSMITTER_IE_ENABLE(1);
	SET_UARTn_TRANSMITTER_EMPTY_ENABLE(1);
	SET_UARTn_ENABLE(1);
	// UART1 IO
	SET_UART1_PIN_PC4PC5();
	//lu8v_Rx0BufLength = 5;
}

////--------------------------------------------------------------------------
//void  fun_Uart0StartTx( unsigned char TxLength)
//{
//	lu8v_Tx0BufLength = TxLength;
//	// Start TX
//	gbv_IsBusyUart0Tx = 1; // uart 忙碌
//	lu8v_Tx0Bufoffset = 1; 因為0已經直接發送了
//	_acc = _u0sr;
//	_txr_rxr0 = gu8v_Uart0TxBuf[0];
//}
//--------------------------------------------------------------------------
void fun_Uart1StartTx( unsigned char TxLength)
{
	M_UART_TxLength += TxLength;
	// Start TX
//	gbv_IsBusyUart1Tx = 1; // uart 蹇欑
//	lu8v_Tx1Bufoffset = 1; // 鍥犵偤0宸茬稉鐩存帴鐧奸�佷簡
	//if(M_UART_TxLength ==0)
	if(M_UART_TxIndex ==0)
	{
		//_acc = _u1sr;
		_txr_rxr1 = M_UART_TxFIFO[0];
	}
	else
	{
		if(M_UART_TxIndex == M_UART_TxIndex_Old)
		{
			M_UART_Tx_ErrorCnt++;
			if(M_UART_Tx_ErrorCnt >2)
			{
				M_UART_Tx_ErrorCnt =0;
				_txr_rxr1 = M_UART_TxFIFO[M_UART_TxIndex];
				M_UART_TxIndex_Old = M_UART_TxIndex;
			}	
		}
		else
		{
			M_UART_TxIndex_Old = M_UART_TxIndex;
		}
		
	}
}

////--------------------------------------------------------------------------
//unsigned char fun_UART0WriteTxBuf(char* src,unsigned char startaddr, unsigned char len)
//{
//	if (len+startaddr > UART0_LENGTH_TX)
//	{
//		return UART_OVER;
//	}
//	else
//	{
//		unsigned char i;
//		for ( i = startaddr; i < len; i++)
//		{
//			gu8v_Uart0TxBuf[i] = *src++;
//		}
//		return UART_OK;
//	}
//}
////--------------------------------------------------------------------------
//unsigned char fun_UART0WriteTxBufStart(char* src, unsigned char len)
//{
//	if (len > UART0_LENGTH_TX)
//	{
//		return UART_OVER;
//	}
//	else
//	{
//		unsigned char i;
//		for ( i = 0; i < len; i++)
//		{
//			gu8v_Uart0TxBuf[i] = *src++;
//		}
//		fun_Uart0StartTx(len);
//		return UART_OK;
//	}
//}
//--------------------------------------------------------------------------
unsigned char fun_UART1WriteTxBufStart(unsigned char* src, unsigned char len)
{
	volatile unsigned char i,count/*,temp*/;
	
	if (len > UART1_LENGTH_TX)
	{
		return UART_OVER;
	}
	else
	{			
		if(M_UART_TxIndex < M_UART_TxLength)
			count= M_UART_TxLength;
		else
		{
			count =0;
			M_UART_TxIndex =0;
			M_UART_TxLength =0;
			M_UART_TxIndex_Old =0;
			M_UART_Tx_ErrorCnt =0;
			
		}
			
		for ( i = count; i < count + len; i++)
		{
			M_UART_TxFIFO[i] = *src++;
		}
		
		fun_Uart1StartTx(len);
		
//		temp =1;
//  		while(temp)
//  		{
//			GCC_CLRWDT();
//			if(M_UART_TxIndex >= M_UART_TxLength)
//				temp =0;	
//  		}
		
		return UART_OK;
	}
}
////--------------------------------------------------------------------------
void  fun_Uart0StartTx( unsigned char TxLength)
{
//	lu8v_Tx0BufLength = TxLength;
//	// Start TX
//	gbv_IsBusyUart0Tx = 1; // uart 蹇欑
//	lu8v_Tx0Bufoffset = 1; // 鍥犵偤0宸茬稉鐩存帴鐧奸�佷簡
//	_acc = _u0sr;
//	_txr_rxr0 = gu8v_Uart0TxBuf[0];

	M_UART_TxLength += TxLength;
	if(M_UART_TxIndex ==0)
	{
		//_acc = _u1sr;
		_txr_rxr0 = M_UART_TxFIFO[0];
	}
	else
	{
		if(M_UART_TxIndex == M_UART_TxIndex_Old)
		{
			M_UART_Tx_ErrorCnt++;
			if(M_UART_Tx_ErrorCnt >2)
			{
				M_UART_Tx_ErrorCnt =0;
				_txr_rxr0 = M_UART_TxFIFO[M_UART_TxIndex];
				M_UART_TxIndex_Old = M_UART_TxIndex;
			}	
		}
		else
		{
			M_UART_TxIndex_Old = M_UART_TxIndex;
		}
		
	}

}
//--------------------------------------------------------------------------
unsigned char fun_UART0WriteTxBufStart(char* src, unsigned char len)
{
	volatile unsigned char i,count;
	
	if (len > UART1_LENGTH_TX)
	{
		return UART_OVER;
	}
	else
	{			
		if(M_UART_TxIndex < M_UART_TxLength)
			count= M_UART_TxLength;
		else
		{
			count =0;
			M_UART_TxIndex =0;
			M_UART_TxLength =0;
			M_UART_TxIndex_Old =0;
			M_UART_Tx_ErrorCnt =0;
			
		}
			
		for ( i = count; i < count + len; i++)
		{
			M_UART_TxFIFO[i] = *src++;
		}
		
		fun_Uart0StartTx(len);
		
//		temp =1;
//  		while(temp)
//  		{
//			GCC_CLRWDT();
//			if(M_UART_TxIndex >= M_UART_TxLength)
//				temp =0;	
//  		}
		
		return UART_OK;
	}
}
//--------------------------------------------------------------------------
//void fun_UART_SendfloatValue(signed long tValue)
//{
//	unsigned char buff[10] = {0};
//	unsigned char i = 10;
//	unsigned char tmpValue = 0;
//	unsigned char signFlag = 0;	
//	volatile signed long value = 0;
//
//	if(tValue<0)
//	{
//		signFlag = 1;
//		value =((signed long)0 - tValue);
//	}
//	else
//	{
//		signFlag = 0;
//		value = (signed long)tValue;
//	}
//	
//	
//	while(i)
//	{
//		i--;
//		if(i==7) //Gary
//		//if(i==6)//for 3 digital resolution
//		{
//			buff[i] = '.';
//			i--;
//			buff[i] = value%10+0x30;
//			value = value/10;
//			
//			tmpValue = 0;
//		}
//		else
//		{
//			buff[i] = value%10+0x30;
//			value = value/10;
//			
//			if(buff[i] == 0x30)
//			{
//				tmpValue++;
//			}
//			else
//			{
//				tmpValue = 0;
//			}	
//		}
//
//
//	}
//	tmpValue=tmpValue-2;// Gary
//	if(signFlag)
//	{
//		fun_UART1WriteTxBufStart("-",1);
//		GCC_DELAY(500);
//	}
//	if(tmpValue >= 10)
//	{
//		fun_UART1WriteTxBufStart("0",1);
//		GCC_DELAY(500);
//	}
//	else
//	{
//		fun_UART1WriteTxBufStart(&buff[tmpValue],(10-tmpValue));
//	}
//}

//--------------------------------------------------------------------------
void fun_UART_SendValue(signed long tValue)
{
	unsigned char buff[10] = {0};
	unsigned char i = 10;
	unsigned char tmpValue = 0;
	unsigned char signFlag = 0;	
	volatile signed long value = 0;

	if(tValue<0)
	{
		signFlag = 1;
		value =((signed long)0 - tValue);
	}
	else
	{
		signFlag = 0;
		value = (signed long)tValue;
	}
	
	
	while(i)
	{
		i--;
		buff[i] = value%10+0x30;
		value = value/10;
		if(buff[i] == 0x30)
		{
			tmpValue++;
		}
		else
		{
			tmpValue = 0;
		}
	}
	
	if(signFlag)
	{
		fun_UART1WriteTxBufStart((unsigned char *)"-",1);
		GCC_DELAY(500);
	}

	
	if(tmpValue >= 10)
	{
		fun_UART1WriteTxBufStart((unsigned char *)"0",1);
		GCC_DELAY(500);
	}
	else
	{
		fun_UART1WriteTxBufStart((unsigned char *)&buff[tmpValue],(10-tmpValue));
	}
}

//--------------------------------------------------------------------------
//void fun_UART_ReceiveProcess(void)
//{
//	//--------------------
//	//--- uart RX receive
//	//--------------------
//	if(F_UartDataComing)
//	{
//		F_UartDataComing =0;
//	
//		if(DataCompare(&Table_Bootload[0],&M_UART_RxFIFO[0],8))
//		{
//			Drv_Erase_Page(Signature_Address,128);
//			fun_UART1WriteTxBufStart("ok\r\n",4);
//			//--- Go to watchdog time out
//			while(1);
//		}
//		
//		M_UART_RxIndex =0;
//	}
//}
////--------------------------------------------------------------------------
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
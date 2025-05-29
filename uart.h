
//#ifndef _BH67F2485_UART_H_
//#define _BH67F2485_UART_H_

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 共用變量 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#define  UART0_LENGTH_TX	32	// 協議中最大的長度
#define  UART0_LENGTH_RX	32	// 協議中最大的長度

#define  UART1_LENGTH_TX	128	// 協議中最大的長度
#define  UART1_LENGTH_RX	128	// 協議中最大的長度
unsigned char fun_UART0WriteTxBufStart(char* src, unsigned char len);
//extern volatile unsigned char 	gu8v_Uart0TxBuf[UART0_LENGTH_TX];
//extern volatile unsigned char 	gu8v_Uart0RxBuf[UART0_LENGTH_RX];
//extern volatile unsigned char  lu8v_Tx0Bufoffset;   // TX 偏移量
//extern volatile unsigned char  lu8v_Tx0BufLength;   // TX 幀長度
//extern volatile unsigned char  gu8v_Uart0TxCycle;   // TX 發送週期
//extern volatile bit gbv_IsBusyUart0Tx;              // TX is busy
//
//extern volatile unsigned char  lu8v_Rx0Bufoffset;   // RX 偏移量
//extern volatile unsigned char  lu8v_Rx0BufLength;   // RX 幀長度
//extern volatile unsigned char  gu8v_TBRx0TimeOutCnt;// RX 幀timeout
//extern volatile bit gbv_UartRx0Success;             // Rx is ok,user can process the rx buf data
//
//extern volatile unsigned char 	gu8v_Uart1TxBuf[UART1_LENGTH_TX];
//extern volatile unsigned char 	gu8v_Uart1RxBuf[UART1_LENGTH_RX];
//extern volatile unsigned char  lu8v_Tx1Bufoffset;   // TX 偏移量
//extern volatile unsigned char  lu8v_Tx1BufLength;   // TX 幀長度
//extern volatile unsigned char  gu8v_Uart1TxCycle;   // TX 發送週期
//extern volatile bit gbv_IsBusyUart1Tx;              // TX is busy
//
//extern volatile unsigned char  lu8v_Rx1Bufoffset;   // RX 偏移量
//extern volatile unsigned char  lu8v_Rx1BufLength;   // RX 幀長度
//extern volatile unsigned char  gu8v_TBRx1TimeOutCnt;// RX 幀timeout
//extern volatile bit gbv_UartRx1Success;             // Rx is ok,user can process the rx buf data
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 共用函數 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//void fun_UART0PowerOnInit();     // 初始化
//void fun_UART1PowerOnInit();
//void fun_Uart1StartTx( unsigned char TxLength);
//void fun_Uart0StartTx( unsigned char TxLength);
//unsigned char fun_UART0WriteTxBufStart(char* src, unsigned char len);
//unsigned char fun_UART1WriteTxBufStart(char* src, unsigned char len);
//unsigned char fun_UART0WriteTxBuf(char* src,unsigned char startaddr, unsigned char len);
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 預定義@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#define SET_UARTn_ENABLE(n)	    { _uarten##n = 1;_rxen##n = 1;_txen##n = 1;_ur##n##f = 0;_txif##n = 0; _ur##n##e = 1; _emi = 1;}
#define SET_UARTn_DISABLE(n)	{ _uarten##n = 0;_rxen##n = 0;_txen##n = 0;}
#define SET_UART0_PIN_PD4PD5()  { _pds1 &= 0xF0;_pds1 |= 0x05; }
#define SET_UART1_PIN_PC4PC5()  { _pcs1 = 0x0A;}

#define SET_UARTn_Format_D8_NONE_S1(n)		{ _u##n##cr1 = 0x00; }// 傳輸8bit = (8bit-Data  None-Parity  None-Add)1bit-Stop
#define SET_UARTn_Format_D7_EVEN_S1(n)		{ _u##n##cr1 = 0x20; }// 傳輸8bit = (7bit-Data  Even-Parity  None-Add)1bit-Stop
#define SET_UARTn_Format_D7_ODD_S1(n)		{ _u##n##cr1 = 0x30; }// 傳輸8bit = (7bit-Data  Odd -Parity  None-Add)1bit-Stop
#define SET_UARTn_Format_D9_NONE_S1(n)		{ _u##n##cr1 = 0x40; }// 傳輸9bit = (9bit-Data  None-Parity  None-Add)1bit-Stop
#define SET_UARTn_Format_D8_EVEN_S1(n)		{ _u##n##cr1 = 0x60; }// 傳輸9bit = (8bit-Data  Even-Parity  None-Add)1bit-Stop
#define SET_UARTn_Format_D8_ODD_S1(n)		{ _u##n##cr1 = 0x70; }// 傳輸9bit = (8bit-Data  Odd-Parity   None-Add)1bit-Stop
#define SET_UARTn_Format_D8_NONE_S2(n)		{ _u##n##cr1 = 0x00; }// 傳輸8bit = (8bit-Data  None-Parity  None-Add)2bit-Stop
#define SET_UARTn_Format_D7_EVEN_S2(n)		{ _u##n##cr1 = 0x20; }// 傳輸8bit = (7bit-Data  Even-Parity  None-Add)2bit-Stop
#define SET_UARTn_Format_D7_ODD_S2(n)		{ _u##n##cr1 = 0x30; }// 傳輸8bit = (7bit-Data  Odd -Parity  None-Add)2bit-Stop
#define SET_UARTn_Format_D9_NONE_S2(n)		{ _u##n##cr1 = 0x40; }// 傳輸9bit = (9bit-Data  None-Parity  None-Add)2bit-Stop
#define SET_UARTn_Format_D8_EVEN_S2(n)		{ _u##n##cr1 = 0x60; }// 傳輸9bit = (8bit-Data  Even-Parity  None-Add)2bit-Stop
#define SET_UARTn_Format_D8_ODD_S2(n)		{ _u##n##cr1 = 0x70; }// 傳輸9bit = (8bit-Data  Odd-Parity   None-Add)2bit-Stop

#define SET_UARTn_WAKEUP_ENABLE(n)				{ _wake##n  = 1;}
#define SET_UARTn_WAKEUP_DISABLE(n)				{ _wake##n  = 0;}
#define SET_UARTn_ADDRESS_ENABLE(n)				{ _adden##n = 1;}
#define SET_UARTn_ADDRESS_DISABLE(n)			{ _adden##n = 0;}
#define SET_UARTn_RECEIVER_IE_ENABLE(n)			{ _rie##n   = 1;} // OERR(溢出)/RXIF(有有效數據)置位時可置中斷標誌位
#define SET_UARTn_RECEIVER_IE_DISABLE(n)		{ _rie##n   = 0;}
#define SET_UARTn_TRANSMITTER_IE_ENABLE(n)	    { _tiie##n = 1;} // TIDLE(無數據傳輸)置位，可置中斷標誌位
#define SET_UARTn_TRANSMITTER_IE_DISABLE(n)		{ _tiie##n = 0;}
#define SET_UARTn_TRANSMITTER_EMPTY_ENABLE(n)	{ _teie##n = 1;} // TXIF(數據已加載到移位暫存器，TXR為空)置位時，可置中斷標誌位
#define SET_UARTn_TRANSMITTER_EMPTY_DISABLE(n)	{ _teie##n = 0;}

#if SYS_CLOCK_FREQ == 4000000
    #define SET_UARTn_BAUDRATE_300(n)			{ _brgh##n = 0; _brg##n = 207;}
    #define SET_UARTn_BAUDRATE_1200(n)			{ _brgh##n = 1; _brg##n = 207;}
    #define SET_UARTn_BAUDRATE_2400(n)			{ _brgh##n = 1; _brg##n = 103;}
    #define SET_UARTn_BAUDRATE_4800(n)			{ _brgh##n = 1; _brg##n =  51;}
    #define SET_UARTn_BAUDRATE_9600(n)			{ _brgh##n = 1; _brg##n =  25;}
    #define SET_UARTn_BAUDRATE_19200(n)		    { _brgh##n = 1; _brg##n =  12;}
    #define SET_UARTn_BAUDRATE_250000(n)		{ _brgh##n = 1; _brg##n =   0;}
#endif
#if SYS_CLOCK_FREQ == 8000000
    #define SET_UARTn_BAUDRATE_1200(n)			{ _brgh##n = 0; _brg##n = 103;}
    #define SET_UARTn_BAUDRATE_2400(n)			{ _brgh##n = 1; _brg##n = 207;}
    #define SET_UARTn_BAUDRATE_4800(n)			{ _brgh##n = 1; _brg##n = 103;}
    #define SET_UARTn_BAUDRATE_9600(n)			{ _brgh##n = 1; _brg##n =  51;}
    #define SET_UARTn_BAUDRATE_19200(n)		    { _brgh##n = 1; _brg##n =  25;}
    #define SET_UARTn_BAUDRATE_38400(n)		    { _brgh##n = 1; _brg##n =  12;}
    #define SET_UARTn_BAUDRATE_250000(n)		{ _brgh##n = 1; _brg##n =   1;}
#endif
#if SYS_CLOCK_FREQ == 12000000
    #define SET_UARTn_BAUDRATE_1200(n)			{ _brgh##n = 0; _brg##n = 155;}
    #define SET_UARTn_BAUDRATE_2400(n)			{ _brgh##n = 0; _brg##n =  77;}
    #define SET_UARTn_BAUDRATE_4800(n)			{ _brgh##n = 1; _brg##n = 155;}
    #define SET_UARTn_BAUDRATE_9600(n)			{ _brgh##n = 1; _brg##n =  77;}
    #define SET_UARTn_BAUDRATE_19200(n)		    { _brgh##n = 1; _brg##n =  38;}
    #define SET_UARTn_BAUDRATE_57600(n)		    { _brgh##n = 1; _brg##n =  12;}
    #define SET_UARTn_BAUDRATE_250000(n)		{ _brgh##n = 1; _brg##n =   2;}
#endif

//#endif
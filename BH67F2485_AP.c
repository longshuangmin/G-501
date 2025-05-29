#if 0
#include "BH67F2485.h"
#include "mytypedef.h"
#include "regs_mapping.h"
#include "AP_STARTUP_OPTION.h"
#include "include.h"

//#define Size  9
//
//unsigned char CH[Size];
//unsigned char NUM;
//unsigned char ReceiveFlag;
//unsigned char Command;


void main_AP();
//void Clear_RAM () ;
void UART_init();
void UART_COMMAND_PROCESS();
unsigned char Erase_PAGE_Flash1();
unsigned char ENABLE_Flash_Write1();

#define SETUART_ENABLE()	{ _uarten1 = 1;_rxen1 = 1;_txen1 = 1;_ur1f = 0;_txif1 = 0; _ur1e = 1; _emi = 1;}
#define SETUART_DISABLE()	{ _uarten1 = 0;_rxen1 = 0;_txen1 = 0;}
#define SET_UART_Format_D8_P0_S1()			{ _u1cr1 = 0x00; }// 傳輸8bit = (8bit-Data  None-Parity  None-Add)1bit-Stop

#define SETUART_WAKEUP_ENABLE()					{ _wake1  = 1;}
#define SETUART_WAKEUP_DISABLE()				{ _wake1  = 0;}
#define SETUART_ADDRESS_ENABLE()				{ _adden1 = 1;}
#define SETUART_ADDRESS_DISABLE()				{ _adden1 = 0;}
#define SETUART_RECEIVER_IE_ENABLE()			{ _rie1   = 1;} // OERR(溢出)/RXIF(有有效數據)置位時可置中斷標誌位
#define SETUART_RECEIVER_IE_DISABLE()			{ _rie1   = 0;}
#define SETUART_TRANSMITTER_IE_ENABLE()		    { _tiie1 = 1;} // TIDLE(無數據傳輸)置位，可置中斷標誌位
#define SETUART_TRANSMITTER_IE_DISABLE()		{ _tiie1 = 0;}
#define SETUART_TRANSMITTER_EMPTY_ENABLE()		{ _teie1 = 1;} // TXIF(數據已加載到移位暫存器，TXR為空)置位時，可置中斷標誌位
#define SETUART_TRANSMITTER_EMPTY_DISABLE()	    { _teie1 = 0;}

//#define _HIRC_8M_
#define _HIRC_4M_
//#define SETUART_PIN_PD4PD5() { _pds1 = 0x05; }
#define SETUART_PIN_PC4PC5() { _pcs1 = 0x0a; }

#ifdef _HIRC_4M_
    #define SETUART_BAUTRATE_300()			{ _brgh1 = 0; _brg1 = 207;}
    #define SETUART_BAUTRATE_1200()			{ _brgh1 = 1; _brg1 = 207;}
    #define SETUART_BAUTRATE_2400()			{ _brgh1 = 1; _brg1 = 103;}
    #define SETUART_BAUTRATE_4800()			{ _brgh1 = 1; _brg1 =  51;}
    #define SETUART_BAUTRATE_9600()			{ _brgh1 = 1; _brg1 =  25;}
    #define SETUART_BAUTRATE_19200()		{ _brgh1 = 1; _brg1 =  12;}
    #define SETUART_BAUTRATE_250000()		{ _brgh1 = 1; _brg1 =   0;}
#endif
#ifdef _HIRC_8M_
    #define SETUART_BAUTRATE_1200()			{ _brgh1 = 0; _brg1 = 103;}
    #define SETUART_BAUTRATE_2400()			{ _brgh1 = 1; _brg1 = 207;}
    #define SETUART_BAUTRATE_4800()			{ _brgh1 = 1; _brg1 = 103;}
    #define SETUART_BAUTRATE_9600()			{ _brgh1 = 1; _brg1 =  51;}
    #define SETUART_BAUTRATE_19200()		{ _brgh1 = 1; _brg1 =  25;}
    #define SETUART_BAUTRATE_38400()		{ _brgh1 = 1; _brg1 =  12;}
    #define SETUART_BAUTRATE_250000()		{ _brgh1 = 1; _brg1 =   1;}
#endif
#ifdef _HIRC_12M_
    #define SETUART_BAUTRATE_1200()			{ _brgh1 = 0; _brg1 = 155;}
    #define SETUART_BAUTRATE_2400()			{ _brgh1 = 0; _brg1 =  77;}
    #define SETUART_BAUTRATE_4800()			{ _brgh1 = 1; _brg1 = 155;}
    #define SETUART_BAUTRATE_9600()			{ _brgh1 = 1; _brg1 =  77;}
    #define SETUART_BAUTRATE_19200()		{ _brgh1 = 1; _brg1 =  38;}
    #define SETUART_BAUTRATE_57600()		{ _brgh1 = 1; _brg1 =  12;}
    #define SETUART_BAUTRATE_250000()		{ _brgh1 = 1; _brg1 =   2;}
#endif

/////********************************************************************/
//////UART_InterRup
//// reg_acc(ram) : ram  should be the same to IAP_bootloader setting!!!!
//// isr_at(addr) : addr should be the same to IAP_bootloader setting!!!!
/////********************************************************************/
//__attribute__((interrupt(0x3c),reg_acc(0x8e),isr_at(AP_Start_Address+0x3c))) 
//void ISR_UART_Routine()
//{
// // if(regUif==1)  //2018/12/27
// // {
//	if (regUsr & 0x04)          //receive data
//	{ 
//		CH[NUM]=regTxRx;
//
//		if ( CH[NUM]=='\r' )  //receive end
//		{ 
//			if(NUM==8)
//			{
//			   if (CH[0] == 0x05)//Head==0x05 
//			   {  	 
//			    	Command=CH[1];
//				    ReceiveFlag=1;  
//			   }  
//			}
//		}		 
//		NUM += 1;	 
//	    if(NUM>= 9) 
//	    	NUM=0;			
//    }
// // }	
//    regUif = 0; 
//
//}
//
/////********************************************/
//////AP Mainloop318
/////********************************************/
//__attribute__((at(AP_Main_Address)))  
//void main_AP()
//{
//	_wdtc=0xa8;	
//	GCC_CLRWDT();  // clear PDF & TO
//	//Clear_RAM();	
//	/************Fsys****************/
//	regSmod=0x01;   // HIRC : HXT
//	while(!regHto);
//	UART_init();
//	_pbc3=0;
//	ReceiveFlag=0;//2018/12/27
//	NUM=0;
//	while(1)
//	{   
//		GCC_CLRWDT(); //18/12/18
//		UART_COMMAND_PROCESS();
//		//	User_PROCESS();
//		_pb3=0;
//		_nop();
//		_nop();
//		_pb3=1;
//		_nop();
//		_nop();
//		_pb3=0;
//		_nop();
//		_nop();
//		_pb3=1;
//	}
//}
/*************************************/
//
/************************************/
// void Clear_RAM () 
// {
// 	for (_mp1h=4; _mp1h !=0xff ; _mp1h--)          //bank 4,3,2,0
// 	{
// 		if (_mp1h==1)                               //bank 1 LCD
// 		{
// 			for( _mp1l=0x80 ; _mp1l<0xA8 ; _mp1l++ )
// 				__iar1 =0x00;
// 		}	                        
// 		else
// 		{
// 			for( _mp1l=0x80 ; _mp1l!=0xff ; _mp1l++ )
// 				__iar1 =0x00;         
// 			__iar1 = 0x00;	                
// 		}                        
// 	}        
// 	_mp1h=00;
// } 

//
///******************************************/
////UART_init 
//// 1. interrupt receive data
///******************************************/
void UART_init()
{
	/**************UART_SET**************/
//	regUcr1 = 0x80;   //8bit , UART ENABLE
//	regBrg = 63;       //64; N=63; 9.8304/(64*16) =9600
//	regUcr2 = 0x20;    //High speed baud rate 
//	_nop();
//	regUcr2 |= 0xc0;   //TXEN ; RXEN	
//
//	regUcr2 |= 0x04;   //TERE ; RIE	
//	regUie = 1;
//	regUif = 0;
//	_mf1e = 1;
//	_mf1f = 0;	
//	_emi = 1;
		SETUART_PIN_PC4PC5(); 
	// 數據傳輸格式設定
	SET_UART_Format_D8_P0_S1();
// 波特率設定
	SETUART_BAUTRATE_19200();
	SETUART_ADDRESS_DISABLE();
	SETUART_RECEIVER_IE_ENABLE();
	SETUART_TRANSMITTER_IE_ENABLE();
	SETUART_TRANSMITTER_EMPTY_ENABLE();
	SETUART_ENABLE();
}

///************************************/
////
///************************************/
//void UART_COMMAND_PROCESS()
//{
//	unsigned char ACK_BUF[6] = {0};
//	unsigned char k, temp;
//	if ( ReceiveFlag == 1	)
//	{ 
//		ACK_BUF[0]=0x02; 
//		ACK_BUF[5]=0x0d;
//		if( Command == 'r')   // erase signer and reset
//		{
//			//	Erase_PAGE_Flash1(0x1FE0);   //last page 
//			ACK_BUF[1] = ACK_BUF[4] = 'O';// return ack
//			
//			if (!Erase_PAGE_Flash1()) {
//				ACK_BUF[1] = ACK_BUF[4] = 'F';
//			}                             
//
//			regUie=0; _mf1e=0; _emi=0;
//			for(k=0; k<6; k++)
//			{
//				temp = regTxRx;
//				regTxRx = ACK_BUF[k];
//				while(!((regUsr & 0x03)==0x03)){GCC_CLRWDT();} //18/12/18
//			}
//
//			regfcl=RESET_CODE;	               //reset jmp to 000h
//			while(1);                  //wait reset 
//		}
//		else if (Command == 'i')   // 
//		{
//			ACK_BUF[1] = ACK_BUF[4] = '0';// return ack 
//
//			regUie=0; _mf1e=0; _emi=0;
//			for(k=0; k<6; k++)
//			{
//				temp = regTxRx;
//				regTxRx = ACK_BUF[k];
//				while (!((regUsr & 0x03)==0x03)){GCC_CLRWDT();} //18/12/18
//			}
//			regUie=1; _mf1e=1; _emi=1;
//		}
//		Command = 0; 
//		ReceiveFlag = 0;	
//	}
//}

///*******************************/
////Flash ERASE PAGE
///*******************************/
unsigned char Erase_PAGE_Flash1()
{
	unsigned char Flag_OK = 1;
	if (!ENABLE_Flash_Write1())
		Flag_OK &= 0x0;

	_farh = 0xbf;
	_farl = 0x80;

	regfc0 &= 0x8f;
	regfc0 |= 0x10;          //erase mode
	_fwt = 1;
	while (_fwt){GCC_CLRWDT();} //18/12/18
	_cfwen = 0;

	return Flag_OK;	

}
///*******************************/
///Flash  write enable
///return  ture  or  false
///*******************************/
unsigned char ENABLE_Flash_Write1()
{
	unsigned char Flag_OK=1;	

	regfc0 &= 0x8f;
	regfc0 |= 0x60;

	regfc0 |= 0x08;
	_fd1l = 0x00;
	_fd1h = 0x04;
	_fd2l = 0x0d;
	_fd2h = 0x09;	
	_fd3l = 0xc3;
	_fd3h = 0x40;
	//while(_fc0&0x08);   //FWPEN
	while (regbit_fwpen){GCC_CLRWDT();} //18/12/18
	//if(!(_fc0 & 0x80))
	if (!_cfwen)
		Flag_OK=0x0;

	return Flag_OK;
}
#endif


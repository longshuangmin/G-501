//#include "BH67F2470.h"
//#include "flash.h"
//#include "eeprom.h"
//#include "variable.h"
//#include "flag.h"
//#include "const.h"
#include  "typedef.h"
#include  "AFEPower.h"
//#include  "iap.h"
//#include "flash.h"
//#include  "AFESineWave.h"

////--- IO define
//--- IO define
#define P_S_KEY			_pa5	//…œº¸
#define P_S_KEY_DOWN		_pb3	//œ¬º¸
#define P_M_KEY			_pa6	//ƒ£ Ωº¸
#define P_GSM_PWR		_pb2
//#define P_GSM_KRY		_pb3	//œ¬º¸
#define P_BAT_CHRR		_pc0
//#define P_BAT_STDBY		_pc5
#define P_LED			_pd6
//#define P_HDL_SW		_pc0


#define P_StripIn		_pa4
#define P_StripIn_C		_pac4
#define P_StripIn_PU	_papu4

#define P_UA_StripIn	_pa3
#define P_UA_StripIn_C	_pac3
#define P_UA_StripIn_PU	_papu3

//#define P_CodeCardPwr		_pb0
//#define P_CodeCardPwr_C		_pbc0
//#define P_CodeCardPwr_PU	_pbpu0



//#define P_IOPower	_pb0
//#define P_STRIPC	_pac5
//#define P_STRIPPU	_papu5
////--- 
//#define P_Prom_Present		_pa6
//#define P_Prom_PresentC		_pac6
//#define P_Prom_PresentPU	_papu6
////--- 
//#define P_Uart_Present	_pa7
//#define P_Uart_PresentC	_pac7
//
////--- 
//#define	P_GND1		_pb6
//#define	P_GND1C		_pbc6
//#define	P_TEST_BG	_pb5
//#define	P_TEST_BGC	_pbc5
//#define	P_GND2		_pb0
//#define	P_GND2C		_pbc0

//---

#define P_VoiceBusy		_pb0
#define P_VoiceDat_Buz	_pb1
#define P_VoiceClk		_pc4


//---
#define	SDAC			_pac7
#define	SCLC			_pcc1

#define	SDA				_pa7
#define	SCL				_pc1
//
//
extern const unsigned char 		Month_TABLE1[12];
extern const unsigned char 		Month_TABLE2[12];
extern const unsigned char 		LeapYear_TABLE[22];
extern const unsigned char 		Lcd_Number_Table[16];
//extern const unsigned int 		__attribute__((at(IAPWRSTARTADDRESS))) DebufInfo[IAPWRLENGHT];
//extern const unsigned char 		__attribute__ ((at(C_EEP_SerialNumber))) SerialNumber_Table[128];
extern const unsigned int 		__attribute__ ((at(C_EEP_Significant))) Significant_Table[128];
extern const _code_data   		__attribute__ ((at(C_EEP_glucose_autocode))) glucose_auto_code[3];
extern const _code_data   		__attribute__ ((at(C_EEP_ketone_autocode))) ketone_auto_code[13];

//extern const unsigned char 		__attribute__ ((at(C_EEP_ParameterTable_Adr))) Parameter_Table[256];
extern const struct tagSTRIP	__attribute__ ((at(C_EEP_ParameterTable_Adr))) memStrip ;	// Teddy
extern const unsigned int 		__attribute__ ((at(C_FlashDataOffset))) Exampledata0[membye];
//
//
//
//--- TASK funciton name used
#define	 C_StandByMode          0x00
#define	 C_NormalMode           0x01
#define	 C_RTCModeSettingMode   0x02
#define	 C_OffMode              0x03
#define	 C_MemoryMode           0x04
//#define	 C_AVGMode              0x05
#define	 C_PCLINKMode           0x06
#define	 C_TestingMode          0x07
#define	 C_CodeCardMode         0x08
#define	 C_PwrOnMode			0x09
#define	 C_AlarmMode			0x0A
#define	 C_ChargerMode			0x0B
//#define	 C_SetRangeMode			0x0B

//--- RTC funciton name used = M_RTC_Task
#define	 C_Set_the_DisplayAllOn     0
#define	 C_Set_the_Year             1
#define	 C_Set_the_Month            2
#define	 C_Set_the_Day              3
#define	 C_Set_the_Hour             4
#define	 C_Set_the_Minute           5
//#define	 C_Set_the_DateFormat		6
//#define	 C_Set_the_TimeFormat       7
#define	 C_set_the_Alarm			8
#define	 C_Set_the_DeleteMemory		9
#define	 C_Set_the_Unit		 		10
#define	 C_Set_the_Error		 	11
#define	 C_Set_out		 	12

//
//--- UART_Function_Initial used
#define	 C_BaudRate4800		51
#define	 C_BaudRate9600     25
#define	 C_BaudRate19200    12
//#define	 C_BaudRate115200   1




#define	C_DeviceAddr		0xa0	
//
////--- description ----
//// 2/4096 = 0.00048828125V for adc 1 step
//
////--- ÊØ´ÂÖã/ÂàÜÂçáÔºàmg/dlÔºâË®àÁÆ?----
//#define	 C_Excitation_Voltage	510     // 0.250V/0.00048828125V=512
//#define	 C_Real_Voltage	        24900000  //0.400V
//#define	 C_AMP_resistor			62000000  //62KÈõªÈòª
//
////--- Trigger 1uA Adc count
////0.4/1uA=400K
////((62/400)+1)*0.4=0.462/2=0.231*4096=946.176
//#define	C_TriggerCurrent	946
//
//
//#define C_McuVersion		100
//#define C_MeterPartNumber	1004
//
//#define C_GMDataSaveIndex	500
//
//#define C_DeviceAddr		0xa0

#define SYS_CLOCK_FREQ		 4000000

#define M_PI  		3.14159265358979
#define M_PI_2      1.57079632679489

#define	Signature_Address		  0xbf80

//--- adc read mode
#define single 1
#define continuous 0

//************** RAM in BANK4 ******************//
//--- UART Receiver data FIFO
//static volatile unsigned char M_UART_RxFIFO[32] __attribute__ ((at(0x4A0)));


////--- interrupt function
//void __attribute((interrupt(0x10))) _Multi_funinterrupt0(void);
//void __attribute((interrupt(0x20))) _TimeBase0_funinterrupt(void);
//void __attribute((interrupt(0x2c))) _Usim_funinterrupt(void);

//--- initial function
void Initial_SysClock(void);
void delay (volatile unsigned char n);
void delay_ms (volatile unsigned int n);
void Initial_Sys(void);
void Initial_SysLcd(void);
void Initial_SysStm(void);
void Initial_SysTimebase(void);
void Initial_SysInt(void);
void Initial_SysLvd(void);
void Initial_SysLvd(void);
void Initial_SysWdt(void);
void Initial_SysGpio(void);
void Initial_SysAdc (void);
void Load_RtcTime_Vaule(void);
void Save_RtcTime(void);

//void Initial_Uart(void);
void fun_UART0PowerOnInit(void);
void fun_UART1PowerOnInit(void);
//void Initnal_OPA1_Gpio (unsigned char En);
//void Initnal_OPA2_Gpio (unsigned char En);
void Initnal_StmCmp_Lirc_16K (void);
void Initnal_StmCmp_Hirc_8K (void);
unsigned int get_CalCurrentToADC( unsigned int uACurr );
void Load_StripMeas_Vaule(void);
void SystemRAM_clear (void);
//void Load_Default_Vaule(void);
//void Load_Eeprom_Vaule(void);
//void Load_Eeprom_AlarmVaule(void);
//
////--- dac function
void fun_DACVREFInit(enum PowerOnOff_t PowerOnoff);
//void Dacvref_Off(void);
void fun_DACnInit(unsigned char DACn , enum DACnOuput_t PowerOnOff);
//
////--- opa function
void fun_CalOPAOffset();
void fun_CalOPA1Offset(void);
void fun_CalOPA2Offset(void);
void fun_CalOPA3Offset(void);
//
//--- adc function
void InitADC_Op1n1_Op1s1 (void);
void InitADC_Op1n2_Op1s2 (void);
void InitADC_Op1n1_Avss (void);
void InitADC_Op1n2_Avss (void);
void InitADC_Op2n_Op2o (void);
void InitADC_Op2n_Avss (void);

unsigned int Measurement_Daco (void);
unsigned int Measurement_Temp (void);
unsigned int Measurement_Battery (void);
unsigned int Measurement_Op1n1_VG0 (void);
unsigned int Measurement_Op1n2_VG0 (void);
unsigned int Measurement_Op1n1_Op1s1 (void);
unsigned int Measurement_Op1n2_Op1s0 (void);
unsigned int Measurement_Op2n_VG0 (void);
unsigned int Measurement_Op2n_Op2o (void);
signed int Cal_MeasCurr( unsigned int AdcCount);
//double ADCtoCurrent_Convert (signed long AdcCount);
double ADCtoCurrent_Convert (signed long AdcCount,double Res);
unsigned int Current_to_AD_Convert (unsigned int Current,double Res);

void intit_Impedance(void);
double Impedance_Compute(signed int *bimBuf);
double Impedance_Compute1(signed int *bimBuf);
double Theta_Compute(signed int *bimBuf);
//////--- uart function
////void Send_Uart1_1Byte (unsigned char data);
////
//////--- ble
////void Ble_Process(void);
////void Ble_SendRecordData(unsigned char command,unsigned int record);
//
////--- mode
void Normal_Measurement_Mode (void);
//void Data_AVG_Mode (void);
//void MemoryMode (void);
void Setting_Mode (void);
//void Ready_Into_Halt(void);
void OffMoedProcess (void);
void ChargerProcess(void);
//void Error_meassage_process (void);
//void Alarm_Check_Process(void);
//void TestingMode (void);
//void PCLINKMode_Process (void);
//void SYSTEM_RAMInitial (void);
//void SYSTEM_RAMcehck (void);
//void SYSTEM_RAMClear (void);

//--- Lcd function
void Lcd_Display_Tes (void);


//--- Lcd function
//void Lcd_AllOn (void);
//void Lcd_AllOff (void);
//void Lcd1_Display (unsigned char Lcd_buf);
//void Lcd2_Display (unsigned char Lcd_buf);
//void Lcd3_Display (unsigned char Lcd_buf);
//void Lcd4_Display (unsigned char Lcd_buf);
//void Lcd5_Display (unsigned char Lcd_buf);
//void Lcd6_Display (unsigned char Lcd_buf);
//void Lcd7_Display (unsigned char Lcd_buf);
//void Lcd8_Display (unsigned char Lcd_buf);
//void Lcd9_Display (unsigned char Lcd_buf);
//void Lcd10_Display (unsigned char Lcd_buf);
//void Lcd11_Display (unsigned char Lcd_buf);
//
//void Lcd1_2_Display (unsigned char Lcd_buf,unsigned char Lcd_Unit);
//void Lcd34_Display (unsigned char Lcd_buf,unsigned char Lcd_Unit);
//void Lcd56_Display (unsigned char Lcd_buf,unsigned char Lcd_Unit);
//void Lcd78_Display (unsigned char Lcd_buf,unsigned char Lcd_Unit);
//void Lcd234_Display (unsigned int Lcd_buf,unsigned char Lcd_Unit);
//void Lcd1234_Display (unsigned int Lcd_buf,unsigned char Lcd_Unit);
//void Lcd91011_Display (unsigned int Lcd_buf,unsigned char Lcd_Unit);
//void Lcd1_11_DisplayOff (unsigned char Lcd_buf);

//void Lcd_Display_Fln (void);
void Lcd_Display_dash (void);
void Lcd_Display_Hi (void);
void Lcd_Display_Lo (void);
void Lcd_Display_Ok (void);
void Lcd_Display34_Hi (void);
void Lcd_Display34_Lo (void);
void Lcd_Display_DEL (void);
void Lcd_GmRangeCheck(void);
void Lcd_Display_OFF (void);
void Lcd_Unit (void);
void Lcd_Bat(unsigned char BatLevel);
void Clr_Bat(void);

void Lcd_ControlOption (void);

void Lcd_Clock_Process (unsigned char Hour,unsigned char Minutes);
void Lcd_Month_Day_Process (unsigned char Month,unsigned char Days);
//void Lcd_Month_Day_Process1 (unsigned char Month,unsigned char Days);

void Lcd_Year_Process (unsigned char Year);
void Lcd_Glucose(signed int data);
void Lcd_ShowHW(unsigned int data);
void Lcd_ShowAvgNum(unsigned int data);
void Lcd_ShowAvgDay(unsigned char data);
void Lcd_ShowC1(unsigned char data);
void Lcd_ShowC2(unsigned char data);
void Lcd_ShowRecordLength(unsigned int data);

//--- Scankey
void ScanKeyProcess (void);

//--- Beep
void BeepReset(void);
void BeepProcess (void);
void Short_beep(void);

//--- Battery
void BatteryCheckProcess (void);
//
//--- IAP
unsigned int Drv_ReadFlashRom(unsigned int RPage_Addr);
unsigned char Drv_WriteFlashRom(unsigned int FlashAddr,unsigned char FlashLength);
unsigned char Drv_Erase_Page(unsigned int EPage_Addr,unsigned char EPage_Length);
unsigned char Drv_Enable_FWEN(void);

unsigned int Flash_Store_Read_Process (unsigned int address);
//unsigned char Flash_Store_Write_Process (unsigned int address,unsigned int data);
//unsigned char Flash_Store_PageErase_Process (unsigned int address);
//unsigned char WritePage_flash (unsigned int address);
void Store_measurement_data (void);
void Significant_Checksum (void);
void Store_SetVauletoFlash (void);

//---- RTC
unsigned long DateToSecond (unsigned char *buf);
void SecondToDate (unsigned long Second,unsigned char *buf);

////---- eeprom
enum STATUS_t Read_EEPROMByte(unsigned char addr, unsigned char *data);
enum STATUS_t Read_EEPROMBuf(unsigned char addr, unsigned char* buf, unsigned char len);
enum STATUS_t Write_EEPROMByte(unsigned char addr, unsigned char WriteData);
enum STATUS_t Write_EEPROMBuf(unsigned char addr, unsigned char * buf, unsigned char len);
enum STATUS_t clear_EEPROMBuf(unsigned char addr, unsigned char len);

void EepromCalibartion_Checksum (void);

//--- sin wave
enum SINEWAVESETRESULT_t fun_SineWaveInit(unsigned char SinWaveFreq);
void Set_HCT_Adc_Channel (unsigned char mode);

void fun_StripModuleAllOpen (void);
void fun_StripModuleAllOpen2 (void);


//--- uart
void fun_UART0PowerOnInit();     // ÂàùÂßãÂå?
void fun_UART1PowerOnInit();
void fun_Uart1StartTx( unsigned char TxLength);
//void fun_Uart0StartTx( unsigned char TxLength);
//unsigned char fun_UART0WriteTxBufStart(char* src, unsigned char len);
unsigned char fun_UART1WriteTxBufStart(unsigned char* src, unsigned char len);
//unsigned char fun_UART0WriteTxBuf(char* src,unsigned char startaddr, unsigned char len);
void fun_UART_SendValue(signed long Value);
void fun_UART_SendfloatValue(signed long tValue);
unsigned char DataCompare (unsigned char *Targetdata,unsigned char *Sourcedata,unsigned char length);
void fun_UART_ReceiveProcess(void);

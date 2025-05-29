#ifndef _VARIALLE_
#define _VARIALLE_

#include  "typedef.h"
#define  LED   _pd6



#define  time_12_hour_en 0
#define  UART_TO_PC_EN 0
#define  voice_en  0 //
#define  unit_default 1  //0：mg，  1：mmol
#define  UNIT_ADJUST	0 //1单位可调，0单位不可调
#define  alarm_en	0 //是否有闹铃功能 1：有闹铃，0：没闹铃

#define  NO_TEMPER_CORR 1     // 1-no temperature correction    0-temperature correction
#define ACFG_OSC_EN 1     // 1-external clock    0-internal clock
//#define	 G777G_TEST

#if ACFG_OSC_EN==0
#define TestMode 1
#else
#define TestMode 0
#endif

typedef enum
{
 // e_PowerOn = 0,
  e_Full_screen=0,
  e_Init,
  e_Strip_type,
  e_check_Dac1o,
  e_check_used,  
  e_check_temp,    
  
  e_Start_detection,  //门槛??
  e_ckfull_blood,
  e_Impedance_measurement,
  e_DC_Silence,  
  e_DC_check,
  e_calculation,  
  e_gsm_powen_on,
  e_start_gsm,
  e_cpin,
  e_gsm_start,
  e_gsm_send,
  e_gsm_out,
  e_gsm_out2,
  e_ShowGlucoseResult,
  e_idle,
  e_Factory_mode, 
  e_Errmode,  
  e_Errmode2,    
  e_Exit_mode,
  
  
  
//  e_WorkSleep,
// 
//  e_Exitmode,
//  e_ShowErr,
//  e_setmode,
//
//  e_err,
//
//  e_CodeInserted,
//
//  e_set, 
  // e_Countdown,
//          
//  e_ShowImpedanceResult,
//  e_savemem, 
  
} E_MAIN_Glucose_STATUS;
//--- main
extern unsigned char 			M_Task,M_TaskBuf0,M_TaskBuf1,M_Error_Task;
extern unsigned char  			M_Halt_Cnt,M_ErrorCount;;
extern unsigned int				M_RTC_display;
extern volatile unsigned int   			M_No_Active_Cnt,M_GM_data_Record,M_GM_Record_current,M_GM_SendRecord,M_GM_data_Record_buf;
extern signed int 				M_GM_data;
extern unsigned char			M_Unit;
extern unsigned char  			M_Cbuf0,M_Cbuf1;
extern unsigned int   			M_Ibuf0,M_Ibuf1,M_Ibuf2;
extern unsigned long  			M_Lbuf0;
extern unsigned char 			M_FlashPage;
extern unsigned int				M_WaitCount,M_LogCount,M_Log,M_LogCount_Switch;
extern unsigned char 			M_ACTurnOn,M_DCTurnOff,M_DCTurnOn;

//--- strip
extern unsigned char 			M_Strip_Type;

//--- key
extern unsigned int 			M_MKey_Hold_CNT,M_SKey_Hold_CNT;
extern unsigned int				M_MSKey_Hold_CNT;
extern unsigned char			M_Inc_Cnt,M_Hold_cnt;
extern unsigned char			M_KeyDebounce;

//--- int
extern volatile unsigned char 	M_Main_cnt,M_Main_Cal_Cnt,M_Main_Cal,M_Main_Cnt_6s;
//extern volatile unsigned int	M_Main_cnt_1s,M_Cal_Lirc_Cnt;

//--- daco
extern unsigned char			M_Daco1L,M_Daco1H,M_Daco2L,M_Daco2H;
#ifdef G777G_TEST
extern unsigned int 			M_Current_use_log,M_Current_start_log,M_Current_full_log;

#endif

//--- RTC
extern volatile unsigned char  	M_Second_buf,M_DaysLimit;
extern volatile unsigned char	M_Second,M_Minutes,M_Hour,M_Days,M_Month,M_Year;

//--- system
extern unsigned int				M_GM_Range_Hi,M_GM_Range_Low;

//--- Beep
extern unsigned int 			M_Beep_Cnt;
extern unsigned char 			M_BeepMode;

//--- Uart
extern volatile unsigned char 	M_UARTRxTimeOut,M_UART_RxIndex,M_UART_TxLength,M_UART_TxIndex,M_Length,M_UartInsertCnt;
extern unsigned char 			M_UART_TxIndex_Old,M_UART_Tx_ErrorCnt;

//---Adc
extern volatile 				ADCSource_t 	SDKADCSourceData;
//--- Measurement
extern unsigned int  			M_Excitation_Voltage;
extern signed char				M_Excitation_Offset,M_OPA_Offset;
extern unsigned int 			M_Temperature,M_Current,M_CurrentX10,M_BackCurrent;
extern unsigned int				M_Avg_16bit_result;
extern unsigned int				M_TriggerCurrent_Adc ;
extern unsigned int				M_StripUsedCurrent_Adc ;
extern unsigned int				M_DropCurrent_Adc ;

//--- data avg
extern unsigned long 			M_7days_datasum,M_14days_datasum,M_28days_datasum,M_30days_datasum,M_60days_datasum,M_90days_datasum;
extern unsigned int 			M_7daysNumber,M_14daysNumber,M_28daysNumber,M_30daysNumber,M_60daysNumber,M_90daysNumber;

//--- Alarm
extern volatile unsigned char 	M_Alarm1_HR,M_Alarm1_MIN;
extern volatile unsigned char 	M_Alarm2_HR,M_Alarm2_MIN;
extern volatile unsigned char 	M_Alarm3_HR,M_Alarm3_MIN;
extern volatile unsigned char 	M_Alarm4_HR,M_Alarm4_MIN;

//--- Battery
extern unsigned int				M_BAT_Energy;

//--- sin
extern unsigned char 			M_SinFreq;
extern unsigned char			M_SinGain;

//---bootload
extern unsigned char 			ReceiveFlag,Command;

//--- AC
extern double 					M_Impedance,M_Theta;
extern double					M_ImpedanceBuf[2];
extern signed int 				M_HCT_ADCData[4];

//--- IAP
extern unsigned int 			M_PageAddress;
extern unsigned char			M_PageIndex;

extern unsigned char			FlashTimeFlag;
extern unsigned char 			FlashTimeCon;
//--- calbration
//extern volatile unsigned int	M_Cal_Licr_ObjCnt,M_Cal_Hicr_ObjCnt;
//extern volatile signed char		M_Cal_Licr_ObjVaule,M_Cal_Hicr_ObjVaule;
extern unsigned int				M_Cal_10K_Adc,M_Cal_100K_Adc;

//--- Sinwave Ram used
static  volatile  unsigned int SinDataRam[32] __attribute__ ((at(0x300)));
//--- Lcd RAM used
//static volatile unsigned char M_LCD_RAM[32] __attribute__ ((at(0x400)));
static volatile unsigned char M_LCD_RAM[20] __attribute__ ((at(0x400)));
//--- FlashBuf used
static volatile unsigned int  M_FlashBuf0[64] __attribute__ ((at(0x780)));

static volatile unsigned int  M_FlashBuf1[64] __attribute__ ((at(0x680)));
//--- UART_RxFIFO used
static volatile unsigned char M_UART_RxFIFO[128] __attribute__ ((at(0x1e80)));
static volatile unsigned char M_UART_TxFIFO[128] __attribute__ ((at(0x1f80)));

////--- OP1 Measurement used
//static volatile unsigned int M_CurrentFIFO1[51] __attribute__ ((at(0x680)));
////--- OP1 Measurement used
//static volatile unsigned int M_CurrentFIFO0[30] __attribute__ ((at(0x780)));
static volatile  signed int  M_Impedance_data[40] __attribute__ ((at(0x880)));

static volatile  double M_Impedance_buf[10] __attribute__ ((at(0x980)));

static volatile unsigned char mi __attribute__ ((at(0xa80)));
static volatile  signed int  work_time __attribute__ ((at(0xa82)));
static volatile  signed int  work_time6S __attribute__ ((at(0xa84)));
static volatile  signed int  old_work_time __attribute__ ((at(0xa86)));
static volatile  signed int  work_time_buf[10] __attribute__ ((at(0xa88)));


static volatile  signed int DC_data_buf[64]  __attribute__ ((at(0xb80)));//存储ad采样时的??
static volatile  BGM_code mcode_data  __attribute__ ((at(0xc80)));
static volatile  _sys_data sys_data  __attribute__ ((at(0xd80)));
//------------------------------------------------------------------------------
static volatile  unsigned char  memkey  __attribute__ ((at(0xe80)));
static volatile  unsigned int   memkey_time  __attribute__ ((at(0xe81)));

static volatile  unsigned char  setkey  __attribute__ ((at(0xe83)));
static volatile  unsigned int   setkey_time  __attribute__ ((at(0xe84)));
static volatile  unsigned char  uar_en  __attribute__ ((at(0xe86)));
static volatile  unsigned char  test_mode  __attribute__ ((at(0xe87)));
static volatile  unsigned char  wait_sec   __attribute__ ((at(0xe88)));
static volatile  unsigned char  batlevel  __attribute__ ((at(0xe89)));

//------------------------------------------------------------------------------
static volatile  unsigned char  m_pvref		__attribute__ ((at(0xe90)));
static volatile  unsigned int   m_afeda1	__attribute__ ((at(0xe91)));
static volatile  unsigned char  imp		__attribute__ ((at(0xe93)));
static volatile  signed int		avg_ad  __attribute__ ((at(0xe94)));
static volatile  signed int		avg_ad2  __attribute__ ((at(0xe96)));
static volatile  signed char    back  __attribute__ ((at(0xe98)));
static volatile  _biao_ding 	Calibration  	__attribute__ ((at(0xea0)));

static volatile  _new_sys_data  new_sys_data __attribute__ ((at(0xfa0)));

//static volatile  unsigned int   m_afeda1h 	__attribute__ ((at(0xe922)));

//-------------------------GSM-----------------------------------------------------
static volatile char CIMI[15]	__attribute__((at(0xf80)));		//15 byte
static volatile char GSM_Signal	__attribute__((at(0xf8f)));		//1 byte
static volatile char IMEI[15]	__attribute__((at(0xf90)));		//15 byte
static volatile signed int gsm_loop	__attribute__((at(0xfA0)));		//15 byte
static volatile unsigned char server_data[10]	__attribute__((at(0xfA2)));		//15 byte
static volatile unsigned char data[10]	__attribute__((at(0xfAC)));	
static volatile unsigned char k	__attribute__((at(0xfB6)));	
static volatile unsigned char key_lock  __attribute__((at(0xfB7)));	
static volatile unsigned char index	__attribute__((at(0xfB8)));	
static volatile unsigned char mymax	__attribute__((at(0xfB9)));	
static volatile unsigned char meals	__attribute__((at(0xfBA)));	
//------------------------------------------------------------------------------
static volatile _gsm_data unsend_data[11] 	__attribute__((at(0x1080)));
//------------------------------------------------------------------------------
static volatile unsigned char GSM_data[128] 	__attribute__((at(0x1180)));
//------------------------------------------------------------------------------
static volatile unsigned char m			__attribute__((at(0x1280)));
static volatile unsigned char send_ok	__attribute__((at(0x1281)));

static volatile double  untemp_glucose		__attribute__((at(0x1282)));
//static volatile double  untemp_glucose		__attribute__((at(0x12FD)));
static volatile unsigned int lcd_scan_index	__attribute__((at(0x1286)));	
static volatile unsigned int LcdMappingSize	__attribute__((at(0x1288)));	
static volatile unsigned char Start_Detection_flag	__attribute__((at(0x128A)));	

static volatile unsigned char TIME[12]	__attribute__((at(0x12F0)));
static volatile unsigned int auto_code		__attribute__((at(0x12FC)));


//------------------------------------------------------------------------------
static volatile TFBLOOD_Package  code_buf __attribute__((at(0x1380)));
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
static volatile double testf __attribute__((at(0x1480)));

static volatile  unsigned char  setkeydown  __attribute__ ((at(0x1484)));
static volatile  unsigned int   setkeydown_time  __attribute__ ((at(0x1485)));
static volatile  unsigned int   time_conut  __attribute__ ((at(0x1487)));
static volatile char set_temp_25 __attribute__((at(0x1489)));
static volatile char twokey __attribute__((at(0x148b)));
static volatile int  twokey_time __attribute__((at(0x148c)));

static volatile _code_data alg_para __attribute__((at(0x148e)));
//------------------------------------------------------------------------------
#endif

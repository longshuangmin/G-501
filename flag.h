
#define	bool	_Bool

//typedef	unsigned long	ULONG;
//typedef	signed long	    SLONG;

typedef	unsigned int	uint16_t;
typedef	signed int		int16_t;

//typedef	unsigned short	USHORT;
//typedef	signed short	SHORT;

typedef	unsigned char	uint8_t;
typedef	signed char		int8_t;

// Indie File Defined
typedef	unsigned long	ULONG;
typedef	signed long	    SLONG;

typedef	unsigned int	UINT;
typedef	signed int		SINT;

typedef	unsigned short	USHORT;
typedef	signed short	SHORT;

typedef	unsigned char	UCHAR;
typedef	signed char		SCHAR;

#define BOOLEAN     bool
#define BOOLEAN     bool
#define INT8U       uint8_t
#define INT8S       int8_t
#define INT16U      uint16_t
#define INT16S      int16_t
#define INT32U      uint32_t
#define INT32S      int32_t
#define FP32
#define FP64
#define WORD        uint16_t

#define false         		(BOOLEAN)0
#define true         		(BOOLEAN)1

#define DOWN         		(BOOLEAN)0
#define UP          		(BOOLEAN)1
                    		
#define OFF         		(BOOLEAN)0
#define ON          		(BOOLEAN)1
                    		
#define LOW         		(BOOLEAN)0
#define HIGH        		(BOOLEAN)1
                    		
//#define DISABLE     		(BOOLEAN)0
//#define ENABLE      		(BOOLEAN)1
                    		
#define PortDir_In  		(BOOLEAN)0
#define PortDir_Out 		(BOOLEAN)1
                    		
#define LEFT        		(BOOLEAN)0
#define RIGHT       		(BOOLEAN)1
                    		
#define Temp_oC				(BOOLEAN)0
#define Temp_oF				(BOOLEAN)1

#define TimeFormat_AMPM     (BOOLEAN)0
#define TimeFormat_2400     (BOOLEAN)1

#define GMunit_mg_dL    	(BOOLEAN)0
#define GMunit_mmol_L   	(BOOLEAN)1

typedef struct {
volatile unsigned  bit0 : 1;
volatile unsigned  bit1 : 1;
volatile unsigned  bit2 : 1;
volatile unsigned  bit3 : 1;
volatile unsigned  bit4 : 1;
volatile unsigned  bit5 : 1;
volatile unsigned  bit6 : 1;
volatile unsigned  bit7 : 1;
}bit_type;

extern bit_type Flag1;
#define F_MainTimerOut   	Flag1.bit0
#define F_500ms_RTC      	Flag1.bit1
#define F_UartDataComing	Flag1.bit2
#define F_UartRxBegin    	Flag1.bit3
#define F_ControlOption	   	Flag1.bit4
#define F_Low_battery_Act  	Flag1.bit5
#define F_Into_FactoryMode	Flag1.bit6
#define F_500ms_LCD    		Flag1.bit7

extern bit_type Flag2;
#define F_Battery_checked   Flag2.bit0
#define F_LcdUpdate			Flag2.bit1
#define F_KeyHold_IntoHalt  Flag2.bit2 
#define F_read_eeprom       Flag2.bit3
#define F_Unit				Flag2.bit4		//mg/dL =0 , mmol/L=1
//#define F_Key_wakeup	    Flag2.bit5			//MM-DD =0 , DD-MM =1;
#define F_LcdUpdateBuf		Flag2.bit6
#define F_read_eeprom_Up_Down   	Flag2.bit7

//---scankey
extern bit_type Flag3;
//#define F_M_KEY_HOLD		Flag3.bit0
//#define F_M_KEY_TOGGLE		Flag3.bit1
//#define F_MKeyHoldCheck   	Flag3.bit2
//#define F_S_KEY_HOLD		Flag3.bit3
//#define F_S_KEY_TOGGLE		Flag3.bit4
//#define F_SKeyHoldCheck  	Flag3.bit5
//#define F_Strip_HOLD		Flag3.bit6
//#define F_Strip_TOGGLE		Flag3.bit7

extern bit_type Flag6;
#define F_Alarm1_Enable		Flag6.bit0
#define F_Alarm1_TimeUp_ACT	Flag6.bit1
#define F_Alarm2_Enable		Flag6.bit2
#define F_Alarm2_TimeUp_ACT	Flag6.bit3
#define F_Alarm3_Enable		Flag6.bit4
#define F_Alarm3_TimeUp_ACT	Flag6.bit5
#define F_Alarm4_Enable		Flag6.bit6
#define F_Alarm4_TimeUp_ACT	Flag6.bit7

extern bit_type Flag7;
#define F_ReadAdc_Start   		Flag7.bit0
#define F_MeasureStart			Flag7.bit1
#define F_MeasureFullBlood		Flag7.bit2
#define F_MeasureAc    			Flag7.bit3
#define F_BatFull	   			Flag7.bit4
//#define F_Qc_KeyTest  			Flag7.bit5
//#define F_StripIndexHold		Flag7.bit6
//#define F_AutoCodeReady    		Flag7.bit7

//---beep
extern bit_type Flag4;
#define F_Beep_Act   		Flag4.bit0
#define F_Beep_Shortx1      Flag4.bit1
#define F_Beep_Shortx2	   	Flag4.bit2
#define F_Beep_Longx1		Flag4.bit3
#define	F_Beep_Alarm		Flag4.bit4
//#define F_AlarmReCkeck		Flag4.bit5
//#define	F_Alarm5min_Start	Flag4.bit6
//#define F_Alarm5min_TimeUp_ACT	Flag4.bit7

//---set
extern bit_type Flag8;
#define F_Set_Transmit   				Flag8.bit0
#define F_Set_No_Tempera_Comp   		Flag8.bit1
#define F_Set_Disp_Yes   				Flag8.bit2
	
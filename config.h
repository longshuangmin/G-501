
#ifndef _CONFIG_H
#define _CONFIG_H

//#define _LXT_
#define _LIRC_
//#define _HIRC_8M_
#define _HIRC_4M_
//#define _HXT_10M_BELOW_

#define _SYS_CLK_8M_

#ifdef _SYS_CLK_4M_
#define GetSystemClock()  4000000UL
#endif

#ifdef _SYS_CLK_8M_
#define GetSystemClock()  8000000UL
#endif

#ifdef _SYS_CLK_12M_
#define GetSystemClock()  12000000UL
#endif

typedef unsigned char uint8_t;
typedef unsigned int  uint16_t;
typedef unsigned long uint32_t;

typedef signed char int8_t;
typedef signed int  int16_t;
typedef signed long int32_t;

typedef enum _BOOL { FALSE = 0, TRUE } BOOL;    /* Undefined size */
typedef enum _BIT { CLEAR = 0, SET } BIT;
typedef enum _STATUS { ERROR = 0, SUCCESS } ErrorStatus;

typedef union
{
	int32_t signVal;
    uint32_t unsignVal;
    uint16_t w[2];
    uint8_t v[4];
    struct
    {
        uint16_t LW;
        uint16_t HW;
    } word;
    struct
    {
        uint8_t LB;
        uint8_t HB;
        uint8_t UB;
        uint8_t MB;
    } byte;

    struct
    {
        uint8_t b0:1;
        uint8_t b1:1;
        uint8_t b2:1;
        uint8_t b3:1;
        uint8_t b4:1;
        uint8_t b5:1;
        uint8_t b6:1;
        uint8_t b7:1;
        uint8_t b8:1;
        uint8_t b9:1;
        uint8_t b10:1;
        uint8_t b11:1;
        uint8_t b12:1;
        uint8_t b13:1;
        uint8_t b14:1;
        uint8_t b15:1;
        uint8_t b16:1;
        uint8_t b17:1;
        uint8_t b18:1;
        uint8_t b19:1;
        uint8_t b20:1;
        uint8_t b21:1;
        uint8_t b22:1;
        uint8_t b23:1;
        uint8_t b24:1;
        uint8_t b25:1;
        uint8_t b26:1;
        uint8_t b27:1;
        uint8_t b28:1;
        uint8_t b29:1;
        uint8_t b30:1;
        uint8_t b31:1;
    } bits;
} DWORD_VAL;



#define NULL  (0)

//#include <math.h>
//#include "BH67F2485.h"
//#include "HPALC.h"
//#include "Drv_Uart.h"
//#include "Drv_AFE_DAC.h"
//#include "Drv_AFE_ADC.h"
//#include "Drv_AFE_OPA.h"
//#include "Drv_AFE_SIN.h"
//#include "Drv_AFE_BIM.h"
//#include "Drv_Timer.h"
//#include "Drv_EEPROM.h"
//#include "Drv_Buff.h"
//#include "Drv_Key.h"
//#include "App_Comm_PC.h"
//#include "App_Work.h"
//#include "flag.h"



#define	START_VECTOR			0x000		// Ö÷³ÌÐò
#define INT0_VECTOR				0x004		// Interrupt 0
#define INT1_VECTOR				0x008		// Interrupt 1
#define ADC_VECTOR				0x00C		// ADC
#define MUFUNCTION0_VECTOR		0x010		// Multi function0 STM0 & PTM0
#define STM0_VECTOR				0x010		// STM0
#define PTM0_VECTOR				0x010		// PTM0
#define MUFUNCTION1_VECTOR		0x014		// Multi function1 PTM1 & PTM2
#define PTM1_VECTOR				0x014		// PTM1
#define PTM2_VECTOR				0x014		// PTM2
#define MUFUNCTION2_VECTOR		0x018		// Multi function2 LVD & EEPROM W
#define OVP_VECTOR				0x01C		// OVP
#define TIMEBASE0_VECTOR		0x020		// timebase0
#define TIMEBASE1_VECTOR		0x024		// timebase1
#define INT2_VECTOR				0x028		// Interrupt 2
#define INT3_VECTOR				0x02C		// Interrupt 3
#define UART0_VECTOR		    0x030		// UART 0
#define SIM_VECTOR				0x034		// SIM SPI & IIC
#define SPI_VECTOR				0x038		// SPI
#define UART1_VECTOR		    0x03C		// UART 1




#endif
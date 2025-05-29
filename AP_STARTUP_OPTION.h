#ifndef  _AP_STARTUP_OPTION_H_
#define  _AP_STARTUP_OPTION_H_

/***************************************/
//AP_Start_Address
//User modify :  0x300--->user define
/***************************************/
#define AP_Start_Address          0x400
#define Interrupt_Vectors_Offset  0x40



#define AP_Main_Address           AP_Start_Address+Interrupt_Vectors_Offset
#define ASM_EQU(varname)          asm("AP_Main_Address EQU (" ___mkstr1(varname) ")")
ASM_EQU(AP_Start_Address+Interrupt_Vectors_Offset);

#endif
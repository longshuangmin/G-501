#include "BH67F2485.h"
#include "AP_STARTUP_OPTION.h"
#include "include.h"

#define  Redirection_Addr    AP_Start_Address

//
extern void main_AP();
void main()
{
	main_AP();
}

/*******************************/
//interrupter  redirection
/******************************/

//*****************************************//
// interrupt Vector 0004  --- > 400H +04H 
//*****************************************//
__attribute__((interrupt(0x04), reg_acc(0x80), redirect_at(0x04+Redirection_Addr)))  
void ISR_0x04_Routine(){} 



//*****************************************//
// interrupt Vector 0008  --- > 400H +08H 
//*****************************************//
__attribute__((interrupt(0x08), reg_acc(0x81), redirect_at(0x08+Redirection_Addr)))  
void ISR_0x08_Routine(){} 



//*****************************************//
// interrupt Vector 000C  --- > 400H +0CH 
//*****************************************//
__attribute__((interrupt(0x0C), reg_acc(0x82), redirect_at(0x0C+Redirection_Addr)))  
void ISR_0x0c_Routine(){} 



//*****************************************//
// interrupt Vector 0010  --- > 400H +10H 
//*****************************************//
__attribute__((interrupt(0x10), reg_acc(0x83), redirect_at(0x10+Redirection_Addr)))  
void ISR_0x10_Routine(){} 


//*****************************************//
// interrupt Vector 0014  --- > 400H +14H 
//*****************************************//
__attribute__((interrupt(0x14), reg_acc(0x84), redirect_at(0x14+Redirection_Addr)))  
void ISR_0x14_Routine(){} 



//*****************************************//
// interrupt Vector 0018  --- > 400H +18H 
//*****************************************//
__attribute__((interrupt(0x18), reg_acc(0x85), redirect_at(0x18+Redirection_Addr)))  
void ISR_0x18_Routine(){} 


//*****************************************//
// interrupt Vector 001C  --- > 400H +1CH 
//*****************************************//
__attribute__((interrupt(0x1C), reg_acc(0x86), redirect_at(0x1C+Redirection_Addr)))  
void ISR_0x1c_Routine(){} 


//*****************************************//
// interrupt Vector 0020  --- > 400H +20H 
//*****************************************//
__attribute__((interrupt(0x20), reg_acc(0x87), redirect_at(0x20+Redirection_Addr)))  
void ISR_0x20_Routine(){} 


//*****************************************//
// interrupt Vector 0024  --- > 400 +24H 
//*****************************************//
__attribute__((interrupt(0x24), reg_acc(0x88), redirect_at(0x24+Redirection_Addr)))  
void ISR_0x24_Routine(){} 


//*****************************************//
// interrupt Vector 0028  --- > 400 +28H 
//*****************************************//
__attribute__((interrupt(0x28), reg_acc(0x89), redirect_at(0x28+Redirection_Addr)))  
void ISR_0x28_Routine(){} 


//*****************************************//
// interrupt Vector 002c  --- > 400 +2cH 
//*****************************************//
__attribute__((interrupt(0x2C), reg_acc(0x8a), redirect_at(0x2C+Redirection_Addr)))  
void ISR_0x2c_Routine(){} 


//*****************************************//
// interrupt Vector 0030  --- > 400 +30H 
//*****************************************//
__attribute__((interrupt(0x30), reg_acc(0x8b), redirect_at(0x30+Redirection_Addr)))  
void ISR_0x30_Routine(){} 



//*****************************************//
// interrupt Vector 0034  --- > 400 +34H 
//*****************************************//
__attribute__((interrupt(0x34), reg_acc(0x8c), redirect_at(0x34+Redirection_Addr)))  
void ISR_0x34_Routine(){}



//*****************************************//
// interrupt Vector 0038  --- > 400 +38H 
//*****************************************//
__attribute__((interrupt(0x38), reg_acc(0x8d), redirect_at(0x38+Redirection_Addr)))  
void ISR_0x38_Routine(){} 



//*****************************************//
// interrupt Vector 003C  --- > 400 +3CH 
//*****************************************//
__attribute__((interrupt(0x3C), reg_acc(0x8e), redirect_at(0x3C+Redirection_Addr)))  
void ISR_0x3C_Routine(){}


#include "include.h"
//#define BatLv0 (((3.7/2)/2)*8388608) /256
//#define BatLv1 (((3.8/2)/2)*8388608) /256
//#define BatLv2 (((4.0/2)/2)*8388608) /256

//#define BatLv0 30310
//#define BatLv1 31129
//#define BatLv2 32345//=3.9v
#ifdef PRO_TEST
#define LowBatter 0 //show low power symbol
#define PoweroffBatter 0 //power off when measurement
#else
#define LowBatter 18980 //2.7(实际2.67) 显示低电符号
#define PoweroffBatter 18200 //2.57(实际2.57) 显示E-B
#endif
//--------------------------------------------------------------------------
void BatteryCheckProcess (void)
{

	if((M_Task !=C_StandByMode) && (M_Task !=C_OffMode) && (M_Task !=C_PwrOnMode))
    {
	    if(F_Battery_checked ==0)
		{
		
			//fun_UART0PowerOnInit();
			F_Battery_checked =1;
			F_Low_battery_Act =0;
			M_BAT_Energy = Measurement_Battery();    // 10K//10K  ref for 2.0
			//M_BAT_Energy = 32768;
			//print_str("ad_value:");
			//print_long(M_BAT_Energy);
			//print_str("\r\n");
		}
    }	
	
	if((M_Task !=C_StandByMode) && (M_Task !=C_OffMode) && (M_Task !=C_ChargerMode) && (M_Task !=C_PwrOnMode))
    {
		//--- 3V/2 = 1.5V
		//--- (1.5/2)* 8388608 = 6291456 = 00600000h
		//--- 00600000h >> 8 = 6000h = 24576
		
		//--- 2.4V/2 = 1.25V
		//--- (1.25/2)* 8388608 = 5242542 = 004FFEAEh
		//--- 004FFEAEh >> 8 = 4ffeh = 20478
	
		//--- 2.4V/2 = 1.2V
		//--- (1.2/2)* 8388608 = 5033165 = 004ccccdh
		//--- 004ccccdh >> 8 = 4ccch = 19660  	
    	
    	
		//-- <2.4V => 1.2V =2457 for Low battery
		batlevel =1;
		if(M_BAT_Energy < LowBatter)// Low battery active
		{
			//F_Low_battery_Act =1;       
			batlevel =0;
			if(M_BAT_Energy < PoweroffBatter)
			{
				F_Low_battery_Act =1;		// power off when measure
			}
		}
		
#if (TestMode==1)
		F_Low_battery_Act =0;
#endif

		#if 0
		else
		{
			if(M_TaskBuf0 >=1)
			{
				if(M_BAT_Energy >= BatLv2)
					batlevel =3;
				else if((M_BAT_Energy >= BatLv1) && (M_BAT_Energy < BatLv2))	
					batlevel =2;
				else if((M_BAT_Energy >= BatLv0) && (M_BAT_Energy < BatLv1))	
					batlevel =1;
			}
		}
		#endif
		//--- update bat lcd
		Lcd_Bat(batlevel);
    }
}

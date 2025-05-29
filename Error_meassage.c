#include "include.h"

//--------------------------------------------------------------------------
void Error_meassage_process (void)
{
	if(M_Error_Task !=0)
		Lcd_Display_E_();
		
	switch(M_Error_Task)
	{
		//--- Error meassage ==> srrip used
		case 2:
		{
			//--- display "U"
			M_LCD_RAM[5] = 0x07;
			M_LCD_RAM[6] = 0x05;	
			break;
		}
		
		//--- Error meassage ==> tempertuer Hi&Lo
		case 3:
		case 4:
		{
			//--- display "t"
			M_LCD_RAM[5] = 0x07;
			M_LCD_RAM[6] = 0x02;
			break;
		}
		
		case 5:
		{
			//--- display "b"
			Lcd4_Display(0x0b);
			break;
		}
		
		default:
		{
			break;
		}
	}
	
}
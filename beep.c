#include "include.h"

//--------------------------------------------------------------------------
void BeepReset(void)
{
	_ston =0;
	F_Beep_Shortx1 =0;
	F_Beep_Shortx2 =0;
	F_Beep_Longx1 =0;
	M_Beep_Cnt =0;	
}

void Short_beep(void)
{
	_pbs02 =0;
	_pbs03 =1;
	_ston =0;
	_stmal = 250;
	_stmah = 250>>8;
	_ston =1;
	delay_ms(100);
	_ston =0;
}

void BeepProcess (void)
{	
//	if(	F_Beep_Shortx1)
//	{
//		M_Beep_Cnt++;
//	    if(M_Beep_Cnt == 1)
//			F_Beep_Act =1;
//	   	else if(M_Beep_Cnt >= 10)
//	   	{
//			F_Beep_Act =0;
//			F_Beep_Shortx1 =0;
//			M_Beep_Cnt =0;
//	   	}
//	}
//	else if(F_Beep_Shortx2 ==1)
//	{
//		M_Beep_Cnt++;
//	    if(M_Beep_Cnt == 1)
//			F_Beep_Act =1;
//	   	else if(M_Beep_Cnt == 10)
//			F_Beep_Act =0;
//	    else if(M_Beep_Cnt == 20)
//			F_Beep_Act =1;
//	   	else if(M_Beep_Cnt == 30)
//	   	{
//			F_Beep_Act =0;
//			F_Beep_Shortx2 =0;
//			M_Beep_Cnt =0;
//	   	}
//	}
//	else if(F_Beep_Longx1 ==1)
//	{
//		M_Beep_Cnt++;
//	    if(M_Beep_Cnt == 1)
//			F_Beep_Act =1;
//	   	else if(M_Beep_Cnt >= 30)
//	   	{
//			F_Beep_Act =0;
//			F_Beep_Longx1 =0;
//			M_Beep_Cnt =0;
//	   	}
//	}
	
	if(C_Beep_Enable)
	{
		if(	F_Beep_Shortx1)
		{
			M_Beep_Cnt++;
		    if(M_Beep_Cnt == 1)
		    {
				_pbs02 =0;
				_pbs03 =1;
				_ston =0;
				_stmal = 250;
				_stmah = 250>>8;
				_ston =1;
		    }
		   	else if(M_Beep_Cnt >= 10)
		   	{
		    	_ston =0;
				F_Beep_Shortx1 =0;
				M_Beep_Cnt =0;
		   	}
		}
		else if(F_Beep_Shortx2 ==1)
		{
			M_Beep_Cnt++;
		    if(M_Beep_Cnt == 1)
		    {
				_pbs02 =0;
				_pbs03 =1;
				_ston =0;
				_stmal = 250;
				_stmah = 250>>8;
				_ston =1;
		    }
		   	else if(M_Beep_Cnt == 10)
		   	{
				_ston =0;
		   	}
		    else if(M_Beep_Cnt == 20)
		    {
				_pbs02 =0;
				_pbs03 =1;
				_ston =0;
				_stmal = 250;
				_stmah = 250>>8;
				_ston =1;
		    }
		   	else if(M_Beep_Cnt == 30)
		   	{
				_ston =0;
				F_Beep_Shortx2 =0;
				M_Beep_Cnt =0;
		   	}
		}
		else if(F_Beep_Longx1 ==1)
		{
			M_Beep_Cnt++;
		    if(M_Beep_Cnt == 1)
		   	{
				_pbs02 =0;
				_pbs03 =1;
				_ston =0;
				_stmal = 250;
				_stmah = 250>>8;
				_ston =1;
		   	}
		   	else if(M_Beep_Cnt >= 30)
		   	{
				_ston =0;
				F_Beep_Longx1 =0;
				M_Beep_Cnt =0;
		   	}
		}
		
	}
	else
	{
		F_Beep_Shortx1 =0;
		F_Beep_Shortx2 =0;
		F_Beep_Longx1 =0;
		M_Beep_Cnt =0;	
	}
	
	if(F_Beep_Alarm ==1)
	{
		M_Beep_Cnt++;
	    if(M_Beep_Cnt == 1)
	    {
			_pbs02 =0;
			_pbs03 =1;
			_ston =0;
			_stmal = 125;
			_stmah = 125>>8;
			_ston =1;
	    }
	   	else if(M_Beep_Cnt == 20)
	    {
			_ston =0;
	    }
	    else if(M_Beep_Cnt == 25)
	    {
			_pbs02 =0;
			_pbs03 =1;
			_ston =0;
			_stmal = 125;
			_stmah = 125>>8;
			_ston =1;
	    }
	   	else if(M_Beep_Cnt == 45)
	    {
			_ston =0;
	    }
	    else if(M_Beep_Cnt == 50)
	    {
			_pbs02 =0;
			_pbs03 =1;
			_ston =0;
			_stmal = 125;
			_stmah = 125>>8;
			_ston =1;
	    }
	   	else if(M_Beep_Cnt == 70)
	    {
			_ston =0;
	    }
	   	else if(M_Beep_Cnt == 90)
	    {
	    	M_Beep_Cnt =0;
	    }
	}
}
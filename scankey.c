#include "include.h"



void ScanKey(void)
{
			if(P_S_KEY ==0 &&  P_M_KEY ==0)
			{
				if(twokey_time<disen_tiem)
				{
				   twokey_time++;	
				   if(twokey_time==LONGKEY)	
				      twokey=2;//long
				}
				return ;
			}
			else
			{
				if(twokey_time>0 && twokey_time<LONGKEY)
				{
					twokey=1;
					twokey_time=0;
					return; 
				}
				twokey_time=0;
			}
//		_pd6=~_pd6;//LED
			if(P_M_KEY ==0)//模式键
			{
				if(memkey_time<disen_tiem)
				{
					memkey_time++;
						//	_pd6=~_pd6;//LED
					if(memkey_time==LONGKEY)
					{
					   memkey=2;//long
					}
					else if(memkey_time>LONGKEY+15)
					{
					   memkey=3;
					   memkey_time=LONGKEY;					
						
					}
				}

			}
			else
			{
				if(memkey_time>0 && memkey_time<LONGKEY)
				   memkey=1;
				memkey_time=0;
				
			}	
	
			if(P_S_KEY ==0)//上键
			{
				if(setkey_time<disen_tiem)
				{
				   setkey_time++;	
				   if(setkey_time==LONGKEY)	
				      setkey=2;//long
				}

			}
			else
			{
				if(setkey_time>0 && setkey_time<LONGKEY)
				   setkey=1;
				setkey_time=0;
				
			}	

			if(P_S_KEY_DOWN ==0)//下键
			{
				if(setkeydown_time<disen_tiem)
				{
				   setkeydown_time++;	
				   if(setkeydown_time==LONGKEY)	
				      setkeydown=2;//long
				}

			}
			else
			{
				if(setkeydown_time>0 && setkeydown_time<LONGKEY)
				   setkeydown=1;
				setkeydown_time=0;
				
			}
		
}

////--------------------------------------------------------------------------
//void ScanKeyProcess (void)
//{
//	unsigned char  KeyStatus;
//	
//	KeyStatus = (~_pa & 0x71);
//	
//	if(KeyStatus!=0)
//	{
//		if(M_KeyDebounce <3)
//			M_KeyDebounce++;
//	}
//	else
//		M_KeyDebounce =0;
//			
//	
//	if((KeyStatus!=0) && (M_KeyDebounce >=3))
//	{
//	
//		//---Left Key
//		if(F_M_KEY_HOLD ==0)
//		{
//			if(P_M_KEY ==0)
//			{
//				//GCC_DELAY(100);
//				F_M_KEY_HOLD =1;
//				F_M_KEY_TOGGLE =1;
//			}
//			else
//			{
//				F_M_KEY_HOLD =0;
//				F_M_KEY_TOGGLE =0;
//			}
//		}
//		else
//		{
//			if(P_M_KEY ==0)
//			{
//				//GCC_DELAY(100);
//				F_M_KEY_TOGGLE =0;
//				F_M_KEY_HOLD =1;
//			}
//			else
//			{
//				F_M_KEY_HOLD =0;
//				F_M_KEY_TOGGLE =0;	
//			}
//		}
//		
//		//---Right key
//		if(F_S_KEY_HOLD ==0)
//		{
//			if(P_S_KEY ==0)
//			{
//				//GCC_DELAY(100);
//				F_S_KEY_HOLD =1;
//				F_S_KEY_TOGGLE =1;
//			
//			}
//			else
//			{
//				F_S_KEY_HOLD =0;
//				F_S_KEY_TOGGLE =0;
//			}
//		}
//		else
//		{
//			if(P_S_KEY ==0)
//			{
//				//GCC_DELAY(100);
//				F_S_KEY_TOGGLE =0;
//				F_S_KEY_HOLD =1;
//			}
//			else
//			{
//				F_S_KEY_HOLD =0;
//				F_S_KEY_TOGGLE =0;	
//			}
//		}
//				
////		if(F_Strip_HOLD ==0)
////		{
////			if((P_StripIn ==0) || (P_UA_StripIn ==0))//blood_strips_pin4||_pa3
////			{
////				//GCC_DELAY(100);
////				F_Strip_HOLD =1;
////				F_Strip_TOGGLE =1;
////			
////			}
////			else
////			{
////				F_Strip_HOLD =0;
////				F_Strip_TOGGLE =0;
////			}
////		}
////		else
////		{
////			if((P_StripIn ==0) || (P_UA_StripIn ==0))//blood_strips_pin4||_pa3
////			{
////				//GCC_DELAY(100);
////				F_Strip_TOGGLE =0;
////				F_Strip_HOLD =1;
////			}
////			else
////			{
////				F_Strip_HOLD =0;
////				F_Strip_TOGGLE =0;	
////			}	
////		}
//		
////		F_Strip_HOLD=~blood_strips_pin4;
//		
////		//---UDkey
////		if(F_MS_KEY_HOLD ==0)
////		{
////			if((P_M_KEY ==0) && (P_S_KEY ==0))
////			{
////				//GCC_DELAY(100);
////				F_MS_KEY_HOLD =1;
////				F_MS_KEY_TOGGLE =1;
////				
////				
////				F_M_KEY_HOLD =0;
////				F_M_KEY_TOGGLE =0;	
////				F_S_KEY_HOLD =0;
////				F_S_KEY_TOGGLE =0;
////			
////			}
////			else
////			{
////				F_MS_KEY_HOLD =0;
////				F_MS_KEY_TOGGLE =0;
////			}
////		}
////		else
////		{
////			if((P_M_KEY ==0) && (P_S_KEY ==0))
////			{
////				//GCC_DELAY(100);
////				F_MS_KEY_TOGGLE =0;
////				F_MS_KEY_HOLD =1;
////				
////				F_M_KEY_HOLD =0;
////				F_M_KEY_TOGGLE =0;	
////				F_S_KEY_HOLD =0;
////				F_S_KEY_TOGGLE =0;
////			}
////			else
////			{
////				F_MS_KEY_HOLD =0;
////				F_MS_KEY_TOGGLE =0;
////				//F_M_KEY_TOGGLE =0;
////				//F_S_KEY_TOGGLE =0;
////				
////				if(P_M_KEY ==0)
////					F_M_KEY_HOLD =1;
////				if(P_S_KEY ==0)	
////					F_S_KEY_HOLD =1;
////					
////			}
////		}
////		
////		//---Strip
////		if(F_STRIP_HOLD ==0)
////		{
//////			if(P_STRIP ==0)
//////			{
//////				//GCC_DELAY(100);
//////				F_STRIP_HOLD =1;
//////				F_STRIP_TOGGLE =1;
//////			
//////			}
//////			else
//////			{
//////				F_STRIP_HOLD =0;
//////				F_STRIP_TOGGLE =0;
//////			}
////		}
////		else
////		{
//////			if(P_STRIP ==0)
//////			{
//////				//GCC_DELAY(1000);
//////				F_STRIP_TOGGLE =0;
//////				F_STRIP_HOLD =1;
//////			}
//////			else
//////			{
//////				F_STRIP_HOLD =0;
//////				F_STRIP_TOGGLE =0;	
//////			}
////		}
//	}
//	else
//	{
//		F_M_KEY_HOLD =0;
//		F_M_KEY_TOGGLE =0;
//		F_S_KEY_HOLD =0;
//		F_S_KEY_TOGGLE =0;
////		F_Strip_HOLD =0;
//		F_Strip_TOGGLE =0;	
//	}
//}
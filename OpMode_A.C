#include "include.h"

//unsigned char get_CODE(unsigned char Hex)
//{
//	switch(Hex)
//	{
//		case	0:	return	1;
//		case	1:	return	2;
//		case	2:	return	3;
//		case	3:	return	4;
//		case	4:	return	5;
//		case	5:	return	6;
//		case	6:	return	7;
//		case	7:	return	8;
//		case	8:	return	9;
//		case	9:	return	10;
//		
//		case	10:	return	11;
//		case	11:	return	12;
//		case	12:	return	13;
//
//		default:		return	1;
//	}
//}



void init_Error_Task(unsigned char err_number)
{

	M_TaskBuf0 =e_Errmode;//mode
 	M_TaskBuf1 =0;
 		   	
	M_Error_Task =err_number;
	M_ErrorCount=0;
	M_RTC_display=0;
	LCD_Clear(OFF);

}


//static float getGMtempOfs( INT8U show )
//{
//    struct tagTAB {
//        const INT8U *Tm , *Tf ;
//    } const *p ;
//
//    static const struct tagTAB tab[] = {
//    	{&memStrip.T[0]  ,	&memStrip.Tf[0]  },
//        {&memStrip.T[1]  ,  &memStrip.Tf[1]  },
//        {&memStrip.T[2]  ,  &memStrip.Tf[2]  },
//        {&memStrip.T[3]  ,  &memStrip.Tf[3]  },
//        {&memStrip.T[4]  ,  &memStrip.Tf[4]  },
//        {&memStrip.T[5]  ,  &memStrip.Tf[5]  },
//        {&memStrip.T[6]  ,  &memStrip.Tf[6]  },
//        {&memStrip.T[7]  ,  &memStrip.Tf[7]  },
//        {&memStrip.T[8]  ,  &memStrip.Tf[8]  },
//        {&memStrip.T[9]  ,  &memStrip.Tf[9]  },
//        {&memStrip.T[10] ,	&memStrip.Tf[10] },
//        {&memStrip.T[11] ,  &memStrip.Tf[11] },
//        {&memStrip.T[12] ,  &memStrip.Tf[12] },
//        {&memStrip.T[13] ,  &memStrip.Tf[13] },
//        {&memStrip.T[14] ,  &memStrip.Tf[14] },
//        {&memStrip.T[15] ,  &memStrip.Tf[15] },
//    } ;
//    	
//    int measTemp ;
//    INT16U tempOfs ;
//    float data ;
//
//    //measTemp = MeasTemp() ;
//    //RecData.measTemp = measTemp ;
//    measTemp = M_Temperature ;
//    //
//    if( *(tab[0].Tm)*(INT16U)10 >= measTemp ) return (float)*(tab[0].Tf)/(float)100 ;
//    if( *(tab[sizeof(tab)/sizeof(tab[0])-1].Tm) * (INT16U)10 <= measTemp ) return (float)*tab[sizeof(tab)/sizeof(tab[0])-1].Tf/(float)100 ;
//    //
//    p = tab + sizeof(tab)/sizeof(tab[0]) ;
//    while( tab != p-- ) {
//        if( (INT16U)*(p->Tm)*(INT16U)10 == measTemp ) return ( (float)*(p->Tf)/(float)100 ) ;
//        if( (INT16U)*(p->Tm)*(INT16U)10 > measTemp ) continue ;
//        //
//        if( *((p+1)->Tf) == *(p->Tf) ) {
//            if( true == show ) {
//                //ShowDec( (INT16U)*(p->Tf)*10 ) ;
//                //LCD_ScanOut() ; 
//                //delayTime_t10mS( 200 ) ;
//            }
//            return (float)*(p->Tf)/(float)100 ;
//        }
//        //
//        if( *((p+1)->Tf) < *(p->Tf) ) {
//            data  = (float)(*((p+1)->Tm)- *(p->Tm) )*(float)10 ;
//            tempOfs = measTemp - (INT16U)*(p->Tm)*(INT16U)10 ;
//            data = ( (float)*(p->Tf) - (float)(*(p+1)->Tf) ) / data ;
//            data = (float)*(p->Tf) - ( (float)tempOfs * data ) + (float)0.5 ;
//            if( true == show ) {
//                //ShowDec( (INT16U)data*10 ) ;
//                //LCD_ScanOut() ;
//                //delayTime_t10mS( 200 ) ;
//            }
//            return data/(float)100 ;
//        }
//        else {
//            data  = (float)(*((p+1)->Tm)- *(p->Tm) )*(float)10 ;
//            tempOfs = (INT16U)(measTemp - *(p->Tm)*(float)10) ;
//            data = ( (float)(*(p+1)->Tf) - (float)*(p->Tf) ) / data ;
//            data = (float)*(p->Tf) + ( (float)tempOfs * data ) + (float)0.5 ;
//            if( true == show ) {
//                //ShowDec( (INT16U)data*10 ) ;
//                //LCD_ScanOut() ;
//                //delayTime_t10mS( 200 ) ;
//            }
//            return data/(float)100 ;
//        }
//    }
//    return 0 ;
//}

//static INT16U Calulator_GM( INT16U data )
//{
//	float gm ;
//	
//	gm = (float)data/(float)100	* (float)memStrip.B ;	// because base is x.xx uA
//	gm *= 1 + ( (float)memStrip.C1-(float)memStrip.S ) * (float)memStrip.d / (float)100 ;
//	gm += (float)memStrip.C2 - (float)memStrip.I ;
//	gm *= getGMtempOfs(false) ;
//	gm += (float)0.5 ;
//	if( 0 > gm ) return 0 ;
//	data = (INT16U)gm ;
//	return data ;
//}
//
//static INT16U Calulator_LinearGM( INT16U data )
//{
//	INT8U index = 10 ;
//
//	//	
//	if( data < memStrip.Meas[0] ) return data ;
//	if( data > memStrip.Meas[9] ) return data ;	
//	//	
//	while( index-- ) {
//	    if( data == memStrip.Meas[index] ) return memStrip.Target[index] ;
//		if( data < memStrip.Meas[index] ) continue ;
//		break ;
//	}
//	//if( 0 == index || 9 == index ) return data ;
//	data = (INT16U)memStrip.Target[index] + ((memStrip.Target[index+1]-memStrip.Target[index] )*( data-memStrip.Meas[index] ))/( memStrip.Meas[index+1]-memStrip.Meas[index] ) ;
//	return data ;
//}

//static INT16U MeasGMdataCheck( INT16U data )
//{
//    //if( Is_StripVref_Err() ) {
//    //    return memStrip.GlucoseMax + 10 ;
//    //}
//    //else {
//    //    if( data ) {
//	        data = Calulator_GM( data ) ;
//	        data = Calulator_LinearGM( data ) ;
//	//    }
//	    return data ;        
//    //}
//}


void send_uart_data(void)
{
#ifdef G35 	
	uint8_t i;
	
	for(i =0;i<M_UART_TxFIFO[1]-1;i++)
	
	    M_UART_TxFIFO[M_UART_TxFIFO[1]-1] += M_UART_TxFIFO[i];			  			
	
//	 M_UART_TxFIFO[M_UART_TxFIFO[1]-1] += 2;
	M_UART_TxLength =M_UART_TxFIFO[1];
	M_UART_TxIndex =0;
	_txr_rxr0= M_UART_TxFIFO[M_UART_TxIndex];	    								
			
	i =1;
	while(i)
	{
		GCC_CLRWDT();
		if(M_UART_TxIndex >= M_UART_TxLength)
			i =0;
	}		
#endif
}


#define		GPIO_led			_pd6

	volatile unsigned long 	Lbuf1;
	volatile signed int 	Ibuf0,Ibuf1;
	volatile unsigned int	Address;
	unsigned char 			Cbuf0,count;
	volatile unsigned char 	temp,buf[8];
	volatile char dis =0;
	volatile unsigned long Project_Sequence;
	volatile double 	proportion[2];	
	
//void get_sys_data(void)
//{
//	unsigned char k;
//	M_UART_RxIndex=0;
////	work_time=0;
//
////	while(work_time<50)	GCC_CLRWDT();
//	for(work_time=0;work_time<50;)
//	{	
//		GCC_CLRWDT();
//  		if(M_UART_RxIndex>0)
//  		{
//  			if(M_UART_RxFIFO[0]!=0x5a)
//  			{
//  				M_UART_RxIndex=0;
//  			}
//  			else
//  			{
//  				if(M_UART_RxIndex>2 && M_UART_RxFIFO[1]==M_UART_RxIndex)
//  				{
//  					 Ibuf0=2;
//                     for(Ibuf1=0;Ibuf1<M_UART_RxFIFO[1]-1;Ibuf1++)
//                         Ibuf0+=M_UART_RxFIFO[Ibuf1];
//                     
//                     if(Ibuf0%256==M_UART_RxFIFO[M_UART_RxFIFO[1]-1] && M_UART_RxFIFO[2]==7)
//                     {
//                     	
//						 Ibuf1 = M_UART_RxFIFO[3] *256+ M_UART_RxFIFO[4];    //E_U检测电流值 *1000
//                         if(Ibuf1>=10 && Ibuf1<= 10000)
//                            mcode_data.EU_Current=Ibuf1;
//                         
//                         Ibuf1 = M_UART_RxFIFO[5] *256+ M_UART_RxFIFO[6];   //启动电流门槛值 *1000
//                         if(Ibuf1>=100 && Ibuf1<= 10000)                   
//                            mcode_data.START_Current=Ibuf1;
//                   
//                         Ibuf1 = M_UART_RxFIFO[7] *256+ M_UART_RxFIFO[8];    //启动阻抗门槛值*100
//                         if(Ibuf1>0 && Ibuf1<= 60000) 
//                         {
//                            mcode_data.Start_z=Ibuf1; 
//                            mcode_data.Start_z/=100;
//                         }
//                         Ibuf1 = M_UART_RxFIFO[9] *256+ M_UART_RxFIFO[10];   //满血延时检测时间,1.2秒。 *1 
//                         if(Ibuf1>=50 && Ibuf1<= 1200)                   
//                            mcode_data.Full_delay_time=Ibuf1;
//                         
//                         Ibuf1 = M_UART_RxFIFO[11] *256+ M_UART_RxFIFO[12];  //满血出错阀值  * 1000   //0.1-10.000uA
//                         if(Ibuf1>=100 && Ibuf1<= 10000)                   
//                            mcode_data.Full_check=Ibuf1;                         
//                         
//                         Ibuf1 = M_UART_RxFIFO[13] *256+ M_UART_RxFIFO[14];  //血糖测量时间  *1   
//                         if(Ibuf1>=4000 && Ibuf1 <= 7000)                   
//                            mcode_data.Work_time=Ibuf1; 
//                            
//                            
//				  			Cbuf0 =0;
//				  			M_UART_TxFIFO[Cbuf0++] = 0x55;
//				  			M_UART_TxFIFO[Cbuf0++] = 16;//包长
//				  			
//				  			M_UART_TxFIFO[Cbuf0++] = 8;//包类别
//				  			
//				  			M_UART_TxFIFO[Cbuf0++] = mcode_data.EU_Current/256;//E_U检测电流值
//				  			M_UART_TxFIFO[Cbuf0++] = mcode_data.EU_Current%256;//E_U检测电流值
//				  			
//				  			M_UART_TxFIFO[Cbuf0++] = mcode_data.START_Current/256;//启动电流门槛值
//				  			M_UART_TxFIFO[Cbuf0++] = mcode_data.START_Current%256;//启动电流门槛值
//				  			
//				  			M_UART_TxFIFO[Cbuf0++] = mcode_data.Start_z*100/256;//启动阻抗门槛值							  			
//				  			M_UART_TxFIFO[Cbuf0++] = mcode_data.Start_z*100%256;
//				  			
//				  			
//				  			M_UART_TxFIFO[Cbuf0++] = mcode_data.Full_delay_time/256;
//				  			M_UART_TxFIFO[Cbuf0++] = mcode_data.Full_delay_time%256;
//				  			
//				  			M_UART_TxFIFO[Cbuf0++] = mcode_data.Full_check/256;
//				  			M_UART_TxFIFO[Cbuf0++] = mcode_data.Full_check%256;
//				  			
//				  			M_UART_TxFIFO[Cbuf0++] = mcode_data.Work_time/256;
//				  			M_UART_TxFIFO[Cbuf0++] = mcode_data.Work_time%256;							  			
//				  			
//
//				  			M_UART_TxFIFO[Cbuf0++]=2;
//				  			for(Cbuf0 =0;Cbuf0<M_UART_TxFIFO[1]-1;Cbuf0++)
//				  			
//				  			    M_UART_TxFIFO[M_UART_TxFIFO[1]-1] += M_UART_TxFIFO[Cbuf0];			  			
//				  			
//				  			
//				  			M_UART_TxLength =M_UART_TxFIFO[1];
//				  			M_UART_TxIndex =0;
//				  			_txr_rxr0= M_UART_TxFIFO[M_UART_TxIndex];	    								
//									
//							Cbuf0 =1;
//							do
//							{
//								GCC_CLRWDT();
//								if(M_UART_TxIndex >= M_UART_TxLength)
//									Cbuf0 =0;
//							}
//							while(Cbuf0);
//							memset(M_UART_RxFIFO,0,128);	
//							M_UART_RxIndex=0;
//							k=0;		                            
//                            
//			                     	
//                     }		      					  					
//  					
//  			    } 				
//  			} 			 			
//  		}
//	}
//}

void intit_Impedance(void)
 {
		SET_OPAn_POWER(1,POWEROFF);
		SET_OPAn_POWER(2,POWEROFF);
		SET_OPA34_POWER(POWEROFF);
		SET_PIN_OPnP_OPEN(1);
		SET_PIN_OPnP_OPEN(2);
		SET_PIN_OP3P_OPEN();
		fun_StripModuleAllOpen();
		
		

		
//								
//		//---set VG0
//
		_pac3 = 1;  		
		_papu3=0;//去掉血糖检测端上拉，否则有电流??
		
		up_pin4 =0;//血糠试纸插入脚拉?		
		strips_pin4_dir = 1;  

		_papu1 = 0;
		_pac1 = 0;			
		_pa1 =0;	

#if 0						
		strips_pin8_dir=1;//in--strips pin8
		up_pin8=0;
		strips_pin8=0;
		
		strips_pin7_dir=1;//in--strips pin7
		up_pin7=0;
		strips_pin7=0;
		
		
		strips_pin6_dir=1;//in--strips pin6
		up_pin6=0;
		strips_pin6=0;												

		_papu1 =0;//--strips pin6--G35改到此脚！！		
		_pac1 = 1;  		
#endif						
		//--- set sin wave
	//	M_SinGain = 50;//50=1.16vpp/15=344//16=376
	
		M_SinGain = 50;//=1.22vpp
		fun_SineWaveInit(SINWAVEFREQ_50KHZ);	//50KH						
	
		
	
		
//		M_SinGain = 25;//=1.22vpp
//		fun_SineWaveInit(SINWAVEFREQ_50KHZ);	//50KH		
								
		//--- set measurement ac channel

		//--- enable opa3 & bia
		SET_OPA34_POWER(POWERON);

		/* Sine Wave out*/
		SET_PIN_SINO1_SINOUT();
   						
 }	
 
// 最新试纸测量流程：
//试纸规格：
//1.AC
//2.DC
//3,4,FULL,KEY
//5.COM
void load_autoCode_data(void)
{
	
		//sys_data.used_AD =  Current_to_AD_Convert (glucose_auto_code[12].a1,C_ResOP1N1);//68.0K
		//sys_data.start_AD = Current_to_AD_Convert (glucose_auto_code[12].b1,C_ResOP1N1);//68.0K;		
		//sys_data.full_AD = Current_to_AD_Convert (glucose_auto_code[12].c1,C_ResOP1N2); //95.3K;		
		sys_data.used_curren =  glucose_auto_code[2].a_T;
		sys_data.start_curren = glucose_auto_code[2].b_T;
		sys_data.full_curren = glucose_auto_code[2].c_T; 	
		sys_data.measurement_time = glucose_auto_code[2].a_I;
		sys_data.err_Impedance = glucose_auto_code[2].b_I;
		auto_code = 2;				
		if(M_Strip_Type==glucose_Type)
		{
		
			   if(F_ControlOption)
			   {
			   			//sys_data.a1=glucose_code1[0].a1;
					   alg_para.a_T=glucose_auto_code[0].a_T;//0.0003469;
		               alg_para.b_T=glucose_auto_code[0].b_T;//-0.0237844;  
		               alg_para.c_T=glucose_auto_code[0].c_T;//1.3501328; 	
				     	
				     	
		               alg_para.a_I=glucose_auto_code[0].a_I;//-0.004785;
		               alg_para.b_I=glucose_auto_code[0].b_I;//0.139243;  
		               alg_para.c_I=glucose_auto_code[0].c_I;//0.37215; 
		
		               //alg_para.a_corr1=glucose_auto_code[0].a_corr1;//0.020434;
		               //alg_para.b_corr1=glucose_auto_code[0].b_corr1;//1.833924;  
		               //alg_para.c_corr1=glucose_auto_code[0].c_corr1;//-1.614224; 		

					   alg_para.a_HCT=glucose_auto_code[0].a_HCT;//0.020434;
		               alg_para.b_HCT=glucose_auto_code[0].b_HCT;//1.833924;  
		               alg_para.c_HCT=glucose_auto_code[0].c_HCT;//-1.614224; 	

					   alg_para.a_imp1=glucose_auto_code[0].a_imp1;//0.020434;
		               alg_para.b_imp1=glucose_auto_code[0].b_imp1;//1.833924;  
		               alg_para.c_imp1=glucose_auto_code[0].c_imp1;//-1.614224; 	

					   alg_para.a_imp2=glucose_auto_code[0].a_imp2;//0.020434;
		               alg_para.b_imp2=glucose_auto_code[0].b_imp2;//1.833924;  
		               alg_para.c_imp2=glucose_auto_code[0].c_imp2;//-1.614224; 

					   alg_para.a_C=glucose_auto_code[0].a_C;//0.020434;
		               alg_para.b_C=glucose_auto_code[0].b_C;//1.833924;  
		               alg_para.c_C=glucose_auto_code[0].c_C;//-1.614224; 
			   	
			   }
			   else
			   {
					   //alg_para.a1=glucose_auto_code[auto_code-1].a1;//0.0003469;
					   alg_para.a_T=glucose_auto_code[auto_code-1].a_T;//0.0003469;
		               alg_para.b_T=glucose_auto_code[auto_code-1].b_T;//-0.0237844;  
		               alg_para.c_T=glucose_auto_code[auto_code-1].c_T;//1.3501328; 	
				     	
				     	
		               alg_para.a_I=glucose_auto_code[auto_code-1].a_I;//-0.004785;
		               alg_para.b_I=glucose_auto_code[auto_code-1].b_I;//0.139243;  
		               alg_para.c_I=glucose_auto_code[auto_code-1].c_I;//0.37215; 
		
		               //alg_para.a_corr1=glucose_auto_code[auto_code-1].a_corr1;//0.020434;
		               //alg_para.b_corr1=glucose_auto_code[auto_code-1].b_corr1;//1.833924;  
		               //alg_para.c_corr1=glucose_auto_code[auto_code-1].c_corr1;//-1.614224; 		

					   alg_para.a_HCT=glucose_auto_code[auto_code-1].a_HCT;//0.020434;
		               alg_para.b_HCT=glucose_auto_code[auto_code-1].b_HCT;//1.833924;  
		               alg_para.c_HCT=glucose_auto_code[auto_code-1].c_HCT;//-1.614224; 	

					   alg_para.a_imp1=glucose_auto_code[auto_code-1].a_imp1;//0.020434;
		               alg_para.b_imp1=glucose_auto_code[auto_code-1].b_imp1;//1.833924;  
		               alg_para.c_imp1=glucose_auto_code[auto_code-1].c_imp1;//-1.614224; 	

					   alg_para.a_imp2=glucose_auto_code[auto_code-1].a_imp2;//0.020434;
		               alg_para.b_imp2=glucose_auto_code[auto_code-1].b_imp2;//1.833924;  
		               alg_para.c_imp2=glucose_auto_code[auto_code-1].c_imp2;//-1.614224; 

					   alg_para.a_C=glucose_auto_code[auto_code-1].a_C;//0.020434;
		               alg_para.b_C=glucose_auto_code[auto_code-1].b_C;//1.833924;  
		               alg_para.c_C=glucose_auto_code[auto_code-1].c_C;//-1.614224; 

			   	
			   	}
		}
		else if(M_Strip_Type==ketone_Type)
		{
			
//			sys_data.used_tape_current = ketone_auto_code[12].a1;
//			sys_data.trigger_current = ketone_auto_code[12].b1;		
//			sys_data.full_blood_current = ketone_auto_code[12].c1;	
			
		//sys_data.used_AD =  Current_to_AD_Convert (ketone_auto_code[12].a1,C_ResOP1N1);//68.0K
		//sys_data.start_AD = Current_to_AD_Convert (ketone_auto_code[12].b1,C_ResOP1N1);//68.0K;		
		//sys_data.full_AD = Current_to_AD_Convert (ketone_auto_code[12].c1,C_ResOP1N2); //95.3K;			
					
			//sys_data.measurement_time = ketone_auto_code[12].a2;				
			
			
			
			
		}
		else if(M_Strip_Type==Urea_Type)
		{}
		else if(M_Strip_Type==Chol_Type)
		{}
		sys_data.M_Strip_Type=M_Strip_Type;
		sys_data.auto_code=auto_code;

}
//const _code_data glucose_code[12]=
//{
//     
//    {0.0003469 ,-0.0237844, 1.3501328,-0.004785,0.139243,0.37215,0.020434,1.833924,-1.614224 } ,     // code1
//    
//    {0.0003469 ,-0.0237844, 1.3501328,-0.004785,0.139243,0.37215,0.020434,1.833924,-1.614224 } ,     // 2
//    
//    {0.0003469 ,-0.0237844, 1.3501328,-0.004785,0.139243,0.37215,0.020434,1.833924,-1.614224 } ,     // 3   
//    
//    {0.0003469 ,-0.0237844, 1.3501328,-0.004785,0.139243,0.37215,0.020434,1.833924,-1.614224 } ,     // 4   
//    
//    {0.0003469 ,-0.0237844, 1.3501328,-0.004785,0.139243,0.37215,0.020434,1.833924,-1.614224 } ,     // 5
//    
//    {0.0003469 ,-0.0237844, 1.3501328,-0.004785,0.139243,0.37215,0.020434,1.833924,-1.614224 } ,     // 6 
//      
//    {0.0003469 ,-0.0237844, 1.3501328,-0.004785,0.139243,0.37215,0.020434,1.833924,-1.614224 } ,     // 7  
//         
//    {0.0003469 ,-0.0237844, 1.3501328,-0.004785,0.139243,0.37215,0.020434,1.833924,-1.614224 } ,     // 8
//    
//    {0.0003469 ,-0.0237844, 1.3501328,-0.004785,0.139243,0.37215,0.020434,1.833924,-1.614224 } ,     // 9   
//     
//    {0.0003469 ,-0.0237844, 1.3501328,-0.004785,0.139243,0.37215,0.020434,1.833924,-1.614224 } ,     // 10   
//      
//    {0.0003469 ,-0.0237844, 1.3501328,-0.004785,0.139243,0.37215,0.020434,1.833924,-1.614224 } ,     //  11 
//          
//    {0.0003469 ,-0.0237844, 1.3501328,-0.004785,0.139243,0.37215,0.020434,1.833924,-1.614224 } ,     // 12
//};


void get_auto_code(void)
{
#if 0
		strips_pin8_dir=1;//in--strips pin8
		up_pin8=1;
		strips_pin8=0;
		
		strips_pin7_dir=1;//in--strips pin7
		up_pin7=1;
		strips_pin7=0;
		
		
		strips_pin6_dir=1;//in--strips pin6
		up_pin6=1;
		strips_pin6=0;	  
		
		
//		strips_pin4_dir=1;//in--strips pin4
//		up_pin4=1;
//		blood_strips_pin4=0;	    
	    
		strips_pin4_dir=0;//set  pin4 to 0
		up_pin4=0;
		blood_strips_pin4=0;	  
						
		GCC_CLRWDT();
		delay(250);          //1ms for base
			//pin 8,7,6
		imp=0;
		if(strips_pin6)//6
		  imp|=1;	
		if(strips_pin7)//7
		  imp|=2;
		if(strips_pin8)//8
		   imp|=4;	
		if( imp==7)
		{
			strips_pin8_dir=0;//set pin8 to 0
			up_pin8=0;
			strips_pin8=0;	
			delay(250);          //1ms for base
				//pin 8,7,6	
				
			imp=0;
			if(strips_pin6)//6
			  imp|=1;	
			if(strips_pin7)//7
			  imp|=2;	
			  
			 if(imp==3) 
			 {
				strips_pin7_dir=0;//in--strips pin7
				up_pin7=0;
				strips_pin7=0;					 	
				delay(250); 

				if(strips_pin6)//6
				   auto_code=12;						  
				else
				   auto_code=9;

			 }
			 else
			 {
			 	if(imp==0)
			       auto_code=8;
			 	if(imp==1)
			       auto_code=11;
			 	if(imp==2)
			       auto_code=10;					     					     	
			 	
			 }						

		}
		else
		{
		   if(imp==0) 
		      auto_code=1;
		   if(imp==1) 
		      auto_code=2;					
		   if(imp==2) 
		      auto_code=3;
		   if(imp==3) 
		      auto_code=5;
		   if(imp==4) 
		      auto_code=4;					
		   if(imp==5) 
		      auto_code=6;
		   if(imp==6) 
		      auto_code=7;				     				     
		     
		     					
		}	
#endif
		load_autoCode_data();	
}




/**
temp 0;无温补
temp 1;有温补
**/
void get_glucose (unsigned char temp)
{	 
	//unsigned int kk;
	//alg_para.a1 =0.12;
	_emi=0; 
	 sys_data.f_T=alg_para.a_T*sys_data.Temperature*sys_data.Temperature + alg_para.b_T*sys_data.Temperature + alg_para.c_T;
	  if(temp)	
		 sys_data.f_I=alg_para.a_I*sys_data.f_T*sys_data.f_T + alg_para.b_I*sys_data.f_T + alg_para.c_I;										   
	  else
	  sys_data.f_I=1.0;
	  sys_data.I_corr=sys_data.Current*sys_data.f_I;	  
	 // sys_data.I_corr1=alg_para.a_corr1*sys_data.I_corr*sys_data.I_corr + alg_para.b_corr1*sys_data.I_corr + alg_para.c_corr1;
	  
	  sys_data.f_HCT=alg_para.a_HCT*sys_data.f_T*sys_data.f_T + alg_para.b_HCT*sys_data.f_T + alg_para.c_HCT; 

	  
	  sys_data.HCT_corr=sys_data.f_HCT*sys_data.Impedance;
	  
	  sys_data.f_imp1=alg_para.a_imp1*sys_data.HCT_corr*sys_data.HCT_corr + alg_para.b_imp1*sys_data.HCT_corr + alg_para.c_imp1; 
	  sys_data.f_imp2=alg_para.a_imp2*sys_data.HCT_corr*sys_data.HCT_corr + alg_para.b_imp2*sys_data.HCT_corr + alg_para.c_imp2; 
	  sys_data.Low_C_High_HCT = sys_data.I_corr/sys_data.HCT_corr *100;
	  sys_data.f_imp = (sys_data.Low_C_High_HCT>60) ? sys_data.f_imp1:sys_data.f_imp2;
	  sys_data.f_imp_c = (sys_data.HCT_corr>30) ? 0.85:sys_data.f_imp;

	  sys_data.I_imp=sys_data.I_corr*sys_data.f_imp_c;

	  sys_data.mmol=alg_para.a_C*sys_data.I_imp*sys_data.I_imp + alg_para.b_C*sys_data.I_imp + alg_para.c_C;
	  
//		kk=sys_data.mmol*100+5;//四舍五入
//		sys_data.mg=kk;
//		sys_data.mg*=18; 
//	  sys_data.mmol = sys_data.mmol+0.05;//四舍五入
	  sys_data.mg= sys_data.mmol*18;

	 _emi=1;		
	 GCC_CLRWDT();				
}

/**
质控液算法
temp 0;无温补
temp 1;有温补


**/

void get_glucose_ctr (unsigned char temp)
{	 
//	unsigned int kk;
	//alg_para.a1 =0.12;
	sys_data.f_T=alg_para.a_T*sys_data.Temperature*sys_data.Temperature + alg_para.b_T*sys_data.Temperature + alg_para.c_T;
	_emi=0; 
	  if(temp)	
      	 sys_data.f_I=alg_para.a_I*sys_data.f_T*sys_data.f_T + alg_para.b_I*sys_data.f_T + alg_para.c_I; 		               		               
	  else
	  sys_data.f_I=1.0;
      sys_data.I_corr=sys_data.Current*sys_data.f_I;
	  
      sys_data.mmol=alg_para.a_HCT*sys_data.I_corr*sys_data.I_corr + alg_para.b_HCT*sys_data.I_corr + alg_para.c_HCT;

	  //sys_data.mmol = sys_data.mmol+0.05;//四舍五入
    //  kk=sys_data.mmol*100+5;//四舍五入
    //  sys_data.mg=kk;
//      sys_data.mg*=18; 
      sys_data.mg= sys_data.mmol*18;

	 _emi=1;		
	 GCC_CLRWDT();				
}
#if 0
volatile unsigned char Start_Detection_flag= 0 ;
unsigned char Is_Stop_Update_Lcd(void)//因刷屏耗时较长，在特殊情况下中断刷屏
{
	//在滴血界面下 按下按键，停止刷屏，否则概率按键没响应
	if(M_Task==C_NormalMode && M_TaskBuf0 == e_Start_detection)
	{
		if(P_S_KEY ==0 &&  P_M_KEY ==0)
		{
			return 1;
		}
	}
	if(!Start_Detection_flag)
	return 0;
	if(SDKADCSourceData.flag.b.IsReady)//检测到滴血  停止刷屏
	{
		SDKADCSourceData.flag.b.IsReady =0;
		 avg_ad2= SDKADCSourceData.data.ADCData >> 16;
		 if(avg_ad2<0)
			avg_ad2=0;					
		M_Current = ADCtoCurrent_Convert(avg_ad2,C_ResOP1N1);
		//M_Current/=1000;
		if(M_Current>sys_data.used_curren)//is used
		{
			return 1;
		}
	}
	return 0;
}
#endif
/*******************************************************************
一：试纸pin脚图
----------
| --------
| |
| | ======
| | ---  |
| |   |  |
| |   |  |
| |   |  |
| |   |  |
| |   |  |
| |   |  |
| |   |  |
|-----|  |
1 2   3  4

试纸pin脚位对应芯片的io命名
试纸			芯片
pin1---->SINO1/VG0
pin2---->R_SINI/OP2N
pin3---->OP1N2/PA4
pin4---->I_OP1N1/PA3

二：pin脚说明
1. 试纸共有4个pin脚，共有4个电极，AC测量阻抗电极C1、C2，DC测量电极C3、C4；
2. 试纸的pin3和pin4用在DC血糖电流测试；其中，pin4为工作电极，电位为0.35V，pin3作对电极，；
3. 试纸的pin1和pin2用在AC血糖阻抗测试；
三：时序控制
a.仪器pin1/pin3判断试纸插入；
b.插入试纸后，1）首先判断试纸是否用过或者受潮，该过程是在Pin3和Pin4加压测量电流值，判断电流值值大于某个值时则提示试纸异常，
			  2）等待吸样过程：同上在PIN3和PIN4加压测量电流值，大于阈值则仪器启动计时，在3S内，Pin3/pin4 检测电流信号，
			  电流信号大于阈值，即为加样完成，否则报错
c.加样完成后，pin1/pin2测试AC阻抗信号,采用交流信号±600mv测试，激励1S；
d.Pin3/pin4电极输出0mv，持续2.5S，再输出350mv持续2.5S。
e.至此测试过程结束。倒计时结束，LCD显示测试结果！

四：软件实现
a.试纸插入判断
  1.仪器休眠前设置pin1接入模拟地
  2.pin3接入到芯片唤醒口（PA4）
  3.因为试纸pin1和pin3连接，当试纸插入则芯片的PA4接到模拟地，此时仪器唤醒

b.阻抗测量
  1.配置模拟地pin1断开
  2.配置pin1脚输出幅度为±600mv，频率为50kHZ的正弦包
  3.正弦波经过血液后从pin2输入到芯片内部
  4.配置ad采集到内部MOD1ON（解调器 1），采集4个相位的数据，用这4个相位的ad值带入公式计算出阻抗值

c.电流测量
  1.配置模拟地pin1接入地，pin3与pin1相连接到地
  2.加压--》配置寄存器，使得VDAC(0.35v)接入到OP1N1引脚(试纸4脚)，此时完成加压，通过血液经过3脚流入1脚模拟地
  3.硬件回路如下图所示，0.35V从OP1N1(试纸4脚)给血液加压，加压后产生的电流经过反馈电阻68K
  4.通过内部ADC设置采集采集反馈电阻两端的电压，使用I=U/R得到留经过血液的电流

                        流过反馈电阻的电流I
                       <------------
                           _____
		 _________________| 68k |_______________
        |     |           |_____|          |    |      
        |     |                            |    |
        |      -----ADC采样这两端的电压----     |
        |                                       |
		|0.35v			OP1N1 |\  OPA1          |
		|—————————————————————| \               |
		|				DAC10 |  \______________|
	   _|_				——————|  /
      |血 |				  	  | /
	  |液 |				      |/ 
	  |___|
	    |
		|
		|
	  —————
	   ———
	    — 
********************************************************************/	
void Normal_Measurement_Mode (void)
{
	//volatile unsigned int M_Avg_16bit_result;
//	_pd6=~_pd6;//LED
    int i=0;
	M_RTC_display++;
	M_No_Active_Cnt++;
	if(M_No_Active_Cnt >= 18000)
	{
		//init_Error_Task(1);
		M_TaskBuf0 = e_Exit_mode;

	}
	switch (M_TaskBuf0)
	{
		
		
		//--- start measurement display ----
 	  	case e_Full_screen:
 	  	{
 	  //		LED=1;

//	      	M_RTC_display++;		//base 10ms
	      	
			if(M_RTC_display<2)
			{
	      		//---Lcd All on
	      		
	      		LCD_Clear(ON);
	      		memset((unsigned char *)DC_data_buf,0,128);
	      		memset((unsigned char *)M_Impedance_data,0,80);				     	
	            //--- Beep ON
	            F_Beep_Shortx1 =1;

  				_pac3 =0;//
				_pa3 =0;//
							
				M_RTC_display =0;
		     	M_TaskBuf0 =e_Init;
		     	M_TaskBuf1 =0;
		     	M_Cbuf0 =0;
		     	F_ControlOption =0;
		     	M_No_Active_Cnt =0;
				meals=0;
				Start_Detection_flag= 0 ;

		     	
//		     	LED=1;
		     	
		     	if(Load_VrefDaco_Vaule())
		     	{
			    	init_Error_Task(0xe);
			    	break;		     		
		     	}	
				fun_UART0PowerOnInit();
				
	            //--- Dacvref Enable		        
    			fun_DACVREFInit(POWERON);
		        //--- Daco1 Enable
		        fun_DACnInit(1,DACnOEnable);				

				//--- opa calibration offset
				fun_CalOPA1Offset();
				fun_CalOPA2Offset();
				fun_CalOPA3Offset();
				
	            //--- Dacvref Enable		        
    			fun_DACVREFInit(POWERON);
		        //--- Daco1 Enable
		        fun_DACnInit(1,DACnOEnable);


				memset((unsigned char *)M_UART_RxFIFO,0,128);
				memset((unsigned char *)M_UART_TxFIFO,0,128);				
				//--- clear count	
				M_Cbuf0 =0;
				//--- clear flag
				F_Into_FactoryMode =0;
				F_MeasureFullBlood =0;
				F_MeasureStart =0;
				F_MeasureAc =0;		
				imp=0;		 
				
	  			if(F_Low_battery_Act)
		     	{
			    	init_Error_Task(0x6);
			    	break;		     		
		     		
		     	}
		     	
#ifdef G777G_TEST
				M_Current_use_log = 0;
				M_Current_start_log = 0;
				M_Current_full_log = 0;
#endif
		     	meals=0;
		     	lcd.meas.Bit.AftMeal=0;		     								
	            lcd.meas.Bit.BefMeal=0;	
				lcd.meas.Bit.Gen=1;	
	            lcd.meas.Bit.ControlSoultion=0;	
			}
		//	else if(M_RTC_display >30)
			{
		     	M_TaskBuf0=e_Init;
		  //   	_pd6=~_pd6;
			}

	      	break;
 	  	}
	    
//--------------------------------------------------------------------------		    
	    case e_Init:
	     get_auto_code();

				M_TaskBuf0=e_Strip_type;
				
				break; 
//--------------------------------------------------------------------------	 
 	  	case e_Strip_type:
 	  	
// #define glucose_Type   1//血糖
//#define ketone_Type    2//血酮
//#define Urea_Type      3//尿酸
//#define Chol_Type      4//总胆固醇
//#define code_Type      5//密码卡	  	
// 	
 	      	//--- check Strip type

	      		//
	      		if((M_Strip_Type == 0) || (M_Strip_Type >4))
	      		{
	      			init_Error_Task(2);//------------------------------------------------------------	2 --- check strip type error "E-7"
	      		
	      			break;
	      		}	

				M_TaskBuf0=e_check_Dac1o;
				M_RTC_display=0;
	  		  	 imp=0;
 	  	
 	  	   break;	  	
//--------------------------------------------------------------------------	
 	  	case e_check_Dac1o:
 	  	
 
 	      	//--- check Dac1o--0.4V
//				M_RTC_display++;
				M_Avg_16bit_result = Measurement_Daco();
				DC_data_buf[imp++]=M_Avg_16bit_result;
				if(imp>3)
				  imp=0;
				if(M_RTC_display>12)
				{
					
					    M_Lbuf0=0;
					    for(imp=0;imp<4;imp++)
					       M_Lbuf0+=DC_data_buf[imp];						
						M_Lbuf0 /= 4;	
						if(M_Avg_16bit_result>M_Lbuf0)
						  	M_Excitation_Offset=M_Avg_16bit_result-M_Lbuf0;
						else
						    M_Excitation_Offset=M_Lbuf0-M_Avg_16bit_result;
						if(M_Excitation_Offset>100)
						{
		      				init_Error_Task(3);//------------------------------------------------------------3 --- check Daco		      		
			      			break;														
						}

						SET_PIN_OP1N1_OP1N();//检测电极3、4的电流值
					    SET_PIN_OP1S0_OP1O();
					    SET_PIN_OPnP_DAC1O(1);
						Measurement_Op1n1_Op1s1();//DC
						SET_PIN_VG0_GND();
						SET_PIN_VG1_GND();
						up_pin4 =1;//血糠试纸插入脚拉高，高电平可能会影响其它脚！			
						_pac3 =1;//
						_papu3 =0;//
					    SET_OPAn_POWER(1,POWERON);
						fun_ADCStart();
						SET_UARTn_BAUDRATE_19200(0);	// 波特率設定
					    mi=0;
					    imp=0;
					    M_TaskBuf0=e_check_used;
										   			
					
				}  


 	  		break;
//--------------------------------------------------------------------------
 	  	case e_check_used:
				//--- DC量測+电流
			if(SDKADCSourceData.flag.b.IsReady)
			{
				SDKADCSourceData.flag.b.IsReady =0;
				 avg_ad2= SDKADCSourceData.data.ADCData >> 16;
				 if(avg_ad2<0)
					avg_ad2=0;					
				M_Current = ADCtoCurrent_Convert(avg_ad2,C_ResOP1N1);
				//M_Current/=1000;
#ifdef G777G_TEST
					M_Current_use_log = M_Current;
#endif
				if(M_Current>sys_data.used_curren)//is used
				{
						fun_StripModuleAllOpen2();
						SET_PIN_VG1_GND();
						_papu4 =1;//血糠试纸插入脚拉?
						LCD_Clear(OFF);
						init_Error_Task(4);//------------------------E-U----------------------------------4-- check 100K into factory mode 
						temp=0;
						break;
				}
				else
				{
						M_TaskBuf0=e_check_temp;
						M_RTC_display =0;
						temp=0;
						break;

				}
			}
 	  		break;
//--------------------------------------------------------------------------
 	  	case e_check_temp:
 	  	  //  	LED=0;
// 	  	    M_RTC_display++;
 	      	if(M_RTC_display <2)
	      	{
				M_Temperature = Measurement_Temp();
				
//		  		avg_ad2=M_Temperature;	
//		  		avg_ad2-=Calibration.CAL.CAL_temp_offset;
//		  		M_Temperature=avg_ad2;	
#if (NO_TEMPER_CORR==0)

				if(Calibration.CAL.temp_offset>0)
				  	M_Temperature-=	Calibration.CAL.temp_offset;	  			
				else
				    M_Temperature+= abs(Calibration.CAL.temp_offset);
#endif
				if(set_temp_25==0x55)
				  M_Temperature = 250;

		        //if((M_Temperature < 100) || (M_Temperature > 400))
				if((M_Temperature < 10) || (M_Temperature > 400))
				{

							init_Error_Task(5);//------------------------------------------------------------	5 get Tempture vaule
			      		
			      			break;

				}
	      		LCD_Clear_Buff(OFF) ;			
	      		Ibuf0 = M_Temperature;
	      		lcd.meas.Bit.BigNum_DP =1;
	      		ShowDec_BigNum(Ibuf0);
//	      		lcd.meas.Bit.Temperature =1;
	      		F_LcdUpdate =1;	

				SET_PIN_OP1N1_OP1N();//检测电极3、4的电流值
				SET_PIN_OP1S0_OP1O();
				SET_PIN_OPnP_DAC1O(1);
				Measurement_Op1n1_Op1s1();//DC
				SET_PIN_VG0_GND();
				SET_PIN_VG1_GND();
				up_pin4 =1;//血糠试纸插入脚拉高，高电平可能会影响其它脚！			
				_pac3 =1;//
				_papu3 =0;//
				SET_OPAn_POWER(1,POWERON);
				fun_ADCStart();
				mi=0;
				imp=0;
		     	M_TaskBuf1 =0;
		     	M_No_Active_Cnt =0;	
			    F_LcdUpdateBuf=0;
#if (voice_en==1)			
				vice_data_buf[vice_pointer_in++]=0x66;	//百芝堂    
				vice_data_buf[vice_pointer_in++]=0x67;	//提醒你
				vice_data_buf[vice_pointer_in++]=0x2B;	//请将血液靠到试纸血液吸入口
#endif
//		    #ifdef G777G_TEST
//		    	_emi=0;
//		    	print_str("\r\nstart testing..............\r\n");
//		    	_emi=1;
//		    #endif			

	      	}
	      	else if(M_RTC_display >=60)
	      	{	      	
	      				//--- display temperture
				LCD_Clear_Buff(OFF) ;
  	     		M_TaskBuf0 =e_Start_detection;  
				M_RTC_display =0;
  	     		memkey=0;  	
				lcd_scan_index = 0;
				Start_Detection_flag= 1 ;
	      	}	  	
 	  		break;
//--------------------------------------------------------------------------
	  	
	  	//--- start check measurement limit ----
	  	case e_Start_detection://启动门槛检测
	  	{ 
				if(SDKADCSourceData.flag.b.IsReady)
				{
					SDKADCSourceData.flag.b.IsReady =0;
					 avg_ad2= SDKADCSourceData.data.ADCData >> 16;
					 if(avg_ad2<0)
						avg_ad2=0;					
					M_Current = ADCtoCurrent_Convert(avg_ad2,C_ResOP1N1);
					//M_Current/=1000;
#ifdef G777G_TEST
					M_Current_start_log = M_Current;
#endif
					if(M_Current>sys_data.start_curren)//启动测量
					{
						#if 0
						fun_ADCStop();	
						//-----------------------满血初始化------------------------------
						SET_PIN_OP1N1_OP1N();
					    SET_PIN_OP1S0_OP1O();
					    SET_PIN_OPnP_DAC1O(1);
						Measurement_Op1n1_Op1s1();//DC
						SET_PIN_VG0_GND();
						SET_PIN_VG1_GND();
						up_pin4 =1;//血糠试纸插入脚拉高，高电平可能会影响其它脚！			
						_pac3 =1;//
						_papu3 =0;//
					    SET_OPAn_POWER(1,POWERON);
						fun_ADCStart();
						#endif
						//LCD_Clear_Buff(OFF);
						F_Beep_Shortx1 =1;
						#if (voice_en==1)
						voice_reset();
						vice_data_buf[vice_pointer_in++]=(78);//滴
						#endif
						//LCD_Clear(OFF);
						LCD_Clear1(OFF);
						dis_beat();
						imp=0;	
						mi=0;
						M_TaskBuf1 =0;
						M_No_Active_Cnt =0;	
						M_RTC_display = 0;
						Start_Detection_flag= 0 ;
						M_TaskBuf0=e_ckfull_blood;
						break;
					}
					
				//	SET_PIN_SINO1_OPEN();
				//	SET_PIN_VG0_GND();
				//	_papu4 =1;
				//	delay(1);	
					if(blood_strips_pin4)
					{
							Start_Detection_flag= 0 ;
					    	init_Error_Task(9);
					    	break;
					}	
				//	SET_PIN_VG0_OPEN();	
				//	_papu4 =0;						
				//	SET_PIN_SINO1_SINOUT();					
					delay(1);
					
					
				//LED = ~LED;
				//	GPIO_led=~GPIO_led;//_pd6----test time--about 160ms						  
				//}		
				//Set_HCT_Adc_Channel(M_Cbuf0);
				    
			}	
			//--- display date & time
			if(F_LcdUpdateBuf ==0)
			{
				//--- display Month & Day
				//Lcd_Month_Day_Process(M_Month,M_Days);
				//--- display Hour & Minutes
				//Lcd_Clock_Process(M_Hour,M_Minutes);
			  	//--- display unit
			  	Lcd_Unit();		
//				//--- display "P9"
//				Lcd_ControlOption();
				
				//if(F_ControlOption)
				//	LCD_BitSetOut( LcdBit_Strip_StripBase, ON ) ;//显示试纸版代表质控						
				//else
				//	LCD_BitSetOut( LcdBit_Strip_StripBase, OFF) ;		
				
				
				//--- strip
			//	lcd.strip.Bit.StripBase =1;	//on "P10"
				//--- display strip type
		//		ShowDec_BigNum(M_Strip_Type);
///				ShowDec_BigNum(auto_code);				
				F_LcdUpdateBuf =1;
				F_LcdUpdate =1;
			}
			
			//--- display col flash
			if(F_500ms_LCD)
			{
				//if(lcd.unit.Bit.TimeColon != 0)
				//	LCD_BitSetOut( LcdBit_Unit_TimeColon, OFF) ;
				//else
				//	LCD_BitSetOut( LcdBit_Unit_TimeColon, ON ) ;
				if(lcd.strip.Bit.Blood != 0)
					LCD_BitSetOut( LcdBit_Strip_Blood, OFF) ;
				else
					LCD_BitSetOut( LcdBit_Strip_Blood, ON ) ;
				FlashTimeCon++;
				if(FlashTimeCon%2)
				{
					if(FlashTimeFlag)
					{
						FlashTimeFlag=0;
						Lcd_Month_Day_Process(M_Month,M_Days);
						lcd.unit.Bit.AM =0;
						lcd.unit.Bit.PM =0;
						lcd.unit.Bit.TimeColon =0;
					}
					else
					{
						FlashTimeFlag=1;
						Lcd_Clock_Process(M_Hour,M_Minutes);
						lcd.unit.Bit.TimeColon =1;
						lcd.unit.Bit.DateSlash =0;
					}
					
					lcd_scan_index = 0;
					F_LcdUpdate =1;
				}
				F_500ms_LCD =0;

				
			}
			
   //   		--- remove strip
				//--- 試紙移除
						
#ifdef G777G_TEST
				if((setkey ==2 || memkey ==2))
				{
					//setkey = 0;
					//memkey = 0;
					_emi=0;
					print_str("\r\n check_start:I(nA) ");	
					print_double(M_Current_start_log);	
					_emi=1; 
				}
#endif

			
			//--- Select Normal & Control
      		if(memkey == 1)
      		{
	      		//if(memkey==1)
	      		{	
					//--- update lcd
				memkey=0;
				//Short_beep();
				F_Beep_Shortx1 =1;
				#if (voice_en==1)
				voice_reset();
				vice_data_buf[vice_pointer_in++]=(78);//滴
				#endif
				meals++;
				if(meals>2)
		     	   meals=0;
		     	if(meals==1)//餐前
		     	{
		     		lcd.meas.Bit.AftMeal=0;		     								
	            	lcd.meas.Bit.BefMeal=1;
		     	}
		     	else if(meals==2)//餐后
		     	{
		     		lcd.meas.Bit.AftMeal=1;		     								
	            	lcd.meas.Bit.BefMeal=0;		     		
		     	}
		     	else
		     	{
		     		lcd.meas.Bit.AftMeal=0;		     								
	            	lcd.meas.Bit.BefMeal=0;			     		
		     	}
		     		
		
	      		}
	      		   
				F_LcdUpdateBuf =0;	      		     			
	      		//memkey=0;  
	      		    						
      		}		
    		
      		if(memkey==2)
      		{
				memkey = 0;
				F_ControlOption =~F_ControlOption;

//	            lcd.meas.Bit.ControlSoultion=0;	
#if (voice_en==1)				
					voice_reset();								
					vice_data_buf[vice_pointer_in++]=(78);//滴
					if(F_ControlOption)
						vice_data_buf[vice_pointer_in++]=58;//质控液模式						
					else
						vice_data_buf[vice_pointer_in++]=59;//测试模式						  
#endif
//	            lcd.meas.Bit.ControlSoultion=0;						
										
				//--- update lcd
				F_Beep_Shortx1 =1;
				//Short_beep();
				if(F_ControlOption)
				{
					lcd.meas.Bit.ControlSoultion=1;		
				}
				else
				{
					lcd.meas.Bit.ControlSoultion=0;	
				}
				F_LcdUpdateBuf =0;	
      		}
      		
			break;
	  	}
	  	
//--------------------------------------------------------------------------	  	
	  	case e_ckfull_blood:	//ck   	MeasureFullBlood

			if(SDKADCSourceData.flag.b.IsReady)
			{
						SDKADCSourceData.flag.b.IsReady =0;
																
					//	M_Impedance_data[M_Cbuf0++] = SDKADCSourceData.data.ADCData >> 16;
						
				//			M_Lbuf0 = SDKADCSourceData.data.ADCData >> 16;
//							DC_data_buf[mi++]=SDKADCSourceData.data.ADCData >> 16;;
//							if(mi>3)
//							  mi=0;
//							M_Impedance=0;								
//							for(imp=0;imp<4;imp++)
//							   M_Impedance+=DC_data_buf[imp];
//							M_Impedance/=4;
	
							 avg_ad2= SDKADCSourceData.data.ADCData >> 16;
							 if(avg_ad2<0)
								avg_ad2=0;					
														
//							_emi=0;
//							print_bcd(M_Lbuf0);
//							print_str("\r\n");	
//							_emi=1; 
													
//							
//							GPIO_led=~GPIO_led;//_pd6----test time--about 160ms 

							M_Current = ADCtoCurrent_Convert(avg_ad2,C_ResOP1N1);
							//M_Current/=1000;
#ifdef G777G_TEST
							M_Current_full_log = M_Current;
#endif
							if(M_Current>sys_data.full_curren)// Sampling completed:	
							{

								M_TaskBuf1 =0;
								
								M_No_Active_Cnt =0;
								//--- clrar time count
								//_ct0on =0;
								M_Main_cnt =0;
								M_Main_Cal_Cnt =0;
																  
								//-----------------------AC初始化------------------------------
								
								intit_Impedance();	
								up_pin4 =1;//血糠试纸插入脚拉?	
								SET_PIN_VG1_GND();						
								M_Cbuf0 =0; 
								Set_HCT_Adc_Channel(M_Cbuf0);

								dis_nub2(5);

								//	
								//	F_LcdUpdate=1;						

								imp=0;
								mi=0;

								//M_Ibuf0=600;//显示值

								work_time=0;//6秒计时开始
								M_Main_cnt = 0;
								F_MainTimerOut=0;	 //10ms 	
								#if ACFG_OSC_EN==1
								_pt0on = 0;
								 work_time=0;//6秒计时开始
								 M_Main_cnt = 0;
								_ptm0al = 0x00ff & 328;     //;32.768kHZ
								_ptm0ah = (0xff00 & 328) >> 8;	//;TIMER0 10 BIT TIMER  =328 X 30.5176uS = 10.0097ms
								_pt0on = 1;
								#endif
								M_RTC_display = 0;
								work_time_buf[0]=0; //第一笔数据从0开始。
								count=1;	
								M_TaskBuf0=e_Impedance_measurement;

								break;
		
							}							
			
																
			}

			if(M_RTC_display>=300) //wait 2s check full blood
			{
				init_Error_Task(7);//------------------------------------------------------------	full blood error
				break;
			}
			  	
	  		break;
//--------------------------------------------------------------------------
		//--- start measurement process2 display value ----	  	
	  	case e_Impedance_measurement:
	  	{

					
					//--- 試紙移除
					//if(blood_strips_pin4)
					//{
					//    	init_Error_Task(8);
					//    	break;
					//}
									
					if(((600-work_time) % 100 == 0) && ((600-work_time) !=0))//--- 顯示倒數
					{
						dis=(unsigned char)((600-work_time) / 100-1);

						dis_nub2(dis);
					}
					//--- AC量測+取阻抗 
					if(SDKADCSourceData.flag.b.IsReady)
					{
						SDKADCSourceData.flag.b.IsReady =0;
						//---												
						M_Impedance_data[imp++] = SDKADCSourceData.data.ADCData >> 16;
		
						M_Cbuf0++;
						if(M_Cbuf0 >3)	
						{
							M_Cbuf0 =0;	
							work_time_buf[count++]=work_time;//记录时间
					//		work_time=0;
							
							//M_Impedance = Impedance_Compute(&M_Impedance_data[0]);//---------------------Impedance	
						    //sys_data.Impedance = M_Impedance ;
						   // _emi=0;
							//print_str("\r\n Impedance(k): ");							
							//print_double(sys_data.Impedance);	
							//print_str("   time: ");
							//print_long(work_time);
							//_emi=1;														
							//imp=0;							

							
						//LED = ~LED;
						//	GPIO_led=~GPIO_led;//_pd6----test time--about 160ms						  
						}		
						Set_HCT_Adc_Channel(M_Cbuf0);
						    
					}
					if(work_time>=100)
					{
					     	M_TaskBuf0 =e_DC_Silence;
					     	M_TaskBuf1 =0;
					   //  	M_No_Active_Cnt =0;		
							M_RTC_display =0;					     	
					     	
					     	
//-----------------------DC初始化------------------------------
					  	
							
							fun_ADCStop();
							SET_SINE_OFF();
							SET_PIN_SINO1_OPEN();//这部分不处理会影响校正模式与测量模式下AD值差30个。
							SET_PIN_SINO2_OPEN();
				            SET_PIN_RF2_OPEN();
							SET_PIN_RF1_OPEN();							
							
							SET_OPA34_POWER(POWEROFF);
							fun_StripModuleAllOpen();
							SET_PIN_OPnP_OPEN(1);
							SET_PIN_OPnP_OPEN(2);
							SET_PIN_OP3P_OPEN();
							SET_PIN_RF1_OPEN();
							SET_PIN_SINI_OPEN();
							
 	          				_pac3 =0;//
							_pa3 =0;//	  								
							
//							InitADC_Op1n1_Op1s1();
//							
//						
//						    //--- set vg0
//						    SET_PIN_VG0_GND();
//						    up_pin4 =1;
//						    //--- Start adc
//						    fun_ADCStart();	
//						    //--- set vg0
						    SET_PIN_VG0_GND();
							SET_PIN_VG1_GND();	
						//	LCD_Clear_Buff(OFF) ;
						

							M_RTC_display=0;						
						
					}
					
					
					

			break;	
		}
		
		case e_DC_Silence://wait 2.5s
		{
			
		  		//if(M_Ibuf0 !=0)
		  		//	M_Ibuf0--;
		  		//M_Ibuf1 = M_Ibuf0;
				if(((600-work_time) % 100 == 0) && ((600-work_time) !=0))//--- 顯示倒數
				{
					//--- display countdown
//						ShowDec_MeasDownCount((unsigned int) M_Ibuf1 / 100-1);
//						F_LcdUpdate =1;
					dis=(unsigned char)((600-work_time) / 100-1);

					dis_nub2(dis);
			
					
				}	

				//--- 試紙移除
				if(blood_strips_pin4)
				{
				    	init_Error_Task(9);
				    	break;
				}			
													
			
				if(work_time >= 350)//
				{
						InitADC_Op1n1_Op1s1();
						
					
					    //--- set vg0
					    SET_PIN_VG0_GND();
					    up_pin4 =1;
					    //--- Start adc
					    fun_ADCStart();	
					    //--- set vg0
					    SET_PIN_VG0_GND();
						SET_PIN_VG1_GND();						
					
				     	M_TaskBuf0 =e_DC_check;
				     	M_TaskBuf1 =0;
				   //  	M_No_Active_Cnt =0;		
						M_RTC_display =0;								
				}			
			
			
		}		
		break;	
		
		case e_DC_check:
		{
			
			M_RTC_display=0;
			send_ok=1;
		    while(send_ok)
		    {
		    
						if(F_MainTimerOut)
						{
							//	_pd6=~_pd6;//LED
				
							F_MainTimerOut =0;
				
						//	 M_RTC_display++;
					  		//---Dec Count
					  		GCC_CLRWDT();
					  		//if(M_Ibuf0 !=0)
					  		//	M_Ibuf0--;
					  		//M_Ibuf1 = M_Ibuf0;
							if(((600-work_time) % 100 == 0) && ((600-work_time) !=0))//--- 顯示倒數
							{
	
								dis=(unsigned char)( (600-work_time) / 100-1);
		
								dis_nub2(dis);
						
								
							}			  		
					  		
	
							//--- 試紙移除
							if(blood_strips_pin4)
							{
							    	init_Error_Task(9);
							    	break;
							}			
						}							  		
	//					//--- DC取值
						if(SDKADCSourceData.flag.b.IsReady)//---给个采样缓冲
						{
							
							DC_data_buf[0]= SDKADCSourceData.data.ADCData >> 16;
							SDKADCSourceData.flag.b.IsReady=0;

							if(work_time%10 == 0 && old_work_time!=work_time)
							{
								old_work_time = work_time;
								proportion[0]=DC_data_buf[0];

								proportion[0]/=Calibration.CAL.k_value;

								M_Lbuf0=(unsigned long )proportion[0];


								M_Current = ADCtoCurrent_Convert(M_Lbuf0,C_ResOP1N1);
								sys_data.Current = M_Current;
								sys_data.Current/=1000;
								//#ifdef G777G_TEST
								//print_str("\r\n DC I(uA): ");								
								//print_double(sys_data.Current);	
								//#endif
							}

						}
						
						if(work_time>=600)
			  			{
							proportion[1]=DC_data_buf[0];
							M_TaskBuf0 = e_calculation;
							fun_ADCStop();
							//--- set daco1 to gnd
							fun_DACnInit(1,DACnOGND);

							//--- disable opa
							SET_OPAn_POWER(1,POWEROFF);
							SET_OPAn_POWER(2,POWEROFF);
							SET_OPA34_POWER(POWEROFF);
							SET_PIN_OPnP_OPEN(1);
							SET_PIN_OPnP_OPEN(2);
							SET_PIN_OP3P_OPEN();
						   	send_ok=0;		
			  			}
			}
				break;	
		}
//--------------------------------------------------------------------------
		case e_calculation:
		{

						//fun_StripModuleAllOpen();
																		
						proportion[1]/=Calibration.CAL.k_value;
						
						M_Lbuf0=(unsigned long )proportion[1];

			      	
			      		M_Current = ADCtoCurrent_Convert(M_Lbuf0,C_ResOP1N1);


						_emi=0;
						
						GCC_CLRWDT();
						/*
						0,1,2,3...................20,21,22,23,24,25
						每4个数据为一组，取最后一组的4个数据
						如imp为25  ，最后需要取的数据是20,21,22,23
						25%4=1 
						25-1-4=20
						*/
						i=imp%4;
						imp = imp-i-4;
						M_Impedance = Impedance_Compute((signed int*)&M_Impedance_data[imp]);//---------------------Impedance,取最后一组AC数据（一组数据4个值）
						GCC_CLRWDT();
						load_autoCode_data();
						_emi=1;
						if(M_Impedance>sys_data.err_Impedance)		//阻抗值较大血样异常
						{
							LCD_Clear(OFF);
							init_Error_Task(10);
							break;
						}

												
		               sys_data.Temperature=M_Temperature;
		               sys_data.Temperature/=10;
		               
		               sys_data.Current=M_Current;
		               sys_data.Current/=1000;
		               
		               sys_data.Impedance=M_Impedance;  
					   
//						if(F_Set_No_Tempera_Comp)
//						{
//							if(F_ControlOption)
//							get_glucose_ctr(0);
//							else
//							get_glucose(0);//0为无温补系数	               
//							untemp_glucose=sys_data.mmol;
//						}
//						else
						{
							if(F_ControlOption)
								get_glucose_ctr(1);
							else
								get_glucose(1);//1为有温补系数
						}

						if(sys_data.mg < 0)
						   sys_data.mg =0; 
						if(sys_data.mg>601)
						   sys_data.mg=601;	 
						
						if(sys_data.mmol < 0)
						   sys_data.mmol =0; 
						if(sys_data.mmol>33.3)
						   sys_data.mmol=33.3;	 


//		               F_Set_No_Tempera_Comp = 0;
				       M_GM_data=(signed int)(sys_data.mg+0.5);

									  			
//---------------------------------------------------------------							
						GCC_CLRWDT();	
						Lcd_Glucose(M_GM_data);	
						LCD_BitSetOut( LcdBit_Strip_Blood, OFF) ;
						LCD_BitSetOut( LcdBit_Unit_TimeColon, ON ) ;
						if(M_GM_data > 240)//閰綋鏄剧ず
						{
							lcd.unit.Bit.Ketone=1;
						}
						if(meals==1)//
				     	{
				     		lcd.meas.Bit.AftMeal=0;		     								
			            	lcd.meas.Bit.BefMeal=1;
				     	}
				     	else if(meals==2)//
				     	{
				     		lcd.meas.Bit.AftMeal=1;		     								
			            	lcd.meas.Bit.BefMeal=0;		     		
				     	}
				     	else
				     	{
				     		lcd.meas.Bit.AftMeal=0;		     								
			            	lcd.meas.Bit.BefMeal=0;			     		
				     	}
						//--- display Month & Day
						Lcd_Month_Day_Process(M_Month,M_Days);
						//--- display Hour & Minutes
						Lcd_Clock_Process(M_Hour,M_Minutes);
						LCD_ScanOut() ;	
						#if (voice_en==1)
						voice_reset();
						vice_data_buf[vice_pointer_in++]=(78);//滴
						voice_Blood_glucose(M_GM_data);
						#endif
//---------------------------------------------------------------						
#ifdef G777G_TEST								
							print_str("\r\n\r\n");	

							print_str("\r\n check_used:I(nA) ");	
							print_double(M_Current_use_log);	
								
							print_str("\r\n check_start:I(nA) ");	
							print_double(M_Current_start_log);	
							
							print_str("\r\n check_full:I(nA) ");	
							print_double(M_Current_full_log);	
							
							print_str("\r\n\r\n T(c): ");							
							print_double(sys_data.Temperature);														

							print_str("\r\n I(uA): ");								
							print_double(sys_data.Current);																				

							print_str("\r\n Impedance(k): ");							
							print_double(sys_data.Impedance);	

							print_str("\r\n used_trigger_current(nA): ");							
							print_double(glucose_auto_code[2].a_T);	

							print_str("\r\n trigger_current(nA): ");							
							print_double(glucose_auto_code[2].b_T);

							print_str("\r\n full_blood_current(nA): ");							
							print_double(glucose_auto_code[2].c_T);

							print_str("\r\n error Impedance(K): ");	
							print_double(glucose_auto_code[2].b_I);	
#if 0							
							///////////////////////////////////
							print_str("\r\n\r\n\r\n  k_value: ");							
							print_double(Calibration.CAL.k_value);
							
							print_str("\r\n  2_0v value: ");
							print_long(Calibration.CAL.pvref_2_0V);
							
							print_str("\r\n  0_35 L_value: ");
							Ibuf0=Calibration.CAL.afeda1_0_35V<<4;	
							print_long(Ibuf0%256);
							print_str("\r\n  0_35 H_value: ");
							print_long(Ibuf0/256);
							print_str("\r\n\r\n\r\n");	
							////////////////////////////////
#endif
						
							
							print_str("\r\n\r\n  unT_mmol: ");							
							print_double(untemp_glucose);
							print_str("\r\n  unT_mg: ");								
							print_double(untemp_glucose*18);							
							

							print_str("\r\n\r\n  mmol: ");							
							print_double(sys_data.mmol);
							print_str("\r\n  mg: ");								
							print_double(sys_data.mg);	
							
							work_time=M_GM_data;
							
							print_str("\r\n\r\n  lcd_mol: ");
							work_time*=10;
							work_time+=9;
							work_time/=18;
							
							if(work_time/100)
							{
								print_long(work_time/100);
							}
							
							print_long(work_time/10%10);
							Send_data('.');	
							print_long(work_time%10);
							
							
							print_str("\r\n  lcd_mg: ");														
							print_long(M_GM_data);							
							
							print_str("\r\n--------------------\r\n");										
							GCC_CLRWDT();	
							_emi=1;

#endif							
	
//---------------------------------------------------------------			  													
						if(F_ControlOption ==0)	
							{
								//--- Save measure data	
								Store_measurement_data();//-------------------------------------------------------------data-
								Save_RtcTime();
							}
//---------------------------------------------------------------			  			
			  								  			

//			  							    		
//						work_time=0;
//						while(work_time<2)GCC_CLRWDT();		//等一会，否则会乱码。
						
									    		
			    		goto_next_case();
				    		

				    		
							SET_UARTn_BAUDRATE_9600(0);		    										
							F_Beep_Shortx1 =1; 	//--- Beep on			    		
				    		M_TaskBuf0 = e_ShowGlucoseResult;
//#if defined(G777G_TEST) || defined(G_426_1)			//测试模式下打印值完成后  ，直接输出结果不做传输
							M_TaskBuf0 = e_ShowGlucoseResult;
							break;
//#endif				    				    		
				    		if(F_ControlOption ==0 && F_Set_Transmit==0)
				    		{
				    		  M_TaskBuf0 = e_gsm_start;
				    		 
				    		  //--- Beep on
							  //F_Beep_Shortx1 =0; 
				    		}
				    		F_Set_Transmit=0;	
				    			
				    		M_TaskBuf1 = 0;	
				    		GSM_Signal=0;	
				    		

						   lcd.send.Bit.Fail=0;
						   lcd.send.Bit.OK=0;
						  // lcd.send.Bit.Ing=0;
						   M_RTC_display=0;
		    		
			 				break;		
		}			
//--------------------------------------------------------------------------
		case e_gsm_start:
					M_RTC_display++;
#if (voice_en==1)				
					if(vice_wait_play_complete(200)==0)
					break;
#endif
					if(M_RTC_display<50)
					break;
					send_ok=0;
					if(starting_gsm())
					{
						M_RTC_display=0;
						M_TaskBuf0 = e_gsm_out;
						
					}
					else
					{
						   mymax=	unsend_data[10].year*10;
						   mymax+=unsend_data[10].month;
						   index=unsend_data[10].month;	
						   k=0;						
						
							M_UART_RxIndex=0;
							gsm_loop=0;
							memset((unsigned char *)M_UART_RxFIFO,0,128);						
							M_TaskBuf0 = e_gsm_send;
					}
					

			
				    break;
//--------------------------------------------------------------------------
		case e_gsm_send:
					
					for(m=0;m<mymax;m++)
					{
					
						if(index!=0)
						   index--;
						else
						   index=9;
						if(	unsend_data[index].is_send)
						{	
							 M_TaskBuf1=0;	
							 M_RTC_display=0;				   
							 if(send_gsm_data())
							 {
								M_RTC_display=0;
								M_TaskBuf0 = e_gsm_out;	//异常退出。
								k=1;
								break;					 	
							 	
							 }
						}

						
					}
					if(k==0)
					{
						M_RTC_display=0;//正常退出
						M_TaskBuf0 = e_gsm_out;	
						
					}
			
				    break;									

//--------------------------------------------------------------------------							
		case e_gsm_out:
					
//------------------------------------------------------------------
						//lcd.send.Bit.Ing=0;	
                        if(send_ok)
                          lcd.send.Bit.OK=1;
                        else
                          lcd.send.Bit.Fail=1;
                          					 
						setRssi();
						lcd.ant.Bit.Ant=1;					 
						if(M_RTC_display==1)//AT+QIDEACT=1
						{
								    		
							M_UART_RxIndex=0;
							gsm_loop=0;
							memset((unsigned char *)M_UART_RxFIFO,0,128);
							print_str("AT+QIDEACT=1\r\n");																		
						    _emi=1;									
						}
					
						else if(M_RTC_display>100 ||strstr((const char *)M_UART_RxFIFO,(const char *)"OK\r\n"))
						{
							memset((unsigned char *)M_UART_RxFIFO,0,128);
							print_str("AT+QPOWD\r\n");																		
						    _emi=1;	
							goto_next_case();	
							M_TaskBuf0 = e_gsm_out2;
								    		//--- Beep on
						    F_Beep_Shortx1 =1; 						    
						    
						}

//						
//						if(M_RTC_display>300 && blood_strips_pin4 )//延时3秒关机---这里只针对血糖试纸做处理，血酮或其它试纸要另外增加判断！
//						{
//						      _pb2=0;//powern
//						      _pb3=1; //rest							
//								goto_next_case();	
//								M_TaskBuf0 = e_ShowGlucoseResult;
//									setRssi();
//									lcd.ant.Bit.Ant=1;			    					      	
//						      	M_TaskBuf1=0;								
//							
//						}

						if(F_500ms_LCD)
						{
							F_LcdUpdate =1;  	
							F_500ms_LCD =0;		
						}						
						
						
						
			
				    break;	
//------------------------------------------------------------------
				    
				    
		case e_gsm_out2:
					

						
						if(M_RTC_display>300)//延时1秒关机---这里只针对血糖试纸做处理，血酮或其它试纸要另外增加判断！
						{
						      _pb2=0;//powern
						      _pb3=1; //rest							
								goto_next_case();	
								M_TaskBuf0 = e_ShowGlucoseResult;
		    					      	
						      	M_TaskBuf1=0;
						      	break;								
							
						}

						if(F_500ms_LCD)
						{
							F_LcdUpdate =1;  
							

							if(lcd.unit.Bit.TimeColon != 0)
								LCD_BitSetOut( LcdBit_Unit_TimeColon, OFF) ;
							else
								LCD_BitSetOut( LcdBit_Unit_TimeColon, ON ) ;					
									
							F_500ms_LCD =0;		
						}						
						
			//     		BatteryCheckProcess();
			//     		
			//	  //   	--- Clear lcd 9,10,11
			//	     	Clr_BigString();
				  		
						//--- display Month & Day
						Lcd_Month_Day_Process(M_Month,M_Days);
						//--- display Hour & Minutes
						Lcd_Clock_Process(M_Hour,M_Minutes);

						if(F_500ms_LCD)
						{
							if(lcd.unit.Bit.TimeColon != 0)
								LCD_BitSetOut( LcdBit_Unit_TimeColon, OFF) ;
							else
								LCD_BitSetOut( LcdBit_Unit_TimeColon, ON ) ;					
							F_500ms_LCD =0;
								F_LcdUpdate =1;   
			
							
						}			
					
						
			
				    break;	
				    				    									
//--------------------------------------------------------------------------		
		//--- start measurement process3 display value ----
	  	case e_ShowGlucoseResult:
	  	{
			//---憿舐內銵?蝟???
										
				SET_OPAn_POWER(1,POWEROFF);
				SET_OPAn_POWER(2,POWEROFF);
				SET_OPA34_POWER(POWEROFF);
				SET_PIN_OPnP_OPEN(1);
				SET_PIN_OPnP_OPEN(2);
				SET_PIN_OP3P_OPEN();
				fun_StripModuleAllOpen();
				//--- adc disable
				fun_ADCStop();
		  		//--- Dacvref disable
		  		if(!C_LCD4V_Enable)
					fun_DACVREFInit(POWEROFF);
				//--- set daco1 to gnd
				fun_DACnInit(1,DACnOGND);
				
      			//--- opa1 "s1" on &??"s0" on
      			_opa1ofm =0;
      			_opa1rs =0;
      			
      			//--- opa1 "s5" on &??"s4" on
      			_opa2ofm =0;
      			_opa2rs =0;			
			
			
	    		M_TaskBuf0 = e_idle;
	    		M_TaskBuf1 = 0;
	    		M_Cbuf0 =0;
	    		M_Cbuf1 =0;
	    		M_RTC_display =0;
		        M_No_Active_Cnt =0;
		        
			
				//--- Lcd update
				F_LcdUpdate =1;	
						
//				strips_pin4_dir =1;//血糖试纸侦测脚设置输入
//				up_pin4 =1;//上接使能

			    SET_PIN_VG0_GND();
				SET_PIN_VG1_GND();
				F_LcdUpdateBuf=0;
				//---set sw
//				P_HDL_SW =0;
				//--- set daco1 to gnd
				SET_PIN_VG1_GND();
			    //--- 
				_pa3 =0;
				_pac3 =1;
				_papu3 =1;
				blood_strips_pin4 =0;
				
				strips_pin4_dir =1;
				up_pin4 =1;				
				
						       	
	  		break;  //case 4 end
	  	}
		
//--------------------------------------------------------------------------
		//--- start measurement process3 display value ----
		case e_idle:
		{
     		//--- check strip remover
     		BatteryCheckProcess();
     		Lcd_Glucose(M_GM_data);	
						//LCD_ScanOut() ;	
	  //   	--- Clear lcd 9,10,11
	   //  	Clr_BigString();
	  		
			//--- display Month & Day
			//Lcd_Month_Day_Process(M_Month,M_Days);
			//--- display Hour & Minutes
			//Lcd_Clock_Process(M_Hour,M_Minutes);
//			ShowDec_HourMin(M_Impedance * 100);
//			lcd.unit.Bit.TimeColon =1;	//on "Col"	
			if(F_500ms_LCD)
			{
				//if(lcd.unit.Bit.TimeColon != 0)
				//	LCD_BitSetOut( LcdBit_Unit_TimeColon, OFF) ;
				//else
				//	LCD_BitSetOut( LcdBit_Unit_TimeColon, ON ) ;	
				FlashTimeCon++;
				if(FlashTimeCon%2)
				{
					if(FlashTimeFlag)
					{
						FlashTimeFlag=0;
						Lcd_Month_Day_Process(M_Month,M_Days);
						lcd.unit.Bit.AM =0;
						lcd.unit.Bit.PM =0;
						lcd.unit.Bit.TimeColon =0;
					}
					else
					{
						FlashTimeFlag=1;
						Lcd_Clock_Process(M_Hour,M_Minutes);
						lcd.unit.Bit.TimeColon =1;
						lcd.unit.Bit.DateSlash =0;
					}
					F_LcdUpdate =1;   
				}
				F_500ms_LCD =0;

				
			}			
			if(F_ControlOption)
				LCD_BitSetOut( LcdBit_Meas_Ctl, ON ) ;//显示试纸版代表质控						
			else
				LCD_BitSetOut( LcdBit_Meas_Ctl, OFF) ;			
				    		
     		
			if(blood_strips_pin4)           //strip quit check
			{
#if (voice_en==1)		
				if(vice_wait_play_complete(150)==0)
				break;
#endif				
	    		M_TaskBuf0 = e_Exit_mode;
	    		M_RTC_display =0;
	    		M_No_Active_Cnt =0;
			}
			
			
			

			break;
		}
//--------------------------------------------------------------------------
		//--- Factory mode
//		case e_Factory_mode:
//		{
//			switch(M_TaskBuf1)
//			{
//				//--- display strip current 
//				case 0:
//				{
////					M_RTC_display++;		//base 10ms
//	      			if(M_RTC_display ==1)
//	      			{
//	      				M_Avg_16bit_result = Measurement_Op1n1_Op1s1();
////			      		Ibuf0 = M_Avg_16bit_result;
////			      		Ibuf0 +=  M_Excitation_Offset;
//			      		M_Current = ADCtoCurrent_Convert(M_Avg_16bit_result,C_ResOP1N1);
//			      		//M_Current = Cal_MeasCurr(Ibuf0);
//			      		//M_Current /= 10 ;
//						
//						ShowDec_BigNum(M_Current / 10);
//						
//						//--- Lcd update
//						F_LcdUpdate =1;	
//	      			}
//	      			else if(M_RTC_display >= 100)
//	      			{
//						M_RTC_display =0;
//				     	M_TaskBuf1 =1;
//				     	M_No_Active_Cnt =0;
//				     	
//				     	//--- Lcd All off
//				     	LCD_Clear(OFF);				     		
//	      			}
//	      			
//					break;
//				}
//				
//				
//				//--- display temperture & F/W Ver & H/W Ver
//				case 1:
//				{
////					M_RTC_display++;		//base 10ms
//	      			if(M_RTC_display ==1)
//	      			{
//	      				//--- display temperture
//			      		Ibuf0 = M_Temperature;
//			      		ShowDec_BigNum(Ibuf0);
//			      		lcd.meas.Bit.BigNum_DP =1;
////			      		lcd.meas.Bit.Temperature =1;
//						
//							
//						//--- display H/W Ver
//			      		Ibuf0 = C_HwVersion;
//			      		Lcd_ShowHW(Ibuf0);
//						
//						//--- display F/W Ver
//			      		Ibuf0 = C_FwVersion;
//			      		Lcd_ShowFW(Ibuf0);
//						
//						//--- Lcd update
//						F_LcdUpdate =1;	
//	      			}
//	      			else if(M_RTC_display >= 100)
//	      			{
//						M_RTC_display =0;
//				     	M_TaskBuf1 =2;
//				     	M_No_Active_Cnt =0;
//				     	
//				     	//--- Lcd All off
//				     	LCD_Clear(OFF);				     		
//	      			}
//	      			
//					break;
//				}
//								
//				case 2:
//				{
////					if(M_RTC_display < 100)
////						M_RTC_display++;		//base 10ms
//						
//	      			if(M_RTC_display ==1)
//	      			{
//	      				//--- display temperture
//			      		M_GM_data = (unsigned long) (M_Current * 25) / 100;
//			      		
//			      		//M_GM_data = MeasGMdataCheck( M_Current ) ;
//			      		
//			      		Lcd_Unit();
//						Lcd_Glucose(M_GM_data);
//						
//						//--- Lcd update
//						F_LcdUpdate =1;	
//	      			}
//					
//		     		//--- check strip remover
//					if(blood_strips_pin4==0)          //strip quit check
//					{
////						//--- Init OPA1
////						Initnal_OPA1_Gpio(0);
////						//--- Init OPA2
////						Initnal_OPA2_Gpio(0);
//						//--- disable opa
//						SET_OPAn_POWER(1,POWEROFF);
//						SET_OPAn_POWER(2,POWEROFF);
//						SET_OPA34_POWER(POWEROFF);
//						SET_PIN_OPnP_OPEN(1);
//						SET_PIN_OPnP_OPEN(2);
//						SET_PIN_OP3P_OPEN();
//						fun_StripModuleAllOpen();
//						//--- adc disable
//						fun_ADCStop();
//				  		//--- Dacvref disable
//				  		if(!C_LCD4V_Enable)
//							fun_DACVREFInit(POWEROFF);
//						//--- set daco1 to gnd
//						fun_DACnInit(1,DACnOGND);
//						
//		      			//--- opa1 "s1" on &??"s0" on
//		      			_opa1ofm =0;
//		      			_opa1rs =0;
//		      			
//		      			//--- opa1 "s5" on &??"s4" on
//		      			_opa2ofm =0;
//		      			_opa2rs =0;
//			
//			    		M_TaskBuf0 = e_Exit_mode;
//			    		M_RTC_display =0;
//			    		M_No_Active_Cnt =0;
//					}
//				    
//					break;
//				}
//			}
//			break;
//		}	  	
//--------------------------------------------------------------------------
	  	//--- Error task ----
	  	case e_Errmode:
	  	{	
	  		BatteryCheckProcess ();
  			Cbuf0 =0;
  			M_UART_TxFIFO[Cbuf0++] = 0x55;
  			M_UART_TxFIFO[Cbuf0++] = 0x05;
	  		fun_UART0PowerOnInit();	

				
#ifdef G777G_TEST
			if(M_RTC_display==1 &&
			  M_Error_Task>0 && M_Error_Task<99)
			{			
				M_RTC_display++;
				SET_UARTn_BAUDRATE_19200(0);
				_emi=0;
				print_str("\r\n check_used:I(nA) ");	
				print_double(M_Current_use_log);	
					
				print_str("\r\n check_start:I(nA) ");	
				print_double(M_Current_start_log);	
				
				print_str("\r\n check_full:I(nA) ");	
				print_double(M_Current_full_log);	
				_emi=1; 
			}
#endif
	  		switch(M_Error_Task)
	  		{
	  			
	  			case 0:
	  					M_Error_Task=99;
	  					M_RTC_display=203;
	  					break;
	  					
//------------------------------------------------------	
	  			case 4://E-U
						//--- display "E"
						//LCD_Clear(OFF);
						memset((unsigned char *)&lcd,0,sizeof(lcd));
						lcd.BigNum[0] = charTab['E'] ;	
						//--- display "-"	
						lcd.BigNum[1] = charTab['-'] ;	  			
			  			lcd.BigNum[2] = charTab['U'] ;
			  			F_LcdUpdate =1;
			  			M_Error_Task=0;	
			  			
	  			
#if (voice_en==1)
			  			vice_data_buf[vice_pointer_in++]=(0X37);//试纸已用过
#endif
			  			M_UART_TxFIFO[Cbuf0++] = 0XEE;//包类别
			  			M_UART_TxFIFO[Cbuf0++] = 0XE3;			  			
			  			M_UART_TxFIFO[Cbuf0++]=2;
			  			send_uart_data();
		  				M_RTC_display=0;
			  			M_Error_Task=99;

			  			break;	
//------------------------------------------------------			  				  					
	  			case 5://E-T
					//	LCD_Clear(OFF);
						memset((unsigned char *)&lcd,0,sizeof(lcd));
						lcd.BigNum[0] = charTab['E'] ;	
						//--- display "-"	
						lcd.BigNum[1] = charTab['-'] ;	  			
			  			lcd.BigNum[2] = charTab['t'] ;
			  			F_LcdUpdate =1;
			  			M_Error_Task=0;	 
#if (voice_en==1)
			  			vice_data_buf[vice_pointer_in++]=(0X1D);//温度超出，无法测量
#endif
			  			M_UART_TxFIFO[Cbuf0++] = 0XEE;//包类别
			  			M_UART_TxFIFO[Cbuf0++] = 0XE4;			  			
			  			M_UART_TxFIFO[Cbuf0++]=2;
			  			send_uart_data();
		  				M_RTC_display=0;
			  			M_Error_Task=99;
			  			
			  			break;
//------------------------------------------------------			  				 					
	  			case 6://E-b
					//	LCD_Clear(OFF);
						memset((unsigned char *)&lcd,0,sizeof(lcd));
						lcd.BigNum[0] = charTab['E'] ;	
						//--- display "-"	
						lcd.BigNum[1] = charTab['-'] ;	  			
			  			lcd.BigNum[2] = charTab['b'] ;
#if (voice_en==1)
			  			vice_data_buf[vice_pointer_in++]=(0X56);//电量低
			  			vice_data_buf[vice_pointer_in++]=(0X57);//请充电		
#endif	  			
			  					//--- update bat lcd
//		Lcd_Bat(batlevel);
			  			F_LcdUpdate =1;
//			  			send_uart_data();
		  				M_RTC_display=0;
			  			M_Error_Task=99;
			  			break;
			  				
	  			case 7://满血超时出错。
//------------------------------------------------------	  				
//-------------check remove strip-------------	
					//LCD_Clear(OFF);
					memset((unsigned char *)&lcd,0,sizeof(lcd));
					if(blood_strips_pin4)
					{
				    	M_Error_Task=9;//E-F
				    	break;
					}
					else
					{
						//--- display "E"
					
						
						lcd.BigNum[0] = charTab['E'] ;	
						//--- display "-"	
						lcd.BigNum[1] = charTab['-'] ;	  			
			  			lcd.BigNum[2] = charTab[M_Error_Task+0x30] ;
			  			F_LcdUpdate =1;
#if (voice_en==1)	  			
			  			vice_data_buf[vice_pointer_in++]=(0X38);//错误码，请查说明书
#endif
			  			M_UART_TxFIFO[Cbuf0++] = 0XEE;//包类别
			  			M_UART_TxFIFO[Cbuf0++] = 0XE7;	//满血出错		  			
			  			M_UART_TxFIFO[Cbuf0++] =2;
			  			send_uart_data();			  			
			  			
					}
		  			//send_uart_data();
	  				M_RTC_display=0;
		  			M_Error_Task=99;				
					break;
//------------------------------------------------------				  			
			  			
	  			case 10://阻抗异常错误。
//------------------------------------------------------	  				
//-------------check remove strip-------------	
					//LCD_Clear(OFF);
					
#ifdef G777G_TEST
					_emi=0;						
					print_str("\r\n check error Impedance(K): ");	
					print_double(M_Impedance);	
					_emi=1; 
#endif
					memset((unsigned char *)&lcd,0,sizeof(lcd));
					if(blood_strips_pin4)
					{
				    	M_Error_Task=9;//E-F
				    	break;
					}
					else
					{
						//--- display "E"
					
						
						lcd.BigNum[0] = charTab['E'] ;	
						//--- display "-"	
						lcd.BigNum[1] = charTab['1'] ;	  			
			  			lcd.BigNum[2] = charTab['0'] ;
			  			F_LcdUpdate =1;
#if (voice_en==1)	  			
			  			vice_data_buf[vice_pointer_in++]=(0X38);//错误码，请查说明书
#endif
			  			M_UART_TxFIFO[Cbuf0++] = 0XEE;//包类别
			  			M_UART_TxFIFO[Cbuf0++] = 0XE8;	//满血出错		  			
			  			M_UART_TxFIFO[Cbuf0++]=2;
			  			send_uart_data();			  			
			  			
					}
		  			//send_uart_data();
	  				M_RTC_display=0;
		  			M_Error_Task=99;				
					break;			  									  					
//------------------------------------------------------		
	  			case 9://E-F
					//	LCD_Clear(OFF);
						memset((unsigned char *)&lcd,0,sizeof(lcd));
						lcd.BigNum[0] = charTab['E'] ;	
						//--- display "-"	
						lcd.BigNum[1] = charTab['-'] ;	  			
			  			lcd.BigNum[2] = charTab['F'] ;
			  			F_LcdUpdate =1;

			  			
			  			M_UART_TxFIFO[Cbuf0++] = 0XEE;//包类别
			  			M_UART_TxFIFO[Cbuf0++] = 0XE1;	//测量过程取出试纸		  			
			  			M_UART_TxFIFO[Cbuf0++]=2;			  			
			  			
			  			
			  			send_uart_data();
						#if (voice_en==1)	 
						vice_data_buf[vice_pointer_in++]=(0X38);//错误码，请查说明书
						#endif
		  				M_RTC_display=0;
			  			M_Error_Task=99;
			  			break;	
//------------------------------------------------------			  			
	  			case 0xe://E-E
					//	LCD_Clear(OFF);
						memset((unsigned char *)&lcd,0,sizeof(lcd));
						lcd.BigNum[0] = charTab['E'] ;	
						//--- display "-"	
						lcd.BigNum[1] = charTab['-'] ;	  			
			  			lcd.BigNum[2] = charTab['E'] ;
			  			F_LcdUpdate =1;

			  			
			  			M_UART_TxFIFO[Cbuf0++] = 0XEE;//包类别
			  			M_UART_TxFIFO[Cbuf0++] = 0XE2;	//标定数据丢失	  			
			  			M_UART_TxFIFO[Cbuf0++]=2;			  			
						#if (voice_en==1)	 			
						vice_data_buf[vice_pointer_in++]=(0X38);//错误码，请查说明书
						#endif
			  			send_uart_data();
		  				M_RTC_display=0;
			  			M_Error_Task=99;
			  			break;	
//------------------------------------------------------				  			
			  			
	  			case 1:	//超时
							
						memset((unsigned char *)&lcd,0,sizeof(lcd));
						lcd.BigNum[0] = charTab['E'] ;	
						//--- display "-"	
						lcd.BigNum[1] = charTab['-'] ;	  			
			  			lcd.BigNum[2] = charTab[M_Error_Task+0x30] ;
			  			F_LcdUpdate =1;
						#if (voice_en==1)	 
						vice_data_buf[vice_pointer_in++]=(0X38);//错误码，请查说明书
						#endif
		  				M_No_Active_Cnt=0;
			  			M_Error_Task=99;
	  					break;		  			  					
	  			case 2:
	  			case 3:			  				  			       

	  			
						//--- display "E"
					//	LCD_Clear(OFF);
						memset((unsigned char *)&lcd,0,sizeof(lcd));
						lcd.BigNum[0] = charTab['E'] ;	
						//--- display "-"	
						lcd.BigNum[1] = charTab['-'] ;	  			
			  			lcd.BigNum[2] = charTab[M_Error_Task+0x30] ;
			  			F_LcdUpdate =1;
						#if (voice_en==1)	 
			  			vice_data_buf[vice_pointer_in++]=(0X38);//错误码，请查说明书
						#endif
			  			Cbuf0 =0;
			  			M_UART_TxFIFO[Cbuf0++] = 0x55;
			  			M_UART_TxFIFO[Cbuf0++] = 0x05;			  			
			  			M_UART_TxFIFO[Cbuf0++] = 0XEE;//包类别
			  			M_UART_TxFIFO[Cbuf0++] = M_Error_Task;	  			
			  			M_UART_TxFIFO[Cbuf0++]=2;				  			
			  			
			  			send_uart_data();
		  				M_RTC_display=0;
			  			M_Error_Task=99;

	  					break;	
//------------------------------------------------------	  					
	  			case 99:
	  			default:	  			
			  	
//					M_RTC_display ++;
				#ifdef G35 	
					M_RTC_display=203;
				#endif	
					
								
					
					if(M_RTC_display>200)
					{
					 // LCD_Clear(OFF);
					  memset((unsigned char *)&lcd,0,sizeof(lcd));
					  M_TaskBuf0 = e_Exit_mode;
					  M_RTC_display=0; 
					  M_Error_Task=0;
					  
					  
					  _emi=1;

					}	  			
	  				 			  			
			  			break;	  					
	  					 	  					
	  						  						  			
	  			
	  			
	  		}
	  		


			break; 
			
	  	}
//--------------------------------------------------------------------------
		case e_Errmode2:

					  M_TaskBuf0 = e_Exit_mode;

						break;
		//Exit mode	  
		case e_Exit_mode:
		default:
				#ifdef G35 	
				
					SET_PIN_VG1_GND();
					strips_pin4_dir=1;
					up_pin4=1;
					LCD_Clear(OFF);//delay
					while(blood_strips_pin4 ==0)GCC_CLRWDT();           //strip quit check
					{		
			  			Cbuf0 =0;
			  			M_UART_TxFIFO[Cbuf0++] = 0x55;
			  			M_UART_TxFIFO[Cbuf0++] = 0x05;		
			  			M_UART_TxFIFO[Cbuf0++] = 0X05;//包类别
			  			M_UART_TxFIFO[Cbuf0++] = 0;			  			
			  			M_UART_TxFIFO[Cbuf0++]=2;
			  			send_uart_data();
			  		//	LED=0;
					}					
					
					
				#endif		

			    M_RTC_display = 0;
				M_No_Active_Cnt = 0;
				F_ControlOption =0;
				M_Task = C_OffMode;
				M_TaskBuf0 =0;			
				M_TaskBuf1 =0;
			    //F_Beep_Shortx1 =1;
			    M_Error_Task =0;
			    //--- Lcd All off
			    LCD_Clear(OFF);
//				//--- Init OPA1
//				Initnal_OPA1_Gpio(0);
//				//--- Init OPA2
//				Initnal_OPA2_Gpio(0);
				//--- disable opa
				SET_OPAn_POWER(1,POWEROFF);
				SET_OPAn_POWER(2,POWEROFF);
				SET_OPA34_POWER(POWEROFF);
				SET_PIN_OPnP_OPEN(1);
				SET_PIN_OPnP_OPEN(2);
				SET_PIN_OP3P_OPEN();
				fun_StripModuleAllOpen();
				SET_PIN_VG1_GND();
				SET_PIN_VG0_GND();
				//--- adc disable
				fun_ADCStop();
		  		//--- Dacvref disable
		  		if(!C_LCD4V_Enable)
					fun_DACVREFInit(POWEROFF);
				//--- set daco1 to gnd
				fun_DACnInit(1,DACnOGND);
				
      			//--- opa1 "s1" on &??"s0" on
      			_opa1ofm =0;
      			_opa1rs =0;
      			
      			//--- opa1 "s5" on &??"s4" on
      			_opa2ofm =0;
      			_opa2rs =0;

      			//处理充电初始
				//GD777
				strips_pin6_dir=1;//in--strips pin6
				up_pin6=1;
				
				//G36
				_pac1 = 1; 			
				_papu1 =1;//--strips pin6--G36改到此脚！！      			

				break;	
		
		
	  

	}
	    

	
}

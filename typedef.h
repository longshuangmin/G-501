//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// ====================================================================================@
//                              此文件不能修改!!!                                       @
// ====================================================================================@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#ifndef _SDK_TYPEDEF_H_
#define _SDK_TYPEDEF_H_
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// ======================================================@
//              SDK接口  ADC採樣接口                      @
// ======================================================@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
typedef struct
{
	union
	{
		struct
		{
            unsigned char ByteRes;		// R ADC 預留位
            unsigned char ByteLow;		// R ADC 原始數據低位
            unsigned char ByteMid;		// R ADC 原始數據中位
            unsigned char ByteHigh;		// R ADC 原始數據高位
		}byte;
		signed long ADCData;
	}data;
	unsigned char SamplingCnt;	// R ADC 採集次數計數
	union {
		struct
		{
			unsigned char IsReady : 1;  // R 有一筆原始ADC數據
		} b;
		unsigned char byte;
	} flag;
} ADCSource_t;
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// ======================================================@
//              SDK接口  ADC濾波接口                      @
// ======================================================@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
typedef struct
{
	unsigned long Current;			// R 當前濾波ADC數據
	unsigned long BufMax;			// R 濾波 buf 中最大的ADC值,如果為0x00000000,說明跳動值超過設置濾波範圍
	unsigned long BufMin;			// R 濾波 buf 中最小的ADC值,如果為0xFFFFFFFF,說明跳動值超過設置濾波範圍
	unsigned int StableThreshold;   // RW 目標穩度閥值,用戶在SDK_UserSetting.h設定值
	unsigned char StableCntTag;		// RW 目標穩度次數,用戶在SDK_UserSetting.h設定值
	unsigned char StableCntCurrent; // R 當前穩度次數
	union {
		struct
		{
			unsigned char IsReady : 1;  // R 有一筆濾波ADC數據
			unsigned char IsStable : 1; // R 濾波ADC數據處於穩定狀態
		} b;
		unsigned char byte;
	} flag;
} ADCFilter_t;
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// ======================================================@
//              SDK接口  體阻抗接口                       @
// ======================================================@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//!< HCT 阻抗測量時序
enum IQModeStep_t
{
    HCT_RF1_R,  //!< 參考電阻1_實部
    HCT_RF1_I,  //!< 參考電阻1_虛部
    HCT_RX1_R,  //!< 待測電阻X_實部
    HCT_RX1_I,  //!< 待測電阻X_虛部
    HCT_RF2_R,  //!< 參考電阻2_實部
    HCT_RF2_I,  //!< 參考電阻2_虛部
    HCT_RX2_R,  //!< 待測電阻X_實部
    HCT_RX2_I,  //!< 待測電阻X_虛部
};
typedef struct
{
    unsigned long ADCData_RF1_R;        // R    ADC值 - 參考電阻1_實部
    unsigned long ADCData_RF1_I;        // R    ADC值 - 參考電阻1_虛部
//    unsigned long ADCData_RF2_R;	    // R    ADC值 - 參考電阻2_實部
//    unsigned long ADCData_RF2_I;	    // R    ADC值 - 參考電阻2_虛部
    unsigned long ADCData_RX1_R;        // R    ADC值 - 待測電阻X_實部
    unsigned long ADCData_RX1_I;        // R    ADC值 - 待測電阻X_虛部
//    unsigned long ADCData_RX2_R;        // R    ADC值 - 待測電阻X_實部
//    unsigned long ADCData_RX2_I;        // R    ADC值 - 待測電阻X_虛部
//    unsigned int Data;                  // R    阻抗 - 阻抗值,單位ohm
} HCT_BGM_AC_Data_t;

typedef struct
{
    enum IQModeStep_t IQModeStep;
    unsigned char StartStop;            // RW   開始/結束測量
    unsigned char SinWaveFreq;          // RW   量測頻率
    unsigned char SINO_N;               // RW   SINO1 or SINO2  path
    unsigned long RF_N;                 // RW   RF1 or RF2 path
    unsigned long RF_RX;	            // RW   RF or Rx
    unsigned long Re_Im;	            // RW   Real or Imaginary
} BGM_HCT_STEP_t;

#define BGM_START			0
#define BGM_MEASUREING		1
#define BGM_MEASUREEND		2


enum STATUS_t
{
    ERROR = 0,
    SUCCESS = 1,
};
/*! 模塊電源開關*/
enum PowerOnOff_t
{
    POWEROFF = 0, //!< 關閉電源
    POWERON = 1,  //!< 開啟電源
};
/*! 模塊電源開關*/
enum FunctionOnOff_t
{
    DISABLE = 0, //!< 關閉功能
    ENABLE = 1,  //!< 開啟功能
};

typedef struct
{ 
    unsigned int EU_Current;            		// E_U检测电流值
    unsigned int START_Current;          		// 启动电流门槛值
    unsigned int Start_z;                // 启动阻抗门槛值
    unsigned int Full_delay_time;                // 满血检测延时时间
    unsigned int Full_check; 	            // 满血出错阀值
    unsigned int Work_time; 	            // 血糖测量时间
} BGM_code;

typedef struct {
	
  unsigned char 	M_Strip_Type;
  unsigned int 		auto_code;
  
  //signed long	   	used_AD;
 // signed long	   	start_AD;
  //signed long	   	full_AD;
  double	   		used_curren;
  double	   		start_curren;
  double	   	    full_curren;
  double	   	    err_Impedance;//异常阻抗
  //signed long	   	full_AD;
  
  unsigned int 		measurement_time;
  unsigned int 		max_dis_value ;
  unsigned int 		mini_dis_value;

  double 			mpedance_lowlimit;
  double 			mpedance_hi_limit;

  double 			MAX_HTC;
  double 			MIN_HTC;
  
  
  
  double	    	Temperature;
  double	    	Current;
  double 			Impedance;  
  double 			f_T; 
  double 			f_I; 
  
  
  //double 	a1;
  //double 	b1;
  //double 	c1;

  double 	I_corr;
  
  double 	f_HCT; 
  double 	HCT_corr; 
  //double 	a2;
  //double 	b2;
  //double 	c2;
  
  double 	f_imp1;   
  //double 	a3;
  //double 	b3;
  //double 	c3;
  

  double 	f_imp2;   
  //double 	a4;
  //double 	b4;
  //double 	c4;
  
  double 	f_imp;  
  double 	f_imp_c; 
  double 	I_imp;
  double 	Low_C_High_HCT;

  double 	mmol;
  //double 	a5;
  //double 	b5;
  //double 	c5;
  
  double 	mg; 

  
}_sys_data;


typedef struct {
	

  double 	a_T;//a1;
  double 	b_T;//b1;
  double 	c_T;//c1;
    
  double 	a_I;//a2;
  double 	b_I;//b2;
  double 	c_I;//c2;
  
 //double 	a_corr1;
 //double 	b_corr1;
 //double 	c_corr1;
  
  
  double 	a_HCT;//a3;
  double 	b_HCT;//b3;
  double 	c_HCT;//c3;

  double 	a_imp1;//a4;
  double 	b_imp1;//b4;
  double 	c_imp1;//c4;

  double 	a_imp2;//a5;
  double 	b_imp2;//b5;
  double 	c_imp2;//c5;

  double 	a_C;//a6;
  double 	b_C;//b6;
  double 	c_C;//c6;

  
}_code_data;




typedef union	tagBLOOD_Package
{	
	
	unsigned char   bytes[24];
	struct TT
	{
		unsigned char   Serial_number[9];			
		unsigned char	pvref_2_0V;
		
		unsigned int	afeda1_0_35V;		  	  
		unsigned int	afeda1_0_6V;
		
				
		unsigned  int 	CAL_AD;		
		double  		k_value;
			      int   temp_offset;  		 	
		unsigned  int	CH_SUM;	
	 
	}CAL;
		
		
  
}_biao_ding;

//typedef union	tagBLOOD_Package
//{	
//	
//		unsigned char   CAL_bytes[22];
//		struct TT
//		{
//		  unsigned char CAL_Serial_number[9];	
//		  unsigned char	CAL_pvref;
//		  unsigned int	CAL_afeda1;
//		  		   int  CAL_temp_offset;  					
//		 unsigned  int 	CAL_AD;		
//		 double			k_value;	
//  		 unsigned  int	CH_SUM;	
//  		 
//		}CAL;
//		
//  
//}_biao_ding;


typedef struct {
  double     temp;
  double	 f_I;
  double	 I_corr;
 
  double 	f_imp;
  double 	I_imp;  
  double 	mmol;
  double 	mg;  
  
  
}_new_sys_data;

typedef struct {
  unsigned char  year;
  unsigned char	 month;
  unsigned char	 day;
 
  unsigned char  hour;
  unsigned char  min ; 
  signed int 	 second;
  signed int 	 sg;  
  unsigned char  is_send;
    
}_gsm_data;


typedef union	daa
{	
	unsigned char   bytes[128];
	unsigned int	adc_buff[64];
//	struct BLOOD_Package2
//	{
//		unsigned char _ver;//版本号
//		unsigned char _client_code;//客户码
//		unsigned char _model_code;//机种码
//		unsigned char _Model_no;//机型号
//		unsigned char _user_no;//用户号
//		unsigned char _productMonth;//生产月份
//		unsigned char _productYear;//生产年份
//		unsigned char _Project_Sequence[4];//机身序列号
//		unsigned char _pvref;
//		unsigned char _dal;
//		unsigned char _dah;
//		unsigned char _unde_mem[4];
//		unsigned char _opc1;
//		unsigned char int _Mem_sequence;
//		
//		unsigned char int _Failbuff[10];
//		unsigned char  _undefine[30];	//没定义
//		unsigned char int _Pub_temp;
//		unsigned char  _Mem_sequence_falg;	
//		unsigned char  _sum;
//		
//		unsigned char  _Year;//75 back time
//		unsigned char  _Month; //76    // 		  
//		unsigned char  _Day;	      // 
//		unsigned char  _Hour;
//		unsigned char  _Minute;
//		unsigned char  _Second;	
//			
//		unsigned char  _undefine2[37];	//没定义	
//			
//		unsigned char int _CurrentLow;
//		unsigned char int _CurrentLowAD;
//		unsigned char int _CurrentHi;
//		unsigned char int _CurrentHiAD;
//		
//		unsigned char int  _sum2;		
//	}biaoding;		

	struct {
	
	  double 	a1;
	  double 	b1;
	  double 	c1;
	    
	  double 	a2;
	  double 	b2;
	  double 	c2;
	  
	  double 	a3;
	  double 	b3;
	  double 	c3;
	  
	}code_Chol_Typ;////总胆固醇
	
	struct {
	
	  double 	a1;
	  double 	b1;
	  double 	c1;
	    
	  double 	a2;
	  double 	b2;
	  double 	c2;
	  
	  double 	a3;
	  double 	b3;
	  double 	c3;
	  
	}code_Urea_Type;//尿酸 	
	
}TFBLOOD_Package, *PFBLOOD_Package;


typedef struct 
{
	unsigned int  gen_count;
	unsigned int  pc_count;
	unsigned int  ac_count;
			
	unsigned long gen_Blood;
	unsigned long pc_Blood;
	unsigned long ac_Blood;
	
}_measure_avg;

#endif

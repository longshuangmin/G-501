//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// ====================================================================================@
//                              ���ļ������޸�!!!                                       @
// ====================================================================================@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#ifndef _SDK_TYPEDEF_H_
#define _SDK_TYPEDEF_H_
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// ======================================================@
//              SDK�ӿ�  ADC��ӽӿ�                      @
// ======================================================@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
typedef struct
{
	union
	{
		struct
		{
            unsigned char ByteRes;		// R ADC �A��λ
            unsigned char ByteLow;		// R ADC ԭʼ������λ
            unsigned char ByteMid;		// R ADC ԭʼ������λ
            unsigned char ByteHigh;		// R ADC ԭʼ������λ
		}byte;
		signed long ADCData;
	}data;
	unsigned char SamplingCnt;	// R ADC �񼯴Δ�Ӌ��
	union {
		struct
		{
			unsigned char IsReady : 1;  // R ��һ�PԭʼADC����
		} b;
		unsigned char byte;
	} flag;
} ADCSource_t;
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// ======================================================@
//              SDK�ӿ�  ADC�V���ӿ�                      @
// ======================================================@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
typedef struct
{
	unsigned long Current;			// R ��ǰ�V��ADC����
	unsigned long BufMax;			// R �V�� buf ������ADCֵ,�����0x00000000,�f������ֵ���^�O�ÞV������
	unsigned long BufMin;			// R �V�� buf ����С��ADCֵ,�����0xFFFFFFFF,�f������ֵ���^�O�ÞV������
	unsigned int StableThreshold;   // RW Ŀ�˷����yֵ,�Ñ���SDK_UserSetting.h�O��ֵ
	unsigned char StableCntTag;		// RW Ŀ�˷��ȴΔ�,�Ñ���SDK_UserSetting.h�O��ֵ
	unsigned char StableCntCurrent; // R ��ǰ���ȴΔ�
	union {
		struct
		{
			unsigned char IsReady : 1;  // R ��һ�P�V��ADC����
			unsigned char IsStable : 1; // R �V��ADC����̎춷�����B
		} b;
		unsigned char byte;
	} flag;
} ADCFilter_t;
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// ======================================================@
//              SDK�ӿ�  �w�迹�ӿ�                       @
// ======================================================@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//!< HCT �迹�y���r��
enum IQModeStep_t
{
    HCT_RF1_R,  //!< �������1_����
    HCT_RF1_I,  //!< �������1_̓��
    HCT_RX1_R,  //!< ���y���X_����
    HCT_RX1_I,  //!< ���y���X_̓��
    HCT_RF2_R,  //!< �������2_����
    HCT_RF2_I,  //!< �������2_̓��
    HCT_RX2_R,  //!< ���y���X_����
    HCT_RX2_I,  //!< ���y���X_̓��
};
typedef struct
{
    unsigned long ADCData_RF1_R;        // R    ADCֵ - �������1_����
    unsigned long ADCData_RF1_I;        // R    ADCֵ - �������1_̓��
//    unsigned long ADCData_RF2_R;	    // R    ADCֵ - �������2_����
//    unsigned long ADCData_RF2_I;	    // R    ADCֵ - �������2_̓��
    unsigned long ADCData_RX1_R;        // R    ADCֵ - ���y���X_����
    unsigned long ADCData_RX1_I;        // R    ADCֵ - ���y���X_̓��
//    unsigned long ADCData_RX2_R;        // R    ADCֵ - ���y���X_����
//    unsigned long ADCData_RX2_I;        // R    ADCֵ - ���y���X_̓��
//    unsigned int Data;                  // R    �迹 - �迹ֵ,��λohm
} HCT_BGM_AC_Data_t;

typedef struct
{
    enum IQModeStep_t IQModeStep;
    unsigned char StartStop;            // RW   �_ʼ/�Y���y��
    unsigned char SinWaveFreq;          // RW   ���y�l��
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
/*! ģ�K�Դ�_�P*/
enum PowerOnOff_t
{
    POWEROFF = 0, //!< �P�]�Դ
    POWERON = 1,  //!< �_���Դ
};
/*! ģ�K�Դ�_�P*/
enum FunctionOnOff_t
{
    DISABLE = 0, //!< �P�]����
    ENABLE = 1,  //!< �_������
};

typedef struct
{ 
    unsigned int EU_Current;            		// E_U������ֵ
    unsigned int START_Current;          		// ���������ż�ֵ
    unsigned int Start_z;                // �����迹�ż�ֵ
    unsigned int Full_delay_time;                // ��Ѫ�����ʱʱ��
    unsigned int Full_check; 	            // ��Ѫ����ֵ
    unsigned int Work_time; 	            // Ѫ�ǲ���ʱ��
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
  double	   	    err_Impedance;//�쳣�迹
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
//		unsigned char _ver;//�汾��
//		unsigned char _client_code;//�ͻ���
//		unsigned char _model_code;//������
//		unsigned char _Model_no;//���ͺ�
//		unsigned char _user_no;//�û���
//		unsigned char _productMonth;//�����·�
//		unsigned char _productYear;//�������
//		unsigned char _Project_Sequence[4];//�������к�
//		unsigned char _pvref;
//		unsigned char _dal;
//		unsigned char _dah;
//		unsigned char _unde_mem[4];
//		unsigned char _opc1;
//		unsigned char int _Mem_sequence;
//		
//		unsigned char int _Failbuff[10];
//		unsigned char  _undefine[30];	//û����
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
//		unsigned char  _undefine2[37];	//û����	
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
	  
	}code_Chol_Typ;////�ܵ��̴�
	
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
	  
	}code_Urea_Type;//���� 	
	
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

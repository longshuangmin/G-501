#define  strips_pin8_dir _pac1
#define  up_pin8 	 	_papu1
#define  strips_pin8 	_pa1


#define  strips_pin7_dir _pac7 
#define  up_pin7 		_papu7 
#define  strips_pin7 	_pa7 

#define  strips_pin6_dir _pcc5 
#define  up_pin6 		 _pcpu5 
#define  strips_pin6 	 _pc5  


#define  strips_pin4_dir _pac4 
#define  up_pin4 		 _papu4 
#define  blood_strips_pin4 	 _pa4 



#define glucose_Type   1//血糖
#define ketone_Type    2//血酮
#define Urea_Type      3//尿酸
#define Chol_Type      4//总胆固醇
#define code_Type      5//密码卡

#define low      20//11
#define hi       600

//----	Beep Enable or Disable
#define C_Beep_Enable 	1
//----	LCD 4V Enable(1) or Disable(0)
#define C_LCD4V_Enable 	0
//----  Trim HIRC Enable or Disable
#define C_TrimHirc_Enable 	1
//----  Trim LIRC Enable or Disable
#define C_TrimLirc_Enable 	1

////----	Date change mode
//#define C_DateMode		0			//MM-DD =0 , DD-MM =1;
////----	Time change mode
//#define C_TimeMode		1			//24h =0 , 12h =1;
//----  H/W version
#define C_HwVersion		100
//----  F/W version
#define C_FwVersion		1010

#define Start_year 	24
#define End_year 	50


//#define bl_Version		20
//#define bl_Version		21//1.修改传输后，天线的显示方式为常显；2.温度开放到1-40度；3.显示范围调到1.1-33.3，
//#define bl_Version		22//1.校正部分改成直接测量试纸0.35V，2.修改E-U和E-7的阀值
//#define bl_Version		23//1.算法更新进血判断改为电流值。2.增加语音播报功能
//#define bl_Version		24//修改电池电量检测不准，语音播报的相关bug
//#define bl_Version		25//集成20240705版本的算法
//#define bl_Version		26//集成20240712版本的算法,加上阻抗异常判断，区分老试纸插在新仪器上，报E10
//#define bl_Version		27//集成20240715版本的算法,蓝航算法和量产算法分开管理
//#define bl_Version		28//集成20240717版本的算法,修改量产质控液算法
//#define bl_Version		29//1修改白志堂语音播报在传输失败三次后会重播，，2测量时只显示时间倒计时
//#define bl_Version		30//解决测量完成  显示时间没有分隔符
//#define bl_Version		31//解决白志堂1.偶现传输完成播报两次传输成功，2.测量连续按按键会有连续"didi"
//#define bl_Version		32//增加G-426-1支持，出G-426-1版本
//#define bl_Version			33//1.修改编码格式为ANSI（原来是utf-8）；2.V31爱奥乐偶现进入记忆模式显示白屏（V32已经解决）
//20240731  1.G426-1加上背光


/*
版本号命名规则
V1.0.00
 - - --
 | | |
 | | |
 | | |
 | | |------->Z 修正版本号
 | |--------->Y 子版本号
 |----------->X 主版本号
 
其中，VX.Y.Z为完整版本号，VX.Y为发布版本号 机器可在上单显示版本号按任意键显示完整版本号

X	主版本号	当功能模块发生较大变化时，比如增加模块或整体结构发生变化，用数字1-9表示，初始值为1。
Y	子版本号	局部的变动，主要是局部函数的功能改进或Bug修正或功能的扩充，用数字0-9表示，初始值为0。
Z	修正版本号	表示纠正类软件更新，指修复软件存在且已造成运行故障缺陷的软件更新或指修复软件存在
	但尚未造成运行故障缺陷的软件更新，用数字0-99表示，初始值为0。

注如下：1234对应   X--1      Y--2 Z--34  
*/
#define bl_Version			1000




//----  鏈�澶х瓎鏁?
#define C_GMDataSaveIndex	500
////----  血糖範圍上限
//#define C_Health_H_Std    180
//#define C_Health_H_Max    300
//#define C_Health_H_Min    120
////----  血糖範圍下限
//#define C_Health_L_Std    70
//#define C_Health_L_Max    90
//#define C_Health_L_Min    60

//--- 	description ----
//----  電極電壓
//--- 	毫克/分升（mg/dl）計算 ----

#define	 C_Vref_Voltage	        	2000000	// uV
#define	 C_ADC_Bit	        		32768

#define	 C_Excitation_Voltage		6554     	// 0.400V / 2 * 32768 =6553.6 adc count

//#define	 C_Real_Voltage	        	40000000
#define	 C_Real_Voltage	        	400000	// uV
//----  OPA倍率電阻
//#define	 C_AMP_Resistor				39000000
#define	 C_AMP_Resistor				95300	// Ohm

#define  C_ResOP2N					95.3
#define  C_ResOP1N1					68.0// GLU & UA
#define  C_ResOP1N2					95.3


//--- Trigger 1uA Adc count
//0.4/0.47uA=851K
//((39/851)+1)*0.4=0.41833/2=0.20916*4095=856.5
#define C_TriggerCurrent				10//47		// Base 0.01uA	
//#define	C_TriggerCurrent_Adc			857
//--- strip used 0.22uA Adc count			
//0.4/0.3uA=1333K
//((39/1333)+1)*0.4=0.4117/2=0.20585*4095=842.9
#define C_StripUsedCurrent				30		// Base 0.01uA
//#define	C_StripUsedCurrent_Adc			843
//--- drop 0.02uA Adc count
//0.4/0.3uA=2000K
//((39/2000)+1)*0.4=0.4078/2=0.2039*4095=834.9
#define C_DropCurrent					50		// Base 0.01uA
//#define	C_DropCurrent_Adc				835
//--- 100K Adc count
//((39/100)+1)*0.4=0.556/2=0.278*32768=91095.5
#define	C_Strip_100K_Adc				91069

//---
#define	C_OffTime						2	// Base 1S
#define	C_OnTime						4	// Base 1S

//---
//#define C_DropEnable					1
#define C_DropCount						50	// Base 0.01S


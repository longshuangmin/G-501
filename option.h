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



#define glucose_Type   1//Ѫ��
#define ketone_Type    2//Ѫͪ
#define Urea_Type      3//����
#define Chol_Type      4//�ܵ��̴�
#define code_Type      5//���뿨

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
//#define bl_Version		21//1.�޸Ĵ�������ߵ���ʾ��ʽΪ���ԣ�2.�¶ȿ��ŵ�1-40�ȣ�3.��ʾ��Χ����1.1-33.3��
//#define bl_Version		22//1.У�����ָĳ�ֱ�Ӳ�����ֽ0.35V��2.�޸�E-U��E-7�ķ�ֵ
//#define bl_Version		23//1.�㷨���½�Ѫ�жϸ�Ϊ����ֵ��2.����������������
//#define bl_Version		24//�޸ĵ�ص�����ⲻ׼���������������bug
//#define bl_Version		25//����20240705�汾���㷨
//#define bl_Version		26//����20240712�汾���㷨,�����迹�쳣�жϣ���������ֽ�����������ϣ���E10
//#define bl_Version		27//����20240715�汾���㷨,�����㷨�������㷨�ֿ�����
//#define bl_Version		28//����20240717�汾���㷨,�޸������ʿ�Һ�㷨
//#define bl_Version		29//1�޸İ�־�����������ڴ���ʧ�����κ���ز�����2����ʱֻ��ʾʱ�䵹��ʱ
//#define bl_Version		30//����������  ��ʾʱ��û�зָ���
//#define bl_Version		31//�����־��1.ż�ִ�����ɲ������δ���ɹ���2.����������������������"didi"
//#define bl_Version		32//����G-426-1֧�֣���G-426-1�汾
//#define bl_Version			33//1.�޸ı����ʽΪANSI��ԭ����utf-8����2.V31������ż�ֽ������ģʽ��ʾ������V32�Ѿ������
//20240731  1.G426-1���ϱ���


/*
�汾����������
V1.0.00
 - - --
 | | |
 | | |
 | | |
 | | |------->Z �����汾��
 | |--------->Y �Ӱ汾��
 |----------->X ���汾��
 
���У�VX.Y.ZΪ�����汾�ţ�VX.YΪ�����汾�� ���������ϵ���ʾ�汾�Ű��������ʾ�����汾��

X	���汾��	������ģ�鷢���ϴ�仯ʱ����������ģ�������ṹ�����仯��������1-9��ʾ����ʼֵΪ1��
Y	�Ӱ汾��	�ֲ��ı䶯����Ҫ�Ǿֲ������Ĺ��ܸĽ���Bug�������ܵ����䣬������0-9��ʾ����ʼֵΪ0��
Z	�����汾��	��ʾ������������£�ָ�޸������������������й���ȱ�ݵ�������»�ָ�޸��������
	����δ������й���ȱ�ݵ�������£�������0-99��ʾ����ʼֵΪ0��

ע���£�1234��Ӧ   X--1      Y--2 Z--34  
*/
#define bl_Version			1000




//----  最大筆�?
#define C_GMDataSaveIndex	500
////----  Ѫ�ǹ�������
//#define C_Health_H_Std    180
//#define C_Health_H_Max    300
//#define C_Health_H_Min    120
////----  Ѫ�ǹ�������
//#define C_Health_L_Std    70
//#define C_Health_L_Max    90
//#define C_Health_L_Min    60

//--- 	description ----
//----  늘O늉�
//--- 	����/������mg/dl��Ӌ�� ----

#define	 C_Vref_Voltage	        	2000000	// uV
#define	 C_ADC_Bit	        		32768

#define	 C_Excitation_Voltage		6554     	// 0.400V / 2 * 32768 =6553.6 adc count

//#define	 C_Real_Voltage	        	40000000
#define	 C_Real_Voltage	        	400000	// uV
//----  OPA�������
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


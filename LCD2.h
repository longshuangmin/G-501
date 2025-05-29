#ifndef _LCD2_H
#define _LCD2_H
	void dis_nub1(unsigned char i);
	void dis_nub2(unsigned char i);
	void dis_nub3(unsigned char i);
	void dis_unit(void);
	void dis_123(unsigned int date);
	void testlcd();
	void updata_lcd(void );
	
	void Load_System_Vaule(void);
	void fun_AFEPoweronInit();	
	void PwrOnMode (void);
	void MemoryMode (void);
	void Error_meassage_process (void);
	void RTC_Mode_Setting_Process (void);
	void Alarm_Check_Process(void);
	void PCLINKMode_Process (void);
	void TestingMode (void);
	void Initial_HaltSys(void);
	void Fill_Test_Calibration_data(void);
	unsigned char Load_VrefDaco_Vaule(void);
//	void Calibration_data_reset(void);
	void fun_ADCStop(void);
	void fun_ADCStart(void);
	void keyinti(void);
	void dis_beat(void);
	
#define LONGKEY	100
#define disen_tiem	300	
#endif
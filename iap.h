//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ �A���x @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#define  	IAPWRLENGHT			    8192		// One Page
#define     IAPWRSTARTADDRESS       0xa000


#define 	PAGE_ERASE_MODE		0x90		// �K����ģʽ
#define 	READ_FLASH_MODE		0x32		// �xFlashģʽ
#define 	ENABLE_FWEN_MODE	0x68 		// ������ʹ��ģʽ
#define 	WRITE_FLASH_MODE	0x80		// ��Flashģʽ
////@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ����׃�� @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//static volatile unsigned int Flash_WR_Buff[IAPWRLENGHT] __attribute__((at(0x280)));
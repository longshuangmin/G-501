//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 預定義 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#define  	IAPWRLENGHT			    8192		// One Page
#define     IAPWRSTARTADDRESS       0xa000


#define 	PAGE_ERASE_MODE		0x90		// 塊擦除模式
#define 	READ_FLASH_MODE		0x32		// 讀Flash模式
#define 	ENABLE_FWEN_MODE	0x68 		// 寫功能使能模式
#define 	WRITE_FLASH_MODE	0x80		// 寫Flash模式
////@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 共用變量 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//static volatile unsigned int Flash_WR_Buff[IAPWRLENGHT] __attribute__((at(0x280)));
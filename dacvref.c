#include "include.h"

//--------------------------------------------------------------------------
/**
 * @brief DACVREF初始化 打開/關閉
 *
 * @param PowerOnoff  = POWERON/POWEROFF
 * @note DACVREF 輸出選擇 DACVREF 2.0V 輸出 若需要使用其他 請自行修改 SET_DACVREF_VOLTAGE(DACVREF2V0)
 * PVREF 校準值默認從EEPROM載入 EEPROM_DACVREF
 * @warning  DACVREF電源來自 Voreg 若需使用 DACVREF 必須開啟 Voreg
 */
 //--------------------------------------------------------------------------
void fun_DACVREFInit(enum PowerOnOff_t PowerOnoff)
{
	if (PowerOnoff == POWERON)
	{
		SET_DACVREF_VOLTAGE(DACVREF2V0);
		SET_DACVREF_POWER(POWERON);
	}
	else
	{
		SET_DACVREF_POWER(POWEROFF);
	}
}

#include "include.h"

//--------------------------------------------------------------------------
/**
 * @brief DACVREF��ʼ�� ���_/�P�]
 *
 * @param PowerOnoff  = POWERON/POWEROFF
 * @note DACVREF ݔ���x�� DACVREF 2.0V ݔ�� ����Ҫʹ������ Ո�����޸� SET_DACVREF_VOLTAGE(DACVREF2V0)
 * PVREF У��ֵĬ�J��EEPROM�d�� EEPROM_DACVREF
 * @warning  DACVREF�Դ���� Voreg ����ʹ�� DACVREF ����_�� Voreg
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

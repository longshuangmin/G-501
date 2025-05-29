#include "include.h"

/**
 * @brief Sine Wave �������L�c,������ͬ��ϵ�y�l�� & sine wave �l���O���d�벻ͬ�� TABLE
 *
 * @remarks ݔ����Sine Wave ���ֵ= Voreg*Gain,Ԕ������fun_LoadHCTSinWaveSetting();
 */
const unsigned int SinData_32[32] = {
  0,  50, 100,	148 ,196 ,241 ,284 ,324 ,361 ,395 ,425 ,451,472 ,489 ,501 ,509 ,511 ,509 ,501 ,489 ,
472, 451, 425,  395, 361 ,324 ,284 ,241 ,196 ,148 ,100 ,50,
};

const unsigned int SinData_28[32] = {
  0,  54, 108, 160, 211, 258, 303, 343, 380, 411, 437, 458, 473, 482, 485, 482, 473, 458, 437, 411, 	
380, 343, 303, 258, 211, 160, 108,  54,   0,   0,   0, 	 0, 
};

const unsigned int SinData_24[32] = {
  0,  67, 132, 196, 256, 311, 361, 405, 443, 472, 494, 507, 511, 507, 494, 472, 443, 405, 361, 311,
256, 196, 132,  67,   0,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,
};
const unsigned int SinData_20[32] = {
  0,  80, 158, 232, 300, 361, 413, 455, 486, 505, 511, 505, 486, 455, 413, 361, 300, 232, 158,  80,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
};
const unsigned int SinData_16[32] = {
  0, 100, 196, 284, 361, 425, 472, 501, 511, 501, 472, 425, 361, 284, 196, 100,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
};
const unsigned int SinData_12[32] = {
  0, 132, 256, 361, 443, 494, 511, 494, 443, 361, 256, 132,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
};
const unsigned int SinData_8[32] = {
  0, 196, 361, 472, 511, 472, 361, 196,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
};
const unsigned int SinData_4[32] = {
  0, 361, 511, 361,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
};

//--------------------------------------------------------------------------
/**
 * @brief �O�� Sine wave ݔ���̶��l�ʻ����P�]sine wave ݔ��
 *
 * @param SinWaveFreq   �l���O�� SINWAVEFREQ_OFF���P�]ݔ��
 * @return enum SINEWAVESETRESULT_t �O�ýY��; SINEWAVE_IS_OK �O�óɹ� SINEWAVE_IS_FAIL �o���l������
 * @note ÿ��ϵ�y�l�ʵķ��ֵ�����ԆΪ��{����Ĭ�J��0.5* voreg늉�
 */
 //--------------------------------------------------------------------------
enum SINEWAVESETRESULT_t fun_SineWaveInit(unsigned char SinWaveFreq)
{
	SET_OPA34_POWER(POWERON);
    SET_SINE_OFF(); // �����d��Sine wave Data ǰ����P�] Sine �l����
    SET_OPA34_POWER(POWERON);
    SET_SINE_OFF(); // �����d��Sine wave Data ǰ����P�] Sine �l����
    SET_PIN_VG0_GND();
    unsigned char i;
    enum SINEWAVESETRESULT_t result = SINEWAVE_IS_FAIL;
    switch (SinWaveFreq)
    {
    case SINWAVEFREQ_OFF:
        return result;
        break;        
    
    case SINWAVEFREQ_1KHZ:
        for (i = 0; i < 32; i++)
        {
            SinDataRam[i] = ((float) M_SinGain * 0.01) * SET_SINTABLE_1KHz[i];
        }
        SET_SINFREQ_1KHz();
        break;    
    case SINWAVEFREQ_2KHZ:
        for (i = 0; i < 32; i++)
        {
            SinDataRam[i] = ((float) M_SinGain * 0.01) * SET_SINTABLE_2KHz[i];
        }
        SET_SINFREQ_2KHz();
        break;    
    case SINWAVEFREQ_5KHZ:
        for (i = 0; i < 32; i++)
        {
            SinDataRam[i] = ((float) M_SinGain * 0.01) * SET_SINTABLE_5KHz[i];
        }
        SET_SINFREQ_5KHz();
        break;
    case SINWAVEFREQ_10KHZ:
        for (i = 0; i < 32; i++)
        {
            SinDataRam[i] = ((float) M_SinGain * 0.01) * SET_SINTABLE_10KHz[i];
        }
        SET_SINFREQ_10KHz();
        break;
    case SINWAVEFREQ_16KHZ:
        for (i = 0; i < 32; i++)
        {
            SinDataRam[i] = ((float) M_SinGain * 0.01) * SET_SINTABLE_16KHz[i];
        }
        SET_SINFREQ_16KHz();
        break;
        
    case SINWAVEFREQ_20KHZ:
        for (i = 0; i < 32; i++)
        {
            SinDataRam[i] = ((float) M_SinGain * 0.01) * SET_SINTABLE_20KHz[i];
        }
        SET_SINFREQ_20KHz();
        break;
    case SINWAVEFREQ_25KHZ:
        for (i = 0; i < 32; i++)
        {
            SinDataRam[i] = ((float) M_SinGain * 0.01) * SET_SINTABLE_25KHz[i];
        }
        SET_SINFREQ_25KHz();
        break;
    case SINWAVEFREQ_50KHZ:
        for (i = 0; i < 32; i++)
        {
            SinDataRam[i] = ((float) M_SinGain * 0.01) * SET_SINTABLE_50KHz[i];
        }
        SET_SINFREQ_50KHz();
        break;
    case SINWAVEFREQ_71KHZ:
        for (i = 0; i < 32; i++)
        {
            SinDataRam[i] = ((float) M_SinGain * 0.01) * SET_SINTABLE_75KHz[i];
        }
        SET_SINFREQ_71KHz();
        break;        
        
    case SINWAVEFREQ_100KHZ:
        for (i = 0; i < 32; i++)
        {
            SinDataRam[i] = ((float) M_SinGain * 0.01) * SET_SINTABLE_100KHz[i];
        }
        SET_SINFREQ_100KHz();
        break;
#if SYS_CLOCK_FREQ == 8000000
    case SINWAVEFREQ_200KHZ:
        for (i = 0; i < 32; i++)
        {
            SinDataRam[i] = 0.5 * SET_SINTABLE_200KHz[i];
        }
        SET_SINFREQ_200KHz();
        break;
#endif
    case SINWAVEFREQ_250KHZ:
        for (i = 0; i < 32; i++)
        {
            SinDataRam[i] = 0.5 * SET_SINTABLE_250KHz[i];
        }
        SET_SINFREQ_250KHz();
        break;
    case SINWAVEFREQ_500KHZ:
        for (i = 0; i < 32; i++)
        {
            SinDataRam[i] = 0.5 * SET_SINTABLE_500KHz[i];
        }
        SET_SINFREQ_500KHz();
        break;
#if (SYS_CLOCK_FREQ == 8000000 || SYS_CLOCK_FREQ == 12000000)
    case SINWAVEFREQ_1000KHZ:
        for (i = 0; i < 32; i++)
        {
            SinDataRam[i] = 0.5 * SET_SINTABLE_1000KHz[i];
        }
        SET_SINFREQ_1000KHz();
        break;
#endif
    default:
        return result;
        break;
    }
	SET_PIN_VG0_OPEN();
    SET_SINE_DCSET_0_5AVDD();
    //SET_SINE_DCSET_DACO2();
    SET_HCT_MODE_IQ();
    //SET_HCT_MODE_FWR();
    SET_SINE_ON();
    result = SINEWAVE_IS_OK;
    return result;
}
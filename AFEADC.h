#ifndef _AFEADC_H_
#define _AFEADC_H_

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// ====================================================================================@
//                              24Bit ADC �����O��                                      @
// ====================================================================================@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#define SET_ADCPOWER(x)			    { _adoff = !x; _adslp = !x;}    //!< ADC�Դ�_�P
#define SET_ADC_STARTCONVERT()		{ _adrst = 0; _adrst = 1; _adrst = 0; _adcdl = 0; _eoc = 0; }   //!< �_ʼADC�D�Q���_���󼴿��B�m�@ȡADCֵ�o�����_��
#define SET_ADCINTERRUPT_ENABLE()   { _adf = 0; _ade = 1; _emi = 1;}    //!< �_��ADC�Д��ȫ���Д�
#define SET_ADCINTERRUPT_DISABLE()  { _ade = 0;}    //!< �P�]ADC�Д�

#define SET_ADC_INPUT_SHORT(x)    { _inis = x;} //!< ADC�ȶ��_�P  �������ñ���O�Þ�DISABLE  ENABLE��ADCݔ����0 ��Ҫ���debugʹ��

#define SET_VREF_GAIN_1()		{ _vgs1=0; _vgs0 = 0;}  //!< ����늉��Ŵ����O�Þ�1
#define SET_VREF_GAIN_0_5()		{ _vgs1=0; _vgs0 = 1;}  //!< ����늉��Ŵ����O�Þ�0.5*(VREFP~VREFN)
#define SET_VREF_GAIN_0_25()	{ _vgs1=1; _vgs0 = 0;}  //!< ����늉��Ŵ����O�Þ�0.25*(VREFP~VREFN)

#define SET_ADC_GAIN_1()		{ _ags1=0; _ags0 = 0;}  //!< ADC��λ�Ŵ��O�Þ�1
#define SET_ADC_GAIN_2()		{ _ags1=0; _ags0 = 1;}  //!< ADC��λ�Ŵ��O�Þ�2
#define SET_ADC_GAIN_4()		{ _ags1=1; _ags0 = 0;}  //!< ADC��λ�Ŵ��O�Þ�4
//!< PGA�Ŵ����x��
#define SET_PGA_BYPASS_WITHBUF()	    { _pgabp = 1;  _pgabpbuf = 1;}  //!< �O��PGA bypass(�o�Ŵ�) �obuf ݔ�빠���o���ƣ��������^С���������迹�^���m��
#define SET_PGA_BYPASS_WITHOUTBUF()	    { _pgabp = 1;  _pgabpbuf = 0;}  //!< �O��PGA bypass(�o�Ŵ�) ��buf ݔ�빠����datasheet�������ƣ���ADC�����^���m�Â�����ݔ���迹�^��
#define SET_PGA_GAIN_1()		{ _pgabp = 0; _pgas2=0; _pgas1 = 0; _pgas0 = 0;}    //!< PGA���ʞ�1��
#define SET_PGA_GAIN_2()		{ _pgabp = 0; _pgas2=0; _pgas1 = 0; _pgas0 = 1;}    //!< PGA���ʞ�2��
#define SET_PGA_GAIN_4()		{ _pgabp = 0; _pgas2=0; _pgas1 = 1; _pgas0 = 0;}    //!< PGA���ʞ�4��
#define SET_PGA_GAIN_8()		{ _pgabp = 0; _pgas2=0; _pgas1 = 1; _pgas0 = 1;}    //!< PGA���ʞ�8��
#define SET_PGA_GAIN_16()		{ _pgabp = 0; _pgas2=1; _pgas1 = 0; _pgas0 = 0;}    //!< PGA���ʞ�16��
#define SET_PGA_GAIN_32()		{ _pgabp = 0; _pgas2=1; _pgas1 = 0; _pgas0 = 1;}    //!< PGA���ʞ�32��
#define SET_PGA_GAIN_64()		{ _pgabp = 0; _pgas2=1; _pgas1 = 1; _pgas0 = 0;}    //!< PGA���ʞ�64��
#define SET_PGA_GAIN_128()		{ _pgabp = 0; _pgas2=1; _pgas1 = 1; _pgas0 = 1;}    //!< PGA���ʞ�128��
//!< ���?����? PGAOP/PGAON ƫ��??λ
#define SET_ADC_DCSET_0V()			{ _dcset2=0; _dcset1 = 0; _dcset0 = 0;}     //!< DCSET=+0V
#define SET_ADC_DCSET_UP_0_25()		{ _dcset2=0; _dcset1 = 0; _dcset0 = 1;}     //!< DCSET= +0.25 �� ��VR_I
#define SET_ADC_DCSET_UP_0_5()		{ _dcset2=0; _dcset1 = 1; _dcset0 = 0;}     //!< DCSET= +0.5  �� ��VR_I
#define SET_ADC_DCSET_UP_0_75()		{ _dcset2=0; _dcset1 = 1; _dcset0 = 1;}     //!< DCSET= +0.75 �� ��VR_I
#define SET_ADC_DCSET_DOWN_0_25()	{ _dcset2=1; _dcset1 = 0; _dcset0 = 1;}     //!< DCSET= -0.25 �� ��VR_I
#define SET_ADC_DCSET_DOWN_0_5()	{ _dcset2=1; _dcset1 = 1; _dcset0 = 0;}     //!< DCSET= -0.5  �� ��VR_I
#define SET_ADC_DCSET_DOWN_0_75()	{ _dcset2=1; _dcset1 = 1; _dcset0 = 1;}     //!< DCSET= -0.75 �� ��VR_I
// ADCͨ��D-�x��
#define SET_ADC_CHANNEL_N_AN1()		{ _chsn3=0; _chsn2=0; _chsn1=0; _chsn0=0;}  //!< �ⲿADCͨ��-AN1
#define SET_ADC_CHANNEL_N_AN3()		{ _chsn3=0; _chsn2=0; _chsn1=0; _chsn0=1;}  //!< �ⲿADCͨ��-AN3
#define SET_ADC_CHANNEL_N_AN5()		{ _chsn3=0; _chsn2=0; _chsn1=1; _chsn0=0;}  //!< �ⲿADCͨ��-AN5
#define SET_ADC_CHANNEL_N_DAC1O()	{ _chsn3=0; _chsn2=0; _chsn1=1; _chsn0=1;}  //!< �Ȳ�ADCͨ��-DAC1Oݔ��늉��c
#define SET_ADC_CHANNEL_N_DAC2O()	{ _chsn3=0; _chsn2=1; _chsn1=0; _chsn0=0;}  //!< �Ȳ�ADCͨ��-DAC2Oݔ��늉��c
#define SET_ADC_CHANNEL_N_MOD1ON()	{ _chsn3=0; _chsn2=1; _chsn1=0; _chsn0=1;}  //!< �Ȳ�ADCͨ��-����MOD1OPһ��ʹ��:FWRģʽ��ZֵN��/IQģʽ��RE N��
#define SET_ADC_CHANNEL_N_MOD2ON()	{ _chsn3=0; _chsn2=1; _chsn1=1; _chsn0=0;}  //!< �Ȳ�ADCͨ��-����MOD2OPһ��ʹ��:FWRģʽ�o��/IQģʽ��IM N��
#define SET_ADC_CHANNEL_N_VDD_6()	{ _chsn3=0; _chsn2=1; _chsn1=1; _chsn0=1;}  //!< �Ȳ�ADCͨ��-1/6VDD늉� ��1/5VDD�������yVDD늉�
#define SET_ADC_CHANNEL_N_OP1N1()	{ _chsn3=1; _chsn2=0; _chsn1=0; _chsn0=0;}  //!< �Ȳ�ADCͨ��-OPA1-1 N�� ͨ������OPA1ݔ�������y�������늉�
#define SET_ADC_CHANNEL_N_OP1N2()	{ _chsn3=1; _chsn2=0; _chsn1=0; _chsn0=1;}  //!< �Ȳ�ADCͨ��-OPA1-2 N�� ͨ������OPA1ݔ�������y�������늉�
#define SET_ADC_CHANNEL_N_OP2N()	{ _chsn3=1; _chsn2=0; _chsn1=1; _chsn0=0;}  //!< �Ȳ�ADCͨ��-OPA2   N�� ͨ������OPA2ݔ�������y�������늉�
#define SET_ADC_CHANNEL_N_AVSS()	{ _chsn3=1; _chsn2=0; _chsn1=1; _chsn0=1;}  //!< �Ȳ�ADCͨ��-AVSS �ζˑ��Õrʹ�ã�����ʹ��PGA��Ҫ�O�Þ�bypass

#define SET_ADC_CHANNEL_P_AN0()		{ _chsp3=0; _chsp2=0; _chsp1=0; _chsp0=0;}  //!< �ⲿADCͨ��-AN0
#define SET_ADC_CHANNEL_P_AN2()		{ _chsp3=0; _chsp2=0; _chsp1=0; _chsp0=1;}  //!< �ⲿADCͨ��-AN2
#define SET_ADC_CHANNEL_P_AN4()		{ _chsp3=0; _chsp2=0; _chsp1=1; _chsp0=0;}  //!< �ⲿADCͨ��-AN4
#define SET_ADC_CHANNEL_P_DAC1O()	{ _chsp3=0; _chsp2=0; _chsp1=1; _chsp0=1;}  //!< �Ȳ�ADCͨ��-DAC1Oݔ��늉��c
#define SET_ADC_CHANNEL_P_DAC2O()	{ _chsp3=0; _chsp2=1; _chsp1=0; _chsp0=0;}  //!< �Ȳ�ADCͨ��-DAC2Oݔ��늉��c
#define SET_ADC_CHANNEL_P_MOD1OP()	{ _chsp3=0; _chsp2=1; _chsp1=0; _chsp0=1;}  //!< �Ȳ�ADCͨ��-����MOD1ONһ��ʹ��:FWRģʽ��ZֵP��/IQģʽ��RE P��
#define SET_ADC_CHANNEL_P_MOD2OP()	{ _chsp3=0; _chsp2=1; _chsp1=1; _chsp0=0;}  //!< �Ȳ�ADCͨ��-����MOD2ONһ��ʹ��:FWRģʽ�o��/IQģʽ��IM P��
#define SET_ADC_CHANNEL_P_OP1S0()	{ _chsp3=0; _chsp2=1; _chsp1=1; _chsp0=1;}  //!< �Ȳ�ADCͨ��-OPA1-0 ݔ���� ͨ������OPA1-N�����y�������늉�
#define SET_ADC_CHANNEL_P_OP1S1()	{ _chsp3=1; _chsp2=0; _chsp1=0; _chsp0=0;}  //!< �Ȳ�ADCͨ��-OPA1-1 ݔ���� ͨ������OPA1-N�����y�������늉�
#define SET_ADC_CHANNEL_P_OP2O()	{ _chsp3=1; _chsp2=0; _chsp1=0; _chsp0=1;}  //!< �Ȳ�ADCͨ��-OPA2   ݔ���� ͨ������OPA2-N�����y�������늉�
#define SET_ADC_CHANNEL_P_AVDD_5()	{ _chsp3=1; _chsp2=0; _chsp1=1; _chsp0=0;}  //!< �Ȳ�ADCͨ��-1/5VDD늉� ��1/6VDD�������yVDD늉�
#define SET_ADC_CHANNEL_P_AVSS()	{ _chsp3=1; _chsp2=0; _chsp1=1; _chsp0=1;}  //!< �Ȳ�ADCͨ��-AVSS �ζˑ��Õrʹ�ã�����ʹ��PGA��Ҫ�O�Þ�bypass

//!< ADC DATA RARE Ӌ�㷽ʽ����:
//!< FMCLK = fSYS/2/(ADCS+1) if ADCS=0x1F, FMCLK = fSYS
//!< DataRate = FMCLK/(OSR*N*CHOP)
#define CHOP2_FLMS30()              { _flms2=0; _flms1=0; _flms0=0;}
#define CHOP2_FLMS12()              { _flms2=0; _flms1=1; _flms0=0;}
#define CHOP1_FLMS30()              { _flms2=1; _flms1=0; _flms0=0;}
#define CHOP1_FLMS12()              { _flms2=1; _flms1=1; _flms0=0;}
#define OSR_16384()                 { _ador2=0; _ador1=0; _ador0=0;}
#define OSR_8192()                  { _ador2=0; _ador1=0; _ador0=1;}
#define OSR_4096()                  { _ador2=0; _ador1=1; _ador0=0;}
#define OSR_2048()                  { _ador2=0; _ador1=1; _ador0=1;}
#define OSR_1024()                  { _ador2=1; _ador1=0; _ador0=0;}
#define OSR_512()                   { _ador2=1; _ador1=0; _ador0=1;}
#define OSR_256()                   { _ador2=1; _ador1=1; _ador0=0;}
#define OSR_128()                   { _ador2=1; _ador1=1; _ador0=1;}

#if SYS_CLOCK_FREQ == 4000000
#define SET_ADC_DATARATE_10HZ()		{ _adcs=0x1F; CHOP2_FLMS12(); OSR_16384();}
#define SET_ADC_DATARATE_20HZ()		{ _adcs=0x1F; CHOP2_FLMS12(); OSR_8192(); }
#define SET_ADC_DATARATE_40HZ()		{ _adcs=0x1F; CHOP2_FLMS12(); OSR_4096(); }
#define SET_ADC_DATARATE_64HZ()		{ _adcs=0x1F; CHOP2_FLMS30(); OSR_1024(); }
#define SET_ADC_DATARATE_80HZ()		{ _adcs=0x1F; CHOP2_FLMS12(); OSR_2048(); }
#define SET_ADC_DATARATE_160HZ()	{ _adcs=0x1F; CHOP2_FLMS12(); OSR_1024(); }
#define SET_ADC_DATARATE_320HZ()	{ _adcs=0x1F; CHOP2_FLMS12(); OSR_512();  }
#define SET_ADC_DATARATE_1300HZ()	{ _adcs=0x1F; CHOP2_FLMS12(); OSR_128();  }
#define SET_ADC_DATARATE_2600HZ()	{ _adcs=0x1F; CHOP1_FLMS12(); OSR_128();  }

#define SET_ADC_DATARATE_4HZ()		{ _adcs=0x1F; CHOP2_FLMS30(); OSR_16384() }
#define SET_ADC_DATARATE_8HZ()		{ _adcs=0x1F; CHOP2_FLMS30(); OSR_8192()  }
#define SET_ADC_DATARATE_16HZ()		{ _adcs=0x1F; CHOP2_FLMS30(); OSR_4096()  }
#define SET_ADC_DATARATE_32HZ()		{ _adcs=0x1F; CHOP2_FLMS30(); OSR_2048()  }
#define SET_ADC_DATARATE_64HZ()		{ _adcs=0x1F; CHOP2_FLMS30(); OSR_1024(); }
#define SET_ADC_DATARATE_128HZ()	{ _adcs=0x1F; CHOP2_FLMS30(); OSR_512(); }
#define SET_ADC_DATARATE_256HZ()	{ _adcs=0x1F; CHOP2_FLMS30(); OSR_256(); }
#define SET_ADC_DATARATE_512HZ()	{ _adcs=0x1F; CHOP2_FLMS30(); OSR_128(); }
#endif

#if SYS_CLOCK_FREQ == 8000000
#define SET_ADC_DATARATE_10HZ()		{ _adcs=0x00; CHOP2_FLMS12(); OSR_16384() }
#define SET_ADC_DATARATE_20HZ()		{ _adcs=0x00; CHOP2_FLMS12(); OSR_8192(); }
#define SET_ADC_DATARATE_40HZ()		{ _adcs=0x00; CHOP2_FLMS12(); OSR_4096(); }
#define SET_ADC_DATARATE_80HZ()		{ _adcs=0x00; CHOP2_FLMS12(); OSR_2048(); }
#define SET_ADC_DATARATE_160HZ()	{ _adcs=0x00; CHOP2_FLMS12(); OSR_1024(); }
#define SET_ADC_DATARATE_320HZ()	{ _adcs=0x00; CHOP2_FLMS12(); OSR_512();  }
#define SET_ADC_DATARATE_640HZ()	{ _adcs=0x00; CHOP2_FLMS12(); OSR_256();  }
#define SET_ADC_DATARATE_1300HZ()	{ _adcs=0x00; CHOP2_FLMS12(); OSR_128();  }

#define SET_ADC_DATARATE_4HZ()		{ _adcs=0x00; CHOP2_FLMS30(); OSR_16384() }
#define SET_ADC_DATARATE_8HZ()		{ _adcs=0x00; CHOP2_FLMS30(); OSR_8192()  }
#define SET_ADC_DATARATE_16HZ()		{ _adcs=0x00; CHOP2_FLMS30(); OSR_4096()  }
#define SET_ADC_DATARATE_32HZ()		{ _adcs=0x00; CHOP2_FLMS30(); OSR_2048()  }
#define SET_ADC_DATARATE_64HZ()		{ _adcs=0x00; CHOP2_FLMS30(); OSR_1024(); }
#define SET_ADC_DATARATE_128HZ()	{ _adcs=0x00; CHOP2_FLMS30(); OSR_512(); }
#define SET_ADC_DATARATE_256HZ()	{ _adcs=0x00; CHOP2_FLMS30(); OSR_256(); }
#define SET_ADC_DATARATE_512HZ()	{ _adcs=0x00; CHOP2_FLMS30(); OSR_128(); }

#endif
#if SYS_CLOCK_FREQ == 12000000
#define SET_ADC_DATARATE_10HZ()		{ _adcs=0x02; CHOP2_FLMS12(); OSR_8192(); }
#define SET_ADC_DATARATE_20HZ()		{ _adcs=0x02; CHOP2_FLMS12(); OSR_4096(); }
#define SET_ADC_DATARATE_40HZ()		{ _adcs=0x02; CHOP2_FLMS12(); OSR_2048(); }
#define SET_ADC_DATARATE_64HZ()		{ _adcs=0x02; CHOP2_FLMS30(); OSR_512();  }
#define SET_ADC_DATARATE_80HZ()		{ _adcs=0x02; CHOP2_FLMS12(); OSR_1024(); }
#define SET_ADC_DATARATE_160HZ()	{ _adcs=0x02; CHOP2_FLMS12(); OSR_512();  }
#define SET_ADC_DATARATE_320HZ()	{ _adcs=0x02; CHOP2_FLMS12(); OSR_256();  }
#define SET_ADC_DATARATE_1300HZ()	{ _adcs=0x1F; CHOP2_FLMS30(); OSR_128();  }
#endif

#endif
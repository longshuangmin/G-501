#ifndef _AFE_SINE_WAVE_H_
#define _AFE_SINE_WAVE_H_

/*! sine wave ݔ���l�� */
enum SINEWAVEFREQ_t
{
    SINWAVEFREQ_OFF,     //!< �P�]Sine Wave ݔ��
    SINWAVEFREQ_1KHZ,    //!< 5khz
    SINWAVEFREQ_2KHZ,    //!< 5khz
    SINWAVEFREQ_5KHZ,    //!< 5khz
    SINWAVEFREQ_10KHZ,   //!< 10khz
    SINWAVEFREQ_16KHZ,   //!< 16khz
    SINWAVEFREQ_20KHZ,   //!< 20khz
    SINWAVEFREQ_25KHZ,   //!< 25khz
    SINWAVEFREQ_50KHZ,   //!< 50khz
    SINWAVEFREQ_71KHZ,   //!< 50khz
    SINWAVEFREQ_100KHZ,  //!< 100khz
    SINWAVEFREQ_200KHZ,  //!< 200khz    ֻ����ϵ�y�l��=8MHz�²ſ���
    SINWAVEFREQ_250KHZ,  //!< 250khz
    SINWAVEFREQ_500KHZ,  //!< 500khz
    SINWAVEFREQ_1000KHZ, //!< 1000khz   ֻ����ϵ�y�l��=8MHz/12MHz�²ſ���
};
/*! sine wave �O�ýY�� */
enum SINEWAVESETRESULT_t
{
    SINEWAVE_IS_OK,   //!< �O��OK
    SINEWAVE_IS_FAIL, //!< �O��ʧ�����o����l���O��
};
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// ====================================================================================@
//                                SINE    �����O��                                      @
// ====================================================================================@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// �����l�����_�P
#define SET_SINE_DCSET_0_5AVDD()    { _sgop0p1 = 0; _sgop0p0 = 0; _bren = 1;}   //!< sine Wave ݔ�� offset ��0.5*AVDD
#define SET_SINE_DCSET_DACO1()      { _sgop0p1 = 0; _sgop0p0 = 1; _bren = 0;}   //!< sine Wave ݔ�� offset ��DACO1ֵ
#define SET_SINE_DCSET_DACO2()      { _sgop0p1 = 1; _sgop0p0 = 0; _bren = 1;}   //!< sine Wave ݔ�� offset ��DACO2ֵ
#define SET_SINE_ON()               {  _sgen= 1; ; _sgiqrs = 1; _sgiqrs = 0;}     //!< sine Wave ݔ��
#define SET_SINE_OFF()              {  _sgc = 0; }  //!< sine Wave ݔ�� �P�]
// �y��ģʽ
#define SET_HCT_MODE_IQ()           { _iq_fwr = 0;} //!< Demodulator ݔ��ģʽ IQ Mode  MOD1OP&MOD1ON �錍����Ϣ,MOD2OP&MOD2ON ��̓����Ϣ
#define SET_HCT_MODE_FWR()          { _iq_fwr = 1;} //!< Demodulator ݔ��ģʽ FWR Mode MOD1OP&MOD1ON ��Zֵ��Ϣ ,MOD2OP&MOD2ON �oЧ
// SINE PIN
#define SET_PIN_SINO1_OPEN()        { _bswsino1 = 0;}   //!< SINO1 Pin �Ȳ����_
#define SET_PIN_SINO1_SINOUT()      { _bswsino1 = 1;}   //!< SINO1 Pin �Ȳ��B�ӵ� Sine wave ��ݔ��
#define SET_PIN_SINO2_OPEN()        { _bswsino2 = 0;}   //!< SINO2 Pin �Ȳ����_
#define SET_PIN_SINO2_SINOUT()      { _bswsino2 = 1;}   //!< SINO2 Pin �Ȳ��B�ӵ� Sine wave ��ݔ��
// SINE Freq
#if SYS_CLOCK_FREQ == 4000000
#define SET_SINTABLE_1KHz           SinData_32
#define SET_SINTABLE_2KHz           SinData_20
#define SET_SINTABLE_5KHz           SinData_20
#define SET_SINTABLE_10KHz          SinData_20
#define SET_SINTABLE_16KHz          SinData_32
#define SET_SINTABLE_20KHz          SinData_20
#define SET_SINTABLE_25KHz          SinData_20
#define SET_SINTABLE_50KHz          SinData_20
#define SET_SINTABLE_75KHz          SinData_28
#define SET_SINTABLE_100KHz         SinData_20
#define SET_SINTABLE_250KHz         SinData_8
#define SET_SINTABLE_500KHz         SinData_4

#define SET_SINFREQ_1KHz()			{ _sgn = 62; _sgdnr = 31;}
#define SET_SINFREQ_2KHz()			{ _sgn = 49; _sgdnr = 19;}
#define SET_SINFREQ_5KHz()			{ _sgn = 19; _sgdnr = 19;}
#define SET_SINFREQ_10KHz()			{ _sgn =  9; _sgdnr = 19;}
#define SET_SINFREQ_16KHz()			{ _sgn =  3; _sgdnr = 31;}
#define SET_SINFREQ_20KHz()			{ _sgn =  4; _sgdnr = 19;}
#define SET_SINFREQ_25KHz()			{ _sgn =  3; _sgdnr = 19;}
#define SET_SINFREQ_50KHz()			{ _sgn =  1; _sgdnr = 19;}
#define SET_SINFREQ_71KHz()			{ _sgn =  0; _sgdnr = 27;}
#define SET_SINFREQ_100KHz()		{ _sgn =  0; _sgdnr = 19;}
#define SET_SINFREQ_250KHz()		{ _sgn =  0; _sgdnr =  7;}
#define SET_SINFREQ_500KHz()		{ _sgn =  0; _sgdnr =  3;}
#endif
#if SYS_CLOCK_FREQ == 8000000
#define SET_SINTABLE_5KHz           SinData_32
#define SET_SINTABLE_10KHz          SinData_20
#define SET_SINTABLE_20KHz          SinData_20
#define SET_SINTABLE_25KHz          SinData_32
#define SET_SINTABLE_50KHz          SinData_20
#define SET_SINTABLE_100KHz         SinData_20
#define SET_SINTABLE_200KHz         SinData_20
#define SET_SINTABLE_250KHz         SinData_16
#define SET_SINTABLE_500KHz         SinData_8
#define SET_SINTABLE_1000KHz        SinData_4
#define SET_SINFREQ_5KHz()			{ _sgn = 24; _sgdnr = 31;}
#define SET_SINFREQ_10KHz()			{ _sgn = 19; _sgdnr = 19;}
#define SET_SINFREQ_20KHz()			{ _sgn =  9; _sgdnr = 19;}
#define SET_SINFREQ_25KHz()			{ _sgn =  4; _sgdnr = 31;}
#define SET_SINFREQ_50KHz()			{ _sgn =  3; _sgdnr = 19;}
#define SET_SINFREQ_100KHz()		{ _sgn =  1; _sgdnr = 19;}
#define SET_SINFREQ_200KHz()		{ _sgn =  0; _sgdnr = 19;}
#define SET_SINFREQ_250KHz()		{ _sgn =  0; _sgdnr = 15;}
#define SET_SINFREQ_500KHz()		{ _sgn =  0; _sgdnr =  7;}
#define SET_SINFREQ_1000KHz()		{ _sgn =  0; _sgdnr =  3;}
#endif
#if SYS_CLOCK_FREQ == 12000000
#define SET_SINTABLE_5KHz           SinData_24
#define SET_SINTABLE_10KHz          SinData_24
#define SET_SINTABLE_20KHz          SinData_20
#define SET_SINTABLE_25KHz          SinData_24
#define SET_SINTABLE_50KHz          SinData_24
#define SET_SINTABLE_100KHz         SinData_20
#define SET_SINTABLE_250KHz         SinData_24
#define SET_SINTABLE_500KHz         SinData_12
#define SET_SINTABLE_1000KHz        SinData_8
#define SET_SINFREQ_5KHz()			{ _sgn = 49; _sgdnr = 23;}
#define SET_SINFREQ_10KHz()			{ _sgn = 24; _sgdnr = 23;}
#define SET_SINFREQ_20KHz()			{ _sgn = 14; _sgdnr = 19;}
#define SET_SINFREQ_25KHz()			{ _sgn =  9; _sgdnr = 23;}
#define SET_SINFREQ_50KHz()			{ _sgn =  4; _sgdnr = 23;}
#define SET_SINFREQ_100KHz()		{ _sgn =  2; _sgdnr = 19;}
#define SET_SINFREQ_250KHz()		{ _sgn =  0; _sgdnr = 23;}
#define SET_SINFREQ_500KHz()		{ _sgn =  0; _sgdnr = 11;}
#define SET_SINFREQ_1000KHz()		{ _sgn =  0; _sgdnr =  7;}
#endif

////@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//// ======================================================@
////                     �����ӿ�                           @
//// ======================================================@
////@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//
//enum SINEWAVESETRESULT_t fun_SineWaveInit(enum SINEWAVEFREQ_t SinWaveFreq);

#endif
#ifndef _AFEPOWER_H_
#define _AFEPOWER_H_

#define EEPROM_DACVREF  0x01
#define EEPROM_DAC1     0x02
#define EEPROM_DAC2     0x04
#define EEPROM_OPA1     0x06
#define EEPROM_OPA2     0x07
#define EEPROM_OPA3     0x08
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// ====================================================================================@
//                                AFE Power  �����O��                                   @
// ====================================================================================@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

/*! Voregݔ��늉� ADC OPA ���Դ���� VOREG*/
enum VoregOuput_t
{
    Voreg2V4 = 0,    //!< Voreg����ݔ��2.4V
    Voreg2V6 = 1,    //!< ����ݔ��2.6V
    Voreg2V2 = 2,    //!< ����ݔ��2.2V
    Voreg2V3 = 3,    //!< ����ݔ��2.3V
    VoregBypass = 4, //!< AVDD bypass ݔ��
};
//                         -----VOREG Definition------;
#define SET_VOREG_OUTPUT(x)     { _pwrc = x;}   //!< �O�� VOREG ��ݔ��늉� x = enum VoregOuput_t
#define SET_VOREG_POWER(x)      {_ldoen = x;}   //!< VOREG �Դ�_�P x = enum PowerOnOff_t
//                         -----DACVREF Definition------;
/*! DACVREFݔ��늉�, ADC �ą���늉����Դ�̎*/
enum DACVREFOuput_t
{
    DACVREF2V0 = 0, //!< DACVREF ݔ���� �Ȳ�2.0V @��ߵĜ�Ư���Ժͷ�����
    AVDD = 2,       //!< DACVREF ݔ���� AVDD @ݔ�����SAVDD׃�� �����hʹ��
    HZ = 3,         //!< DACVREF �����B �����늉�ݔ�� �����hʹ��
};
#define SET_DACVREF_VOLTAGE(x)  { _irefc = x;}  //!< �O�� DACVREF ��ݔ��늉� x = enum DACVREFOuput_t
#define SET_DACVREF_POWER(x)    { _irefen = x;} //!< DACVREF �Դ�_�P x = enum PowerOnOff_t

#define SET_DACVREF2V0_ADD500UV()   { _pvref--;}    //!< DACVREF ݔ��늉�΢�{-����0.5mV
#define SET_DACVREF2V0_SUB500UV()   { _pvref++;}    //!< DACVREF ݔ��늉�΢�{-�pС0.5mV
#define SET_DACVREF2V0_CALDATA(x)   { _pvref = x;}  //!< DACVREF ݔ��늉�΢�{-�O���{��ֵ
//                      -----12Bit DAC Definition------;
/*! DACnO ݔ��늉��O�� n = 1/2 */
enum DACnOuput_t
{
    DACnODISABLE = 0, //!< Disable, output in a high-impedance state
    DACnOEnable = 1,  //!< Enable, Output with DAC data;
    DACnOGND = 2,     //!< Disable, output in a ground state
};
#define SET_DACn_VOLTAGE(n, x)  { _afeda##n##c = x;}    //!< �O�� DACn ��ݔ��늉��x� n=1/2; x = enum DACVREFOuput_t;
#define SET_DACOn_DATA(n, x)    { _afeda##n##l = (x<<4)&0xFF; _afeda##n##h = x>>4;}//!< �O�� DACn ��ݔ��늉�ֵ n=1/2;



//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ���ú��� @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//void fun_DACVREFInit(enum PowerOnOff_t PowerOnoff);
//void fun_DACnInit(unsigned char DACn, enum PowerOnOff_t PowerOnOff);


#endif

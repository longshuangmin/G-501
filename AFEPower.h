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
//                                AFE Power  基本設置                                   @
// ====================================================================================@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

/*! Voreg輸出電壓 ADC OPA 等電源來自 VOREG*/
enum VoregOuput_t
{
    Voreg2V4 = 0,    //!< Voreg穩壓輸出2.4V
    Voreg2V6 = 1,    //!< 穩壓輸出2.6V
    Voreg2V2 = 2,    //!< 穩壓輸出2.2V
    Voreg2V3 = 3,    //!< 穩壓輸出2.3V
    VoregBypass = 4, //!< AVDD bypass 輸出
};
//                         -----VOREG Definition------;
#define SET_VOREG_OUTPUT(x)     { _pwrc = x;}   //!< 設置 VOREG 的輸出電壓 x = enum VoregOuput_t
#define SET_VOREG_POWER(x)      {_ldoen = x;}   //!< VOREG 電源開關 x = enum PowerOnOff_t
//                         -----DACVREF Definition------;
/*! DACVREF輸出電壓, ADC 的參考電壓來自此處*/
enum DACVREFOuput_t
{
    DACVREF2V0 = 0, //!< DACVREF 輸出為 內部2.0V @最高的溫漂特性和穩定性
    AVDD = 2,       //!< DACVREF 輸出為 AVDD @輸出會隨AVDD變化 不建議使用
    HZ = 3,         //!< DACVREF 高阻狀態 可外掛電壓輸入 不建議使用
};
#define SET_DACVREF_VOLTAGE(x)  { _irefc = x;}  //!< 設置 DACVREF 的輸出電壓 x = enum DACVREFOuput_t
#define SET_DACVREF_POWER(x)    { _irefen = x;} //!< DACVREF 電源開關 x = enum PowerOnOff_t

#define SET_DACVREF2V0_ADD500UV()   { _pvref--;}    //!< DACVREF 輸出電壓微調-增加0.5mV
#define SET_DACVREF2V0_SUB500UV()   { _pvref++;}    //!< DACVREF 輸出電壓微調-減小0.5mV
#define SET_DACVREF2V0_CALDATA(x)   { _pvref = x;}  //!< DACVREF 輸出電壓微調-設置調節值
//                      -----12Bit DAC Definition------;
/*! DACnO 輸出電壓設置 n = 1/2 */
enum DACnOuput_t
{
    DACnODISABLE = 0, //!< Disable, output in a high-impedance state
    DACnOEnable = 1,  //!< Enable, Output with DAC data;
    DACnOGND = 2,     //!< Disable, output in a ground state
};
#define SET_DACn_VOLTAGE(n, x)  { _afeda##n##c = x;}    //!< 設置 DACn 的輸出電壓選項 n=1/2; x = enum DACVREFOuput_t;
#define SET_DACOn_DATA(n, x)    { _afeda##n##l = (x<<4)&0xFF; _afeda##n##h = x>>4;}//!< 設置 DACn 的輸出電壓值 n=1/2;



//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 共用函數 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//void fun_DACVREFInit(enum PowerOnOff_t PowerOnoff);
//void fun_DACnInit(unsigned char DACn, enum PowerOnOff_t PowerOnOff);


#endif

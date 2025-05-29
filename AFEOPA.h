#ifndef _AFEOPA_H
#define _AFEOPA_H

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// ====================================================================================@
//                                  OPA   »ù±¾ÔOÖÃ                                      @
// ====================================================================================@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#define SET_OPAn_POWER(n,x)         { _opa##n##en  = x;}    //!< OPAnëŠÔ´¿ØÖÆ n=1~3 x=enum PowerOnOff_t
#define SET_OPAn_MODE_NORMAL(n)     { _opa##n##ofm = 0;}    //!< OPAn ÆÕÍ¨Ä£Ê½ n=1~3
#define SET_OPAn_MODE_CALOFFSET(n)  { _opa##n##ofm = 1; _opa##n##rs = 1;}   //!< OPAn VosÐ£œÊÄ£Ê½ n=1~3
// OPnP
#define SET_PIN_OPnP_OPEN(n)    { _gsop##n##p1 = 0; _gsop##n##p0 = 0;}  //!< OPAn(n=1~2) P¶ËëŠ‰ºÔOÖÃ-¸¡¿Õ
#define SET_PIN_OPnP_DAC1O(n)   { _gsop##n##p1 = 0; _gsop##n##p0 = 1;}  //!< OPAn(n=1~2) P¶ËëŠ‰ºÔOÖÃ-DACO1
#define SET_PIN_OPnP_DAC2O(n)   { _gsop##n##p1 = 1; _gsop##n##p0 = 0;}  //!< OPAn(n=1~2) P¶ËëŠ‰ºÔOÖÃ-DACO2
#define SET_PIN_OP3P_0_5AVDD()  { _bren = 1;}   //!< OPA3 P¶ËëŠ‰ºÔOÖÃ-0.5AVDD
#define SET_PIN_OP3P_OPEN()     { _bren = 0;}   //!< OPA3 P¶ËëŠ‰ºÔOÖÃ¸¡¿Õ
// OP1N
#define SET_PIN_OP1N1_OPEN()    { _gsw4 = 0;}   //!< OP1N1 ¸¡¿Õ
#define SET_PIN_OP1N1_OP1N()    { _gsw4 = 1;}   //!< OP1N1 ßB½Óµ½ OPA1 N¶Ë
#define SET_PIN_OP1N2_OPEN()    { _gsw5 = 0;}   //!< OP1N2 ¸¡¿Õ
#define SET_PIN_OP1N2_OP1N()    { _gsw5 = 1;}   //!< OP1N2 ßB½Óµ½ OPA1 N¶Ë
// OP2N
#define SET_PIN_OP2N_OPEN()     { _gsw7 = 0;}   //!< OP2N ¸¡¿Õ
#define SET_PIN_OP2N_OP2N()     { _gsw7 = 1;}   //!< OP2N ¸¡¿Õ  OPA2 N¶Ë
// OP1O
#define SET_PIN_OP1S0_OPEN()    { _gsw0 = 0;}   //!< OP1S0 ¸¡¿Õ
#define SET_PIN_OP1S0_OP1O()    { _gsw0 = 1;}   //!< OP1S0 ßB½Ó OPA1 Ý”³ö
#define SET_PIN_OP1S1_OPEN()    { _gsw1 = 0;}   //!< OP1S1 ¸¡¿Õ
#define SET_PIN_OP1S1_OP1O()    { _gsw1 = 1;}   //!< OP1S1 ßB½Ó OPA1 Ý”³ö
// OP2O
#define SET_PIN_OP2O_OPEN()     { _gsw6 = 0;}   //!< OP2O ¸¡¿Õ
#define SET_PIN_OP2O_OP2O()     { _gsw6 = 1;}   //!< OP2O ßB½Ó OPA2 Ý”³ö
//					-----OPA3 Definition------;
#define SET_OPA34_POWER(x)          { _bopaen  = x; _opa3en = x;}
#define SET_OPA3_MODE_NORMAL()      { _opa3ofm = 0;}
#define SET_OPA3_MODE_CALOFFSET()   { _opa3ofm = 1; _opa3rs = 1;}

// RF1&RF2
#define SET_PIN_RF1_OPEN()          { _bswrf1 = 0;}
#define SET_PIN_RF1_OP3O()          { _bswrf1 = 1;}
#define SET_PIN_RF2_OPEN()          { _bswrf2 = 0;}
#define SET_PIN_RF2_OP3O()          { _bswrf2 = 1;}
// SINI
#define SET_PIN_SINI_OPEN()         { _bswsini = 0;}
#define SET_PIN_SINI_OP3N()         { _bswsini = 1;}
// OP3P ¹Ì¶¨žé1/2AVDD
//					-----OPA4 Definition------;
#define SET_PIN_OPA4_RF1()          { _bswc0 = 0x24; _bswc1 = 0x00;}
// #define SET_PIN_OPA4_RF1()          { _bswc0 = 0x18; _bswc1 = 0x00;}
#define SET_PIN_OPA4_RF2()          { _bswc0 = 0x21; _bswc1 = 0x00;}
// #define SET_PIN_OPA4_RF2()          { _bswc0 = 0x12; _bswc1 = 0x00;}
#define SET_PIN_OPA4_RX1()          { _bswc0 = 0x10; _bswc1 = 0x02;}
// #define SET_PIN_OPA4_RX1()          { _bswc0 = 0x20; _bswc1 = 0x01;}
#define SET_PIN_OPA4_RX2()          { _bswc0 = 0x90; _bswc1 = 0x00;}
// #define SET_PIN_OPA4_RX2()          { _bswc0 = 0x60; _bswc1 = 0x00;}

#define	SET_OPA4_GAIN_1()			{ _bopac0 &= 0xF0; _bopac0 |= 0x00;}
#define	SET_OPA4_GAIN_1_14()		{ _bopac0 &= 0xF0; _bopac0 |= 0x01;}
#define	SET_OPA4_GAIN_1_31()		{ _bopac0 &= 0xF0; _bopac0 |= 0x02;}
#define	SET_OPA4_GAIN_1_5()		    { _bopac0 &= 0xF0; _bopac0 |= 0x03;}
#define	SET_OPA4_GAIN_1_73()		{ _bopac0 &= 0xF0; _bopac0 |= 0x04;}
#define	SET_OPA4_GAIN_2()			{ _bopac0 &= 0xF0; _bopac0 |= 0x05;}
#define	SET_OPA4_GAIN_2_33()		{ _bopac0 &= 0xF0; _bopac0 |= 0x06;}
#define	SET_OPA4_GAIN_2_75()		{ _bopac0 &= 0xF0; _bopac0 |= 0x07;}
#define	SET_OPA4_GAIN_3_285()		{ _bopac0 &= 0xF0; _bopac0 |= 0x08;}
#define	SET_OPA4_GAIN_4()			{ _bopac0 &= 0xF0; _bopac0 |= 0x09;}
#define	SET_OPA4_GAIN_5() 		    { _bopac0 &= 0xF0; _bopac0 |= 0x0A;}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// ====================================================================================@
//                                 VG  PIN Select                                      @
// ====================================================================================@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#define SET_PIN_VG0_OPEN()          { _gsvg02 = 0; _gsvg01 = 0; _gsvg00 = 0;}
#define SET_PIN_VG0_GND()           { _gsvg02 = 1; _gsvg01 = 0; _gsvg00 = 0;}
#define SET_PIN_VG0_DAC2O()         { _gsvg02 = 0; _gsvg01 = 1; _gsvg00 = 0;}
#define SET_PIN_VG0_DAC1O()         { _gsvg02 = 0; _gsvg01 = 0; _gsvg00 = 1;}

#define SET_PIN_VG1_OPEN()          { _gsvg12 = 0; _gsvg11 = 0; _gsvg10 = 0;}
#define SET_PIN_VG1_GND()           { _gsvg12 = 1; _gsvg11 = 0; _gsvg10 = 0;}
#define SET_PIN_VG1_DAC2O()         { _gsvg12 = 0; _gsvg11 = 1; _gsvg10 = 0;}
#define SET_PIN_VG1_DAC1O()         { _gsvg12 = 0; _gsvg11 = 0; _gsvg10 = 1;}

#define SET_RX1_MODE_RF1()          { _bswsino2 = 0; _bswsino1 = 1; _bswrf2 = 0;_bswrf1 = 1;}
#define SET_RX1_MODE_RF2()          { _bswsino2 = 0; _bswsino1 = 1; _bswrf2 = 1;_bswrf1 = 0;}
#define SET_RX2_MODE_RF1()          { _bswsino2 = 1; _bswsino1 = 0; _bswrf2 = 0;_bswrf1 = 1;}
#define SET_RX2_MODE_RF2()          { _bswsino2 = 1; _bswsino1 = 0; _bswrf2 = 1;_bswrf1 = 0;}

#endif
#ifndef _AFEADC_H_
#define _AFEADC_H_

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// ====================================================================================@
//                              24Bit ADC 基本設置                                      @
// ====================================================================================@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#define SET_ADCPOWER(x)			    { _adoff = !x; _adslp = !x;}    //!< ADC電源開關
#define SET_ADC_STARTCONVERT()		{ _adrst = 0; _adrst = 1; _adrst = 0; _adcdl = 0; _eoc = 0; }   //!< 開始ADC轉換，開啟后即可連續獲取ADC值無需再開啟
#define SET_ADCINTERRUPT_ENABLE()   { _adf = 0; _ade = 1; _emi = 1;}    //!< 開啟ADC中斷和全局中斷
#define SET_ADCINTERRUPT_DISABLE()  { _ade = 0;}    //!< 關閉ADC中斷

#define SET_ADC_INPUT_SHORT(x)    { _inis = x;} //!< ADC內短開關  正常應用必須設置為DISABLE  ENABLE后ADC輸出為0 主要用於debug使用

#define SET_VREF_GAIN_1()		{ _vgs1=0; _vgs0 = 0;}  //!< 參考電壓放大倍率設置為1
#define SET_VREF_GAIN_0_5()		{ _vgs1=0; _vgs0 = 1;}  //!< 參考電壓放大倍率設置為0.5*(VREFP~VREFN)
#define SET_VREF_GAIN_0_25()	{ _vgs1=1; _vgs0 = 0;}  //!< 參考電壓放大倍率設置為0.25*(VREFP~VREFN)

#define SET_ADC_GAIN_1()		{ _ags1=0; _ags0 = 0;}  //!< ADC數位放大設置為1
#define SET_ADC_GAIN_2()		{ _ags1=0; _ags0 = 1;}  //!< ADC數位放大設置為2
#define SET_ADC_GAIN_4()		{ _ags1=1; _ags0 = 0;}  //!< ADC數位放大設置為4
//!< PGA放大倍率選擇
#define SET_PGA_BYPASS_WITHBUF()	    { _pgabp = 1;  _pgabpbuf = 1;}  //!< 設置PGA bypass(無放大) 無buf 輸入範圍無限制，但內阻較小，傳感器阻抗較大不適用
#define SET_PGA_BYPASS_WITHOUTBUF()	    { _pgabp = 1;  _pgabpbuf = 0;}  //!< 設置PGA bypass(無放大) 有buf 輸入範圍有datasheet範圍限制，但ADC內阻較大，適用傳感器輸出阻抗較大
#define SET_PGA_GAIN_1()		{ _pgabp = 0; _pgas2=0; _pgas1 = 0; _pgas0 = 0;}    //!< PGA倍率為1倍
#define SET_PGA_GAIN_2()		{ _pgabp = 0; _pgas2=0; _pgas1 = 0; _pgas0 = 1;}    //!< PGA倍率為2倍
#define SET_PGA_GAIN_4()		{ _pgabp = 0; _pgas2=0; _pgas1 = 1; _pgas0 = 0;}    //!< PGA倍率為4倍
#define SET_PGA_GAIN_8()		{ _pgabp = 0; _pgas2=0; _pgas1 = 1; _pgas0 = 1;}    //!< PGA倍率為8倍
#define SET_PGA_GAIN_16()		{ _pgabp = 0; _pgas2=1; _pgas1 = 0; _pgas0 = 0;}    //!< PGA倍率為16倍
#define SET_PGA_GAIN_32()		{ _pgabp = 0; _pgas2=1; _pgas1 = 0; _pgas0 = 1;}    //!< PGA倍率為32倍
#define SET_PGA_GAIN_64()		{ _pgabp = 0; _pgas2=1; _pgas1 = 1; _pgas0 = 0;}    //!< PGA倍率為64倍
#define SET_PGA_GAIN_128()		{ _pgabp = 0; _pgas2=1; _pgas1 = 1; _pgas0 = 1;}    //!< PGA倍率為128倍
//!< 差分?入信? PGAOP/PGAON 偏置??位
#define SET_ADC_DCSET_0V()			{ _dcset2=0; _dcset1 = 0; _dcset0 = 0;}     //!< DCSET=+0V
#define SET_ADC_DCSET_UP_0_25()		{ _dcset2=0; _dcset1 = 0; _dcset0 = 1;}     //!< DCSET= +0.25 × ΔVR_I
#define SET_ADC_DCSET_UP_0_5()		{ _dcset2=0; _dcset1 = 1; _dcset0 = 0;}     //!< DCSET= +0.5  × ΔVR_I
#define SET_ADC_DCSET_UP_0_75()		{ _dcset2=0; _dcset1 = 1; _dcset0 = 1;}     //!< DCSET= +0.75 × ΔVR_I
#define SET_ADC_DCSET_DOWN_0_25()	{ _dcset2=1; _dcset1 = 0; _dcset0 = 1;}     //!< DCSET= -0.25 × ΔVR_I
#define SET_ADC_DCSET_DOWN_0_5()	{ _dcset2=1; _dcset1 = 1; _dcset0 = 0;}     //!< DCSET= -0.5  × ΔVR_I
#define SET_ADC_DCSET_DOWN_0_75()	{ _dcset2=1; _dcset1 = 1; _dcset0 = 1;}     //!< DCSET= -0.75 × ΔVR_I
// ADC通道D-選擇
#define SET_ADC_CHANNEL_N_AN1()		{ _chsn3=0; _chsn2=0; _chsn1=0; _chsn0=0;}  //!< 外部ADC通道-AN1
#define SET_ADC_CHANNEL_N_AN3()		{ _chsn3=0; _chsn2=0; _chsn1=0; _chsn0=1;}  //!< 外部ADC通道-AN3
#define SET_ADC_CHANNEL_N_AN5()		{ _chsn3=0; _chsn2=0; _chsn1=1; _chsn0=0;}  //!< 外部ADC通道-AN5
#define SET_ADC_CHANNEL_N_DAC1O()	{ _chsn3=0; _chsn2=0; _chsn1=1; _chsn0=1;}  //!< 內部ADC通道-DAC1O輸出電壓點
#define SET_ADC_CHANNEL_N_DAC2O()	{ _chsn3=0; _chsn2=1; _chsn1=0; _chsn0=0;}  //!< 內部ADC通道-DAC2O輸出電壓點
#define SET_ADC_CHANNEL_N_MOD1ON()	{ _chsn3=0; _chsn2=1; _chsn1=0; _chsn0=1;}  //!< 內部ADC通道-搭配MOD1OP一起使用:FWR模式為Z值N端/IQ模式為RE N端
#define SET_ADC_CHANNEL_N_MOD2ON()	{ _chsn3=0; _chsn2=1; _chsn1=1; _chsn0=0;}  //!< 內部ADC通道-搭配MOD2OP一起使用:FWR模式無用/IQ模式為IM N端
#define SET_ADC_CHANNEL_N_VDD_6()	{ _chsn3=0; _chsn2=1; _chsn1=1; _chsn0=1;}  //!< 內部ADC通道-1/6VDD電壓 和1/5VDD搭配量測VDD電壓
#define SET_ADC_CHANNEL_N_OP1N1()	{ _chsn3=1; _chsn2=0; _chsn1=0; _chsn0=0;}  //!< 內部ADC通道-OPA1-1 N端 通常搭配OPA1輸出端量測反饋電阻電壓
#define SET_ADC_CHANNEL_N_OP1N2()	{ _chsn3=1; _chsn2=0; _chsn1=0; _chsn0=1;}  //!< 內部ADC通道-OPA1-2 N端 通常搭配OPA1輸出端量測反饋電阻電壓
#define SET_ADC_CHANNEL_N_OP2N()	{ _chsn3=1; _chsn2=0; _chsn1=1; _chsn0=0;}  //!< 內部ADC通道-OPA2   N端 通常搭配OPA2輸出端量測反饋電阻電壓
#define SET_ADC_CHANNEL_N_AVSS()	{ _chsn3=1; _chsn2=0; _chsn1=1; _chsn0=1;}  //!< 內部ADC通道-AVSS 單端應用時使用，若有使用PGA需要設置為bypass

#define SET_ADC_CHANNEL_P_AN0()		{ _chsp3=0; _chsp2=0; _chsp1=0; _chsp0=0;}  //!< 外部ADC通道-AN0
#define SET_ADC_CHANNEL_P_AN2()		{ _chsp3=0; _chsp2=0; _chsp1=0; _chsp0=1;}  //!< 外部ADC通道-AN2
#define SET_ADC_CHANNEL_P_AN4()		{ _chsp3=0; _chsp2=0; _chsp1=1; _chsp0=0;}  //!< 外部ADC通道-AN4
#define SET_ADC_CHANNEL_P_DAC1O()	{ _chsp3=0; _chsp2=0; _chsp1=1; _chsp0=1;}  //!< 內部ADC通道-DAC1O輸出電壓點
#define SET_ADC_CHANNEL_P_DAC2O()	{ _chsp3=0; _chsp2=1; _chsp1=0; _chsp0=0;}  //!< 內部ADC通道-DAC2O輸出電壓點
#define SET_ADC_CHANNEL_P_MOD1OP()	{ _chsp3=0; _chsp2=1; _chsp1=0; _chsp0=1;}  //!< 內部ADC通道-搭配MOD1ON一起使用:FWR模式為Z值P端/IQ模式為RE P端
#define SET_ADC_CHANNEL_P_MOD2OP()	{ _chsp3=0; _chsp2=1; _chsp1=1; _chsp0=0;}  //!< 內部ADC通道-搭配MOD2ON一起使用:FWR模式無用/IQ模式為IM P端
#define SET_ADC_CHANNEL_P_OP1S0()	{ _chsp3=0; _chsp2=1; _chsp1=1; _chsp0=1;}  //!< 內部ADC通道-OPA1-0 輸出端 通常搭配OPA1-N端量測反饋電阻電壓
#define SET_ADC_CHANNEL_P_OP1S1()	{ _chsp3=1; _chsp2=0; _chsp1=0; _chsp0=0;}  //!< 內部ADC通道-OPA1-1 輸出端 通常搭配OPA1-N端量測反饋電阻電壓
#define SET_ADC_CHANNEL_P_OP2O()	{ _chsp3=1; _chsp2=0; _chsp1=0; _chsp0=1;}  //!< 內部ADC通道-OPA2   輸出端 通常搭配OPA2-N端量測反饋電阻電壓
#define SET_ADC_CHANNEL_P_AVDD_5()	{ _chsp3=1; _chsp2=0; _chsp1=1; _chsp0=0;}  //!< 內部ADC通道-1/5VDD電壓 和1/6VDD搭配量測VDD電壓
#define SET_ADC_CHANNEL_P_AVSS()	{ _chsp3=1; _chsp2=0; _chsp1=1; _chsp0=1;}  //!< 內部ADC通道-AVSS 單端應用時使用，若有使用PGA需要設置為bypass

//!< ADC DATA RARE 計算方式如下:
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
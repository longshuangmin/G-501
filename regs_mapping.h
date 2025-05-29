#ifndef _regs_mapping_h_
#define _regs_mapping_h_

#include <BH67F2485.h>

#define __EMUREG_BHSN3__
#define __EMUREG_IAP2__

//*******************************************************
// System frequency setting SFR
// UARTn SFR
//******************************************************* 
//******************************************************* 
#ifdef __EMUREG_BHSN1__
//#ifdef __EMUREG_BH66F2650__
//#ifdef __EMUREG_BH66F2660__
//#ifdef __EMUREG_BH66F2260__
	#define regSmod _hircc
	#define regHto _hircf

	#define regTxRx _txr_rxr
	#define regUsr _usr
	#define regBrg _brg
	#define regUcr1 _ucr1
	#define regUcr2 _ucr2
	
	#define regUif	_urf
	#define regUie	_ure
#endif

#ifdef __EMUREG_BHSN2__
//#ifdef __EMUREG_BH67F2260__
	#define regSmod _hircc
	#define regHto _hircf

	#define regTxRx _txr_rxr1
	#define regUsr _u1sr
	#define regBrg _brg1
	#define regUcr1 _u1cr1
	#define regUcr2 _u1cr2

	#define regUif	_urf
	#define regUie	_ure
#endif

#ifdef __EMUREG_BHSN3__
//#ifdef __EMUREG_BH66F2470__
//#ifdef __EMUREG_BH67F2270__ 
//#ifdef __EMUREG_BH67F2270__
//#ifdef __EMUREG_BH67F2480__
//#ifdef __EMUREG_BH67F2470__
	#define regSmod _hircc
	#define regHto _hircf
	
	#define regTxRx _txr_rxr1
	#define regUsr  _u1sr
	#define regBrg  _brg1
	#define regUcr1 _u1cr1
	#define regUcr2 _u1cr2

	#define regUif	_ur1f
	#define regUie	_ur1e
#endif

#ifdef __EMUREG_BHSN4__
//#ifdef __EMUREG_BH67F2262__
//#ifdef __EMUREG_BH45F68__
//#ifdef __EMUREG_BH66F5250__
//#ifdef __EMUREG_BH67F5250__
//#ifdef __EMUREG_BH67F5260__
//#ifdef __EMUREG_BH67F5270__
	#define regSmod _hircc
	#define regHto _hircf

	#define regTxRx _utxr_rxr
	#define regUsr _uusr
	#define regBrg _ubrg
	#define regUcr1 _uucr1
	#define regUcr2 _uucr2

	#define regUif	_usimf
	#define regUie	_usime
#endif

#ifdef __EMUREG_BHSN5__
//#ifdef __EMUREG_BH67F2762__
	#define regSmod _hircc
	#define regHto _hircf

	#define regTxRx _txr_rxr
	#define regUsr _usr
	#define regBrg _brg
	#define regUcr1 _ucr1
	#define regUcr2 _ucr2

	#define regUif	_usimf
	#define regUie	_usime
#endif 

#ifdef __EMUREG_BSSN1__
//#ifdef __EMUREG_BS66F350__
//#ifdef __EMUREG_BS66F360__
//#ifdef __EMUREG_BS66F370__
//#ifdef __EMUREG_BS67F350__
//#ifdef __EMUREG_BS67F360__
//#ifdef __EMUREG_BS67F370__
//#ifdef __EMUREG_BS66FV350__
//#ifdef __EMUREG_BS66FV360__
//#ifdef __EMUREG_BS67F350C__
	#define regSmod _hircc
	#define regHto _hircf
	
	#define regTxRx _txr_rxr
	#define regUsr _usr
	#define regBrg _brg
	#define regUcr1 _ucr1
	#define regUcr2 _ucr2

	#define regUif	_urf
	#define regUie	_ure
#endif

#ifdef __EMUREG_BSSN2__
//#ifdef __EMUREG_BS66F360C__
	#define regSmod _hircc
	#define regHto _hircf
	
	#define regTxRx _txr_rxr
	#define regUsr _usr
	#define regBrg _brg
	#define regUcr1 _ucr1
	#define regUcr2 _ucr2

	#define regUif	_uartf
	#define regUie	_uarte
#endif

#ifdef __EMUREG_BASN1__
//#ifdef __EMUREG_BA45F5250__
	#define regSmod _hircc
	#define regHto _hircf

	#define regTxRx _txr_rxr
	#define regUsr _usr
	#define regBrg _brg
	#define regUcr1 _ucr1
	#define regUcr2 _ucr2
	
	#define regUif	_urf
	#define regUie	_ure
#endif 

#ifdef __EMUREG_HTSN1__
//#ifdef __EMUREG_HT45F65__
//#ifdef __EMUREG_HT45F66__
//#ifdef __EMUREG_HT45F67__
	#define regSmod _smod0
	#define regHto _hto
	
	#define regTxRx _txrrxr
	#define regUsr _usr
	#define regBrg _brg
	#define regUcr1 _ucr1
	#define regUcr2 _ucr2
	
	#define regUif	_urf
	#define regUie	_ure
#endif 
#ifdef __EMUREG_HTSN2__
//#ifdef __EMUREG_HT67F370__
//#ifdef __EMUREG_HT67F86A__
	#define regSmod _hircc
	#define regHto _hircf
	
	#define regTxRx _txr_rxr
	#define regUsr _usr
	#define regBrg _brg
	#define regUcr1 _ucr1
	#define regUcr2 _ucr2
	
	#define regUif	_urf
	#define regUie	_ure
#endif 	
#ifdef __EMUREG_HTSN3__
//#ifdef __EMUREG_HT69F360__
	#define regSmod _hircc
	#define regHto _hircf
	
	#define regTxRx _txr_rxr
	#define regUsr _usr
	#define regBrg _brg
	#define regUcr1 _ucr1
	#define regUcr2 _ucr2
	
	#define regUif	_uartf
	#define regUie	_uarte
#endif 	
#ifdef __EMUREG_HTSN4__
//#ifdef __EMUREG_HT45F77__
//#ifdef __EMUREG_HT45F75__
//#ifdef __EMUREG_HT67F5652__
//#ifdef __EMUREG_HT67F5650__
//#ifdef __EMUREG_HT67F5660__
	#define regSmod _smod
	#define regHto _hto
	
	#define regTxRx _txr_rxr
	#define regUsr _usr
	#define regBrg _brg
	#define regUcr1 _ucr1
	#define regUcr2 _ucr2
	
	#define regUif	_uif
	#define regUie	_uie
#endif 	
#ifdef __EMUREG_HTSN5__
//#ifdef __EMUREG_HT66F2560__
//#ifdef __EMUREG_HT66F2360__
//#ifdef __EMUREG_HT66F2370__
//#ifdef __EMUREG_HT66F2390__
//#ifdef __EMUREG_HT67F2350__
//#ifdef __EMUREG_HT67F2360__
//#ifdef __EMUREG_HT67F2370__
//#ifdef __EMUREG_HT67F2390__
	#define regSmod _hircc
	#define regHto _hircf
	
	#define regTxRx _txr_rxr1
	#define regUsr  _u1sr
	#define regBrg  _brg1
	#define regUcr1 _u1cr1
	#define regUcr2 _u1cr2

	#define regUif	_ur1f
	#define regUie	_ur1e
#endif 	
#ifdef __EMUREG_HTSN6__
//#ifdef __EMUREG_HT66FB570__
//#ifdef __EMUREG_HT66FB572__
	#define regSmod _hircc
	#define regHto _hircf
	
	#define regTxRx _txr_rxr
	#define regUsr  _usr
	#define regBrg  _brg
	#define regUcr1 _ucr1
	#define regUcr2 _ucr2

	#define regUif	_urf
	#define regUie	_ure
#endif 	

#ifdef __EMUREG_HTSN7__
//#ifdef __EMUREG_HT45F77__
	#define regSmod _smod
	#define regHto _hto
	
	#define regTxRx _txrrxr
	#define regUsr  _usr
	#define regBrg  _brg
	#define regUcr1 _ucr1
	#define regUcr2 _ucr2

	#define regUif	_uif
	#define regUie	_uie
#endif 	

#ifdef __EMUREG_HTSN8__
//#ifdef __EMUREG_HT67F2567__
	#define regSmod _hircc
	#define regHto _hircf

	#define regTxRx _utxr_rxr
	#define regUsr _uusr
	#define regBrg _ubrg
	#define regUcr1 _uucr1
	#define regUcr2 _uucr2

	#define regUif	_usimf
	#define regUie	_usime
#endif


//*******************************************************
// IAP(Flash) SFR
//******************************************************* 
#ifdef __EMUREG_IAP1__
	#define regfc0 _fcr
	#define regfc2 _frcr
	#define regfcl _wdtc
	#define regbit_fwpen _bwt 
	#define RESET_CODE 0xFF
#endif

#ifdef __EMUREG_IAP2__
	#define regfc0 _fc0
	#define regfc2 _fc2
	#define regfcl _fc1
	#define regbit_fwpen _fwpen 
	#define RESET_CODE 0x55
#endif


#endif // _regs_mapping_h_
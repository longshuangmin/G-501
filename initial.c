#include "include.h"


//--------------------------------------------------------------------------
void SystemRAM_clear (void)
{    
	_mp1h = 0;
	_mp1l = 0x80;
	while(_mp1h <32)
	{
		for(_tblp = 0x00;_tblp < 128;_tblp++)
		{
			 _iar1 = 0;
			  _mp1l++;
		}
		_mp1l = 0x80;
		_mp1h++;
	}
	_mp1h = 0;
	_mp1l = 0x80;		 
}

//--------------------------------------------------------------------------
void Initial_SysClock(void)
{
//		_pas0 = 0xc0;
//		_pas1 = 0x03;
#if ACFG_OSC_EN
		_pas0 = 0x33;
		_pas1 = 0x00;
#endif		
#if ACFG_OSC_EN
		_scc =  0b00000100;
#else
		_scc =  0b00000000;
#endif
						//Bit 7~5 CKS2~CKS0: System clock selection
						//000: fH
						//001: fH/2
						//010: fH/4
						//011: fH/8
						//100: fH/16
						//101: fH/32
						//110: fH/64
						//111: fSUB
						//These three bits are used to select which clock is used as the system clock source. In
						//addition to the system clock source directly derived from fH or fSUB, a divided version
						//of the high speed system oscillator can also be chosen as the system clock source.
						//Bit 4 Unimplemented, read as ‚Ä?„Ä?
						//Bit 3 FHS: High frequency clock selection
						//0: HIRC
						//1: HXT
						//Bit 2 FSS: Low frequency clock selection
						//0: LIRC
						//1: LXT
						//Bit 1 FHIDEN: High frequency oscillator control when CPU is switched off
						//0: Disable
						//1: Enable
						//This bit is used to control whether the high speed oscillator is activated or stopped
						//when the CPU is switched off by executing an ‚Ä•HALT„Ä?instruction.
						//Bit 0 FSIDEN: Low frequency oscillator control when CPU is switched off
						//0: Disable
						//1: Enable
						//This bit is used
						
		_hircc =  0b00000001;
						//Bit 7~4 Unimplemented, read as ‚Ä?„Ä?
						//Bit 3~2 HIRC1~HIRC0: HIRC frequency selection
						//00: 4MHz
						//01: 8MHz
						//10: 12MHz
						//11: 4MHz
						//When the HIRC
						//Bit 1 HIRCF: HIRC oscillator stable flag
						//0: Unstable
						//1: Stable
						//This bit is used to indicate whether the HIRC oscillator is stable or not. When the
						//HIRCEN bit is set to 1 to enable the HIRC oscillator, the HIRCF bit will first be
						//cleared to 0 and then set to 1 after the HIRC oscillator is stable.
						//Bit 0 HIRCEN: HIRC oscillator enable control
						//0: Disable
						//1: Enable								
		while(!_hircf)
			GCC_CLRWDT();						
				

										
//		_hxtc =  0b00000001;
//						//Bit 7~3 Unimplemented, read as ‚Ä?„Ä?
//						//Bit 2 HXTM: HXT mode selection
//						//0: HXT frequency ? 10MHz
//						//1: HXT frequency > 10MHz
//						//This bit is used to select the HXT oscillator operating mode. Note that this bit must
//						//be properly configured before the HXT is enabled. When the HXTEN bit is set to 1 to
//						//enable the HXT oscillator, it is invalid to change the value of this bit.
//						//Bit 1 HXTF: HXT oscillator stable flag
//						//0: Unstable
//						//1: Stable
//						//This bit is used to indicate whether the HXT oscillator is stable or not. When the
//						//HXTEN bit is set to 1 to enable the HXT oscillator, the HXTF bit will first be cleared
//						//to 0 and then set to 1 after the HXT oscillator is stable.
//						//Bit 0 HXTEN: HXT oscillator enable control
//						//0: Disable
//						//1: Enable
//		while(!_hxtf)
//			GCC_CLRWDT();

//		_lxtc =  0b00000001;
//						//Bit 7~2 Unimplemented, read as ‚Ä?‚Ä?
//						//Bit 1 LXTF: LXT oscillator stable flag
//						//0: Unstable
//						//1: Stable
//						//This bit is used to indicate whether the LXT oscillator is stable or not. When the
//						//LXTEN bit is set to 1 to enable the LXT oscillator, the LXTF bit will first be cleared
//						//to 0 and then set to 1 after the LXT oscillator is stable.
//						//Bit 0 LXTEN: LXT oscillator enable control
//						//0: Disable
//		while(!_lxtf)
//			GCC_CLRWDT();	

#if ACFG_OSC_EN
				_lxtc =  0b00000001;
				//Bit 7~2 Unimplemented, read as °∞0°±
				//Bit 1 LXTF: LXT oscillator stable flag
				//0: Unstable
				//1: Stable
				//This bit is used to indicate whether the LXT oscillator is stable or not. When the
				//LXTEN bit is set to 1 to enable the LXT oscillator, the LXTF bit will first be cleared
				//to 0 and then set to 1 after the LXT oscillator is stable.
				//Bit 0 LXTEN: LXT oscillator enable control
				//0: Disable
				while(!_lxtf)
					GCC_CLRWDT();	
#endif			
			
}

//--------------------------------------------------------------------------
void Initial_SysLcd(void)
{
#if 0
		//--- LCD SEETING ----
		_lcdc0 = 0b10000000;
		//Bit 7 TYPE: LCD waveform type selection
		//0: Type A
		//1: Type B
		//Bit 6 Unimplemented, read as ‚Ä?„Ä?
		//Bit 5~4 LCDP1~LCDP0: C type LCD power source selection
		//00: From external pin PLCD/V1/V2
		//01: From internal reference voltage VREFIN supplied to VC
		//10: From internal voltage 3V supplied to VB
		//11: From internal voltage VDD supplied to VA
		//The VREFIN is an internal reference voltage with an approximate level of 1.08V.
		//Bit 3~1 Unimplemented, read as ‚Ä?„Ä?
		//Bit 0 LCDEN: LCD Enable Control
		//0: Disable
		//1: Enable
		_lcdcp = 0b00001010;		

		_lcdc2 = 0b10100010;
		//Bit7~5 LCDPCK2 ~LCDPCK0: C type LCD pump clock divider selection
		//000: 250Hz (divided by 128).
		//001: 500Hz (divided by 64)
		//010: 1kHz (divided by 32)
		//011: 2kHz (divided by 16)
		//100: 4kHz (divided by 8).
		//101: 8kHz (divided by 4)
		//110: 16kHz (divided by 2)
		//111: 16kHz (divided by 2)
		//The selection is based on the 32kHz LCD clock source.
		//Bit 4~3 Unimplemented, read as ‚Ä?„Ä?
		//Bit 2~1 DTYC1~DTYC0: LCD duty selection
		//00: 1/4 duty (COM0~COM3)
		//01: 1/6 duty (COM0~COM5)
		//10: 1/8 duty (COM0~COM7), for R type only
		//11: unimplemented
		//The unused COM pins are allowed to be configured as normal I/O or other pin-shared
		//functions.
		//Bit 0 Unimplemented, read as ‚Ä?
#else
		_lcdc0 = 0b10000000;
		_lcdcp = 0b00001000;
		_lcdc2 = 0b10100010;
#endif
}

//--------------------------------------------------------------------------
void Initial_SysStm(void)
{
		//--- SETTING 10 BIT TIMER0
//		_tm0al = 0xF4;       //;;4MHZ
//		_tm0ah = 0x01;       //;TIMER0 10 BIT TIMER  =1000 X 0.25uS = 250us 
//		_stmal = 0x00ff & 125;     //;;4MHZ
//		_stmah = (0xff00 & 125) >> 8;	//;TIMER0 10 BIT TIMER  =1000 X 0.25uS = 250us 
		
		_stmc0 = 0b00000000;
						//Bit 7 STPAU: STM Counter Pause Control
						//0: Run
						//1: Pause
						//The counter
						//Bit 6~4 STCK2~STCK0: Select STM Counter Clock
						//000: fSYS/4
						//001: fSYS
						//010: fH/16
						//011: fH/64
						//100: fSUB
						//101: fSUB
						//110: STCK rising edge clock
						//111: STCK falling edge clock
						//Bit 3 STON: STM Counter On/Off Control
						//0: Off
						//1: On
						//Bit 2~0 Unimplemented, read as "0"
		
		_stmc1 = 0b00111001;
						//Bit 7~6 STM1~STM0: Select STM Operating Mode
						//00: Compare Match Output Mode
						//01: Capture Input Mode
						//10: PWM Output Mode or Single Pulse Output Mode
						//11: Timer/Counter Mode
						//Bit 5~4 STIO1~STIO0: Select STM External Pin (STP or STPI) Function
						//Compare Match Output Mode
						//00: No change
						//01: Output low
						//10: Output high
						//11: Toggle output
						//PWM Output Mode/Single Pulse Output Mode
						//00: PWM output inactive state
						//01: PWM output active state
						//10: PWM output
						//11: Single Pulse Output
						//Capture Input Mode
						//00: Input capture at rising edge of STPI
						//01: Input capture at falling edge of STPI
						//10: Input capture at rising/falling edge of STPI
						//11: Input capture disabled
						//Bit 3 STOC: STM STP Output Control
						//Compare Match Output Mode
						//0: Initial low
						//1: Initial high
						//PWM Output Mode/Single Pulse Output Mode
						//0: Active low
						//1: Active high
						//Bit 2 STPOL: STM STP Output Polarity Control
						//0: Non-inverted
						//1: Inverted
						//Bit 1 STDPX: STM PWM Duty/Period Control
						//0: CCRP Óì?period; CCRA Óì?duty
						//1: CCRP Óì?duty; CCRA Óì?period
						//Bit 0 STCCLR: STM Counter Clear Condition Selection
						//0: Comparator P match
						//1: Comparator A match
}

//--------------------------------------------------------------------------
void Initial_SysPTM0(void)
{
		//--- SETTING 10 BIT TIMER0
		#if ACFG_OSC_EN==0
		_ptm0al = 0x00ff & 125;     //;;4MHZ
		_ptm0ah = (0xff00 & 125) >> 8;	//;TIMER0 10 BIT TIMER  =125 X 1uS = 125us
		#else
		_ptm0al = 0x00ff & 328;     //;;32.768kMHZ
		_ptm0ah = (0xff00 & 328) >> 8;	//;TIMER0 10 BIT TIMER  =328 X 30.5176uS = 10.0097ms
		#endif
		//_ptm0rpl = 0x00ff & 250;     //;;4MHZ
		//_ptm0rph = (0xff00 & 250) >> 8;	//;TIMER0 10 BIT TIMER  =1000 X 0.25uS = 250us
		#if ACFG_OSC_EN==0	
		_ptm0c0 = 0b00000000;
		#else
		_ptm0c0 = 0b01000000;
		#endif
						//Bit 7 PTnPAU: PTMn Counter Pause Control
						//0: Run
						//1: Pause
						//Bit 6~4 PTnCK2~PTnCK0: Select PTMn Counter Clock
						//000: fSYS/4
						//001: fSYS
						//010: fH/16
						//011: fH/64
						//100: fSUB
						//101: fSUB
						//110: PTCKn rising edge clock
						//111: PTCKn falling edge clock
						//Bit 3 PTnON: PTMn Counter On/Off Control
						//0: Off
						//1: On
						//Bit 2~0 Unimplemented, read as ‚Ä?‚Ä?
								
		_ptm0c1 = 0b11000001;
						//Bit 7~6 PTnM1~PTnM0: Select PTMn Operating Mode
						//00: Compare Match Output Mode
						//01: Capture Input Mode
						//10: PWM Output Mode or Single Pulse Output Mode
						//11: Timer/Counter Mode
						//Bit 5~4 PTnIO1~PTnIO0: Select PTMn External Pin (PTPn, PTPnI or PTCKn) Function
						//Compare Match Output Mode
						//00: No change
						//01: Output low
						//10: Output high
						//11: Toggle output
						//PWM Output Mode/Single Pulse Output Mode
						//00: PWM Output inactive state
						//01: PWM Output active state
						//10: PWM output
						//11: Single pulse output
						//Capture Input Mode
						//00: Input capture at rising edge of PTPnI or PTCKn
						//01: Input capture at falling edge of PTPnI or PTCKn
						//10: Input capture at falling/rising edge of PTPnI or PTCKn
						//11: Input capture disabled
						//Timer/Counter Mode
						//Unused
						//Bit 3 PTnOC: PTMn PTPn Output Control bit
						//Compare Match Output Mode
						//0: Initial low
						//1: Initial high
						//PWM Output Mode/Single Pulse Output Mode
						//0: Active low
						//1: Active high
						//Bit 2 PTnPOL: PTMn PTPn Output Polarity Control
						//0: Non-invert
						//1: Invert
						//This bit controls the polarity of the PTPn output pin. When the bit is set high the
						//PTMn output pin will be inverted and not inverted when the bit is zero. It has no effect
						//if the PTMn is in the Timer/Counter Mode.
						//Bit 1 PTnCAPTS: PTMn Capture Trigger Source Selection
						//0: From PTPnI pin
						//1: From PTCKn pin
						//Bit 0 PTnCCLR: Select PTMn Counter Clear Condition
						//0: Comparator P match
						//1: Comparator A match

}

//--------------------------------------------------------------------------
void Initial_SysTimebase(void)
{
		_pscr = 0x02;
						//Bit 7~2 Unimplemented, read as "0"
						//Bit 1~0 CLKSEL1~CLKSEL0: Prescaler clock source selection
						//00: fSYS
						//01: fSYS/4
						//1x: fSUB						

		_tb0c = 0x86;
						//Bit 7 TB0ON: Time Base 0 Control
						//0: Disable
						//1: Enable
						//Bit 6~3 Unimplemented, read as "0"
						//Bit 2~0 TB02~TB00: Select Time Base 0 Time-out Period
						//000: 28/fPSC
						//001: 29/fPSC
						//010: 210/fPSC
						//011: 211/fPSC
						//100: 212/fPSC
						//101: 213/fPSC
						//110: 214/fPSC
						//111: 215/fPSC
						
		_tb1c = 0x00;
						//Bit 7 TB1ON: Time Base 1 Control
						//0: Disable
						//1: Enable
						//Bit 6~3 Unimplemented, read as "0"
						//Bit 2~0 TB12~TB10: Select Time Base 1 Time-out Period
						//000: 28/fPSC
						//001: 29/fPSC
						//010: 210/fPSC
						//011: 211/fPSC
						//100: 212/fPSC
						//101: 213/fPSC
						//110: 214/fPSC
						//111: 215/fPSC
}

//--------------------------------------------------------------------------
void Initial_SysInt(void)
{
		_integ0 = 0b00000000;
					//Bit 7~6 INT3S1~INT3S0: Interrupt Edge Control for INT3 Pin
					//00: Disable
					//01: Rising edge
					//10: Falling edge
					//11: Rising and falling edges
					//Bit 5~4 INT2S1~INT2S0: Interrupt Edge Control for INT2 Pin
					//00: Disable
					//01: Rising edge
					//10: Falling edge
					//11: Rising and falling edges
					//Bit 3~2 INT1S1~INT1S0: Interrupt Edge Control for INT1 Pin
					//00: Disable
					//01: Rising edge
					//10: Falling edge
					//11: Rising and falling edges
					//Bit 1~0 INT0S1~INT0S0: Interrupt Edge Control for INT0 Pin
					//00: Disable
					//01: Rising edge
					//10: Falling edge
					//11: Rising and falling edges

		_integ1	 = 0b00000000;					
					//Bit 7~4 Unimplemented, read as ‚Ä?„Ä?
					//Bit 3~2 INT5S1~INT5S0: Interrupt Edge Control for INT5 Pin
					//00: Disable
					//01: Rising edge
					//10: Falling edge
					//11: Rising and falling edges
					//Bit 1~0 INT4S1~INT4S0: Interrupt Edge Control for INT4 Pin
					//00: Disable
					//01: Rising edge
					//10: Falling edge
					//11: Rising and falling edges				
						
		_intc0 = 0b00001000;
					//Bit 7 Unimplemented, read as ‚Ä?„Ä?
					//Bit 6 ADF: A/D Converter interrupt request flag
					//0: No request
					//1: Interrupt request
					//Bit 5 INT1F: External Interrupt 1 request flag
					//0: No request
					//1: Interrupt request
					//Bit 4 INT0F: External Interrupt 0 request flag
					//0: No request
					//1: Interrupt request
					//Bit 3 ADE: A/D Converter interrupt control
					//0: Disable
					//1: Enable
					//Bit 2 INT1E: External Interrupt 1 control
					//0: Disable
					//1: Enable
					//Bit 1 INT0E: External Interrupt 0 control
					//0: Disable
					//1: Enable
					//Bit 0 EMI: Global Interrupt control
					//0: Disable
					//1: Enable
		
		_intc1 = 0b00000001;
					//Bit 7 OVPF: Over Voltage Protection Interrupt Request Flag
					//0: No request
					//1: Interrupt request
					//Bit 6 MF2F: Multi-function Interrupt 2 Request Flag
					//0: No request
					//1: Interrupt request
					//Bit 5 MF1F: Multi-function Interrupt 1 Request Flag
					//0: No request
					//1: Interrupt request
					//Bit 4 MF0F: Multi-function Interrupt 0 Request Flag
					//0: No request
					//1: Interrupt request
					//Bit 3 OVPE: Over Voltage Protection Interrupt Control
					//0: Disable
					//1: Enable
					//Bit 2 MF2E: Multi-function Interrupt 2 Control
					//0: Disable
					//1: Enable
					//Bit 1 MF1E: Multi-function Interrupt 1 Control
					//0: Disable
					//1: Enable
					//Bit 0 MF0E: Multi-function Interrupt 0 Control
					//0: Disable
					//1: Enable
		
		_intc2 = 0b00000001;
					//Bit 7 INT3F: External Interrupt 3 Request Flag
					//0: No request
					//1: Interrupt request
					//Bit 6 INT2F: External Interrupt 2 Request Flag
					//0: No request
					//1: Interrupt request
					//Bit 5 TB1F: Time Base 1 Interrupt Request Flag
					//0: No request
					//1: Interrupt request
					//Bit 4 TB0F: Time Base 0 Interrupt Request Flag
					//0: No request
					//1: Interrupt request
					//Bit 3 INT3E: External Interrupt 3 Control
					//0: Disable
					//1: Enable
					//Bit 2 INT2E: External Interrupt 2 Control
					//0: Disable
					//1: Enable
					//Bit 1 TB1E: Time Base 1 Interrupt Control
					//0: Disable
					//1: Enable
					//Bit 0 TB0E: Time Base 0 Interrupt Control
					//0: Disable
					//1: Enable
					
		_intc3 = 0b00001000;
					//Bit 7 UR1F: UART1 Interrupt Request Flag
					//0: No request
					//1: Interrupt request
					//Bit 6 SPIF: SPI Interrupt Request Flag
					//0: No request
					//1: Interrupt request
					//Bit 5 SIMF: Serial Interface Module Interrupt Request Flag
					//0: No request
					//1: Interrupt request
					//Bit 4 UR0F: UART0 Interrupt Request Flag
					//0: No request
					//1: Interrupt request
					//Bit 3 UR1E: UART1 Interrupt Control
					//0: Disable
					//1: Enable
					//Bit 2 SPIE: SPI Interrupt Control
					//0: Disable
					//1: Enable
					//Bit 1 SIME: Serial Interface Module Interrupt Control
					//0: Disable
					//1: Enable
					//Bit 0 UR0E: UART0 Interrupt Control
					//0: Disable
					//1: Enable		
								
		
		_mfi0 = 0b00001000;
					//Bit 7 PTM0AF: PTM0 CCRA Comparator Interrupt Request Flag
					//0: No request
					//1: Interrupt request
					//Bit 6 PTM0PF: PTM0 CCRP Comparator Interrupt Request Flag
					//0: No request
					//1: Interrupt request
					//Bit 5 STMAF: STM CCRA Comparator Interrupt Request Flag
					//0: No request
					//1: Interrupt request
					//Bit 4 STMPF: STM CCRP Comparator Interrupt Request Flag
					//0: No request
					//1: Interrupt request
					//Bit 3 PTM0AE: PTM0 CCRA Comparator Interrupt Control
					//0: Disable
					//1: Enable
					//Bit 2 PTM0PE: PTM0 CCRP Comparator Interrupt Control
					//0: Disable
					//1: Enable
					//Bit 1 STMAE: STM CCRA Comparator Interrupt Control
					//0: Disable
					//1: Enable
					//Bit 0 STMPE: STM CCRP Comparator Interrupt Control
					//0: Disable
					//1: Enable

		_mfi1 = 0b00000000;
					//Bit 7 PTM2AF: PTM2 CCRA Comparator Interrupt Request Flag
					//0: No request
					//1: Interrupt request
					//Bit 6 PTM2PF: PTM2 CCRP Comparator Interrupt Request Flag
					//0: No request
					//1: Interrupt request
					//Bit 5 PTM1AF: PTM1 CCRA Comparator Interrupt Request Flag
					//0: No request
					//1: Interrupt request
					//Bit 4 PTM1PF: PTM1 CCRP Comparator Interrupt Request Flag
					//0: No request
					//1: Interrupt request
					//Bit 3 PTM2AE: PTM2 CCRA Comparator Interrupt Control
					//0: Disable
					//1: Enable
					//Bit 2 PTM2PE: PTM2 CCRP Comparator Interrupt Control
					//0: Disable
					//1: Enable
					//Bit 1 PTM1AE: PTM1 CCRA Comparator Interrupt Control
					//0: Disable
					//1: Enable
					//Bit 0 PTM1PE: PTM1 CCRP Comparator Interrupt Control
					//0: Disable
					//1: Enable
		
		_mfi2 = 0b00000000;
					//Bit 7 INT5F: External Interrupt 5 Request Flag
					//0: No request
					//1: Interrupt request
					//Bit 6 INT4F: External Interrupt 4 Request Flag
					//0: No request
					//1: Interrupt request
					//Bit 5 DEF: Data EEPROM Interrupt Request Flag
					//0: No request
					//1: Interrupt request
					//Bit 4 LVF: LVD Interrupt Request Flag
					//0: No request
					//1: Interrupt request
					//Bit 3 INT5E: External Interrupt 5 Control
					//0: Disable
					//1: Enable
					//Bit 3 INT4E: External Interrupt 4 Control
					//0: Disable
					//1: Enable
					//Bit 1 DEE: Data EEPROM Interrupt Control
					//0: Disable
					//1: Enable
					//Bit 0 LVE: LVD Interrupt Control
					//0: Disable
					//1: Enable
}

//--------------------------------------------------------------------------
void Initial_SysLvr(void)
{
		_lvrc = 0b01010101;    //2.1v lvr
						//Bit 7~0 LVS7~LVS0: LVR Voltage Select control
						//01010101: 2.1V
						//00110011: 2.55V
						//10011001: 3.15V
						//10101010: 3.8V
						//Any other value: Generates

}

//--------------------------------------------------------------------------
void Initial_SysLvd(void)
{
		_lvdc = 0b00000010;
						//Bit 7~6 Unimplemented, read as "0"
						//Bit 5 LVDO: LVD detection output flag
						//0: No Low Voltage Detected
						//1: Low Voltage Detected
						//Bit 4 LVDEN: Low Voltage Detector Control
						//0: Disable
						//1: Enable
						//Bit 3 VBGEN: Bandgap Buffer Control
						//0: Disable
						//1: Enable
						//Bit 2~0 VLVD2~VLVD0: Select LVD Voltage
						//000: VLVDIN ? 1.04V
						//001: 2.2V
						//010: 2.4V
						//011: 2.7V
						//100: 3.0V
						//101: 3.3V
						//110: 3.6V
						//111: 4.0V
}		

//--------------------------------------------------------------------------
void Initial_SysWdt(void)
{
//		_wdtc = 0b01010111;    //WDT enable
		_wdtc = 0b01010101;    //WDT enable   2^16
//		_wdtc = 0b10101101;    //WDT enable   2^16

						//Bit 7~3 WE4~WE0: WDT function control
						//10101: Disable
						//01010: Enable
						//Other values: Reset MCU
						//Bit 2~0 WS2~WS0: WDT time-out period selection
						//000: 28/fLIRC
						//001: 210/fLIRC
						//010: 212/fLIRC
						//011: 214/fLIRC
						//100: 215/fLIRC
						//101: 216/fLIRC
						//110: 217/fLIRC
						//111: 218/fLIRC
						//These three bits	
	
}

//--------------------------------------------------------------------------
void Initial_SysAdc (void)
{
	_pgac0 =0;
						//Bit 7 PGABP: DI+/DI- differential channel input bypass gain
						//0: Not bypass
						//1: Bypass
						//Bit 6~5 VGS1~VGS0: VREFP/VREFN differential reference voltage gain selection
						//00: VREFGN=1
						//01: VREFGN=1/2
						//10: VREFGN=1/4
						//11: Reserved
						//Bit 4~3 AGS1~AGS0: A/D converter PGAOP/PGAON differential input signal gain selection
						//00: ADGN=1
						//01: ADGN=2
						//10: ADGN=4
						//11: Reserved
						//Bit 2~0 PGS2~PGS0: PGA DI+/DI- differential channel input gain selection
						//000: PGAGN=1
						//001: PGAGN=2
						//010: PGAGN=4
						//011: PGAGN=8
						//100: PGAGN=16
						//101: PGAGN=32
						//110: PGAGN=64
						//111: PGAGN=128	
	_pgac1 =0;
						//Bit 7 Unimplemented, read as ‚Ä?‚Ä?
						//Bit 6 INIS: Selected inputs, IN1/IN2, internal connection control
						//0: Not connected
						//1: Connected
						//Bit 5~4 INX1~INX0: Selected inputs, IN1/IN2, and the PGA differential input ends, DI+/DIconnection
						//control bits
						//Bit 3~1 DCSET2~DCSET0: Differential input signal PGAOP/PGAON offset selection
						//000: DCSET=+0V
						//001: DCSET=+0.25√óŒîVR_I
						//010: DCSET=+0.5√óŒîVR_I
						//011: DCSET=+0.75√óŒîVR_I
						//100: DCSET=+0V
						//101: DCSET=-0.25√óŒîVR_I
						//110: DCSET=-0.5√óŒîVR_I
						//111: DCSET=-0.75√óŒîVR_I
						//The voltage, ŒîVR_I, is the differential reference voltage which is amplified by specific
						//gain selection based on the selected inputs.
						//Bit 0 Unimplemented, read as ‚Ä?‚Ä?
	_pgacs =0;
						//Bit 7~4 CHSN3~CHSN0: Negative input end IN2 selection
						//0000: AN1
						//0001: AN3
						//0010: AN5
						//0011: DAC1O
						//0100: DAC2O
						//0101: MOD1ON
						//0110: MOD2ON
						//0111: AVDD/6
						//1xxx: Reserved
						//These bits are used to select the negative input, IN2.
						//Bit 3~0 CHSP3~CHSP0: Positive input end IN1 selection
						//0000: AN0
						//0001: AN2
						//0010: AN4
						//0011: DAC1O
						//0100: DAC2O
						//0101: MOD1OP
						//0110: MOD2OP
						//0111: OP1S0
						//1000: OP1S1
						//1001: OP1S2
						//1010: OP1O
						//1011: OP2O
						//1100: AVDD/5
						//1101~1111: Reserved
						//These bits are used to select the positive input, IN1.
	_adcr0 = 0x60;
						//Bit 7 ADRST: A/D converter software reset control
						//0: Disable
						//1: Enable
						//Bit 6 ADSLP: A/D converter sleep mode control bit
						//0: Normal mode
						//1: Sleep mode
						//This bit is used to
						//Bit 5 ADOFF: A/D converter module power on/off control bit
						//0: Power on
						//1: Power off
						//Bit 4~2 ADOR2~ADOR0: A/D conversion oversampling rate selection
						//000: Oversampling rate OSR=16384
						//001: Oversampling rate OSR=8192
						//010: Oversampling rate OSR=4096
						//011: Oversampling rate OSR=2048
						//100: Oversampling rate OSR=1024
						//101: Oversampling rate OSR=512
						//110: Oversampling rate OSR=256
						//111: Oversampling rate OSR=128
						//Bit 1~0 Unimplemented, read as ‚Ä?‚Ä?	
	_adcr1 = 0;
						//Bit 7~5 FLMS2~FLMS0: A/D converter clock frequency and sampled data doubling function
						//control
						//000: CHOP=2, fADCK=fMCLK/30
						//010: CHOP=2, fADCK=fMCLK/12
						//100: CHOP=1, fADCK=fMCLK/30
						//110: CHOP=1, fADCK=fMCLK/
						//Bit 4~3 Unimplemented, read as ‚Ä?‚Ä?
						//Bit 2 ADCDL: A/D converted data latch function enable control
						//0: Disable data latch function
						//1: Enable data latch function
						//Bit 1 EOC: End of A/D conversion flag
						//0: A/D conversion in progress
						//1: A/D conversion ended
						//This bit must be cleared by software.
						//Bit 0 Unimplemented, read as ‚Ä?‚Ä?
	_adcs = 0;
						//Bit 7~5 Unimplemented, read as ‚Ä?‚Ä?
						//Bit 4~0 ADCK4~ADCK0: A/D converter clock source fMCLK setup
						//00000~11110: fMCLK=fSYS/2/(ADCK[4:0]+1)
						//11111: fMCLK=fSYS					
}

 //--------------------------------------------------------------------------
void fun_AFEPoweronInit()
{
	SET_VOREG_OUTPUT(Voreg2V4);
	SET_VOREG_POWER(POWERON);
//	fun_CalOPA1Offset();
//	fun_CalOPA2Offset();
//	fun_CalOPA3Offset();
}

//--------------------------------------------------------------------------
void fun_CalOPAOffset()
{
	fun_CalOPA1Offset();
	fun_CalOPA2Offset();
	fun_CalOPA3Offset();
}

//--------------------------------------------------------------------------
void Initial_SysGpio(void)
{
		//--- PA setting
		//pa0 @ ocdsda & xt1
		//pa1 @ strip det
		//pa2 @ ocdsck & xt2
		//pa3 @ osc2
		//pa4 @ osc1
		//pa5 @ sw1
		//pa6 @ sw2
		//pa7 @ rs232 det
		_pac =  0b11111111;
		_pa =   0b00000010;
		_papu = 0b11111111;
		_pawu = 0b01111010;
		
		//--- PA Pin-shared Functions		
#if ACFG_OSC_EN
		_pas0 = 0b00110011;
#else
		_pas0 = 0b00000000;
#endif
						//Bit 7~6 PAS07~PAS06: PA3 Pin-Shared function selection
						//00: PA3/PTP1I
						//01: PTP1
						//10: SPISDO
						//11: OSC2
						//Bit 5~4 PAS05~PAS04: PA2 Pin-Shared function selection
						//00/01/10: PA2/PTCK0
						//11: XT2
						//Bit 3~2 PAS03~PAS02: PA1 Pin-Shared function selection
						//00: PA1/INT0/STCK
						//01: OVPVR
						//10: LVDIN
						//11: PA1/INT0/STCK
						//Bit 1~0 PAS01~PAS00: PA0 Pin-Shared function selection
						//00/01/10: PA0/PTP0I
						//11: XT1
						
		_pas1 = 0b00000000;
						//Bit 7~6 PAS17~PAS16: PA7 Pin-Shared function selection
						//00: PA7/PTCK2
						//01: SEG30
						//10: OVPI
						//11: SDI/SDA
						//Bit 5~4 PAS15~PAS14: PA6 Pin-Shared function selection
						//00: PA6/STCK
						//01: SEG31
						//10: SPISDI
						//11: PA6/STCK
						//Bit 3~2 PAS13~PAS12: PA5 Pin-Shared function selection
						//00: PA5/STPI
						//01: SPISCK
						//10: SEG32
						//11: PA5/STPI
						//Bit 1~0 PAS11~PAS10: PA4 Pin-Shared function selection
						//00: PA4/PTP2I
						//01: PTP2
						//10: SPISCS
						//11: OSC1

		//--- PB setting
		//pb0 @ io_power
		//pb1 @ full
		//pb2 @ lcd vset
		//pb3 @ test3
		_pbc =  0b00001001;
		_pb =   0b00000011;
		_pbpu = 0b00001001;
		
		//--- PB Pin-shared Functions
		_pbs0 = 0b00000000;
						//Bit 7~6 PBS07~PBS06: PB3 Pin-Shared function selection
						//00: PB3/INT3
						//01: SEG26
						//10: SPISDI
						//11: SDO
						//Bit 5~4 PBS05~PBS04: PB2 Pin-Shared function selection
						//00: PB2/INT2
						//01: SEG27
						//10: SCS
						//11: SPISCK
						//Bit 3~2 PBS03~PBS02: PB1 Pin-Shared function selection
						//00: PB1/INT1
						//01: SEG28
						//10: STPB
						//11: OVPI
						//Bit 1~0 PBS01~PBS00: PB0 Pin-Shared function selection
						//00: PB0
						//01: SEG29
						//10: SCK/SCL
						//11: OVPI

		//--- PC setting
		//pc0 @ ad_temp
		//pc1 @ buzzer
		//pc2 @ working
		//pc3 @ ad_bat
		//pc4 @ uart_rx1
		//pc5 @ uart_tx1
		_pcc =  0b00111001;
		_pc =   0b00110000;
		_pcpu = 0b00110001;
		
		//--- PC Pin-shared Functions
		_pcs0 = 0b00000000;				
						//Bit 7~6 PCS07~PCS06: PC3 Pin-Shared function selection
						//00/01/10: PC3/PTCK2
						//11: AN1
						//Bit 5~4 PCS05~PCS04: PC2 Pin-Shared function selection
						//00: PC2/PTP2I
						//01: PTP2
						//10: PC2/PTP2I
						//11: AN0
						//Bit 3~2 PCS03~PCS02: PC1 Pin-Shared function selection
						//00/01: PC1/PTCK1
						//10: PTP0
						//11: AN3
						//Bit 1~0 PCS01~PCS00: PC0 Pin-Shared function selection
						//00/01: PC0/PTP1I/INT5
						//10: PTP1
						//11: AN2
						
		_pcs1 = 0b00000000;
						//Bit 7~4 Unimplemented, read as ‚Ä?„Ä?
						//Bit 3~2 PCS13~PCS12: PC5 Pin-Shared function selection
						//00: PC5
						//01: SPISDO
						//10: TX1
						//11: AN5
						//Bit 1~0 PCS11~PCS10: PC4 Pin-Shared function selection
						//00: PC4
						//01: SPISCS
						//10: RX1
						//11: AN4
		
		//--- PD setting
		//pd0 @ s0
		//pd1 @ s1
		//pd2 @ s2
		//pd3 @ s3
		//pd4 @ txd0
		//pd5 @ rxd0
		//pd6 @ buzzer gnd
		_pdc =  0b00000000;
		_pd =   0b00010000;
		_pdpu = 0b00000000;
		
		//--- PD Pin-shared Functions
		_pds0 = 0b10101111;
		//Bit 7~6 PDS07~PDS06: PD3 Pin-Shared function selection
		//00/01: PD3
		//10: SEG3
		//11: COM7
		//Bit 5~4 PDS05~PDS04: PD2 Pin-Shared function selection
		//00/01: PD2
		//10: SEG2
		//11: COM6
		//Bit 3~2 PDS03~PDS02: PD1 Pin-Shared function selection
		//00/01: PD1
		//10: SEG1
		//11: COM5
		//Bit 1~0 PDS01~PDS00: PD0 Pin-Shared function selection
		//00/01: PD0
		//10: SEG0
		//11: COM4
						
		_pds1 = 0b00000000;
		//Bit 7~6 Unimplemented, read as ‚Ä?„Ä?
		//Bit 5~4 PDS15~PDS14: PD6 Pin-Shared function selection
		//00/01/10: PD6/INT4
		//11: PTP0B
		//Bit 3~2 PDS13~PDS12: PD5 Pin-Shared function selection
		//00: PD5
		//01: RX0
		//10: OVPI
		//11: SEG25
		//Bit 1~0 PDS11~PDS10: PD4 Pin-Shared function selection
		//00: PD4
		//01: TX0
		//10: STP
		//11: SEG24		
		

		//--- PE setting
		//pe0~pe7 @ s16~s23			
		_pec =  0b00000000;
		_pe = 	0b00000000;
		_pepu = 0b00000000;
		
		//--- PE Pin-shared Functions
		_pes0 = 0b11111111;
						//Bit 7~6 PES07~PES06: PE3 Pin-Shared function selection
						//00/01/10: PE3
						//11: SEG19
						//Bit 5~4 PES05~PES04: PE2 Pin-Shared function selection
						//00/01/10: PE2
						//11: SEG18
						//Bit 3~2 PES03~PES02: PE1 Pin-Shared function selection
						//00/01/10: PE1
						//11: SEG17
						//Bit 1~0 PES01~PES00: PE0 Pin-Shared function selection
						//00/01/10: PE0
						//11: SEG16
		
		//_pes1 = 0b11111111;
		_pes1 = 0b00000000;
						//Bit 7~6 PES17~PES16: PE7 Pin-Shared function selection
						//00/01/10: PE7
						//11: SEG23
						//Bit 5~4 PES15~PES14: PE6 Pin-Shared function selection
						//00/01/10: PE6
						//11: SEG22
						//Bit 3~2 PES13~PES12: PE5 Pin-Shared function selection
						//00/01/10: PE5
						//11: SEG21
						//Bit 1~0 PES11~PES10: PE4 Pin-Shared function selection
						//00/01/10: PE4
						//11: SEG20
		
		//--- PF setting
		//pf0~pf7 @ s8~s15	
		_pfc =  0b00000000;
		_pf =   0b00000000;
		_pfpu = 0b00000000;
		
		//--- PF Pin-shared Functions
		_pfs0 = 0b11111111;
						//Bit 7~6 PFS07~PFS06: PF3 Pin-Shared function selection
						//00/01/10: PF3
						//11: SEG11
						//Bit 5~4 PFS05~PFS04: PF2 Pin-Shared function selection
						//00/01/10: PF2
						//11: SEG10
						//Bit 3~2 PFS03~PFS02: PF1 Pin-Shared function selection
						//00/01/10: PF1
						//11: SEG9
						//Bit 1~0 PFS01~PFS00: PF0 Pin-Shared function selection
						//00/01/10: PF0
								
		_pfs1 = 0b11111111;
						//Bit 7~6 PFS17~PFS16: PF7 Pin-Shared function selection
						//00/01/10: PF7
						//11: SEG15
						//Bit 5~4 PFS15~PFS14: PF6 Pin-Shared function selection
						//00/01/10: PF6
						//11: SEG14
						//Bit 3~2 PFS13~PFS12: PF5 Pin-Shared function selection
						//00/01/10: PF5
						//11: SEG13
						//Bit 1~0 PFS11~PFS10: PF4 Pin-Shared function selection
						//00/01/10: PF4
						//11: SEG12
							
		//--- PG setting
		_pgc =  0b00000000;
		_pg =   0b00000000;
		_pgpu = 0b00000000;
		

		//--- PG Pin-shared Functions
		_pgs0 = 0b00101010;
						//Bit 7~6 Unimplemented, read as ‚Ä?„Ä?
						//Bit 5~4 PGS05~PGS04: PG2 Pin-Shared function selection
						//00/01: PG2
						//10: V2
						//11: SEG35
						//Bit 3~2 PGS03~PGS02: PG1 Pin-Shared function selection
						//00/01: PG1
						//10: C2
						//11: SEG34
						//Bit 1~0 PGS01~PGS00: PG0 Pi n-Shared function selection
						//00/01: PG0
						//10: C1
						//11: SEG33
						
							
						
		_ifs0 = 0b00000000;
						//Bit 7 PTP2IPS: PTP2I input source pin selection
						//0: PA4
						//1: PC2
						//Bit 6 PTP1IPS: PTP1I input source pin selection
						//0: PA3
						//1: PC0
						//Bit 5 PTP0IPS: PTP0I input source pin selection
						//0: PA0
						//1: Internally connected to OVPINT
						//Bit 4 Unimplemented, read as ‚Ä?„Ä?
						//Bit 3 PTCK2PS: PTCK2 input source pin selection
						//0: PC3
						//1: PA7
						//Bit 2~1 Unimplemented, read as ‚Ä?„Ä?
						//Bit 0 STCKPS: STCK input source pin selection
						//0: PA1
						//1: PA6
						
		_ifs1 = 0b00000000;
						//Bit 7 Unimplemented, read as ‚Ä?„Ä?
						//Bit 6 SPISCSBPS: SPISCS input source pin selection
						//0: PA4
						//1: PC4
						//Bit 5 SPISDIPS: SPISDI input source pin selection
						//0: PA6
						//1: PB3
						//Bit 4 SPISCKPS: SPISCK input source pin selection
						//0: PA5
						//1: PB2
						//Bit 3~0 Unimplemented, read as ‚Ä?„Ä?
						
//		_sledc0 = 0b00000000;
//		_sledc1 = 0b00000011;
//		_sledc2 = 0b00000000;
//		_sledc3 = 0b00000000;					
}
//--------------------------------------------------------------------------
void Initnal_StmCmp_Lirc_16K (void)
{
	_stmal = 1;     	//;;4MHZ
	_stmah = 1 >> 8;	//;TIMER0 10 BIT TIMER  =1000 X 0.25uS = 250us 
	
	_stmc0 = 0b01000000;
					//Bit 7 STPAU: STM Counter Pause Control
					//0: Run
					//1: Pause
					//The counter
					//Bit 6~4 STCK2~STCK0: Select STM Counter Clock
					//000: fSYS/4
					//001: fSYS
					//010: fH/16
					//011: fH/64
					//100: fSUB
					//101: fSUB
					//110: STCK rising edge clock
					//111: STCK falling edge clock
					//Bit 3 STON: STM Counter On/Off Control
					//0: Off
					//1: On
					//Bit 2~0 Unimplemented, read as "0"
	
	_stmc1 = 0b00111101;
					//Bit 7~6 STM1~STM0: Select STM Operating Mode
					//00: Compare Match Output Mode
					//01: Capture Input Mode
					//10: PWM Output Mode or Single Pulse Output Mode
					//11: Timer/Counter Mode
					//Bit 5~4 STIO1~STIO0: Select STM External Pin (STP or STPI) Function
					//Compare Match Output Mode
					//00: No change
					//01: Output low
					//10: Output high
					//11: Toggle output
					//PWM Output Mode/Single Pulse Output Mode
					//00: PWM output inactive state
					//01: PWM output active state
					//10: PWM output
					//11: Single Pulse Output
					//Capture Input Mode
					//00: Input capture at rising edge of STPI
					//01: Input capture at falling edge of STPI
					//10: Input capture at rising/falling edge of STPI
					//11: Input capture disabled
					//Bit 3 STOC: STM STP Output Control
					//Compare Match Output Mode
					//0: Initial low
					//1: Initial high
					//PWM Output Mode/Single Pulse Output Mode
					//0: Active low
					//1: Active high
					//Bit 2 STPOL: STM STP Output Polarity Control
					//0: Non-inverted
					//1: Inverted
					//Bit 1 STDPX: STM PWM Duty/Period Control
					//0: CCRP ‚Ä?period; CCRA ‚Ä?duty
					//1: CCRP ‚Ä?duty; CCRA ‚Ä?period
					//Bit 0 STCCLR: STM Counter Clear Condition Selection
					//0: Comparator P match
					//1: Comparator A match
					
	_pes00 =0;
	_pes01 =1;
	_mf1e =0;
	_stmae =0;
								
}

//--------------------------------------------------------------------------
void Initnal_StmCmp_Hirc_8K (void)
{
	_stmal = 250;     	//;;4MHZ
	_stmah = 250 >> 8;	//;TIMER0 10 BIT TIMER  =1000 X 0.25uS = 250us 
	
	_stmc0 = 0b00010000;
					//Bit 7 STPAU: STM Counter Pause Control
					//0: Run
					//1: Pause
					//The counter
					//Bit 6~4 STCK2~STCK0: Select STM Counter Clock
					//000: fSYS/4
					//001: fSYS
					//010: fH/16
					//011: fH/64
					//100: fSUB
					//101: fSUB
					//110: STCK rising edge clock
					//111: STCK falling edge clock
					//Bit 3 STON: STM Counter On/Off Control
					//0: Off
					//1: On
					//Bit 2~0 Unimplemented, read as "0"
	
	_stmc1 = 0b00111101;
					//Bit 7~6 STM1~STM0: Select STM Operating Mode
					//00: Compare Match Output Mode
					//01: Capture Input Mode
					//10: PWM Output Mode or Single Pulse Output Mode
					//11: Timer/Counter Mode
					//Bit 5~4 STIO1~STIO0: Select STM External Pin (STP or STPI) Function
					//Compare Match Output Mode
					//00: No change
					//01: Output low
					//10: Output high
					//11: Toggle output
					//PWM Output Mode/Single Pulse Output Mode
					//00: PWM output inactive state
					//01: PWM output active state
					//10: PWM output
					//11: Single Pulse Output
					//Capture Input Mode
					//00: Input capture at rising edge of STPI
					//01: Input capture at falling edge of STPI
					//10: Input capture at rising/falling edge of STPI
					//11: Input capture disabled
					//Bit 3 STOC: STM STP Output Control
					//Compare Match Output Mode
					//0: Initial low
					//1: Initial high
					//PWM Output Mode/Single Pulse Output Mode
					//0: Active low
					//1: Active high
					//Bit 2 STPOL: STM STP Output Polarity Control
					//0: Non-inverted
					//1: Inverted
					//Bit 1 STDPX: STM PWM Duty/Period Control
					//0: CCRP ‚Ä?period; CCRA ‚Ä?duty
					//1: CCRP ‚Ä?duty; CCRA ‚Ä?period
					//Bit 0 STCCLR: STM Counter Clear Condition Selection
					//0: Comparator P match
					//1: Comparator A match
					
	_pes02 =0;
	_pes03 =1;
	_mf1e =0;
	_stmae =0;					
}

//--------------------------------------------------------------------------
void Initial_Sys(void)
{
	Initial_SysGpio();
	Initial_SysLcd();
	Initial_SysWdt();
	Initial_SysLvr();
	Initial_SysInt();
	Initial_SysTimebase();//0.5s ±ª˘÷–∂œ
	Initial_SysStm();
	Initial_SysPTM0();	
	Initial_SysLcd();
	Initial_SysAdc();
}


//--------------------------------------------------------------------------
void Initial_HaltSys(void)
{
	Initial_SysGpio();
	//--- set pwm mode to gpio mode
	_pbs02 =0;
	_pbs03 =0;	
}


////--------------------------------------------------------------------------
//void UART_Function_Initial (void)
//{
//
//	_ucr1 = 0b10000000;      //BIT3=2 STOP BIT
//	
//	_brgh = 1;			     //HIGH SPEED RATE
//	_adden = 0;              //DISABLE ADDRESS DETECTION
//	_wake = 0;               //RX PIN WAKE UP FUNCTION DISABLE
//
//	_tiie = 1;               //TX INTERRUPT ENABLE
//	_teie = 1;               //TX INTERRUPT ENABLE
//	
//	_txen =1;                //default Enable TX
//	_rxen =1;                //default Enable RX
//	
//	//--- rx
//	_rie = 1;                //RX INTERRUPT ENABLE
//		
//	//--- 9600 bps / 19200bps
//	//_brg = C_BaudRate19200;   //BRGH=1 25=>9600/12=>19200
//	_brg = C_BaudRate115200;   //BRGH=1 25=>9600/12=>19200
//	
////	_euti =1;                //in MFI1 reg bit3
//	_ure =1;                //in MFI1 reg bit3
//	_mf1e =1;                //in intc1 reg bit1
//}

//--------------------------------------------------------------------------
void Load_System_Vaule(void)
{
	unsigned char count,count1;
	unsigned int  checksum;
	
	//--- Ë®àÁÆóblock checksum
	for(count =0; count < 4; count++)
	{
		checksum =0;
		for(count1 =0; count1 < 15; count1++)
			checksum += Significant_Table[(count * 0x10) + count1];
		if(checksum == Significant_Table[(count * 0x10) + 0x0f])
			break;
	}
	
	if(count < 4 && checksum!=0)
	{
		//--- Load record
		M_GM_data_Record = Significant_Table[C_Flash_RecordAdr + (0x10 * count)];
		//--- Load Current record
		M_GM_Record_current = Significant_Table[C_Flash_Current_RecordAdr + (0x10 * count)];
		//--- Load Send record
		M_GM_SendRecord = Significant_Table[C_Flash_Send_RecordAdr + (0x10 * count)];		
		//--- Load Unit
		M_Unit = Significant_Table[C_Flash_UnitAdr + (0x10 * count)];
		//--- Load Alarm1 Flag ==>bit15
		if(Significant_Table[C_Flash_Alarm1Adr + (0x10 * count)] & 0x8000)	
			F_Alarm1_Enable =1;
		else
			F_Alarm1_Enable =0;
			
		//--- Load Alarm2 Flag ==>bit15
		if(Significant_Table[C_Flash_Alarm2Adr + (0x10 * count)] & 0x8000)	
			F_Alarm2_Enable =1;
		else
			F_Alarm2_Enable =0;
			
		//--- Load Alarm3 Flag ==>bit15
		if(Significant_Table[C_Flash_Alarm3Adr + (0x10 * count)] & 0x8000)	
			F_Alarm3_Enable =1;
		else
			F_Alarm3_Enable =0;
			
		//--- Load Alarm4 Flag ==>bit15
		if(Significant_Table[C_Flash_Alarm4Adr + (0x10 * count)] & 0x8000)	
			F_Alarm4_Enable =1;
		else
			F_Alarm4_Enable =0;
			
		//--- Load Alarm1 Hour ==>bit6~bit10
		M_Alarm1_HR =  (Significant_Table[C_Flash_Alarm1Adr + (0x10 * count)] & 0b0000011111000000) >> 6;
		//--- Load Alarm1 Hour ==>bit0~bit5
		M_Alarm1_MIN = (Significant_Table[C_Flash_Alarm1Adr + (0x10 * count)] & 0b0000000000111111);
		
		//--- Load Alarm2 Hour ==>bit6~bit10
		M_Alarm2_HR =  (Significant_Table[C_Flash_Alarm2Adr + (0x10 * count)] & 0b0000011111000000) >> 6;
		//--- Load Alarm2 Hour ==>bit0~bit5
		M_Alarm2_MIN = (Significant_Table[C_Flash_Alarm2Adr + (0x10 * count)] & 0b0000000000111111);
		
		//--- Load Alarm3 Hour ==>bit6~bit10
		M_Alarm3_HR =  (Significant_Table[C_Flash_Alarm3Adr + (0x10 * count)] & 0b0000011111000000) >> 6;
		//--- Load Alarm3 Hour ==>bit0~bit5
		M_Alarm3_MIN = (Significant_Table[C_Flash_Alarm3Adr + (0x10 * count)] & 0b0000000000111111);
		
		//--- Load Alarm4 Hour ==>bit6~bit10
		M_Alarm4_HR =  (Significant_Table[C_Flash_Alarm4Adr + (0x10 * count)] & 0b0000011111000000) >> 6;
		//--- Load Alarm4 Hour ==>bit0~bit5
		M_Alarm4_MIN = (Significant_Table[C_Flash_Alarm4Adr + (0x10 * count)] & 0b0000000000111111);
	}
	else
	{
		M_GM_data_Record =0;
		M_GM_Record_current =0;
		M_Unit =unit_default;
		F_Alarm1_Enable =0;
		M_Alarm1_HR = 12;
		M_Alarm1_MIN = 0;	
		F_Alarm2_Enable =0;
		M_Alarm2_HR = 12;
		M_Alarm2_MIN = 0;
		F_Alarm3_Enable =0;
		M_Alarm3_HR = 12;
		M_Alarm3_MIN = 0;
		F_Alarm4_Enable =0;
		M_Alarm4_HR = 12;
		M_Alarm4_MIN = 0;	
	}						
}

//--------------------------------------------------------------------------
 unsigned int get_CalCurrentToADC( unsigned int uACurr )
{
	float data ;
	
	data = (float)uACurr/100 ;
	data *= C_AMP_Resistor ;
	data += C_Real_Voltage ;
	data /= (float)C_Vref_Voltage/(float)C_ADC_Bit ;
	return 	(unsigned int)data ;
}

//--------------------------------------------------------------------------
void Load_StripMeas_Vaule(void)
{
	M_TriggerCurrent_Adc = get_CalCurrentToADC( C_TriggerCurrent ) ;
	M_StripUsedCurrent_Adc = get_CalCurrentToADC( C_StripUsedCurrent ) ;
	M_DropCurrent_Adc = get_CalCurrentToADC( C_DropCurrent ) ;
}
//--------------------------------------------------------------------------
void Save_RtcTime(void)
{
	unsigned char buf[7];	
	#if (EVERY_MIN_SAVE_TIME==1)
	static unsigned char P_Minutes = 0;
	if(P_Minutes == M_Minutes)
	return;
	P_Minutes = M_Minutes;
	#endif
	//if(P_Minutes != M_Minutes)
	{
//		P_Minutes = M_Minutes;
		buf[0] = M_Second;
		buf[1] = M_Minutes;
		buf[2] = M_Hour;
		buf[3] = M_Days;
		buf[4] = M_Month;
		buf[5] = M_Year;
		buf[6] = FLASH_CHECK_MASK;
		Write_EEPROMBuf(C_EEP_RtcTime,buf,sizeof(buf));
	}
}
void Load_RtcTime_Vaule(void)
{
	unsigned char buf[7];
	
	memset((unsigned char *)buf,0,sizeof(buf));

	Read_EEPROMBuf(C_EEP_RtcTime,buf,sizeof(buf));
	if(buf[6] == FLASH_CHECK_MASK)
	{	
		M_Second = buf[0]; 	
		M_Minutes = buf[1];		
		M_Hour = buf[2];		
		M_Days = buf[3];		
		M_Month = buf[4];		
		M_Year = buf[5];
	}
	else
	{
		//--- Date initnal
		M_Second =1;
		M_Minutes =0;
		M_Hour =15;
		M_Days =1;
		M_Month =12;
		M_Year =Start_year;
		Save_RtcTime();
	}
}
////--------------------------------------------------------------------------
//void Load_Calibration_Vaule (void)
//{
//	unsigned char buf[4],count,count1;
//	unsigned int  checksum,Ibuf0,Ibuf1;
//	unsigned long Lbuf0;
//	double 	Dbuf0,Dbuf1;
//	
//	//--- Ë®àÁÆóblock checksum
//	for(count =0; count < 4; count++)
//	{
//		checksum =0;
//		for(count1 =0; count1 < 14; count1++)
//		{
//			Read_EEPROMBuf((count * 0x10) + count1,buf,1);
//			checksum += buf[0];
//		}
//		
//		//--- read checksum	
//		Read_EEPROMBuf((count * 0x10) + 0x0e,buf,2);
//		Ibuf0 = buf[0] << 8;
//		Ibuf0 |= buf[1];
//		
//		//--- check checksum
//		if(checksum == Ibuf0)
//			break;
//	}
//	
//	//--- load calibration
//	if(count < 4)
//	{
//		//--- Read LIRC & HIRC
//		Read_EEPROMBuf(C_EEP_CalLircAdr,buf,6);
//		Lbuf0 = (unsigned long)buf[0] << 24;
//		Lbuf0 |= (unsigned long)buf[1] << 16;
//		Lbuf0 |= (unsigned long)buf[2] << 8;
//		Lbuf0 |= (unsigned long)buf[3];	
//		
//		Ibuf1 = buf[4] << 8;
//		Ibuf1 |= buf[5];	
//		//--- LircË£úÂÑü
//		if((Lbuf0 <= 1680000) && (Lbuf0 >= 1520000))
//		{
//			Dbuf0 = (double)Lbuf0 / 3200000;
//			if(Dbuf0 >=0.5)
//			{
//				Dbuf0 -= 0.5;
//				Dbuf0 = 0.5 / Dbuf0;
//				//--- ÂõõÊç®‰∫îÂÖ•
//				Dbuf0 += 0.5;
//				M_Cal_Licr_ObjCnt= Dbuf0;
//				M_Cal_Licr_ObjVaule =1;	
//			}
//			else
//			{
//				Dbuf0 = 0.5 - Dbuf0;
//				Dbuf0 = 0.5 / Dbuf0;
//				//--- ÂõõÊç®‰∫îÂÖ•
//				Dbuf0 += 0.5;
//				M_Cal_Licr_ObjCnt = Dbuf0;
//				M_Cal_Licr_ObjVaule = -1;
//			}
//			
//		}
//		else
//		{
//			M_Cal_Licr_ObjCnt =0;
//			M_Cal_Licr_ObjVaule =0;	
//		}
//		
//		//--- HircË£úÂÑü
//		if((Ibuf1 <= 8400) && (Ibuf1 >= 7600))
//		{
//			Dbuf0 =  (double) 1 /  Ibuf1;
//			Dbuf1 = Dbuf0;
//			Dbuf1 *= 8000;
//			if(Dbuf1 <= 1)
//			{
//				Dbuf1 = 1 - Dbuf1;
//				Dbuf1 /= Dbuf0;
//				//--- ÂõõÊç®‰∫îÂÖ•
//				Dbuf1 += 0.5;
//				M_Cal_Hicr_ObjCnt = Dbuf1;
//				M_Cal_Hicr_ObjVaule =-1;	
//			}
//			else
//			{
//				Dbuf1 = Dbuf1 - 1;
//				Dbuf1 /= Dbuf0;
//				//--- ÂõõÊç®‰∫îÂÖ•
//				Dbuf1 += 0.5;
//				M_Cal_Hicr_ObjCnt = Dbuf1;
//				M_Cal_Hicr_ObjVaule =1;	
//			}
//		}
//		else
//		{
//			M_Cal_Hicr_ObjCnt = 0;
//			M_Cal_Hicr_ObjVaule =0;
//		}
//		
//		//--- Read 10K & 100K calibration
//		Read_EEPROMBuf(C_EEP_Cal10KAdr,buf,4);
//		Ibuf0 = buf[0] << 8;
//		Ibuf0 |= buf[1];
//		
//		Ibuf1 = buf[2] << 8;
//		Ibuf1 |= buf[3];
//		
//		//--- 10KË£úÂÑü
//		if((Ibuf0 <= 4034) && (Ibuf0 >= 3994))
//			M_Cal_10K_Adc = Ibuf0;
//		else
//			M_Cal_10K_Adc = 4014;
//			
//		//--- 100KË£úÂÑü
//		if((Ibuf1 <= 1159) && (Ibuf1 >= 1119))
//			M_Cal_100K_Adc = Ibuf1;
//		else
//			M_Cal_100K_Adc = 1139;
//
//	}
//	else
//	{
//		M_Cal_Licr_ObjCnt =0;
//		M_Cal_Licr_ObjVaule =0;
//		M_Cal_Hicr_ObjCnt = 0;
//		M_Cal_Hicr_ObjVaule =0;
////		M_Cal_10K_Adc = 4014;	
////		M_Cal_100K_Adc = 1139;
////			
////		M_Cal_Licr_ObjCnt =1600;
////		M_Cal_Licr_ObjVaule =1;
////		M_Cal_Hicr_ObjCnt = 33;
////		M_Cal_Hicr_ObjVaule =-1;
//	}	
//}

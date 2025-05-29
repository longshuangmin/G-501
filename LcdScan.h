#ifndef _LCDSCAN_H
#define _LCDSCAN_H

// Big Numbers
//   _a_ 
// f|   |b 
//  |_g_|
// e|   |c
//  |_d_|
//

#define SEG_a       ((uint16_t)1 << 0)
#define SEG_b       ((uint16_t)1 << 1)
#define SEG_c       ((uint16_t)1 << 2)
#define SEG_d       ((uint16_t)1 << 3)
#define SEG_e       ((uint16_t)1 << 4)
#define SEG_f       ((uint16_t)1 << 5)
#define SEG_g       ((uint16_t)1 << 6)
#define SEG_h       ((uint16_t)1 << 7)
#define SEG_i       ((uint16_t)1 << 8)

enum tagLCDPATTERN {
   CHAR_NULL = 0,
   CHAR0    = 	  SEG_a | SEG_b | SEG_c | SEG_d | SEG_e | SEG_f			,
   CHAR1    = 	          SEG_b | SEG_c									,
   CHAR2    = 	  SEG_a | SEG_b         | SEG_d | SEG_e         | SEG_g	,
   CHAR3    = 	  SEG_a | SEG_b | SEG_c | SEG_d                 | SEG_g	,
   CHAR4    = 	          SEG_b | SEG_c                 | SEG_f | SEG_g	,
   CHAR5    = 	  SEG_a         | SEG_c | SEG_d         | SEG_f | SEG_g	,
   CHAR6    = 	  SEG_a         | SEG_c | SEG_d | SEG_e | SEG_f | SEG_g	,
   CHAR7    = 	  SEG_a | SEG_b | SEG_c                            		,
   CHAR8    = 	  SEG_a | SEG_b | SEG_c | SEG_d | SEG_e | SEG_f | SEG_g	,
   CHAR9    = 	  SEG_a | SEG_b | SEG_c | SEG_d |         SEG_f | SEG_g	,
   CHARa    = 	  SEG_a | SEG_b | SEG_c         | SEG_e | SEG_f | SEG_g	,
   CHARb    = 	                  SEG_c | SEG_d | SEG_e | SEG_f | SEG_g	,
   CHARc    = 	                          SEG_d | SEG_e         | SEG_g	,
   CHARd    = 	          SEG_b | SEG_c | SEG_d | SEG_e         | SEG_g ,
   CHARe    = 	  SEG_a                 | SEG_d | SEG_e | SEG_f | SEG_g ,
   CHARf    = 	  SEG_a                         | SEG_e | SEG_f | SEG_g	,
   CHARg    = 	  SEG_a         | SEG_c | SEG_d | SEG_e | SEG_f       	,
   CHARh    = 	                  SEG_c         | SEG_e | SEG_f | SEG_g	,
   CHARi    = 	                  SEG_c                     			,
   CHARj    = 	          SEG_b | SEG_c | SEG_d | SEG_e              	,
   CHARk    = 	  SEG_a 		| SEG_c         | SEG_e | SEG_f | SEG_g	,
   CHARl    = 	                          SEG_d | SEG_e | SEG_f       	,
   CHARm    = 	  SEG_a         | SEG_c         | SEG_e        	| SEG_g	,
   CHARn    = 	                  SEG_c         | SEG_e        	| SEG_g	,   
   CHARo    = 	                  SEG_c | SEG_d | SEG_e        	| SEG_g	,
   CHARp    = 	  SEG_a | SEG_b                 | SEG_e | SEG_f | SEG_g ,
   CHARq    = 	  SEG_a | SEG_b | SEG_c               	| SEG_f | SEG_g	,
   CHARr    = 	                                  SEG_e         | SEG_g	,
   CHARs    = 	  SEG_a         | SEG_c | SEG_d         | SEG_f | SEG_g	,
   CHARt    = 	                          SEG_d | SEG_e | SEG_f | SEG_g	,
   CHARu    = 	          SEG_b | SEG_c | SEG_d | SEG_e | SEG_f       	,
   CHARv    = 	          SEG_b | SEG_c | SEG_d | SEG_e | SEG_f | SEG_g	,
   CHARw    = 	  SEG_a         | SEG_c | SEG_d              	| SEG_g	,
   CHARx    = 	                                  SEG_e | SEG_f | SEG_g	,
   CHARy    = 	          SEG_b | SEG_c | SEG_d         | SEG_f | SEG_g	,
   CHARz    = 	  SEG_a                 | SEG_d                 | SEG_g	,
   CHARques = 	  SEG_a | SEG_b                 | SEG_e         | SEG_g	,
   CHAR_    =                             SEG_d                     	,
   CHARdash =                                           	      SEG_g	,
   CHARquestion = SEG_a | SEG_b                 | SEG_e         | SEG_g ,
   CHARC    = 	  SEG_a                 | SEG_d | SEG_e | SEG_f       	,
   CHARH    = 	          SEG_b | SEG_c         | SEG_e | SEG_f | SEG_g	,
   CHARI    =                               	  SEG_e | SEG_f			,
   CHARN    = 	  SEG_a | SEG_b | SEG_c         | SEG_e | SEG_f         ,
   CHARK    = 	                                  SEG_e | SEG_f | SEG_h | SEG_i ,
} ;

enum tagLCDSEG {
	LcdSeg_Strip_Blood			= 1 << 0 ,
	LcdSeg_Strip_StripBase 		= 1 << 1 ,
	//                      	
	LcdSeg_Unit_mmoL 			= 1 << 0 ,
	LcdSeg_Unit_mgdL 			= 1 << 1 ,
	LcdSeg_Unit_Ketone			= 1 << 2 ,

	LcdSeg_Unit_DateSlash   	= 1 << 3 ,
	LcdSeg_Unit_TimeColon  		= 1 << 4 ,
	LcdSeg_Unit_AM				= 1 << 5 ,
	LcdSeg_Unit_PM				= 1 << 6 ,
	LcdSeg_Unit_TEMP			= 1 << 7 ,
	//                      	
    LcdSeg_Mem_Day      		= 1 << 0 ,		
	LcdSeg_Mem_Average		    = 1 << 1 ,
	LcdSeg_Mem_Memory 			= 1 << 2 ,
	//
	LcdSeg_Meas_BigNum_DP       = 1 << 0 ,
	LcdSeg_Meas_Bat				= 1 << 1 ,
	//LcdSeg_Meas_BatLv0			= 1 << 2 ,
	//LcdSeg_Meas_BatLv1			= 1 << 3 ,
	//LcdSeg_Meas_BatLv2			= 1 << 4 ,
    LcdSeg_Meas_BefMeal        	= 1 << 2 ,
	LcdSeg_Meas_AftMeal        	= 1 << 3 ,
	LcdSeg_Meas_Gen        		= 1 << 4 ,
	LcdSeg_Meas_Ctl        		= 1 << 5 ,
	LcdSeg_Meas_Mute        	= 1 << 6 ,
	//
	LcdSeg_Send_BLE 			= 1 << 0 ,
    LcdSeg_Send_BLE_S1 			= 1 << 1 ,
    LcdSeg_Send_BLE_S2         	= 1 << 2 ,
    LcdSeg_Send_BLE_S3        	= 1 << 3 ,
    LcdSeg_Send_OK         		= 1 << 4 ,
    LcdSeg_Send_Fail        	= 1 << 5 ,
//	LcdSeg_Send_BLE 			= 1 << 6 ,
    //
    LcdSeg_Ant_Ant 				= 1 << 0 ,
    LcdSeg_Ant_Lv0         		= 1 << 1 ,
    LcdSeg_Ant_Lv1         		= 1 << 2 ,
    LcdSeg_Ant_Lv2         		= 1 << 3 ,
  //  LcdSeg_Ant_Lv3         		= 1 << 4 ,

	LcdSeg_Alarm_Alarm 			= 1 << 0 ,
    LcdSeg_Alarm_Seg1         	= 1 << 1 ,
    LcdSeg_Alarm_Seg2         	= 1 << 2 ,
    LcdSeg_Alarm_Seg3         	= 1 << 3 ,
    LcdSeg_Alarm_Seg4         	= 1 << 4 ,

	LcdSeg_Dire_1         		= 1 << 0 ,
    LcdSeg_Dire_2         		= 1 << 1 ,
    LcdSeg_Dire_3         		= 1 << 2 ,
	//
	LcdSeg_S0					= 1 << 0 ,
	LcdSeg_S1					= 1 << 1 ,
	LcdSeg_S2					= 1 << 2 ,
	LcdSeg_S3					= 1 << 3 ,
	LcdSeg_S4					= 1 << 4 ,
	LcdSeg_S5					= 1 << 5 ,
	LcdSeg_S6					= 1 << 6 ,
	LcdSeg_S7					= 1 << 7 ,
	//	
	LcdSeg_End ,
} ;

enum tagLCDBIT {
	LcdBit_Strip_Blood  	    ,
   	LcdBit_Strip_StripBase 	    ,
   	//
	LcdBit_Unit_mmoL 		    ,
   	LcdBit_Unit_mgdL 		    ,
   	LcdBit_Unit_Ketone			,
	LcdBit_Unit_DateSlash       ,
   	LcdBit_Unit_TimeColon       ,
   	LcdBit_Unit_AM   		    ,
   	LcdBit_Unit_PM   		    ,
   	LcdBit_Unit_TEMP   		    ,
   	//
   	LcdBit_Mem_Day	            ,
   	LcdBit_Mem_Average	        ,
   	LcdBit_Mem_Memory 		    ,
	//
	LcdBit_Meas_BigNum_DP      	,
	LcdBit_Meas_Bat_Low    		,
//    LcdBit_Meas_Bat    			,
//	LcdBit_Meas_BatLv0			,
//	LcdBit_Meas_BatLv1			,
//	LcdBit_Meas_BatLv2			,
	LcdBit_Meas_BefMeal			,
	LcdBit_Meas_AftMeal			,
	LcdBit_Meas_Gen				,
	LcdBit_Meas_Ctl				,
	LcdBit_Meas_Mute			,
	//
	LcdBit_Send_BLE				,
	LcdBit_Send_BLE_S1 			,		
	LcdBit_Send_BLE_S2 			,	
	LcdBit_Send_BLE_S3 			,	
	LcdBit_Send_LTE_OK 			,		
	LcdBit_Send_LTE_ERR 		,	
    //LcdBit_Send_Ing				,
   // LcdBit_Send_OK				,
   // LcdBit_Send_Fail			,
    //
    LcdBit_Ant_Ant				,
    LcdBit_Ant_Lv0				,
    LcdBit_Ant_Lv1				,
    LcdBit_Ant_Lv2				,
    LcdBit_Ant_Lv3				,

	LcdBit_Alarm_Alarm			,
    LcdBit_Alarm_Seg1			,
    LcdBit_Alarm_Seg2			,
    LcdBit_Alarm_Seg3			,
    LcdBit_Alarm_Seg4			,

} ;

struct tagLCD {
	uint16_t month[2] ,
		 	 day[2] ,
		 	 hour[2] ,
		 	 min[2] ,
		 	 BigNum[3] ;
  	//
  	union {
  		uint16_t Byte ;
		struct {
			uint16_t Blood	   : 1 ,	// P11
					 StripBase : 1 ;	// P10
		} Bit ;
	} strip ;
	//
	union {
  		uint16_t Byte ;
		struct {
			uint16_t mmoL 	  : 1 ,	// P14
					 mgdL 	  : 1 ,	// P!3
					 Ketone	   :1,
					 DateSlash : 1 ,	// P2
					 TimeColon : 1 ,	// P2
					 AM   	  : 1 ,	// AM
					 PM   	  : 1 ,	// PM
					 Temp : 1 ;	// P1 
					 
		} Bit ;
	} unit ;		
	//
	union {
  		uint16_t Byte ;
		struct {
		uint16_t Day     : 1 ,	// DAY
		 Average	: 1 ,	// AVG
				 Memory  	: 1 ;	// P7
		} Bit ;
	} mem ;	
	//
	union {
  		uint16_t Byte ;	
		struct {
			uint16_t BigNum_DP       : 1 ,	// P4
					 Bat     	 : 1 ,
					 //BatLv0 		 : 1 ,
					 //BatLv1 		 : 1 ,
					 //BatLv2 		 : 1 ,	
					 BefMeal	    : 1 ,	// P6
					 AftMeal		: 1 ,	// P5
						Gen 	   : 1 ,   // P6
					 ControlSoultion : 1,
					 mute		: 1 ;	// P5
					 
		} Bit ;
	} meas ;
	//
	union {
  		uint16_t Byte ;	
		struct {
			uint16_t BLE       		: 1 ,	// P4
					 BLE_S1     		: 1 ,	// P8
					 BLE_S2 			: 1 ,	// P9
					 BLE_S3         	: 1 ,	// P12
					 OK         		: 1 ,	// P12
					 Fail         		: 1 ;	// P12
		} Bit ;
	} send ;
	//
	union {
  		uint16_t Byte ;	
		struct {
			uint16_t Ant       		: 1 ,	// ÐÅºÅÖµ
					 Lv0     		: 1 ,	//
					 Lv1 			: 1 ,	// 
					 Lv2         	: 1 ;	// 
					// Lv3         	: 1 ;	// 
		} Bit ;
	} ant ;
	
	union {
		uint16_t Byte ;	
	struct {
		uint16_t Alarm       		: 1 ,	// ÄÖÁå
				 Alarm_seg1     	: 1 ,	// 
				 Alarm_seg2 		: 1 ,	// 
				 Alarm_seg3         : 1 ,	// 
				 Alarm_seg4         : 1 ;	// 
	} Bit ;
} alarm ;
	
} ;


/* ==================================
 *		Basic LCD Function
 * ==================================
*/

extern const uint8_t AsciiTab[16] ;
extern const uint16_t HexTab[16] ;
extern  const uint16_t charTab[];

extern struct tagLCD lcd ;

extern void Show_BigString( char *str ) ;
extern void Show_MonthDayString( char *str ) ;
extern void Show_HourMinString( char *str ) ;
extern void ShowDec_BigNum( uint16_t data ) ;
extern void ShowDec_HourMin( uint16_t data ) ;
//extern void ShowDec_HourMin( uint8_t hour, uint8_t minutes ) ;
extern void ShowDec_MonthDay( INT16U data ) ;
//extern void ShowDec_MonthDay( uint8_t month, uint8_t day ) ;
extern void ShowDec_MeasDownCount( uint8_t data ) ;
extern void Clr_BigString(void);
void Clr_MonthDayString(void);
extern void Clr_MonthString (void);
extern void Clr_DayString (void);
extern void Clr_HourString (void);
extern void Clr_MinString (void);
extern void Clr_Unit (void);
void ScanKey(void);
void ShowDec_BigNum_for_mem( uint16_t data );
void Lcd_Bat(unsigned char BatLevel);
//extern void Clr_MonthDayString (void);
extern void Clr_HourMinString (void);

extern void LCD_BitSetOut( enum tagLCDBIT LcdBitIndex , bool OnOff ) ;
extern void LCD_ScanIn() ;
extern void LCD_ScanOut() ;
extern void LCD_Clear( bool OnOff ) ;
extern void LCD_Clear_Buff( bool OnOff ) ;

extern void WriteAll_LCD( uint8_t *p , uint8_t cnt );
extern void ReadAll_LCD( uint8_t *p , uint8_t cnt );
void Lcd_Bat(unsigned char BatLevel);
extern void LCD_Par_init(void);
extern void LCD_Update(uint8_t status);
extern void LCD_ScanOut1();
extern void LCD_Clear1( bool OnOff );


#endif	// End If LCDSCAN_H




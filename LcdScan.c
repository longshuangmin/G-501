#include "include.h"

/* ==================================
 *		Basic LCD Function
 * ==================================
*/
struct tagLCD lcd ;

static uint8_t LcdBuf[sizeof(M_LCD_RAM)/sizeof(M_LCD_RAM[0])] ;

const uint8_t AsciiTab[16] = { 
	'0' , '1' , '2' , '3' ,
	'4' , '5' , '6' , '7' ,
	'8' , '9' , 'a' , 'b' ,
	'C' , 'd' , 'e' , 'f' ,
} ;

const uint16_t HexTab[16] = { 
	CHAR0 , CHAR1 , CHAR2 , CHAR3 ,
	CHAR4 , CHAR5 , CHAR6 , CHAR7 ,
	CHAR8 , CHAR9 , CHARa , CHARb ,
	CHARC , CHARd , CHARe , CHARf ,
} ;

const uint16_t charTab[] = {
// disCode     Character  Decimal  HEX   
//
   CHAR_NULL ,       // NUL      000      00
   CHAR_NULL ,       // SOH      001      01
   CHAR_NULL ,       // STX      002      02
   CHAR_NULL ,       // ETX      003      03
   CHAR_NULL ,       // EOT      004      04
   CHAR_NULL ,       // ENQ      005      05
   CHAR_NULL ,       // ACK      006      06
   CHAR_NULL ,       // BEL      007      07
   CHAR_NULL ,       //  BS      008      08
   CHAR_NULL ,       //  HT      009      09
   CHAR_NULL ,       //  LF      010      0A
   CHAR_NULL ,       //  VT      011      0B
   CHAR_NULL ,       //  FF      012      0C
   CHAR_NULL ,       //  CR      013      0D
   CHAR_NULL ,       //  SO      014      0E
   CHAR_NULL ,       //  SI      015      0F

   CHAR_NULL ,       // DLE      016      10
   CHAR_NULL ,       // DC1      017      11
   CHAR_NULL ,       // DC2      018      12
   CHAR_NULL ,       // DC3      019      13
   CHAR_NULL ,       // DC4      020      14
   CHAR_NULL ,       // NAK      021      15
   CHAR_NULL ,       // SYN      022      16
   CHAR_NULL ,       // ETB      023      17
   CHAR_NULL ,       // CAN      024      18
   CHAR_NULL ,       //  EM      025      19
   CHAR_NULL ,       // SUB      026      1A
   CHAR_NULL ,       // ESC      027      1B
   CHAR_NULL ,       //  FS      028      1C
   CHAR_NULL ,       //  GS      029      1D
   CHAR_NULL ,       //  RS      030      1E
   CHAR_NULL ,       //  US      031      1F
             
   CHAR_NULL ,       //  SP      032      20
   CHAR_NULL ,       //   !      033      21
   CHAR_NULL ,       //   "      034      22
   CHAR_NULL ,       //   #      035      23
   CHAR_NULL ,       //   $      036      24
   CHAR_NULL ,       //   %      037      25
   CHAR_NULL ,       //   &      038      26
   CHAR_NULL ,       //   '      039      27
   CHAR_NULL ,       //   (      040      28
   CHAR_NULL ,       //   )      041      29
   CHAR_NULL ,       //   *      042      2A
   CHAR_NULL ,       //   +      043      2B
   CHAR_NULL ,       //   ,      044      2C
   CHARdash,         //   -      045      2D
   CHAR_NULL ,       //   .      046      2E
   CHAR_NULL ,       //   /      047      2F

   CHAR0 ,           //   0      048      30
   CHAR1 ,           //   1      049      31
   CHAR2 ,           //   2      050      32
   CHAR3 ,           //   3      051      33
   CHAR4 ,           //   4      052      34
   CHAR5 ,           //   5      053      35
   CHAR6 ,           //   6      054      36
   CHAR7 ,           //   7      055      37
   CHAR8 ,           //   8      056      38
   CHAR9 ,           //   9      057      39
   CHAR_NULL ,       //   :      058      3A
   CHAR_NULL ,       //   ;      059      3B
   CHAR_NULL ,       //   <      060      3C
   CHAR_NULL ,       //   =      061      3D
   CHAR_NULL ,       //   >      062      3E
   CHARquestion ,    //   ?      063      3F

   CHAR_NULL ,       //   @      064      40
   CHARa ,      	 //   A      065      41
   CHARb ,      	 //   B      066      42
   CHARC ,      	 //   C      067      43
   CHARd ,      	 //   D      068      44
   CHARe ,      	 //   E      069      45
   CHARf ,      	 //   F      070      46
   CHARg ,      	 //   G      071      47
   CHARH ,      	 //   H      072      48
   CHARI ,      	 //   I      073      49
   CHARj ,      	 //   J      074      4A
   CHARK ,      	 //   K      075      4B
   CHARl ,      	 //   L      076      4C
   CHARm ,      	 //   M      077      4D
   CHARN ,      	 //   N      078      4E
   CHAR0 ,      	 //   O      079      4F
                	 
   CHARp ,      	 //   P      080      50
   CHARq ,      	 //   Q      081      51
   CHARr ,      	 //   R      082      52
   CHARs ,      	 //   S      083      53
   CHARt ,      	 //   T      084      54
   CHARu ,      	 //   U      085      55
   CHARv ,      	 //   V      086      56
   CHARw ,      	 //   W      087      57
   CHARx ,      	 //   X      088      58
   CHARy ,      	 //   Y      089      59
   CHARz ,      	 //   Z      090      5A
   CHAR_NULL ,       //   [      091      5B
   CHAR_NULL ,       //   \      092      5C
   CHAR_NULL ,       //   ]      093      5D
   CHAR_NULL ,       //   ^      094      5E
   CHAR_ ,      	 //   _      095      5F

   CHAR_NULL ,       //   '      096      60
   CHARa ,      	 //   a      097      61
   CHARb ,      	 //   b      098      62
   CHARc ,      	 //   c      099      63
   CHARd ,      	 //   d      100      64
   CHARe ,      	 //   e      101      65
   CHARf ,      	 //   f      102      66
   CHARg ,      	 //   g      103      67
   CHARh ,      	 //   h      104      68
   CHARi ,      	 //   i      105      69
   CHARj ,      	 //   j      106      6A
   CHARk ,      	 //   k      107      6B
   CHARl ,      	 //   l      108      6C
   CHARm ,      	 //   m      109      6D
   CHARn ,      	 //   n      110      6E
   CHARo ,      	 //   o      111      6F
                	 
   CHARp ,      	 //   p      112      70
   CHARq ,      	 //   q      113      71
   CHARr ,      	 //   r      114      72
   CHARs ,      	 //   s      115      73
   CHARt ,      	 //   t      116      74
   CHARu ,      	 //   u      117      75
   CHARv ,      	 //   v      118      76
   CHARw ,      	 //   w      119      77
   CHARx ,      	 //   x      120      78
   CHARy ,      	 //   y      121      79
   CHARz ,      	 //   z      122      7A
   CHAR_NULL ,       //   {      123      7B
   CHAR_NULL ,       //   |      124      7C
   CHAR_NULL ,       //   }      125      7D
   CHAR_NULL ,       //   ~      126      7E
   CHAR_NULL ,       // DEL      127      7F
} ;

struct tagLCDTAB {
   uint16_t *id ; uint16_t mark ; uint8_t *adr ; uint8_t Bit ; uint8_t Index ;
};

static struct tagLCDTAB const LCDMappingTab[] = {
	{&lcd.strip.Byte ,		LcdSeg_Strip_Blood  	    ,	&LcdBuf[16] , LcdSeg_S5  ,	16 },
   	{&lcd.strip.Byte ,		LcdSeg_Strip_StripBase 	    ,	&LcdBuf[16] , LcdSeg_S4  ,  16 },
   	//                                                                                      
	{&lcd.unit.Byte ,		LcdSeg_Unit_mmoL 		    ,	&LcdBuf[3]  , LcdSeg_S1 ,  3 },
   	{&lcd.unit.Byte ,		LcdSeg_Unit_mgdL 		    ,	&LcdBuf[10]  , LcdSeg_S0 ,  10 },
   	{&lcd.unit.Byte ,		LcdSeg_Unit_Ketone 		    ,	&LcdBuf[3]  , LcdSeg_S0 ,  3 },
	{&lcd.unit.Byte ,		LcdSeg_Unit_DateSlash       ,	&LcdBuf[7]  , LcdSeg_S5 ,  7 },
   	{&lcd.unit.Byte ,		LcdSeg_Unit_TimeColon       ,	&LcdBuf[7]   , LcdSeg_S4 ,  7  },
   	{&lcd.unit.Byte ,		LcdSeg_Unit_AM   		    ,	&LcdBuf[11]  , LcdSeg_S2 ,  11 },
   	{&lcd.unit.Byte ,		LcdSeg_Unit_PM   		    ,	&LcdBuf[11]  , LcdSeg_S1 ,  11 },
   	{&lcd.unit.Byte ,		LcdSeg_Unit_TEMP   		    ,	&LcdBuf[14]  , LcdSeg_S4 ,  14 },
   	//                                                                                      
   	{&lcd.mem.Byte ,			LcdSeg_Mem_Day	            ,	&LcdBuf[4]  , LcdSeg_S1 ,   4  },
   	{&lcd.mem.Byte ,			LcdSeg_Mem_Average	        ,	&LcdBuf[4]  , LcdSeg_S0 ,   4  },
   	{&lcd.mem.Byte ,			LcdSeg_Mem_Memory 		    ,	&LcdBuf[10] , LcdSeg_S1,    10 },
	//                                                                                      
	{&lcd.meas.Byte ,		LcdSeg_Meas_BigNum_DP      	,	&LcdBuf[14]  , LcdSeg_S0 ,  14 },
    {&lcd.meas.Byte ,		LcdSeg_Meas_Bat        		,	&LcdBuf[2]  , LcdSeg_S5 ,  2 },
    //&lcd.meas.Byte ,		LcdSeg_Meas_BatLv0          ,	&LcdBuf[1]   , LcdSeg_S0 ,  1  ,
    //&lcd.meas.Byte ,		LcdSeg_Meas_BatLv1          ,	&LcdBuf[5]   , LcdSeg_S0 ,  5  ,
    //&lcd.meas.Byte ,		LcdSeg_Meas_BatLv2          ,	&LcdBuf[8]   , LcdSeg_S0 ,  8  ,
    {&lcd.meas.Byte ,		LcdSeg_Meas_BefMeal         ,	&LcdBuf[15]  , LcdSeg_S4 ,  15 },
    {&lcd.meas.Byte ,		LcdSeg_Meas_AftMeal         ,	&LcdBuf[16]  , LcdSeg_S3 ,  16 },
    {&lcd.meas.Byte ,		LcdSeg_Meas_Gen         	,	&LcdBuf[17]  , LcdSeg_S4 ,  17 },
    {&lcd.meas.Byte ,		LcdSeg_Meas_Ctl         	,	&LcdBuf[14]  , LcdSeg_S5 ,  14 },  
    {&lcd.meas.Byte ,		LcdSeg_Meas_Mute         	,	&LcdBuf[15]  , LcdSeg_S5 ,  15 },
	//
	{&lcd.send.Byte ,		LcdSeg_Send_BLE 			,	&LcdBuf[3] , LcdSeg_S5 ,   3 },
    {&lcd.send.Byte ,		LcdSeg_Send_BLE_S1 			,	&LcdBuf[3] , LcdSeg_S4 ,   3 },
    {&lcd.send.Byte ,		LcdSeg_Send_BLE_S2         	,	&LcdBuf[3] , LcdSeg_S3 ,   3 },
    {&lcd.send.Byte ,		LcdSeg_Send_BLE_S3        	,	&LcdBuf[3] , LcdSeg_S2 ,   3 }, 
    {&lcd.send.Byte ,		LcdSeg_Send_OK         		,	&LcdBuf[17] , LcdSeg_S5 ,   17 },
    {&lcd.send.Byte ,		LcdSeg_Send_Fail        	,	&LcdBuf[18] , LcdSeg_S5 ,   18 }, 
	//
    {&lcd.ant.Byte ,			LcdSeg_Ant_Ant 				,	&LcdBuf[18] , LcdSeg_S1 ,  18 },
    {&lcd.ant.Byte ,			LcdSeg_Ant_Lv0         		,	&LcdBuf[18] , LcdSeg_S2 ,  18 },
    {&lcd.ant.Byte ,			LcdSeg_Ant_Lv1         		,	&LcdBuf[18] , LcdSeg_S3 ,  18 },
    {&lcd.ant.Byte ,			LcdSeg_Ant_Lv2         		,	&LcdBuf[18] , LcdSeg_S4 ,  18 },
 //   &lcd.ant.Byte ,			LcdSeg_Ant_Lv3         		,	&LcdBuf[14] , LcdSeg_S2 ,  14 ,    

	{&lcd.alarm.Byte ,			LcdSeg_Alarm_Alarm 		,	&LcdBuf[2] , LcdSeg_S2 ,  2 },
    {&lcd.alarm.Byte ,			LcdSeg_Alarm_Seg1       ,	&LcdBuf[2] , LcdSeg_S0 ,  2 },
    {&lcd.alarm.Byte ,			LcdSeg_Alarm_Seg2       ,	&LcdBuf[2] , LcdSeg_S1 ,  2 },
    {&lcd.alarm.Byte ,			LcdSeg_Alarm_Seg3       ,	&LcdBuf[2] , LcdSeg_S3 ,  2 },
    {&lcd.alarm.Byte ,			LcdSeg_Alarm_Seg4       ,	&LcdBuf[2] , LcdSeg_S4 ,  2 },

    	
#if 0	                                                                                
	&lcd.LitNum[0] ,			SEG_a ,							&LcdBuf[13] , LcdSeg_S3 ,   13 ,
   	&lcd.LitNum[0] ,			SEG_b ,							&LcdBuf[13] , LcdSeg_S2 ,   13 ,
   	&lcd.LitNum[0] ,			SEG_c ,							&LcdBuf[13] , LcdSeg_S1 ,   13 ,
   	&lcd.LitNum[0] ,			SEG_d ,							&LcdBuf[13] , LcdSeg_S3 ,   13 ,
   	&lcd.LitNum[0] ,			SEG_e ,							&LcdBuf[13] , LcdSeg_S3 ,   13 ,
   	//&lcd.LitNum[0] ,			SEG_f ,							&LcdBuf[14] , LcdSeg_S3 ,   14 ,
   	&lcd.LitNum[0] ,			SEG_g ,							&LcdBuf[13] , LcdSeg_S3 ,   13 ,
   	//                                                  	                                
	&lcd.LitNum[1] ,			SEG_a ,							&LcdBuf[11] , LcdSeg_S3 ,   11 , 
   	&lcd.LitNum[1] ,			SEG_b ,							&LcdBuf[11] , LcdSeg_S2 ,   11 , 
   	&lcd.LitNum[1] ,			SEG_c ,							&LcdBuf[11] , LcdSeg_S1 ,   11 , 
   	&lcd.LitNum[1] ,			SEG_d ,							&LcdBuf[11] , LcdSeg_S0 ,   11 , 
   	&lcd.LitNum[1] ,			SEG_e ,							&LcdBuf[12] , LcdSeg_S1 ,   12 ,
   	&lcd.LitNum[1] ,			SEG_f ,							&LcdBuf[12] , LcdSeg_S3 ,   12 ,
   	&lcd.LitNum[1] ,			SEG_g ,							&LcdBuf[12] , LcdSeg_S2 ,   12 ,
   	//                                                                                      
	&lcd.LitNum[2] ,			SEG_a ,							&LcdBuf[9]  , LcdSeg_S3 ,   9  , 
   	&lcd.LitNum[2] ,			SEG_b ,							&LcdBuf[9]  , LcdSeg_S2 ,   9  , 
   	&lcd.LitNum[2] ,			SEG_c ,							&LcdBuf[9]  , LcdSeg_S1 ,   9  , 
   	&lcd.LitNum[2] ,			SEG_d ,							&LcdBuf[9]  , LcdSeg_S0 ,   9  , 
   	&lcd.LitNum[2] ,			SEG_e ,							&LcdBuf[10] , LcdSeg_S1 ,   10 , 
   	&lcd.LitNum[2] ,			SEG_f ,							&LcdBuf[10] , LcdSeg_S3 ,   10 , 
   	&lcd.LitNum[2] ,			SEG_g ,							&LcdBuf[10] , LcdSeg_S2 ,   10 , 
   	//                                                                                      
	&lcd.LitNum[3] ,			SEG_a ,							&LcdBuf[7]  , LcdSeg_S3 ,   7  , 
   	&lcd.LitNum[3] ,			SEG_b ,							&LcdBuf[7]  , LcdSeg_S2 ,   7  , 
   	&lcd.LitNum[3] ,			SEG_c ,							&LcdBuf[7]  , LcdSeg_S1 ,   7  , 
   	&lcd.LitNum[3] ,			SEG_d ,							&LcdBuf[7]  , LcdSeg_S0 ,   7  , 
   	&lcd.LitNum[3] ,			SEG_e ,							&LcdBuf[8]  , LcdSeg_S1 ,   8  , 
   	&lcd.LitNum[3] ,			SEG_f ,							&LcdBuf[8]  , LcdSeg_S3 ,   8  , 
   	&lcd.LitNum[3] ,			SEG_g ,							&LcdBuf[8]  , LcdSeg_S2 ,   8  , 
#endif
   	//                                                                                      
   	{&lcd.hour[0] ,			SEG_a ,							&LcdBuf[4]  , LcdSeg_S2 ,   4  },
   	{&lcd.hour[0] ,			SEG_b ,							&LcdBuf[5]  , LcdSeg_S2 ,   5  },
   	{&lcd.hour[0] ,			SEG_c ,							&LcdBuf[5]  , LcdSeg_S4 ,   5  },
   	{&lcd.hour[0] ,			SEG_d ,							&LcdBuf[4]  , LcdSeg_S5 ,   4  },
    {&lcd.hour[0] ,			SEG_e ,							&LcdBuf[4]  , LcdSeg_S4 ,   4  },
  	{&lcd.hour[0] ,			SEG_f ,							&LcdBuf[4]  , LcdSeg_S3,    4  }, 
   	{&lcd.hour[0] ,			SEG_g ,							&LcdBuf[5]  , LcdSeg_S3 ,   5  },
   	//                                                                                      
	{&lcd.hour[1] ,			SEG_a ,							&LcdBuf[5]  , LcdSeg_S0 ,   5  },
	{&lcd.hour[1] ,			SEG_b ,							&LcdBuf[6]  , LcdSeg_S2 ,   6  },
   	{&lcd.hour[1] ,			SEG_c ,							&LcdBuf[6]  , LcdSeg_S4 ,   6  },
   	{&lcd.hour[1] ,			SEG_d ,							&LcdBuf[6]  , LcdSeg_S5 ,   6  },
   	{&lcd.hour[1] ,			SEG_e ,							&LcdBuf[5]  , LcdSeg_S5 ,   5  },
   	{&lcd.hour[1] ,			SEG_f ,							&LcdBuf[5]  , LcdSeg_S1 ,   5  },
   	{&lcd.hour[1] ,			SEG_g ,							&LcdBuf[6]  , LcdSeg_S3 ,   6  },
   	//                                                                                      
	{&lcd.min[0] ,			SEG_a ,							&LcdBuf[8]  , LcdSeg_S2 ,   8  },
   	{&lcd.min[0] ,			SEG_b ,							&LcdBuf[9]  , LcdSeg_S3 ,   9  },
   	{&lcd.min[0] ,			SEG_c ,							&LcdBuf[9]  , LcdSeg_S5 ,   9  },
   	{&lcd.min[0] ,			SEG_d ,							&LcdBuf[8]  , LcdSeg_S5 ,   8  },
   	{&lcd.min[0] ,			SEG_e ,							&LcdBuf[8]  , LcdSeg_S4 ,   8  },
   	{&lcd.min[0] ,			SEG_f ,							&LcdBuf[8]  , LcdSeg_S3 ,   8  },
   	{&lcd.min[0] ,			SEG_g ,							&LcdBuf[9]  , LcdSeg_S4 ,    9  },
   	//                                                                                      
	{&lcd.min[1] ,			SEG_a ,							&LcdBuf[10]  , LcdSeg_S2 ,   10  },
   	{&lcd.min[1] ,			SEG_b ,							&LcdBuf[11]  , LcdSeg_S3 ,   11  },
   	{&lcd.min[1] ,			SEG_c ,							&LcdBuf[11]  , LcdSeg_S5 ,   11  },
   	{&lcd.min[1] ,			SEG_d ,							&LcdBuf[10]  , LcdSeg_S5 ,   10  },
   	{&lcd.min[1] ,			SEG_e ,							&LcdBuf[10]  , LcdSeg_S4 ,   10  },
   	{&lcd.min[1] ,			SEG_f ,							&LcdBuf[10]  , LcdSeg_S3 ,   10  },
   	{&lcd.min[1] ,			SEG_g ,							&LcdBuf[11]  , LcdSeg_S4 ,   11  },
   	//                                                                                      
	{&lcd.BigNum[0] ,		SEG_a ,							&LcdBuf[17] , LcdSeg_S3 ,  17 },
   	{&lcd.BigNum[0] ,		SEG_b ,							&LcdBuf[16] , LcdSeg_S2 ,  16 },
   	{&lcd.BigNum[0] ,		SEG_c ,							&LcdBuf[16] , LcdSeg_S0 ,  16 },
   	{&lcd.BigNum[0] ,		SEG_d ,							&LcdBuf[17] , LcdSeg_S0 ,  17 },
   	{&lcd.BigNum[0] ,		SEG_e ,							&LcdBuf[17] , LcdSeg_S1 ,  17 },
   	{&lcd.BigNum[0] ,		SEG_f ,							&LcdBuf[17] , LcdSeg_S2 ,  17 },
   	{&lcd.BigNum[0] ,		SEG_g ,							&LcdBuf[16] , LcdSeg_S1 ,  16 }, 	
   	//                                                                                      
	{&lcd.BigNum[1] ,		SEG_a ,							&LcdBuf[15] , LcdSeg_S3,   15 },
   	{&lcd.BigNum[1] ,		SEG_b ,							&LcdBuf[14] , LcdSeg_S3,   14 },
   	{&lcd.BigNum[1] ,		SEG_c ,							&LcdBuf[14] , LcdSeg_S1,   14 },
   	{&lcd.BigNum[1] ,		SEG_d ,							&LcdBuf[15] , LcdSeg_S0,   15 },
   	{&lcd.BigNum[1] ,		SEG_e ,							&LcdBuf[15] , LcdSeg_S1,   15 },
   	{&lcd.BigNum[1] ,		SEG_f ,							&LcdBuf[15] , LcdSeg_S2,   15 },
   	{&lcd.BigNum[1] ,		SEG_g ,							&LcdBuf[14] , LcdSeg_S2,   41 },
   	//                                                                                      
	{&lcd.BigNum[2] ,		SEG_a ,							&LcdBuf[13] , LcdSeg_S5 ,  13 },
   	{&lcd.BigNum[2] ,		SEG_b ,							&LcdBuf[12] , LcdSeg_S5 ,  12 },
   	{&lcd.BigNum[2] ,		SEG_c ,							&LcdBuf[12] , LcdSeg_S3 ,  12 },
   	{&lcd.BigNum[2] ,		SEG_d ,							&LcdBuf[13] , LcdSeg_S0 ,  13 },
   	{&lcd.BigNum[2] ,		SEG_e ,							&LcdBuf[13] , LcdSeg_S1 ,  13 },
   	{&lcd.BigNum[2] ,		SEG_f ,							&LcdBuf[13] , LcdSeg_S3 ,  13 },
   	{&lcd.BigNum[2] ,		SEG_g ,							&LcdBuf[12] , LcdSeg_S4 ,  12 },
    {&lcd.BigNum[2] ,		SEG_h ,							&LcdBuf[13] , LcdSeg_S4 ,   13 },
    {&lcd.BigNum[2] ,		SEG_i ,							&LcdBuf[13] , LcdSeg_S2 ,   13 }   	
} ;                                                                                  

//--------------------------------------------------------------------------
void LCD_ScanIn()
{
   	uint8_t index ;
   	
   	ReadAll_LCD( LcdBuf , sizeof(LcdBuf) ) ;
   	
	index = 0 ;
	do {   	
   		if( *LCDMappingTab[index].adr & LCDMappingTab[index].Bit ) *(LCDMappingTab[index].id) |=  LCDMappingTab[index].mark ;
   	   	else   	   			   								       *(LCDMappingTab[index].id) &= ~LCDMappingTab[index].mark ;
   	} while( sizeof(LCDMappingTab)/sizeof(LCDMappingTab[0]) > ++index ) ;
}
//extern unsigned char Is_Stop_Update_Lcd(void);
//--------------------------------------------------------------------------
void LCD_ScanOut1()
{
	//do {   	
   		if( *LCDMappingTab[lcd_scan_index].id & LCDMappingTab[lcd_scan_index].mark )
   			 *(LCDMappingTab[lcd_scan_index].adr) |=  LCDMappingTab[lcd_scan_index].Bit ;
   	   	else 
   	   	  	 *(LCDMappingTab[lcd_scan_index].adr) &= ~LCDMappingTab[lcd_scan_index].Bit ;
	//	if(Is_Stop_Update_Lcd()==1)
   //	return;  	   	  	 
   //	} while( sizeof(LCDMappingTab)/sizeof(LCDMappingTab[0]) > ++index ) ;
   	if(++lcd_scan_index >= LcdMappingSize)
	WriteAll_LCD( LcdBuf , sizeof(LcdBuf) ) ;
}

//--------------------------------------------------------------------------
void LCD_ScanOut()
{
	uint8_t index ;

	//LCD_ScanIn() ;
	//
	index = 0 ;
	do {   	
   		if( *LCDMappingTab[index].id & LCDMappingTab[index].mark )
   			 *(LCDMappingTab[index].adr) |=  LCDMappingTab[index].Bit ;
   	   	else 
   	   	  	 *(LCDMappingTab[index].adr) &= ~LCDMappingTab[index].Bit ;
		//if(Is_Stop_Update_Lcd()==1)
		//return;  	   	  	 
   	} while( sizeof(LCDMappingTab)/sizeof(LCDMappingTab[0]) > ++index ) ;
   	
	WriteAll_LCD( LcdBuf , sizeof(LcdBuf) ) ;
}






/*
struct tagLCDTAB {
   uint8_t *id ; uint8_t mark ; uint8_t adr ; uint8_t Bit ;
};

static struct tagLCDTAB const LCDMappingTab[] = {
	&lcd.strip.Byte ,		LcdSeg_Strip_Blood  	    ,	29 , LcdSeg_S3 ,	
   	&lcd.strip.Byte ,		LcdSeg_Strip_StripBase 	    ,	29 , LcdSeg_S4 ,    
   	//                                                                          
	&lcd.unit.Byte ,		LcdSeg_Unit_mmoL 		    ,	5  , LcdSeg_S4 ,    
   	&lcd.unit.Byte ,		LcdSeg_Unit_mgdL 		    ,	4  , LcdSeg_S5 ,    
	&lcd.unit.Byte ,		LcdSeg_Unit_AM   		    ,	10 , LcdSeg_S0 ,    
   	&lcd.unit.Byte ,		LcdSeg_Unit_PM   		    ,	21 , LcdSeg_S0 ,    
	&lcd.unit.Byte ,		LcdSeg_Unit_DateSlash       ,	6  , LcdSeg_S0 ,    
   	&lcd.unit.Byte ,		LcdSeg_Unit_TimeColon       ,	25 , LcdSeg_S0 ,    
   	//                                                                          
   	&lcd.mem.Byte ,			LcdSeg_Mem_Day	            ,	3  , LcdSeg_S4 ,    
   	&lcd.mem.Byte ,			LcdSeg_Mem_Average	        ,	3  , LcdSeg_S5 ,    
   	&lcd.mem.Byte ,			LcdSeg_Mem_Memory 		    ,	4  , LcdSeg_S4,     
	//                                                                          
	&lcd.meas.Byte ,		LcdSeg_Meas_BigNum_DP      	,	6  , LcdSeg_S5 ,    
    &lcd.meas.Byte ,		LcdSeg_Meas_Temperature    	,	29 , LcdSeg_S1 ,    
    &lcd.meas.Byte ,		LcdSeg_Meas_ControlSoultion ,	29 , LcdSeg_S2 ,    
    &lcd.meas.Byte ,		LcdSeg_Meas_Battery         ,	29 , LcdSeg_S5 ,    
    &lcd.meas.Byte ,		LcdSeg_Meas_Health_H 		,	5  , LcdSeg_S5 ,    
    &lcd.meas.Byte ,		LcdSeg_Meas_Health_N 		,	21 , LcdSeg_S5 ,    
    &lcd.meas.Byte ,		LcdSeg_Meas_Health_L 		,	25 , LcdSeg_S5 ,    
	//                                                                          
	&lcd.LitNum[0] ,			SEG_a ,							13 , LcdSeg_S0 ,    
   	&lcd.LitNum[0] ,			SEG_b ,							13 , LcdSeg_S1 ,    
   	&lcd.LitNum[0] ,			SEG_c ,							13 , LcdSeg_S2 ,    
   	&lcd.LitNum[0] ,			SEG_d ,							13 , LcdSeg_S3 ,    
   	&lcd.LitNum[0] ,			SEG_e ,							21 , LcdSeg_S3 ,    
   	&lcd.LitNum[0] ,			SEG_f ,							21 , LcdSeg_S1 ,    
   	&lcd.LitNum[0] ,			SEG_g ,							21 , LcdSeg_S2 ,    
   	//                                                  	                    
	&lcd.LitNum[1] ,			SEG_a ,							7 ,  LcdSeg_S0 ,    
   	&lcd.LitNum[1] ,			SEG_b ,							7 ,  LcdSeg_S1 ,    
   	&lcd.LitNum[1] ,			SEG_c ,							7 ,  LcdSeg_S2 ,    
   	&lcd.LitNum[1] ,			SEG_d ,							7 ,  LcdSeg_S3 ,    
   	&lcd.LitNum[1] ,			SEG_e ,							10 , LcdSeg_S3 ,    
   	&lcd.LitNum[1] ,			SEG_f ,							10 , LcdSeg_S1 ,    
   	&lcd.LitNum[1] ,			SEG_g ,							10 , LcdSeg_S2 ,    
   	//                                                                          
	&lcd.LitNum[2] ,			SEG_a ,							5 ,  LcdSeg_S0 ,    
   	&lcd.LitNum[2] ,			SEG_b ,							5 ,  LcdSeg_S1 ,    
   	&lcd.LitNum[2] ,			SEG_c ,							5 ,  LcdSeg_S2 ,    
   	&lcd.LitNum[2] ,			SEG_d ,							5 ,  LcdSeg_S3 ,    
   	&lcd.LitNum[2] ,			SEG_e ,							6 ,  LcdSeg_S3 ,    
   	&lcd.LitNum[2] ,			SEG_f ,							6 ,  LcdSeg_S1 ,    
   	&lcd.LitNum[2] ,			SEG_g ,							6 ,  LcdSeg_S2 ,    
   	//                                                                          
	&lcd.LitNum[3] ,			SEG_a ,							3 ,  LcdSeg_S0 ,    
   	&lcd.LitNum[3] ,			SEG_b ,							3 ,  LcdSeg_S1 ,    
   	&lcd.LitNum[3] ,			SEG_c ,							3 ,  LcdSeg_S2 ,    
   	&lcd.LitNum[3] ,			SEG_d ,							3 ,  LcdSeg_S3 ,    
   	&lcd.LitNum[3] ,			SEG_e ,							4 ,  LcdSeg_S3 ,    
   	&lcd.LitNum[3] ,			SEG_f ,							4 ,  LcdSeg_S1 ,    
   	&lcd.LitNum[3] ,			SEG_g ,							4 ,  LcdSeg_S2 ,    
   	//                                                                          
   	&lcd.LitNum[0] ,			SEG_a ,							28 , LcdSeg_S2 ,    
   	&lcd.LitNum[0] ,			SEG_b ,							28 , LcdSeg_S1 ,    
   	&lcd.LitNum[0] ,			SEG_c ,							28 , LcdSeg_S3 ,    
   	&lcd.LitNum[0] ,			SEG_d ,							28 , LcdSeg_S2 ,    
     &lcd.LitNum[0] ,			SEG_e ,							28 , LcdSeg_S2 ,    
  //&lcd.LitNum[0] ,			SEG_f ,							] , LcdSeg_S ,      
   	&lcd.LitNum[0] ,			SEG_g ,							28 , LcdSeg_S2 ,    
   	//                                                                          
	&lcd.LitNum[1] ,			SEG_a ,							26 , LcdSeg_S0 ,    
	&lcd.LitNum[1] ,			SEG_b ,							26 , LcdSeg_S1 ,    
   	&lcd.LitNum[1] ,			SEG_c ,							26 , LcdSeg_S2 ,    
   	&lcd.LitNum[1] ,			SEG_d ,							26 , LcdSeg_S3 ,    
   	&lcd.LitNum[1] ,			SEG_e ,							27 , LcdSeg_S3 ,    
   	&lcd.LitNum[1] ,			SEG_f ,							27 , LcdSeg_S1 ,    
   	&lcd.LitNum[1] ,			SEG_g ,							27 , LcdSeg_S2 ,    
   	//                                                                          
	&lcd.LitNum[2] ,			SEG_a ,							24 , LcdSeg_S0 ,    
   	&lcd.LitNum[2] ,			SEG_b ,							24 , LcdSeg_S1 ,    
   	&lcd.LitNum[2] ,			SEG_c ,							24 , LcdSeg_S2 ,    
   	&lcd.LitNum[2] ,			SEG_d ,							24 , LcdSeg_S3 ,    
   	&lcd.LitNum[2] ,			SEG_e ,							25 , LcdSeg_S3 ,    
   	&lcd.LitNum[2] ,			SEG_f ,							25 , LcdSeg_S1 ,    
   	&lcd.LitNum[2] ,			SEG_g ,							25 , LcdSeg_S2 ,    
   	//                                                                          
	&lcd.LitNum[3] ,			SEG_a ,							22 , LcdSeg_S0 ,    
   	&lcd.LitNum[3] ,			SEG_b ,							22 , LcdSeg_S1 ,    
   	&lcd.LitNum[3] ,			SEG_c ,							22 , LcdSeg_S2 ,    
   	&lcd.LitNum[3] ,			SEG_d ,							22 , LcdSeg_S3 ,    
   	&lcd.LitNum[3] ,			SEG_e ,							23 , LcdSeg_S3 ,    
   	&lcd.LitNum[3] ,			SEG_f ,							23 , LcdSeg_S1 ,    
   	&lcd.LitNum[3] ,			SEG_g ,							23 , LcdSeg_S2 ,    
   	//                                                                          
	&lcd.BigNum[0] ,		SEG_a ,							28 , LcdSeg_S4 ,    
   	&lcd.BigNum[0] ,		SEG_b ,							27 , LcdSeg_S4 ,    
   	&lcd.BigNum[0] ,		SEG_c ,							26 , LcdSeg_S4 ,    
   	&lcd.BigNum[0] ,		SEG_d ,							25 , LcdSeg_S4 ,    
   	&lcd.BigNum[0] ,		SEG_e ,							26 , LcdSeg_S5 ,    
   	&lcd.BigNum[0] ,		SEG_f ,							28 , LcdSeg_S5 ,    
   	&lcd.BigNum[0] ,		SEG_g ,							27 , LcdSeg_S5 ,      	
   	//                                                                          
	&lcd.BigNum[1] ,		SEG_a ,							24 , LcdSeg_S4,     
   	&lcd.BigNum[1] ,		SEG_b ,							23 , LcdSeg_S4,     
   	&lcd.BigNum[1] ,		SEG_c ,							22 , LcdSeg_S4,     
   	&lcd.BigNum[1] ,		SEG_d ,							21 , LcdSeg_S4,     
   	&lcd.BigNum[1] ,		SEG_e ,							22 , LcdSeg_S5,     
   	&lcd.BigNum[1] ,		SEG_f ,							24 , LcdSeg_S5,     
   	&lcd.BigNum[1] ,		SEG_g ,							23 , LcdSeg_S5,     
   	//                                                                          
	&lcd.BigNum[2] ,		SEG_a ,							13 , LcdSeg_S4 ,    
   	&lcd.BigNum[2] ,		SEG_b ,							10 , LcdSeg_S4 ,    
   	&lcd.BigNum[2] ,		SEG_c ,							7  , LcdSeg_S4 ,    
   	&lcd.BigNum[2] ,		SEG_d ,							6  , LcdSeg_S4 ,    
   	&lcd.BigNum[2] ,		SEG_e ,							7  , LcdSeg_S5 ,    
   	&lcd.BigNum[2] ,		SEG_f ,							13 , LcdSeg_S5 ,    
   	&lcd.BigNum[2] ,		SEG_g ,							10 , LcdSeg_S5 ,    
} ;

*/

/*
struct tagLCDTAB {
   uint8_t *id ; uint8_t mark ; uint8_t *adr ; uint8_t Bit ;
};
*/

/*
void LCD_ScanIn()
{
   	uint8_t index ;
   	
   	ReadAll_LCD( LcdBuf , sizeof(LcdBuf) ) ;
   	
	index = 0 ;
	do {   	
   		if( LcdBuf[LCDMappingTab[index].adr] & LCDMappingTab[index].Bit ) *LCDMappingTab[index].id |=  LCDMappingTab[index].mark ;
   	   	else   	   			   				  				              *LCDMappingTab[index].id &= ~LCDMappingTab[index].mark ;
   	} while( sizeof(LCDMappingTab)/sizeof(LCDMappingTab[0]) > ++index ) ;
}

void LCD_ScanOut()
{
	uint8_t index ;

	ReadAll_LCD( LcdBuf , sizeof(LcdBuf) ) ;
	//
	index = 0 ;
	do {   	
   		if( *LCDMappingTab[index].id & LCDMappingTab[index].mark ) LcdBuf[LCDMappingTab[index].adr] |=  LCDMappingTab[index].Bit ;
   	   	else   	   			   								       LcdBuf[LCDMappingTab[index].adr] &= ~LCDMappingTab[index].Bit ;
   	} while( sizeof(LCDMappingTab)/sizeof(LCDMappingTab[0]) > ++index ) ;
   	//
	WriteAll_LCD( LcdBuf , sizeof(LcdBuf) ) ;
}
*/
void LCD_Par_init(void)
{
	Start_Detection_flag= 0 ;

	LcdMappingSize=sizeof(LCDMappingTab)/sizeof(LCDMappingTab[0]);

}
//--------------------------------------------------------------------------
void LCD_BitSetOut( enum tagLCDBIT LcdBitIndex , bool OnOff )
{
	if( ON == OnOff ) 
	{
		*LCDMappingTab[LcdBitIndex].id |= LCDMappingTab[LcdBitIndex].mark ;    
		//M_LCD_RAM[index] |= LCDMappingTab[LcdBitIndex].Bit ;
		M_LCD_RAM[LCDMappingTab[LcdBitIndex].Index] |= LCDMappingTab[LcdBitIndex].Bit ;
	}
	else 
	{
		*LCDMappingTab[LcdBitIndex].id &= ~LCDMappingTab[LcdBitIndex].mark ;
		M_LCD_RAM[LCDMappingTab[LcdBitIndex].Index] &= ~LCDMappingTab[LcdBitIndex].Bit ;
	}
}
void LCD_Seg_TestScan(void)
{
	unsigned char lcdbuf_idle=2;
	 unsigned char lcd_seg=0;
	//int i=0;
	//fun_UART0PowerOnInit();
	#if 1
	lcdbuf_idle=10;
	lcd_seg=0;
	while(1)
	{
		GCC_CLRWDT();
		delay(10);		 //1ms for base
		//if(P_M_KEY ==0)
		{
			delay(100);
			//if(P_M_KEY ==0)
			{
				if(lcd_seg==0)
				{
					LcdBuf[lcdbuf_idle] |= LcdSeg_S0;
				}
				else if(lcd_seg==1)
				{
					LcdBuf[lcdbuf_idle] |=LcdSeg_S1;
				}
				else if(lcd_seg==2)
				{
					LcdBuf[lcdbuf_idle] |=LcdSeg_S2;
				}
				else if(lcd_seg==3)
				{
					LcdBuf[lcdbuf_idle] |=LcdSeg_S3;
				}
				else if(lcd_seg==4)
				{
					LcdBuf[lcdbuf_idle] |=LcdSeg_S4;
				}
				else if(lcd_seg==5)
				{
					LcdBuf[lcdbuf_idle] |=LcdSeg_S5;
				}
				//print_str("lcdbuf_idle:");
				//print_long(lcdbuf_idle);
				//print_str("  lcd_seg:");
				///print_long(lcd_seg);
				//print_str("\r\n");		
				WriteAll_LCD( LcdBuf , sizeof(LcdBuf) ) ;
				delay(100);
				//LcdBuf[lcdbuf_idle] = 0;
				memset(LcdBuf,0,sizeof(LcdBuf));

				//LCD_ScanOut();
				lcd_seg++;
				if(lcd_seg==6)
				{
					lcdbuf_idle++;
					lcd_seg = 0;

				}
				//while(P_M_KEY==0)
				{
					GCC_CLRWDT();
					delay(10);		 //1ms for base
				}
			}
		}
	}
	#else
	//LCD_Clear(ON);
	for(i=0;i<sizeof(LcdBuf);i++)
		LcdBuf[i] = 0xff;
	WriteAll_LCD( LcdBuf , sizeof(LcdBuf) ) ;
	while(1)
	{
	GCC_CLRWDT();
	delay(200);
	#if 0
		LCD_Clear(ON);
		delay(200);
		delay(200);
		delay(200);
		delay(200);
		delay(200);
		LCD_Clear(OFF);
		delay(200);
		delay(200);
		delay(200);
		delay(200);
		delay(200);
		#endif
	}
	#endif
}

/*
//此寫法Complier會認為錯誤
void LCD_ScanIn()
{
   	struct tagLCDTAB const *p;
   	
   	ReadAll_LCD( LcdBuf , sizeof(LcdBuf) ) ;
   	
   	p = LCDMappingTab + sizeof(LCDMappingTab)/sizeof(LCDMappingTab[0]);
   	while(LCDMappingTab != p--) {
   		if( *p->adr & p->Bit ) *p->id |=  p->mark ;
   	   	else   	   			   *p->id &= ~p->mark ;
   	}
}
*/

/*
void LCD_ScanOut()
{
   	struct tagLCDTAB const *p;
   	
   	//ReadAll_LCD( LcdBuf , sizeof(LcdBuf) ) ;
   	
   	p = LCDMappingTab + sizeof(LCDMappingTab)/sizeof(LCDMappingTab[0]);
   	while(LCDMappingTab != p--) {
   	   if( *p->id & p->mark ) *p->adr |=  p->Bit;
   	   else                   *p->adr &= ~p->Bit;
   	}
   	//
	WriteAll_LCD( LcdBuf , sizeof(LcdBuf) ) ;
}
*/

//--------------------------------------------------------------------------
void LCD_Clear_Buff( bool OnOff )
{
	uint8_t *p = (uint8_t *)&lcd ;
	uint8_t i = sizeof(lcd) ;

	while( i-- ) *p++ = OnOff ? 0xff : 0x00 ;
	//
}

//--------------------------------------------------------------------------
void LCD_Clear( bool OnOff )
{
	LCD_Clear_Buff( OnOff ) ;
	//
	if( OFF == OnOff ) {
	}
	else {
	}	
	LCD_ScanOut() ;
}

void LCD_Clear1( bool OnOff )
{
	LCD_Clear_Buff( OnOff ) ;
	memset(LcdBuf,0,sizeof(LcdBuf));
	WriteAll_LCD( LcdBuf , sizeof(LcdBuf) );
}

//
//--------------------------------------------------------------------------
void Show_BigString(char *str )
{
    lcd.BigNum[0] = charTab[(unsigned char)*str++] ;
    lcd.BigNum[1] = charTab[(unsigned char)*str++] ;
    lcd.BigNum[2] = charTab[(unsigned char)*str++] ;
}

//--------------------------------------------------------------------------
void Clr_BigString(void)
{
    lcd.BigNum[0] = 0 ;
    lcd.BigNum[1] = 0 ;
    lcd.BigNum[2] = 0 ;
//    //
//    LCD_ScanOut() ;
}

//--------------------------------------------------------------------------
void Show_MonthDayString( char *str )
{
    lcd.month[0] = charTab[(unsigned char)*str++] ;
    lcd.month[1] = charTab[(unsigned char)*str++] ;
    lcd.day[0]   = charTab[(unsigned char)*str++] ;
    lcd.day[1]   = charTab[(unsigned char)*str++] ;
}

//--------------------------------------------------------------------------
void Clr_MonthDayString(void)
{
    lcd.hour[0] = 0 ;
    lcd.hour[1] = 0 ;
    lcd.min[0]   = 0 ;
    lcd.min[1]   = 0 ;
}

//--------------------------------------------------------------------------
void Clr_MonthString(void)
{
    lcd.hour[0] = 0 ;
    lcd.hour[1] = 0 ;
}

//--------------------------------------------------------------------------
void Clr_DayString(void)
{
    lcd.min[0]   = 0 ;
    lcd.min[1]   = 0 ;
}

//--------------------------------------------------------------------------
void Show_HourMinString( char *str )
{
    lcd.hour[0] = charTab[(unsigned char)*str++] ;
    lcd.hour[1] = charTab[(unsigned char)*str++] ;
    lcd.min[0]  = charTab[(unsigned char)*str++] ;
    lcd.min[1]  = charTab[(unsigned char)*str++] ;
}    

//--------------------------------------------------------------------------
void Clr_HourMinString(void)
{
    lcd.hour[0] = 0 ;
    lcd.hour[1] = 0 ;
    lcd.min[0]  = 0 ;
    lcd.min[1]  = 0 ;
}

//--------------------------------------------------------------------------
void Clr_HourString(void)
{
    lcd.hour[0] = 0 ;
    lcd.hour[1] = 0 ;
}  

//--------------------------------------------------------------------------
void Clr_MinString(void)
{
    lcd.min[0]  = 0 ;
    lcd.min[1]  = 0 ;
}     

//--------------------------------------------------------------------------
void ShowDec_BigNum( uint16_t data )
{
    data %= 1000 ;
    lcd.BigNum[0] = (data/100) ? HexTab[data/100] : 0 ;
    data %= 100 ;
	if(lcd.meas.Bit.BigNum_DP)
	lcd.BigNum[1] = HexTab[data/10];
	else
    lcd.BigNum[1] = (lcd.BigNum[0] || data/10) ? HexTab[data/10] : 0 ;
    data %= 10 ;
    lcd.BigNum[2] = HexTab[data] ;
}


void ShowDec_BigNum_for_mem( uint16_t data )
{
	UCHAR dis[3];
	dis[0]=data /100 % 10 ;	
	dis[1]=data /10 % 10 ;	
	dis[2]=data % 10 ;
	
	if(data>99)
	    lcd.BigNum[0] = HexTab[dis[0]] ;

    lcd.BigNum[1] = HexTab[dis[1]] ;
    lcd.BigNum[2] = HexTab[dis[2]] ;
}

/*
void ShowDec_MonthDay( INT16U data )
{
	lcd.LitNum[0] = (data/1000) ? HexTab[data/1000] : 0 ;
    data %= 1000 ;
    lcd.LitNum[1] = (lcd.LitNum[0] || data/100 ) ? HexTab[data/100] : 0 ;
    data %= 100 ;
    lcd.LitNum[2] = (lcd.LitNum[0] || lcd.LitNum[1] || data/10 ) ? HexTab[data/10] : 0 ;
    data %= 10 ;
    lcd.LitNum[3] = HexTab[data] ;
}

void ShowDec_HourMin( uint16_t data )
{
	lcd.LitNum[0] = (data/1000) ? HexTab[data/1000] : 0 ;
    data %= 1000 ;
    lcd.LitNum[1] = (lcd.LitNum[0] || data/100 ) ? HexTab[data/100] : 0 ;
    data %= 100 ;
    lcd.LitNum[2] = (lcd.LitNum[0] || lcd.LitNum[1] || data/10 ) ? HexTab[data/10] : 0 ;
    data %= 10 ;
    lcd.LitNum[3] = HexTab[data] ;
}
*/

void ShowDec_MonthDay( INT16U data )
{
	if(data/1000 !=0)
		lcd.month[0] = HexTab[data/1000] ;
	else
		lcd.month[0] =0; 
		
    data %= 1000 ;
    lcd.month[1] = HexTab[data/100] ;
    data %= 100 ;
    lcd.day[0] = HexTab[data/10] ;
    data %= 10 ;
    lcd.day[1] = HexTab[data] ;
}

void ShowDec_HourMin( uint16_t data )
{
	if(data/1000 !=0)
		lcd.hour[0] = HexTab[data/1000] ;
	else
		lcd.hour[0] =0;
		
    data %= 1000 ;
    lcd.hour[1] = HexTab[data/100] ;
    data %= 100 ;
    lcd.min[0] = HexTab[data/10] ;
    data %= 10 ;
    lcd.min[1] = HexTab[data] ;
}

//--------------------------------------------------------------------------
//void ShowDec_HourMin( uint16_t data )
void Lcd_Clock_Process( uint8_t hour, uint8_t minutes )
{
//	//--- time " : " flash
//	if((M_Task == C_RTCModeSettingMode) || ((M_Task == C_MemoryMode) && (M_TaskBuf0 == 3)))
//		lcd.unit.Bit.TimeColon =1;
//	else
//	{
//		if(F_500ms_LCD)
//			lcd.unit.Bit.TimeColon =~lcd.unit.Bit.TimeColon;
//			
//	}
//
	lcd.unit.Bit.DateSlash =0;//clear date slash symbol
#if (time_12_hour_en==1)
	//---12H
	if(hour >= 12)
	{
		lcd.unit.Bit.AM =0;
		lcd.unit.Bit.PM =1;
		
		if((hour - 12) ==0)			// = 0:00 23->24
			hour = 12;
		else
			hour -= 12;
	}
	else
	{
		lcd.unit.Bit.AM =1;
		lcd.unit.Bit.PM =0;
		if(hour ==0)				// = 0:00 23->24
			hour = 12;

	}	
#endif	  

	if(hour/10 !=0)
    	lcd.hour[0] = HexTab[hour/10];
    else
    	lcd.hour[0] =0;
    	
    hour %= 10 ;
    lcd.hour[1] = HexTab[hour] ;
    
    lcd.min[0] = HexTab[minutes/10];
    minutes %= 10 ;
    lcd.min[1] = HexTab[minutes] ;	
}

//--------------------------------------------------------------------------
//void ShowDec_MonthDay( INT16U data )
void Lcd_Month_Day_Process( uint8_t month, uint8_t day )
{
//	unsigned char mychar = 0;
	lcd.unit.Bit.DateSlash =1;
   //偶现屏幕显示出错，  此处做一层规避
	if(month>12 || month<1 ||
		day>31 || day<1)
	{
		Load_RtcTime_Vaule();
	}
	if(month/10 != 0)
    	lcd.hour[0] = HexTab[month/10];
    else
    	lcd.hour[0] = 0;
    	
    month %= 10 ;
    lcd.hour[1] = HexTab[month] ;
    
    lcd.min[0] = HexTab[day/10];
    day %= 10 ;
    lcd.min[1] = HexTab[day] ;	

} 	

//--------------------------------------------------------------------------
void ShowDec_MeasDownCount( uint8_t data )
{
	char str[] = "    " ;
	
	str[1] = AsciiTab[data] ;
	Show_BigString( str ) ;
}

//--------------------------------------------------------------------------
void WriteAll_LCD( uint8_t *p , uint8_t cnt )
{
	uint8_t index = 0 ;
	
	do {
		M_LCD_RAM[index++] = *p++ ;
	} while( cnt > index ) ;
}

//--------------------------------------------------------------------------
void ReadAll_LCD( uint8_t *p , uint8_t cnt )
{
	uint8_t index = 0 ;
	
	do {	
		*p++ = M_LCD_RAM[index++] ;
	} while( cnt > index ) ;	
}

//--------------------------------------------------------------------------
void Lcd_Year_Process (unsigned char Year)
{
	//unsigned char buf =20;
	
    //lcd.month[0] = HexTab[buf/10];
    //buf %= 10 ;
    //lcd.month[1] = HexTab[buf] ;
    
    lcd.BigNum[1] = HexTab[Year/10];
    Year %= 10 ;
    lcd.BigNum[2] = HexTab[Year] ;
}

//--------------------------------------------------------------------------
void Lcd_Unit()
{
	//--- display mmol or mgdl
	if((M_Unit & 0x01) !=0)
	{
		lcd.unit.Bit.mmoL =1;	//on "mmol"
		lcd.unit.Bit.mgdL =0;	//off "mgdl"
	}
	else
	{
		lcd.unit.Bit.mmoL =0;	//off "mmol"
		lcd.unit.Bit.mgdL =1;	//on "mgdl"
	}
}

//--------------------------------------------------------------------------
void Clr_Unit()
{
	lcd.unit.Bit.mmoL =0;	//off "mmol"	
	lcd.unit.Bit.mgdL =0;	//off "mgdl"
}

//--------------------------------------------------------------------------
void Lcd_Bat(unsigned char BatLevel)
{
	//lcd.meas.Bit.Bat =1;
	//--- display bat level
	if(BatLevel ==0)
	{
		//lcd.meas.Bit.BatLv0 =0;
		//lcd.meas.Bit.BatLv1 =0;
		//lcd.meas.Bit.BatLv2 =0;
		lcd.meas.Bit.Bat =1;
	}
	else
	{
		lcd.meas.Bit.Bat =0;

	}
	#if 0
	else if(BatLevel ==1)
	{
		lcd.meas.Bit.BatLv0 =1;
		lcd.meas.Bit.BatLv1 =0;
		lcd.meas.Bit.BatLv2 =0;
	}
	else if(BatLevel ==2)
	{
		lcd.meas.Bit.BatLv0 =1;
		lcd.meas.Bit.BatLv1 =1;
		lcd.meas.Bit.BatLv2 =0;
	}
	else if(BatLevel ==3)
	{
		lcd.meas.Bit.BatLv0 =1;
		lcd.meas.Bit.BatLv1 =1;
		lcd.meas.Bit.BatLv2 =1;
	}
	#endif
}

//--------------------------------------------------------------------------
void Clr_Bat(void)
{
	lcd.meas.Bit.Bat =0;
	//lcd.meas.Bit.BatLv0 =0;
	//lcd.meas.Bit.BatLv1 =0;
	//lcd.meas.Bit.BatLv2 =0;
}

//--------------------------------------------------------------------------
/*
void Lcd_Display_DEL()
{
	//--- display "d"
    lcd.BigNum[0] = charTab['D'] ;
	//--- display "E"
	lcd.BigNum[1] = charTab['E'] ;
	//--- display "L"
	lcd.BigNum[2] = charTab['L'] ;
}
*/
//--------------------------------------------------------------------------
/*
void Lcd_Display_dash()
{
	//--- display "-"
    lcd.BigNum[0] = charTab['-'] ;
	//--- display "-"
	lcd.BigNum[1] = charTab['-'] ;
	//--- display "-"
	lcd.BigNum[2] = charTab['-'] ;	
}
*/
//--------------------------------------------------------------------------
/*
void Lcd_Display_OFF()
{
	//--- display "-"
    lcd.BigNum[0] = charTab['O'] ;
	//--- display "-"
	lcd.BigNum[1] = charTab['F'] ;
	//--- display "-"
	lcd.BigNum[2] = charTab['F'] ;	
}
*/
////--------------------------------------------------------------------------
void Lcd_ControlOption()
{
	//--- display Control
	if(F_ControlOption)
		lcd.meas.Bit.ControlSoultion =1;	//on "P9"
	else
		lcd.meas.Bit.ControlSoultion =0;	//off "P9"
}

//--------------------------------------------------------------------------
void Lcd_Glucose(signed int data)
{
	//unsigned char Cbuf0;
	unsigned int  Ibuf0,Ibuf1;
	
	if((data >= low) && (data <= hi))
	{
//			if( (M_GM_data >= memStrip.GlucoseMin) && (M_GM_data <= memStrip.GlucoseMax) ) {
	//if( true ) {	
		Lcd_Unit();

		
		data %= 1000 ;
		
		if((M_Unit & 0x01) !=0)
		{
			//---mmol
			Ibuf1 = data;	
			Ibuf1 *= 100;
			Ibuf1 /= 18;
			Ibuf0 = Ibuf1 / 10;
			Ibuf1 %= 10;
			//---four out five in
			if(Ibuf1 >=5)
				Ibuf0 ++;
			
			lcd.meas.Bit.BigNum_DP =1;
			ShowDec_BigNum(Ibuf0);
		}
		else
		{
			//---mgdl
			Ibuf0 = data;
			ShowDec_BigNum(Ibuf0);	
		}		
	}
	else if(data < low) {
		Lcd_Unit();
		Show_BigString( " Lo" ) ;
		//Lcd_Display_Lo();				
	}
	else if(data > hi) {
		Lcd_Unit();
		Show_BigString( " HI" ) ;
		//Lcd_Display_Hi();
	}						
//	LCD_ScanOut() ;		
	
	

	
	
	
}

//--------------------------------------------------------------------------
void Lcd_ShowHW(unsigned int data)
{
	lcd.unit.Bit.TimeColon =1;
	
	data %= 1000 ;	
	
	lcd.hour[1] = HexTab[data /100] ;
	data %= 100;
	lcd.min[0] = HexTab[data/10];
	data %= 10 ;
	lcd.min[1] = HexTab[data] ;	
}

//--------------------------------------------------------------------------
void Lcd_ShowFW(unsigned int data)
{		
	lcd.unit.Bit.DateSlash =1;
	
	if(data/1000 !=0)
    	lcd.month[0] = HexTab[data/1000];
    else
    	lcd.month[0] =0;
    	
    data %= 1000 ;
    lcd.month[1] = HexTab[data /100] ;
    data %= 100;
    lcd.day[0] = HexTab[data];
}

//--------------------------------------------------------------------------
void Lcd_ShowAvgNum(unsigned int data)
{
	data %= 1000 ;	
	if(data /100 !=0)
	lcd.hour[1] = HexTab[data /100] ;
	else
	lcd.hour[1] = 0 ;
	data %= 100;
	lcd.min[0] = HexTab[data/10];
	data %= 10 ;
	lcd.min[1] = HexTab[data] ;	
}

//--------------------------------------------------------------------------
void Lcd_ShowAvgDay(unsigned char data)
{	
	data %= 100 ;
	if(data /10 !=0)	
		lcd.month[0] = HexTab[data /10] ;
	else
		lcd.month[0] =0;
		
	data %= 10;
	lcd.month[1] = HexTab[data] ;
	
	lcd.day[0] = charTab['d'];
	
	lcd.unit.Bit.DateSlash =1;
}

//--------------------------------------------------------------------------
void Lcd_ShowC1(unsigned char data)
{
	if(data /10 !=0)
		lcd.month[0] = HexTab[data /10] ;
	else
		lcd.month[0] =0;
		
	data %= 10;
	lcd.month[1] = HexTab[data] ;
}

//--------------------------------------------------------------------------
void Lcd_ShowC2(unsigned char data)
{
	lcd.day[0] = HexTab[data /10] ;
	data %= 10;
	lcd.day[1] = HexTab[data] ;
}

//--------------------------------------------------------------------------
void Lcd_ShowRecordLength(unsigned int data)
{
	data %= 1000 ;	

	lcd.hour[1] = HexTab[data /100] ;
	data %= 100;
	lcd.min[0] = HexTab[data/10];
	data %= 10 ;
	lcd.min[1] = HexTab[data] ;	
}

//--------------------------------------------------------------------------
/*
void Lcd_Display_Hi()
{
	//--- display "H"
	lcd.BigNum[1] = charTab['H'] ;
	//--- display "I"
	lcd.BigNum[2] = charTab['I'] ;
}
*/
//--------------------------------------------------------------------------

/*
void Lcd_Display_Lo()
{
	//--- display "L"
	lcd.BigNum[1] = charTab['L'] ;
	//--- display "O"
	lcd.BigNum[2] = charTab['O'] ;		
}
*/

//--------------------------------------------------------------------------
/*
void Lcd_Display_Ok()
{
	//--- display "O"
	lcd.BigNum[1] = charTab['O'] ;
	//--- display "K"
	lcd.BigNum[2] = charTab['K'] ;
	
	lcd.display.Bit.Dis_P5 =1;
	lcd.display.Bit.Dis_P6 =1;			
}
*/

//--------------------------------------------------------------------------
/*
void Lcd_Display_LNK()
{
	//--- display "L"
	lcd.BigNum[0] = charTab['L'] ;
	//--- display "N"
	lcd.BigNum[1] = charTab['n'] ;
	//--- display "K"
	lcd.BigNum[2] = charTab['K'] ;
	
	lcd.display.Bit.Dis_P5 =1;
	lcd.display.Bit.Dis_P6 =1;			
}
*/

//--------------------------------------------------------------------------
/*
void Lcd_Display_PC()
{
	//--- display "P"
	lcd.BigNum[1] = charTab['P'] ;
	//--- display "C"
	lcd.BigNum[2] = charTab['C'] ;		
}
*/
//--------------------------------------------------------------------------
void Lcd_Display_Tes()
{
	//--- display "L"
	lcd.BigNum[0] = charTab['t'] ;
	//--- display "N"
	lcd.BigNum[1] = charTab['E'] ;
	//--- display "K"
	lcd.BigNum[2] = charTab['S'] ;			
}




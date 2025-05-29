////--- FLASH ROM address data MAP
#define	 C_Flash_RecordAdr				0x00
#define	 C_Flash_Current_RecordAdr		0x01
#define	 C_Flash_Send_RecordAdr			0x02
#define	 C_Flash_UnitAdr				0x03
#define	 C_Flash_Alarm1Adr				0x04
#define	 C_Flash_Alarm2Adr				0x05
#define	 C_Flash_Alarm3Adr				0x06
#define	 C_Flash_Alarm4Adr				0x07


struct tagBLOCK {
	uint16_t RecordAdr ,
			 Current_RecordAdr ,
			 UnitAdr ,
			 MeasureRangeMaxAdr ,
			 MeasureRangeMinAdr ,
	 		 Rev[10] ,
			 checksum ; 		 	
} ;

struct tagSYSOP {
	struct tagBLOCK Block[4] ;
} ;

struct tagSERIALNUMBER {
	INT8U data[15] ,
		  checksum ;	
} ;

struct tagSTRIP {
	uint8_t B ,						        // 0x00                                               
		    S ,                             // 0x01                                               
		    d ,                             // 0x02                                               
		    I ;                             // 0x03                                               
    uint8_t C1 ,                            // 0x04                                               
    	    C2 ;                            // 0x05                                               
	uint8_t MeasOffTime ,                   // 0x06        // Res -> 1Sec                         
		    MeasOnTime ;			        // 0x07        // Res -> 1Sec                         
	bool    Unit ,					        // 0x08        // 0 = GMunit_mg_dL , 1 = GMunit_mmol_L
		    Hospital_Personal ;		        // 0x09        // true -> Hospital, false-> Personal  
	uint8_t TrigerI ,				        // 0x0a        // Res -> 0.1uA , default -> 0.4uA     
            UserStripI ;			        // 0x0b        // Res -> 0.1uA , default -> 0.3uA     
	int8_t  TempMin ,				        // 0x0c        // Res -> 1 oC                         
		    TempMax ;				        // 0x0d        // Res -> 1 oC                         
	uint16_t GlucoseMin ,			        // 0x0e ~ 0x0f // Unit base on GMunit_mg_dL           
		     GlucoseMax ;			        // 0x10 ~ 0x11 // Unit base on GMunit_mg_dL           
	uint16_t GlucoseMidLow ,		        // 0x12 ~ 0x13 // Unit base on GMunit_mg_dL           
		     GlucoseMidHigh ;		        // 0x14 ~ 0x15 // Unit base on GMunit_mg_dL           
	uint8_t T[16] ,					        // 0x16 ~ 0x25 // Res -> 1 oC                         
		    Tf[16] ;				        // 0x26 ~ 0x35 // Res -> 0.01                         
	uint16_t Meas[10] ,                     // 0x36 ~ 0x49                                        
		     Target[10] ;                   // 0x4a ~ 0x5d                                        
    bool    MemoryClear ,                   // 0x5e        
    		Enable_Second_Meas ,            // 0x5f        
    		Enable_Download ;               // 0x60        
   	uint8_t Second_Meas_Count ;             // 0x61        
   	bool    Enable_ElecStrip ,              // 0x62        
   			DateMode ;				        // 0x63
	uint8_t UnitMode ;      		        // 0x64
	bool    TimeFormat ;      		        // 0x65  0 :ÃÀÒŽ AMPM , 1 = šWÒŽ 24:00
	bool    Beep ,					        // 0x66
			Hypo20 ;				        // 0x67
	uint8_t	PowerOnEntryMode ;				// 0x68  0= Setting Mode , 1= Wait Strip Insert Mode 		
	uint8_t StripID ;                       // 0x69  Rev9 
	uint16_t RecDataFileLen ;               // 0x6a  Rev10, Rev11
	uint8_t REV1[35] ;                      // 0x6c ~ 0x8e 
	uint8_t Enable_SerialWrite ;       		// 0x8f 
	struct tagSERIALNUMBER SerialNumber ;	// 0x90 ~ 0x9f
	uint8_t REV2[94] ;               		// 0xa0 ~ 0xfd 
    uint16_t CheckSum ;               		// 0xfe ~ 0xff 
};





//-- ROM Area
//-- 0x6f00 ~ 0x6f3f for system record
#define	 C_EEP_SerialNumber					0xae00
//-- 0x6f40 ~ 0x6f3f for system record
#define	 C_EEP_Significant					0xae80
//----- Code card Parameter -----


//-- 0x6f80 ~ 0x6fff for Code card Parameter
//#define	 C_EEP_ParameterTable_Adr			0xaf00

#define	 C_EEP_Chol_Type					0xaf00//×Üµ¨¹Ì´¼ code
#define	 C_EEP_Urea_Type					0xaf40//ÄòËá     code


//-- 0x7000 ~ 0x7fff for data record
//----- data Record  -----
#define	 C_EEP_glucose_autocode       		0xaf80//???2????
#define	 C_EEP_ketone_autocode       		0xB180//???2????

#define	 C_FlashDataOffset       			0xB400
#define	 membye								4096/2

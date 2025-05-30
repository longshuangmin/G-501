; Generated by holtek-gcc v3.19, Fri May 23 10:39:43 2025
; 
; Configuration:
;       with long instruction
;       Multi-ROM, Multi-RAM
;       bits_per_rom_unit:16
;       with mp1
;       with tbhp, address(0x9)
;          Use tabrd-const
;       
; SFR address of long-instruction arch:
;    mp0 = -1,1,0
;    mp1 = 4,3,2
;    mp2 = 14,13,12
;    tbp = 9,7,8
;    acc = 5
;    pcl = 6
;    status = 10
;    bp = 11
;    intc = 32
;       
;       
; use 'tabrdc' instead of 'tabrd'
;       

#pragma translator "holtek-gcc 4.6.4" "3.19" "build 20130711"
; Rebuild 718

ir equ [2]
mp equ [3]
sbp equ [4]
acc equ [5]
bp equ [11]
tblp equ [7]
tbhp equ [9]
status equ [10]
c equ [10].0
ac equ [10].1
z equ [10].2
ov equ [10].3
cz equ [10].6
sc equ [10].7
intc equ [32]
mduwr0 equ [59h]
mduwr1 equ [5ah]
mduwr2 equ [5bh]
mduwr3 equ [5ch]
mduwr4 equ [5dh]
mduwr5 equ [5eh]
mduwrctrl equ [5fh]

extern ra:byte
extern rb:byte
extern rc:byte
extern rd:byte
extern re:byte
extern rf:byte
extern rg:byte
extern rh:byte
extern _Crom2Prom:near
extern _Crom2PromNext:near

RAMBANK 0 @BITDATASEC, @BITDATASEC1
@HCCINIT	.section 'data'
@HCCINIT0	.section 'data'
@BITDATASEC	 .section 'data'
@BITDATASEC1	 .section 'data'

#pragma debug scope 1 1
	extern __DELAY3:near
	extern __DELAYX3:near
	extern __DELAYX6:near
	extern __DELAYY5:near
	extern __DELAYY3:near
	extern _builtin_holtek_delay_2:byte
public _Exampledata0
#line 241 "c:\users\longshuangmin\desktop\worke_space\g-501\g-501\flash_area.c"
crom_Exampledata0 .section at 0b400h 'crom'
_Exampledata0:
#pragma debug array 42 12 2048 1
#pragma debug variable 42 1 _Exampledata0 "Exampledata0"
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	dc -1
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
public _glucose_auto_code
#line 172 "c:\users\longshuangmin\desktop\worke_space\g-501\g-501\flash_area.c"
crom_glucose_auto_code .section at 0af80h 'crom'
_glucose_auto_code:
#pragma debug struct_begin 43 "_code_data"
#pragma debug field 0 29 "a_T"
#pragma debug field 0 29 "b_T"
#pragma debug field 0 29 "c_T"
#pragma debug field 0 29 "a_I"
#pragma debug field 0 29 "b_I"
#pragma debug field 0 29 "c_I"
#pragma debug field 0 29 "a_HCT"
#pragma debug field 0 29 "b_HCT"
#pragma debug field 0 29 "c_HCT"
#pragma debug field 0 29 "a_imp1"
#pragma debug field 0 29 "b_imp1"
#pragma debug field 0 29 "c_imp1"
#pragma debug field 0 29 "a_imp2"
#pragma debug field 0 29 "b_imp2"
#pragma debug field 0 29 "c_imp2"
#pragma debug field 0 29 "a_C"
#pragma debug field 0 29 "b_C"
#pragma debug field 0 29 "c_C"
#pragma debug struct_end
#pragma debug array 44 43 3 1
#pragma debug variable 44 1 _glucose_auto_code "glucose_auto_code"
	db 70
	db -58
	db 52
	db -70
	db 92
	db 61
	db 84
	db 63
	db -53
	db -87
	db 81
	db 64
	db 106
	db 23
	db 17
	db 58
	db -70
	db -118
	db 35
	db -67
	db -111
	db 54
	db -40
	db 63
	db -14
	db -113
	db 4
	db 62
	db 70
	db 53
	db 46
	db 62
	db 24
	db -10
	db 89
	db 61
	db 0
	db 0
	db -128
	db 79
	db 0
	db 0
	db -128
	db 79
	db 0
	db 0
	db -128
	db 79
	db 0
	db 0
	db -128
	db 79
	db 0
	db 0
	db -128
	db 79
	db 0
	db 0
	db -128
	db 79
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 110
	db 80
	db 123
	db -69
	db -31
	db -35
	db -128
	db 63
	db 39
	db -117
	db 61
	db 62
	db 40
	db -116
	db 118
	db -71
	db 49
	db -93
	db -69
	db 59
	db 116
	db -29
	db -127
	db 63
	db 44
	db -35
	db -72
	db -72
	db -7
	db -28
	db -80
	db 60
	db 112
	db 113
	db 3
	db 63
	db -11
	db -82
	db 14
	db 61
	db 3
	db 64
	db 116
	db -70
	db 105
	db 61
	db 89
	db 63
	db -23
	db -70
	db -50
	db 60
	db -60
	db -56
	db -24
	db -67
	db -122
	db -112
	db -115
	db 63
	db 87
	db 56
	db 19
	db -71
	db 60
	db 19
	db 1
	db 64
	db 22
	db -24
	db 105
	db -64
	db 0
	db 0
	db -56
	db 67
	db 0
	db 0
	db 22
	db 68
	db 0
	db 0
	db -106
	db 68
	db 0
	db 64
	db 22
	db 68
	db 0
	db 0
	db -56
	db 66
	db 0
	db 0
	db -128
	db 79
	db 0
	db 0
	db -128
	db 79
	db 0
	db 0
	db -128
	db 79
	db 0
	db 0
	db -128
	db 79
	db 0
	db 0
	db -128
	db 79
	db 0
	db 0
	db -128
	db 79
	db 0
	db 0
	db -128
	db 79
	db 0
	db 0
	db -128
	db 79
	db 0
	db 0
	db -128
	db 79
	db 0
	db 0
	db -128
	db 79
	db 0
	db 0
	db -128
	db 79
	db 0
	db 0
	db -128
	db 79
	db 0
	db 0
	db -128
	db 79
public _Significant_Table
#line 59 "c:\users\longshuangmin\desktop\worke_space\g-501\g-501\flash_area.c"
crom_Significant_Table .section at 0ae80h 'crom'
_Significant_Table:
#pragma debug array 45 12 128 1
#pragma debug variable 45 1 _Significant_Table "Significant_Table"
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
public _SerialNumber_Table
#line 22 "c:\users\longshuangmin\desktop\worke_space\g-501\g-501\flash_area.c"
crom_SerialNumber_Table .section at 0ae00h 'crom'
_SerialNumber_Table:
#pragma debug array 46 8 128 1
#pragma debug variable 46 1 _SerialNumber_Table "SerialNumber_Table"
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0
	db 0

; 
; Generated by holtek-gcc v3.19, Fri May 23 10:39:43 2025
; Rebuild 718
; end of file

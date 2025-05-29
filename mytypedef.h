//-----------------------------------------------------------------------------
// File Name: mytypedef.h
//
//-----------------------------------------------------------------------------

#ifndef _MYTYPE_DEF_H_
#define _MYTYPE_DEF_H_


// ----------------------------------------------------------------------------
// Type definition 
// ----------------------------------------------------------------------------
typedef unsigned char		uchar, UCHAR, BYTE;
typedef unsigned short 	    ushort, USHORT;
typedef unsigned int		uint, UINT, WORD;
typedef unsigned long		ulong, ULONG, DWORD;

typedef unsigned char	    BOOL;
typedef long		LONG;
typedef int			INT;
typedef void		VOID;

typedef unsigned char *		PBYTE;
typedef unsigned short *    PUSHORT;
typedef unsigned int *		PWORD;
typedef unsigned long *		PDWORD;

typedef long *		PLONG;
typedef int *		PINT;
typedef void *		PVOID;


// ----------------------------------------------------------------------------
// Boolean value definition 	
// ----------------------------------------------------------------------------
#define TRUE			((BOOL) 1)
#define FALSE			((BOOL) 0)


// ----------------------------------------------------------------------------
// Data type conversion
// ----------------------------------------------------------------------------
#define MAKEWORD(a, b)        (((WORD)b <<8)&0xff00) |a

#define LOWORD(l)           ((WORD)((ULONG)(l) & 0xffff))
#define HIWORD(l)           ((WORD)((ULONG)(l) >> 16))
#define LOBYTE(w)           ((BYTE)(w&0xff))
#define HIBYTE(w)           ((BYTE)(w >> 8))

// ----------------------------------------------------------------------------
// Mathematical formula Definition
// ----------------------------------------------------------------------------
#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif
											

#endif
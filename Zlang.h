#ifndef _ZLANG_H_
#define _ZLANG_H_

#include <iostream>
#include <sstream>
using namespace std;

//Memory related 
//TODO : fully hookable methods
//#define ZAlloc(_size) malloc(_size)
#define ZAlloc(t,sz) new t[sz];
#define ZFree(_mem) free(_mem)

#define ZBTrue true
#define ZBFalse false

//unicode stuff [Borrowd from Squirrel]
#ifdef _UNICODE
//#define ZCUNICODE
#endif

#ifdef ZCUNICODE
/*
#if (defined(_Mzc_VER) && _Mzc_VER >= 1400) // 1400 = VS8

#if defined(wchar_t) //this is if the compiler considers wchar_t as native type
#define wchar_t unsigned short
#endif

#else
typedef unsigned short wchar_t;
#endif
*/
typedef wchar_t ZChar;
#define _ZC(a) L##a
#define	zcstrcmp	wczcmp
#define zcsprintf	swprintf
#define zcstrlen	wcslen
#define zcstrtod	wcstod
#define zcstrtol	wcstol
#define zcatoi		_wtoi
#define zcstrtoul	wcstoul
#define zcvsprintf	vswprintf
#define zcstrstr	wcsstr
#define zcisspace	iswspace
#define zcisdigit	iswdigit
#define zcisxdigit	iswxdigit
#define zcisalpha	iswalpha
#define zcizcntrl	iswcntrl
#define zcisalnum	iswalnum
#define zcprintf	wprintf
#define zccat		wcscat
#define zcitoa		_itow
#define zcstrcpy	wcscpy
#define zcsstream	std::wstringstream
#define zcstring	std::wstring
#define MAX_CHAR    0xFFFF
#else
typedef char ZChar;
#define _ZC(a) a
#define	zcstrcmp	strcmp
#define zcsprintf	sprintf
#define zcstrlen	strlen
#define zcstrtod	strtod
#define zcstrtol	strtol
#define zcatoi		atoi
#define zcstrtoul	strtoul
#define zcvsprintf	vsprintf
#define zcstrstr	strstr
#define zcisspace	isspace
#define zcisdigit	isdigit
#define zcisxdigit	isxdigit
#define zcizcntrl	izcntrl
#define zcisalpha	isalpha
#define zcisalnum	isalnum
#define zcprintf	printf
#define zccat		strcat
#define zcitoa		_itoa
#define zcstrcpy	strcpy
#define zcsstream	std::stringstream
#define zcstring	std::string
#define MAX_CHAR    0xFF
#endif
#define _ZCS(a) zcstring(_ZC(a))
//
//Primitive types 
typedef int			ZIInteger; //internal integer
typedef float		ZIFloat;
typedef bool		ZIBool;
typedef zcstring    ZIString;
//

//
#endif
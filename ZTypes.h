#ifndef _ZTYPES_H_
#define _ZTYPES_H_

#include <sstream>
#include <vector>
#include "Zlang.h"
#include <boost/variant.hpp>
#include <boost/lexical_cast.hpp>

//Operations types
//
class AbOps
{
public:
	AbOps(){}
};
class NumOps : public AbOps
{
public:
	NumOps(const AbOps & other){}
	NumOps(){}
};
class SeqOps : public AbOps
{
public:
	SeqOps(const AbOps & other){}
	SeqOps(){}
};
//

// ZObject : the generic container
template <class Container,class Operations>
class ZObject : public Operations
{
public:
	Container* cont;

	template <class C1,class P1>
	ZObject ( ZObject<C1,P1> & other)
		:Operations(other)
	{cont=static_cast<Container*>(other.cont);}

	ZObject(Container cn)
	{
		cont=ZAlloc(Container,1);
		*cont=cn;
	}
	ZObject(){cont=new Container();}

};
//
class ZMemFunGenClass{};

//streamability
namespace boost
{ 
	template <class Container,class Operations>
	std::ostream& operator<<(std::ostream &stream ,const ZObject<Container,Operations> & arg)
	{
		ToString a;
		return stream << a(arg);
	}
}

enum ZETypes
{
	ZETInt,
	ZETFloat,
	ZETBool,
	ZETString
};

#include "ZTDefs.h"

// Type shorthands
typedef ZObject<ZTRoot,AbOps> gZTR;
typedef ZObject<ZTInt,NumOps> gZInt;
typedef ZObject<ZTFloat,NumOps> gZFloat;
typedef ZObject<ZTBool,NumOps> gZBool;
typedef ZObject<ZTString,SeqOps> gZString;

// our varaint 
typedef boost::variant<gZInt,gZFloat,gZBool,gZString> ZTvar;
typedef std::vector<ZTvar> ZTvarS;
typedef ZTvar* ZTvarp;

// generic member function pointer
typedef ZTvar (ZMemFunGenClass::*ZTmfp)(ZTvarS);

#include "ZTRoot.h"
#include "ZTBool.h"
#include "ZTInt.h"
#include "ZTFloat.h"
#include "ZTString.h"

#include "ZTHelpers.h"
#include "ZErrors.h"
#include "ZTTraits.h"
#include "ZTOperations.h"
#include "ZTBridge.h"

#endif
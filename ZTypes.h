#ifndef _ZTYPES_H_
#define _ZTYPES_H_

#include <sstream>
#include <vector>
#include "Zlang.h"
#include <boost/variant.hpp>
#include <boost/bind.hpp>
#include <boost/lexical_cast.hpp>

//Operations types
//
class AbOps
{
public:
	AbOps(){}
};
//Numerical operations (numeric types , e.g. ints/floats/etc..)
class NumOps : public AbOps
{
public:
	NumOps(const AbOps & other){}
	NumOps(){}
};
//sequence operations (sequencable types , e.g. strings/arrays/etc..)
class SeqOps : public AbOps
{
public:
	SeqOps(const AbOps & other){}
	SeqOps(){}
};
//call operations (callable types , e.g. functions )
class CallOps : public AbOps
{
public:
	CallOps(const AbOps & other){}
	CallOps(){}
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
		return stream << a(arg);
	}
}

enum ZETypes
{
	ZETInt,
	ZETFloat,
	ZETBool,
	ZETString,
	ZETFunction,
	ZETList,
	ZETObject,
	ZETInstance,
	ZETMemDataItem
};



#include "ZTDefs.h"


// Type shorthands
typedef ZObject<ZTRoot,AbOps> gZTR;
typedef ZObject<ZTInt,NumOps> gZInt;
typedef ZObject<ZTFloat,NumOps> gZFloat;
typedef ZObject<ZTBool,NumOps> gZBool;
typedef ZObject<ZTString,SeqOps> gZString;
typedef ZObject<ZTFunction,CallOps> gZFunction;
typedef ZObject<ZTList,SeqOps> gZList;
typedef ZObject<ZObjP,CallOps> gZObject;
typedef ZObject<ZTOInstance,CallOps> gZOInstance;
typedef ZObject<ZTMemData,CallOps> gZMemData;

// our varaint 
typedef boost::variant<gZInt,gZFloat,gZBool,gZString,gZFunction,gZList,gZObject,gZOInstance,gZMemData> ZTvar;
typedef ZTvar* ZTvarp;
typedef std::vector<ZTvarp> ZTvarS;

// generic member function pointer
typedef ZTvarp (ZMemFunGenClass::*ZTmfp)(ZTvarS);
typedef ZTvarp (*ZTfp)(ZTvarS);

//basic info regarding built-in modules
struct ZBuiltinModule
{
	ZChar* ZModName;
	void (*ZModInitFunc)(void);
};

#include "ZTRoot.h"
#include "ZTBool.h"
#include "ZTInt.h"
#include "ZTFloat.h"
#include "ZTString.h"
#include "ZTFunction.h"
#include "ZTList.h"
#include "ZTObject.h"
#include "ZTMemData.h"

#include "ZTHelpers.h"
#include "ZErrors.h"
#include "ZTTraits.h"
#include "ZTOperations.h"
#include "ZTBridge.h"

#endif
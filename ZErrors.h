#ifndef _ZERRORS_H_
#define _ZERRORS_H_

#include <typeinfo>

class SystemException
{
public:
	ZTvar obj;
	zcstring  Messege;
	SystemException(ZTvar& cobj):obj(cobj)
	{
		Messege.append(_ZC("System Exception"));
	}
	ZChar* Speak()
	{
		gZTR eobj=boost::apply_visitor(getZTR(),obj);
		Messege.append(_ZC(" in Object of type "));
		Messege.append( eobj.cont->Oname() );
		Messege.append(_ZC(" whose value is "));
		Messege.append( boost::apply_visitor(ToString(),obj));
		Messege.append(_ZC("\r\n"));
		return (const_cast<ZChar*>(Messege.c_str()));
	} 
};

class ArithmeticException : public SystemException
{
public:
	ArithmeticException(ZTvar& cobj):SystemException(cobj)
	{
		Messege.append(_ZC("\r\nArithmetic Exception"));
	}
};

class DivisionByZeroException : public ArithmeticException
{
public:
	DivisionByZeroException(ZTvar& cobj):ArithmeticException(cobj)
	{
		Messege.append(_ZC("\r\nDivision By Zero Exception"));
	}
};

#endif
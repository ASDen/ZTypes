#define BASE_CASE \
	template<class S,class S1,class V,class V1,template <typename,typename> class T>\
	ZTvar operator()(T<S,S1> &a1,T<V,V1> &a2) const\
	{\
	ZError::Throw<ZOperationNotSupported>();\
	return a1;\
	}

#define BASE_CASE_1 \
	template<class S,class S1,template <typename,typename> class T>\
	ZTvar operator()(T<S,S1> &a) const\
	{\
	ZError::Throw<ZOperationNotSupported>();\
	return a;\
	}

#define Z_INIT_OP(c1,p1,c2,p2) \
	typedef OperationTrait<p1,p2>::OpT OperationT; \
	T<ResulT,OperationT> res=T<ResulT,OperationT>(); \
	ResulT *ires=ZAlloc(ResulT,1);\
	res.cont=ires;

class GzT : public boost::static_visitor<ZTvar>
{
public:
	template<template <typename,typename> class T>
	ZTvar operator()(T<ZTString,SeqOps> &a) const
	{
		return gZInt(a.cont->Len());
	}

	BASE_CASE_1
};

/*
TODO
1) Handel all sequences in genereic way
2) when adding to string , all types are converted to Eqv toString()
*/

class Sum : public boost::static_visitor<ZTvar>
{
public:

	template<class S,class V,template <typename,typename> class T>
	ZTvar operator()(T<S,NumOps> &a1,T<V,NumOps> &a2) const
	{
		typedef SumResultTrait<S,V>::RsT ResulT;
		Z_INIT_OP(S,NumOps,V,NumOps)
		ires->val=a1.cont->val+a2.cont->val;
		return res;
	}

	template< template <typename,typename> class T>
	ZTvar operator()(T<ZTMatrix,SeqOps> &a1,T<ZTMatrix,SeqOps> &a2) const
	{
		typedef SumResultTrait<ZTMatrix,ZTMatrix>::RsT ResulT;
		Z_INIT_OP(S,SeqOps,V,SeqOps)
		ires->val=a1.cont->val + a2.cont->val;
		return res;
	}

	
	template<class S,class V,template <typename,typename> class T>
	ZTvar operator()(T<S,CallOps> &a1,T<V,CallOps> &a2) const
	{
		ZError::Throw<ZOperationNotSupported>();
		return a1;
	}

	BASE_CASE
};

class Subtract : public boost::static_visitor<ZTvar>
{
public:

	template<class S,class V,template <typename,typename> class T>
	ZTvar operator()(T<S,NumOps> &a1,T<V,NumOps> &a2) const
	{
		typedef SubtractResultTrait<S,V>::RsT ResulT;
		Z_INIT_OP(S,NumOps,V,NumOps)
			ires->val=a1.cont->val-a2.cont->val;
		return res;
	}

	template< template <typename,typename> class T>
	ZTvar operator()(T<ZTMatrix,SeqOps> &a1,T<ZTMatrix,SeqOps> &a2) const
	{
		typedef SubtractResultTrait<ZTMatrix,ZTMatrix>::RsT ResulT;
		Z_INIT_OP(S,SeqOps,V,SeqOps)
		ires->val=a1.cont->val - a2.cont->val;
		return res;
	}

	BASE_CASE
};

class Multiply : public boost::static_visitor<ZTvar>
{
public:

	template<class S,class V,template <typename,typename> class T>
	ZTvar operator()(T<S,NumOps> &a1,T<V,NumOps> &a2) const
	{
		typedef MultiplyResultTrait<S,V>::RsT ResulT;
		Z_INIT_OP(S,NumOps,V,NumOps);
		ires->val=a1.cont->val*a2.cont->val;
		return res;
	}

	template< template <typename,typename> class T>
	ZTvar operator()(T<ZTMatrix,SeqOps> &a1,T<ZTMatrix,SeqOps> &a2) const
	{
		typedef MultiplyResultTrait<ZTMatrix,ZTMatrix>::RsT ResulT;
		Z_INIT_OP(S,SeqOps,V,SeqOps);
		ires->val=a1.cont->val*a2.cont->val;
		return res;
	}


	BASE_CASE
};

class Divide : public boost::static_visitor<ZTvar>
{
public:

	template<class S,class V,template <typename,typename> class T>
	ZTvar operator()(T<S,NumOps> &a1,T<V,NumOps> &a2) const
	{
		ZTvar t=a1;
		if(a2.cont->val==0)
			ZError::Throw<ZDivisionByZeroException>();
		typedef DivideResultTrait<S,V>::RsT ResulT;
		Z_INIT_OP(S,NumOps,V,NumOps);
#pragma warning( disable : 4244)
		ires->val=a1.cont->val;
		ires->val/=a2.cont->val;
		return res;
	}

	template<class S,template <typename,typename> class T>
	ZTvar operator()(T<ZTMatrix,SeqOps> &a1,T<ZTMatrix,SeqOps> &a2) const
	{
		typedef MultiplyResultTrait<ZTMatrix,ZTMatrix>::RsT ResulT;
		Z_INIT_OP(S,SeqOps,V,SeqOps);
		ires->val=a1.cont->val/a2.cont->val;
		return res;
	}
	BASE_CASE
};

class Modulus : public boost::static_visitor<ZTvar>
{
public:

	template<class S,class V,template <typename,typename> class T>
	ZTvar operator()(T<S,NumOps> &a1,T<V,NumOps> &a2) const
	{
		typedef ModulusResultTrait<S,V>::RsT ResulT;
		Z_INIT_OP(S,NumOps,V,NumOps);
		ires->val=fmod((ZIFloat)a1.cont->val,(ZIFloat)a2.cont->val);
		return res;
	}

	BASE_CASE
};

namespace Boolean
{
	class And: public boost::static_visitor<ZTvar>
	{
	public:

		template<class S,class V,template <typename,typename> class T>
		ZTvar operator()(T<S,NumOps> &a1,T<V,NumOps> &a2) const
		{
			typedef ZTBool ResulT;
			Z_INIT_OP(S,NumOps,V,NumOps);
			ires->val=a1.cont->val && a2.cont->val;
			return res;
		}

		BASE_CASE
	};

	class Or: public boost::static_visitor<ZTvar>
	{
	public:

		template<class S,class V,template <typename,typename> class T>
		ZTvar operator()(T<S,NumOps> &a1,T<V,NumOps> &a2) const
		{
			typedef ZTBool ResulT;
			Z_INIT_OP(S,NumOps,V,NumOps);
			ires->val=a1.cont->val || a2.cont->val;
			return res;
		}

		BASE_CASE
	};

	class Equal: public boost::static_visitor<ZTvar>
	{
	public:

		template<class S,class V,template <typename,typename> class T>
		ZTvar operator()(T<S,NumOps> &a1,T<V,NumOps> &a2) const
		{
			return ZTBool(a1.cont->val == a2.cont->val);
		}
		BASE_CASE
	};

	class Less: public boost::static_visitor<ZTvar>
	{
	public:

		template<class S,class V,template <typename,typename> class T>
		ZTvar operator()(T<S,NumOps> &a1,T<V,NumOps> &a2) const
		{
			return ZTBool(a1.cont->val < a2.cont->val);
		}
		BASE_CASE
	};

	
	class Great: public boost::static_visitor<ZTvar>
	{
	public:

		template<class S,class V,template <typename,typename> class T>
		ZTvar operator()(T<S,NumOps> &a1,T<V,NumOps> &a2) const
		{
			return ZTBool(a1.cont->val > a2.cont->val);
		}
		BASE_CASE
	};
};

namespace TypeConversion
{
	template<class T,class S>
	inline
	typename T::IType Convert(ZTvar val)
	{
		return gConvert<T,S>(val).cont->val;
	}

	template<class T,class S>
	inline
	ZObject<T,S> gConvert(ZTvar val)
	{
		try{
			return boost::get< ZObject<T,S> >(val);
		}
		catch (boost::bad_get& e) {
			ZError::Throw<ZBadConversionError>();
			//adsads
		}
	}
	
	inline
	bool checkType(ZETypes t1,ZETypes t2)
	{
		return t1 == t2 ;
	}

	inline 
	ZETypes getType(ZTvar z)
	{
		return ZETypes( z.which() ) ;
	}
};
#define GET_ZTYPE(x)	  TypeConversion::getType(x)
#define CHK_ZTYPE(x,y)	  TypeConversion::checkType(GET_ZTYPE(x),y)

#define INT_ZCONV(x)      (int)TypeConversion::Convert<ZTFloat,NumOps>(x)
#define FLOAT_ZCONV(x)    TypeConversion::Convert<ZTFloat,NumOps>(x) 
#define BOOL_ZCONV(x)     TypeConversion::Convert<ZTBool,NumOps>(x)
#define STRING_ZCONV(x)   TypeConversion::Convert<ZTString,SeqOps>(x)
#define FUNCTION_ZCONV(x) TypeConversion::Convert<ZTFunction,CallOps>(x)
#define LIST_ZCONV(x)     TypeConversion::Convert<ZTList,SeqOps>(x)
#define MATRIX_ZCONV(x)   TypeConversion::Convert<ZTMatrix,SeqOps>(x)
#define OBJECT_ZCONV(x)   TypeConversion::Convert<ZObjP,CallOps>(x)
#define INSTANCE_ZCONV(x) TypeConversion::Convert<ZTOInstance,CallOps>(x)
#define MEMDATA_ZCONV(x)  TypeConversion::Convert<ZTMemData,CallOps>(x)

#define gINT_ZCONV(x)      (int)TypeConversion::gConvert<ZTFloat,NumOps>(x)
#define gFLOAT_ZCONV(x)    TypeConversion::gConvert<ZTFloat,NumOps>(x) 
#define gBOOL_ZCONV(x)     TypeConversion::gConvert<ZTBool,NumOps>(x)
#define gSTRING_ZCONV(x)   TypeConversion::gConvert<ZTString,SeqOps>(x)
#define gFUNCTION_ZCONV(x) TypeConversion::gConvert<ZTFunction,CallOps>(x)
#define gLIST_ZCONV(x)     TypeConversion::gConvert<ZTList,SeqOps>(x)
#define gOBJECT_ZCONV(x)   TypeConversion::gConvert<ZObjP,CallOps>(x)
#define gINSTANCE_ZCONV(x) TypeConversion::gConvert<ZTOInstance,CallOps>(x)
#define gMEMDATA_ZCONV(x)  TypeConversion::gConvert<ZTMemData,CallOps>(x)
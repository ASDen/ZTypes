#define BASE_CASE \
	template<class S,class S1,class V,class V1,template <typename,typename> class T>\
	ZTvar operator()(T<S,S1> &a1,T<V,V1> &a2) const\
	{\
		return a1;\
	}

#define BASE_CASE_1 \
	template<class S,class S1,template <typename,typename> class T>\
	ZTvar operator()(T<S,S1> &a) const\
	{\
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

class Sum : public boost::static_visitor<ZTvar>
{
public:

	template<class S,class V,class W,template <typename,typename> class T>
	ZTvar operator()(T<S,W> &a1,T<V,W> &a2) const
	{
		typedef SumResultTrait<S,V>::RsT ResulT;
		Z_INIT_OP(S,W,V,W)
		ires->val=a1.cont->val+a2.cont->val;
		return res;
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
			throw DivisionByZeroException(t);
		typedef DivideResultTrait<S,V>::RsT ResulT;
		Z_INIT_OP(S,NumOps,V,NumOps);
		ires->val=a1.cont->val;
		ires->val/=a2.cont->val;
		return res;
	}

	BASE_CASE
};

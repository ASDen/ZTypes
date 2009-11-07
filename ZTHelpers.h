class getZTR : public boost::static_visitor<gZTR>
{
public:
	template<class S,class S1,template <typename,typename> class T>
	gZTR operator()(T<S,S1> &a) const
	{
		return static_cast<gZTR>(a);
	}
};

class ToString : public boost::static_visitor<ZChar*>
{
public:
	template<class S,class S1,template <typename,typename> class T>
	ZChar* operator()(T<S,S1> &a) const
	{
		zcsstream oss;
		oss << a.cont->val;
		ZChar* zt=ZAlloc(ZChar,oss.str().length());
		zcstrcpy(zt,oss.str().c_str());
		return zt;
	}

	template< template <typename,typename> class T >
	ZChar* operator()(T<ZTString,SeqOps> &a) const
	{
		return const_cast<ZChar*>(a.cont->val.c_str());
	}
};

class Setter : public boost::static_visitor<void>
{
public:
	template<class S,class S1,template <typename,typename> class T>
	void operator()(T<S,S1> &a,S &cont) const
	{
		a.cont=&cont;
	}

	template<class V,class S,class S1,template <typename,typename> class T>
	void operator()(T<S,S1> &a,V &cont) const
	{}
};
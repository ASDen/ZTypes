class getZTR : public boost::static_visitor<gZTR>
{
public:
	template<class S,class S1,template <typename,typename> class T>
	gZTR operator()(T<S,S1> &a) const
	{
		return static_cast<gZTR>(a);
	}
};

class getType : public boost::static_visitor<ZETypes>
{
public:
	template<class S,class S1,template <typename,typename> class T>
	ZETypes operator()(T<S,S1> &a) const
	{
		return a.cont->myType;
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

	template< template <typename,typename> class T >
	ZChar* operator()(T<ZTList,SeqOps> &a) const
	{
		ZIString zs;
		zs.append(_ZC("["));
		ZTvarS::iterator i;
		if(a.cont->val.size()>0)
		{
			for ( i = a.cont->val.begin(); i != a.cont->val.end()-1 ; i++ )
			{
				zs.append(boost::apply_visitor(ToString(),**i));
				zs.append(_ZC(","));
			}
			zs.append(boost::apply_visitor(ToString(),**i));
		}
		zs.append(_ZC("]"));

		ZChar* zt=ZAlloc(ZChar,zs.length());
		zcstrcpy(zt,zs.c_str());
		return zt;
	}

	template< template <typename,typename> class T >
	ZChar* operator()(T<ZTBool,NumOps> &a) const
	{
		if(a.cont->val==true)
			return _ZC("True");
		return _ZC("False");
	}
};

class BoolVal : public boost::static_visitor<ZIBool>
{
public:
	template<class S,class S1,template <typename,typename> class T>
	ZIBool operator()(T<S,S1> &a) const
	{
		return a.cont->BoolVal();
	}

	template< template <typename,typename> class T >
	ZIBool operator()(T<ZTString,SeqOps> &a) const
	{
		return (a.cont->val.length()==0)?ZBFalse:ZBTrue;
	}

	template<class S, template <typename,typename> class T >
	ZIBool operator()(T<S,NumOps> &a) const
	{
		return (a.cont->val==0)?ZBFalse:ZBTrue;
	}	

	template< template <typename,typename> class T >
	ZIBool operator()(T<ZTBool,NumOps> &a) const
	{
		return a.cont->val;
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
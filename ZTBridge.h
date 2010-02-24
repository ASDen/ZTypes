class ZTCallBridge : public boost::static_visitor<ZTvarp>
{
public:

	ZTmfp zmfp;
	ZTvarS InpArg;
	typedef ZTvarp (ZObjP::*ztioiFun)(ZTvarS);

	ZTCallBridge (ZTmfp mfp ,ZTvarS ip):zmfp(mfp),InpArg(ip)
	{}

	//template<class V,template <typename,typename> class T>
	ZTvarp operator()(ZObject<ZTOInstance,CallOps> &a) const
	{
		ztioiFun v=reinterpret_cast<ztioiFun>(zmfp);
		return  (a.cont->val->*v)(InpArg);
	}

	template<class S,class S1,template <typename,typename> class T>
	ZTvarp operator()(T<S,S1> &a) const
	{
		//Fire Exception
		return NULL;
	}

};

class ZTDataBridge : public boost::static_visitor<ZTvarp>
{
public:

	ZMemD ztm;
	typedef ZTvar ZObjP::*ztdata;

	ZTDataBridge (ZMemD m ):ztm(m)
	{}

	//template<class V,template <typename,typename> class T>
	ZTvarp operator()(ZObject<ZTOInstance,CallOps> &a) const
	{
		ztdata v=reinterpret_cast<ztdata>(ztm);
		return  &(a.cont->val->*v) ;
	}

	template<class S,class S1,template <typename,typename> class T>
	ZTvarp operator()(T<S,S1> &a) const
	{
		//Fire Exception
		return NULL;
	}

};
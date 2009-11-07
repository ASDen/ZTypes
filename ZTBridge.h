class ZTCallBridge : public boost::static_visitor<ZTvar>
{
public:

	ZTmfp zmfp;
	ZTvarS InpArg;

	ZTCallBridge (ZTmfp mfp ,ZTvarS ip):zmfp(mfp),InpArg(ip)
	{}

	template<class S,class V,template <typename,typename> class T>
	ZTvar operator()(T<S,V> &a) const
	{
		typedef ZTvar (S::*zz)(ZTvarS);
	    zz v=reinterpret_cast<zz>(zmfp);
		return  (a.cont->*v)(InpArg);
	}

	ZTvar operator()(boost::blank &a) const
	{
		return ZTvar();
	}
};
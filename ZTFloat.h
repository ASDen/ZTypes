class ZTFloat : public ZTRoot
{
public:
	ZIFloat val;

	ZTFloat(ZIFloat in)
	{
		myType=ZETFloat;
		val=in;
	}
	
	ZTFloat()
	{
		ZTFloat(0.0f);
	}
	
	ZTFloat(const ZTRoot & other) : ZTRoot(other)
	{
		ZTFloat();
	}
	
	ZChar* Oname()
	{
		return _ZC("Float");
	}

	ZTvar Square(ZTvarS inp)
	{
		return ZTFloat(val * boost::get<gZFloat>(inp[0]).cont->val);
	}

};
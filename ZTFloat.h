class ZTFloat : public ZTRoot
{
public:
	typedef ZIFloat IType;

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

	/*ZTvar Square(ZTvarS inp)
	{
		return ZTFloat(val * FLOAT_ZCONV(*(inp[0])));
	}*/

};
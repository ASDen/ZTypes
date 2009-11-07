class ZTString : public ZTRoot
{
public:
	ZIString val;

	ZTString(ZIString in)
	{
		myType=ZETString;
		val=in;
	}
	
	ZTString()
	{
		ZTString(_ZC(""));
	}
	
	ZTString(const ZTRoot & other) : ZTRoot(other)
	{
		ZTString();
	}

	ZChar* Oname()
	{
		return _ZC("String");
	}

	ZTvar Len(ZTvarS inp)
	{
		return ZTInt(val.length());
	}

};
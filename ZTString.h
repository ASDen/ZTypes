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

	const ZTString operator+(const ZTString &other) const
	{
		return (*this).val+other.val;
	}

	void RemQuotes()
	{
		val.erase(0,1);
		val.erase(val.size()-1,1);
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
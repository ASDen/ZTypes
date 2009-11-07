class ZTDefault : public ZTRoot
{
public:
	ZIInteger val;
	
	ZTDefault(ZIInteger in)
	{
		myType=ZETInt;
		val=in;
	}

	ZTDefault()
	{
		ZTDefault(0);
	}
	
	ZTDefault(const ZTRoot & other) :ZTRoot(other)
	{
		ZTDefault();
	}

	ZChar* Oname()
	{
		return _ZC("Integer");
	}



};
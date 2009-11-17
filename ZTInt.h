class ZTInt : public ZTRoot
{
public:
	ZIInteger val;
	
	ZTInt(ZIInteger in)
	{
		myType=ZETInt;
		val=in;
	}

	ZTInt()
	{
		ZTInt(0);
	}
	
	ZTInt(const ZTRoot & other) :ZTRoot(other)
	{
		ZTInt();
	}

	ZChar* Oname()
	{
		return _ZC("Integer");
	}

};
class ZTBool : public ZTRoot
{
public:
	ZIBool val;
	
	ZTBool(ZIBool in)
	{
		myType=ZETBool;
		val=in;
	}

	ZTBool()
	{
		ZTBool(false);
	}
	
	ZTBool(const ZTRoot & other) :ZTRoot(other)
	{
		ZTBool();
	}

	ZChar* Oname()
	{
		return _ZC("Boolean");
	}

};
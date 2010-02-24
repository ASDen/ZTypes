typedef ZTvar ZMemFunGenClass::*ZMemD;

class ZTMemData : public ZTRoot
{
public:
	ZMemD val;

	ZTMemData(ZMemD in)
	{
		myType=ZETMemDataItem;
		val=in;
	}
	
	ZTMemData()
	{
		//ZTFloat(0.0f);
	}
	
	ZTMemData(const ZTRoot & other) : ZTRoot(other)
	{
		ZTMemData();
	}
	
	ZChar* Oname()
	{
		return _ZC("Class Member Item");
	}

};
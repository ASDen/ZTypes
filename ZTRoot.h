class ZTRoot
{
public:
	ZETypes myType;

	ZTRoot (const ZTRoot & other)
		: myType(other.myType)
	{}

	ZTRoot(){}

	virtual ZChar* Oname()
	{
		return _ZC("Generic Object");
	}

	virtual ZIBool BoolVal()
	{
		return ZBFalse;
	}
};
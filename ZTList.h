class ZTList : public ZTRoot
{
public:
	ZTvarS val;

	ZTList(ZTvarS in)
	{
		myType=ZETList;
		val=in;
	}
	
	ZTList()
	{
		val.clear();
	}
	
	ZTList(const ZTRoot & other) : ZTRoot(other)
	{
		ZTList();
	}
	
	ZChar* Oname()
	{
		return _ZC("List");
	}

	void Append(ZTvarp var)
	{
		val.push_back(var);
	}

	ZTvarp Get(int Index)
	{
		return val[Index];
	}

};
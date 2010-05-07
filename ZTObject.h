typedef ZSymbolTable<ZTvar> ZTvTable;

class ZObjP : public ZTRoot
{
public:
	typedef ZObjP* IType;

	ZObjP* val;
	ZTvTable DyProps;

	ZObjP()
	{
		myType=ZETObject;
		val=this;
	}

	ZTvTable getDyn()
	{
		return DyProps;
	}

	template<class T>
	void AddDataMember(ZChar* dName,ZTvar T::*mdi )
	{
		ZTvarp zv=ZAlloc(ZTvar,1);
		*zv=ZTMemData( reinterpret_cast<ZMemD>(mdi) );
		DyProps.InsertSymbol( dName , zv );
	}

	virtual void cpy(ZObjP*& A,ZTvarS args)
	{
		std::cout<<"Parent cpy"<<std::endl;
		*(reinterpret_cast<ZObjP*>(A))=*this;
	}
};

template <class T>
class ZTBaseObject : public ZObjP
{
public:

	static ZTvTable StProps;	

	ZTBaseObject()
	{
		DyProps = StProps;
	}

	static void Inheriet(ZTvTable child)
	{
		StProps.InitScope(child);
	}

	template<class T>
	static void AddFunction(ZChar* mfpName,int mfpNumArgs, ZTvarp (T::*mfp)(ZTvarS) )
	{
		ZIFunction* zf=ZAlloc(ZIFunction,1);
		ZTvarp zv=ZAlloc(ZTvar,1);
		ZTmfp v=reinterpret_cast<ZTmfp>(mfp);

		zf->pMFunInit(mfpNumArgs,v);
		*zv=ZTFunction(zf);
		StProps.InsertSymbol(_ZC(mfpName),zv);
	}

	void cpy(ZObjP*& A,ZTvarS args)
	{
		A=new T(args);
		*A=*this;
		/**(reinterpret_cast<T*>(A))=
			*(reinterpret_cast<T*>(this));*/
	}

};

template <class T> ZTvTable ZTBaseObject<T>::StProps;

class ZTObject;
typedef ZTBaseObject<ZTObject> ZTObjBase;

class ZTObject : public ZTObjBase
{
public:
	
	/*ZBaseObject(ZIInteger in)
	{
		myType=ZETInt;
		val=in;
	}*/
	ZTObject(ZTvarS inp)
	{
	}

	ZTObject()
	{
	}
	
	ZTObject(const ZTObjBase & other) : ZTObjBase(other)
	{
		ZTObject();
	}

	static void Init()
	{
		StProps.InitScope();
		AddFunction(_ZC("toString"),0,&ZTObject::toString);
	}

	ZTvarp toString(ZTvarS inp)
	{
		ZTvarp res=ZAlloc(ZTvar,1);
		*res=ZTString(ZIString(_ZC("Base Object")));
		return res;
	}

	ZChar* Oname()
	{
		return _ZC("Object");
	}
};

typedef ZObjP* pZObjP;

class ZTOInstance : public ZTRoot
{
public:

	pZObjP val;

	ZTOInstance(pZObjP in)
	{
		myType=ZETInstance;
		val=in;
	}

	ZTOInstance()
	{
		myType=ZETInstance;
		//ZTOInstance(NULL);
	}
	
	ZTOInstance(const ZTRoot & other) :ZTRoot(other)
	{
		ZTOInstance();
	}

	ZChar* Oname()
	{
		return _ZC("Object");
	}
};
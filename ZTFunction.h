enum ZFunTypes
{
	ZExternal,
	ZMExternal,
	ZInternal,
	ZMInternal
};

//generic ZFunction , either internal or external
struct ZIFunction
{
	ZFunTypes FunT;
	int NumArgs;
	ZTvarp obj;

	union {
		int NodeID;
		ZTmfp pMFun;
		ZTfp  pFun;
	}FunData;

	void pFunInit(int narg,ZTfp fp)
	{FunT=ZExternal;NumArgs=narg;FunData.pFun=fp;}

	void pMFunInit(int narg,ZTmfp fp)
	{FunT=ZMExternal;NumArgs=narg;FunData.pMFun=fp;}

	void NodeInit(int narg,int nid)
	{FunT=ZInternal;NumArgs=narg;FunData.NodeID=nid;}

};

typedef ZIFunction* pZIFunction;

class ZTFunction : public ZTRoot
{
public:
	pZIFunction val;
	
	ZTFunction(pZIFunction in)
	{
		myType=ZETFunction;
		val=in;
	}

	ZTFunction()
	{
		val=ZAlloc(ZIFunction,1);
	}
	
	ZTFunction(const ZTRoot & other) :ZTRoot(other)
	{
		ZTFunction();
	}

	ZChar* Oname()
	{
		return _ZC("Function");
	}

};
///////////
// Traits
//----------
//////////////////////////
// Result Promotion traits
/////////////////////////
template<class T1,class T2>
class ResultTrait {};

template<class T>
class ResultTrait<T,T>
{
public:
	typedef T RsT;
};

template<>
class ResultTrait<ZTFloat,ZTInt>
{
public:
	typedef ZTFloat RsT;
};

template<>
class ResultTrait<ZTInt,ZTFloat>
{
public:
	typedef ZTFloat RsT;
};

template<>
class ResultTrait<ZTBool,ZTBool>
{
public:
	typedef ZTInt RsT;
};

template<class T>
class ResultTrait<ZTBool,T>
{
public:
	typedef T RsT;
};

template<class T>
class ResultTrait<T,ZTBool>
{
public:
	typedef T RsT;
};

template<class T1,class T2>
class SumResultTrait	  : public ResultTrait<T1,T2> 
{};

template<class T1,class T2>
class SubtractResultTrait : public ResultTrait<T1,T2> 
{};

template<class T1,class T2>
class MultiplyResultTrait : public ResultTrait<T1,T2> 
{};

template<class T1,class T2>
class ModulusResultTrait   : public ResultTrait<T1,T2>
{
public:
	typedef ZTInt RsT;
};

template<class T1,class T2>
class DivideResultTrait   : public ResultTrait<T1,T2>
{};


template<>
class DivideResultTrait<ZTInt,ZTInt>
{
public:
	typedef ZTFloat RsT;
};

//////////////
//Operations traits
//////////////
template<class T1,class T2>
class OperationTrait {};

template<class T>
class OperationTrait<T,T>
{
public:
	typedef T OpT;
};

template<>
class OperationTrait<NumOps,SeqOps>
{
public:
	typedef SeqOps OpT;
};

template<>
class OperationTrait<SeqOps,NumOps>
{
public:
	typedef SeqOps OpT;
};

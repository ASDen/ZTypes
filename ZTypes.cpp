// ZTypes.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "../ZSymbolTable/ZSymbolTable.h"
#include "ZTypes.h"

//class ASD : public ZTBaseObject<ASD> 
//{
//public:
//
//	ZTvar a;
//	
//	static void Init()
//	{
//		StProps.InitScope();
//		AddFunction(_ZC("xtoString"),0,&ASD::toString);
//
//		ZTObject::Inheriet(StProps);
//	}
//
//	ASD()
//	{
//		AddDataMember(_ZC("ival") , &ASD::a);
//	}
//
//	ZTvarp toString(ZTvarS inp)
//	{
//		ZTvarp res=ZAlloc(ZTvar,1);
//		*res=ZTString(ZIString(_ZC("ASD Object")));
//		std::cout<<"a = "<<boost::apply_visitor(ToString(),a)<<std::endl;
//		return res;
//	}
//
//	//void cpy(ZObjP*& A)
//	//{
//	//	A=new ASD();
//	//	*A=*this;
//	//	//std::cout<<"ASD cpy"<<std::endl;
//	//	//ASD* c=new ASD();
//	//	//*c=*this;
//	//	//*(dynamic_cast<ASD*>(A))=*c;
//	//	//*(reinterpret_cast<ASD*>(A))=*this;
//	//}
//};

class Dgg : public ZTObject {};

//ZSymbolTable<ZTvar> ASD::StProps;

int main(int argc, char* argv[])
{
	ZTvar zv1=ZTInt(5);
	ZTvar zv2=ZTFloat(3.25);
	ZTvar t;

	ZIFloat fpy = FLOAT_ZCONV(zv2);
	std::cout<<fpy<<std::endl;
	//std::wcout<<boost::apply_visitor(ToString(),t)<<std::endl;
	//(boost::get<gZFloat>(zv1)).cont=new ZTFloat(32.456f);
	
	//boost::apply_visitor(Setter(),zv1,z1=ZTFloat(3.456f));
	//boost::apply_visitor(Setter(),zv2,z2=ZTInt(4));

	//std::wcout<<boost::apply_visitor(ToString(),zv1);
	//std::cout<<zv1<<"  "<<zv2<<"  "<<boost::apply_visitor(Sum(),zv1,zv2)<<std::endl;
	/*try
	{
		std::cout<<zv1<<"  "<<zv2<<"  "<<boost::apply_visitor(Divide(),zv1,zv2)<<std::endl;
	}
	catch(DivisionByZeroException ss)
	{
		std::wcout<<ss.Speak();
	}*/


	ZTvar a1,a2,a3,a4,z4,z5;
	ZTmfp v;
	ZTvarS i;
	

	a1=ZTString(_ZC("AxSxD"));
	a2=ZTString(_ZC("Qwe"));
	a3=boost::apply_visitor(Sum(),a1,a2);
	a3=boost::apply_visitor(Sum(),a3,a3);
	

	ZTList zl;zl.Append(&a1);zl.Append(&a2);zl.Append(&a3);
	a4=zl;
	a4=boost::apply_visitor(Sum(),a4,a4);
	
	std::wcout<<boost::apply_visitor(ToString(),a3)<<std::endl;
	std::wcout<<boost::apply_visitor(ToString(),a4)<<std::endl;

	
	v=reinterpret_cast<ZTmfp>(&ZTString::Len);
	ZIFunction fv;fv.pMFunInit(0,v);
	a4=ZTFunction(&fv);
	
	
	//z4=boost::apply_visitor(ZTCallBridge((boost::get<gZFunction>(a4)).cont->val->FunData.pMFun,i),a3);
	//std::wcout<<boost::apply_visitor(ToString(),z4)<<std::endl;

	ZTvarp in=ZAlloc(ZTvar,1);
	in[0]=ZTFloat(2.5);
	//v=reinterpret_cast<ZTmfp>(&ZTFloat::Square);
	i.push_back(in);
	//z5=boost::apply_visitor(ZTCallBridge(v,i),zv2);

	//std::wcout<<boost::apply_visitor(ToString(),z5)<<std::endl;
 
	ZTvar x1,x2,x3;
	x1=ZTBool(true);
	x2=ZTBool(true);
	x3=boost::apply_visitor(Boolean::And(),x1,x2);
	std::wcout<<boost::apply_visitor(ToString(),x3)<<std::endl;



	/*gZString cc=gZString(ZTString((_ZC("ASD"))));
	ZTString bb=ZTString(_ZC("QWE"));
	std::wcout<<cc.cont->val.c_str()<<std::endl;
	std::wcout<<bb.val.c_str()<<std::endl;*/
	
	//ZTObject::Init();
	//ASD::Init();
	//ZTOInstance zin0,zin1;
	//zin0.val=ZAlloc(ASD,1);zin1.val=ZAlloc(ASD,1);
	//ZTvar zo=zin0;
	//ZTvar zk=zin1;
	//ZTvarp vx,vy;
	//i.clear();
	//
	//vx=zin0.val->getDyn().getSymbol("xtoString",true);
	//vy=zin0.val->getDyn().getSymbol("ival",true);
	//*(boost::apply_visitor(ZTDataBridge((boost::get<gZMemData>(*vy)).cont->val),zo))=ZTInt(304);
	//z4=*(boost::apply_visitor(ZTCallBridge((boost::get<gZFunction>(*vx)).cont->val->FunData.pMFun,i),zo));

	//vx=zin1.val->getDyn().getSymbol("xtoString",true);
	//vy=zin1.val->getDyn().getSymbol("ival",true);
	//*(boost::apply_visitor(ZTDataBridge((boost::get<gZMemData>(*vy)).cont->val),zk))=ZTInt(6504);
	//z4=*(boost::apply_visitor(ZTCallBridge((boost::get<gZFunction>(*vx)).cont->val->FunData.pMFun,i),zk));
	//
	//vx=zin0.val->getDyn().getSymbol("xtoString",true);
	//vy=zin0.val->getDyn().getSymbol("ival",true);
	//z4=*(boost::apply_visitor(ZTCallBridge((boost::get<gZFunction>(*vx)).cont->val->FunData.pMFun,i),zo));

	//ZTvarp hv = ZAlloc(ZTvar,1);
	//ZTvarp hw = ZAlloc(ZTvar,1);
	//ZTvarp hz = ZAlloc(ZTvar,1);
	//ZTvarp hy = ZAlloc(ZTvar,1);
	//ZTvarp h1 = ZAlloc(ZTvar,1);
	//ZTvarp h2 = ZAlloc(ZTvar,1);
	//ZTvarp h3 = ZAlloc(ZTvar,1);


	//ZTOInstance zin2,zin3,zin4,zin5,zin6,zin7;
	//zin1.val = new ASD();
	//zin2.val = new ZObjP();
	//zin3.val = new ZObjP();
	//zin4.val = new ZObjP();
	//zin5.val = new ZObjP();
	//zin6.val = new ZObjP();
	//zin7.val = new ZObjP();



	//reinterpret_cast<ASD*>(zin1.val)->a=ZTInt(888);
	////*hv=zin1;
	//*hv=ZObjP();
	//boost::get<gZObject>(*hv).cont=new ASD();
	//reinterpret_cast<ASD*>(boost::get<gZObject>(*hv).cont)->a=ZTInt(888);
	
	//boost::get<gZObject>(*hv).cont->cpy(zin2.val);
	//boost::get<gZObject>(*hv).cont->cpy(zin3.val);
	//boost::get<gZObject>(*hv).cont->cpy(zin4.val);

	///////*boost::get<gZOInstance>(*hv).cont->val->cpy(zin2.val);
	//////boost::get<gZOInstance>(*hv).cont->val->cpy(zin3.val);*/

	////ZObjP* zasd=new ASD();
	////zin2.val = new ASD();//zasd; //boost::get<gZObject>(*hv).cont;
	////zin3.val = new ASD();//zasd; //boost::get<gZObject>(*hv).cont;
	////*zin3.val=*(boost::get<gZObject>(*hv)).cont;
	//
	////zin2.val=new ZTObject();
	////zin2.val->DyProps=(boost::get<gZObject>(*hv).cont->DyProps);
	////zin3.val=new ZObjP();
	////zin3.val->DyProps=(boost::get<gZObject>(*hv).cont->DyProps);
	////*(zin3.val)=*(boost::get<gZObject>(*hv).cont);
	////zin2.val=new ZObjP(*(boost::get<gZObject>(*hv).cont));
	////zin3.val=new ZObjP(*(boost::get<gZObject>(*hv).cont));
	//
	////std::cout<<"cont : "<<(boost::get<gZObject>(*hv).cont)<<std::endl;
	//
	//*hw=zin2;
	//*hz=zin3;
	//*hy=zin4;
	//*hy=zin5;
	//*h1=zin6;
	//*h2=zin7;
	//*h3=zin4;

	////typedef ZTvar ZObjP::*ztdata;

	////boost::get<gZObject>(*hw).cont->*(reinterpret_cast<ztdata>(((boost::get<gZMemData>(*vy)).cont->val)))=ZTInt(969);


	//ZTDataBridge ztbg((boost::get<gZMemData>(*vy)).cont->val);
	//h3=(boost::apply_visitor(ztbg,*hw));
	////*h1=*h3;
	//
	//*(boost::apply_visitor(ztbg,*hw))=ZTInt(969);
	//z4=*(boost::apply_visitor(ZTCallBridge((boost::get<gZFunction>(*vx)).cont->val->FunData.pMFun,i),*hw));

	//*(boost::apply_visitor(ZTDataBridge((boost::get<gZMemData>(*vy)).cont->val),*hz))=ZTInt(767);
	//z4=*(boost::apply_visitor(ZTCallBridge((boost::get<gZFunction>(*vx)).cont->val->FunData.pMFun,i),*hz));

	//z4=*(boost::apply_visitor(ZTCallBridge((boost::get<gZFunction>(*vx)).cont->val->FunData.pMFun,i),*hw));
	//
	//std::cout<<boost::apply_visitor(getType(),*h3)<<std::endl;
	//std::cout<<boost::apply_visitor(getType(),*hw)<<std::endl;
	//std::cout<<boost::apply_visitor(getType(),*vx)<<std::endl;
	//std::cout<<boost::apply_visitor(getType(),z4)<<std::endl;
	////std::wcout<<boost::apply_visitor(ToString(),((ASD*)(zin.val))->a)<<std::endl;
	////std::wcout<<boost::apply_visitor(ToString(),z4)<<std::endl;

	////ZTvarp vy=zin.val->getDyn().getSymbol("ival",true);
	////std::wcout<<boost::apply_visitor(ToString(),*vy)<<std::endl;

	return 0;
}
// ZTypes.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "ZTypes.h"



int main(int argc, char* argv[])
{
	ZTvar zv1=ZTInt(5);
	ZTvar zv2=ZTFloat(3.25);
	ZTvar t;
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


	ZTvar a1,a2,a3,z4,z5;
	ZTmfp v;
	ZTvarS i;
	

	a1=ZTString(_ZC("AxSxD"));
	a2=ZTString(_ZC("Qwe"));
	a3=boost::apply_visitor(Sum(),a1,a2);
	a3=boost::apply_visitor(Sum(),a3,a3);
	
	std::wcout<<boost::apply_visitor(ToString(),a3)<<std::endl;

	
	v=reinterpret_cast<ZTmfp>(&ZTString::Len);
	
	
	z4=boost::apply_visitor(ZTCallBridge(v,i),a3);
	std::wcout<<boost::apply_visitor(ToString(),z4)<<std::endl;

	v=reinterpret_cast<ZTmfp>(&ZTFloat::Square);
	i.push_back(ZTFloat(2.5));
	z5=boost::apply_visitor(ZTCallBridge(v,i),zv2);

	std::wcout<<boost::apply_visitor(ToString(),z5)<<std::endl;
 
	ZTvar x1,x2,x3;
	x1=ZTBool(true);
	x2=ZTBool(true);
	x3=boost::apply_visitor(Boolean::And(),x1,x2);
	std::wcout<<boost::apply_visitor(ToString(),x3)<<std::endl;



	/*gZString cc=gZString(ZTString((_ZC("ASD"))));
	ZTString bb=ZTString(_ZC("QWE"));
	std::wcout<<cc.cont->val.c_str()<<std::endl;
	std::wcout<<bb.val.c_str()<<std::endl;*/
	
	return 0;
}
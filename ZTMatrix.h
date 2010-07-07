USING_PART_OF_NAMESPACE_EIGEN
class ZTMatrix : public ZTRoot
{
public:
	typedef MatrixXf IType;

	MatrixXf val;
	ZTMatrix(MatrixXf in)
	{
		myType=ZETMatrix;
		val=in;
	}

	ZTMatrix(const Eigen::Transform3f& in)
	{
		myType=ZETMatrix;
		val.resize(4,4);
		val.setIdentity();
		for(int i=0;i<3;i++)
			for(int j=0;j<4;j++)
				val(i,j) = in(i,j);
	}
	
	ZTMatrix()
	{
		val.Identity(4,4);
	}
	
	ZTMatrix(const ZTRoot & other) : ZTRoot(other)
	{
		ZTMatrix();
	}
	
	ZChar* Oname()
	{
		return _ZC("Matrix");
	}
	
};
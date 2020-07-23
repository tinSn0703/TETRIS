
#include "Vector.h"

#include <cmath>

/*************************************************************************/

namespace Suzugram	{
namespace Suzurary	{

/*************************************************************************/

constexpr double ERROR = 0.0001; 

/*************************************************************************/

//-----------------------------------------------------------------------//

double Vector::GetArgument()
{
	return 0.0;
}

//-----------------------------------------------------------------------//

double Vector::GetAbsolute()
{
	double _Absolute = 0;

	for (std::uint8_t i = 0; i < DIMENSION; i++)
	{
		_Absolute += std::pow(_Pos[i], 2);
	}

	return std::sqrt(_Absolute);
}

double& Vector::operator[](const Coodinate _Cood)
{
	return _Pos[_Cood];
}

Vector Vector::operator+(const Vector& _Obj) const
{
	return Vector
	(
		this->_Pos[X] + _Obj._Pos[X], 
		this->_Pos[Y] + _Obj._Pos[Y],
		this->_Pos[Z] + _Obj._Pos[Z]
	);
}

Vector Vector::operator-(const Vector& _Obj) const
{
	return Vector();
}

//-----------------------------------------------------------------------//

/*************************************************************************/

};	//Suzurary
};	//Suzugram

/*************************************************************************/


#pragma once

#include <iostream>

/*************************************************************************/

namespace Suzugram	{
namespace Suzurary	{

/*************************************************************************/

#define DIMENSION 3

class Vector
{
public:
	
	enum Coodinate	{	X = 0, Y = 1, Z = 2	};

public:
	
	Vector(const Vector& _Obj)
	{
		for (std::uint8_t i = 0; i < DIMENSION; i++)
		{
			this->_Pos[i] = _Obj._Pos[i];
		}
	}

	Vector(const double _X = 0, const double _Y = 0, const double _Z = 0)
	{
		_Pos[X] = _X;
		_Pos[Y] = _Y;
		_Pos[Z] = _Z;
	}

	double GetArgument();
	double GetAbsolute();

	double& operator[] (const Coodinate _Cood);
 
	Vector operator + (const Vector& _Obj) const;
	Vector operator - (const Vector &_Obj) const;

	double operator * (const Vector &_Obj) const;

	Vector operator * (const double _Value) const;
	Vector operator / (const double _Value) const;

	Vector & operator = (const Vector &_Obj);
	Vector & operator += (const Vector &_Obj);
	Vector & operator -= (const Vector &_Obj);

	Vector & operator *= (const double _Value);
	Vector & operator /= (const double _Value);

	bool operator == (const Vector &_Obj) const;
	bool operator != (const Vector &_Obj) const;

private:
	
	double _Pos[DIMENSION];
};

/*************************************************************************/

};	//Suzurary
};	//Suzugram

/*************************************************************************/

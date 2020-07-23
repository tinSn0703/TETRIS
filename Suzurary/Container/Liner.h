
#pragma once

/*************************************************************************/

#include "ReferenceCounter.h"

#include <iostream>
#include <memory>

/*************************************************************************/

namespace Suzugram	{
namespace Suzurary	{

/*************************************************************************/

template <class temp_type>
class Liner
{
//type
public:
	
	using value_type = temp_type;
	using reference = temp_type &;
	using const_reference = const temp_type &;
	using pointer = temp_type *;
	using const_pointer = const temp_type *;
	
//variable
protected:

	pointer _Elements;
	std::uint16_t *_Width;

	ReferenceCounter _Counter;

//funtion
public:
	
//-----------------------------------------------------------------------//
	
	Liner()
	{
		this->_Elements = nullptr;
		this->_Width = nullptr;
	}

	Liner(nullptr_t)
	{
		this->_Elements = nullptr;
		this->_Width = nullptr;
	}

	Liner(const std::int32_t _Width)
	{
		if (_Width < 2)
		{
			if (_Width < 0)	throw std::out_of_range("The number of elements is a negative number");
			else			throw std::out_of_range("The number of elements is too small");
		}
		
		this->_Elements = new temp_type[_Width];
		this->_Width = new std::uint16_t;
		(*this->_Width) = _Width;
	}

	Liner(const Liner<temp_type> & _Obj)
	{
		if (_Obj._Elements == nullptr)
		{
			throw std::invalid_argument("The object is empty.");
		}
		
		this->_Elements = _Obj._Elements;
		this->_Width = _Obj._Width;
		this->_Counter = _Obj._Counter;
		
		this->_Counter++;
	}
	
	void Reset(const std::int32_t _Width)
	{
		if (_Width < 2)
		{
			if (_Width < 0)	throw std::out_of_range("The number of elements is a negative number");
			else			throw std::out_of_range("The number of elements is too small");
		}

		Liner::Delete();

		this->_Elements = new value_type[_Width];
		this->_Width = new std::uint16_t;
		(*this->_Width) = _Width;
	}
	
	std::uint16_t GetWidth() const noexcept
	{
		return (this->_Width != nullptr ? *this->_Width : 0);
	}
	
	reference GetFront() noexcept	{ return _Elements[0]; }
	reference GetBack() noexcept	{ return _Elements[(*_Width) - 1]; }
	
	constexpr const_reference GetFront() const noexcept	{ return _Elements[0]; }
	constexpr const_reference GetBack() const noexcept	{ return Liner::Get(Liner::GetWidth() - 1); }
	
	reference Get(const std::uint16_t _Pos)
	{
		if (Liner::GetWidth() <= _Pos)	throw std::out_of_range("The specified number is too large");
		
		return this->_Elements[_Pos];
	}
	
	constexpr const_reference Get(const std::uint16_t _Pos) const
	{
		if (Liner::GetWidth() <= _Pos)	throw std::out_of_range("The specified number is too large");
		
		return this->_Elements[_Pos];
	}
	
	void Fill(const_reference _Elements) noexcept
	{
		for (std::uint16_t i = 0; i < Liner::GetWidth(); i++)
		{
			this->_Elements[i] = _Elements;
		}
	}

	void Swap(Liner<temp_type>& _Obj) noexcept
	{
		pointer temp_data = _Obj._Elements;
		std::uint16_t * temp_width = _Obj._Width;

		_Obj._Elements = this->_Elements;
		_Obj._Width = this->_Width;

		this->_Elements = temp_data;
		this->_Width = temp_width;

		this->_Counter.Swap(_Obj._Counter);
	}

	void Delete() noexcept
	{
		if (this->_Elements != nullptr)
		{
			if ( ! _Counter)
			{
				delete[] this->_Elements;
				delete	 this->_Width;
			}
			
			this->_Elements = nullptr;
			this->_Width = nullptr;
			
			_Counter.Delete();
		}
	}
	
	reference operator[](const std::uint16_t _Pos) noexcept
	{	return this->_Elements[_Pos];	}

	constexpr const_reference operator[](const std::uint16_t _Pos) const noexcept
	{	return this->_Elements[_Pos];	}
	
	Liner<temp_type> & operator= (const Liner<temp_type>& _Obj)
	{
		if ((this->_Elements != _Obj._Elements) && (_Obj._Elements != nullptr))
		{
			Liner::Delete();

			this->_Elements = _Obj._Elements;
			this->_Width = _Obj._Width;
			this->_Counter = _Obj._Counter;

			this->_Counter ++;
		}

		return *this;
	}
	
	explicit operator bool() const noexcept	{ return (this->_Elements != nullptr); }
	
	~Liner() noexcept	{ Liner::Delete();	}
}; //Liner

/*************************************************************************/

};	//Suzurary
};	//Suzugram

/*************************************************************************/

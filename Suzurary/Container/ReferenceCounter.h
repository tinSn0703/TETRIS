
#pragma once

#include <iostream>

/*************************************************************************/

namespace Suzugram	{
namespace Suzurary	{

/*************************************************************************/

class ReferenceCounter
{
//type
public:
	
	using Type = std::int16_t;
	using ConstType = const Type;
	using Pointer = Type *;
	using ConstPointer = ConstType *;
	
//function
public:
	
	ReferenceCounter()
	{
		this->num = new Type;
		(*this->num) = 0;
	}
	
	ReferenceCounter(nullptr_t)
	{
		this->num = new Type;
		(*this->num) = 0;
	}
	
	ReferenceCounter(const ReferenceCounter & obj)
	{
		if (obj.num == nullptr)	throw std::invalid_argument("The object is empty.");

		ReferenceCounter::Delete();

		this->num = obj.num;
	}
	
	ReferenceCounter(ReferenceCounter && obj)
	{
		if (obj.num == nullptr)	throw std::invalid_argument("The object is empty.");

		ReferenceCounter::Delete();

		this->num = obj.num;
		obj.num = nullptr;
	}
	
	Type Get() const noexcept { return ((this->num != nullptr) ? (*this->num) : 0); }
	
	void Swap(ReferenceCounter &obj) noexcept
	{
		Pointer temp = obj.num;
		obj.num = this->num;
		this->num = temp;
	}

	void Reset()
	{
		ReferenceCounter::Delete();

		this->num = new Type;
		(*this->num) = 0;
	}
	
	void Delete() noexcept
	{
		if (num != nullptr)
		{
			if ((*this->num) < 1)	delete this->num;
			else					(*this->num) --;
			
			this->num = nullptr;
		}
	}

	ReferenceCounter & operator = (const ReferenceCounter & obj) noexcept
	{
		if ((obj.num != nullptr) || (obj.num != num))
		{
			ReferenceCounter::Delete();

			this->num = obj.num;
		}
		
		return (*this);
	}

	ReferenceCounter & operator = (ReferenceCounter && obj) noexcept
	{
		if ((obj.num != nullptr) || (obj.num != num))
		{
			ReferenceCounter::Delete();

			this->num = obj.num;
		}
		return (*this);
	}
	
	void operator ++() noexcept	{ if (this->num != nullptr)			(*this->num) ++; }
	void operator --() noexcept	{ if (ReferenceCounter::Get() > 1)	(*this->num) --; }

	void operator ++(int) noexcept	{ ReferenceCounter::operator++(); }
	void operator --(int) noexcept	{ ReferenceCounter::operator--(); }
	
	explicit operator bool () noexcept	{	return (ReferenceCounter::Get() > 0);}

	~ReferenceCounter()	noexcept { ReferenceCounter::Delete(); }
	
//variable
private:
	
	Pointer num;
};

/*************************************************************************/

};
};

/*************************************************************************/

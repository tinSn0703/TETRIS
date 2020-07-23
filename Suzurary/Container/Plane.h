
#include "Liner.h"

/*************************************************************************/

namespace Suzugram	{
namespace Suzurary	{

/*************************************************************************/

template <class temp_type>
class Plane : public Liner<Liner<temp_type>>
{
//type
private:
	
	using mybase = Liner<Liner<temp_type>>;
	
public:

	using value_type = temp_type;
	using reference = temp_type &;
	using const_reference = const temp_type &;
	using pointer = typename mybase::pointer;
	using const_pointer = typename mybase::const_pointer;

//function
public:

	Plane() noexcept
	{
		this->_Elements = nullptr;
		this->_Width = nullptr;
		this->_Height = nullptr;
	}

	Plane(nullptr_t) noexcept
	{
		this->_Elements = nullptr;
		this->_Width = nullptr;
		this->_Height = nullptr;
	}

	Plane(const std::int16_t _Height, const std::int16_t _Width)
	{
		if ((_Width < 2) || (_Height < 2))
		{
			if ((_Width < 0) || (_Height < 0))	throw std::out_of_range("The number of elements is a negative number");
			else								throw std::out_of_range("The number of elements is too small");
		}
		
		this->_Height = new std::uint16_t;
		this->_Width = new std::uint16_t;
		
		this->_Elements = new Liner<temp_type>[_Height];
		
		for (std::uint16_t i = 0; i < _Height; i++)	this->_Elements[i].Reset(_Height);
		
		(*this->_Height) = _Height;
		(*this->_Width) = _Width;
	}

	Plane(const Plane<temp_type> & _Obj)
	{
		if (_Obj._Elements == nullptr)
		{
			throw std::invalid_argument("The object is empty.");
		}

		this->_Elements = _Obj._Elements;
		this->_Width = _Obj._Width;
		this->_Height = _Obj._Height;
		this->_Counter = _Obj._Counter;

		this->_Counter++;
	}
	
	void Reset(const std::int16_t _Height, const std::int16_t _Width)
	{
		if ((_Width < 2) || (_Height < 2))
		{
			if ((_Width < 0) || (_Height < 0))	throw std::out_of_range("The number of elements is a negative number");
			else								throw std::out_of_range("The number of elements is too small");
		}

		Plane::Delete();

		this->_Height = new std::uint16_t;
		this->_Width = new std::uint16_t;

		this->_Elements = new Liner<temp_type>[_Height];

		for (std::uint16_t i = 0; i < _Height; i++)	this->_Elements[i].Reset(_Width);

		(*this->_Height) = _Height;
		(*this->_Width) = _Width;
	}
	
	void Fill(const_reference _Elements) noexcept
	{
		for (std::uint16_t i = 0; i < GetHeight(); i++)
		{
			this->_Elements[i].Fill(_Elements);
		}
	}

	void Swap(Plane<temp_type>& _Obj) noexcept
	{
		Liner<temp_type> * _Temp_data = _Obj._Elements;
		std::uint16_t * _Temp_width = _Obj._Width;
		std::uint16_t * _Temp_height = _Obj._Height;

		_Obj._Elements = this->_Elements;
		_Obj._Width = this->_Width;
		_Obj._Height = this->_Height;

		this->_Elements = _Temp_data;
		this->_Width = _Temp_width;
		this->_Height = _Temp_height;

		this->_Counter.Swap(_Obj._Counter);
	}

	std::uint16_t GetHeight() const noexcept
	{
		return (this->_Height != nullptr ? *this->_Height : 0);
	}

	Liner<temp_type> & Get(const std::uint16_t _Pos)
	{
		if (GetHeight() <= _Pos)
		{
			throw std::out_of_range("The specified number is too large");
		}

		return this->_Elements[_Pos];
	}

	constexpr const Liner<temp_type> & Get(const std::uint16_t _Pos) const
	{
		if (GetHeight() <= _Pos)
		{
			throw std::out_of_range("The specified number is too large");
		}

		return this->_Elements[_Pos];
	}

	reference Get(const std::uint16_t y, const std::uint16_t x)
	{
		if ((GetWidth() <= x) || (GetHeight() <= y))
		{
			throw std::out_of_range("The specified number is too large");
		}

		return this->_Elements[y][x];
	}

	constexpr const_reference Get(const std::uint16_t y, const std::uint16_t x) const
	{
		if ((GetWidth() <= x) || (GetHeight() <= y))
		{
			throw std::out_of_range("The specified number is too large");
		}

		return this->_Elements[y][x];
	}

	void Delete() noexcept
	{
		if (this->_Elements != nullptr)
		{
			for (std::uint16_t i = 0; i < GetHeight(); i++)
			{
				_Elements[i].Delete();
			}
			
			if (_Counter.Get() < 1)
			{
				delete[] this->_Elements;
				delete	 this->_Width;
				delete	 this->_Height;
			}

			this->_Elements = nullptr;
			this->_Width = nullptr;
			this->_Height = nullptr;

			_Counter.Delete();
		}
	}
	
	Plane<temp_type> & operator = (const Plane<temp_type> &obj)
	{
		if ((this->_Elements != obj._Elements) && (obj._Elements != nullptr))
		{
			Plane::Delete();
			
			this->_Elements = obj._Elements;
			this->_Width = obj._Width;
			this->_Height = obj._Height;
			this->_Counter = obj._Counter;
			
			this->_Counter++;
		}
	}

	~Plane() noexcept	{	Plane::Delete();	}
	
	//variable
protected:
	
	std::uint16_t *_Height;
};

/*************************************************************************/

};	//Suzurary
};	//Suzugram

/*************************************************************************/

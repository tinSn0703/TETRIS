
#pragma once

#include "Suzurary/Draw.h"

/*************************************************************************/

namespace Suzugram	{
namespace TETRIS	{

/*************************************************************************/

//-----------------------------------------------------------------------//

class Piece
{
public:
	
	Piece();
	Piece(const Piece &_Obj);
	Piece(Suzurary::DrawObject& _DrawObj, const std::uint16_t _ID);
	
	std::uint16_t GetID();
	Suzurary::DrawObject& Get();

	~Piece();

private:
	std::uint16_t _ID;
	Suzurary::DrawObject& _DrawObj;
};


//-----------------------------------------------------------------------//

/*************************************************************************/

};	//Suzurary
};	//Suzugram

/*************************************************************************/


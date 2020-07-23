
#pragma once

#include <iostream>

/*************************************************************************/

namespace Suzugram	{
namespace Suzurary	{

/*************************************************************************/

class Randam
{
public:
	
	Randam();
	Randam(std::int16_t min, std::int16_t max);

	virtual void Set(std::int16_t min, std::int16_t max);
	
	virtual std::int16_t Create();

protected:
	
	std::int16_t min;
	std::int16_t max;
};

/*************************************************************************/

};	//Suzurary
};	//Suzugram

/*************************************************************************/

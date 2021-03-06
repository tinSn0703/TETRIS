
#pragma once

#include <list>
#include <memory>

/*************************************************************************/

namespace Suzugram {
namespace Suzurary {

/*************************************************************************/

class DrawObject;

/*************************************************************************/

class Drawer
{
protected:
	std::list<std::shared_ptr<DrawObject>> _draw_list;

};

/*************************************************************************/

};	//Suzurary
};	//Suzugram

/*************************************************************************/

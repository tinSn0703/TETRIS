
#pragma once

#include <iostream>
#include <memory>
#include <list>

/*************************************************************************/

namespace Suzugram
{
namespace Suzurary
{

/*************************************************************************/

//class DrawObject;
class Drawer;

/*************************************************************************/

//-----------------------------------------------------------------------//

class DrawProcess
{
};

//-----------------------------------------------------------------------//

class DrawObject
{
private:
	static std::shared_ptr<Drawer> _drawer;

protected:
	DrawObject()
	{
		if (_drawer) _drawer->Regist(this);
	}
public:
	void Draw()
	{
		std::cout << "a" << std::endl;
	}
	
	static void SetDrawer(Drawer& _obj)
	{
		std::shared_ptr<Drawer> _temp(&_obj);

		_drawer = _temp;
	}
};

//-----------------------------------------------------------------------//

class Drawer
{
protected:
	std::list<DrawObject*> _list_draw;

public:
	Drawer() {}

	virtual void Draw()
	{
		for (auto element : _list_draw)	element->Draw();
	}

	void Regist(DrawObject* _obj)
	{
		_list_draw.push_back(_obj);
	}
};

//-----------------------------------------------------------------------//

class DrawTest : public DrawObject
{
public:
	DrawTest()
	{

	}

	void Draw()
	{
		std::cout << "b" << std::endl;
	}
};

//-----------------------------------------------------------------------//

/*************************************************************************/

}
}

/*************************************************************************/

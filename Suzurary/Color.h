
#pragma once

#include <iostream>
#include <memory>
#include <list>

/*************************************************************************/

namespace Suzugram	{
namespace Suzurary	{

/*************************************************************************/

class DrawObject;

/*************************************************************************/

//-----------------------------------------------------------------------//

class Drawer
{
protected:
	std::list<std::shared_ptr<DrawObject>> _list_draw;

public:
	Drawer();

	virtual void Draw()
	{
		for (auto element : _list_draw) element->Draw();
	}

	void Regist(std::shared_ptr<DrawObject> _obj)
	{
		_list_draw.push_back(_obj);
	}
};

//-----------------------------------------------------------------------//

class DrawObject
{
private:
	static std::shared_ptr<Drawer> _drawer;
	
protected:
	DrawObject()
	{
		if (_drawer) _drawer->Regist(std::shared_ptr<DrawObject>(this));
	}
public:
	virtual void Draw() = 0;

	static void SetDrawer(std::shared_ptr<Drawer> _obj)
	{
		_drawer = _obj;
	}
};

//-----------------------------------------------------------------------//

class DrawTest : public DrawObject
{
public:

};

//-----------------------------------------------------------------------//

/*************************************************************************/

};	//Suzurary
};	//Suzugram

/*************************************************************************/

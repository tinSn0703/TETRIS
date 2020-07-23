
#include "Draw.h"

/*************************************************************************/

namespace Suzugram	{
namespace Suzurary	{

/*************************************************************************/

virtual void Drawer::Draw()
{
	for (auto element : _list_draw)	element->Draw();
}

void Drawer::Regist(DrawObject* _obj)
{
	_list_draw.push_back(_obj);
}


/*************************************************************************/

}}

/*************************************************************************/

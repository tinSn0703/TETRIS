
#include "Grafphics.h"

//------------------------------------------------------------//

Graphic::Graphic(const int _width, const int _height)

	: HEIGHT(_height)
	, WIDTH(_width)
{
	_pixel = new Pixel*[WIDTH];	//x軸の確保

	forloop(x, 0, WIDTH)
	{
		_pixel[x] = new Pixel[HEIGHT];	//y軸の確保
	}
}

//------------------------------------------------------------//

void Graphic::Paint(Graphic &_obj, const int x0, const int y0)
{
	if ((WIDTH <= x0) || (HEIGHT <= y0))	return (void)0;	//追加する描画が範囲外

	forloop(y, (y0 < 0 ? y0 * -1 : 0), HEIGHT)
	//y : 追加したい描画のy座標
	//追加する描画がマイナス領域に入っているとき、描画範囲に入っている座標から開始
	{
		if (y == _obj.GetHeight())	return (void)0;	//全ての描画を完了

		forloop(x, (x0 < 0 ? x0 * -1 : 0), WIDTH)
		//追加する描画がマイナス領域に入っているとき、描画範囲に入っている座標から開始
		{
			if (x == _obj.GetWidth())	break;	//現在の行の描画を終了し次の列に移る

			if (_obj.IsPixelExist(x, y) == true)
			{
				_pixel[x0 + x][y0 + y](_obj.GetColor(x, y));
			}
		}
	}
}

//------------------------------------------------------------//

void Graphic::PaintAll(const Color _color /*= 0*/)
{
	forloop(y, 0, HEIGHT)
	{
		forloop(x, 0, WIDTH)
		{
			_pixel[x][y](_color);
		}
	}
}

//------------------------------------------------------------//

void Graphic::PaintLineLengthways(int x, int y_start, int y_end, const Color _color /*= 0*/)
{
	if ((x < 0) || (WIDTH <= x))	return (void)0;	//座標が描画範囲外

	if (y_start > y_end)	//最初と最後の上下関係が逆なので入れ替え
	{
		const int _temp = y_start; y_start = y_end; y_end = _temp;
	}

	if (y_start < 0)	//範囲外の座標を範囲内にする
	{
		if (y_end < 0)	return (void)0;	//座標が描画範囲外

		y_start = 0;
	}

	if (HEIGHT <= y_end)	//範囲外の座標を範囲内にする
	{
		if (HEIGHT <= y_start)	return (void)0;	//座標が描画範囲外

		y_end = HEIGHT - 1;
	}

	forloop(y, y_start, y_end + 1)
	{
		_pixel[x][y](_color);
	}
}

//------------------------------------------------------------//

void Graphic::PaintLineSidetways(int y, int x_start, int x_end, const Color _color /*= 0*/)
{
	if ((y < 0) || (HEIGHT <= y))	return (void)0;	//座標が描画範囲外

	if (x_start > x_end)	//最初と最後の上下関係が逆なので入れ替え
	{
		const int _temp = x_start; x_start = x_end; x_end = _temp;
	}

	if (x_start < 0)	//範囲外の座標を範囲内にする
	{
		if (x_end < 0)	return (void)0;	//座標が描画範囲外

		x_start = 0;
	}

	if (WIDTH <= x_end)	//範囲外の座標を範囲内にする
	{
		if (WIDTH <= x_start)	return (void)0;	//座標が描画範囲外

		x_end = WIDTH - 1;
	}

	forloop(x, x_start, x_end + 1)
	{
		_pixel[x][y](_color);
	}
}

//------------------------------------------------------------//

void Graphic::PaintSquare(int x_start, int y_start, int x_end, int y_end, const Color _color /*= 0*/)
{
	if (y_start > y_end)
	{
		const int _temp = y_start; y_start = y_end; y_end = _temp;
	}

	if (x_start > x_end)
	{
		const int _temp = x_start; x_start = x_end; x_end = _temp;
	}

	if (x_start < 0)
	{
		if (x_end < 0)	return (void)0;

		x_start = 0;
	}

	if (y_start < 0)
	{
		if (y_end < 0)	return (void)0;

		y_start = 0;
	}

	if (WIDTH <= x_end)
	{
		if (WIDTH <= x_start)	return (void)0;

		x_end = WIDTH - 1;
	}

	if (HEIGHT <= y_end)
	{
		if (HEIGHT <= y_start)	return (void)0;

		y_end = HEIGHT - 1;
	}

	forloop(x, x_start, x_end + 1)
	{
		forloop(y, y_start, y_end + 1)
		{
			_pixel[x][y](_color);
		}
	}
}

//------------------------------------------------------------//

void Graphic::PaintPixel(int x, int y, const Color _color /*= 0*/)
{
	if (x < 0)			x = 0;
	if (WIDTH <= x)		x = WIDTH - 1;

	if (y < 0)			y = 0;
	if (HEIGHT <= y)	y = HEIGHT - 1;

	_pixel[x][y](_color);
}

//------------------------------------------------------------//

bool Graphic::IsPixelExist(int x, int y)
{
	return _pixel[x][y]._is_exist;
}

//------------------------------------------------------------//

Color Graphic::GetColor(int x, int y)
{
	return _pixel[x][y]._color;
}

//------------------------------------------------------------//

int Graphic::GetHeight()
{
	return HEIGHT;
}

//------------------------------------------------------------//

int Graphic::GetWidth()
{
	return WIDTH;
}

//------------------------------------------------------------//

Graphic::~Graphic()
{
	forloop(x, 0, WIDTH)
	{
		delete[] _pixel[x];
		_pixel[x] = 0;
	}

	delete[] _pixel;
	_pixel = 0;
}

//------------------------------------------------------------//

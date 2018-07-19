#pragma once

#include <Windows.h>
#include <iostream>

#define forloop(i, MIN, MAX) for(int i = MIN; i < MAX; i++)

#define CLEAR	0x1000000
#define BLACK	0x000000
#define RED		0x0000ff
#define GREEN	0x00ff00
#define BLUE	0xff0000
#define YELLOW	RED | GREEN
#define MAGENTA	RED | BLUE
#define CYAN	BLUE | GREEN
#define WHITE	RED | GREEN | BLUE

typedef DWORD Color;

inline Color COLOR(const Color Blue, const Color Green, const Color Red)
{
	return ((Blue & 0xff) << 16) | ((Green & 0xff) << 8) | ((Red & 0xff));
}

/**************************************************************/

struct Pixel
{
public:
	
	bool	_is_exist;
	Color	_color;

	Pixel()
	{
		_is_exist = false;
		_color = CLEAR;
	}

	void operator () (Color _color)
	{
		this->_is_exist = (_color == CLEAR) ? false : true;	
		this->_color = _color;
	}

	void operator () (bool _is_exist, Color _color)
	{
		this->_is_exist	= _is_exist;
		this->_color	= _color;
	}
};

/**************************************************************/

class Graphic
{
public:
	
	/**
	 *	_width	: 幅。x座標上限
	 *	_height	: 高さ。y座標上限
	**/
	Graphic(const int _width, const int _height);
	
	/**　別の描画を追加する。
	 *	_obj	: 追加したい絵
	 *	x0,y0	: 追加する座標。右上になる
	**/
	void Paint(Graphic &_obj, const int x0, const int y0);
	
	/**	全体を配色する
	 *	_color	: 色
	**/
	void PaintAll(const Color _color = BLACK);
	
	/**	縦線を引く。
	 *	x		: 縦線のx座標
	 *	y_start	: 上の値
	 *	y_end	: 下の値
	 *	_color	: 色
	**/
	void PaintLineLengthways(int x, int y_start, int y_end, const Color _color = BLACK);
	
	/**	横線を引く。
	 *	y		: 横線のy座標
	 *	x_start	: 左の値
	 *	x_end	: 右の値
	 *	_color	: 色
	**/
	void PaintLineSidetways(int y, int x_start, int x_end, const Color _color = BLACK);
	
	/**	四角形に配色。
	 *	x_start, y_start	: 左上の座標
	 *	x_end, y_end		: 右下の座標 
	 *	_color	: 色
	**/
	void PaintSquare(int x_start, int y_start, int x_end, int y_end, const Color _color = BLACK);
	
	/**	1ピクセルに配色。
	 *	x,y		: 座標
	 *	_color	: 色
	**/
	void PaintPixel(int x, int y, const Color _color = BLACK);

	/**	指定したピクセルが空白でないかを返す。	
	 *	x,y	: 見たい座標 
	**/
	bool IsPixelExist(int x, int y);
	
	/**	指定したピクセルの色を返す	
	 *	x,y	: 見たい座標
	**/
	Color GetColor(int x, int y);
	
	/*	高さを返す。*/
	int GetHeight();
	
	/*	幅を返す。	*/
	int GetWidth();

	virtual ~Graphic();
	
protected:
	
	const int HEIGHT;	//高さ
	const int WIDTH;	//幅

	Pixel **_pixel;	//ピクセル
};

/**************************************************************/

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
	 *	_width	: ���Bx���W���
	 *	_height	: �����By���W���
	**/
	Graphic(const int _width, const int _height);
	
	/**�@�ʂ̕`���ǉ�����B
	 *	_obj	: �ǉ��������G
	 *	x0,y0	: �ǉ�������W�B�E��ɂȂ�
	**/
	void Paint(Graphic &_obj, const int x0, const int y0);
	
	/**	�S�̂�z�F����
	 *	_color	: �F
	**/
	void PaintAll(const Color _color = BLACK);
	
	/**	�c���������B
	 *	x		: �c����x���W
	 *	y_start	: ��̒l
	 *	y_end	: ���̒l
	 *	_color	: �F
	**/
	void PaintLineLengthways(int x, int y_start, int y_end, const Color _color = BLACK);
	
	/**	�����������B
	 *	y		: ������y���W
	 *	x_start	: ���̒l
	 *	x_end	: �E�̒l
	 *	_color	: �F
	**/
	void PaintLineSidetways(int y, int x_start, int x_end, const Color _color = BLACK);
	
	/**	�l�p�`�ɔz�F�B
	 *	x_start, y_start	: ����̍��W
	 *	x_end, y_end		: �E���̍��W 
	 *	_color	: �F
	**/
	void PaintSquare(int x_start, int y_start, int x_end, int y_end, const Color _color = BLACK);
	
	/**	1�s�N�Z���ɔz�F�B
	 *	x,y		: ���W
	 *	_color	: �F
	**/
	void PaintPixel(int x, int y, const Color _color = BLACK);

	/**	�w�肵���s�N�Z�����󔒂łȂ�����Ԃ��B	
	 *	x,y	: ���������W 
	**/
	bool IsPixelExist(int x, int y);
	
	/**	�w�肵���s�N�Z���̐F��Ԃ�	
	 *	x,y	: ���������W
	**/
	Color GetColor(int x, int y);
	
	/*	������Ԃ��B*/
	int GetHeight();
	
	/*	����Ԃ��B	*/
	int GetWidth();

	virtual ~Graphic();
	
protected:
	
	const int HEIGHT;	//����
	const int WIDTH;	//��

	Pixel **_pixel;	//�s�N�Z��
};

/**************************************************************/

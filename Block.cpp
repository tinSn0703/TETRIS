
#include "Block.h"

#include <random>

/**************************************************************/

//------------------------------------------------------------//

BlockGraphic::BlockGraphic()

	: Graphic(PIECE_WIDTH, PIECE_HEIGHT)
{

}

//------------------------------------------------------------//

void BlockGraphic::CreateBlock(int i)
{
	PaintAll(CLEAR);

	switch (i)
	{
		case 0:										//□□□□
			PaintPixel(1, 2, RED);					//□□■□
			PaintLineLengthways(2, 1, 3, RED);		//□■■□
			break;									//□□■□

		case 1:										//□□□□
			PaintLineLengthways(1, 1, 2, BLUE);		//□■□□
			PaintLineLengthways(2, 2, 3, BLUE);		//□■■□
			break;									//□□■□
		
		case 2:										//□□□□
			PaintLineLengthways(1, 2, 3, GREEN);	//□□■□
			PaintLineLengthways(2, 1, 2, GREEN);	//□■■□
			break;									//□■□□
		
		case 3:										//□□■□
													//□□■□
			PaintLineLengthways(2, 0, 3, WHITE);	//□□■□
			break;									//□□■□

		case 4:										//□□□□
													//□■■□
			PaintSquare(1, 1, 2, 2, MAGENTA);		//□■■□
			break;									//□□□□
		
		case 5:										//□□□□
			PaintLineLengthways(2, 1, 3, CYAN);		//□□■□
			PaintPixel(1, 3, CYAN);					//□□■□
			break;									//□■■□
		
		case 6:										//□□□□
			PaintLineLengthways(1, 1, 3, YELLOW);	//□■□□
			PaintPixel(2, 3, YELLOW);				//□■□□
			break;									//□■■□

		default:	break;
	}
}

//------------------------------------------------------------//

void BlockGraphic::CreateRandomBlock()
{
	std::random_device _rand_init;			// 非決定的な乱数生成器を生成
	std::mt19937 _generator(_rand_init());	//  メルセンヌ・ツイスタの32ビット版、引数は初期シード値

	std::uniform_int_distribution<int> _rand2(0, 2);
	std::uniform_int_distribution<int> _rand3(0, 3);
	std::uniform_int_distribution<int> _rand7(1, 10);

	int x = _rand3(_generator);
	int y = _rand3(_generator);

	int dx = 0;
	int dy = 0;

	for (int i = _rand7(_generator); 0 < i; i--)
	{
		PaintPixel(x, y, COLOR(100, 200, 0));

		do
		{
			dx = _rand2(_generator) - 1;
		}
		while (((dx + x) < 0) || (GetWidth() <= (dx + x)));

		x += dx;

		do
		{
			dy = _rand2(_generator) - 1;
		}
		while (((dy + y) < 0) || (GetHeight() <= (dy + y)));

		y += dy;
	}
}

//------------------------------------------------------------//

BlockGraphic & BlockGraphic::operator = (BlockGraphic &_obj)
{
	Paint(_obj, 0, 0);

	return _obj;
}

//------------------------------------------------------------//

BlockGraphic::~BlockGraphic()
{

}

//------------------------------------------------------------//

/**************************************************************/

//------------------------------------------------------------//

Block::Block()
{

}

//------------------------------------------------------------//

void Block::Set(BlockGraphic &_obj)
{
	_graphic = _obj;
}

//------------------------------------------------------------//

void Block::TurnLeft()
{
	

	for ()
}

//------------------------------------------------------------//

//------------------------------------------------------------//

//------------------------------------------------------------//

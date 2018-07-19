#pragma once

#include "Grafphics.h"

//Piece Size
#define PIECE_WIDTH 4
#define PIECE_HEIGHT 4

//Field Size
#define FIELD_WIDTH 14
#define FIELD_HEIGHT 24

class BlockGraphic : public Graphic
{
public:
	
	BlockGraphic();

	void CreateBlock(int i);

	void CreateRandomBlock();

	BlockGraphic & operator = (BlockGraphic &_obj);

	~BlockGraphic();
};

class Block
{
public:
	
	Block();

	void Set(BlockGraphic &_obj);

	void TurnLeft();

	void TurnRight();

	int GetLeft();

	int GetRight();

	int GetTop();

	int GetBottom();

	POINT GetPoint();

	void Move(int x, int y);

	~Block();

protected:
	
	POINT _point;	//�u���b�N�̍��W
	BlockGraphic _graphic;	
};

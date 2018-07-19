
#include <dxgi1_4.h>
#include <d3d12.h>

#include <windows.h>

#include "Grafphics.h"
#include "Block.h"

int main()
{
	BlockGraphic _block;

	for (int i = 0; i < 14; i++)
	{
		if (i < 7)
		{
			_block.CreateBlock(i);
		}
		else
		{
			_block.CreateRandomBlock();
		}

		
		for (int y = 0; y < _block.GetHeight(); y++)
		{
			for (int x = 0; x < _block.GetWidth(); x++)
			{
				if (_block.IsPixelExist(x, y) == true)
				{
					std::cout << "¡";
				}
				else
				{
					std::cout << " ";
				}
			}

			std::cout << std::endl;
		}

		std::cout << std::endl;
	}

	getchar();
}

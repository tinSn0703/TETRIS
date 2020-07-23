
//http://vivi.dyndns.org/tech/cpp/setColor.html
//https://support.microsoft.com/ja-jp/help/99261/how-to-performing-clear-screen-cls-in-a-console-application
//https://msdn.microsoft.com/ja-jp/library/cc429358.aspx

#define _CRT_SECURE_NO_WARNINGS

#include <dxgi1_4.h>
#include <d3d12.h>

#include <ctime>

#include <iostream>

//#include "Suzurary/Container/Liner.h"
//#include "Suzurary/Container/Plane.h"

#include <memory>
#include <list>
#include <array>
#include <vector>

#include "Suzurary/Draw.h"

class Base
{
public:
	virtual void Sign() = 0;
};

class ClassA : public Base
{
public:
	void Sign()
	{
		std::cout << "ClassA\n";
	}
};

class ClassB : public Base
{
public:
	void Sign()
	{
		std::cout << "ClassB\n";
	}
};

//-----------------------------------------------------------------------//

int main()
{
	Suzugram::Suzurary::Drawer _drawer;
	Suzugram::Suzurary::DrawTest _test;

	_test.SetDrawer(_drawer);

	_drawer.Draw();

	std::getchar();

	return 0;
}

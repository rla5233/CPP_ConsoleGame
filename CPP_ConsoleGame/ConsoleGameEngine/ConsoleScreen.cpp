#include "ConsoleScreen.h"

#include "ConsoleObject.h"

ConsoleScreen::ConsoleScreen()
{
}

ConsoleScreen::~ConsoleScreen()
{
	ReleaseScreen();
}

void ConsoleScreen::CreateScreen(int _ScreenX, int _ScreenY)
{
	ReleaseScreen();

	if (0 >= _ScreenX)
	{
		MsgBoxAssert("CreateScreen Error : Screen Range Error");
	}

	if (0 >= _ScreenY)
	{
		MsgBoxAssert("CreateScreen Error : Screen Range Error");
	}

	if (0 != ScreenData.size())
	{
		MsgBoxAssert("CreateScreen Error : Already Exist Screen");
	}

	ScreenX = _ScreenX;
	ScreenY = _ScreenY;

	ScreenData.resize(ScreenY);

	if (0 == ScreenData.size())
	{
		MsgBoxAssert("CreateScreen Error : Failed Create Screen");
	}
	
	for (int y = 0; y < ScreenY; y++)
	{
		ScreenData[y].resize(ScreenX + 2);

		if (0 == ScreenData[y].size())
		{
			MsgBoxAssert("CreateScreen Error : Failed Create Screen");
		}
	}

	ClearScreen();
}

void ConsoleScreen::ReleaseScreen()
{
	ScreenData.clear();
}

void ConsoleScreen::PrintScreen()
{
	system("cls");

	for (int y = 0; y < ScreenY; y++)
	{
		if (0 == ScreenData[y].size())
		{
			MsgBoxAssert("PrintScreen Error : Print Not Exist Line");
		}

		wprintf_s(&ScreenData[y][0]);
	}

	ClearScreen();
}

void ConsoleScreen::ClearScreen()
{
	for (int y = 0; y < ScreenY; y++)
	{
		for (int x = 0; x < ScreenX; x++)
		{
			ScreenData[y][x] = '*';
		}
		ScreenData[y][ScreenX] = '\n';
	}
}

void ConsoleScreen::SetChar(const ConsoleObject& _Object)
{
	
}

void ConsoleScreen::SetChar(const ConsoleObject* _Object)
{

}

void ConsoleScreen::SetChar(const Point _Pos, wchar_t _Char)
{
	if (0 > _Pos.X || 0 > _Pos.Y || ScreenX <= _Pos.X || ScreenY <= _Pos.Y)
	{
		return;
	}

	ScreenData[_Pos.Y][_Pos.X] = _Char;

}

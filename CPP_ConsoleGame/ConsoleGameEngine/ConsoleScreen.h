#pragma once

#include <iostream>
#include <vector>

#include "EngineDebug.h"
#include "ConsoleMath.h"

class ConsoleScreen
{
public:
	ConsoleScreen();
	virtual ~ConsoleScreen();

	void CreateScreen(int _ScreenX, int _ScreenY);
	void ReleaseScreen();
	void PrintScreen();
	void ClearScreen();

	void SetChar(const class ConsoleObject& _Object);
	void SetChar(const class ConsoleObject* _Object);
	void SetChar(const Point _Pos, wchar_t _Char);

	inline int GetScreenX() const
	{
		return ScreenX;
	}

	inline int GetScreenY() const
	{
		return ScreenY;
	}

protected:

private:
	int ScreenX = -1;
	int ScreenY = -1;

	std::vector<std::vector<wchar_t>> ScreenData;
};


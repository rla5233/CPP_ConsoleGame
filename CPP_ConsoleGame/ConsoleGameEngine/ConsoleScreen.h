#pragma once

#include <vector>

#include "EngineDebug.h"
#include "ConsoleMath.h"

class ConsoleScreen
{
public:
	ConsoleScreen();
	virtual ~ConsoleScreen();

	void CreateScreen(int _ScreenX, int _ScreenY);
	void ReleaseScreen() const;
	void PrintScreen() const;
	void ClearScreen() const;

	void SetChar(const class ConsoleObject& _Object) const;
	void SetChar(const class ConsoleObject* _Object) const;
	void SetChar(const Point _Pos, char _Char) const;

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

	std::vector<std::vector<const char*>> ScreenData;
};


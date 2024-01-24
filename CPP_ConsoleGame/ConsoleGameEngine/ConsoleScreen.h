#pragma once

#include <string>
#include <vector>

#include "EngineDebug.h"
#include "ConsoleMath.h"

class ConsoleScreen
{
public:
	ConsoleScreen();
	virtual ~ConsoleScreen();

	// delete Function
	ConsoleScreen(const ConsoleScreen& _Other) = delete;
	ConsoleScreen(ConsoleScreen&& _Other) noexcept = delete;
	ConsoleScreen& operator=(const ConsoleScreen& _Other) = delete;
	ConsoleScreen& operator=(ConsoleScreen&& _Other) noexcept = delete;

	void CreateScreen(int _ScreenX, int _ScreenY);
	void ReleaseScreen();
	void PrintScreen();
	void ClearScreen();

	void SetChar(const class ConsoleObject& _Object);
	void SetChar(const class ConsoleObject* _Object);
	void SetChar(const Point _Pos, char _Char);

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

	std::vector<std::string> ScreenData;
};


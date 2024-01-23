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

}

void ConsoleScreen::ReleaseScreen() const
{
}

void ConsoleScreen::PrintScreen() const
{
}

void ConsoleScreen::ClearScreen() const
{
}

void ConsoleScreen::SetChar(const ConsoleObject& _Object) const
{
}

void ConsoleScreen::SetChar(const ConsoleObject* _Object) const
{
}

void ConsoleScreen::SetChar(const Point _Pos, char _Char) const
{
}

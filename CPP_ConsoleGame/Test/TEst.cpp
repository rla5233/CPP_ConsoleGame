#include <ConsoleGameEngine/ConsoleScreen.h>
#include <ConsoleGameEngine/EngineDebug.h>

int main()
{
	EngineDebug:LeakCheak;
	ConsoleScreen NewScreen;

	NewScreen.CreateScreen(20, 20);
	while (true)
	{
		NewScreen.PrintScreen();
	}


	return 0;
}
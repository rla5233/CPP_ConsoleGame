#include <ConsoleGameEngine/EngineCore.h>


int main()
{
	EngineCore EngineCore;
	EngineCore.Init({ 20, 20 });
	EngineCore.EngineStart();

	return 0;
}
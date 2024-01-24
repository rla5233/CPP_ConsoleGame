#include "EngineCore.h"
#include "EngineDebug.h"
#include "time.h"

EngineCore::EngineCore()
{
}

EngineCore::~EngineCore()
{
}

void EngineCore::Init(Point _ScreenSize)
{
	LeakCheak;

	Screen.CreateScreen(_ScreenSize.X, _ScreenSize.Y);
	srand(static_cast<unsigned int>(time(0)));
}

void EngineCore::EngineStart()
{
	while (EngineUpdate)
	{
		Sleep(100);

		// 매니저 업데이트


		// 오브젝트 업데이트


		// 렌더링


		// 렌더 릴리즈


		// 업데이트 릴리즈
	}
}

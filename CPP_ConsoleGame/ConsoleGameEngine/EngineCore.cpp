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

		// �Ŵ��� ������Ʈ


		// ������Ʈ ������Ʈ


		// ������


		// ���� ������


		// ������Ʈ ������
	}
}

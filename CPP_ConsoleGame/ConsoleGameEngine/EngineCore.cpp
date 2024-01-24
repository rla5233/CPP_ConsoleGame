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
		{
			for (std::pair<const int, ConsoleUpdater*>& Order : AllManager)
			{
				ConsoleUpdater* Object = Order.second;
				if (nullptr == Object)
				{
					MsgBoxAssert("Manager Nullptr Error");
				}

				Object->Update();
			}
		}

		// 오브젝트 업데이트
		{
			for (std::pair<const int, std::list<ConsoleObject*>>& Order : AllUpdateObject)
			{
				std::list<ConsoleObject*>& ObjectList = Order.second;
				for (ConsoleObject* Object : ObjectList)
				{
					if (nullptr == Object)
					{
						MsgBoxAssert("Update Object Nullptr Error");
					}
					
					Object->Update();
				}
			}
		}


		// 렌더링


		// 렌더 릴리즈


		// 업데이트 릴리즈
	}
}

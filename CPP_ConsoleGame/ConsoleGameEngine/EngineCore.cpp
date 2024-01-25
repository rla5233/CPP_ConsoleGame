#include "EngineCore.h"
#include "EngineDebug.h"
#include "time.h"

#include <conio.h>

EngineCore::EngineCore()
{
}

EngineCore::~EngineCore()
{
}

void EngineCore::Init(Point _ScreenSize)
{
	Screen.CreateScreen(_ScreenSize.X, _ScreenSize.Y);
	srand(static_cast<unsigned int>(time(0)));
}

void EngineCore::Start()
{	
	Tick();
}

void EngineCore::Tick()
{
	while (EngineUpdate)
	{
		Sleep(500);

		// �Ŵ��� ������Ʈ
		{
			for (std::pair<const int, ConsoleUpdater*>& Order : AllManager)
			{
				ConsoleUpdater* Object = Order.second;
				if (nullptr == Object)
				{
					MsgBoxAssert("Update : Manager Nullptr Error");
				}

				Object->Update();
			}
		}

		// ������Ʈ ������Ʈ
		{
			for (std::pair<const int, std::list<ConsoleObject*>>& Order : AllUpdateObject)
			{
				std::list<ConsoleObject*>& ObjectList = Order.second;
				for (ConsoleObject* Object : ObjectList)
				{
					if (nullptr == Object)
					{
						MsgBoxAssert("Update : Object Nullptr Error");
					}

					Object->Update();
				}
			}
		}

		// ������
		{
			for (std::pair<const int, std::list<ConsoleObject*>>& Order : AllRenderObject)
			{
				std::list<ConsoleObject*>& ObjectList = Order.second;
				for (ConsoleObject* Object : ObjectList)
				{
					if (nullptr == Object)
					{
						MsgBoxAssert("Rendering : Object Nullptr Error");
					}

					Screen.SetChar(Object);
				}
			}

			Screen.PrintScreen();
		}

		// ���� ������
		{
			for (std::pair<const int, std::list<ConsoleObject*>>& Order : AllRenderObject)
			{
				std::list<ConsoleObject*>& ObjectList = Order.second;
				for (std::list<ConsoleObject*>::iterator iter = ObjectList.begin(); iter != ObjectList.end();)
				{
					ConsoleObject* Object = *iter;
					if (nullptr == Object)
					{
						MsgBoxAssert("RenderRelease : Object Nullptr Error");
					}

					if (Object->IsDeath())
					{
						iter = ObjectList.erase(iter);
					}
					else
					{
						++iter;
					}
				}
			}
		}

		// ������Ʈ ������
		{
			for (std::pair<const int, std::list<ConsoleObject*>>& Order : AllUpdateObject)
			{
				std::list<ConsoleObject*>& ObjectList = Order.second;
				for (std::list<ConsoleObject*>::iterator iter = ObjectList.begin(); iter != ObjectList.end();)
				{
					ConsoleObject* Object = *iter;
					if (nullptr == Object)
					{
						MsgBoxAssert("UpdateRelease : Object Nullptr Error");
					}

					if (Object->IsDeath())
					{
						delete Object;
						Object = nullptr;

						iter = ObjectList.erase(iter);
					}
					else
					{
						++iter;
					}
				}
			}
		}
	}

	End();
}

void EngineCore::End()
{
	// ���� �����
	for (std::pair<const int, std::list<ConsoleObject*>>& Order : AllUpdateObject)
	{
		std::list<ConsoleObject*>& ObjectList = Order.second;
		for (std::list<ConsoleObject*>::iterator iter = ObjectList.begin(); iter != ObjectList.end();)
		{
			ConsoleObject* Object = *iter;
			if (nullptr != Object)
			{
				delete Object;
				Object = nullptr;
			}
		}
	}

	AllUpdateObject.clear();

	for (std::pair<const int, ConsoleUpdater*>& Order : AllManager)
	{
		ConsoleUpdater* Updater = Order.second;
		if (nullptr != Updater)
		{
			delete Updater;
			Updater = nullptr;
		}
	}

	AllManager.clear();
}
#pragma once

#include <map>
#include <list>

#include "ConsoleScreen.h"
#include "ConsoleObject.h"

class EngineCore
{
	// 충돌체크를 위해 ConsoleObject에 friend를 선언했다.
	friend class ConsoleObject;
public:
	// constructor destructor
	EngineCore();
	~EngineCore();

	// delete Function
	EngineCore(const EngineCore& _Other) = delete;
	EngineCore(EngineCore&& _Other) noexcept = delete;
	EngineCore& operator=(const EngineCore& _Other) = delete;
	EngineCore& operator=(EngineCore&& _Other) noexcept = delete;
	/////////////////////////////////////////////////////////////
	void Init(Point _ScreenSize);
	virtual void Start();
	virtual void Tick();
	virtual void End();
	//{
	//	EngineUpdate = false;
	//}

	template<typename ObjectType, typename EnumType>
	ObjectType* CreateObject(EnumType _Order)
	{
		return CreateObject<ObjectType>(_Order, _Order);
	}

	template<typename ObjectType, typename UpdateEnumType, typename RenderEnumType>
	ObjectType* CreateObject(UpdateEnumType _UpdateOrder, RenderEnumType _RenderOrder)
	{
		return CreateObject<ObjectType>(static_cast<int>(_UpdateOrder), static_cast<int>(_RenderOrder));
	}

	template<typename ObjectType>
	ObjectType* CreateObject(int _UpdateOrder = 0, int _RenderOrder = 0)
	{
		ObjectType* NewObject = new ObjectType();
		NewObject->ConsoleUpdater::SetCore(this);
		AllUpdateObject[_UpdateOrder].push_back(NewObject);
		AllRenderObject[_RenderOrder].push_back(NewObject);
		return NewObject;
	}

	template<typename ObjectType>
	ObjectType* CreateManager(int _UpdateOrder)
	{
		if (true == AllManager.contains(_UpdateOrder))
		{
			MsgBoxAssert("Manager Already Exist");
			return nullptr;
		}

		ObjectType* NewObject = new ObjectType();
		NewObject->ConsoleUpdater::SetCore(this);
		AllManager[_UpdateOrder] = NewObject;
		return NewObject;
	}

	template<typename EnumType>
	std::list<ConsoleObject*> GetUpdateGroup(EnumType _Order)
	{
		return GetUpdateGroup(static_cast<int>(_Order));
	}

	// 보통 엄청 무거운 함수가 된다. -> 새 리스트가 만들어지기 때문에
	// 따라서 필요한 클래스에 friend를 사용하는 방법이 있다.
	std::list<ConsoleObject*> GetUpdateGroup(int _Order = 0)
	{
		return AllUpdateObject[_Order];
	}

protected:

private:
	ConsoleScreen Screen = ConsoleScreen();

	// 관리 감독하는 기능들을 모아둔 map
	std::map<int, ConsoleUpdater*> AllManager;

	// 실제 Object
	std::map<int, std::list<ConsoleObject*>> AllUpdateObject;
	std::map<int, std::list<ConsoleObject*>> AllRenderObject;
	bool EngineUpdate = true;
};

#define ENGINESTART(SCREENSIZE_X, SCREENSIZE_Y) \
int main() \
{ \
	LeakCheak; \
	EngineCore EngineCore; \
	EngineCore.Init({ SCREENSIZE_X, SCREENSIZE_Y }); \
	EngineCore.Start(); \
}
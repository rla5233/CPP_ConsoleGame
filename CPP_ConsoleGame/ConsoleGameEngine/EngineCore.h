#pragma once

#include <map>
#include <list>

#include "ConsoleScreen.h"
#include "ConsoleObject.h"

class EngineCore
{
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
	void EngineStart();
	void EngineEnd()
	{
		EngineUpdate = false;
	}

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

	// 보통 엄청 무거운 함수가 된다.
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


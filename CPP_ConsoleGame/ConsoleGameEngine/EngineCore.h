#pragma once

#include <map>
#include <list>

#include "ConsoleScreen.h"
#include "ConsoleObject.h"

class EngineCore
{
	// �浹üũ�� ���� ConsoleObject�� friend�� �����ߴ�.
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

	// ���� ��û ���ſ� �Լ��� �ȴ�. -> �� ����Ʈ�� ��������� ������
	// ���� �ʿ��� Ŭ������ friend�� ����ϴ� ����� �ִ�.
	std::list<ConsoleObject*> GetUpdateGroup(int _Order = 0)
	{
		return AllUpdateObject[_Order];
	}

protected:

private:
	ConsoleScreen Screen = ConsoleScreen();

	// ���� �����ϴ� ��ɵ��� ��Ƶ� map
	std::map<int, ConsoleUpdater*> AllManager;

	// ���� Object
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
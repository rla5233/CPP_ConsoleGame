#include "ConsoleObject.h"
#include "EngineCore.h"

ConsoleObject::ConsoleObject()
{
}

ConsoleObject::ConsoleObject(const Point& _StartPos, char _Renderchar)
	: Pos(_StartPos), RenderChar(_Renderchar)
{
}

ConsoleObject::~ConsoleObject()
{
}

ConsoleObject* ConsoleObject::Collision(int _UpdateOrder)
{
	std::list<ConsoleObject*>& ObjectList = GetCore()->AllUpdateObject[_UpdateOrder];
	for (ConsoleObject* Object : ObjectList)
	{
		if (nullptr == Object)
		{
			MsgBoxAssert("Collision Error : Object is Nullptr");
		}

		if (this == Object)
		{
			continue;
		}

		if (GetPos() == Object->GetPos())
		{
			return Object;
		}
	}

	return nullptr;
}

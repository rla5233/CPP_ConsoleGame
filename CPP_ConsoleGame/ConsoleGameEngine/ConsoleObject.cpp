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
	//std::list<ConsoleObject*>& ObjectList = ;

	return nullptr;
}

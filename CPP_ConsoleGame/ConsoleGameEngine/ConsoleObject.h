#pragma once

#include "ConsoleMath.h"
#include "ConsoleUpdater.h"

class ConsoleObject : public ConsoleUpdater
{
	friend class EngineCore;
public:
	// constructor destructor
	ConsoleObject();
	ConsoleObject(const Point& _StartPos, char _Renderchar);

	virtual ~ConsoleObject();

	// delete Function
	ConsoleObject(const ConsoleObject& _Other) = delete;
	ConsoleObject(ConsoleObject&& _Other) noexcept = delete;
	ConsoleObject& operator=(const ConsoleObject& _Other) = delete;
	ConsoleObject& operator=(ConsoleObject&& _Other) noexcept = delete;
	
	///////////////////////////////////////////////////////////////////
	template<typename EnumType>
	ConsoleObject* Collision(EnumType _UpdateOrder)
	{
		return Collision(static_cast<int>(_UpdateOrder));
	}

	ConsoleObject* Collision(int _UpdateOrder);


	// Get
	inline Point GetPos() const
	{
		return Pos;
	}

	inline char GetRenderChar() const
	{
		return RenderChar;
	}

	// Set
	inline void SetPos(const Point& _Pos)
	{
		Pos = _Pos;
	}
	
	inline void AddPos(const Point& _Dir)
	{
		Pos += _Dir;
	}

protected:

private:
	Point Pos = Point::Zero;
	char RenderChar = '@';

};


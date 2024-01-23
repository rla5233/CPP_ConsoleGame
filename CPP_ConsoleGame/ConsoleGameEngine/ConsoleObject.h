#pragma once

#include "ConsoleMath.h"
#include "ConsoleUpdater.h"

class ConsoleObject
{
public:
	// constructor destructor
	ConsoleObject();
	~ConsoleObject();

	// delete Function
	ConsoleObject(const ConsoleObject& _Other) = delete;
	ConsoleObject(ConsoleObject&& _Other) noexcept = delete;
	ConsoleObject& operator=(const ConsoleObject& _Other) = delete;
	ConsoleObject& operator=(ConsoleObject&& _Other) noexcept = delete;

protected:

private:

};


#pragma once

// Ό³Έν :
class ConsoleUpdater
{
public:
	// constructor destructor
	ConsoleUpdater();
	~ConsoleUpdater();
	
	// delete Function
	ConsoleUpdater(const ConsoleUpdater& _Other) = delete;
	ConsoleUpdater(ConsoleUpdater&& _Other) noexcept = delete;
	ConsoleUpdater& operator=(const ConsoleUpdater& _Other) = delete;
	ConsoleUpdater& operator=(ConsoleUpdater&& _Other) noexcept = delete;


protected:

private:

};


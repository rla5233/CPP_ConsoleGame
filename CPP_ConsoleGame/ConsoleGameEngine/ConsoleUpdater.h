#pragma once

// Ό³Έν :
class ConsoleUpdater
{
	friend class EngineCore;
public:
	// constructor destructor
	ConsoleUpdater();
	~ConsoleUpdater();
	
	// delete Function
	ConsoleUpdater(const ConsoleUpdater& _Other) = delete;
	ConsoleUpdater(ConsoleUpdater&& _Other) noexcept = delete;
	ConsoleUpdater& operator=(const ConsoleUpdater& _Other) = delete;
	ConsoleUpdater& operator=(ConsoleUpdater&& _Other) noexcept = delete;
	//////////////////////////////////////////////////////////////////////
	inline bool IsDeath() const
	{
		return DeathValue;
	}

	inline class EngineCore* GetCore() const
	{
		return Core;
	}

	void Death()
	{
		DeathValue = true;
	}

	virtual void Update() {};


protected:

private:
	bool DeathValue = false;
	class EngineCore* Core = nullptr;

	void SetCore(EngineCore* _Core)
	{
		Core = _Core;
	}
};


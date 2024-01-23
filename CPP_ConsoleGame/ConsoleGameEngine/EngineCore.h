#pragma once

#include <map>
#include <list>


class EngineCore
{
	
public:
	// constructor destructor
	EngineCore();
	~EngineCore();

	// delete Function
	EngineCore(const EngineCore& _Other) = delete;
	EngineCore(EngineCore&& _Other) noexcept = delete;
	EngineCore& operator=(const EngineCore& _Other) = delete;
	EngineCore& operator=(EngineCore&& _Other) noexcept = delete;

protected:

private:
	// 관리 감독하는 기능들을 모아둔 map
	//std::map<int, ConsoleUpdater*> AllManager;

};


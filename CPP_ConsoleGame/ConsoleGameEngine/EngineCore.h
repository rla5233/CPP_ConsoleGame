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
	// ���� �����ϴ� ��ɵ��� ��Ƶ� map
	//std::map<int, ConsoleUpdater*> AllManager;

};


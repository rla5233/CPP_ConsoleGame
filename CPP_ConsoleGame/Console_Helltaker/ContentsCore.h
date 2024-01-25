#pragma once
#include <ConsoleGameEngine/EngineCore.h>

// Ό³Έν :
class ContentsCore : EngineCore
{
public:
	// constructor destructor
	ContentsCore();
	~ContentsCore();
	
	// delete Function
	ContentsCore(const ContentsCore& _Other) = delete;
	ContentsCore(ContentsCore&& _Other) noexcept = delete;
	ContentsCore& operator=(const ContentsCore& _Other) = delete;
	ContentsCore& operator=(ContentsCore&& _Other) noexcept = delete;


protected:


private:

};


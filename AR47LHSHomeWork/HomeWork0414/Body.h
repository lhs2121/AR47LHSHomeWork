#pragma once
#include "Parts.h"
#include <GameEngineConsole/ConsoleGameObject.h>

class ConsoleGameScreen;
class Body : public Parts
{
public:
	// constrcuter destructer
	Body();
	~Body();

	// delete Function
	Body(const Body& _Other) = delete;
	Body(Body&& _Other) noexcept = delete;
	Body& operator=(const Body& _Other) = delete;
	Body& operator=(Body&& _Other) noexcept = delete;

	
protected:
	void Update() override;

private:
	
};


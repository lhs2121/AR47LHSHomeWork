#pragma once
#include <GameEngineConsole/ConsoleGameObject.h>


class ConsoleGameScreen;
class Player : public ConsoleGameObject
{
public:
	static bool IsGameUpdate;

public:
	Player();
	void Update() override;

	bool IsBomb(int2 _NextPos);

	bool IsItem(int2 _NextPos);

	void EatItem();

protected:

private:
	int BombPower = 1;
};


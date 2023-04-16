#pragma once
#include "ConsoleGameMath.h"
#include "GameEngineArray.h"
#include <vector>

// 이게 1단계
// 근본오브 근본 수학 물리 
class ConsoleGameScreen
{
public:
	static ConsoleGameScreen& GetMainScreen()
	{
		return MainScreen;
	}

	int2 GetScreenSize();

	void SetScreenSize(int2 _Size);

	void ScreenClear();

	void ScreenPrint() const;

	bool IsScreenOver(const int2& _Pos) const;

	void SetScreenCharacter(const int2& _Pos, char _Ch);

protected:

private:
	GameEngineArray<GameEngineArray<char>> ArrScreen;

	int2 Size;

	ConsoleGameScreen();
	~ConsoleGameScreen();

	static ConsoleGameScreen MainScreen;
};
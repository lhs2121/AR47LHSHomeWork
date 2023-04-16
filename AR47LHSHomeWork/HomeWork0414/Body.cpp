#include "Body.h"
#include "Head.h"
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineConsole/ConsoleObjectManager.h>

Body::Body() 
{
	RenderChar = 'i';

	int X = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().X - 1);
	int Y = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().Y - 1);
	SetPos({ X, Y });

	ConsoleGameObject* head = *(ConsoleObjectManager::GetGroup(0).begin());
	if (head->GetPos() == GetPos())
	{
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos() + int2::Left))
		{
			SetPos(GetPos() + int2::Left);
		}
		else if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos() + int2::Right))
		{
			SetPos(GetPos() + int2::Right);
		}
		else if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos() + int2::Up))
		{
			SetPos(GetPos() + int2::Up);
		}
		else if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos() + int2::Down))
		{
			SetPos(GetPos() + int2::Down);
		}
		
	}
}

Body::~Body() 
{
}

void Body::Update()
{
	ConsoleGameObject::Update();
}
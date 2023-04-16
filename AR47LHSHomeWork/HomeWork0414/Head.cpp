#include "Head.h"
#include "Body.h"
#include "Parts.h"
#include <conio.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineConsole/ConsoleObjectManager.h>


bool Head::IsPlay = true;

Head::Head()
{
	RenderChar = '$';
	SetPos(ConsoleGameScreen::GetMainScreen().GetScreenSize().Half());
}

Head::~Head()
{

}

// 화면바깥으로 못나가게 하세요. 
void Head::Update()
{
	if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos()))
	{
		IsPlay = false;
	}


	if (0 == _kbhit())
	{
		// SetPos(GetPos() + Dir);
		// IsBodyCheck();
		// NewBodyCreateCheck();
		return;
	}

	char Ch = _getch();

	int2 NextPos = { 0, 0 };

	switch (Ch)
	{
	case 'a':
	case 'A':
		Dir = int2::Left;
		break;
	case 'd':
	case 'D':
		Dir = int2::Right;
		break;
	case 'w':
	case 'W':
		Dir = int2::Up;
		break;
	case 's':
	case 'S':
		Dir = int2::Down;
		break;
	case 'q':
	case 'Q':
		IsPlay = false;
		return;
	default:
		return;
	}

	SetPrevPos(GetPos());
	SetPos(GetPos() + Dir);

	if (GetNextParts() == nullptr)
	{
		std::list<ConsoleGameObject*>& bodygroup = ConsoleObjectManager::GetGroup(1);

		for (ConsoleGameObject* ptr : bodygroup)
		{
			if (ptr != nullptr && ptr->GetPos() == GetPos())
			{
				SetNextParts((Parts*)ptr);
				GetNextParts()->SetPos(PrevPos);
				ConsoleObjectManager::CreateConsoleObject<Body>(1);
			}
		}
	}
	else
	{
		GetNextParts()->SetPos(PrevPos);
	}
	
	




	if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos()))
	{
		IsPlay = false;
	}



}

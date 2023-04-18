#include "Head.h"
#include <conio.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <list>
#include <GameEngineConsole/ConsoleObjectManager.h>
#include "GameEnum.h"
#include "Body.h"

bool Head::IsPlay = true;

Head::Head()
{
	RenderChar = L'▼';
	SetPos(ConsoleGameScreen::GetMainScreen().GetScreenSize().Half());
}

Head::~Head()
{
}

void Head::ChangeRenderChar()
{
	if (GetPrevPos() == (GetPos() - int2::Left))
	{
		RenderChar = L'◀';
	}
	else if (GetPrevPos() == (GetPos() - int2::Right))
	{
		RenderChar = L'▶';
	}
	else if (GetPrevPos() == (GetPos() - int2::Up))
	{
		RenderChar = L'▲';
	}
	else if (GetPrevPos() == (GetPos() - int2::Down))
	{
		RenderChar = L'▼';
	}
}

void Head::IsBodyCheck()
{
	std::list<ConsoleGameObject*>& BombGroup
		= ConsoleObjectManager::GetGroup(SnakeGameOrder::Body);

	for (ConsoleGameObject* BodyPtr : BombGroup)
	{
		// 터질때가 있습니다.
		if (nullptr == BodyPtr)
		{
			continue;
		}

		int2 BodyPos = BodyPtr->GetPos();
		if (GetPos() == BodyPos)
		{
			Parts* BodyPart = dynamic_cast<Parts*>(BodyPtr);

			if (nullptr == BodyPart)
			{
				MsgBoxAssert("바디그룹 쪽에 바디가 아닌 객체가 들어있었습니다.");
				return;
			}

			Parts* Last = GetLast();

			//int2 PrevPos = GetPrevPos();
			//BodyPart->SetPos(PrevPos);
			// ??BodyPart
			Last->SetNext(BodyPart);
			ConsoleObjectManager::CreateConsoleObject<Body>(SnakeGameOrder::Body);
			return;
		}
	}
}

void Head::NewBodyCreateCheck()
{

}

// 화면바깥으로 못나가게 하세요. 
void Head::Update()
{
	this;

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

	// 플레이어의 머리가
	// 이동하는 방향에 따라서 ▲ ▼ ◀ ▶
	// ▶▶▶▶▶▶▶▶

	// ▶▶▶▶▶▶▶
	//            ▼

	// ▶▶▶▶▶▶
	//          ▼
	//          ▼

	// 이게 되었다면 2번째 숙제로
	// 

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

	// 내가 이렇게 움직였다고 치겠습니다.



	SetPos(GetPos() + Dir);
	IsBodyCheck();

	NextMove();

	//Parts* CurPart = this;
	//while (true)
	//{
	//	Parts* Next = CurPart->GetNext();

	//	if (nullptr == Next)
	//	{
	//		break;
	//	}

	//	Next->SetPos(CurPart->GetPrevPos());
	//	CurPart = CurPart->GetNext();
	//}

	NewBodyCreateCheck();

	ChangeRenderChar();

	if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos()))
	{
		IsPlay = false;
	}




}

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
	RenderChar = L'��';
	SetPos(ConsoleGameScreen::GetMainScreen().GetScreenSize().Half());
}

Head::~Head()
{
}


void Head::IsBodyCheck()
{
	std::list<ConsoleGameObject*>& BombGroup
		= ConsoleObjectManager::GetGroup(SnakeGameOrder::Body);

	for (ConsoleGameObject* BodyPtr : BombGroup)
	{
		// �������� �ֽ��ϴ�.
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
				MsgBoxAssert("�ٵ�׷� �ʿ� �ٵ� �ƴ� ��ü�� ����־����ϴ�.");
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

// ȭ��ٱ����� �������� �ϼ���. 
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

	// �÷��̾��� �Ӹ���
	// �̵��ϴ� ���⿡ ���� �� �� �� ��
	// ����������������

	// ��������������
	//            ��

	// ������������
	//          ��
	//          ��

	// �̰� �Ǿ��ٸ� 2��° ������
	// 

	int2 NextPos = { 0, 0 };

	switch (Ch)
	{
	case 'a':
	case 'A':
		Dir = int2::Left;
		RenderChar = L'��';
		break;
	case 'd':
	case 'D':
		Dir = int2::Right;
		RenderChar = L'��';
		break;
	case 'w':
	case 'W':
		Dir = int2::Up;
		RenderChar = L'��';
		break;
	case 's':
	case 'S':
		Dir = int2::Down;
		RenderChar = L'��';
		break;
	case 'q':
	case 'Q':
		IsPlay = false;
		return;
	default:
		return;
	}

	// ���� �̷��� �������ٰ� ġ�ڽ��ϴ�.



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

	if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos()))
	{
		IsPlay = false;
	}




}

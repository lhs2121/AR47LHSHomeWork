// HomeWork0414.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineConsole/ConsoleGameObject.h>
#include <GameEngineConsole/ConsoleObjectManager.h>
#include "Head.h"
#include "Body.h"
#include <conio.h>

int main()
{
	GameEngineDebug::LeckCheck();

	int2 ScreenSize = { 9, 9 };
	ConsoleGameScreen::GetMainScreen().SetScreenSize(ScreenSize);

    Head* h = ConsoleObjectManager::CreateConsoleObject<Head>(0);

	Body* b = ConsoleObjectManager::CreateConsoleObject<Body>(1);
	
	

	while (true == Head::IsPlay) 
	{
		ConsoleObjectManager::ConsoleAllObjectUpdate();
		ConsoleObjectManager::ConsoleAllObjectRender();
		ConsoleObjectManager::ConsoleAllObjectRelease();

		printf("head.prevPos.X : %d\n head.prevPos.Y : %d\n\n", h->GetPrevPos().X, h->GetPrevPos().Y);
		printf("head.pos.X : %d\n head.pos.Y : %d\n\n", h->GetPos().X, h->GetPos().Y);

		printf("bullet.prevPos.X : %d\n bullet.prevPos.Y : %d\n\n", b->GetPrevPos().X, b->GetPrevPos().Y);
		printf("bullet.pos.X : %d\n bullet.pos.Y : %d\n\n", b->GetPos().X, b->GetPos().Y);
		Sleep(200);
	}

	ConsoleObjectManager::ConsoleAllObjectDelete();
}

// 1번째 
// 바디는 플레이어와 플레이어를 따라다니는 
// 바디가 존재하지 않는 공간에 만들 방법을 생각해 내야 합니다.
// 추천 벡터를 이용해라.
// 빈공간이 나올때가지 랜덤돌린다 <= 최악의 선택
// ConsoleObjectManager::CreateConsoleObject<Body>(1);
// 주의사항 절대 클리어 못하는 상황이 나오는데 이건 처리 안해도 됩니다.

// 2번째 플레이어 먹으면 아이템은 몸통으로 뒤따라오게 만들고
// 그때 모양이 바뀝니다.

// 3번째 다 먹고 화면을 꽉채우는 순간이 온다.
// 아이템을 먹고 뱀의 몸통으로 화면을 꽉채우는 순간 게임이 종료되고 축하메세지 출력하게 하세요.

// 4번째 몸통을 통과하지 못합니다.
// 플레이어가 몸통이랑 충돌하면 종료되게 하세요.
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
#include "GameEnum.h"
#include <conio.h>

int main()
{
	//while (true)
	//{
	//	printf_s("%d\n", GameEngineRandom::MainRandom.RandomInt(0, 100));
	//}

	GameEngineDebug::LeckCheck();

	int2 ScreenSize = { 10, 5 };
	ConsoleGameScreen::GetMainScreen().SetScreenSize(ScreenSize);

	ConsoleObjectManager::CreateConsoleObject<Head>(SnakeGameOrder::Head);



	// 1번째 
	// 바디는 플레이어와 플레이어를 따라다니는 
	// 바디가 존재하지 않는 공간에 만들 방법을 생각해 내야 합니다.
	// 추천 벡터를 이용해라.
	// 빈공간이 나올때가지 랜덤돌린다 <= 최악의 선택
	ConsoleObjectManager::CreateConsoleObject<Body>(SnakeGameOrder::Body);
	// 주의사항 절대 클리어 못하는 상황이 나오는데 이건 처리 안해도 됩니다.

	// 2번째 플레이어 먹으면 아이템은 몸통으로 뒤따라오게 만들고
	// 그때 모양이 바뀝니다.

	// 3번째 다 먹고 화면을 꽉채우는 순간이 온다.
	// 아이템을 먹고 뱀의 몸통으로 화면을 꽉채우는 순간 게임이 종료되고 축하메세지 출력하게 하세요.

	// 4번째 몸통을 통과하지 못합니다.
	// 플레이어가 몸통이랑 충돌하면 종료되게 하세요.

	while (true == Head::IsPlay)
	{
		ConsoleObjectManager::ConsoleAllObjectUpdate();
		ConsoleObjectManager::ConsoleAllObjectRender();
		ConsoleObjectManager::ConsoleAllObjectRelease();
		Sleep(200);
	}

	ConsoleObjectManager::ConsoleAllObjectDelete();
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.

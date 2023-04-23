// GameEngineMap.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <map>
#include <list>
#include "GameEngineMap.h"


int main()
{
    GameEngineMap map;


    map.insert(GameEnginePair(20,0));
    map.insert(GameEnginePair(15, 0));
    map.insert(GameEnginePair(28, 0));
    map.insert(GameEnginePair(10, 0));
    map.insert(GameEnginePair(17, 0));
    map.insert(GameEnginePair(4, 0));
    map.insert(GameEnginePair(12, 0));
    map.insert(GameEnginePair(19, 0));
    map.insert(GameEnginePair(26, 0));
    map.insert(GameEnginePair(33, 0));
    map.insert(GameEnginePair(30, 0));
    map.insert(GameEnginePair(35, 0));
    
    map.DeleteOrder();
}


// Map.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <map>
#include "GameEngineMap.h"
int main()
{
    {
        std::map<int, int> map;
        map.insert(std::make_pair(1, 0));

    }
    GameEngineMap map1;

    map1.insert(pair(5, 0));
    map1.insert(pair(15, 0));
    map1.insert(pair(4, 0));
    map1.insert(pair(1, 0));
   
}


// Map.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <map>
#include "GameEngineMap.h"
int main()
{
    {
        std::map<int, int> map;
        
    }

    GameEngineMap map1;



    map1.insert(pair(5, 0));
    map1.insert(pair(2, 0));
    map1.insert(pair(4, 0));
    map1.insert(pair(3, 0));
    map1.insert(pair(1, 0));
   
    GameEngineMap::iterator iter = map1.begin(); //1

    std::cout << iter.CurNode->Pair.first << std::endl;
    iter.operator++(); 
    std::cout << iter.CurNode->Pair.first << std::endl;
    iter.operator++();
    std::cout << iter.CurNode->Pair.first << std::endl;

    iter.operator++();
    std::cout << iter.CurNode->Pair.first << std::endl;
    iter.operator++();
    std::cout << iter.CurNode->Pair.first << std::endl;

   
    
    
}


#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int p = 0,y = 0;
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    for (char S:s){
        if (S=='P'|S=='p'){p++;}
        if (S=='Y'|S=='y'){y++;}
    }

    return p==y;
}
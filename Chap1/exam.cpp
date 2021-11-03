
/*
1. 입력 및 출력 기능은 언어의 핵심 부분은 아니나 라이브러리로 제공
2. 표준 I/O는 스트림 모델을 가지며, #include <iostream> 첫줄에서 이렇게 불러야함 
3. main 함수 호출로 시작 >> 종료시 return 0[성공적인 종료를 나타냄]
4. {} >> 코드 블록
5. std::cout >> 화면에 출력하는 스트림. 종료는 std::endl 연산자 >> : std::cout와 같은 출력 스트림에 개체 전달
6. std : 표준 네임스페이스[이름을 구성, 충돌 문제 처리]에서 사용된 타입이나 함수를 의미
7. "" :문자열 상수는 큰따옴표(작은따옴표 하면 error: warning: character constant too long for its type)
8. c++은 type에 민감한데 추론 가능...
*/
#include <iostream>

using namespace std; 

int main()
{
    cout << "The answer to the Ultimate Question of Life, \n"
    << "the Universe, and Everything is: "<< endl 
    << 6*7 <<endl;

    return 0;
}



/*
변수

cpp는 변수 type에 엄격 >> 모든 변수는 type을 가지며 한 번 정해지면 절대 안바뀜

char > short > int > long > long long : 하나의 문자나 매우 좁은 법위를 갖는 정수
char : 좁은 범위 숫자 + 문자 표현 가능 

float >> double >> long double : 소숫점 범위
*/

#include <iostream>

using namespace std;

int main()
{
    // signed int i1 = -2;
    // int a; // initial value 들어가네
    // long i2,i3 = 5;
    // float pi = 3.14;
    // double x = -1.5e6;
    // double y = -1.5e-6;
    // const char *c1 = "a" ;
    // char y = 'abc';  >>> error '는 문자만 가능[길이가 1인]
    // char y = 'a';
    // bool cmp = i1 <pi,
    // happy = true;
    // cout << i1  << i2  << c1  << y  << a << endl;

    // const int x = 3; >> 이걸로 x++하면 안됨..


    // int x = 3;
    // x++;

    // long x = 1234567890123; >> 범위 초과.. 1912276171로 값이 변경됨
    // long long x = 1234567890123; // 값 변경 없음.
    // long x = {1234567890123}; // 값 변경 없음.

    // int x = 3.14; >> 3
    // int x = {3.14}; >> 소수 부분 사라짐.

    // {
    //     int x = 3; >> cout 안됨. 'x' was not declared in this scope
    // }

    // i = j = 4 k = 8 l = 7
    // int i = 3, j = 3;
    // int k = ++i + 4;
    // int l = j++ + 4;

    // cout << i << endl;
    // cout << j << endl;
    // cout << k << endl;
    // cout << l << endl;
    return 0;
}
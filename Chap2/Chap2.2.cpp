/*
래퍼런스 vs 포인터

공통점 : 다른 변수의 주소값을 보관함으로써 해당 변수에 간접적으로 연산을 수행 가능

다른점 : 

1. 래퍼런스는 누구의 별명인지 명시(즉 int& a >> error; int* a >> 가능)

2. 한번 정의되면 바꿀 수 없음(포인터는 주소값 변경 가능)

3. 메모리 x (항상은 아님.) >> 포인터는 메모리 차지 
*/
# include <bits/stdc++.h>

using namespace std;

int main(){
    int a = 3, b = 5;
    int* p = &a;

    // int& b ; 래퍼런스는 누구의 별명인지 명시
    int& another_a = a;


/////////////////////////////////////////
    // another_a = 5;
    // cout << a << endl; // 5
    // cout << another_a << endl;// 5
    
    // cout << &a << endl; // 0x61ff08
    // cout << &another_a << endl;// 0x61ff08 
//////////////////////////////////////////

//한번 정의되면 바꿀 수 없음 >> 값은 바뀌는 데 주소는 바뀌지 않음.

    // another_a = &b; // nvalid conversion from 'int*' to 'int'
    // another_a = b;
    // cout << a << endl; // 5
    // cout << another_a << endl;// 5
    // cout << b << endl; // 5

    // cout << &a << endl; // 0x61ff08
    // cout << &another_a << endl;// 0x61ff08 
    // cout << &b << endl;// 0x61ff04 

    cout << p << endl;  // 0x61ff04
    cout << &a << endl; // 0x61ff04
    cout << &b << endl; // 0x61ff00
    cout << &another_a <<endl; // 0x61ff04

    p = &b;
    cout << p << endl;  // 0x61ff00
    cout << &a << endl; // 0x61ff04
    cout << &b << endl; // 0x61ff00

}

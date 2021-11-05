# include <bits/stdc++.h>

using namespace std;

// int ftn(){
//     int a = 2;
//     return a;
// }

// int main(){
//     int b = ftn();

//     cout << b <<endl;

//     cout << &b <<endl; // 0x61ff0c
//     cout << &ftn <<endl; // 1 >> 왜 1이지..
    
//     return 0;
// }

// int& ftn() 은 래퍼런스를 리턴하는 함수인데 return 값이 a 즉 지역변수임.. 따라서 함수가 종료되면 a는 사라져서 return 값이 문제가됨.
// 외부변수를 받아서 래퍼런스를 리턴하는 것은 문제되지 않음.
// 참조자 리턴하는 경우의 장점. >> 래퍼런스가 참조하는 타입의 크기와 상관없이 딱 한번의 주소값 복사로 전달 완료 >
// int& ftn(){
//     int a = 2;
//     return a;
// }

// int main(){
//     int b = ftn();
//     b = 3;
//     return 0;
// }


int ftn(){
    int a = 3;
    
    cout << &a << endl;
    return a;
}

int main(){
    const int& b = ftn();

    cout << &b << endl;
    // cout << sizeof(a) << endl;
}
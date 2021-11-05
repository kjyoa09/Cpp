# Cpp
## 씹어먹는 C++with(모던 C++ 입문)
### Chap 1 : Intro

### Chap 2 : C++ 참조자(레퍼런스의 도입)

1. 참조자(레퍼런스)

- 변수나 상수를 가르키는 방법(포인터와 비슷) >> 별명 만드는 것 >> 같은 주소값 공유

- 참조자의 참조자, 참조자의 배열, 참조자의 포인터 불가능

'''

    int& arr[2] = {a,b}; >> error

    int arr[2] = {a,b};
    int (&ref)[2] = arr;

    cout << &a << endl; //0x61ff08
    cout << &arr[0] << endl; //0x61fefc
    cout << &ref[0] << endl;//0x61fefc

    cout << &b << endl; //0x61ff04
    cout << &arr[1] << endl;//0x61ff00
    cout << &ref[1] << endl;//0x61ff00
    
'''
- 레퍼런스 리턴하는 함수

    Case1 : 외부 변수를 받아서 레퍼런스 리턴 >> 가능

    Case2 : 함수 내 지역변수 레퍼런스 리턴 >> 불가능

    Case3 : 함수 지역변수를 외부에서 레퍼런스로 받기 >> 가능(다만 const 참조자로 받아야함) 

    int ftn(){
        int a = 3;
        
        cout << &a << endl; // 0x61fedc
        return a;
    }

    int main(){
        const int& b = ftn();

        cout << &b << endl; // 0x61ff08
        // cout << sizeof(a) << endl; >> error
    }

2. 참조자 vs 포인터

- 참조자는 처음 정의할 때, 값을 정확하게 명시 (int& p = a;) 포인터는 아님(int* p; 가능)

- 참조자는 주소값을 바꿀 수 없음.(처음 명시한 주소값 계속 가지고 감) 포인터는 변경 가능.

- 참조자는 메모리 상에 존재하지 않을 수도 있다. >> 포인터는 메모리 차지.


## Coding Test
### programmers
#### level 1
##### 21.11.04 ~
### Boj
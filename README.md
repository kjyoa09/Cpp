# Cpp
## 씹어먹는 C++with(모던 C++ 입문)
### Chap 1 : Intro

### Chap 2 : C++ 참조자(레퍼런스의 도입)

1. 참조자(레퍼런스)

- 변수나 상수를 가르키는 방법(포인터와 비슷) >> 별명 만드는 것 >> 같은 주소값 공유

- 참조자의 참조자, 참조자의 배열, 참조자의 포인터 불가능



        int& arr[2] = {a,b}; >> error

        int arr[2] = {a,b};
        int (&ref)[2] = arr;

        cout << &a << endl; //0x61ff08
        cout << &arr[0] << endl; //0x61fefc
        cout << &ref[0] << endl;//0x61fefc

        cout << &b << endl; //0x61ff04
        cout << &arr[1] << endl;//0x61ff00
        cout << &ref[1] << endl;//0x61ff00
    

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

### Chap 3 : 메모리 관리

1. new & delete

        int main(){
            int *p = new int;
            *p = 10;

            cout << *p << endl;
            cout << &p << endl;

            delete p;
            return 0;        
        }


    new >> int 크기의 공간을 할당하여 그 주소값을 p에 넣음.

    delete >> 할당된 공간 해제(new를 통해 할당한 공간만 가능)

        int main(){
            int p = 10;

            cout << p << endl;
            cout << &p << endl;

            delete p; //>> error
            delete &p; //>> 가능하긴 한데 Heap이 아닌 공간을 해제한다는 경고 메세지;;; >> 컴파일러에 따라 다른가..?
            return 0;
            }


2. new로 배열 할당하기

        int main(){
            int arr_size;

            cout << "arr size : ";
            cin >> arr_size;
            
            int *list = new int[arr_size];
            for (int i = 0; i < arr_size; i++){
                cin >> list[i]; // >> for 문 안에서 int i를 선언해서 cin을 활용하여 list를 받음.. >> i 는 external에서 사용할 수 없음(python은 가능했던 것 같음..)
            }
        
            for (int i = 0; i < arr_size; i++){
                cout << i << "th element of list : " << list[i] << endl;
            }

            delete list;
            cout << &list << endl; // 0x61ff00
            cout << list[0] << endl; // 16777408
            
            return 0;
        }


3. 참고
    굳이 같은 이름으로 변수를 만들지는 말자....
    
        int main(){
            int a = 4;
            {
                cout << "external a : " << a << endl; // 0x61ff0c
                cout << "external a : " << &a << endl; //4
                int a = 3; // > 이 선언으로 외부 변수 a는 가려짐
                cout << "Internal a : " << a << endl;//0x61ff08
                cout << "Internal a : " << &a << endl; // 3
            }   // > 중괄호를 벗어나면서 내부 변수 a 삭제 >> 가려진 외부 변수 a가 드러남.
            cout << "external 2 : " << a << endl;//0x61ff0c
            cout << "external 2 : " << &a << endl; // 4
            return 0;
        }
## Coding Test
### programmers
#### level 1
##### 21.11.04 ~ 21.11.07
#### level 2
##### 21.11.08 ~ 
### Boj
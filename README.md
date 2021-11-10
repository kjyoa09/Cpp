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

### Chap 4 : 객체 지향 프로그래밍

1. 객체란?
    
    변수들과 참고 자료들로 이루어진 소프트웨어 덩어리.

        typedef struct Animal{
            char name[30]; // 이름
            int age; // 나이

            int health // 체력
            int food // 배부른 정도
            int clean // 청결 상태
        } Animal;

        play(list[play_with])

    play 함수에 인자로 전달하는 것이 불필요해보임

        Animal animal;
        animal.play();
        animal.sleep();
    
    이런식으로 코딩하는 것이 좀더 좋지 않을까? >> 즉 객체 자체가 자신의 정보[인스턴스 변수]를 적절한 처리[인스턴스 메소드]를 할 수 있는 

    특징 :
        캡슐화 >> 객체의 인스턴스 변수에 직접 접근하지 못함 즉 인스턴스 메소드를 통해 간접으로 조절해야 함

            animal.food += 100; // X
            animal.increase_food(100); // O
    
    클래스 >> 설계도
        
     
        class Animal{
            private: // 자기 객체 안에서만 접근 가능 >> 외부에서는 불가능
                int food; // 맴버 변수
                int weight;// 맴버 변수
            
            public:// 외부에서도 접근 가능.
            
                void set_animal(int _food, int _weight){// 맴버 함수
                    food = _food;
                    weight = _weight;
                }
                
                void increase_food(int inc){
                    food += inc;
                    weight += (inc/3);
                }

                void view_stat(){
                    cout << "이 동물의 food : " << food << endl;
                    cout << "이 동물의 weight : " << weight << endl; 
                }
        };

        int main(){
            Animal animal;
            animal.set_animal(100,50);
            animal.increase_food(30);

            animal.view_stat();
            return 0;
        }

2. 함수의 오버로딩(Overloading)

    - C에서는 같은 함수 이름을 갖을 수 없음 >> C++에서는 가능[함수의 인자를 보고 판단] : 함수의 이름이 같더라도 인자가 다르면 다른 함수라 판단.

            #include <iostream>
            
            void print(int x){std::cout << "int : " << x << std::endl;}
            //void print(int x){std::cout << "int : " << x << std::endl;} error:: 'void print(int)' previously defined here
            void print(char x){std::cout << "char : " << x << std::endl;}
            void print(double x){std::cout << "double : " << x << std::endl;}

            int main(){
                print(1); // int : 1
                print('a');//char : a >>print(char x)없으면 int : 99 [최대한 비슷한 인자 함수로 호출]
                print(1.1);//double : 1.1
                return 0;
            }

    - 단계 >> 아래 과정을 전부 진행해도 맞는 타입이 없거나 같은 단계에서 두개 이상에 조건 이상이 만족하는 경우 ambiguous error

        1) 자신과 타입이 정확히 일치하는 함수
        2) 1단계를 만족하는 함수가 없을 경우 
            - Char, Unsigned char, short >> int 변환
            - Unsigned short는 int의 크기에 따라 int 혹은 Unsigned int로 변환
            - Float은 double
            - Enum은 int 변환
        3) 2단계도 만족하는 함수가 없을 경우
            - 임의의 숫자 타입은 다른 숫자 타입으로 변환 (float -> int)
            - Enum도 임의의 숫자 타입으로 변환
            - 0은 포인터 타입이나 숫자 타입으로 변환된 0은 포인터 타입이나 숫자 타입으로 변환
            - 포인터는 void 포인터로 변환
        4) 유저 정의된 타입 변환으로 일치하는 것을 찾는다


                // 오류 안 나는데;;

                #include <iostream>

                //void print(int x){std::cout << "int : " << x << std::endl;}
                //void print(int x){std::cout << "int : " << x << std::endl;}
                void print(char x){std::cout << "char : " << x << std::endl;}
                // void print(double x){std::cout << "double : " << x << std::endl;}

                int main(){
                    int a = 1;
                    char b = 'c';
                    double c = 3.2f;

                    print(a);
                    print(b);
                    print(c);
                    return 0;}

    - Class >> 굳이 class 내부에서 정의하지 않고 밖에서도 할 수 있음

    - 디폴트 생성자(Default constructor)

        명시적으로 정의하지 않았을 경우 컴파일러가 자동으로 추가해주는 생성자

            class Date{
                private:
                    int year_;
                    int month_;
                    int day_;

                public:
                    void SetDate(int year, int month, int date);
                    void AddYear(int inc);
                    void Addmonth(int inc);
                    void Addday(int inc);
                    void ShowDate();
                    
                    int getCurrentMonthToalDays(int year, int month);

                // 생성자 (constructor) >> 객체 생성시 자동으로 호출되는 함수.
                Date(int year, int month, int day){
                    year_ = year;
                    month_ = month;
                    day_ = day;
                } 

            };

3. 소멸자와 복사 생성자

        #include <string.h>
        #include <iostream>

        using namespace std;

        class Marine{
            int hp;
            int coord_x,coord_y;
            int damage;
            bool is_dead;
            char* name;

            public:
                Marine();
                Marine(int x, int y, const char* marine_name);
                Marine(int x, int y);
                ~Marine();

                int attack();
                void be_attacked(int damage_earn);
                void move(int x, int y);

                void show_status();
        };

        Marine::Marine(){
            hp = 50;
            coord_x = coord_y = 0;
            damage = 5;
            is_dead = false;
            name = NULL;
        }
        Marine::Marine(int x, int y, const char* marine_name){
            // > 직접 delete 해줘야함  >> marine이 죽어서 delete 될 때, 같이 안사라짐. >> 소멸자(Destructor) 생성해야함.
            name = new char[strlen(marine_name) + 1]; 
            strcpy(name,marine_name);
            hp = 50;
            coord_x = x;
            coord_y = y;
            damage = 5;
            is_dead = false;

        }
        void Marine::move(int x, int y){
            coord_x = x;
            coord_y = y;
        }
        int Marine::attack(){return damage;}
        void Marine::be_attacked(int damage_eran){
            hp -= damage_eran;
            if (hp <=0 ){is_dead = true;}
        }
        void Marine::show_status(){
            cout << "*** Marine : ***" << name << endl;
            cout << "Location : ( " <<coord_x << ", " << coord_y << " )" << endl;
            cout << " HP : " << hp << endl;
        }
        // 생성자가 Class 이름과 같다면 ~만 붙여주면 됨.
        Marine::~Marine(){ 
            cout << name << " Destructor" << endl;
            if (name != NULL){
                delete[] name;
            }
        }

        // int main(){
        //     Marine marine1(2,3);
        //     Marine marine2(3,5);

        //     marine1.show_status();
        //     marine2.show_status();

        //     marine2.be_attacked(marine1.attack());

        //     marine1.show_status();
        //     marine2.show_status();

        // }

        int main(){
            Marine* marines[100];
            
            // > new는  동시에 생성자도 호출.
            marines[0] = new Marine(2,3, "Marine 2"); 
            marines[1] = new Marine(3,5, "Marine 1");
            
            // marines[0].show_status() 는 안됨. pointer 라
            marines[0] -> show_status(); 
            marines[1] -> show_status();

            marines[0] -> be_attacked(marines[1] -> attack());

            marines[0] -> show_status();
            marines[1] -> show_status();

            delete marines[0];
            delete marines[1];

            return 0;
        }

        /*
        A : a : Test a('a')
        A : b : Simple_test()
        B : b : Simple_test 지역이 사라지면서 소멸자 호출
        B : a : Main 함수 소멸과 함께 소멸자 호출 

        */

        #include <string.h>
        #include <iostream>

        using namespace std;
        class Test{
            char c;

            public:
                Test(char _c){
                    c = _c;
                    cout << "A : " << c << endl;
                }

                ~Test(){cout << "B : "<< c << endl;} 
        };

        void simple_test(){Test b('b');}
        int main(){
            Test a('a');
            simple_test();
        }

## Coding Test
### programmers
#### level 1
##### 21.11.04 ~ 21.11.07
#### level 2
##### 21.11.08 ~ 
### Boj
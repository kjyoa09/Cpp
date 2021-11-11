#include <iostream>

using namespace std;

class A{
    int x = 1;

    public:
        A(int c) : x(c){};

        int& access_x(){return x;} // ref 리턴
        int get_x(){return x;} // 값 리턴
        void show_x(){cout << x << endl;}
};

int main(){
    A a(5);
    a.show_x();

    int& c = a.access_x(); // ref 리턴한 것을 ref로 받음
    c = 4; // return 된 ref를 바꿔서 객체 내부 값도 변화
    a.show_x();

    int d = a.access_x(); // ref 리턴한 것을 값만 받음.
    d = 3;
    a.show_x(); 

    // 오류
    // int& e = a.get_x(); // 값을 리턴 받는건 ref로 받음. >> 오류
    // e = 2;
    // a.show_x();

    int f =a.get_x();
    f = 1;
    a.show_x();}
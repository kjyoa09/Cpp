/*
A : a : Test a('a')
A : b : Simple_test()
B : b : Simple_test 지역이 사라지면서 소멸자 호출
B : a : Main 함수 소멸과 함께 소멸자 호출 

Default 소멸자.. > 어떻게 작동함,..?
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
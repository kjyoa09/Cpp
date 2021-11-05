# include <bits/stdc++.h>

using namespace std;

int change_val(int *p){
    *p = 3;
    return 0;
}

int change_value(int p){
    p = 3;
    return p;
}


int main(){
    int number = 5,num = 5;

    cout << number << endl; // >> 5
    
    cout << &number << endl; // >> 0x61ff0c : &변수 하면 변수가 저장된 주소 나옴..

    // cout << *number << endl; // invalid type argument of unary '*'
    
    // change_val(number); >> error: invalid conversion from 'int' to 'int*'
    
    change_val(&number); // >> 3 : chage_val에 주소값을 전달 >> *p를 통해 number 참조 >> number 값 변환

    cout << number << endl;


    cout << num << endl; // >> 5
    
    cout << &num << endl; // >> 0x61ff08  

    num = change_value(num); // >> 3 

    // num = change_value(&num); // invalid conversion from 'int*' to 'int' >> int 가 아니라 주소 들어가서 그런듯

    cout << num << endl;
   
}
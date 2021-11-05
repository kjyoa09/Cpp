# include <bits/stdc++.h>

using namespace std;

int main(){
    int x;
    int &y = x, &z = y;  // 참조자의 참조자는 C++에서 금지 >> z는 x의 참조자.

    // int& y = x;
    // int& z = y;

    x = 1;
    cout << "x : " << x <<" y : "<< y<< " z : " << z <<endl;

    y = 2;
    cout << "x : " << x <<" y : "<< y<< " z : " << z <<endl;
    
    z = 3;
    cout << "x : " << x <<" y : "<< y<< " z : " << z <<endl; 

}
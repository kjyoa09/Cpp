# include <bits/stdc++.h>

using namespace std;

int main(){
    const int &ref = 4;

    int a = ref;

    cout << &ref << endl; // 0x61ff08
    cout << ref << endl;
    cout << &a << endl; // 0x61ff04

}
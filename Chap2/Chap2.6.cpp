# include <bits/stdc++.h>

using namespace std;

// 래퍼런스의 배열, 래퍼런스의 래퍼런스, 래퍼런스의 포인터는 존재할 수 없다 >> 래퍼런스는 항상 주소값(메모리 상에 존재하지 않기 때문..)

// int main(){
//     // int arr[3] = {1,2,3};
//     // int (&ref)[3] = arr; 

//     int arr[3][2] = {1,2,3,4,5,6};
//     int (&ref)[3][2] = arr;
//     // int *ref = arr; >> 포인터는 배열의 크기 명시 안해줘도 됨.

//     ref[0][0] = 2;
//     ref[0][1] = 3;
//     ref[0][2] = 1;

//     cout << ref[0][0] << endl;
//     cout << ref[0][1] << endl;
//     cout << ref[0][2] << endl;
//     return 0;
// }

int main(){
    int a=1,b=3;
    // int& arr[2] = {a,b};
    int arr[2] = {a,b};
    int (&ref)[2] = arr;

    cout << &a << endl; //0x61ff08
    cout << &arr[0] << endl; //0x61fefc
    cout << &ref[0] << endl;//0x61fefc

    cout << &b << endl; //0x61ff04
    cout << &arr[1] << endl;//0x61ff00
    cout << &ref[1] << endl;//0x61ff00

    return 0;
}
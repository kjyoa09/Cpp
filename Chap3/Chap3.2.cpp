# include <iostream>

using namespace std;


int main(){
    int arr_size;
    cout << "arr size : ";
    cin >> arr_size;
    int *list = new int[arr_size];
    for (int i = 0; i < arr_size; i++){
        cin >> list[i]; 
    }
    
    for (int i = 0; i < arr_size; i++){
        cout << i << "th element of list : " << list[i] << endl;
    }

    delete list;
    cout << &list << endl; // 0x61ff00
    cout << list[0] << endl; // 16777408
    
    return 0;
}


/*
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
*/
# include <bits/stdc++.h>

using namespace std;

int chage_val(int &p){ 
    // int &p : 래퍼런스는 누구의 별명인지 명시를 안함 >> 근데 되는 이유는 change_val을 호출할 때, 정의됨 >> 따라서 int &p = number효과.
    // *p = 3; 과는 다르게 &p = 3; 이 아님.
    p = 3;
    return 0;
}

/*
Chap 2.1

int change_val(int *p){
    *p = 3;
    return 0;
}
*/
int main(){
    int number = 5;

    cout << number << endl;
    chage_val(number);
    cout << number << endl;
}
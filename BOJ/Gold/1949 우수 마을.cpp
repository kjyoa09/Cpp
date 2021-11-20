#include <iostream>

using namespace std;

int a = 3;
int p(const int a,const  int b){
    a++;
    return a + b;
}

int main(){
    int b = 4;

    cout << p(a,b) << endl;
}
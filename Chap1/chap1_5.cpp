#include <iostream>

using namespace std;

// void f(const int& i){ //>> n : 4
void f(int i){     // n : 3
    i++;
}

int main(){
    int n = 3;
    f(n);
    cout << n << endl;
    return 0;
}

# include <iostream>

using namespace std;

/*
int main(){
    int *p = new int;
    *p = 10;

    cout << *p << endl;
    cout << &p << endl;

    delete p;
    return 0;
    
}
*/

int main(){
    int p = 10;

    cout << p << endl;
    cout << &p << endl;

    delete &p;
    return 0;
    
}
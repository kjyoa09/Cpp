#include <iostream>

using namespace std;

int main(void) {
    int a;
    int b;
    cin >> a >> b;
    
    string tmp;
    for (int c = 1; c<=a; c++){
        tmp += '*';// cpp 도 string + 가능
    }
    
    for (int r = 1; r <= b ; r++){
        cout << tmp << endl;
    }

    return 0;
}

/*
#include <iostream>

using namespace std;

int main(void) {
    int a;
    int b;
    cin >> a >> b;

    for (int r = 1; r <= b ; r++){
        for (int c = 1; c <= a; c++){
            cout << '*';
        }
        cout << endl;
    }

    return 0;
}

*/
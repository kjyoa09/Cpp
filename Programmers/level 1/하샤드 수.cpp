#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    const int y = x;
    int n = 0;
    while (x != 0){
        int tmp = x%10;
        x = (int)x/10;
        n += tmp;
    }
    
    if (y%n == 0){
        return true;
    }
    else {
        return false;
    }

}
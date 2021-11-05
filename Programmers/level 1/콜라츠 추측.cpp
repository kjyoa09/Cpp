#include <string>
#include <vector>
#include <iostream>

using namespace std;


int solution(int num) {
    long long number = num; // 계산하다보면 int 범위 넘어감

    for(int cnt = 0; cnt < 500 ; cnt ++){
        if (number == 1){
            return cnt;
        }
        else{
            number = number%2 ? 3*number+1:(long long )number/2;
        }
    }
    return -1;
}
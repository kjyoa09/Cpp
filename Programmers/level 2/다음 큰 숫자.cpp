#include <string>
#include <vector>

using namespace std;

int checkbit(int n){
    int cnt = 0 , bit = 0;
    while (1<<bit < n){
        if (n & 1<<bit){cnt++;}
        bit ++;
    }
    return cnt;
}
int solution(int n) {
    int cnt = checkbit(n);
    
    while(true){
        n++;
        if (checkbit(n) == cnt){return n;}
    }
 }
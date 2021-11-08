#include <vector>
using namespace std;

int solution(int n) {
    vector<int> tmp = {0,1};
    for (int i = 1; i < n; i++){
        tmp = {tmp[1],(tmp[0]+tmp[1])%1234567};
    }
    return tmp[1]%1234567;
}
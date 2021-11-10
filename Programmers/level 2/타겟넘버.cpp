#include <vector>

using namespace std;
int t, ans = 0;
vector<int> num;

void dfs(int idx, int v){
    if (num.size() == idx){
        if (t == v){
            ans++;}
    }
    else {
        dfs(idx+1,v+num[idx]);
        dfs(idx+1,v-num[idx]);
    }
}
int solution(vector<int> numbers, int target) {
    t = target;
    num = numbers;
    dfs(0,0);
    return ans;
}
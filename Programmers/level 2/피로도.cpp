#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    vector<int> tmp;
    queue<vector<int>> que;
    que.push({k,0,0});
    while (!que.empty()){
        tmp = que.front();
        que.pop();
        
        for (int i = 1; i <= dungeons.size(); i++){
            if (tmp[1]&1<<i || dungeons[i-1][0] > tmp[0]){continue;}
            que.push({tmp[0] - dungeons[i-1][1],tmp[1]|1<<i,tmp[2]+1});
            answer = tmp[2]+1 > answer ? tmp[2]+1:answer;
        }
    }
    
    return answer;
}
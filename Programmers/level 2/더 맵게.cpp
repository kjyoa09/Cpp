#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int,vector<int>,greater<int>> que;
    int answer = 0;
    for (int s:scoville){que.push(s);}
    while (!que.empty()){
        int f = que.top();
        que.pop();
        if (f > K){return answer;}
        else{
            if (que.empty()){return -1;}
            int s = que.top();
            que.pop();
            que.push(f+2*s);
            answer ++;
        }
    }
    return -1;
}
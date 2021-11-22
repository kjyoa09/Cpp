#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> que;
    int sum = 0,ans=0,idx=0,cnt = truck_weights.size();
    for (int i = 0; i < bridge_length; i++)que.push(0);
    
    while (cnt > 0){
        ans ++;
        if (que.front() != 0){
            sum -= que.front();
            cnt --;
        }
        que.pop();
        
        if (sum + truck_weights[idx] <= weight){
            sum += truck_weights[idx];
            que.push(truck_weights[idx]);
            idx ++;
        }
        else {que.push(0);}
    }
    

    return ans;
}
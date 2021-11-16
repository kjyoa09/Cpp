#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int solution(int N, vector<vector<int>> road, int K) {
    int ans = 0;
    vector<vector<pair<int,int>>> map(N+1,vector<pair<int,int>>(0,{0,0}));
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> que;
    vector<int> TF(N+1,false),dis(N+1,500001);
    que.push({0,1});
    
    for (vector<int> R:road){
        map[R[0]].push_back({R[2],R[1]});
        map[R[1]].push_back({R[2],R[0]});
    }
    
    pair<int,int> tmp;
    while(!que.empty()){
        tmp = que.top();
        que.pop();
        // cout << tmp.first << "  " << tmp.second << endl;
        if (tmp.first > K){return ans;}
        if (not TF[tmp.second]){
            TF[tmp.second] = true;
            dis[tmp.second] = tmp.first;
            ans ++;
            
            for (pair<int,int> next:map[tmp.second]){
                if (TF[next.second] == true || dis[next.second]<=tmp.first + next.first){continue;}
                que.push({tmp.first + next.first,next.second});                
                dis[next.second] = tmp.first + next.first;
            }   
        }        
    }
}
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
        
    queue<pair<int,int>> que;
    map<int,int> cnt;
    vector<int> keys;
    
    for (int i=0;i<priorities.size();i++){
        que.push({i,priorities[i]});
        if (cnt.find(priorities[i]) == cnt.end()){
            keys.push_back(priorities[i]);
        }
        cnt[priorities[i]] ++;
    }
    
    sort(keys.rbegin(),keys.rend());
    int key_idx = 0, ans = 1;
    pair<int,int> tmp;
    
    while (!que.empty()){
        tmp = que.front();
        que.pop();
        // cout << "IDX : " << tmp.first << " V : " << tmp.second <<endl;
        
        if (tmp.second == keys[key_idx]){
            if (tmp.first == location){return ans;}
            else{
                cnt[tmp.second] --;
                ans ++;
                if (cnt[tmp.second] == 0){key_idx ++;}
            }
        }
        else{que.push(tmp);}
    }
}
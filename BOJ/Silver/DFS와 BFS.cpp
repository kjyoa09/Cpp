#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N,M,V;
bool dfs_vist[1001],bfs_vist[1001];
// vector<int> dfs,bfs;
vector<vector<int>> map(1001,vector<int> (0,0));

void dfs(int now){
    dfs_vist[now] = true;
    cout << now << " ";
    for (int next:map[now]){
        if (dfs_vist[next] == false){
            // dfs_vist[next] = true;            
            dfs(next);
        }
    }
}
void bfs(int now){
    queue<int> que;
    bfs_vist[now] = true;
    int node;
    que.push(now);
    while (!que.empty()){
        node = que.front();
        cout << node << " ";
        que.pop();
        for (int next:map[node]){
            if (bfs_vist[next] == false){
                que.push(next);
                bfs_vist[next] = true;
            }
        }
    }
}
int main(){    
    int idx1,idx2;
    freopen("BOJ/in.txt","r",stdin);
    cin >> N >> M >> V;
    // cout << N << M << V << endl;
    for (int m = 0; m< M; m++){
        scanf("%d %d",&idx1,&idx2);
        if (find(map[idx1].begin(),map[idx1].end(),idx2) == map[idx1].end()){
            map[idx1].push_back(idx2);
            map[idx2].push_back(idx1);
        }
    }
    for (int n = 1; n <=N ; n++){
        sort(map[n].begin(),map[n].end());
    }
    
    dfs(V);
    cout << endl;
    bfs(V);
    return 0;
}




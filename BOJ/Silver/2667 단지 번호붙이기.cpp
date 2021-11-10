#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int map[25][25],ch[25][25],N;
vector<int> dx = {1,0,-1,0}, dy = {0,-1,0,1},ans;


void bfs(int r, int c){
    queue<vector<int>> que;
    vector<int>now = {r,c};
    ch[r][c] = 1; 
    int cnt = 0;
    que.push(now);
    
    while (!que.empty()){
        now = que.front();
        que.pop();
        cnt ++;
        for (int idx = 0; idx < 4; idx ++){
            int nextX = now[0] + dx[idx];
            int nextY = now[1] + dy[idx];
            if (nextX<0 || nextX >=N || nextY<0 || nextY >=N){continue;}
            if (map[nextX][nextY] == 1 && ch[nextX][nextY] == 0){
                ch[nextX][nextY] = 1;
                map[nextX][nextY] = 0;
                que.push({nextX,nextY});
            }
        }
    }
    ans.push_back(cnt);
}
int main(){
    int v;
    freopen("BOJ/in.txt","r",stdin);
    cin >> N;

    for (int r = 0; r < N; r++){
        for (int c = 0; c < N ; c++){
            scanf("%1d", &v);
            map[r][c] = v;
            ch[r][c] = 0;
        }
    }

    for (int r = 0; r < N; r++){
        for (int c = 0; c < N ; c++){
            if (map[r][c] == 1 && ch[r][c] == 0){
                bfs(r,c);
            }
        }
    }
    sort(ans.begin(),ans.end());
    cout << ans.size() << endl;
    for (int a :ans ){cout << a << endl;}
    return 0;

}
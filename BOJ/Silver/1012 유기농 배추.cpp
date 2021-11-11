#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

int M,N,K,T,ans,idx1,idx2;
bool map[50][50],ch[50][50];
int dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0};

void bfs(int r, int c){
    queue<pair<int,int>> que;
    ans ++;
    que.push({r,c});
    map[r][c] = false;
    while (!que.empty()){
        pair<int,int> tmp = que.front();
        que.pop();
        for (int idx = 0; idx < 4; idx++){
            int nextX = tmp.first + dx[idx];
            int nextY = tmp.second + dy[idx];

            if (nextX >= N || nextX < 0 || nextY >= M || nextY < 0){continue;}
            if (map[nextX][nextY] && ch[nextX][nextY] == false){
                ch[nextX][nextY] = true;
                que.push({nextX,nextY});
            }
        }
    }
}

int main(){
    freopen("BOJ/in.txt","r",stdin);
    scanf("%d",&T);
    for (int _ = 0; _ < T; _++){
        scanf("%d %d %d",&M,&N,&K);
        ans = 0;
        for (int i = 0; i < 50 ; i++){
            for (int c = 0; c < 50; c ++){
                map[i][c] = false;
                ch[i][c] = false;
            }
        }
        // map[50][50],ch[50][50];
        for (int __ = 0; __ < K; __++){        
            scanf("%d %d",&idx1,&idx2);
            map[idx2][idx1] = true;
        }
        for (int R = 0 ; R < N ; R++){
            for (int C = 0; C < M ; C++){
                if (map[R][C] && ch[R][C] == false){
                    bfs(R,C);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
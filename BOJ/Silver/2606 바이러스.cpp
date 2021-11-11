#include <stdio.h> // scanf
#include <iostream> //cout
#include <queue> // bfs


int N,V,ans;
bool map[101][101];
bool ch[101];
using namespace std;

void bfs(){
    queue<int> que;
    que.push(1);
    ch[1] = true;
    while (!que.empty()){
        int idx = que.front();
        que.pop();

        for (int i = 1; i < 101; i++){
            if (map[idx][i] && ch[i] == false){
                ans ++;
                ch[i] = true;
                que.push(i);
            }
        }
    }
}
int main(){
    int idx1,idx2;
    freopen("BOJ/in.txt","r",stdin);
    scanf("%d",&N);
    scanf("%d",&V);

    for (int _ = 0; _<V ; _++){
        scanf("%d %d",&idx1,&idx2);
        map[idx1][idx2] = 1;
        map[idx2][idx1] = 1;
    }

    bfs();
    cout << ans << endl;
    return 0;
}
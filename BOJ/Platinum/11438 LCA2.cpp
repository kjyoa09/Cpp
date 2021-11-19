#include <iostream>
#include <vector>

using namespace std;

int n,u,v,m,lca[100001][22],depth[100001];
vector<vector<int>> maps;

void mk(int pre, int now){

    lca[now][0] = pre;
    depth[now] = depth[pre]+1;

    for (int i = 1; i <= 21; i++){
        int tmp = lca[now][i-1];
        lca[now][i] = lca[tmp][i-1];
    }

    for (int next:maps[now]){
        if (next != pre){
            mk(now,next);
        }
    }
}

int find(int a, int b){
    if (depth[a] != depth[b]){
        if (depth[a] > depth[b])swap(a,b); //b가 더 깊음

        for (int i = 21; i >= 0; i--){
            if (depth[a] <= depth[lca[b][i]]){
                b = lca[b][i];
            }
        }
    }
    if (a == b){return a;}
    int re = a;
    for (int i = 21; i >= 0; i--){
        if(lca[a][i] != lca[b][i]){
            a = lca[a][i];
            b = lca[b][i];
        }
        re = lca[a][i];
    }
    return re;
}

int main(){
    freopen("BOJ/in.txt","r",stdin);
    scanf("%d",&n);

    maps.resize(n+1);

    for (int i = 1; i < n; i++){
        scanf("%d %d",&u,&v);
        maps[u].push_back(v);
        maps[v].push_back(u);
    }

    mk(0,1);

    // for(int i = 1; i < n+1; i++){
    //     for (int c=0;c<22;c++){
    //         cout << lca[i][c] << " ";
    //     }
    //     cout << '\n';
    // }

    scanf("%d",&m);

    while(m--){
        scanf("%d %d",&u,&v);
        // cout << u << "  "<< v << '\n';
        // find(u,v);
        cout << find(u,v) << '\n';
    }
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

long long dist[100001];
int lca[100001][22],depth[100001];
vector<vector<pair<int,long long>>> maps;

int n,u,v,k,m;
int a,b,c,d;

void mk(int pre, int now){

    lca[now][0] = pre;
    for (int i = 1; i < 20; i++){
        int tmp = lca[now][i-1];
        lca[now][i] = lca[tmp][i-1];
    }

    for (auto tmp:maps[now]){
        if (tmp.first != pre){
            dist[tmp.first] = dist[now] + tmp.second;
            depth[tmp.first] = depth[now] + 1;
            lca[tmp.first][0] = now;
            mk(now,tmp.first);
        }
    }
}

int findlca(int a, int b){
    if (depth[a] != depth[b]){
        if (depth[a] > depth[b]){swap(a,b);}

        for (int i = 21; i >= 0; i--){
            if(depth[a] <= depth[lca[b][i]]){b = lca[b][i];}
        }
    }
    
    int re = a;
    if (a!=b){
        for (int i = 21; i>=0; i--){
            if(lca[a][i] != lca[b][i]){
                a = lca[a][i];
                b = lca[b][i];
            }
            re = lca[a][i];
        }
    }
    return re;
}

int main(){
    freopen("BOJ/in.txt","r",stdin);
    cin >> n;
    maps.resize(n+1);

    for (int i = 0; i < n-1; i++){
        scanf("%d %d %d", &u, &v, &k);
        maps[u].push_back({v,k});
        maps[v].push_back({u,k});
    }

    mk(0,1);

    cin >> m;
    while(m--){
        scanf("%d",&a);
        if (a == 1){
            scanf("%d %d",&b,&c);
            n = findlca(b,c);
            // cout << dist[b] + dist[c] - 2*(dist[n]) << '\n';
            printf("%lld\n",dist[b] + dist[c] - 2*(dist[n]));
        }
        else{
            scanf("%d %d %d",&b,&c,&d);
            // cout <<a << " " << b << " " << c << " " << d <<" ";
            n = findlca(b,c);
            int diffb = depth[b] - depth[n];
            if (diffb + 1 >= d){
                d --;
                for(int i = 20; i >=0; i--){
                    if ((1<<i) <= d){
                        d -= (1 << i);
                        b = lca[b][i];
                    }
                }
                printf("%d\n",b);
            }
            else{
                d = depth[c] - depth[n] + 1 + diffb - d;
                for (int i = 20; i >= 0; i--){
                    if((1<<i) <= d){
                        d -= (1 << i);
                        c = lca[c][i];
                    }
                }
                
                printf("%d\n",c);
            }
        }
    }
    return 0;

}
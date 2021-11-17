#include <iostream>
#include <vector>

using namespace std;

int N,R,Q;
vector<vector<int>> map(100001,vector<int>(0,0));
vector<vector<int>> tree(100001,vector<int>(0,0));
vector<int> ans(100001,0);

void MK(int pre, int now){
    int tmp = 1;
    for (int Next:map[now]){
        if (Next != pre){
            tree[now].push_back(Next);
            MK(now,Next);
            tmp += ans[Next];
        }
    }
    ans[now] = tmp;
}

// void count(int Node){
//     int tmp = 1;
//     if (tree[Node].size() != 0){
//         for (int next:tree[Node]){
//             count(next);
//             tmp += ans[next];
//         }
//     }
//     ans[Node] = tmp;
// }
int main(){
    freopen("BOJ/in.txt","r",stdin);
    cin >> N >> R >> Q;
    int S,E;
    for (int i = 0; i < N-1; i++){
        scanf("%d %d",&S,&E);
        map[S].push_back(E);
        map[E].push_back(S);
    }
    MK(-1,R);
//    count(R);
    for (int q = 0; q < Q; q++){
        scanf("%d",&S);
        cout << ans[S] << "\n";
    }
    return 0;
}
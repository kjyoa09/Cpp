#include <iostream>
#include <vector>
using namespace std;

int N,M,num[9];

void dfs(int cnt){
    if (cnt == M){
        for (int a = 0 ; a < M ; a++){
            cout << num[a] << ' ';
        }
        cout << '\n'; // endl; 하면 시간초과
        }

    else{
        for (int i = cnt==0 ? 1:num[cnt-1] ; i <= N; i ++){
            num[cnt] = i;
            dfs(cnt + 1);
        }
    }
}


int main(){
    freopen("BOJ/in.txt","r",stdin);
    cin >> N >> M ;
    dfs(0);
    return 0;
}

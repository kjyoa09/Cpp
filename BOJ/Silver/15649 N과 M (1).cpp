#include <iostream>
#include <vector>
using namespace std;

int N,M,num[9];
bool TF[9];
void dfs(int cnt){
    if (cnt == M){
        for (int a = 0 ; a < M ; a++){
            cout << num[a] << ' ';
        }
        cout << '\n'; // endl; 하면 시간초과
        }

    else{
        for (int i = 1; i <= N; i ++){
            if (TF[i] == false){
                TF[i] = true;
                num[cnt] = i;
                dfs(cnt + 1);
                TF[i] = false;
            }
        }
    }
}

int main(){
    freopen("BOJ/in.txt","r",stdin);
    cin >> N >> M ;
    dfs(0);
    return 0;
}

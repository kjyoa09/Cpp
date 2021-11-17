#include <iostream>

using namespace std;

bool TF[20];
int arr[20],N,S,ans = 0;

void dfs(int idx, int Sum){
    if (idx == N){return;}

    for (int i = idx; i < N; i ++){
        ans += (Sum+arr[i] == S) ? 1:0;
        dfs(i+1,Sum + arr[i]);
    }

}
int main(){
    freopen("BOJ/in.txt","r",stdin);
    cin >> N >> S;
    for (int i = 0; i < N; i++){cin >> arr[i] ;}
    dfs(0,0);
    cout << ans << endl;
    return 0;
}
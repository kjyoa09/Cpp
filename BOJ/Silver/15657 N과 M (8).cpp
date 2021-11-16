#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M,num[9];
vector<int> vec;

void dfs(int cnt,int idx){
    if (cnt == M){
        for (int a = 0 ; a < M ; a++){
            cout << num[a] << ' ';
        }
        cout << '\n'; // endl; 하면 시간초과
        }

    else{
        for (int i = idx; i < N; i ++){
            num[cnt] = vec[i];
            dfs(cnt+1,i);
        }
    }
}



int main(){
    freopen("BOJ/in.txt","r",stdin);
    int tmp;
    cin >> N >> M ;
    for (int i = 0; i < N; i++){
        cin >> tmp; 
        vec.push_back(tmp);
    }
    sort(vec.begin(),vec.end());
    // for (int v:vec){cout << v << endl;}

    dfs(0,0);
    return 0;
}

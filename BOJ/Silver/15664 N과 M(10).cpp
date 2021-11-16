#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int N,M,arr[9];
vector<int> num(0,9);
bool TF[9];

map<vector<int>,int> dic;

void dfs(int cnt,int idx ){
    if (cnt == M){
    
        vector<int> tmp = {};
        for (int i = 0; i < M; i ++){
            tmp.push_back(arr[i]);
        }
        if (dic.find(tmp) == dic.end()){
            dic[tmp] = 1;
            for (int t:tmp){cout << t << " ";}
            cout << '\n';
        }
    }

    else {
        
        for (int i = idx; i < N; i ++){
            if (TF[i] == false){
                TF[i] = true;
                arr[cnt] = num[i];
                dfs(cnt + 1,i);
                TF[i] = false;
            }
        }
    }

}


int main(){
    freopen("BOJ/in.txt","r",stdin);
    int tmp;
    cin >> N >> M ;
    for (int i = 0; i < N; i++){
        cin >> tmp; 
        num.push_back(tmp);
    }
    sort(num.begin(),num.end());
    // for (int v:num){cout << v << endl;}

    dfs(0,0);
    return 0;
}

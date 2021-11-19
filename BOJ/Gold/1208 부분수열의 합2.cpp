/*
ans 단위 설정 int >> longlong
*/
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int N,S,arr[40];
map<int,int> ldic, rdic;
long long ans;
void dfs(int idx, int end, int num, map<int,int>& dic){
    if (idx == end){return;}
    dic[num+arr[idx]]++;
    dfs(idx+1,end,num+arr[idx],dic);
    dfs(idx+1,end,num,dic);
}
int main(){
    freopen("BOJ/in.txt","r",stdin);
    cin >> N >> S;

    for (int i = 0; i < N; i++){cin >> arr[i];}
    dfs(0,N/2,0,ldic);
    dfs(N/2,N,0,rdic);

    // for (auto tmp:ldic){
    //     cout << tmp.first << "  " << tmp.second << '\n';
    // }
    // for (auto tmp:rdic){
    //     cout << tmp.first << "  " << tmp.second << '\n';
    // }
    ans += ldic[S] + rdic[S];
    for (auto tmp:ldic){
        if (rdic.find(S-tmp.first) != rdic.end()){
            ans += (1ll)*rdic[S-tmp.first] * tmp.second;
        }
    }
    cout << ans << endl;
    return 0;
}
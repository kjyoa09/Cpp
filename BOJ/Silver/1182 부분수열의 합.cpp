#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,S,ans = 0;
vector<int> arr(40,1000001);
int main(){
    freopen("BOJ/in.txt","r",stdin);
    int Sum = 0;
    cin >> N >> S;
    for (int i = 0; i < N; i++){
        cin >> arr[i];
        Sum += arr[i];}
    sort(arr.begin(),arr.end());
    int lt = 0, rt = N-1;

    while (lt <= rt){
        if (Sum < S){
            Sum -= arr[lt];
            lt ++;
        }

        else if (Sum == S){
            ans ++;
            Sum -= arr[lt];
            lt ++;
        }

        else {
            Sum -= arr[rt];
            rt --;
        }
    }
    
    cout << ans << endl;
    return 0;
}
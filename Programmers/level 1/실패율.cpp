/* sort 함수;;;;*/
#include <bits/stdc++.h>

using namespace std;

bool cmd(const pair<double,int>& a, const pair<double,int>&b){
    if (a.first != b.first){
        return a.first > b.first;
    }
    else{
        return a.second < b.second;
    }

}
vector<int> solution(int N, vector<int> stages) {
    vector<vector<double>> dic;
    
    for (int i = 0; i <= N ; i++){
        dic.push_back({0.0,0.0});
    }
    
    for (int st:stages){
        for (int i = 1; i <= (st == N+1 ? N:st); i++){
            dic[i][0]++;
        }
        dic[(st == N+1 ? 0:st)][1]++;
    }
    vector<pair<double,int>> vec;
    for (int i = 1; i <= N ; i++){
        vec.push_back({dic[i][0] == 0 ? 0:dic[i][1]/dic[i][0],(int)i});
    }
    vector<int>answer;    
    sort(vec.begin(),vec.end(),cmd);
    for (int i = 0;i < vec.size();i++){
        answer.push_back(vec[i].second);
        // cout << "stage : " << vec[i].second << ": " << vec[i].first << endl;
    }
    

    return answer;
}
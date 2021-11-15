/*
map을 지역변수로 설정해서 check이랑 dfs에 넣어주면 시간초과 >> 계속 복사해서 그런듯..
>> 참조자로 하거나 전역변수로 설정 해야함.

#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> ans = {0,0};
bool check(vector<vector<int>>& map, int R_s,int C_s, int L){

    int std = map[R_s][C_s];
    if (L == 1){
        ans[std]++;
        // cout <<  "A " << "R :" << R_s << " C :" << C_s << " L :" << L << " STD : "<< std << endl;
        return true;
    }
    for (int r = R_s ; r < L+R_s; r++){
        for (int c = C_s; c < L+C_s; c++){
            if (map[r][c] != std){return false;}
        }
    }
    ans[std] ++;
    // cout << "B " << "R :" << R_s << " C :" << C_s << " L :" << L << " STD : "<< std << endl;
    return true;    
}


void dfs(vector<vector<int>>& map, int R_s, int C_s, int L){
    
    if(check(map,R_s,C_s,L)){return;}
    
    else{
        dfs(map,R_s,C_s,(int)L/2);
        dfs(map,R_s,C_s+(int)L/2,(int)L/2);
        dfs(map,R_s+(int)L/2,C_s,(int)L/2);
        dfs(map,R_s+(int)L/2,C_s+(int)L/2,(int)L/2);
    }    
}

vector<int> solution(vector<vector<int>> arr) {
    dfs(arr,0,0,arr.size());
    return ans;
}
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> map;

vector<int> ans = {0,0};
bool check(int R_s,int C_s, int L){

    int std = map[R_s][C_s];
    if (L == 1){
        ans[std]++;
        // cout <<  "A " << "R :" << R_s << " C :" << C_s << " L :" << L << " STD : "<< std << endl;
        return true;
    }
    for (int r = R_s ; r < L+R_s; r++){
        for (int c = C_s; c < L+C_s; c++){
            if (map[r][c] != std){return false;}
        }
    }
    ans[std] ++;
    // cout << "B " << "R :" << R_s << " C :" << C_s << " L :" << L << " STD : "<< std << endl;
    return true;    
}


void dfs(int R_s, int C_s, int L){
    
    if(check(R_s,C_s,L)){return;}
    
    else{
        dfs(R_s,C_s,(int)L/2);
        dfs(R_s,C_s+(int)L/2,(int)L/2);
        dfs(R_s+(int)L/2,C_s,(int)L/2);
        dfs(R_s+(int)L/2,C_s+(int)L/2,(int)L/2);
    }    
}

vector<int> solution(vector<vector<int>> arr) {
    map = arr;
    dfs(0,0,arr.size());
    return ans;
}
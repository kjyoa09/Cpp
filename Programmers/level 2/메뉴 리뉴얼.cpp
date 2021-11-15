#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

vector<string> comb;
map<int,map<string,int>> dic;

void dfs(string& order,int idx, string c){
    
    if (idx == order.size()){return;}
    comb.push_back(c+order[idx]);
    dfs(order,idx+1,c+order[idx]);
    dfs(order,idx+1,c);
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (string order:orders){
        sort(order.begin(),order.end());
        dfs(order,0,"");        
    }

    for (string str:comb){
        if (str.size() != 1){
            dic[str.size()][str] ++;
        }
    }
    
    
    for (int num:course){
        int Max = 2;
        for(auto iter:dic[num]){
            Max = Max > iter.second ? Max:iter.second;
        }

        for(auto iter:dic[num]){

            if (iter.second == Max){answer.push_back(iter.first);}
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}
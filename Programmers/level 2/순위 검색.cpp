#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map<string,vector<int>> dic;

vector<string> infospilt(string i){
    vector<string> temp = {};
    string t = "";
    for (char in:i){
        if (in == ' '){
            temp.push_back(t);
            t = "";
        }
        else t+=in;
    }
    temp.push_back(t);
    return temp;
}

void dfs(int i, string st, vector<string>& vec){
    if (i == 4){
        dic[st].push_back(stoi(vec[4]));
        return;
    }
    else{
        if (i == 0){
            dfs(i+1,st + vec[0], vec);
            dfs(i+1,st + '-',vec);
        }
        else{
            dfs(i+1,st + " and " + vec[i],vec);
            dfs(i+1,st + " and -",vec);
        }
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    for (string i:info){
        vector<string> temp = infospilt(i);
        dfs(0,"",temp);
    }
    for (auto d:dic){
        sort(dic[d.first].begin(),dic[d.first].end());
    }
    for (string Q:query){
        string tmp = "";
        while (Q.back() != ' '){
            tmp = Q.back() + tmp;
            Q.pop_back();
        }
        Q.pop_back();
        int num = stoi(tmp);
        if (dic.find(Q) != dic.end()){
            vector<int>::iterator iter = lower_bound(dic[Q].begin(),dic[Q].end(),num);
            answer.push_back(dic[Q].end() - iter);
        }
        else {answer.push_back(0);}
    }
    
    return answer;
}
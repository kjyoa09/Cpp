#include <bits/stdc++.h>
using namespace std;


string solution(vector<string> participant, vector<string> completion) {
    
    map<string,int> dic;
    vector<string> names;
    
    for (string part:participant){
        if(dic.count(part) == 0){
            dic.insert({part,1});
            names.push_back(part);
        }
        else{
            dic[part]++;
        }
    }
    
    for (string com:completion){
        dic[com]--;
    }
    
    for (string name:names){
        if (dic[name] == 1){
            return name;
        }
    }

}
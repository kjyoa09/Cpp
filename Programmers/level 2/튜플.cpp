#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

map<int,vector<int>> dic;
vector<int> solution(string s) {
    s = s.substr(1,s.size()-2);
    for (int idx = 0; idx < s.size();idx ++){
        vector<int> vec = {};
        while (true){
            idx ++;
            int tmp = 0;
            while (isdigit(s[idx])){
                tmp *=10;
                tmp += s[idx] - '0';
                idx++;
            }
            vec.push_back(tmp);
            if (s[idx] == '}'){break;}
        }
        dic[vec.size()] = vec;
        idx ++;
    }
    vector<int> answer;
    map<int,int> set;
    for (auto tmp:dic){

        for (int t:tmp.second){
            if (set.find(t) == set.end()){
                answer.push_back(t);
                set[t] = 1;
                break;
            }
        }
    }
    

    return answer;
}
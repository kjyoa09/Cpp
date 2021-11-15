#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<string,int> dic;
vector<int> solution(string msg) {
    int cnt = 1;
    vector<int> answer;
    string tmp;
    for(char chr = 'A'; chr <= 'Z'; chr++){
        tmp = "";
        tmp += chr;
        dic[tmp] = cnt;
        cnt ++;
    }
    tmp = "";
    for (int i = 0; i < msg.size(); i++){
        tmp += msg[i];
        if (dic.find(tmp) == dic.end()){
            dic[tmp] = cnt;
            cnt ++;
            answer.push_back(dic[tmp.substr(0,tmp.size()-1)]);
            tmp = msg[i];
        }
        
        if (i == msg.size()-1){
            answer.push_back(dic[tmp]);
        }
    }

    return answer;
}
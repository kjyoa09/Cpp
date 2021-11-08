/*
        switch(sp[0]){
            case "Enter" :
                dic.insert({sp[1],sp[2]});
                action.push_back({sp[1],sp[0]});
                break;
            case "Leave":
                action.push_back({sp[1],sp[0]});
                break;
            case "Change":
                dic.insert({sp[1],sp[2]});
                break;
>> switch string 못 받음;;
*/

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <regex>
using namespace std;

vector<string> solution(vector<string> record) {
    regex rgx("([A-Z|a-z|0-9]+) ([A-Z|a-z|0-9]+)( ([A-Z|a-z|0-9]+))?");
    smatch matches;
    
    vector<string> answer;
    map<string,string> dic;
    vector<pair<string,string>> action;
        
    for (string re:record){
        vector<string> split;
        regex_search(re,matches,rgx);
        for (size_t i = 1; i < matches.size();++i){
            if (i == 3){continue;}
            else{split.push_back(matches[i].str());}
        }
        if (split[0] == "Enter"){
            dic[split[1]] = split[2];
            action.push_back({split[1],split[0]});            
        }
        else if (split[0] == "Leave"){
            action.push_back({split[1],split[0]});
        }
        else {
            dic[split[1]] = split[2];
        }
        // cout << dic[split[1]] <<endl;
    }
    
    for (pair<string,string> act:action){
        string tmp = dic[act.first];
        tmp += act.second == "Enter" ? "님이 들어왔습니다." : "님이 나갔습니다.";
        // string tmp = dic[act.first] + act.second == "Enter" ? "님이 들어왔습니다." : "님이 나갔습니다.";
        // cout << tmp <<endl;
        answer.push_back(tmp);
    }
    
    return answer;
}
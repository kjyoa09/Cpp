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


#include <bits/stdc++.h>
using namespace std;


string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    return answer; // >> return 없으면 signal: segmentation fault (core dumped) //
    // sort(completion.begin(), completion.end());
    // for(int i=0;i<completion.size();i++)
    // {
    //     if(participant[i] != completion[i])
    //         return participant[i];
    // }
    // return participant.back();
    //return answer;
}
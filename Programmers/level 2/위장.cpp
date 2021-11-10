#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> clothes) {
    
    map<string,int> dic;
    vector<string> keys;
    
    for (int i = 0; i < clothes.size(); i++){
        if (find(keys.begin(),keys.end(),clothes[i][1]) == keys.end()){
            keys.push_back(clothes[i][1]);
            dic[clothes[i][1]] = 1;
        }
        else{dic[clothes[i][1]]++;}
    }
    int answer = 1;
    for (string key:keys){answer *= (dic[key]+1); }
    return answer - 1;
}
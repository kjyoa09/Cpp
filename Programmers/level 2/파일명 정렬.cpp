#include <string>
#include <vector>
#include <regex>
#include <iostream>

using namespace std;

string tolow(string st){
    string tmp = "";
    for (char s:st){
        if ('A' <= s && s<= 'Z'){tmp += (s-'A'+'a');}
        else tmp += s;
    }    
    return tmp;
}

void sort(vector<vector<string>>& vec){
    int N = vec.size();
    
    for(int i = 0; i < vec.size(); i++){
        bool TF = true;
        for (int idx = 0; idx < N-1; idx++){
            if (vec[idx][1] > vec[idx+1][1]){swap(vec[idx],vec[idx+1]);TF = false;}
            else if (vec[idx][1] == vec[idx+1][1]){
                if (stoi(vec[idx][2]) > stoi(vec[idx+1][2])){swap(vec[idx],vec[idx+1]);TF = false;}
            }
        }
        if (TF){break;}
    }
}
vector<string> solution(vector<string> files) {
    vector<vector<string>> R;
    regex re("([^0-9]+)([0-9]+)([0-9A-Za-z. -]+)?");
    smatch match;
    for (int i = 0; i<files.size(); i++){
        regex_match(files[i],match,re);
        vector<string> tmp = {match[0],tolow(match[1]),match[2]};
        R.push_back(tmp);
     }
    
    sort(R);
    vector<string> answer;
    for (vector<string> r:R){answer.push_back(r[0]);}

    return answer;
}
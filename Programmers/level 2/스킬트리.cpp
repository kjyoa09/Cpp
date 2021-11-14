#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    vector<bool> islist(26,false);
    vector<char> next(' ',26);
    int answer = skill_trees.size();
    
    for (int i = 0; i < skill.size(); i ++ ){
        islist[skill[i]-'A'] = true;       
        if (i != 0){
            next[skill[i-1]-'A'] = skill[i];
            }
        if (i == skill.size()-1){
            next[skill[i]-'A'] = skill[i];
        }
    }

    for (string str:skill_trees){
        vector<bool> TF(26,false);
        TF[skill[0]-'A'] = true;
        for (char s:str){            
            if (islist[s-'A'] == false){continue;}
            else{
                if (TF[s-'A'] == true){
                    TF[next[s-'A']-'A'] = true;
                }
                else{
                    answer --;
                    break;}
            }
        }
    }
    

    return answer;
}
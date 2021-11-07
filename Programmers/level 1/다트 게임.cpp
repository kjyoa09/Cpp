#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


int solution(string dartResult) {
    int answer = 0;

    vector<int> tmp;
    
    for (int i = 0; i < dartResult.size(); i ++ ){
        string s = "";        
        s += dartResult[i];
        if ('0' <= dartResult[i+1] & dartResult[i+1] <= '9'){
            s += dartResult[i+1];
            i++;
        }
        i ++;
        int score = stoi(s);
        if (dartResult[i] == 'D'){score *= score;}
        else if (dartResult[i] == 'T'){score *= score * score;}
        
        if (dartResult[i+1] == '*' | dartResult[i+1] == '#'){
            if (dartResult[i+1] == '#'){
                score *= -1;
            }
            else{
                score *= 2;
                if (tmp.size()){tmp[tmp.size()-1] *= 2;}
            }
            i ++;
        }
        tmp.push_back(score);
    }
    for(int ss:tmp){
        answer+=ss;}
    return answer;
}
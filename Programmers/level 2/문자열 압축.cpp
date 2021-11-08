#include <string>
#include <vector>
#include <iostream>
using namespace std;


int solution(string s) {
    int L = s.size()/2,answer = 1001;
    
    for (int l = 1; l < L+2 ; l++){
        vector<string> vec;
        for (int i = 0; i < s.size(); i += l){
            string tmp = s.substr(i,l);
            if (i+2*l <= s.size() && s.substr(i+l,l) == tmp){
                int cnt = 1;
                while (i+2*l <= s.size() && s.substr(i+l,l) == tmp){
                    cnt ++;
                    i += l;
                }
                vec.push_back(to_string(cnt)+tmp);
            }
            else{vec.push_back(tmp);}
        }
        int ans = 0;
        for (string v:vec){ans += v.size();}
        answer = ans<answer ? ans:answer;      
    }
    return answer;
}
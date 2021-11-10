#include <string>

using namespace std;

string solution(string p) {
    
    if (p==""){return "";}
    int r = 0, l = 0, idx = 0;
    string tmp = "";
    
    while(true) {
        if (p[idx] == ')'){r++;}
        else{l++;}
        tmp += p[idx];
        if (l == r){break;}
        idx ++;
    }
    string v = p.substr(idx+1,p.size()-idx);
    
    if (tmp[0] == '('){
        return tmp + solution(v);
    }
    else{
        string s = "";
        for (int i = 1; i < tmp.size()-1; i++){
            if (tmp[i] == ')'){s+='(';}
            else{s+=')';}
        }
        return "(" + solution(v) + ")" + s;
    }
}
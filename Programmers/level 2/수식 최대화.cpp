#include <string>
#include <vector>
#include <iostream>


using namespace std;

typedef long long ll;

int f(vector<char>& vec,char si){
    for (int i = 0; i < vec.size(); i++){
        if (vec[i] == si){return i;}
    }
    return -1;
}

long long solution(string expression) {
    string tmp = "";
    vector<ll> num;
    vector<char> sims;
    for (char exp:expression){
        switch(exp){
            case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':
                tmp += exp;
                break;
            default:
                sims.push_back(exp);
                num.push_back(stoll(tmp));
                tmp = "";
                break;             
        }
    }
    num.push_back(stoll(tmp));
    vector<string> pos = {"*+-","-*+","-+*","+-*","+*-","*-+"};
    
    long long answer = 0;
    for (int i = 0; i < 6; i++){
        vector<ll> n = num;
        vector<char> s = sims;
        for (char p:pos[i]){
            while (true){
                int idx = f(s,p);
                if (idx == -1){break;}                
                else{
                    if (p == '+'){n[idx]+=n[idx+1];}
                    else if (p == '-'){n[idx]-=n[idx+1];}
                    else {n[idx]*=n[idx+1];}
                    s.erase(s.begin()+idx);
                    n.erase(n.begin()+idx+1);
                }
            }
                
        }
        answer = answer > abs(n[0]) ? answer:abs(n[0]);
    }

    
    return answer;
}
#include <string>
#include <vector>
#include <iostream>
using namespace std;
string all = "0123456789ABCDEF";
int N,T,M;

string makeJin(){
    string re = "0", _ = "";
    vector<string> next;
    for (int i=0; i<N; i++){
        next.push_back(_ + all[i]);
    }

    while (re.size() <= M*(T+1)){
        for (string vec:next){re+= vec[0] != '0' ? vec:"";}
        vector<string> tmp;
        
        for (int i=0; i<N; i++){
            for (string vec:next){tmp.push_back(all[i]+vec);}
        }
        next = tmp;
    }
    return re;
}

string solution(int n, int t, int m, int p) {
    N = n, T=t, M=m;
    string Jin = "",answer = "";
    Jin = makeJin();
    // cout << Jin << endl;
    for (int P=p-1;answer.size()<t;P+=m){answer+= Jin[P];}

    return answer;
}
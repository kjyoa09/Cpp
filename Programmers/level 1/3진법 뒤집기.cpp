#include <bits/stdc++.h>

using namespace std;

string ftn(int n){
    string tmp = "";

    while (n>0){
        tmp = to_string(n%3) + tmp;
        n = (int)n/3;
    }
    return tmp;
}

int solution(int n) {
    int answer = 0;
    string mid = ftn(n);
    for (int i = 0;i<mid.size();i++){
        int tmp = mid[i]-48;
        answer += tmp * (pow(3,i));
    }
    return answer;
}
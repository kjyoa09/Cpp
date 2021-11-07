#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    array<int,1000001> list = {0};
    int answer = 0;
    for(long long i = 2;i<1000;i++){
        if (list[i] == 0){
            for (long long ii = 2*i;ii<1000001;ii+=i){
                list[ii] = -1;
            }
        }
    }
    for (int i = 2;i<n+1;i++){
        if(list[i] == 0){
            answer ++;
        }
    }    
    return answer;
}

/*
int solution(int n) {
    int answer = 0;
    vector<bool> tmp(n+1, true); // vector는 초기값 가능..

    for (int i=2; i<n+1; i++) {
        if (tmp[i] == true) {
            for (int j=2; i*j<n+1; j++) tmp[i*j] = false;
            answer++;
        }
    }

    return answer;
}
*/
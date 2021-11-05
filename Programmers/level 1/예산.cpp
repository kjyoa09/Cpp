#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> d, int budget) {
    sort(d.begin(),d.end());
    int answer = 0;
    for (int b:d){
        if (budget-b >=0){
            answer ++;
            budget -= b;
        }
        if (budget<=0){
            return answer;
        }
    }

}
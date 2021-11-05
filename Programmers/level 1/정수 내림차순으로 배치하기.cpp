#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    string tmp = to_string(n);
    sort(tmp.rbegin(),tmp.rend()); // r로하면 내림차순
//    sort(str.begin(), str.end(), greater<char>());
//    answer = stoll(str);
    for (char v:tmp){
        answer = answer * 10 + (v-'0');
    }
    return answer ;
}
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(int a, int b){
    string A = to_string(a), B = to_string(b);

    while(A.size()<12){A += A;}
    while(B.size()<12){B += B;}

    A.resize(12);    
    B.resize(12);
    
    return A>B;
}
string solution(vector<int> numbers) {
    string answer = "";
    bool flag = true;
    sort(numbers.begin(),numbers.end(),cmp);
    
    for (int num:numbers){
        answer += to_string(num);
        if (flag && num != 0){flag = false;}
    }
    return flag ? "0":answer;
}
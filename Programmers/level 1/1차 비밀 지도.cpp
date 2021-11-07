#include <bits/stdc++.h>


using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {

    int a;
    vector<string> answer;
    for (int i = 0;i<n;i++){
        string tmp ;
        a = arr1[i]|arr2[i];
        for (int nn = 0;nn<n;nn++){
            char t = (a%2&1) ? '#':' ';
            tmp = t + tmp;
            a = (int)a/2;
        }
        answer.push_back(tmp);
    }
    
    
    return answer;
}
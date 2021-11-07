#include <bits/stdc++.h>
#include <vector>

using namespace std;


// Bubble sort
void sort(vector<string>& vec,int idx){

    for (int i = 1; i < vec.size(); i ++){
        
        for (int r = 0; r < vec.size() - i ; r ++){
            
            if ((vec[r][idx] > vec[r+1][idx]) | (vec[r][idx] == vec[r+1][idx] & vec[r] > vec[r+1])){
                string tmp = vec[r+1];
                vec[r+1] = vec[r];
                vec[r] = tmp;
            } 
        }        
    }
}
vector<string> solution(vector<string> strings, int n) {   
    sort(strings,n);
    return strings;
}

/*
int i; // 전역변수를 사용;; >> 이거 생각 못해서 sort 만듬..

bool compare (string a, string b) {
    return a[i] == b[i] ? a < b : a[i] < b[i];
}

vector<string> solution(vector<string> strings, int n) {
    i = n;
    sort (strings.begin(), strings.end(), compare);
    return strings;
}*/
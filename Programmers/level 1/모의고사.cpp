//https://m.blog.naver.com/kks227/220246803499

/*
구간 안에서(배열이나 벡터 등) 최대, 최소값을 구하는 함수인
max_element(), min_element() 함수가 존재합니다.
그런데 주의점은, 이 함수는 값 자체를 리턴하지 않고
그 값의 주소를 리턴하는데, 이터레이터를 리턴하기도 합니다. >> 이터레이터 리턴..?
사실 정확히 이야기하자면 C++에서는 배열 역시 array라는 클래스 형 객체로 취급됩니다.
그래서 주소값에 관해서 이터레이터 연산이 가능하게 되어 있습니다.
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> f = {1,2,3,4,5}, s = {2, 1, 2, 3, 2, 4, 2, 5}, t = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5},score = {0,0,0},answer;

    
    for (int i = 0; i < answers.size(); i++){
        if (answers[i] == f[i%5]){score[0]++;}
        if (answers[i] == s[i%8]){score[1]++;}
        if (answers[i] == t[i%10]){score[2]++;}
    }
    
    int max = *max_element(score.begin(),score.end());
    
    for (int i = 0;i <3; i++){
        if(score[i] == max){answer.push_back(i+1);}
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> pos;
vector<bool> L;

void make(string numbers, string num){
    if (num.size() == L.size()){return;}
    else{
        for (int i = 0; i < L.size(); i++){
            if(L[i]){
                if(num.size()==0 && numbers[i] == '0'){continue;}
                else{
                    L[i] = false;
                    pos.push_back(stoi(num+numbers[i]));
                    make(numbers,num + numbers[i]);
                    L[i] = true;
                }
            }
        }
    }
}

int solution(string numbers) {
    vector<bool> che(10000000,true);//vector 초기화
    
    L.assign(numbers.size(),true);
    int answer = 0;
    che[1] = false;
    for (long i = 2; i<10000; i++){
        if (che[i]){
            for (long num = i+i;num<10000000;num += i){che[num] = 0;}
        }
    }
    make(numbers,"");
    
    for (int i:pos){
        if(che[i]){
            che[i] = false;
            answer++;
        }
    }
    
    return answer;
}
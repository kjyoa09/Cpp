#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    
    vector<string> en = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    vector<string> num = {"0","1","2","3","4","5","6","7","8","9"};
    
    for (int i = 0;i< 10;i++){
        s = regex_replace(s,regex(en[i]),num[i]);       
    }   
    
    return stoi(s);
}

int main(){
    string s = "one4seveneight";
    
    cout << solution(s) <<endl;
}


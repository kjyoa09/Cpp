#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    map<string,int> dic;
    dic[words[0]] = 1;
    for (int i = 1; i < words.size(); i ++){
        if (words[i-1][words[i-1].size()-1] != words[i][0] || dic.find(words[i]) != dic.end()){
            i++;
            int a = i%n == 0 ? n:i%n, b = i%n == 0 ? i/n:i/n+1;
            return {a,b};
        }
        dic[words[i]] = 1;
    }
    
    return {0,0};
}
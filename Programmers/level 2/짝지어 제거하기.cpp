#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string s)
{   
    vector<char> vec;    
    for (char S:s){
        if (vec.empty()){vec.push_back(S);}
        else{
            if (vec.back() == S){vec.pop_back();}
            else{vec.push_back(S);}
        }
    }
    
    return vec.size() ? 0:1;
}
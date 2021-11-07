#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    for (int a:arr){
        if(answer.size()==0|answer.back() != a){
            answer.push_back(a);
        }
    }
    return answer;
}
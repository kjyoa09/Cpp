#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    for (int i = 0; i < number.size(); i ++){
        
        if (k != 0){
            
            if (!(answer == "" || answer.back() >= number[i])){
                
                while (!answer.empty() && k != 0){
                    if (answer.back() < number[i]){
                        k--;
                        answer.pop_back();
                    }
                    else{break;}
                }
            }
        }
        answer += number[i];    
    }
    answer.resize(answer.size() - k);
    return answer;
}
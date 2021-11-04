#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    for (int i = 0;i < new_id.size(); i++){
        char tmp = new_id[i];
        
        if (tmp == '.'){
            if (answer.size() == 0){continue;}
            else if (answer.back() != '.'){
                answer += tmp;
            }
        }
        
        else if ((tmp == '_') | (tmp == '-')){
            answer += tmp;
        }
        
        else {
            if (('A' <= tmp) && ('Z' >= tmp)){
                tmp = tmp - 'A' + 'a';                
            }

            if ((('a'<=tmp) && (tmp <= 'z')) | (('0'<=tmp) && (tmp <= '9')) ){
                answer += tmp;
            }
        }
    }

    if (answer == ""){
        answer += 'a';
    }
    
    while (answer.back() == '.'){
        answer.pop_back();
    }
    
    if (answer.size()<=2){
        while (answer.size() < 3){
            answer.push_back(answer.back());
        }
    }
    else if (answer.size() >=16){
        answer = answer.substr(0,15);
    }

    while (answer.back() == '.'){
        answer.pop_back();
    }
    
    return answer;
}
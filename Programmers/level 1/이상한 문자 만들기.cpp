#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int cnt = 0;
    for (char S:s){
        if (S == ' '){
            cnt = 0;
            answer += " ";}
        else{
            if (cnt & 1){answer += tolower(S);}
            else{answer += toupper(S);}
            cnt ++;
        }
    }
    return answer;
}
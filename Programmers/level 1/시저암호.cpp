#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for (char S:s){
        if(S==' '){answer+= " ";}
        else if('a'<=S & S <= 'z'){
            answer += (S+n > 'z') ? S+n-26:S+n;
        }
        else{
            answer += (S+n > 'Z') ? S+n-26:S+n;
        }
    }
    return answer;
}
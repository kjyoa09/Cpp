#include <string>

using namespace std;

string solution(string s) {
    string answer = "";
    for (char ss:s){
        switch(ss){
            case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':case ' ':
                answer += ss;
                break;
            default:
                answer += (answer.size() == 0| answer.back() == ' ') ? toupper(ss):tolower(ss);
        }
    }
    return answer;
}
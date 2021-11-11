#include <string>
#include <vector>

using namespace std;
int cnt,era;

string ftn(string str){
    cnt ++;
    int count = 0;
    for  (char s:str){count += s=='0' ? 1:0;}
    era += count;
    int re = str.size()-count;
    string next = "";
    while (re){
        if (re % 2){next = '1' + next;}
        else{next = '0'+next;}
        re = re/2;
    }
    return next;
}
vector<int> solution(string s) {
    while(s != "1"){
        s = ftn(s);
    }
    vector<int> answer = {cnt,era};
    return answer;
}
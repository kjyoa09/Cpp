#include <string>
#include <vector>

using namespace std;

int answer = 0;

void ftn(string s){
    vector<int> bl,ml,sl;
    
    for (int i = 0; i < s.size(); i ++ ){
        if (s[i] == '['){bl.push_back(i);}
        else if (s[i] == '{'){ml.push_back(i);}
        else if (s[i] == '('){sl.push_back(i);}
        
        else if (s[i] == ']'){
            if (bl.size() == 0 || (ml.size() > 0 && ml.back() > bl.back()) || (sl.size() > 0 && sl.back() > bl.back())) {return;}            
            else {bl.pop_back();}
        }
        else if (s[i] == '}'){
            if (ml.size() == 0 || (bl.size() > 0 && bl.back() > ml.back()) || (sl.size() > 0 && sl.back() > ml.back())) {return;}            
            else {ml.pop_back();}
        }
        else if (s[i] == ')'){
            if (sl.size() == 0 || (bl.size() > 0 && bl.back() > sl.back()) || (ml.size() > 0 && ml.back() > sl.back()) ) {return;}            
            else {sl.pop_back();}
        }
    }
    answer += sl.size() == bl.size() == ml.size() == 0 ? 1:0;
}
int solution(string s) {

    for (int i = 0; i <s.size() ; i++){
        ftn(s);
        s = s.substr(1,s.size()-1) + s[0];
    }

    return answer;
}
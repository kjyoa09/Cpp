#include <string>

using namespace std;

string solution(string s) {
    int Max,Min,num;
    string tmp;
    bool flag = false;
    
    for (int i = 0; i < s.size(); i ++){
        tmp = "";
        while (s[i] != ' '){
            tmp += s[i];
            i++;
        }
        num = stoi(tmp);
        if (flag){
            Max = Max > num ? Max:num;
            Min = Min < num ? Min:num;
        }
        else{
            flag = true;
            Max = num;
            Min = num;
        }
    }
    return to_string(Min) + " " + to_string(Max);
}
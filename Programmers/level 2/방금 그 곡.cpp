#include <string>
#include <vector>
#include <iostream>

using namespace std;

int maxL = 0;
string M,ans = "";

string change(const string& st){
    string tmp = "";
    for (int i = 0; i < st.size(); i++){
        if (st[i] == '#'){tmp[tmp.size()-1] = tmp[tmp.size()-1] - 'A' + 'a';}
        else tmp+=st[i];
    }
    return tmp;
}

vector<string> SP(const string& st){
    vector<string> vec;
    string temp = "";
    for (char s:st){
        switch(s){
            case ':':case ',':
                vec.push_back(temp);
                temp = "";
                break;
            default :
                temp+= s;
        }
    }
    vec.push_back(temp);
    return vec;
}

void ftn(const vector<string>& vec, int idx){
    int Len = (stoi(vec[2]) * 60 + stoi(vec[3])) - (stoi(vec[0]) * 60 + stoi(vec[1]));
    string mm = change(vec[5]),tmp = "";
    while (tmp.size() < Len){
        tmp += mm[tmp.size()%mm.size()];
    }
    if (tmp.find(M) != string::npos){
        if (maxL < Len){
            maxL = Len;
            ans =  vec[4];
        }
    }

}


string solution(string m, vector<string> musicinfos) {
    M = change(m);
    for(int i = 0; i < musicinfos.size(); i++){
        vector<string>tmp = SP(musicinfos[i]);
        ftn(tmp,i);
    }
    return ans == "" ? "(None)":ans;

}
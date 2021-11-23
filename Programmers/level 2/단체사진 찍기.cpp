#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <list>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

int ans;

void dfs(string p,vector<bool>& tf,vector<char>& n, map<char,map<char,list<int>>>& IF,map<char,int>& dic){
    if (p.size() == 8){

        for (int x = 0; x < 8; x++){
            int yy = 0;
            for (int y = x+1; y < 8; y++){
                char X = p[x], Y = p[y];
                if (dic[p[x]] > dic[p[y]])swap(X,Y);
                bool TF = true;
                for(int a :IF[X][Y]){
                    if (a == (y-x-1)){
                        TF = false;
                        break;
                    }
                }
                yy = y;
                if (TF){
                    // cout << x << " " << y << endl;
                    // cout << "A" << p[x] << " " << p[y] << endl;
                    return;}
            }
            // cout << x << "  " << yy << " " << p << endl;
        }
        ans ++;        
        
        return;
    }
    else{
        for (int i = 0; i < 8; i++){
            if (tf[i] == true){
                tf[i] = false;
                dfs(p + n[i], tf, n, IF, dic);
                tf[i] = true;
            }
        }
    }
}

int solution(int n, vector<string> data) {
    map<char,int> dic;
    ans = 0;
    vector<bool> tf = {true,true,true,true,true,true,true,true};
    vector<char> name = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    map<char,map<char,list<int>>> IF;
    
   
    for (int i = 0; i < 8; i++){
        dic[name[i]] = i;
        for (int c = i+1; c < 8; c++){
            IF[name[i]][name[c]] = {0,1,2,3,4,5,6};
        }
    }
    
    for (string d:data){
        char x = d[0], y = d[2], z = d[3];
        int n = d[4] - '0';
        if (dic[x] > dic[y])swap(x,y);
        
        if (z == '='){
            while(!IF[x][y].empty()){
                if (IF[x][y].front() == n){break;}
                IF[x][y].pop_front();
            }
            while(!IF[x][y].empty()){
                if (IF[x][y].back() == n){break;}
                IF[x][y].pop_back();
            }
        }
        else if (z == '<'){
            while(!IF[x][y].empty()){
                if (IF[x][y].back() < n){break;}
                IF[x][y].pop_back();
            }
        }
        else {
            while(!IF[x][y].empty()){
                if (IF[x][y].front() > n){break;}
                IF[x][y].pop_front();
            }            
        }
        if (IF[x][y].empty()){return 0;}
        // cout << x << " " << y << endl;
        // for (auto a:IF[x][y]) { cout << a << endl;}        
    }
    
    dfs("",tf,name,IF,dic);
    
    return ans;
}
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> map;
    for(int i = 1; i <= n; i++){
        vector<int> tmp(i,0);
        map.push_back(tmp);
    }
    int num = 1, last = ((n+1)*n)/2,ldx = 0,rdx = 1,row = 0;
    bool d = true, r = false, u = false;
    while (num <= last){
        
        if (d){
            for (int i = 0; i < n ; i++){
                map[row+i][ldx] = num;
                num ++;
            }
            n --;
            row += n;
            ldx ++;
            d = false;
            r = true;
        }
        
        else if (r){
            for (int i = 0; i < n; i++){
                map[row][i+ldx] = num;
                num ++;
            }
            n --;
            row --;
            r = false;
            u = true;
        }
        
        else {
            for (int i = 0; i < n; i++){
                map[row-i][map[row-i].size()-rdx] = num;
                num ++;
            }
            n --;
            row -= n-1;
            rdx++;
            u = false;
            d = true;
            
        }
        
    }
    for (vector<int>tmp:map){
        for (int t:tmp){answer.push_back(t);}
    }
    return answer;
}
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int dx[4] = {1,0,-1,0},dy[4] = {0,-1,0,0};

bool ftn(int r, int c, vector<string> map ){   
 
    for (int ix = 0; ix < 4; ix ++){
        int pr = r + dx[ix], pc = c + dy[ix];
        if (pr >= 5 || pc >= 5 || pr < 0 || pc < 0){continue;}
        if (r == pr && c == pc){continue;}
        
        if (map[pr][pc] == 'P'){return true;}
        else if (map[pr][pc] == 'X'){continue;}
        else {
            for (int ix2 = 0; ix2 < 4; ix2 ++){
                int ppr = pr + dx[ix2], ppc = pc + dy[ix2];
                if (ppr >= 5 || ppc >= 5 || ppr < 0 || ppc < 0){continue;}
                if (ppr == r && ppc == c){continue;}
                if (map[ppr][ppc] == 'P'){return true;}
           }
        }
    }
    return false;
}


vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (vector<string> maps : places){
        bool flag = false;
        answer.push_back(1);
        for (int r = 0; r < 5 ; r ++){
            if (flag){break;}
            
            for (int c = 0; c < 5; c++){                
                if (maps[r][c] == 'P'){
                    flag = ftn(r,c,maps);                    
                }
                if (flag){
                    answer.back()--;
                    break;
                }                

            }
        }
    }
    return answer;
}
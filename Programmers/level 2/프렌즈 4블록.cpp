#include <string>
#include <vector>
#include <iostream>
using namespace std;

int ans,M,N;
bool TF = true;

void ftn(vector<string>& board){
    vector<vector<bool>> ch(M,vector<bool>(N,false));
    
    for (int r = 0; r < M-1; r++){
        for (int c = 0; c< N-1; c++){
            if (board[r][c] == 'X'){continue;}
            if (board[r][c] == board[r+1][c] && board[r][c] == board[r][c+1] && board[r][c]== board[r+1][c+1]){
                ch[r][c] = true,ch[r+1][c] = true,ch[r][c+1] = true,ch[r+1][c+1] = true;
                TF = false;
            }
        }
    }
    
    if (TF){return;}
    for (int r = 0; r < M; r++){
        string tmp = "";
        for (int c = 0; c < N; c++){
            if (ch[r][c]){
                ans ++;
            }
            else{tmp += board[r][c];}
        }
        tmp.resize(N,'X');
        board[r] = tmp;
    }
}

int solution(int m, int n, vector<string> board) {
    
    vector<string> map(n,"");
    
    for (int c = 0; c < n; c++){
        for (int r = m-1; r >=0; r--){
            map[c]+=board[r][c];
        }
    }
    N = m, M = n;
    while(1){
        TF = true;
        ftn(map);
        if (TF){return ans;}
    }

}
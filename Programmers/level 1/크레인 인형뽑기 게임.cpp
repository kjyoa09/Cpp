#include<bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    vector<int> stack = {},h = {};
    int H = board.size();
    
    int answer = 0;
    
    for (int c = 0; c< board[0].size(); c++){
        for (int r = 0; r<board.size(); r++){
            if (board[r][c] != 0){
                h.push_back(r);
                break;
            }

        }
    }
    
    for (int move:moves){
        if (h[move-1] == H){continue;}
        else{
            if ((stack.size() > 0)&&(stack.back() == board[h[move-1]][move-1])){
                answer += 2;
                stack.pop_back();
            }
            else{
                stack.push_back(board[h[move-1]][move-1]);
            }
            h[move-1] +=1 ;
        }
    }
    
    return answer;
}
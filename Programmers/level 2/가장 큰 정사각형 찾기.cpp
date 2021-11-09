#include<vector>
using namespace std;

int solution(vector<vector<int>> board){
    int R = board.size(), C = board[0].size(),answer = 0;
    int ch[R][C];
    
    for (int r = 0; r<R ; r++){
        for (int c=0; c<C; c++){
            if ((c == 0) || (r == 0)){
                ch[r][c] = board[r][c];
                if (ch[r][c] == 1 && answer == 0){answer = 1;}
            }
            else{
                if (board[r][c] == 0){
                    ch[r][c] = 0;
                }
                else{
                    ch[r][c] = min(ch[r-1][c-1],min(ch[r-1][c],ch[r][c-1])) + 1;
                    if (answer < ch[r][c]){answer = ch[r][c];}
                }
            }
        }
    }
    return answer*answer;
}
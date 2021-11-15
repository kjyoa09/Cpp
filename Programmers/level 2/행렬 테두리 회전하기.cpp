#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> answer;

void rotate(int R1,int C1, int R2, int C2, vector<vector<int>>& map){
    
    int tmp = map[R1-1][C1-1], b = 0, com = map[R1-1][C1-1];
    
    for (int c = C1; c < C2; c++){
        b = map[R1-1][c];
        map[R1-1][c] = tmp;
        tmp = b;
        com = com < tmp ? com:tmp;
    }
    
    for (int r = R1; r < R2; r++){
        b = map[r][C2-1];
        map[r][C2-1] = tmp;
        tmp = b;
        com = com < tmp ? com:tmp;
    }
    
    for (int c = C2-2; c > C1-2; c--){
        b = map[R2-1][c];
        map[R2-1][c] = tmp;
        tmp = b;
        com = com < tmp ? com:tmp;
    }
    
    for (int r = R2-2; r > R1-2; r--){
        b = map[r][C1-1];
        map[r][C1-1] = tmp;
        tmp = b;
        com = com < tmp ? com:tmp;
    }
    answer.push_back(com);
    
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<vector<int>> arr;
    
    int cnt = 0;    
    
    for (int r = 0; r<rows; r++){
        vector<int> tmp;
        for (int c = 0; c < columns; c++){
            cnt++;
            tmp.push_back(cnt);
        }
        arr.push_back(tmp);
    }
    
    for (vector<int> query : queries){
        rotate(query[0],query[1],query[2],query[3],arr);
    }

    return answer;
}
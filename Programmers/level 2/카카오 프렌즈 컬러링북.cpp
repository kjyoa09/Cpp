
#include <vector>
#include <map>
#include <iostream>
#include <deque>

/*
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요. >> 안하면 통고 못함..

*/
using namespace std;



vector<vector<bool>> maps;
vector<int> answer;

void bfs(int m, int n,int r, int c, vector<vector<int>> &picture){
    int cnt = 0, stan = picture[r][c];
    deque<vector<int>> que;
    int dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};   
    que.push_back({r,c});
    maps[r][c] = true;
    
    while (!que.empty()){
        vector<int> coord = que.front();
        que.pop_front();
        cnt ++;
        for (int idx = 0; idx < 4; idx ++ ){
            int px = coord[0] + dx[idx], py = coord[1] + dy[idx];
            if (!(0<= px && px < m) || !(0<= py && py < n)){continue;}
            if (picture[px][py] == stan && maps[px][py] == false){
                maps[px][py] = true;
                que.push_back({px,py});
            }
        }
    }
    answer[1] = answer[1] > cnt ? answer[1] : cnt;

}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    maps.clear();
    answer.clear();
    
    answer = {0,0};
    for (int r = 0; r<m ; r++){
        vector<bool> tmp;
        for (int c=0; c<n; c++){
            tmp.push_back(false);
        }
        maps.push_back(tmp);
    }
            
                
    for (int r = 0; r<m ; r++){
        for (int c=0; c<n; c++){
            if (picture[r][c] != 0 && maps[r][c] != 1){
                answer[0]++;
                bfs(m,n,r,c,picture);
            } 
        }
    }    
    
    return answer;
}

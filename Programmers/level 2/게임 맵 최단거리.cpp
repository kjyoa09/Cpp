#include<vector>
#include<queue>

using namespace std;

int map[100][100];
int dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0};

int solution(vector<vector<int> > maps){
    int R = maps.size(), C = maps[0].size();
    queue<pair<int,int>> que;
    que.push({0,0});
    
    while (!que.empty()){
        pair<int,int> tmp = que.front();
        que.pop();
        
        for (int idx = 0; idx < 4; idx ++){
            int nextX = tmp.first + dx[idx];
            int nextY = tmp.second + dy[idx];
            
            if(nextX<0||nextX>=R||nextY<0||nextY>=C){continue;}
            if(maps[nextX][nextY] == 0){continue;}
            if(map[nextX][nextY] == 0 || map[nextX][nextY] > map[tmp.first][tmp.second]+1 ){
                map[nextX][nextY] = map[tmp.first][tmp.second]+1;
                que.push({nextX,nextY});
            }
        }
    }
        
    return map[R-1][C-1] == 0 ? -1:map[R-1][C-1]+1;
}
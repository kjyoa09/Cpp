#include <string>
#include <vector>
#include <iostream> // cout
#include <map> // dictionary;; keys 어떻게 하는 지 모르겠네;; for (auto it = dic.begin();it != dic.end();it++) tuple<int,int,int> tmp = it -> first;
#include <tuple> // map key 좌표 + direct 굳이 이걸로 할 필요는 없는듯.. >> tuple value get<idx>(name)
#include <algorithm> // sort
using namespace std;
/*
0 : down
1 : Up
2 : right
3 : left
*/

// void dfs(tuple <int,int,int> s, map<tuple<int,int,int>,bool> &dic, )

vector<int> solution(vector<string> grid) {
    int R = grid.size(), C = grid[0].size();
    map<tuple<int,int,int>,bool> dic;
    map<int,int> Left,Right; 
    vector<int> answer;

    Left.insert(pair<int, int>(0, 2));
    Left.insert(pair<int, int>(1, 3));
    Left.insert(pair<int, int>(2, 1));
    Left.insert(pair<int, int>(3, 0));

    Right.insert(pair<int, int>(0, 3));
    Right.insert(pair<int, int>(1, 2));
    Right.insert(pair<int, int>(2, 0));
    Right.insert(pair<int, int>(3, 1));

    for (int r = 0; r < R; r++){
        for (int c = 0; c< C; c++){
            for (int i = 0; i < 4; i++){
                dic[make_tuple(r,c,i)] = true;
            }
        }
    }
    
    for (auto it = dic.begin();it != dic.end();it++){
        tuple<int,int,int> tmp = it -> first;
        if (dic[tmp]){
            int cnt = 0;
            tuple<int,int,int> N = tmp;
            while(true){
                if (dic[N]){
                    cnt ++;
                    dic[N] = false;
                    int r = get<0>(N), c= get<1>(N), dir = get<2>(N);
                    // cout << "R : " << r << " C : " << c << " dir : " << dir << endl;
                    int pr,pc,pdir;
                    switch(dir){
                        case 0 : //down
                            pr = (r == R-1) ? 0:r+1;
                            pc = c;
                            break;
                        case 1: //Up
                            pr = (r == 0)? R-1:r-1;
                            pc = c;
                            break;
                        case 2: //right
                            pr = r;
                            pc = (c == C-1) ? 0:c+1;
                            break;
                        case 3://left
                            pr = r;
                            pc = (c == 0) ? C-1:c-1;
                            break;
                    }
                    switch(grid[pr][pc]){
                        case 'S':
                            pdir = dir;
                            break;
                        case 'L': // left >> up : 3 >> 1 up : left 1>>3 down >> right 0 >> 2 right : down 2 >> 0                            
                            pdir = Left[dir];
                            break;
                        case 'R': // down >> left 0 >> 3 up >> right 1 >> 2 left >> down
                            pdir = Right[dir];
                            break;                            
                    }
//                    cout << "PR : " << pr << " PC : " << pc << " Pdir : " << pdir << endl;
                N = make_tuple(pr,pc,pdir);
                }
                else{break;}
            }
            answer.push_back(cnt);
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}
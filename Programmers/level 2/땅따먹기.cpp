#include <vector>
using namespace std;

int solution(vector<vector<int> > land){
    vector<int> now = land[0];
    
    for (int r = 1; r<land.size(); r++){
        now = {max(max(now[1],now[2]),now[3]) + land[r][0],
              max(max(now[0],now[2]),now[3]) + land[r][1],
              max(max(now[1],now[0]),now[3]) + land[r][2],
              max(max(now[1],now[2]),now[0]) + land[r][3]}        ;
    }
    return max(max(max(now[1],now[2]),now[0]),now[3]);
}
// #include <string>
#include <vector>
// #include <iostream>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    
    int x = 0, y = 0;
    
    vector<int> rank = {6,6,5,4,3,2,1};
    
    for (int i = 0; i < lottos.size(); i++){
        
        if (lottos[i] == 0){
            x ++ ;
        }
        else {
            for (int n =0; n < win_nums.size(); n++){
                if (win_nums[n] == lottos[i]){
                    y ++ ;
                    break;
                }
            }
        }

    }

    // cout << x << y << endl;
    vector<int> answer;
    
    answer.push_back(rank[y+x]); //append
    answer.push_back(rank[y]);
    return answer;
}
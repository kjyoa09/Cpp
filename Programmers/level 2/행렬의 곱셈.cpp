//long으로 하면 error 남..

/*
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int R = arr1.size(), C = arr2[0].size();
    vector<vector<int>> answer;
    
    for (int r = 0; r < R; r++){
        vector<int> tmp_R;
        for (int c=0; c<C; c++){
            int tmp = 0;
            for (int rc = 0; rc < arr2.size(); rc++){
                tmp += arr1[r][rc] * arr2[rc][c];
            }
            tmp_R.push_back(tmp);
        }
        answer.push_back(tmp_R);
    }
    return answer;
}

*/

#include <vector>

using namespace std;

vector<vector<long>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int R = arr1.size(), C = arr2[0].size();
    vector<vector<long>> answer;
    
    for (int r = 0; r < R; r++){
        vector<long> tmp_R;
        for (int c=0; c<C; c++){
            long tmp = 0;
            for (int rc = 0; rc < arr2.size(); rc++){
                tmp += arr1[r][rc] * arr2[rc][c];
            }
            tmp_R.push_back(tmp);
        }
        answer.push_back(tmp_R);
    }
    return answer;
}
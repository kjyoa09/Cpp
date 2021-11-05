#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int R = arr1.size(), C = arr1[0].size();
    for (int r = 0; r<R; r++){
        vector<int> tmp ;
        for (int c = 0; c<C; c++){
            tmp.push_back(arr1[r][c] + arr2[r][c]);
        }
        answer.push_back(tmp);
    }
    return answer;
}
#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<int> A, vector<int> B)
{   sort(A.begin(),A.end());
    sort(B.rbegin(),B.rend());
 
    int answer = 0;   
    for(int i = 0; i < A.size(); i++){
        answer += A[i]*B[i];
    }
    return answer;
}
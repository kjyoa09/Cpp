#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int yellow) {
    int b = (int)(brown/2+2), c = brown + yellow;    
    vector<int> answer = {(int)(b+sqrt(pow(b,2) - 4 * c))/2,(int)(b-sqrt(pow(b,2) - 4 * c))/2};
    return answer;
}
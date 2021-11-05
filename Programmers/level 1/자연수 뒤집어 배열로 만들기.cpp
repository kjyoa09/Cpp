#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    string tmp = to_string(n);
    vector<int> answer;
    while (tmp.size()>0){
        answer.push_back(tmp.back()-'0');
        tmp.pop_back(); // return 하지 않음..
    }
    return answer;
}
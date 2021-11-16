#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    int a;
    string answer = "";
    vector<char> tmp = {'4','1','2'};
    while (true){
        a = n%3;
        answer = tmp[a]+answer;
        n = (int)n/3;
        n -= a==0? 1:0;
        if (n==0){return answer;}
    }
}
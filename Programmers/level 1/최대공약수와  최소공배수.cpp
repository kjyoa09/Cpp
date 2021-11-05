#include <string>
#include <vector>

using namespace std;


int gcd(int r, int l){
    int tmp = r%l;
    if (tmp==0){return l;}
    else{return gcd(l,tmp);}
}
vector<int> solution(int n, int m) {
    vector<int> answer;
    answer.push_back(gcd(n,m));
    answer.push_back((n*m)/answer.back());
    return answer;
}
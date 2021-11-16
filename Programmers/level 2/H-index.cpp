#include<algorithm>
using namespace std;
int solution(vector<int> citations) {
    sort(citations.rbegin(),citations.rend());
    for (int i = 0; i < citations.size(); i++){
        if (citations[i] <= i){return i;}
    }
}
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0,lt = 0, rt = people.size()-1;
    sort(people.rbegin(),people.rend());
    while (lt<=rt){
        answer++;
        if (rt==lt){break;}
        else if(people[lt] + people[rt] <= limit){lt++;rt--;}
        else {lt++;}
    }
    return answer;
}
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int day = 0,cnt = 0;
    for (int i = 0; i < progresses.size(); i ++){
        cnt = 0;
        day +=(int)(99 - progresses[i] - speeds[i] * day)/speeds[i] + 1;

        while (true){
            if (progresses[i] + speeds[i] * day >= 100){
                i++;
                cnt++;
            }
            else{i--;break;}
            if (i >= progresses.size()){break;}
        }
        
        answer.push_back(cnt);
    }
    return answer;
}
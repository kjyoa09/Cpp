#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(),0);
    
    for (int i = prices.size()-2; i >=0; i--){
        if (prices[i] > prices[i+1]){answer[i] = 1;}
        else{
            int cnt = 1;
            for (int tmp = i+1; tmp < prices.size()-1; tmp++){
                if (prices[i] > prices[tmp]){break;}
                cnt ++;
            }
            answer[i] = cnt;
        }
    }
    return answer;
}
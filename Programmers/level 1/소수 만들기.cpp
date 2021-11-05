#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    for (int f = 0;f < nums.size();f++){
        for (int s = f+1;s<nums.size();s++){
            for(int t=s+1;t<nums.size();t++){
                int tmp = nums[f]+nums[s]+nums[t];
                bool flag = true ;
                for (int tt = 2;tt<tmp/2;tt++){
                    if (tmp%tt == 0){
                        flag = false;
                        break;
                    }
                }
                answer += flag? 1:0;
            }
        }
    }

    return answer;
}
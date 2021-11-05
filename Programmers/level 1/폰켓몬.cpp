#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{   map <int,int> dic;
    int answer = 0;

    for (int num : nums){dic[num] ++; // default dict 처럼 사용 가능하네;;
    
        // if (dic.count(num) == 0){
        //     dic.insert({num,0});
        //}
    }
    
    // cout << dic[3] << endl;
    
    return dic.size() > (int)nums.size()/2 ? (int)nums.size()/2:dic.size() ;
}
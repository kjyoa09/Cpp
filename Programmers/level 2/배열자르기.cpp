#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    long long l_a = (long long) left/n, l_b = left%n,r_a = (long long) right/n, r_b = right%n ;
    
    if (l_a == r_a){
        for (int num = l_b; num < r_b+1; num++){
                answer.push_back(num < l_a ? l_a+1:num+1);            
        }
    }
    
    else{
        for (int num = l_b; num < n; num++){
            answer.push_back(num<l_a ? l_a+1:num+1);
        }
        l_a ++;
        while (l_a < r_a ){
            for (int num = 1; num < n+1; num++){
                answer.push_back(num<l_a+1 ? l_a+1:num);
            }
            l_a ++;
        }
        for (int num = 0; num < r_b +1; num++){
            answer.push_back(num+1<r_a+1 ? r_a +1 :num+1);
        }
    }
    // answer.push_back(l_a);
    return answer;
}
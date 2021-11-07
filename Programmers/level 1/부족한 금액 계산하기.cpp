/*
answer 만 long long 해주는 것이 아닌 rvalue 도 선언..
*/
#include <bits/stdc++.h>
using namespace std;
/*
long long solution(int price, int money, int count)
{   
    long long answer = money;
    for (int i = 1; i<count+1 ; i++){
        answer -= i*price;
    }
    return answer < 0 ? -answer:0;
}
*/

long long solution(int price, int money, int count)
{   
//    long long answer = 1LL*count*(count+1)/2*price;
    long long answer = (long long) count*(count+1)/2*price;
    return answer-money > 0 ? answer-money:0;
}
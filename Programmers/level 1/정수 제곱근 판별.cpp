#include <bits/stdc++.h>

using namespace std;

long long solution(long long n) {
    return pow((int)sqrt(n),2) == n ? pow(sqrt(n)+1,2) : -1;
}
#include <vector>
using namespace std;

int gcd(int a, int b){
    int tmp = a%b;
    if (tmp == 0){
        return b;
    }
    else {return gcd(b,tmp);}
}

int solution(vector<int> arr) {
    int a = arr[0];
    for (int i = 1; i < arr.size(); i ++){
        int tmp = gcd(a,arr[i]);
        a = (int)a*arr[i]/tmp;
    }
    return a;
}
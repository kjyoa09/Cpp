#include <string>
#include <list>
#include <iostream>
#include <cmath>
using namespace std;

int solution(string name) {
    list<int> d = {};
    int ans = 0, now = 0;
    for (int i = 0; i < name.size(); i++){
        if (name[i] != 'A'){
            ans += (name[i] - 'A') < ('Z'-name[i]+1) ? (name[i] - 'A'):('Z' - name[i]+1);
            d.push_back(i);
        }
    }
   
    // cout << abs(now - d.front()) << " " << now + name.size()-d.front() << endl;
    // cout << abs(now - d.back()) << now + name.size()-d.back() <<endl;
    while(!d.empty()){
        int A = abs(now - d.front()) < (now + name.size()-d.front()) ?  abs(now - d.front()) : (now + name.size()-d.front());
        int B = abs(now - d.back()) < (now + name.size()-d.back())?  abs(now - d.back()) : (now + name.size()-d.back());
        
        if (A > B){
            ans += B;
            now = d.back();
            d.pop_back();
        }
        else{
            ans += A;
            now = d.front();
            d.pop_front();
        }
    }
    return ans;
}
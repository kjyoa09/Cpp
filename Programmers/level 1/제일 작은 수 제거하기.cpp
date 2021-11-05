#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> ans;
    if (arr.size() == 1){return {-1};}
    else{
        int min = *min_element(arr.begin(),arr.end());
        for(int a:arr){
            if (a != min){ans.push_back(a);}
        }
        return ans;
    }
}


/*
#include <algorithm>
#include <vector>
using namespace std;

vector<int> solution(vector<int> arr) {
    if (arr.size() == 1) {
        return { -1 };
    }
    arr.erase(std::min_element(arr.begin(), arr.end()));
    return arr;
}
*/
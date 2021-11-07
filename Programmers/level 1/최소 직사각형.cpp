# include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int W = 0, H = 0;
    for (int i = 0; i<sizes.size();i++){
        int w = (sizes[i][0]>sizes[i][1]) ? sizes[i][0]:sizes[i][1], h = (sizes[i][0]>sizes[i][1]) ? sizes[i][1]:sizes[i][0];
        if(W < w){W = w;}
        if(H < h){H = h;}
    }
    return W*H;
}
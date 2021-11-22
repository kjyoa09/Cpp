#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

// typedef long long int d;
typedef double d;
vector<string> solution(vector<vector<int>> line) {
    vector<pair<d,d>> points;
    d a,b,c,ymax,ymin,xmax,xmin,_ = 0.0,mod;
    
    d xLen = 0;
    d yLen = 0;
    
    bool TF = true;    
    for (int idx = 0; idx < line.size(); idx ++){
        for (int i = idx + 1; i < line.size(); i++){
            b = ((d)line[idx][0] * (d)line[i][1] - (d)line[idx][1] * (d)line[i][0]);
            if (b == 0)continue;
            a = ((d)line[idx][1] * (d)line[i][2] - (d)line[idx][2] * (d)line[i][1]);
            c = ((d)line[idx][2] * (d)line[i][0] - (d)line[idx][0] * (d)line[i][2]);            
            
            if (modf(a/b,&_) || modf(c/b,&_))continue;
            // if (a%b != 0 || c%b != 0) continue;
            points.push_back({a/b,c/b});
            if (TF){
                xmax = xmin = a/b;
                ymax = ymin = c/b;
                TF = false;
            }
            else{
                xmax = xmax > a/b ? xmax:a/b;
                xmin = xmin < a/b ? xmin:a/b;
                ymax = ymax > c/b ? ymax:c/b;
                ymin = ymin < c/b ? ymin:c/b;
            }
        }
    }
    xLen = xmax - xmin + 1;
    yLen = ymax - ymin + 1;

    vector<string> answer(yLen, string(xLen, '.'));    

    for(auto it : points)
        answer[ yLen - 1 + ymin - it.second ][ -xmin + it.first ] = '*';
    return answer;
}
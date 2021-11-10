#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <queue>
#include <set>
using namespace std;





int solution(vector<vector<string>> relation) {
    map<int,vector<string>> dic;
    vector<int> keys(0,0);
    int R = relation.size(), C = relation[0].size(),ans = 0, bin = 0;
    queue<int> que;
    vector<string> tmp;
    set<string> tmp_set;

    for (int c = 0; c < C; c++){
        bin = 1<<c;
        for (int r = 0; r < R; r++){
            tmp.push_back(relation[r][c]);
            tmp_set.insert(relation[r][c]);
        }
        if (tmp_set.size() == R){
            keys.push_back(bin);
            ans ++;
            // cout << "ans : " << bin << endl;
        }
        else{
            dic[bin] = tmp;
            que.push(bin);
        }
        tmp.clear();
        tmp_set.clear();
    }

    while (!que.empty()){
        int now = que.front();
        // cout << "Now : " << now << endl;
        que.pop();

        for (int c = 0; c< C; c++){

            if (now & 1<<c){continue;}
            bin = now | 1<<c;
            bool flag = false;
            // cout << "Bin : " << bin << endl;
            for (int k:keys){
                // cout << "key : " << k << endl;
                int tmp_bin = bin&k;
                if(tmp_bin == k || k == bin ){flag = true;break;}
            }

            if(flag){continue;}
            else {
                tmp.clear();
                tmp_set.clear();
                for (int r = 0; r < R; r++){
                    tmp.push_back(dic[now][r] + relation[r][c]);
                    tmp_set.insert(dic[now][r] + relation[r][c]);
                }
                if (tmp_set.size() == R){
                    keys.push_back(bin);
                    ans ++;
                    // cout << "ans : " << bin << endl;
                }
                else{
                    dic[bin] = tmp;
                    que.push(bin);
                }
            }
        }   
    }


    return ans;
}
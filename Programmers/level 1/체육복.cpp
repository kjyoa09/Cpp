#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> R,L;
    int answer = n;    
    
    for (int i = 0; i < lost.size();i++){
        if(find(reserve.begin(),reserve.end(),lost[i]) == reserve.end()){L.push_back(lost[i]);}
    }
    for (int i = 0; i < reserve.size();i++){        
        if(find(lost.begin(),lost.end(),reserve[i]) == lost.end()){R.push_back(reserve[i]);}
    }
    
    // for (int r: R){cout << "R" << r <<endl;}
    // for (int r: L){cout << "L" << r <<endl;}
    
    if (L.empty()){return n;}
    else{
        answer -= L.size();
        sort(L.begin(),L.end());
        
        for (int l:L){
            if (R.empty()){break;}
            
            if (find(R.begin(),R.end(),l-1) != R.end()){
                answer ++;
                R.erase(find(R.begin(),R.end(),l-1)); 
            }
            else if(find(R.begin(),R.end(),l+1) != R.end()){
                answer ++;
                R.erase(find(R.begin(),R.end(),l+1));
            }
            // cout << "A" << answer << endl;            
        }
        return answer;
    }
}
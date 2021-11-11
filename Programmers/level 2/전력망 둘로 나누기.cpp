#include <string>
#include <vector>
#include <iostream>
using namespace std;

int ans = 101;
class ftn{
    int n;
    vector<vector<int>> wires;
    vector<vector<int>> maps,tree;
    public:
        ftn(int n, vector<vector<int>> wires);
        void makemaps();
        void maketree(int pre, int now);
        int count(int idx);
}
;
ftn::ftn(int n, vector<vector<int>> wires):n(n),wires(wires){}

void ftn::makemaps(){
    for (int i = 0; i <= n; i++){
        maps.push_back({});
        tree.push_back({});
    }
    for (vector<int> wire:wires){
        maps[wire[0]].push_back(wire[1]);
        maps[wire[1]].push_back(wire[0]);
    }
}

void ftn::maketree(int pre, int now){
    for (int next:maps[now]){
        if (next != pre){
            tree[now].push_back(next);
            maketree(now,next);
        }
    }
}

int ftn::count(int idx){
    int tmp = 1;
    if (tree[idx].size() == 0){
        if (ans > n-2){ans = n-2;}
    }
    else{
        for (int next:tree[idx]){
            tmp += count(next);
        }
        int T = n - 2*tmp >= 0 ? n - 2*tmp: 2*tmp-n;
        if (ans > T){ans = T;}
    }
    // cout << "idx : " << idx << endl;
    // cout << "count : " << tmp << endl;

    return tmp;
}

int solution(int n, vector<vector<int>> wires) {
    ftn sol(n,wires);
    sol.makemaps();
    sol.maketree(0,1);
    sol.count(1);

    return ans;
}
#include <bits/stdc++.h>

using namespace std;

int ftn(vector<int> A,vector<int> B){
    return abs(A[0] - B[0]) + abs(A[1] - B[1]);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    vector<int> L = {4,0}, R = {4,2};
    
    for (int num : numbers){

        if (num != 0 && num%3 == 0){
            answer += "R";
            R = {(int)num/3,2};
        }
        else if ((num+2)%3 == 0){
            answer += "L";
            L = {(int)(num+2)/3,0};
        }
        else {
            vector<int> coord {(int) num == 0? 4:(num+1)/3,1} ;
            if ((ftn(coord,L) > ftn(coord,R)) | ((ftn(coord,L) == ftn(coord,R)) & (hand == "right")) ){
                answer += "R";
                R = coord;
            }
            else{
                L = coord;
                answer += "L";
            }
        }
    }
    
    return answer;
}
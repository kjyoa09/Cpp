#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int l= 0,r=0 ;
    for (char S:s){
        if  (S == ')'){r++;}
        else {l++;}
        
        if (r>l){return false;}
    }
    return r==l ? true:false;
}
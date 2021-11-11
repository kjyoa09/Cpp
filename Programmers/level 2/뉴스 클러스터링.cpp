#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

map<string,int> dic1, dic2;
set<string> set1,set2;

void ftn(string str, map<string,int>& dic, set<string>& set){
    for (int i = 1; i < str.size(); i++){
        if ((('a'<=str[i] && str[i]<='z') || ('A'<=str[i] && str[i]<='Z')) && (('a'<=str[i-1] && str[i-1]<='z') || ('A'<=str[i-1] && str[i-1]<='Z'))){
            
            string tmp = "";
            tmp += 'A' <= str[i-1] && str[i-1] <= 'Z' ?  str[i-1] - 'A' + 'a' : str[i-1];
            tmp += 'A' <= str[i] && str[i] <= 'Z' ?  str[i] - 'A' + 'a' : str[i];
            dic[tmp] ++;
            set.insert(tmp);
        }
    }
}


int solution(string str1, string str2) {

    
    ftn(str1,dic1,set1);
    ftn(str2,dic2,set2);
    
    vector<string> intsec,Union;
    set_intersection(set1.begin(),set1.end(),set2.begin(),set2.end(),back_inserter(intsec));
    for(string s:set2){set1.insert(s);}
    
    float a=0,b=0;
    for(string s:intsec){a += min(dic1[s],dic2[s]);}
    for(string s:set1){
        b += max(dic1.find(s) == dic1.end() ? 0:dic1[s],
                 dic2.find(s) == dic2.end() ? 0:dic2[s]);
    }
    return b==0 ? 65536:(int)65536*(a/b);

}
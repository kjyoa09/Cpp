#include <string>
#include <list>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    list<string> lis;
    int answer = 0;  
    if (cacheSize == 0){return 5*cities.size();}
    for (string tmp:cities){
        string city = "";
        for (char t:tmp){city+=tolower(t);}
        if (find(lis.begin(),lis.end(),city) == lis.end()){
            answer += 5;
            if (lis.size() == cacheSize){lis.pop_front();}
        }
        else{
            answer += 1;
            lis.erase(find(lis.begin(),lis.end(),city));
        }
        lis.push_back(city);                
    }
    

    return answer;
}

using namespace std;

int solution(int n) {
    int answer = 1,lt = 1, rt = 1, num = 1;
    
    while (lt <= rt && rt <= (int)n/2+2){
        
        if(num == n){
            answer++;
            num -= lt;
            lt ++;
        }
        else if (num < n){
            rt++;
            num += rt;
        }
        else{
            num -= lt;
            lt++;
        }
    }
    
    return answer;
}
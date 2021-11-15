using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    
    while (a != b){
        a = ((int)a/2)*2 == a ? (int)a/2:((int)a/2+1);
        b = ((int)b/2)*2 == b ? (int)b/2:((int)b/2+1);
        answer ++;
    }

    return answer;
}
#include <iostream>
using namespace std;
// float main() main' must return 'int' >> float로 하면 안되네
int main()
{
    // 조건식
    // int x = 3;
    // if (x>=3){
    //     int a = 3;
    //     cout << a <<enl;
    // }

    // else {
    //     int a = 4;
    //     cout << a <<endl;
    //     }

    // While
    // int i = 1;
    // while (i <= 3){
    //     i++;
    //     cout <<i<<endl;
    // }


    // For 문
    // double x = 2.0, xn = 1.0, exp_x = 1.0;
    // long fac = 1;
    // for (int i = 1; i<=10; i++){
    //     xn *= x;
    //     fac *= i;
    //     exp_x += xn/fac;

    //     cout << exp_x << endl;
    // }

    int primes[] = {2,3,4,5,6,7,8,9};
    // for (int i : primes)
    for (int i = 0; i <= 5; i++)
    {
        cout << primes[i] << endl;
    }
    return 0;
}
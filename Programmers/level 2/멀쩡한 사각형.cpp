using namespace std;

int gcd(int w,int h){
    int tmp = w%h;
    if (tmp == 0){
        return h;
    }
    else{return gcd(h,tmp);}
}
long long solution(int w,int h) {
    int tmp = gcd(w,h);
    return 1LL * w*h - tmp * ((int)w/tmp + (int)h/tmp - 1) ;
}
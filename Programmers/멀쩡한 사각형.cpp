using namespace std;


int gcd(int w, int h) {  // 최대공약수 (유클리드 호제법)
    int mod = w % h; 
    while (mod > 0) { 
        w = h; 
        h = mod; 
        mod = w % h; 
    } 
    return h;
}


long long solution(int w,int h) {
    long long answer = 1;
    int g = gcd(w,h);

    answer = (long)w*h -( w+h-g); // w*h인 경우 long으로 캐스팅
    
    
    return answer;
}
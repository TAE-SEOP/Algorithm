#include <string>
#include <vector>

using namespace std;

char first(int b){
    if(b == 0) return '1';
    else if(b == 1) return '2';
    else return '4';
}

char after(int b){
    if(b == 1) return '1';
    else if(b == 2) return '2';
    else return '4';
}

string solution(int n) {
    string answer = "";
    n =n -1;
    int a = n/3;
    int b = n%3;
    answer = first(b);
    if(a != 0){
        while(true){
            b = a%3;
            a = a/3;
            answer = after(b) + answer;
            if(b == 0) a-=1;  // 3진법이라면 012 지만 여기서는 123으로 진행하기 때문에 3으로 나누어 떨어지면 몫을 -1하여 진행
            if(a == 0) break;
        }
    }
    return answer;
}
#include <string>
#include <vector>

using namespace std;

vector<int>::iterator ptra;
vector<bool>::iterator ptrb;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    ptrb = signs.begin();
    for(ptra = absolutes.begin(); ptra != absolutes.end(); ptra++){
        if(*ptrb == true) answer += *ptra;
        else answer -= *ptra;
        ptrb++;
    }

    return answer;
}

/*
absolutes : 숫자를 담은 배열
signs : 부호를 담은 배열
*/
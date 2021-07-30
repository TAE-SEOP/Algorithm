#include <string>
#include <vector>

using namespace std;
vector<int>::iterator ptra;
vector<int>::iterator ptrb;
int solution(vector<int> a, vector<int> b) {
    int answer = 0;
    ptrb = b.begin();
    for(ptra = a.begin(); ptra != a.end(); ptra++){
        answer += (*ptra) * (*ptrb);
        ptrb++;
    }
    
    return answer;
}

/*
내적 구하기
*/
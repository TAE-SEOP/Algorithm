#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

int select(vector<char>& v, char a){
    for(int i = 0; i<v.size(); i++){
        if(a == v[i]) return i;
    }
    return -1;
}

bool condition(int first, int second, int dis, char t){
    if(t == '=') return abs(first-second) == dis ? true:false;
    else if(t == '<') return abs(first-second) < dis ? true:false;
    else return abs(first-second) > dis ? true:false;
}

int solution(int n, vector<string> data) {
    int answer = 0;
    bool flag;
    vector<char> v = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    
    do{
        flag = true;
        for(auto& a : data){
            int first = select(v, a[0]);
            int second = select(v, a[2]);
            int dis = (a[4] - '0') +1;
            flag = condition(first,second,dis,a[3]);
          
            if(flag == false) break;
        }
        if(flag == true) answer++;
    }while(next_permutation(v.begin(), v.end()));
    
    return answer;
}
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    unordered_map <string,int> participants;
    
    for(string name : participant){
        ++participants[name];
    }
    for(string name : completion){
        --participants[name];
    }
    for(auto pair : participants){
        if(pair.second > 0){
            return pair.first;
        }
    }
    
}


/*
unorderd_map
- map보다 빠른 탐색을 하기 위한 자료구조
- 중복 데이터 허용 x
- 헤쉬테이블로 구현하여 시간복잡도가 o(1)이다.
   *map은 binary search tree로 시간복잡도가 o(log n)이다.
*/
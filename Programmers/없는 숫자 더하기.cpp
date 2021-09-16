#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    bool n[10] = {false,};
    for(int a : numbers){
        n[a] = true;
    }
    
    for(int i = 0; i< 10; i++){
        if(!n[i]) answer += i;
    }
    
    return answer;
}
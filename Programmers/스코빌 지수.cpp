#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> pq(scoville.begin(),scoville.end());
   
    while(pq.top() < K && pq.size() >1){
        int f = pq.top();
        pq.pop();
        int s = pq.top();
        pq.pop();
        pq.push(f+s*2);
        answer++;
    }
    if(pq.top() < K) answer=-1;
    return answer;
}
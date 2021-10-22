# collections의 내장 함수 counter는 hash들의 값의 개수를 세는 함수
# Counter() 객체끼리 덧셈, 뺄셈 가능

import collections

def solution(participant, completion):
    answer = ''
    answer = collections.Counter(participant) - collections.Counter(completion)
    return list(answer)[0]


# cpp풀이

# #include <string>
# #include <vector>
# #include <unordered_map>
# using namespace std;

# string solution(vector<string> participant, vector<string> completion) {
    
#     unordered_map <string,int> participants;
    
#     for(string name : participant){
#         ++participants[name];
#     }
#     for(string name : completion){
#         --participants[name];
#     }
#     for(auto pair : participants){
#         if(pair.second > 0){
#             return pair.first;
#         }
#     }
    
# }
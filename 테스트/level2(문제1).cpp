#include<string>
#include <iostream>
#include <stack>

using namespace std;
stack <char> stk;

bool solution(string s)
{
    bool answer = true;
    for(char c : s){
        if(c == '(') stk.push(c);
        else{
            if(stk.empty()) {
                answer = false;
                break;
            }
            else{
                if(stk.top() == '(') stk.pop();
            }
        }
    }
    if(!stk.empty()) answer = false;
    return answer;
}

/*
활호 짝 맞는지 확인
*/
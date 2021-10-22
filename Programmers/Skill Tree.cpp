#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map <char,int> s;
    bool check = true;
    
    for(int i = 0; i< skill.size();i++) s[skill[i]] = i+1;
    
    for(int i = 0; i< skill_trees.size();i++){
        int count = 1;
        for(int j = 0; j < skill_trees[i].size(); j++){
            if(s[skill_trees[i][j]] > count){
                check = false;
                break;
            } 
            else if(s[skill_trees[i][j]] == count)count++;
        }
        if(check) answer++;
        check = true;
    }
    return answer;
}
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0; int tmp;
    vector<int> v;
    for(int i = 0; i< moves.size(); i++){
        tmp = moves[i]-1;
        for(int j = 0; j < board[tmp].size();j++){
            if(board[j][tmp] != 0){
               
                v.push_back(board[j][tmp]);
                board[j][tmp] = 0;
                break;
            }
        }
        if(v[v.size()-1] == v[v.size()-2]){
            v.pop_back();
            v.pop_back();
            answer+=2;
        }
    }
    
    return answer;
    
}
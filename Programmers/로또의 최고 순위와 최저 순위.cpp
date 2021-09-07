#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>::iterator iter;
vector<int>::iterator iter2;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int same = 7;
    
    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());
    
    for(iter = win_nums.begin(); iter != win_nums.end();iter++){
        iter2 = find(lottos.begin(),lottos.end(), *iter);
        if(iter2 != lottos.end()) same--;
    }
    int zero = count(lottos.begin(), lottos.end(), 0);
    if(same >= 7) same = 6;
    if(zero == 6) zero = 5;
    answer.push_back(same-zero);
    answer.push_back(same);
    
    
    return answer;
}
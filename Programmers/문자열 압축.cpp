#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 1000;
    int cnt = 0;
    string c = "";
    string tmp = "";
    for (int i = 1; i < s.size(); i++) {
        for (int j = 0; j < s.size(); j += i) {
       
            if(tmp.size() == 0) tmp = s.substr(j,i); 
            
            else if (j + i >= s.size()) {  // 끝을 넘은 경우
                if (tmp == s.substr(j, i)) { // 중복
                    cnt++;
                    c += to_string(cnt + 1);
                    c += tmp;
                    tmp = "";
                    cnt = 0;
                }
                else { //중복 x
                    if(cnt != 0) c += to_string(cnt + 1);
                    c += tmp;
                    c += s.substr(j, i);
                    tmp = "";
                    cnt = 0;
                }
            }
            
            else {
                if (tmp == s.substr(j, i)) cnt++;
                else {
                    if (cnt != 0) c += to_string(cnt + 1);
                    c += tmp;
                    tmp = s.substr(j, i);
                    cnt = 0;
                }
            }
        }

        if (c.size() < answer) answer = c.size();
        c = "";
    }
    if(s.size() == 1) answer = 1;
    return answer;
}
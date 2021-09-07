#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    string temp = "";
    int cnt;
    //1단계
    for(int i = 0; i < new_id.length(); i++){ 
        if(new_id[i] >= 'A' && new_id[i] <= 'Z') new_id[i] = tolower(new_id[i]);
    }
    //2단계
     for(int i = 0; i < new_id.length();i++){ 
        if((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9')||new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.'){
            temp += new_id[i];
        }
    }
    //3단계
    for(int i = 0; i< temp.length();i++){
        if(temp[i] == '.'){
            cnt = 0;
            for(int j=i+1;j<temp.length();j++){
                if(temp[j] != '.') break;
                cnt++;
            }
            if(cnt > 0){
                answer += '.';
                i+=cnt;
            }
            else answer += temp[i];
        }
        else answer += temp[i];
    }
        
    //4단계
    if(answer[0] == '.') answer.erase(0,1);
    if(answer[answer.length()-1] == '.') answer.erase(answer.length()-1,answer.length());
    //5단계
    if(answer.length() == 0) answer+='a';
    //6단계
    if(answer.length() >= 16) answer.erase(15,answer.length());
    while(answer.back() == '.'){
        answer.pop_back();
    }
    //7단계
    if(answer.length()<3){
        while(answer.length()<3){
            answer += answer.back();
        }
    }
    return answer;
}
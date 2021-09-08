#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> uid;
    vector<string> o;
    map<string,string> unick;

    string op; string id; string nick;
    stringstream s;
    for(int i=0; i<record.size();i++){
        s.str(record[i]);
        s >> op;
        if(op == "Enter"){
            s >> id;
            s >> nick;
            o.push_back("님이 들어왔습니다.");
            uid.push_back(id);
            unick[id] = nick;
        }
        else if(op == "Leave"){
            s >> id;
            o.push_back("님이 나갔습니다.");
            uid.push_back(id);
        }
        else{
            s>> id;
            s>>nick;
            unick[id] = nick;
        } 
        s.clear();
    }
    for(int i = 0; i <o.size();i++){
        answer.push_back(unick[uid[i]] + o[i]);
    }
    return answer;
}
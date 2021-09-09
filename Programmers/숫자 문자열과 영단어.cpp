#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string ans  ="";
    string m[10] ={"zero","one","two","three","four","five","six","seven","eight","nine"};
    string t[10] ={"0","1","2","3","4","5","6","7","8","9"};
    string tmp="";

    for(auto i : s){
        if(i>='0' && i<='9') ans += i;
        else{
            tmp += i;
            for(int j =0 ; j<10;j++){
                if(tmp == m[j]){
                    ans+=t[j];
                    tmp = "";
                    break;
                }
            }
        }
    }
    //answer = stoi(ans);
    return stoi(ans);
}
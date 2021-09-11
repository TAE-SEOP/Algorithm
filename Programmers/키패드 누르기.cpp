#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int lu =10 ; int ru =12 ; int rc; int lc;
    
    int *p ; bool l_cnt = false; bool r_cnt = false;
    for(int i = 0 ; i< numbers.size(); i++){
       if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
           answer += "L";
           lu = numbers[i];
       }
       else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
           answer += "R";
           ru = numbers[i];
       }
       else{
         if(numbers[i] == 0) numbers[i] = 11;
         rc = abs(numbers[i]-ru);
         lc = abs(numbers[i]-lu);
         rc = (rc/3)+(rc%3);
         lc = (lc/3)+(lc%3);
         if(rc < lc){
             ru = numbers[i];
             answer += 'R';
         }
         else if(rc > lc){
             lu = numbers[i];
             answer += 'L';
         }
         else{
            if (hand == "left") {
                lu = numbers[i];
                answer += 'L';
            }
            else {
                ru = numbers[i];
                answer += 'R';
            }
         }
       }
       //cout << lu << "  " << ru<<endl;
    }
    return answer;
}
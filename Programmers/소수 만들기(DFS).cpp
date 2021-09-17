#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

vector<int> v;
int e;
int result = 0;
bool arr[50000];

/*
에라토스테네스의 체를 사용하려 했으나 범위를 어디까지 해야할지 고민하다가 그냥 N의 제곱근까지만 확인하는 방식으로 구함.
풀고 나서 50000범위까지 에라토스테네스의 체를 사용하고 구현해보니 9000ms걸려서
vector 안에 모든 수를 더하고 거기까지만 에라토스테네스의 체를 만들어 쓰는 걸로 바꿈 -> 이게 가장 빠른 방식
*/

bool check(int number){   // 소수인지 판별, 2~sqrt(n)까지만 확인하여 판별
    if(number < 2) return false;
    else{
        int tmp = (int)sqrt(number);
        for(int i = 2; i <= tmp; i++)
            if(number % i == 0) return false;
        return true;
    }
}

void check2(int n){  // 에라토스테네스의 체
   for(int i = 2; i<=n;i++) arr[i] =true;
   for(int i =2;i*i <= n; i++){
       if(!arr[i]) continue;
       for(int j=i*i; j<=n; j+=i) arr[j] =false;
   }
}

void dfs(int idx,int cnt, int a){  //dfs를 사용해 조합 구현 , n개중 3개 선택

    if(cnt == 3){
        if(arr[a]) result++;
        return;
    }
    for(int i = idx; i<v.size(); i++) dfs(i+1,cnt+1, a + v[i]);
}

int solution(vector<int> nums) {
    int answer = -1;
    v = nums;
    int sum = 0;
    for(int i = 0; i< nums.size();i++) sum +=nums[i];
    check2(sum);
    dfs(0,0,0);
    return result;
}
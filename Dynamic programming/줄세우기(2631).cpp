#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <stdio.h>


using namespace std;
/*
LIS(최장 증가 수열)
어떤 수열에서 특정 부분을 지워서 만들어낼 수 있는 증가 부분 수열 중 가장 긴 수열
순증가 : 1,2,3  -> 뒷 숫자가 앞 숫자보다 무조건 큰 경우
단조증가 : 1,1,2,3 -> 뒷 숫자가 앞 숫자 이상 ex) 피보나치 수열

인덱스를 하나씩 증가시키면서, 그 인덱스에서 끝나느 최장 증가 수열의 길이를 구한다.
arr[i] =  i번째까지 최장 증가 수열 길이의 배열
dp[i] = 주어진 배열

*/


int main() {
	int n;
	int dp[240];
	int max = 0;
	int arr[240];
	int result = 0;
	int temp = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> dp[i];
	}
	max = 1;
	for (int i = 1; i <= n; i++) {
		arr[i] = 1;
		for (int j = 1; j < i; j++) {
			if (dp[j] < dp[i] && arr[j] + 1 > arr[i]) {
				arr[i] = arr[j] + 1;
				if (max < arr[i]) max = arr[i];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;
	cout << n-max;

	return 0;
}
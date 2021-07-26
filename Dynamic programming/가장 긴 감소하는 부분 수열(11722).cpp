#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;



int main() {
	int n;
	int a[1003];
	int b[1003];

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int max = 1;
	for (int i = 0; i < n; i++) {
		b[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[j] > a[i] && b[j] + 1 > b[i]) {
				b[i] = b[j] + 1;
				if (max < b[i]) max = b[i];
			}
		}
	}

	cout << max;

	return 0;
}

/*
줄세우기(2631)과 비슷한 문제
LDS(최장 감소 수열)을 찾는 문제
배열에서 현재 index에서 이전 index 값들을 확인하면서 현재 index보다 작은 숫자가 있으면 count?

*/
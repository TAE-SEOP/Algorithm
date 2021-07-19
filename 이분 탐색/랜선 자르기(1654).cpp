#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
long long a[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long k, n;
	long long max=0;
	cin >> k >> n;

	for (int i = 0; i < k; i++) {
		cin >> a[i];
		if (max < a[i]) max = a[i];
	}
	long long start = 1;
	long long end = max;
	long long result = 0;
	long long total = 0;

	while (start <= end) {
		long long mid = (start + end) / 2;
		total = 0;
		for (int i = 0; i < k; i++) {
			total += a[i] / mid;
		}
		if (total >= n) {
			if (result < mid) result = mid;
			start = mid + 1;
		}
		else end = mid - 1;
	}
	
	cout << result;
	
	return 0;

}

/* 
자르는 것을 mid 기준으로 나누는 것이기 때문에
start를 0으로 하면... 나중에 mid가 0이 되어 0으로 나누는 상황이 발생..
start를 1로 바꾸어 해결..
*/
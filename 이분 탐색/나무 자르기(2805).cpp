#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
int a[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long int n, m;
	long long int max=0;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (max < a[i]) max = a[i];
	}
	long long int t = 0;
	long long int left = 0;
	long long int right = max;
	long long int result = 0;

	while (left <= right) {
		long long int mid = (left + right) / 2;
		result = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] > mid) result += a[i] - mid;
		}
		if (result >= m) {
			if (t < mid) t = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}
	
	cout << t;
	
	return 0;
}

/*
처음에 자르는 길이를 따로 두고,
배열을 정렬하고, 배열 내에서 잘리는 길이를 구하는 방식으로 이분 탐색을 해서, 시간 초과가 있었다.

배열을 정렬하지 않고, 자를 길이를 이분 탐색을 통해 결정하는 방식을 통해 해결

*/
	/*int k = 0;
	int index=n-1;
	while (true) {
		int start = 0;
		int end = n - 1;
		int result = 0;
		
		while (start <= end) {
			int mid = (start + end) / 2;
			if (a[mid] == max - k) {
				index = mid;
				break;
			}
			else if (a[mid] < max - k) start = mid + 1;
			else if (a[mid] > max - k) end = mid - 1;
		}
		for (int i = index; i < n; i++) {
			result += a[i] - (max - k);
		}
		if (result >= m) break;
		k++;
	}
	cout << max - k;*/

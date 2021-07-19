#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
signed long long int a[500001];
signed long long int b[500001] = { 0, };
signed long long int temp;
int n,m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	sort(a, a + n);

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> temp;
		int start = 0;
		int end = n - 1;
		while (start <= end) {
			int mid = (start + end) / 2;
			if (a[mid] == temp) {
				b[i] = 1;
				break;
			}
			else if (a[mid] < temp) start = mid + 1;
			else end = mid - 1;
		}
	}

	for (int i = 0; i < m; i++) {
		cout << b[i] << " ";
	}

	return 0;

}

/*
딱히
*/
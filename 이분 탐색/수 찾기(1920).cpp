#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
int n, m;
int a[100003];
int b[100003];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	int item;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	cin >> m;


	for (int i = 0; i < m; i++) {
			cin >> b[i];
		int result = 0;
		item = b[i];
		int left = 0;
		int right = n - 1;
			while (left <= right) {
				long int mid = (left + right) / 2;
				if (a[mid] == item) {
					result = 1;
					break;
				}
				else if (a[mid] > item) right = mid - 1;
				else if (a[mid] < item) left = mid + 1;
		
			}
		b[i] = result;
	}
	for (int i = 0; i < m; i++) {
		cout << b[i] << "\n";
	}
	return 0;

}


/*
시간 초과 에러
endl과  "\n"의 차이
endl : flush()함수를 겸하기 때문에 실행마다 출력 버퍼를 지워주는 과정이 생겨 느리다.
endl을 "\n"으로 바꾸니 해결
*/
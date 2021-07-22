#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;

char str[54];
long long int h[54];
long long int n;
long long int result = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long int r = 1;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str[i];
		h[i] = int(str[i]) - 96;
		result += (r * h[i]) % 1234567891;
		r *= 31;
		r %= 1234567891;
	}
	result %= 1234567891;
	cout << result;

	return 0;

}

/*
large 범위인 1 <= L <= 50 범위에서 수가 기하급수적으로 커지는 것에 대해
고려하지 않아서 틀렸었다.
31의 제곱수들도 mod 1234567891를 해주어서 해결함.
*/
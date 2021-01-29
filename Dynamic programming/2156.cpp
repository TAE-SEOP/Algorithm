#include <iostream>

using namespace std;

int compare(int a, int b, int c) {
	if (a > b) {
		return a > c ? a : c;
	}
	else return b > c ? b : c;
}

int main() {
	long long int n;
	unsigned int dp[100004];
	long long int result[100004];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> dp[i];
	}
	result[1] = dp[1];
	result[2] = result[1] + dp[2];
	result[3] = compare(dp[1] + dp[2], dp[2] + dp[3], dp[1]+dp[3]);
	for (int i = 4; i <= n; i++) {
		result[i] = compare(result[i - 3] + dp[i - 1] + dp[i], result[i - 2] + dp[i], result[i-1]);
	}
	cout << result[n]<<"\n";
	return 0;
}
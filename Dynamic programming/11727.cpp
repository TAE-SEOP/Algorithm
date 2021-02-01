
#include <iostream>
using namespace std;

int main() {
	int n;
	long long int dp[1003];
	cin >> n;
	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= n; i++) {
		if (i % 2 == 0) {
			dp[i] = ((dp[i-1] - 1) * 4 + 1 - (((dp[i - 1] - 2) * 4) / 2))%10007 ;
		}
		else {
			dp[i] = ((dp[i-1] - 1) * 2 + 1) % 10007;
		}
	}

	cout << dp[n] % 10007;

	return 0;

}
#include <iostream>

using namespace std;

int compare(int a, int b) {
	return  a > b ? a : b;
}


int main() {
	int n;
	long long int total = 0;
	int dp[301];
	int dp2[301] = {0};
	dp[0] = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> dp[i];
	for (int i = 1; i <= n; i++) {
		if (i == 1) dp2[i] = dp[i];
		else if (i == 2) dp2[i] = dp[i - 1] + dp[i];
		else dp2[i] = compare(dp2[i - 3] + dp[i - 1] + dp[i], dp2[i - 2] + dp[i]);

	}
	
	cout << dp2[n] << "\n";
	return 0;
}
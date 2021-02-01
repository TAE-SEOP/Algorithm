#include <stdlib.h>
#include <iostream>
using namespace std;



int main() {
	int n;
	long long int result=0;
	cin >> n;
	long long int dp[1003][10] = { 0, };
	
	
	for (int i = 0;i < 10;i++) dp[1][i] = 1;
	
	for (int i = 2;i <= n;i++) {
		for (int j = 0;j <= 9;j++) {
			if (j == 0) dp[i][j] = 1;
			else {
				dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 10007;
			}
		}
	}
	for (int i = 0;i < 10;i++) {
		result += dp[n][i];
		result %= 10007;
	}

	cout << result;

	


	return 0;

}
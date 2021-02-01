
#include <iostream>
using namespace std;


int main() {
	int t;
	int n, m;
	long long int dp[30][30] = { 0, };


	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			if (i == j || j == 0) dp[i][j]=1;
			else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
	cin >> t;

	for (int i = 1; i <= t;i++) {
		cin >> n >> m;		
		cout << dp[m][n] << "\n";
	}

	return 0;

}
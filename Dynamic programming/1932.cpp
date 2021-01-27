#include <iostream>

using namespace std;

int compare(int a, int b) {
	return a > b ? a : b;
}


int main() {
	int n;
	int dp[505][505];
	long long int arr[505][505];
	int result=0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> dp[i][j];
		}
	}

	arr[1][1] = dp[1][1];
	arr[2][1] = arr[1][1] + dp[2][1];
	arr[2][2] = arr[1][1] + dp[2][2];
    
	for (int i = 3; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if(j == 1) arr[i][j] = arr[i-1][1] + dp[i][j];
			arr[i][j] = compare(arr[i-1][j-1],arr[i-1][j]) + dp[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		if (result < arr[n][i]) result = arr[n][i];
	}
	cout << result << "\n";
	return 0;

}
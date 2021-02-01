#include <stdlib.h>
#include <iostream>
using namespace std;

int compare(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int t;
	int c;
	cin >> t;

	for (int i = 1;i <= t;i++) {
		cin >> c;
		int **arr = (int **)malloc(sizeof(int *) * 2);
		arr[0] = (int*)malloc(sizeof(int) * c);
		arr[1] = (int*)malloc(sizeof(int) * c);
		
		int** dp = (int**)malloc(sizeof(int*) * 2);
		dp[0] = (int*)malloc(sizeof(int) * c);
	    dp[1] = (int*)malloc(sizeof(int) * c);

		for (int j = 0; j < c;j++) cin >> arr[0][j];
		for (int j = 0; j < c;j++) cin >> arr[1][j];

		for (int j = 0;j < c;j++) {
			if (j == 0) {
				dp[0][0] = arr[0][0];
				dp[1][0] = arr[1][0];
			}
			else if (j == 1) {
				dp[0][1] = dp[1][0] + arr[0][1];
				dp[1][1] = dp[0][0] + arr[1][1];
			}
			else {
				dp[0][j] = compare(dp[1][j-1] + arr[0][j] , dp[1][j-2] + arr[0][j]);
				dp[1][j] = compare(dp[0][j - 1] + arr[1][j], dp[0][j - 2] + arr[1][j]);
			}
		}
		cout << compare(dp[0][c - 1], dp[1][c - 1]) << "\n";
		free(arr);
		free(dp);

	}

	return 0;

}
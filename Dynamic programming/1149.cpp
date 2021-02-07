#include <iostream>

using namespace std;

int compare(int a, int b) {
	return a < b ? a : b;
}

int compare2(int a, int b,int c) {
	if (a > b) {
		return b < c ? b : c;
	}
	else return a < c ? a : c;
	
}


int main() {
	int n;
	int pd[1003][3];
	int result[1003][3];
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> pd[i][0] >> pd[i][1] >> pd[i][2];
	}
	
	result[1][0] = pd[1][0];
	result[1][1] = pd[1][1];
	result[1][2] = pd[1][2];

	for (int i = 2; i <= n; i++) {
		result[i][0] = pd[i][0] + compare(result[i-1][1], result[i-1][2]);
		result[i][1] = pd[i][1] + compare(result[i-1][0], result[i-1][2]);
		result[i][2] = pd[i][2] + compare(result[i-1][1], result[i-1][0]);
	}
		cout << compare2(result[n][0], result[n][1], result[n][2]) << "\n";

	return 0;
}
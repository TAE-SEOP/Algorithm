#include <iostream>

using namespace std;

int compare(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int n;
	cin >> n;
	long long int result[100];

	result[1] = 1;
	result[2] = 1;
	for (int i = 3; i <= n; i++) {
		result[i] = result[i - 2] + result[i - 1];
	}
	cout << result[n]<<"\n";
	return 0;
}
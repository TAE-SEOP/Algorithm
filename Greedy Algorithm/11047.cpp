#include <stdlib.h>
#include <iostream>
using namespace std;



int main() {
	int n, k;
	int temp;
	int result = 0;
	cin >> n >> k;
	int* value = (int*)malloc(sizeof(int) * n + 1);
	for (int i = 1; i <= n; i++) cin >> value[i];
	for (int i = n; i > 0; i--) {
		if (k / value[i] != 0) {
			result += k / value[i];
			k = k % value[i];
		}
	}
	cout << result;
	return 0;
}
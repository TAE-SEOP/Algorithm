#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int n;
	int temp;
	int result;
	cin >> n;

	for (int i = 1; i < n;i++) {
		temp = i;
		result = i;
		while (temp != 0) {
			result += temp % 10;
			temp /= 10;
		}
		if (result == n) {
			result = i;
			break;
		}
		result = 0;
	}
	cout << result;

	return 0;

}

#include <iostream>
using namespace std;


int main() {
	int n;
	cin >> n;
	long long int count[101][10] = { 0, };
	long long int total = 0;

	for (int i = 1;i < 10;i++) {
		count[1][i] = 1;
	}
	for (int j = 2;j <= n; j++) {
		for (int i = 0; i < 10;i++) {
			if (i == 0) {
				count[j][i] += count[j - 1][i + 1] % 1000000000;
			}
			else if (i == 9) {
				count[j][i] += count[j - 1][i - 1] % 1000000000;
			}
			else {
				count[j][i] = (count[j - 1][i - 1] + count[j - 1][i + 1]) % 1000000000;
			}
		}
	}

	for (int i = 0; i < 10;i++) {
//		cout <<"count["<<i<<"] : "<< count[i] << '\n';
		total += count[n][i];
	}

	cout << total % 1000000000;

	return 0;

}
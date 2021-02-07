
#include <string>
#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int number, count = -1, total = 0, m=0;
	char start=0;
	int what;
	cin >> number;
	char a[101][101];
	a[0][0] = '\0';
	for (int i = 0; i < number; i++) {
		cin >> a[i];
		count = -1;
		start = 0;
		m = 0;
		for (int j = 0; j < 101; j++) {
			if (a[i][j] == '\0' && a[i][m] != '\0') {
				j = m+1;
				count = -1;
				start = 0;
			}

			if (start == 0) {
				start = a[i][j];
				count = j;
				m = j;
			}
			else if (start == a[i][j]) {
				if (count == j - 1) count++;
				else {
					what = 0;
					break;
				}
			}
		 if (a[i][j] == '\0' && a[i][m] == '\0') {
				what = 1;
				break;
			}
		}
		if (what == 1) total++;
	}
	cout << total << endl;
	return 0;
}
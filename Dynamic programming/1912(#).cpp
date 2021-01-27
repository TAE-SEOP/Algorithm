
#include <iostream>
using namespace std;

int compare(int a, int b) {
	return a > b ? a : b;
}


int main() {
	int seq[100003] = { 0, };
	int a=-99999;
	int b=-99999;
	int number;

	cin >> number;
	for (int i = 1; i <= number;i++) cin >> seq[i];
	for (int i = 1; i <= number;i++) {
		if (i == 1) a = seq[i];
		else if(i==2) {
			a = compare(a, seq[i]);
			b = compare(seq[i - 1] + seq[i],seq[i]);
		}
		else {
			a = compare(a, b);
			b = compare(seq[i], b + seq[i]);
		}
	}
	if (a > b) cout << a;
	else cout << b;

	return 0;

}
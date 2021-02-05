#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n[10];
	int a = 0;
	int b = 1;
	int total = 0;
	int temp;
	for (int i = 0;i < 9; i++) {
		cin >> n[i];
		total += n[i];
	}

	sort(n, n+9);

	while (true) {
		temp = total;
		temp -= n[a];
		temp -= n[b];
		if (temp == 100) break;
		if (b < 9) b++;
		else {
			a++;
			b = a + 1;
		}
	}

	for (int i = 0;i <9;i++) {
		if(i != a && i != b)  cout << n[i] << "\n";
	}

	return 0;

}
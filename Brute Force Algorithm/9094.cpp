#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int t;
	int n, m;
	int count;
	double a;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		count = 0;
		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (((i * i + j * j + m) % (i * j)) == 0) {
					count++;
				}
			}
		}
		cout << count << "\n";
	}



	return 0;

}
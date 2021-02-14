#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int main() {
	int n, x,y;
	vector <pair<int, int>> number;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> x >> y;
		number.push_back(make_pair(x,y));
	}
	sort(number.begin(), number.end());

	for (int i = 0;i < number.size();i++) {
		cout << number[i].first << " " << number[i].second << "\n";
	}

	return 0;

}
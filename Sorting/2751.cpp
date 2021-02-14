#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;


int main() {
	int n,temp;
	vector <int> number;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> temp;
		number.push_back(temp);
	}
	sort(number.begin(), number.end());

	for (int i = 0;i < number.size();i++) {
		cout << number[i] << "\n";
	}

	return 0;

}
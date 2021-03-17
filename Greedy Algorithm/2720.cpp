#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int t;
	int money;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> money;
		cout << money / 25 << ' ';
		money = money % 25;
		cout << money / 10 << ' ';
		money = money % 10;
		cout << money / 5 << ' ';
		money = money % 5;
		cout << money << "\n";
	}


	return 0;

}
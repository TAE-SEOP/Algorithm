#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	long long int n;
	cin >> n;
	int money[6] = { 500, 100, 50,10, 5, 1 };
	int cal;
	int count = 0;
	cal = 1000 - n;
	for (int i = 0; i < 6;i++) {
		count += cal / money[i];
		cal = cal% money[i];
	}
	cout << count << "\n";

	return 0;

}
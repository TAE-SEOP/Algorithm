#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main() {
	int a,b,c;
	int current = 0;
	vector <pair<int, int>> cow;
	vector<pair<int, int> >::iterator iter;

	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> b >> c;
		cow.push_back(make_pair(b, c));
	}
	sort(cow.begin(), cow.end());
	
	for (iter = cow.begin(); iter != cow.end();iter++) {
		if (current <= iter->first) current = iter->first;
		current += iter->second;
	}
	cout << current;
	return 0;
}
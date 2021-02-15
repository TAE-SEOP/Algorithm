#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <tuple>
#include <algorithm>
using namespace std;


int main() {
	vector <string> either;
	vector <string> both;
	vector <string>::iterator iter;
	int m, n,number;
	string temp;
	
	cin >> m >> n;

	for (int i = 0; i < m+n;i++) {
		cin >> temp;
		either.push_back(temp);
	}

	sort(either.begin(), either.end());

	for (int i = 0; i < either.size()-1; i++) {
		if (either[i] == either[i + 1] ) both.push_back(either[i]);
	}

	cout << both.size() << "\n";
	for (int i = 0; i < both.size();i++) {
		cout << both[i] << "\n";
	}
	
	return 0;

}
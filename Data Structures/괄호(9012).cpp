#include <stdlib.h>
#include <iostream>
#include <stack>
#include <string.h>
#include <queue>
#include <algorithm>
#include <stdio.h>

using namespace std;
stack <char> s;

int main() {
	int a,c;
	string b;
	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> b;
		for (int j = 0; j < b.length(); j++) {
			if (s.empty()) s.push(b[j]);
			else if (b[j] == '(') s.push(b[j]);
			else {
				if (s.top() == '(') s.pop();
				else s.push(b[j]);
			}
		}
		if (s.empty()) cout << "YES" << endl;
		else cout << "NO" << endl;

		while (!s.empty()) {
			s.pop();
		}
	}

	return 0;
}
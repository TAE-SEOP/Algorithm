#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <stack>
#include <algorithm>
#include <stdio.h>
using namespace std;
stack <int> s;

void push(int b) {
	s.push(b);
}

void pop() {
	if (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}
	else cout << -1 << endl;
}

void size() {
	cout << s.size() << endl;
}

void top() {
	if (!s.empty()) {
		cout << s.top() << endl;
	}
	else cout << -1 << endl;
}

void empty() {
	if (s.empty() == 1) {
		cout << 1 << endl;
	}
	else cout << 0 << endl;
}


int main() {
	int a;
	string str;
	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> str;
		if (str == "push") {
			int b;
			cin >> b;
			push(b);
		}
		else if (str == "pop") pop();
		else if (str == "size") size();
		else if (str == "top") top();
		else if (str == "empty") empty();
	}
	return 0;
}
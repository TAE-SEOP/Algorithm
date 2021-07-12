#include <stdlib.h>
#include <iostream>
#include <stack>
#include <string.h>
#include <queue>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

int s,q;
int c, d;
int number = 0;
bool prime[10000] = { false, };
bool visit[10000] = { false, };
queue <pair<int,int>> de;


int change(int number, int i, int j) {
	int temp = number;
	if (i == 1) {
		temp -= (number / 1000) * 1000;
		temp += j * 1000;
	}
	else if (i == 2) {
		temp -= ((number / 100) % 10) * 100;
		temp += j * 100;
	}
	else if (i == 3) {
		temp -= ((number % 100) / 10) * 10;
		temp += j * 10;
	}
	else if (i == 4) {
		temp -= number % 10;
		temp += j;
	}
	return temp;
}

void de_con() {
	for (int i = 1000; i < 10000; i++) {
		prime[i] = 1;
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				prime[i] = 0;
				break;
			}
		}
	}
}


int bfs(int a, int b) {
	de.push(make_pair(a, 0));
	visit[a] = true;
	if (a == b) return 0;
	while (!de.empty()) {
		c = de.front().first;
		d = de.front().second;
		de.pop();
		int next = 0;
		for (int i = 1; i <= 4; i++) {
			for (int j = 0; j <= 9; j++) {
				int next = change(c, i, j);
				if (next <= b && next > 1000 && !visit[next] && prime[next]) {
					visit[next] = true;
					de.push(make_pair(next, d+1));
					number++;
				}
			}
		}
	}
	return d;
}

int main() {
	int a;
	cin >> a;
	de_con();
	for (int i = 0; i < a; i++) {
		cin >> s >> q;
		int result = bfs(s, q);
		if (result == -1) cout << "Impossible";
		else cout << result;
		memset(visit, false, sizeof(visit));
		if (i != a - 1) cout << endl;
	}
	return 0;
}
#include <stdlib.h>
#include <iostream>
#include <stack>
#include <string.h>
#include <queue>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;
int n, m;
int s, e;
int map[150][150] = { 0, };
bool visit[150][150] = { false, };
int result[150][150] = { 0, };
queue <pair<int, int>> f;

void bfs(int a,int b) {
	f.push(make_pair(a, b));
	while (!f.empty()) {
		int next = f.front().first;
		int cnt = f.front().second;
		f.pop();
		for (int i = 1; i <= n; i++) {
			if (!visit[a][i] && map[next][i] == 1) {
				visit[a][i] = true;
				result[a][i] = cnt;
				f.push(make_pair(i, cnt + 1));
			}
		}
	}
}


int main() {
	int a;
	int total=0;
	int	b = 100000;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		map[s][e] = 1;
		map[e][s] = 1;
	}

	for (int i = 1; i <= n; i++) {
		bfs(i,1);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) total += result[i][j];
		}
		if (total < b) {
			a = i;
			b = total;
		}
		total = 0;
	}
	cout << a;
	return 0;
}
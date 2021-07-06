#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
#include <stdio.h>
using namespace std;
int t,x,y;
int m, n, k;
int result = 0;

int field[60][60] = { 0, };

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

bool visit[60][60];

queue <pair<int, int>> coordi;

void bfs(int a, int b) {
	if (visit[a][b] == 1 || field[a][b] == 0) return;
	coordi.push(make_pair(a, b));
	visit[a][b] = 1;
	result++;
	while (!coordi.empty()) {
		a = coordi.front().first;
		b = coordi.front().second;
		coordi.pop();

		for (int i = 0; i < 4; i++) {
			int nextA = a + dx[i];
			int nextB = b + dy[i];
			if (0 <= nextA && nextA < m && 0 <= nextB && nextB < n) {
				if (field[nextA][nextB] == 1 && !visit[nextA][nextB]) {
					visit[nextA][nextB] = 1;
					coordi.push(make_pair(nextA, nextB));
				}
			}
		}

	}
	return;
}


int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> m >> n >> k;
		for (int j = 0; j < k; j++) {
			cin >> x >> y;
			field[x][y] = 1;
		}
		for (int j = 0; j < m; j++) {
			for (int l = 0; l < n; l++) {
				bfs(j, l);
			}
		}
		cout << result << "\n";
		result = 0;
		memset(visit, false, sizeof(visit));
		memset(field, 0, sizeof(field));
	}
	return 0;
}
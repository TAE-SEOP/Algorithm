#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
#include <stdio.h>
using namespace std;
int t, x, y;
int m, n, k;
int result = 0;
int field[60][60] = { 0, };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool visit[60][60];
queue <pair<int, int>> coordi;

void dfs(int a, int b) {
	visit[a][b] = 1;

	for (int i = 0; i < 4; i++) {
		int X = a + dx[i];
		int Y = b + dy[i];
		if (0 <= X && X < m && 0 <= Y && Y < n) {
			if (field[X][Y] == 1 && !visit[X][Y]) {
				dfs(X, Y);
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
				if (!visit[j][l] && field[j][l] == 1) {
					dfs(j, l);
					result++;
				}
			}
		}
		cout << result << "\n";
		result = 0;
		memset(visit, false, sizeof(visit));
		memset(field, 0, sizeof(field));
	}
	return 0;
}
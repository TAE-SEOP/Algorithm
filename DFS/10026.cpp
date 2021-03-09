#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
#include <stdio.h>
using namespace std;

int m;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool visit[305][305];
bool visit_rg[305][305];
char coordi[305][305] = { 0, };
int sum = 0;
int sum_rg = 0;
char color_r;
char color_g;

void dfs(int x, int y) {
	visit[x][y] = 1;
	char color = coordi[x][y];

	
		for (int i = 0; i < 4; i++) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			if (0 <= nextX && nextX < m && 0 <= nextY && nextY < m) {
				if (!visit[nextX][nextY] && color == coordi[nextX][nextY]) {
					visit[nextX][nextY] = 1;
					dfs(nextX, nextY);
				}
			}
		}
}

void dfs_rg(int x, int y) {
	visit_rg[x][y] = 1;
	if (coordi[x][y] == 'R' || coordi[x][y] == 'G') {
		color_r = 'R';
		color_g = 'G';
	}
	else {
		color_r = 'B';
		color_g = 'B';
	}

	
		for (int i = 0; i < 4; i++) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			if (0 <= nextX && nextX < m && 0 <= nextY && nextY < m) {
				if (!visit_rg[nextX][nextY] && (color_r == coordi[nextX][nextY] || color_g == coordi[nextX][nextY])) {
					visit_rg[nextX][nextY] = 1;
					dfs_rg(nextX, nextY);
				}
			}
		}

}

int main() {
	cin >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> coordi[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (!visit[i][j]) {
				dfs(i, j);
				sum++;
			}
			if (!visit_rg[i][j]) {
				dfs_rg(i, j);
				sum_rg++;
			}
		}
	}

	cout << sum << " " << sum_rg;

	return 0;
}
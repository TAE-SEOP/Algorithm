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
queue <pair<int, int>>map;
queue <pair<int, int>>map_rg;

void bfs(int x, int y) {
	map.push(make_pair(x, y));
	visit[x][y] = 1;
	char color = coordi[x][y];

	while (!map.empty()) {
		x = map.front().first;
		y = map.front().second;
		map.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			if (0 <= nextX && nextX < m && 0 <= nextY && nextY < m) {
				if (!visit[nextX][nextY] && color == coordi[nextX][nextY]) {
					visit[nextX][nextY] = 1;
					map.push(make_pair(nextX, nextY));
				}
			}
		}
	}
}

void bfs_rg(int x, int y) {
	map_rg.push(make_pair(x, y));
	visit_rg[x][y] = 1;
	if (coordi[x][y] == 'R' || coordi[x][y] == 'G') {
		color_r = 'R';
		color_g = 'G';
	}
	else {
		color_r = 'B';
		color_g = 'B';
	}
	
	while (!map_rg.empty()) {
		x = map_rg.front().first;
		y = map_rg.front().second;
		map_rg.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			if (0 <= nextX && nextX < m && 0 <= nextY && nextY < m) {
				if (!visit_rg[nextX][nextY] && (color_r == coordi[nextX][nextY] || color_g == coordi[nextX][nextY])) {
					visit_rg[nextX][nextY] = 1;
					map_rg.push(make_pair(nextX, nextY));
				}
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
				bfs(i, j);
				sum++;
			}
			if (!visit_rg[i][j]) {
				bfs_rg(i, j);
				sum_rg++;
			}
		}
	}

	cout << sum << " " << sum_rg;
	
	return 0;
}
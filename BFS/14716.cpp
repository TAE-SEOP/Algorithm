#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
#include <stdio.h>
using namespace std;

int m,n;
int dx[8] = { 0,0,1,-1,-1,-1,1,1 };
int dy[8] = { 1,-1,0,0,-1,1,-1,1 };
bool visit[305][305];
int coordi[305][305] = { 0, };
int result = 0;
queue <pair<int, int>>map;

void bfs(int x, int y) {
	map.push(make_pair(x, y));
	visit[x][y] = 1;
	
	while (!map.empty()) {
		x = map.front().first;
		y = map.front().second;
		map.pop();
		for (int i = 0; i < 8; i++) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			if (0 <= nextX && nextX < m && 0 <= nextY && nextY < n) {
				if (!visit[nextX][nextY] && coordi[nextX][nextY] == 1) {
					visit[nextX][nextY] = 1;
					map.push(make_pair(nextX, nextY));
				}
			}
		}
	}
}


int main() {
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> coordi[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j] && coordi[i][j] == 1) {
				bfs(i, j);
				result++;
			}
		}
	}
	
	cout << result;
	
	return 0;
}
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
#include <stdio.h>
using namespace std;

int m, n;
int ground[55][55] = { 0, };
bool visit[55][55];
int sum;
int dx[8] = {0,0,1,-1,-1,-1,1,1};
int dy[8] = {1,-1,0,0,-1,1,1,-1};

queue <pair<int, int>> map;
vector <int> result;

void bfs(int x,int y) {
	if (ground[x][y] == 0 || visit[x][y] == true) {
		return;
	}
	sum++;
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
				if (ground[nextX][nextY] == 1 && !visit[nextX][nextY]) {
					visit[nextX][nextY] = 1;
					map.push(make_pair(nextX, nextY));
					
				}
			}
		}
	}
}

int main() {
	while (true) {
		cin >> m >> n;
		if (m == 0 && n == 0) break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> ground[j][i];
			}
		}
		sum = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
					bfs(j, i);
			}
		}
		result.push_back(sum);
		sum = 0;
		memset(visit, false, sizeof(visit));
		memset(ground, 0, sizeof(ground));
	}

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}

	return 0;
}
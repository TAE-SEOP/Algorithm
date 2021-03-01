#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
#include <stdio.h>
using namespace std;

int m;
int startA, startB;
int endA, endB;
int dx[6] = { -2, -2, 0, 0, 2, 2 };
int dy[6] = { 1, -1, 2, -2, 1, -1 };
bool visit[305][305];
int coordi[305][305] = { 0, };
int sum = 0;

vector <int> result;
queue <pair<int, int>>map;

void bfs(int x, int y) {
	map.push(make_pair(x, y));
	visit[x][y] = 1;
	while (!map.empty()) {
		x = map.front().first;
		y = map.front().second;
		map.pop();
		for (int i = 0; i < 6; i++) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			if (0 <= nextX && nextX < m && 0 <= nextY && nextY < m) {
				if (!visit[nextX][nextY]) {
					coordi[nextX][nextY] = coordi[x][y] + 1;
					visit[nextX][nextY] = 1;
					map.push(make_pair(nextX, nextY));
				}
			}
		}

	}
}

int main() {
	
	cin >> m;
	cin >> startA >> startB >> endA >> endB;
	bfs(startA, startB);

	if (coordi[endA][endB] != 0) cout << coordi[endA][endB];
	else cout << -1;

	return 0;
}
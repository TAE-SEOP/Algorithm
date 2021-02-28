#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
#include <stdio.h>
using namespace std;

int t,l;
int startA, startB;
int endA, endB;
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};
bool visit[305][305];
int coordi[305][305] = { 0, };
int sum = 0;

vector <int> result;
queue <pair<int, int>>map;

void bfs(int x,int y) {
	map.push(make_pair(x, y));
	visit[x][y] = 1;

	while (!map.empty()) {
		x = map.front().first;
		y = map.front().second;
		map.pop();
		for (int i = 0; i < 8; i++) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			if (0 <= nextX && nextX < l && 0 <= nextY && nextY < l) {
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
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> l;
		cin >> startA >> startB;
		cin >> endA >> endB;
		bfs(startA, startB);

		result.push_back(coordi[endA][endB]);
		
		memset(visit, false, sizeof(visit));
		memset(coordi, 0, sizeof(coordi));
	}

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}

	return 0;
}
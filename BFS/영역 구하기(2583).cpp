#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
#include <stdio.h>

using namespace std;

int table[104][104] = { 0, };
bool visited[104][104] = { false, };
int m, n, h;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int x, y,nextx, nexty;
queue <pair<int, int>> area;
vector <int> result;
vector <int>::iterator iter;

void bfs(int a, int b) {
	visited[a][b] = true;
	long long int count = 1;
	area.push(make_pair(a, b));
	while (!area.empty()) {
		y = area.front().first;
		x = area.front().second;
		area.pop();
		for (int i = 0; i < 4; i++) {
			nexty = y + dy[i];
			nextx = x + dx[i];
			if (0 <= nexty && nexty < m && 0 <= nextx && nextx < n) {
				if (table[nexty][nextx] == 0 && visited[nexty][nextx] == false) {
					visited[nexty][nextx] = true;
					count += 1;
					area.push(make_pair(nexty, nextx));
				}
			}
		}
	}
	result.push_back(count);
	return;
}


int main() {
	cin >> m >> n >> h;
	int leftX, leftY, rightX, rightY;
	for (int i = 0; i < h; i++) {
		cin >> leftX >> leftY >> rightX >> rightY;
		for (int j = leftX; j < rightX; j++) {
			for (int l = leftY; l < rightY; l++) {
				table[l][j] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (table[j][i] == 0 && !visited[j][i]) bfs(j, i);
		}
	}
	sort(result.begin(), result.end());
	
	cout << result.size() << endl;
	for (iter = result.begin(); iter != result.end(); iter++) {
		cout << *iter << " ";
	}
	return 0;
}
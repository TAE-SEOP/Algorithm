#include <stdlib.h>
#include <iostream>
#include <stack>
#include <string.h>
#include <queue>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

int r, c;
int nextX, nextY;
int x, y;
int sheep = 0;
int wolf = 0;
char fence[500][500];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool visit[500][500] = { false, };
queue <pair<int, int>> field;

void bfs(int a, int b) {
	field.push(make_pair(a, b));
	sheep = 0;
	wolf = 0;
	while (!field.empty()){
		x = field.front().first;
		y = field.front().second;
		field.pop();
		if (fence[x][y] == 'v') {
			wolf++;
		}
		else if (fence[x][y] == 'o') {
			sheep++;
		}
		for (int i = 0; i < 4; i++) {
			nextX = x + dx[i];
			nextY = y + dy[i];
			if (!visit[nextX][nextY] && 0 <= nextX && nextX < r && 0 <= nextY && nextY < c && fence[nextX][nextY] != '#') {
				visit[nextX][nextY] = true;
				field.push(make_pair(nextX, nextY));
			}
		}
	}
	return;
}

int main() {
	int result_o = 0;
	int result_v = 0;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> fence[i][j];
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (visit[i][j] == false) {
				bfs(i, j);
				if (sheep != 0 || wolf != 0) {
					if (sheep > wolf) result_o += sheep;
					else result_v += wolf;
				}
			}
		}
	}
	cout << result_o << " " << result_v;
	return 0;
}
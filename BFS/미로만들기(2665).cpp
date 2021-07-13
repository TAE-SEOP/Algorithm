#include <stdlib.h>
#include <iostream>
#include <stack>
#include <string.h>
#include <queue>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <tuple>

using namespace std;
int n;
int map[60][60];
int visit[60][60];
queue <pair<int, int>> q;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };


void bfs() {
	visit[0][0] = 0;
	q.push(make_pair(0, 0));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			 if(0<= nextX && nextX < n && 0 <= nextY && nextY < n){
				 if (visit[x][y] + 1 < visit[nextX][nextY] && map[nextX][nextY] == 0) {
					 visit[nextX][nextY] = visit[x][y] + 1;
					 q.push(make_pair(nextX, nextY));
				 }
				 else if (map[nextX][nextY] == 1 && visit[x][y] < visit[nextX][nextY]) {
					 visit[nextX][nextY] = visit[x][y];
					 q.push(make_pair(nextX, nextY));
				 }
			}
		}
	}
	cout << visit[n - 1][n - 1];
	return;
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
			visit[i][j] = 987654321;
		}
	}
	bfs();
	return 0;
}
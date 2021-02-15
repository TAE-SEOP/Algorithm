#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int mat[102][102] = { 0, };
int v[102][102];
int d[4][2] = { {0,1}, {0,-1},{1,0},{-1,0} };

void BFS(int x, int y) {

	v[x][y] = 1;

	queue <pair<int, int>> q;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		
		for (int i = 0;i < 4;i++) {
			int nextX = x + d[i][0];
			int nextY = y + d[i][1];
			if (1 <= nextX && nextX <= n && 1 <= nextY && nextY <= m) {
				if ( mat[nextX][nextY] == 1 && v[nextX][nextY] == 0) {
					v[nextX][nextY] = v[x][y] + 1;
					q.push(make_pair(nextX, nextY));
				}
				else if (v[nextX][nextY] == 0) {
					v[nextX][nextY] = -1;
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		for (int j = 1; j <= m;j++) {
			scanf("%1d", &mat[i][j]);
		}
	}

	BFS(1,1);
	
	cout << v[n][m];

	return 0;

}
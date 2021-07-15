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
int n, m;
int map[105][105];
queue <pair<int, int>> q;
int visit[105][105] = { 0, };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void bfs(int a, int b) {
	q.push(make_pair(a, b));
	visit[a][b] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			if (0 <= nextX && nextX < n && 0 <= nextY && nextY < m) {
				if (visit[nextX][nextY] == 0 && map[nextX][nextY] == 0) {
					visit[nextX][nextY] = 1;
					q.push(make_pair(nextX, nextY));
				}
			}
		}
	}
	return;
}

void dfs(int a, int b) {

}


int main() {
	int result=0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	

	while (true) {
		memset(visit, 0, sizeof(visit));                                // visit 배열 초기화
		bfs(0, 0);                                                      // bfs를 통해 외부 공기, 내부 공기를 구분
		for (int i = 0; i < n; i++) {                                   
			for (int j = 0; j < m; j++) {
				int cnt = 0;
				if (map[i][j] == 1 && visit[i][j] == 0) {
					for (int k = 0; k < 4; k++) {                       // 치즈가 2개 이상의 외부 공기와 접촉하는지  
						int x = i + dx[k];
						int y = j + dy[k];
						if (visit[x][y] == 1 && map[x][y] == 0) {       
							cnt++;
						}
					}
					if (cnt >= 2) visit[i][j] = 2;                      // 치즈가 2개 이상 외부 공기와 접촉한다면, 녹는다 => visit를 2로 한다.
				}
			}
		}
		int flag = 0;                                                   // map에 치즈가 있는지 판별하기 위한 flag
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visit[i][j] == 2) {                                 // visit가 2라면 녹는다 
					map[i][j] = 0;
					flag = 1;
				}
			}
		}
		if (flag == 0) break;
		result++;                                                       // 하루 지남...
	}

	cout << result;

	return 0;
}
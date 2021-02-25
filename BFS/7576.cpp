#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
#include <stdio.h>
using namespace std;
int m, n;
int tomato[1001][1001] = { 0, };
int visit[1001][1001];
int result = 0;
int day = 1;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

queue <pair<int, int>> coordi;
vector <int> home;

void bfs(int x, int y) {
	while (!coordi.empty()) {
		x = coordi.front().first;
		y = coordi.front().second;
		visit[x][y] = 1;
		coordi.pop();
		
		for (int i = 0; i < 4; i++) {
			int X = x + dx[i];
			int Y = y + dy[i];
			
			if (0 <= X && X < n && 0 <= Y && Y < m) {
				if (tomato[X][Y] == 0 && !visit[X][Y]) {
					
					visit[X][Y] = 1;
					int temp = tomato[x][y];
					tomato[X][Y] = temp + 1;
					coordi.push(make_pair(X, Y));
				}
			}
		}
	}
	
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tomato[i][j];
			if(tomato[i][j] == 1) coordi.push(make_pair(i, j));
		}
	}
	 
	bfs(0, 0);
	int max = -1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (max < tomato[i][j]) max = tomato[i][j];
			if (tomato[i][j] == 0) {
				max = 0;
				break;
			}
		}
		if (max == 0) break;
	}
	cout << max-1;

	return 0;

}
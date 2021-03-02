#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
#include <stdio.h>

using namespace std;
int m;
int apart[26][26] = { 0, };
bool visit[26][26];
int result = 0;
int sum = 0;

queue <pair<int, int>> coordi;
vector <int> home;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };



void dfs(int x, int y) {
	visit[x][y] = 1;
	sum++;
	for (int i = 0; i < 4; i++) {
		int X = x + dx[i];
		int Y = y + dy[i];
		if (0 <= X && X < m && 0 <= Y && Y < m) {
			if (apart[X][Y] == 1 && !visit[X][Y]) {
				visit[X][Y] = 1;
				dfs(X, Y);
			}
		}
	}
	return;
}


int main() {
	cin >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &apart[i][j]);
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (!visit[i][j] && apart[i][j] == 1) {
				dfs(i, j);
				if (sum != 0) {
					home.push_back(sum);
				}
				sum = 0;
			}
		}
	}

	sort(home.begin(), home.end());

	printf("%d\n", home.size());
	for (int i = 0; i < home.size(); i++) {
		printf("%d\n", home[i]);
	}

	return 0;

}
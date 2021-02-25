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
int visit[26][26];
int result = 0;
int sum = 0;

queue <pair<int, int>> coordi;
vector <int> home;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };


void bfs(int x, int y) {
	if (apart[x][y] == 1 && !visit[x][y]) {
		sum++;
		coordi.push(make_pair(x, y));
		visit[x][y] = 1;

		while (!coordi.empty()) {
			x = coordi.front().first;
			y = coordi.front().second;
			coordi.pop();

			for (int i = 0; i < 4; i++) {
				int X = x + dx[i];
				int Y = y + dy[i];

				if (apart[X][Y] == 1 && !visit[X][Y]) {
					visit[X][Y] = 1;
					sum++;
					coordi.push(make_pair(X, Y));
				}
			}
		}
	}
	else return;
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
			bfs(i, j);
			if (sum != 0) {
				home.push_back(sum);
			}
			sum = 0;
		}
		
	}

	sort(home.begin(), home.end());

	cout << home.size() << "\n";
	for (int i = 0; i < home.size(); i++) {
		cout << home[i] << "\n";
	}

	return 0;

}
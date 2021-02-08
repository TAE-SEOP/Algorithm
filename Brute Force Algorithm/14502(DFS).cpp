#include <stdlib.h>
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int n, m;
int result = 0;

typedef struct {
	int x, y;
}Move;

Move movexy[4] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

void dfs(int count, int copy[11][11]) {

	if (count == 3) {
		queue <pair<int, int>> virus;
		int real[9][9] = { 0, };
		for (int i = 0; i < n;i++) {
			for (int j = 0; j < m; j++) {
				real[i][j] = copy[i][j];
				if (real[i][j] == 2) {
					virus.push(make_pair(i, j));
				}
			}
		}
		while (!virus.empty()) {
			int x = virus.front().first;
			int y = virus.front().second;
			virus.pop();

			for (int i = 0; i < 4; i++) {
				int movex = x + movexy[i].x;
				int movey = y + movexy[i].y;
				if (0 <= movex && movex < n && 0<= movey && movey < m) {
					if (real[movex][movey] == 0) {
						real[movex][movey] = 2;
						virus.push(make_pair(movex, movey));
					}
				}
			}
		}


		int temp = 0;

		for (int i = 0;i < n;i++) {
			for (int j = 0; j < m;j++) {
				if (real[i][j] == 0) temp += 1;
			}
		}
		if (result < temp) result = temp;
		
		return;
	}

	for (int i = 0;i < n;i++) {
		for (int j = 0; j < m;j++) {
			if (copy[i][j] == 0) {
				copy[i][j] = 1;
				dfs(count + 1, copy);
				copy[i][j] = 0;
			}
		}
	}
}


int main() {
	cin >> n >> m;
	int copy[11][11];
	int map[11][11];

	for (int i = 0; i < n;i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			copy[i][j] = map[i][j];
		}
	}

	dfs(0, copy);
	cout << result;

	return 0;

}
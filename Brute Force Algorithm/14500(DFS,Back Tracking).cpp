#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

int tetrominox[4] = { 0,0,1,-1 };
int tetrominoy[4] = { -1,1,0,0 };
int tminox[4][4] = { {0,0,0,1},{0,1,2,1},{0,0,0,-1},{0,-1,0,1} };
int tminoy[4][4] = { {0,1,2,1},{0,0,0,1},{0,1,2,1},{0,1,1,1} };

int n, m;
int result = 0;
int paper[502][502];
bool map[502][502];

int compare(int a, int b) {
	return a > b ? a : b;
}

void tmino(int x, int y) {
	for (int i = 0;i < 4;i++) {
		int tmino_sum = 0;
		int flag = 0;
		for (int j = 0; j < 4;j++) {
			int tx = x + tminox[i][j];
			int ty = y + tminoy[i][j];

			if (tx >= 0 && ty >= 0 && tx <= n - 1 && ty <= m - 1) {
				tmino_sum += paper[tx][ty];
			}
			else {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			result = compare(result, tmino_sum);
		}
	}
}

void dfs(int x, int y, int count, int sum) {
	if (count == 4) {
		result = compare(result, sum);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int tx = x + tetrominox[i];
		int ty = y + tetrominoy[i];
		if (tx >= 0 && ty >= 0 && tx <= n-1 && ty <= m-1) {
			if (map[tx][ty] == false) {
				map[tx][ty] = true;
				dfs(tx, ty, count + 1, sum + paper[tx][ty]);
				map[tx][ty] = false;
			}
		}
	}

}

int main() {
	cin >> n >> m;

	for (int i = 0;i < n;i++) {
		for (int j = 0; j < m;j++) {
			cin >> paper[i][j];
		}
	}

	for (int i = 0;i < n;i++) {
		for (int j = 0; j < m;j++) {
			// back tracking
			map[i][j] = true;   
			dfs(i, j, 1, paper[i][j]);
			map[i][j] = false;
			tmino(i, j);
		}
	}

	cout << result;

	return 0;

}
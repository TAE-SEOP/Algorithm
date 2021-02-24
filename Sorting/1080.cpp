#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
#include <stdio.h>
using namespace std;
int a[51][51] = { 0, };
int b[51][51] = { 0, };
int result = 0;
int flag = 0;
int m, n;

void reversal(int x, int y) {
	for (int k = x; k < x+3;k++) {
		for (int l = y; l < y+3;l++) {
			if (a[k][l] == 1) a[k][l] = 0;
			else if (a[k][l] == 0) a[k][l] = 1;
		}
	}
}

int main() {

	cin >> m >> n;
	
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			scanf("%1d", &b[i][j]);
		}
	}

	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			if (a[i][j] != b[i][j]) {
				if (i + 2 < m && j + 2 < n) {
					result++;
					reversal(i, j);
				}
			}
		}
	}

	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			if (a[i][j] != b[i][j]) {
				flag = 1;
			}
		}
	}

	if (flag == 1) cout << -1;
	else cout << result;

	return 0;

}
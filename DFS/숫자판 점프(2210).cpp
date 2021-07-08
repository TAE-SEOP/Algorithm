#include <stdlib.h>
#include <iostream>
#include <set>
#include <string.h>
#include <queue>
#include <algorithm>
#include <stdio.h>

using namespace std;

int table[7][7];
set <int> d;
int com[6];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int number = 0;
int nextx, nexty;
void dfs(int a, int b,int c, int result){
	if (c == 5) {
		d.insert(result);
		return;
	}
	for (int i = 0; i < 4; i++) {
		nextx = a + dx[i];
		nexty = b + dy[i];
		if (0 <= nextx && nextx < 5 && 0 <= nexty && nexty < 5) {
			dfs(nextx, nexty, c + 1, result * 10 + table[nextx][nexty]);
		}
	}
	return;
}

int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> table[i][j];
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			number = 0;
			dfs(i, j,number, table[i][j]);
		}
	}
	cout << d.size();

	return 0;
}
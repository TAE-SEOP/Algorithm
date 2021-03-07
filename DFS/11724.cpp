#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
#include <stdio.h>
using namespace std;
int m, n;
int a, b;
int result = 0;
int com[1004][1004] = { 0, };
bool visit[1004];
queue <int> con;

void dfs(int x) {
	visit[x] = 1;

	for (int i = 1; i <= m; i++) {
		if (com[x][i] == 1 && !visit[i]) {
			visit[i] = 1;
			dfs(i);
		}
	}

}

int main() {
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		com[a][b] = 1;
		com[b][a] = 1;
	}

	for (int i = 1; i <= m; i++) {
		if (!visit[i]) {
			result++;
			dfs(i);
		}
	}
	cout << result;
	return 0;
}
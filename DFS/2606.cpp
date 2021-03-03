#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;

int m, n;
int result = 0;
int computer[101][101] = { 0, };
queue <int> bfs;
bool visit[101];

void DFS(int start) {
	visit[start] = 1;
	for (int i = 1; i <= m; i++) {
		if (computer[start][i] && !visit[i]) {
			visit[i] = 1;
			result++;
			DFS(i);
		}
	}
}


int main() {
	cin >> m;
	cin >> n;
	int start, end;

	for (int i = 1; i <= n; i++) {
		cin >> start >> end;
		computer[start][end] = 1;
		computer[end][start] = 1;
	}

	DFS(1);
	cout << result;
	return 0;

}
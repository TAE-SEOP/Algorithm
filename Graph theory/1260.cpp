#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, v;
int a[1001][1001] = { 0, };
bool visit[1001];
bool visit_bfs[1001];
queue <int> bfs;

void DFS(int start) {
	cout << start << " ";
	for (int i = 0;i <= n;i++) {
		if (a[start][i] == 1 && !visit[i]) {
			visit[i] = true;
			DFS(i);
		}
	}
}

void BFS(int start) {
	bfs.push(start);
	visit_bfs[start] = 1;

	while (!bfs.empty()) {
		start = bfs.front();
		bfs.pop();

		cout << start << " ";
		for (int i = 1;i <= n;i++) {
			if (a[start][i] && !visit_bfs[i]) {
				visit_bfs[i] = 1;
				bfs.push(i);
			}
		}
	}

}

int main() {
	int start, end;
	cin >> n >> m >> v;
	for (int i = 0; i < m;i++) {
		cin >> start >> end;
		a[start][end] = 1;
		a[end][start] = 1;
	}
	visit[v] = true;

	DFS(v);
	cout << "\n";
	BFS(v);
	

	return 0;

}
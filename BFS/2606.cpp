#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;

int m,n;
int result = 0;
int computer[101][101] = { 0, };
queue <int> bfs;
bool visit[101];

void BFS(int start) {
	bfs.push(start);
	visit[start] = 1;
	while (!bfs.empty()) {
		start = bfs.front();
		bfs.pop();

		for (int i = 1; i <= m;i++) {
			if (computer[start][i] && !visit[i]) {
				visit[i] = 1;
				result++;
				bfs.push(i);
			}
		}
	}
}


int main() {
	cin >> m;
	cin >> n;
	int start, end;
	
	for (int i = 1; i <= n;i++) {
		cin >> start >> end;
		computer[start][end] = 1;
		computer[end][start] = 1;
	}
	
	BFS(1);
	cout << result;
	return 0;

}
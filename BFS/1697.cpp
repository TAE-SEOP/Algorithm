#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
#include <stdio.h>

using namespace std;
int subin;
int bro;
int result = 0;
queue <pair<int,int>> path;
bool visit[230001];

void bfs(int su, int number) {
	visit[su] = 1;
	
	while (!path.empty()) {
		su = path.front().first;
		number = path.front().second;
		path.pop();
		long long int next;
		if (su == bro) {
			result = number;
			break;
		}
		for (int i = 0; i < 3; i++) {
			if (i == 0 && su > 0) next = su - 1;
			else if (i == 1)next = su + 1;
			else if (i == 2) next = su * 2;
			if (next < 230000) {
				if (!visit[next]) {
					visit[next] = 1;
					path.push(make_pair(next, number + 1));
				}
			}
		}
	}
	return;
}

int main() {
	cin >> subin >> bro;
	path.push(make_pair(subin, 0));
	bfs(subin, 0);
	cout << result;

	return 0;
}
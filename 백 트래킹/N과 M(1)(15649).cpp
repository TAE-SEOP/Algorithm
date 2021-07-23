#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int seq[10];

bool available(int i,int cnt) {

	for (int j = 0; j < cnt; j++) {
		if (i == seq[j]) return false;
	}

	return true;
}

void dfs(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << seq[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		seq[cnt] = i;
		if (available(i,cnt)) dfs(cnt + 1);
	}


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;

	dfs(0);

}

/*
n-queen과 비슷하게 풀었음
*/


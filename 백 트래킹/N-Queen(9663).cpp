#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int nq[15];
int result = 0;

bool available(int i) {
	for (int j = 0; j < i; j++) {
		if (nq[i] == nq[j] || i - j == abs(nq[i] - nq[j])) return false;
	}
	return true;
}


void dfs(int cnt) {
	if (cnt == n) {
		result++;
		return;
	}
	for (int i = 0; i < n; i++) {
		nq[cnt] = i;
		if (available(cnt)) dfs(cnt + 1);
	}
}

int main() {
	/*ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);*/

	cin >> n;
	dfs(0);
	cout << result;
	return 0;

}
/*
2차원 배열 필요없이 대각선과 직선만으로 퀸을 놓을 수 있는지 판단해서 dfs사용...
*/

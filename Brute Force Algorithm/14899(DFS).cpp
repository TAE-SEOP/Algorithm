#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int n,temp;
int result = 2147483646;

void dfs(string decision, int start, int link, int **p) {

	if (decision.size() == n) {
		vector <int> startTeam, linkTeam;
		long long int startScore = 0, linkScore = 0;

		for (int i = 0; i < decision.length();i++) {
			if (decision[i] == '1') startTeam.push_back(i);
			else linkTeam.push_back(i);
		}
		for (int i = 0;i < startTeam.size();i++) {
			for (int j = i + 1; j < startTeam.size();j++) {
				startScore += p[startTeam[i]][startTeam[j]];
				startScore += p[startTeam[j]][startTeam[i]];
			}
		}
		for (int i = 0;i < linkTeam.size();i++) {
			for (int j = i + 1; j < linkTeam.size();j++) {
				linkScore += p[linkTeam[i]][linkTeam[j]];
				linkScore += p[linkTeam[j]][linkTeam[i]];
			}
		}
		if (startScore > linkScore) temp = startScore - linkScore;
		else temp = linkScore - startScore;

		if (temp < result) result = temp;
		return;
	}

	if (start < (n / 2)) dfs(decision + "1", start + 1, link, p);
	if (link < (n / 2)) dfs(decision + "0", start, link + 1, p);
}

int main() {
	cin >> n;
	int** p = new int *[n];
	for (int i = 0; i < n;i++) {
		p[i] = new int[n];
		memset(p[i], 0, sizeof(int) * n);

	}
	for (int i = 0;i < n;i++) {
		for (int j = 0; j < n;j++) {
			cin >> p[i][j];
		}
	}
	dfs("", 0, 0, p);
	cout << result;

	return 0;

}
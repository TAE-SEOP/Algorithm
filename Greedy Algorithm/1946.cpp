#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

int main() {
	int n;
	int count;
	int max,min;
	int result = 0;
	int doc, inter;
	vector<pair <int, int>> score;
	cin >> n;

	for (int i = 0; i < n;i++) {
		cin >> count;
		for (int j = 0;j < count;j++) {
			cin >> doc >> inter;
			score.push_back(make_pair(doc, inter));
		}
		sort(score.begin(), score.end(), compare);
		for (int j = 0; j < score.size();j++) {
			if (j == 0) {
				result++;
				max = score[j].second;
				min = score[j].second;
			}
			else if (j == count - 1) {
				if (score[j].second == 1) goto ADD;
			}
			else {
				if (min > score[j].second) {
				ADD:
					min = score[j].second;
					result++;
				}
			}
		}
		cout << result << "\n";
		score.clear();
		result = 0;
	}

	return 0;

}
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first< b.first;
	return a.second < b.second;
}

int main() {
	long long int n;
	int time = 0;
	int tempStart;
	int tempEnd;
	int result = 0;
	cin >> n;
	vector<pair<int, int>> conf;

	for (int i = 1;i <= n;i++) {
		cin >> tempStart >> tempEnd;
		conf.push_back(make_pair(tempStart,tempEnd));
	}
	sort(conf.begin(), conf.end(), compare);

	for (int i = 0; i < conf.size(); i++) {
		if (i == 0) {
			time = conf[i].second;
			result++;
		}
		else {
			if (time <= conf[i].first) {
				time = conf[i].second;
				result++;
			}
		}
	}
	cout << result;

	return 0;

}
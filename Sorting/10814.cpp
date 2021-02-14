#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <tuple>
#include <algorithm>
using namespace std;

bool compare(tuple<int,int , string> a, tuple<int, int, string> b) {
	if (get<0>(a) == get<0>(b)) return get<1>(a) < get<1>(b);
	return get<0>(a) < get<0>(b);
}


int main() {
	int n, age;
	string name;
	vector <tuple<int,int, string>> number;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> age >> name;
		number.push_back(make_tuple(age, i, name));
	}
	sort(number.begin(), number.end(), compare);

	for (int i = 0;i < number.size();i++) {
		cout << get<0>(number[i]) << " " << get<2>(number[i]) << "\n";
	}

	return 0;

}
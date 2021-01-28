
#include <iostream>
using namespace std;
int compare(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int n;
	int number;
	long long int hypo[101] = {0,1,1,1,2,2,};

	cin >> n;

	for (int i = 6; i < 101;i++) {
		hypo[i] = hypo[i - 5] + hypo[i - 1];
	}

	for (int j = 0;j < n;j++) {
		cin >> number;
		cout << hypo[number] << "\n";

	}


	return 0;

}
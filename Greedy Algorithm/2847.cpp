#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;


int main() {
	int n;
	int result =0;
	int temp;
	cin >> n;
	int* score = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n;i++) {
		cin >> score[i];
	}

	for (int i = n-1; i > 0 ;i--) {
		if (score[i-1] >= score[i]) {
			result += score[i-1] - score[i]+1;
			score[i-1] = score[i] - 1;
		}
	}

	cout << result;

	return 0;

}
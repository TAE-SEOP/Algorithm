#include <stdlib.h>
#include <iostream>


using namespace std;

int compare(int a, int b, int c) {
	if (a < b) {
		return a < c ? a : c;
	}
	else {
		return b < c ? b : c;
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	char** chess;
	int** cal_B;
	int init=0;
	int result_B;
	int result_W;
	int result=10000;
	chess = new char* [n];
	cal_B = new int* [n];

	for (int i = 0;i < n;i++) {
		chess[i] = new char[m];
		cal_B[i] = new int[m];
	}

	for (int i = 0; i < n;i++) {
		for (int j = 0; j < m;j++) {
			cin >> chess[i][j];
			if ((i + j) % 2 == 0) {
				if (chess[i][j] == 'B') cal_B[i][j] = 0;
				else cal_B[i][j] = 1;
			}
			else if ((i + j) % 2 == 1) {
				if (chess[i][j] == 'W') cal_B[i][j] = 0;
				else cal_B[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < m-7;i++) {
		result_B = 0;
		result_W = 0;
		for (int j = init; j < init+8;j++) {
			result_B += cal_B[j][i] + cal_B[j][i + 1] + cal_B[j][i + 2] + cal_B[j][i + 3] +
				cal_B[j][i + 4] + cal_B[j][i + 5] + cal_B[j][i + 6] + cal_B[j][i + 7];
		}
		
		result_W = 64 - result_B;
		
			result = compare(result_B, result_W, result);
		if (init != (n - 7) - 1 && i == (m - 7) - 1) {
			i = -1;
			init++;
		}
	}


	cout << result;

	return 0;

}
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

int compare(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int n;
	int t,p;
	int result = 0;
	cin >> n;
	int* time = (int*)malloc(sizeof(int) * n+1);
	int *profit = (int*)malloc(sizeof(int) * n + 1);
	int* max = (int*)malloc(sizeof(int) * n + 2);
	for (int i = 1;i <= n;i++) {
		cin >> time[i] >> profit[i];
		max[i] = profit[i];
		
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i;j++) {
			if (i - j >= time[j]) {
				max[i] = compare(profit[i] + max[j], max[i]);
			}
		}
	}
	
	for (int i = 1;i <= n; i++) {
		if (n+1 >= i+time[i]){
			result = compare(max[i], result);
		}
	}


	cout << result;

	return 0;

}
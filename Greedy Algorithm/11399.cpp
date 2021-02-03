#include <stdlib.h>
#include <iostream>
using namespace std;



int main() {
	int p;
	int temp;
	long long int q =0;
	long long int result = 0;
	cin >> p;
	int* time = (int*)malloc(sizeof(int) * p+1);
	for (int i = 1; i <= p;i++) cin >> time[i];
	
	for (int i = 1;i <= p;i++) {
		for (int j = 1; j <= p - i;j++) {
			if (time[j] > time[j + 1]) {
				temp = time[j];
				time[j] = time[j + 1];
				time[j + 1] = temp;
			}
		}
	}

	for (int i = 1; i <= p;i++) {
		q += time[i];
		result += q;
	}
	cout << result;

	return 0;

}
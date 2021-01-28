
#include <iostream>
using namespace std;
int compare(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int n;
	long long int result = 0;
	cin >> n;
	int* price = (int*)malloc(sizeof(int) * n+1);
	int* select = (int*)malloc(sizeof(int) * n+1);
	
	for (int i = 1; i <= n;i++) cin >> price[i];
	
	select[0] = 0;

	for (int i = 1; i <=n; i++) {
		for (int j = 1; j <= i;j++) {
			select[i] = compare(select[i], select[i-j]+price[j]);
		}
	}
	cout << select[n];

	return 0;

}
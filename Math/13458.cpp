#include <stdio.h>
#include <stdlib.h>
int main() {
	int n, b, c;
	scanf("%d", &n);
	long long int count = 0,quo;
	int* a;
	a = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d %d", &b, &c);

	for (int j = 0; j < n; j++) {
		a[j] = a[j] - b;
		count++;
		if (a[j] > 0) {
			quo = a[j] / c;
			count += quo;
			a[j] -= quo * c;
			if (a[j] > 0) count++;
		}
	}

	printf("%lld", count);
	return 0;

}
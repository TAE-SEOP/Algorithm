#include <stdio.h>

int main() {
	long long int number;
	long long int fibo[92] = { 0, };
	fibo[1] = 1;
	scanf("%lld", &number);

	for (int i = 1; i < number; i++) {
		fibo[i + 1] = fibo[i] + fibo[i - 1];
	}
	printf("%lld", fibo[number]);

	return 0;

}
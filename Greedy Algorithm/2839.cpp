#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main() {
	int a;
	int b;
	int quotient;
	int count = 10000;
	int count2 = 0;
	scanf("%d", &a);
	

	quotient = a / 5;

	for (int i = 0; i <= quotient; i++) {
		count2 = 0;
		count2 += i;
		b = a - (5 * i);
		count2 += b / 3;
		b = b % 3;
		if (b == 0) {
			if (count > count2) count = count2;
		}
	}
	if (count == 10000) count = -1;
	printf("%d\n", count);
	return 0;
}
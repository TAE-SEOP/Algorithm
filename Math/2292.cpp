#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main() {
	int a;
	int first = 1;
	int first_add = 6;
	int last = 6;
	int last_add = 12;
	scanf("%d", &a);
	int i = 1;
	if (a != 1) {
		while (true) {
			i++;
			if (a - 1 >= first && a - 1 <= last) break;
			else {
				first += first_add;
				last += last_add;
				first_add += 6;
				last_add += 6;
			}
		}
	}

	else {
		printf("1\n");
		return 0;
	}
	printf("%d\n", i);
	return 0;
}
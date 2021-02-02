#include <stdio.h>
int main() {
	int start, end;
	int a[1000]{0,};
	int j = 0, k = 0, m = 0;
	int total = 0;
	scanf("%d %d", &start, &end);
	for(j; j < 200; j++){
		for(k=0; k < j; k++) {
			a[m] = j;
			if (m == 999) break;
			m++;
		}
		if (m == 999) break;
	}
	for (start; start <= end; start++) {
		total += a[start-1];
	}
	printf("%d", total);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
int main() {
	int n, m, k;
	int team_n;
	int remainder=0;
	scanf("%d %d %d", &n, &m, &k);
	team_n = n / 2;
	remainder += n % 2;
	if (team_n > m) {
		while (team_n > m) {
			team_n -= 1;
			remainder += 2;
		}
	}
	else if (team_n < m) {
		while (team_n < m) {
			m -= 1;
			remainder += 1;
		}
	}

	k = k - remainder;
	while (k > 0) {
		team_n -= 1;
		k -= 3;
	}
	printf("%d", team_n);


	return 0;

}
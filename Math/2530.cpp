#include <stdio.h>
#include <stdlib.h>
int main() {
	int h,m,s;
	int time;
	int plus_m, plus_s;

	scanf("%d %d %d", &h, &m, &s);
	scanf("%d", &time);
	
	plus_m = time / 60;
	plus_s = time % 60;

	s += plus_s;
	m += plus_m;
	if (s >= 60) {
		s -= 60;
		m++;
	}

	if (m >= 60) {
		while(true){
			m -= 60;
			h++;
			if (m < 60)break;
		}
	}
	if (h >= 24) {
		h = h % 24;
	}

	printf("%d %d %d", h, m, s);
	return 0;

}
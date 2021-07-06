#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
	long long int s;
	long long int temp = 0;
	long long int count = 0;
	cin >> s;
	
	for (int i = 1; i <= s; i++) {
		temp += i;
		count++;
		
		if (temp + i + 1 > s) break;
		
	}
	cout << count;
	return 0;
}
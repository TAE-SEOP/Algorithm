#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int number,cf=0,count=0;
	char b[80];
	cin >> number;
	for (int i = 0; i < number; i++) {
		cin >> b;
		for (int j = 0; j < 80; j++) {
			if (b[j] == 'O') {
				cf++;
				if (cf == 0) {
					count++;
				}
				else {
					count += cf;
				}
			}
			else if (b[j] == 'X') cf = 0;
			if (b[j] == '\0') break;
		}
		cout << count << endl;
		count = 0;
		cf = 0;
	}
	
	return 0;
}
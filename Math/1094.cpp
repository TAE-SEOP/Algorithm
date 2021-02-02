#include <string>
#include <iostream>
using namespace std;

int main() {
	int number,count=0;
	cin >> number;
	for (int i = 64; i > 0; i = i / 2) {
		if (i <= number) {
			number = number - i;
			count++;
			if (number == 0) break;
		}
	}
	cout << count << endl;
	return 0;
}
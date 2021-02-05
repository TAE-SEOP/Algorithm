#include <string>
#include <iostream>

using namespace std;

int main() 
{
	int number,a,b,c,d,j;
	int count = 0;
	cin >> number;
	for (int i = 1; i <= number; i++) {
		j = i;
		if (0 < i && i < 100) count++;
		else if (99 < i && 1000) {
			a = j / 100;
			j = j - a * 100;
			b = j / 10;
			j = j - b * 10;
			c = j;
			if ((a - b) == (b - c)) count++;
		}
	}
	cout << count << endl;

	return 0;
}
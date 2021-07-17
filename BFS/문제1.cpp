
#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int Answer;

int p[100005] = { 0, };
int visit[100005] = { 0, };

int main(int argc, char** argv)
{
	int T, test_case;
	
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
	
		int n;
		cin >> n;
		queue <int> b;

		

		for (int i = 1; i <= n; i++) {
			cin >> p[i];
			p[i] += i;
			visit[i] = 0;
		}
		
		for (int i = 1; i < n + 1; i++) {
			int flag = 0;
			if (visit[i] == 0) {
				b.push(i);
				visit[i] = 1;
				while (!b.empty()) {
					int next = b.front();
					b.pop();
					if (visit[p[next]] == 0 && p[next] < n + 1) {
						b.push(p[next]);
						visit[p[next]] = 1;
					}
					else if(p[next] > n){
						flag = 1;
					}
				}
			}
			if (flag != 0) Answer++;
		}

		


		
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
		memset(p, 0, sizeof(p));
		memset(visit, 0, sizeof(visit));
	}

	return 0;
}
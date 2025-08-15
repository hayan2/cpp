#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, res = 0;

	cin >> N;

	for (int i = 1; i <= N; i++) {		
		if (i < 100) {
			res++;
			continue;
		}
		else if (!(i ^ 1000)) break;

		int h = i / 100;
		int t = (i % 100) / 10;
		int u = i % 10;

		if (h - t == t - u) res++;
	}

	cout << res;

	return 0;
}
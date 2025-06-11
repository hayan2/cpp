#include <iostream>
#include <algorithm>

using namespace std;

int cache[11];
int N, cnt = 0, res = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) cin >> cache[i];
	sort(cache, cache + N);

	do {
		for (int i = 0; i < N; i++) {
			int s = 0;
			for (int j = i; j <= N; j++) {
				if (j == N) j = 0;
				s += cache[j];
				if (s > 50) break;
				else if (s == 50) {
					cnt++;
					break;
				}
			}
		}
		res = max(res, cnt);
		cnt = 0;
	} while (next_permutation(cache, cache + N));

	cout << res / 2;

	return 0;
}
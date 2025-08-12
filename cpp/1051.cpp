#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX_N = 51;

string cache[MAX_N];

bool solve(int i, int j, int k) {
	return (cache[j][k] == cache[j + i][k] &&
		cache[j + i][k] == cache[j][k + i] &&
		cache[j][k + i] == cache[j + i][k + i]);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	cin >> N >> M;

	for (int i = 0; i < N; i++) cin >> cache[i];

	int l = min(N, M);
	int res = 1;

	for (int i = 1; i < l; i++) {
		for (int j = 0; j < N - i; j++) {
			for (int k = 0; k < M - i; k++) {
				if (solve(i, j, k)) res = max(res, i + 1);
			}
		}
	}

	cout << res * res;

	return 0;
}
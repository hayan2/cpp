#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 1e9;
const int ALL = 6;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	cin >> N >> M;

	int a = INF, p = INF, x, y;

	while (M--) {
		cin >> x >> y;
		a = min(a, x);
		p = min(p, y);
	}

	int res = 0;
	if (a > p * ALL) cout << N * p;
	else {
		int r = N % ALL;
		N /= ALL;
		res += N * a;
		res += (r * p > a) ? a : r * p;

		cout << res;
	}

	return 0;
}
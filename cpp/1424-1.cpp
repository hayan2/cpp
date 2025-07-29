#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

const int INF = 1e9;
const int MOD = 13;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll N, L, C, res = INF;

	cin >> N >> L >> C;

	for (ll i = (C + 1) / (L + 1); i > 0; i--) {
		if (!(i % MOD)) continue;
		ll k = N % i;
		if (k > 0) {
			if (!(k % MOD) && k + 1 == i) k = 2;
			else k = 1;
		}
		res = min(res, N / i + k);
	}

	cout << res;

	return 0;
}
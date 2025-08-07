#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

const int MAX_N = 51;
const int MOD = 1000;

ll gcd(ll a, ll b) {
	if (!b) return a;
	else return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	if (!a || !b) return 0;
	return (a * b) / gcd(a, b);
}

ll solve(int a) {
	if (!a) return 1;

	for (ll i = 1; ; i++) {
		ll l = ll(a) * i;
		ll u = ll(a + 1) * i;

		ll tmp = ((l + 999) / 1000) * 1000;

		if (tmp < u) return i;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	ll res = 1;

	cin >> N;

	while (N--) {
		double cache;
		cin >> cache;
		
		int avg = static_cast<int>(cache * 1000.0 + 0.5);

		ll ret = solve(avg);

		res = lcm(res, ret);
	}

	cout << res;

	return 0;
}
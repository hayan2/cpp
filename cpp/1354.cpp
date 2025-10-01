#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
using ll = long long;

map<ll, ll> cache;
ll N, P, Q, X, Y;

ll solve(ll x) {
	if (x <= 0) return 1;
	if (cache.count(x)) return cache[x];

	ll ret = solve(x / P - X) + solve(x / Q - Y);
	return cache[x] = ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> P >> Q >> X >> Y;

	cout << solve(N);

	return 0;
}
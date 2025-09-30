#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
using ll = long long;

map<ll, ll> cache;
ll N, P, Q;

ll solve(ll x) {
	if (x == 0) return 1;
	if (cache.count(x)) return cache[x];
	ll ret = solve(x / P) + solve(x / Q);

	return cache[x] = ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> P >> Q;

	cout << solve(N);

	return 0;
}
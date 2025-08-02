#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll mn, mx;

	cin >> mn >> mx;

	vector<bool> cache(mx - mn + 1, true);

	for (ll i = 2; i * i <= mx; i++) {
		ll square = i * i;
		ll s = ((mn + square - 1) / square) * square;

		for (ll j = s; j <= mx; j += square) cache[j - mn] = false;
	}

	ll cnt = 0;
	for (ll i = 0; i < mx - mn + 1; i++) {
		if (cache[i]) cnt++;
	}

	cout << cnt;

	return 0;
}
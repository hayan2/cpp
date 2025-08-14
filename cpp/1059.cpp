#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	int L, n;
	cin >> L;

	vector<int> cache(L + 1);
	for (int i = 0; i < L; i++) cin >> cache[i];
	cin >> n;

	sort(cache.begin(), cache.end());

	if (binary_search(cache.begin(), cache.end(), n)) {
		cout << 0;
		return 0;
	}

	auto u = upper_bound(cache.begin(), cache.end(), n);
	auto l = lower_bound(cache.begin(), cache.end(), n);

	int r = *u;
	int val = 0;

	if (l != cache.begin()) {
		l--;
		val = *l;
	}

	ll cnt = static_cast<ll>(n - (val + 1) + 1) * (r - n) - 1;

	cout << cnt;

	return 0;
}
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

const int INF = 1e9 + 7;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll N, k;

	cin >> N >> k;

	ll d = 1, cnt = 9, s = 1;
	ll len = 0;
	while (s <= N) {
		ll cur = min((ll)N - s + 1, cnt);
		len += cur * d;
		
		if (k <= len) break;

		d++;
		s *= 10;
		cnt *= 10;
	}

	if (k > len) {
		cout << "-1";

		return 0;
	}

	d = 1, cnt = 9, s = 1;
	len = 0;
	while (1) {
		ll x = cnt * d;

		if (k <= x) break;
		k -= x;

		d++;
		cnt *= 10;
		s *= 10;
	}

	k--;
	ll cache = s + (k / d);
	int idx = k % d;

	if (cache > N) cout << "-1";
	else {
		string res = to_string(cache);
		cout << res[idx];
	}

	return 0;
}
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string.h>

using namespace std;
using ll = long long;
string num[55];
ll n, k, a[55], len[55], mul[55], dp[1 << 15][101];

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

void make_table(int k) {
	mul[0] = 1;
	for (int i = 1; i <= 50; i++) {
		mul[i] = mul[i - 1] * 10 % k;
	}
}

ll go(int bit, ll v) {
	if (bit + 1 == (1 << n)) return (v == 0); // base case
	ll& ret = dp[bit][v];
	if (~ret) return ret;
	ret = 0;
	for (int i = 0; i < n; i++) {
		if (bit & (1 << i)) continue;
		ret += go(bit | (1 << i), (v * mul[len[i]] + a[i]) % k);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	ll fac = 1;
	for (ll i = 0; i < n; i++) {
		cin >> num[i];
		fac *= (i + 1);
	}
	cin >> k;
	for (int i = 0; i < n; i++) {
		len[i] = (int)num[i].size();
		int t = 0;

		for (auto s : num[i]) {
			t *= 10; 
			t %= k;
			t += (s - '0');
			t %= k;
		}
		a[i] = t;
	}
	make_table(k);
	memset(dp, -1, sizeof(dp));

	ll p = go(0, 0), q = fac;
	ll g = gcd(p, q);
	if (p == 0) {
		cout << 0 << "/" << 1;
	}
	else {
		cout << p / g << "/" << q / g;
	}
}
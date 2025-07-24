#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
using ll = long long;

ll solved(ll s, ll e, int M) {
	if (s > e) return 0;
	return (e / M) - ((s - 1) / M);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll l, r;
	int k;

	cin >> l >> r >> k;

	ll cnt = 0, sr = 0;

	if (k == 2) {
		sr = max(l, 3LL);
		if (sr <= r) cnt = r - sr + 1;
	}
	else if (k == 3) {
		sr = max(l, 6LL);
		cnt = solved(sr, r, 3);
	}
	else if (k == 4) {
		sr = max(l, 10LL);
		cnt = solved(sr, r, 2);
		if (l <= 12 && r >= 12) cnt--;
	}
	else if (k == 5) {
		sr = max(l, 15LL);
		cnt = solved(sr, r, 5);
	}
	//
	cout << cnt;

	return 0;
}
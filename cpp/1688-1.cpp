#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
const ll INF = 1e9 + 7;
const int MAX_SIZE = 10001;

pll point[MAX_SIZE], root[4];

int ccw(pll p1, pll p2, pll p3) {
	ll tmp = (p2.first - p1.first) * (p3.second - p1.second) - (p2.second - p1.second) * (p3.first - p1.first);
	if (tmp > 0) return 1;
	if (tmp < 0) return -1;
	return 0;
}
//
int solved(pll a, pll b, pll c, pll d) {
	int l1 = ccw(a, b, c) * ccw(a, b, d);
	int l2 = ccw(c, d, a) * ccw(c, d, b);

	if (l1 == 0 && l2 == 0) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		if (b < c || d < a) return 0;
		else return 1;
	}
	else if (l1 <= 0 && l2 <= 0) return 1;
	else return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	ll x, y;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;

		point[i] = { x, y };
	}
	point[N] = point[0];

	for (int i = 0; i < 3; i++) {
		cin >> x >> y;
		root[i] = { x, y };
	}

	for (int i = 0; i < 3; i++) {
		int cnt = 0;
		pll p1 = { root[i].first, root[i].second };
		pll p2 = { root[i].first + INF, root[i].second + 1 };

		bool flag = 0;
		for (int j = 0; j < N; j++) {
			cnt += solved(p1, p2, point[j], point[j + 1]);
			if (ccw(point[j], p1, point[j + 1]) == 0) {
				if ((point[j] <= p1 && p1 <= point[j + 1]) || (point[j + 1] <= p1 && p1 <= point[j])) {
					flag = 1;
					break;
				}
			}
		}
		if (flag) cout << "1\n";
		else if (cnt & 1) cout << "1\n";
		else cout << "0\n";
	}
}
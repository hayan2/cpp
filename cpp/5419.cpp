#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

#define ll long long
#define MAX_LEN 75003

typedef pair<ll, ll> pll;

ll segmentTree[MAX_LEN * 4];
ll box[MAX_LEN];
vector<pll> root;
ll T, N, cnt = 0, cnt = 0, x, y;

ll query(ll node, ll low, ll high, ll s, ll e) {
	if (high < s || e < low) return 0;
	if (s <= low && high <= e) return segmentTree[node];
	ll mid = (low + high) >> 1;
	return query(2 * node, low, mid, s, e) + query(2 * node + 1, mid + 1, high, s, e);
}

void update(ll node, ll low, ll high, ll idx) {
	if (idx < low || high < idx) return;
	segmentTree[node]++;
	if (low == high) return;
	ll mid = (low + high) >> 1;
	update(2 * node, low, mid, idx);
	update(2 * node + 1, mid + 1, high, idx);
}

int main() {
	cin >> T;
	while (T--) {
		memset(segmentTree, 0, sizeof segmentTree);
			
		cin >> N;
		for (ll i = 0; i < N; i++) {
			cin >> x >> y;

			root.push_back({ x, y });
		}
		sort(root.begin(), root.end(), [](pll& a, pll& b) { return a.second < b.second; });

		cnt = 0;
		// coordinate compression
		for (ll i = 0; i < N; i++) {
			if (i > 0 && root[i].second != root[i - 1].second) cnt++;
			box[i] = cnt;
		}
		for (ll i = 0; i < N; i++) root[i].second = box[i];


		sort(root.begin(), root.end(), [](pll& a, pll& b) {
			if (a.first == b.first) return a.second > b.second;
			return a.first < b.first;
			});

		cnt = 0;
		for (ll i = 0; i < N; i++) {
			cnt += query(1, 0, MAX_LEN, root[i].second, MAX_LEN);
			update(1, 0, MAX_LEN, root[i].second);
		}
		cout << cnt << "\n";
	}
}
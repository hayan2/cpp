#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

#define ll long long

const int MAX_N = 2e5 + 3;
const int MOD = 1e9 + 7;

typedef pair<ll, ll> pll;

vector<pll> root;
vector<pll> batch;
vector<ll> segmentTree;
ll tmp[MAX_N];
ll N, x, y, cnt = 0, cnt = 0;

ll query(ll node, ll low, ll high, ll s, ll e) {
	if (high < s || e < low) return 0;
	if (s <= low && high <= e) return segmentTree[node];

	ll mid = (low + high) >> 1;

	return (query(2 * node, low, mid, s, e) + query(2 * node + 1, mid + 1, high, s, e)) % MOD;
}

void update(ll node, ll low, ll high, ll idx) {
	if (idx < low || high < idx) return;
	segmentTree[node]++;
	if (low == high) return;

	ll mid = (low + high) >> 1;
	update(2 * node, low, mid, idx);
	update(2 * node + 1, mid + 1, high, idx);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (ll i = 0; i < N; i++) {
		cin >> x >> y;

		root.push_back({ x, y });
	}
	sort(root.begin(), root.end(), [](pll& a, pll& b) { return a.first < b.first; });

	for (ll i = 0; i < N; i++) {
		if (i > 0 && root[i].first != root[i - 1].first) cnt++;
		tmp[i] = cnt;
	}
	for (ll i = 0; i < N; i++) root[i].first = tmp[i];

	sort(root.begin(), root.end(), [](pll& a, pll& b) {
		return (a.second == b.second) ? a.first < b.first : a.second > b.second;
		});
	ll depth = (1 << (ll)ceil(log2(cnt + 1) + 1));
	segmentTree.assign(depth, 0);
	
	ll prev = root[0].second;
	for (ll i = 0; i < N; i++) {		
		if (prev != root[i].second) {
			for (auto x : batch) update(1, 0, cnt, x.first);
			batch.clear();
			prev = root[i].second;
		}
		cnt += query(1, 0, cnt, 0, root[i].first - 1) * query(1, 0, cnt, root[i].first + 1, cnt) % MOD;
		batch.push_back(root[i]);
	}

	cout << cnt % MOD;

	return 0;
}
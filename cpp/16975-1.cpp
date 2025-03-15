#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

#define ll long long

vector<ll> cache, segmentTree, lazy;
ll k;
int N, M, query, s, e, x, depth;

void init() {
	depth = (1 << (int)(ceil(log2(N)) + 1));
	cache.resize(N + 1);
	segmentTree.resize(depth);
	lazy.resize(depth);
}

ll getSegmentTree(int low, int high, int node) {
	if (low == high) return segmentTree[node] = cache[low];

	int mid = (low + high) >> 1;
	return segmentTree[node] = getSegmentTree(low, mid, node * 2) + getSegmentTree(mid + 1, high, node * 2 + 1);
}

void lazyPropagation(int low, int high, int node) {
	if (lazy[node]) {
		segmentTree[node] += (ll)(high - low + 1) * lazy[node];
		if (low != high) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int low, int high, int node) {
	lazyPropagation(low, high, node);

	if (s > high || e < low) return;
	if (s <= low && high <= e) {
		segmentTree[node] += (ll)(high - low + 1) * k;
		if (low != high) {
			lazy[node * 2] += k;
			lazy[node * 2 + 1] += k;
		}
		return;
	}

	int mid = (low + high) >> 1;
	update(low, mid, node * 2);
	update(mid + 1, high, node * 2 + 1);
	segmentTree[node] = segmentTree[node * 2] + segmentTree[node * 2 + 1];
}

ll getResult(int low, int high, int node) {
	lazyPropagation(low, high, node);

	if (x > high || x < low) return 0;
	if (x <= low && high <= x) return segmentTree[node];

	int mid = (low + high) >> 1;
	return getResult(low, mid, node * 2) + getResult(mid + 1, high, node * 2 + 1);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	init();
	for (int i = 0; i < N; i++) cin >> cache[i];
	cin >> M;

	getSegmentTree(0, N - 1, 1);

	while (M--) {
		cin >> query;

		if (query == 1) {			
			cin >> s >> e >> k;
			s--, e--;
			update(0, N - 1, 1);
		}
		else {
			cin >> x;
			x--;
			cout << getResult(0, N - 1, 1) << "\n";
		}
	}

	return 0;
}
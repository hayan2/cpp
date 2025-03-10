#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

#define ll long long
typedef pair<int, int> type;

vector<type> cache;
vector<int> segmentTree;
ll res = 0;
int N, x;

void getSegmentTree(int low, int high, int node, int idx) {
	if (low == high) {
		segmentTree[node] = 1;
		return;
	}

	int mid = (low + high) / 2;

	if (idx <= mid) getSegmentTree(low, mid, node * 2, idx);
	else getSegmentTree(mid + 1, high, node * 2 + 1, idx);

	segmentTree[node] = segmentTree[node * 2] + segmentTree[node * 2 + 1];
}

ll solved(int low, int high, int node, int s, int e) {
	if (s > high || e < low) return 0;
	if (s <= low && high <= e) return segmentTree[node];

	int mid = (low + high) / 2;

	return solved(low, mid, node * 2, s, e) + solved(mid + 1, high, node * 2 + 1, s, e);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int depth = (1 << (int)ceil(log2(N)) + 1);
	segmentTree.resize(depth);

	for (int i = 0; i < N; i++) {
		cin >> x;
		cache.push_back({ x, i });
	}

	sort(cache.begin(), cache.end());

	for (int i = 0; i < N; i++) {
		int idx = cache[i].second;

		res += solved(0, N - 1, 1, idx + 1, N - 1);

		getSegmentTree(0, N - 1, 1, idx);
	}

	cout << res;

	return 0;
}
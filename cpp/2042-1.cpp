#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

#define lli long long int

// AC

vector<lli> segmentTree, cache;
lli mod, query, s, e;
int N, M, K, x;

void init() {
	x = ceil(log2(N));
	int height = (1 << (x + 1));
	segmentTree.resize(height);
	cache.resize(N + 1);
}

lli getSegmentTree(int low, int high, int idx) {
	if (low == high) return segmentTree[idx] = cache[low];

	int mid = (low + high) / 2;
	return segmentTree[idx] = getSegmentTree(low, mid, idx * 2) + getSegmentTree(mid + 1, high, idx * 2 + 1);
}

lli getResult(int low, int high, int idx) {
	if (s > high || e < low) return 0;
	else if (s <= low && high <= e) return segmentTree[idx];

	int mid = (low + high) / 2;
	return getResult(low, mid, idx * 2) + getResult(mid + 1, high, idx * 2 + 1);
}

void modify(int low, int high, int idx) {
	if (s < low || s > high) return;
	segmentTree[idx] += mod;
	
	if (low != high) {
		int mid = (low + high) / 2;
		modify(low, mid, idx * 2);
		modify(mid + 1, high, idx * 2 + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	init();

	for (int i = 0; i < N; i++) cin >> cache[i];
	getSegmentTree(0, N - 1, 1);

	for (int i = 0; i < M + K; i++) {
		cin >> query >> s >> e;

		if (query == 1) {
			mod = e - cache[--s];
			cache[s] = e;
			modify(0, N - 1, 1);
		}
		else if (query == 2) {
			s--, e--;
			cout << getResult(0, N - 1, 1) << "\n";
		}
	}

	return 0;
}
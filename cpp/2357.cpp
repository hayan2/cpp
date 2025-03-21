#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

#define ll unsigned long long
#define INF 1e9

vector<int> smax, smin, cache;
int N, M, height, x, s, e;

void init() {
	x = ceil(log2(N));
	height = (1 << (x + 1));
	smax.resize(height);
	smin.resize(height);
	cache.resize(N + 1);
}

int getMaxSegmentTree(int low, int high, int idx) {
	if (low == high) return smax[idx] = cache[low];

	int mid = (low + high) / 2;
	return smax[idx] = max(getMaxSegmentTree(low, mid, idx * 2), getMaxSegmentTree(mid + 1, high, idx * 2 + 1));
}

int getMinSegmentTree(int low, int high, int idx) {
	if (low == high) return smin[idx] = cache[low];

	int mid = (low + high) / 2;
	return smin[idx] = min(getMinSegmentTree(low, mid, idx * 2), getMinSegmentTree(mid + 1, high, idx * 2 + 1));
}

int getMaximum(int low, int high, int idx) {
	if (s > high || e < low) return -INF;
	else if (s <= low && high <= e) return smax[idx];

	int mid = (low + high) / 2;
	return max(getMaximum(low, mid, idx * 2), getMaximum(mid + 1, high, idx * 2 + 1));
}

int getMinimum(int low, int high, int idx) {
	if (s > high || e < low) return INF;
	else if (s <= low && high <= e) return smin[idx];

	int mid = (low + high) / 2;
	return min(getMinimum(low, mid, idx * 2), getMinimum(mid + 1, high, idx * 2 + 1));
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	init();

	for (int i = 0; i < N; i++) cin >> cache[i];

	getMaxSegmentTree(0, N - 1, 1);
	getMinSegmentTree(0, N - 1, 1);

	while (M--) {
		cin >> s >> e;
		s--, e--;
		cout << getMinimum(0, N - 1, 1) << " " << getMaximum(0, N - 1, 1) << "\n";
	}

	return 0;
}
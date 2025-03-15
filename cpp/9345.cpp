#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

#define INF 1e9

// TLE

vector<int> smax, smin, cache;
int T, N, K, query, s, e;

void init() {
	int depth = (1 << (int)(ceil(log2(N)) + 1));
	smax.resize(depth), smin.resize(depth);
	cache.clear();
}

int getMaxSegmentTree(int low, int high, int node) {
	if (low == high) return smax[node] = cache[low];

	int mid = (low + high) / 2;
	return smax[node] = max(getMaxSegmentTree(low, mid, node * 2), getMaxSegmentTree(mid + 1, high, node * 2 + 1));
}

int getMinSegmentTree(int low, int high, int node) {
	if (low == high) return smin[node] = cache[low];

	int mid = (low + high) / 2;
	return smin[node] = min(getMinSegmentTree(low, mid, node * 2), getMinSegmentTree(mid + 1, high, node * 2 + 1));
}

int getMaximum(int low, int high, int node) {	
	if (s > high || e < low) return -INF;
	else if (s <= low && high <= e) return smax[node];

	int mid = (low + high) / 2;
	return max(getMaximum(low, mid, node * 2), getMaximum(mid + 1, high, node * 2 + 1));
}

int getMinimum(int low, int high, int node) {
	if (s > high || e < low) return INF;
	else if (s <= low && high <= e) return smin[node];

	int mid = (low + high) / 2;
	return min(getMinimum(low, mid, node * 2), getMinimum(mid + 1, high, node * 2 + 1));
}

string solved() {
	return (getMinimum(0, N - 1, 1) == s) && (getMaximum(0, N - 1, 1) == e) ? "YES" : "NO";
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--) {
		cin >> N >> K;
				
		init();
		for (int i = 0; i < N; i++) cache.push_back(i);

		getMaxSegmentTree(0, N - 1, 1);
		getMinSegmentTree(0, N - 1, 1);

		for (int i = 0; i < K; i++) {
			cin >> query >> s >> e;

			if (!query) {
				// swap
				swap(cache[s], cache[e]);

				getMaxSegmentTree(0, N - 1, 1);
				getMinSegmentTree(0, N - 1, 1);
			}
			else {
				// find
				cout << solved() << "\n";
			}
		}				
	}

	return 0;
}
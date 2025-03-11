#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

#define INF 1e9

// MLE

int T, N, K, q, s, e;

void init(vector<int>& smin, vector<int>& smax) {
	int depth = (1 << (int)(ceil(log2(N)) + 1));
	smax.resize(depth), smin.resize(depth);
}

int getMaxSegmentTree(int low, int high, int node, vector<int>& cache, vector<int>& smax) {
	if (low == high) return smax[node] = cache[low];

	int mid = (low + high) / 2;
	return smax[node] = max(getMaxSegmentTree(low, mid, node * 2, cache, smax), getMaxSegmentTree(mid + 1, high, node * 2 + 1, cache, smax));
}

int getMinSegmentTree(int low, int high, int node, vector<int>& cache, vector<int>& smin) {
	if (low == high) return smin[node] = cache[low];

	int mid = (low + high) / 2;
	return smin[node] = min(getMinSegmentTree(low, mid, node * 2, cache, smin), getMinSegmentTree(mid + 1, high, node * 2 + 1, cache, smin));
}

int getMaximum(int low, int high, int node, vector<int>& smax) {
	if (s > high || e < low) return -INF;
	else if (s <= low && high <= e) return smax[node];

	int mid = (low + high) / 2;
	return max(getMaximum(low, mid, node * 2, smax), getMaximum(mid + 1, high, node * 2 + 1, smax));
}

int getMinimum(int low, int high, int node, vector<int>& smin) {
	if (s > high || e < low) return INF;
	else if (s <= low && high <= e) return smin[node];

	int mid = (low + high) / 2;
	return min(getMinimum(low, mid, node * 2, smin), getMinimum(mid + 1, high, node * 2 + 1, smin));
}

bool solved(vector<int>& smin, vector<int>& smax) {
	return (getMinimum(0, N - 1, 1, smin) == s) && (getMaximum(0, N - 1, 1, smax) == e);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	scanf("%d", &T);

	while (T--) {
		scanf("%d %d", &N, &K);

		vector<int> smax, smin, cache;

		init(smin, smax);
		for (int i = 0; i < N; i++) cache.push_back(i);

		getMaxSegmentTree(0, N - 1, 1, cache, smax);
		getMinSegmentTree(0, N - 1, 1, cache, smin);

		for (int i = 0; i < K; i++) {
			cin >> q >> s >> e;

			if (!q) {
				// swap
				swap(cache[s], cache[e]);

				getMaxSegmentTree(0, N - 1, 1, cache, smax);
				getMinSegmentTree(0, N - 1, 1, cache, smin);
			}
			else {
				// find				
				if (solved(smin, smax)) printf("YES\n");
				else printf("NO\n");
			}
		}
	}

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>

using namespace std;

#define MAX_LEN 300004
#define MAX_N 100001
#define INF 1e8

typedef pair<int, int> pii;

pii segmentTree[MAX_LEN];
int cache[MAX_N];
int T, N, K, query, s, e;

void init() {
	memset(segmentTree, 0, sizeof(segmentTree));
	memset(cache, 0, sizeof(cache));
}

pii getSegmentTree(int low, int high, int node) {
	if (low == high) return segmentTree[node] = { cache[low], cache[low] };

	int mid = (low + high) / 2;

	pii left = getSegmentTree(low, mid, node * 2);
	pii right = getSegmentTree(mid + 1, high, node * 2 + 1);

	return segmentTree[node] = { min(left.first, right.first), max(left.second, right.second) };
}

pii getResult(int low, int high, int node) {
	if (s > high || e < low) return { INF, -INF };
	else if (s <= low && high <= e) return segmentTree[node];

	int mid = (low + high) / 2;

	pii left = getResult(low, mid, node * 2);
	pii right = getResult(mid + 1, high, node * 2 + 1);

	return { min(left.first, right.first), max(left.second, right.second) };
}

pii update(int low, int high, int node, int idx, int n) {
	if (idx < low || idx > high) return segmentTree[node];
	if (low == high) return segmentTree[node] = { n, n };

	int mid = (low + high) / 2;
	pii left = update(low, mid, node * 2, idx, n);
	pii right = update(mid + 1, high, node * 2 + 1, idx, n);

	return segmentTree[node] = { min(left.first, right.first), max(left.second, right.second) };
}

bool solved(pii x) {
	return (x.first == s && x.second == e);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	scanf("%d", &T);

	while (T--) {
		scanf("%d %d", &N, &K);

		init();

		for (int i = 0; i < N; i++) cache[i] = i;

		getSegmentTree(0, N - 1, 1);

		while (K--) {
			scanf("%d %d %d", &query, &s, &e);

			if (!query) {
				update(0, N - 1, 1, cache[s], e);
				update(0, N - 1, 1, cache[e], s);
				swap(cache[s], cache[e]);
			}
			else solved(getResult(0, N - 1, 1)) ? cout << "YES\n" : cout << "NO\n";
		}
	}

	return 0;
}
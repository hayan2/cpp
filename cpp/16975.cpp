#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

#define ll long long

vector<ll> cache, segmentTree;
int N, M, q, s, e, k, x, depth;

void init() {
	depth = (1 << (int)(ceil(log2(N)) + 1));
	segmentTree.resize(depth);
	cache.resize(N);	
}

ll getSegmentTree(int low, int high, int node) {
	if (low == high) return segmentTree[node] = cache[low];

	int mid = (low + high) / 2;
	return segmentTree[node] = getSegmentTree(low, mid, node * 2) + getSegmentTree(mid + 1, high, node * 2 + 1);
}

void modify(int low, int high, int node) {
	if (s < low || s > high) return;
	segmentTree[node] += k;

	if (low != high) {
		int mid = (low + high) / 2;
		modify(low, mid, node * 2);
		modify(mid + 1, high, node * 2 + 1);
	}
}

ll getResult(int low, int high, int node) {
	if (low == high && low == x) return segmentTree[node];
	
	int mid = (low + high) >> 1;
	if (mid < x) {
		getResult(mid + 1, high, node * 2 + 1);
	}
	else {
		getResult(low, mid, node * 2);
	}	
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	init();
	for (int i = 0; i < N; i++) cin >> cache[i];
	getSegmentTree(0, N - 1, 1);
	cin >> M;
	
	while (M--) {
		cin >> q;

		if (q == 1) {
			cin >> s >> e >> k;
			s--, e--;
			modify(0, N - 1, 1);

			/*
			for (int i = 0; i < depth; i++) {
				cout << segmentTree[i] << " ";
			}
			cout << "\n";	
			*/
		}
		else if (q == 2) {
			cin >> x;

			cout << getResult(0, N - 1, 1) << "\n";
		}
	}

	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

#define lli long long int

vector<lli> segmentTree;
vector<lli> cache;
int N, M, K, x;

void init() {
	x = ceil(log2(N));
	segmentTree.resize((1 << (x + 1)));
	cache.resize(N + 1);
}

int getSegmentTree(int low, int high, int idx) {
	if (low == high) return segmentTree[idx] = cache[low];

	int mid = (low + high) / 2;
	return segmentTree[idx] = getSegmentTree(low, mid, idx * 2) + getSegmentTree(mid + 1, high, idx * 2 + 1);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	init();

	for (int i = 0; i < N; i++) cin >> cache[i];
	getSegmentTree(0, N - 1, 1);

	for (int i = 0; i < (1 << (x + 1)); i++) {
		cout << segmentTree[i] << " ";
	}

	return 0;
}
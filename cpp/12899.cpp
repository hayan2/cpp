#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 2000000

int segmentTree[1 << 22];
int N, q, x;

int update(int low, int high, int node) {
	if (low == high) return ++segmentTree[node];

	int mid = (low + high) >> 1;

	if (x <= mid) update(low, mid, node * 2);
	else update(mid + 1, high, node * 2 + 1);

	return segmentTree[node] = segmentTree[node * 2] + segmentTree[node * 2 + 1];
}

int solved(int low, int high, int node) {
	if (low == high) {
		segmentTree[node]--;
		return low;
	}

	int ret = 0;
	int mid = (low + high) >> 1;

	if (x <= segmentTree[node * 2]) ret = solved(low, mid, node * 2);
	else {
		x -= segmentTree[node * 2];
		ret = solved(mid + 1, high, node * 2 + 1);
	}
	segmentTree[node] = segmentTree[node * 2] + segmentTree[node * 2 + 1];

	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> q >> x;
		
		if (q == 1) {
			x--;
			update(0, MAX_N - 1, 1);
		}
		else {			
			cout << solved(0, MAX_N - 1, 1) + 1 << "\n";
		}
	}

	return 0;
}
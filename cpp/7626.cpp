#include <iostream>
#include <algorithm>

using namespace std;

using ull = unsigned long long;
const int MAX_N = 200001;

typedef struct SegmentTree {
	ull length;
	int count;
}SegmentTree;

typedef struct Coordinate {
	ull val, y1, y2;
	int idx;
}Coordinate;

typedef struct Y {
	ull val;
	int idx;
}Y;

SegmentTree segmentTree[MAX_N * 8];
Coordinate cache[MAX_N * 2];
Y y[MAX_N * 2];
ull res = 0;
int N;

void update(int low, int high, int s, int e, int node, int x) {
	int mid = (low + high) >> 1;
	if (s <= low && high <= e) segmentTree[node].count += x;
	else {
		if (s <= mid) update(low, mid, s, e, node * 2, x);
		if (e > mid) update(mid + 1, high, s, e, node * 2 + 1, x);
	}

	if (segmentTree[node].count) segmentTree[node].length = y[high + 1].val - y[low].val;
	else {
		if (low == high) segmentTree[node].length = 0;
		else segmentTree[node].length = segmentTree[node * 2].length + segmentTree[node * 2 + 1].length;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int l = i * 2, r = i * 2 + 1;
		cin >> cache[l].val >> cache[r].val >> y[l].val >> y[r].val;
		cache[l].idx = y[l].idx = l;
		cache[r].idx = y[r].idx = r;
	}
	sort(y, y + N * 2, [](Y& a, Y& b) { return a.val < b.val; });
	
	for (int i = 0; i < N * 2; i++) {
		cout << y[i].idx << ", " << y[i].val << "\n";
	}
	cout << "----\n";

	for (int i = 0; i < N * 2; i++) {
		int idx = y[i].idx / 2;
		if (!(y[i].idx & 1)) {
			cache[idx * 2].y1 = i;
			cache[idx * 2 + 1].y1 = i;
		}
		else {
			cache[idx * 2].y2 = i;
			cache[idx * 2 + 1].y2 = i;
		}
	}

	sort(cache, cache + N * 2, [](Coordinate& a, Coordinate& b) { return a.val < b.val; });

	for (int i = 0; i < N * 2; i++) {
		cout << cache[i].idx << ", " << cache[i].val << ", " << cache[i].y1 << ", " << cache[i].y2 << "\n";
	}
	cout << "------\n";

	for (int i = 0; i < N * 2; i++) {
		if (i > 0) res += segmentTree[1].length * (cache[i].val - cache[i - 1].val);
		if (!(cache[i].val & 1)) update(0, N * 2 - 1, cache[i].y1, cache[i].y2 - 1, 1, 1);
		else update(0, N * 2 - 1, cache[i].y1, cache[i].y2 - 1, 1, -1);
	}

	cout << res;

	return 0;
}
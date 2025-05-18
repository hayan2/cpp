#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAX_N = 400001;

typedef struct Coordinate {
	int x;
	pii y;
	bool flag;
}Coordinate;

ll segmentTree[MAX_N * 4], cnt[MAX_N * 4], cnt = 0;
vector<Coordinate> cache;
vector<ll> y;
int N;

void update(int node, int low, int high, int s, int e, int x) {
	if (s > high || e < low) return;
	if (s <= low && high <= e) cnt[node] += x;
	else {		
		int mid = (low + high) >> 1;
		update(node * 2, low, mid, s, e, x);
		update(node * 2 + 1, mid + 1, high, s, e, x);
	}

	if (cnt[node]) segmentTree[node] = y[high] - y[low - 1];
	else {
		if (low == high) segmentTree[node] = 0;
		else segmentTree[node] = segmentTree[node * 2] + segmentTree[node * 2 + 1];
	}
}

Coordinate generateCache(int x, int y1, int y2, bool flag) {
	Coordinate tmp;
	tmp.x = x;
	tmp.y.first = y1; tmp.y.second = y2;
	tmp.flag = flag;

	return tmp;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x1, x2, y1, y2;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x1 >> x2 >> y1 >> y2;
		cache.push_back(generateCache(x1, y1 + 1, y2 + 1, true));
		cache.push_back(generateCache(x2, y1 + 1, y2 + 1, false));
		y.push_back(y1 + 1);
		y.push_back(y2 + 1);
	}

	sort(y.begin(), y.end());
	y.erase(unique(y.begin(), y.end()), y.end());
	sort(cache.begin(), cache.end(), [](Coordinate& a, Coordinate& b) { return a.x < b.x; });
		
	for (int i = 0; i < cache.size(); i++) {
		if (i > 0) cnt += segmentTree[1] * (cache[i].x - cache[i - 1].x);
		int x = cache[i].flag == true ? 1 : -1;
		int y1 = lower_bound(y.begin(), y.end(), cache[i].y.first) - y.begin();
		int y2 = lower_bound(y.begin(), y.end(), cache[i].y.second) - y.begin();
		update(1, 1, y.size(), y1 + 1, y2, x);
	}

	cout << cnt;

	return 0;
}
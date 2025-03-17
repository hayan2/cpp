#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX_N 100000
#define ROOT 1

queue<int> res;
int segmentTree[1 << 18] = { 0, };
int N, K, previous = 0;

int update(int low, int high, int node) {
	if (low == high) return ++segmentTree[node];

	int mid = (low + high) >> 1;
	return segmentTree[node] = update(low, mid, node * 2) + update(mid + 1, high, node * 2 + 1);
}

int solved(int low, int high, int node, int x) {
	segmentTree[node]--;
	if (low == high) return low;

	int mid = (low + high) >> 1;
	if (x <= segmentTree[node * 2]) return solved(low, mid, node * 2, x);
	else return solved(mid + 1, high, node * 2 + 1, x - segmentTree[node * 2]);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	previous = K;
	update(0, N - 1, 1);

	cout << "<";
	for (int i = 0; i < N - 1; i++) {
		cout << solved(0, N - 1, 1, previous) + 1 << ", ";
		previous += K - 1;
		(!(previous % segmentTree[ROOT])) ? previous = segmentTree[ROOT] : previous %= segmentTree[ROOT];
	}
	cout << solved(0, N - 1, 1, previous) + 1;
	cout << ">";

	return 0;
}
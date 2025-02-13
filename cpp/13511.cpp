#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_N 100001
#define MAX_LOG 18
#define ull unsigned long long

typedef pair<ull, ull> type;

vector<type> tree[MAX_N];
ull dist[MAX_N] = { 0, }, cache[MAX_N][MAX_LOG] = { 0, }, depth[MAX_N] = { 0, };
ull N, M, u, v, w;

void getDepth(ull cur, ull prev) {
	cache[0][cur] = prev;
	depth[cur] = depth[prev] + 1;

	for (type nxt : tree[cur]) {
		if (nxt.first != prev) {
			dist[nxt.first] = dist[cur] + nxt.second;
			getDepth(nxt.first, cur);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v >> w;

		tree[u].push_back({ v, w });
		tree[v].push_back({ u, w });
	}

	getDepth(1, 0);



	return 0;
}
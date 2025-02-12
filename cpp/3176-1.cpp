#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_LEN 100001
#define MAX_LOG 18
#define LONGEST 0
#define SHORTEST 1
#define DISTANCE 2
#define INF 1e8

typedef pair<int, int> type;

vector<type> tree[MAX_LEN];
int cache[MAX_LEN][MAX_LOG][DISTANCE] = { 0, };
int parent[MAX_LEN][MAX_LOG] = { 0, };
int depth[MAX_LEN] = { 0, };
int N, K, u, v, w, D, E;

// AC
// MEM 32384 KB | TIME 136 ms

void getDepth(int cur, int curDepth, int prev) {
	depth[cur] = curDepth;

	for (auto nxt : tree[cur]) {
		if (nxt.first != prev) {
			parent[nxt.first][0] = cur;
			cache[nxt.first][0][LONGEST] = nxt.second;
			cache[nxt.first][0][SHORTEST] = nxt.second;
			getDepth(nxt.first, curDepth + 1, cur);
		}
	}
}

void dp() {
	for (int i = 1; i < MAX_LOG; i++) {
		for (int j = 1; j <= N; j++) {
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
			cache[j][i][LONGEST] = max(cache[parent[j][i - 1]][i - 1][LONGEST], cache[j][i - 1][LONGEST]);
			cache[j][i][SHORTEST] = min(cache[parent[j][i - 1]][i - 1][SHORTEST], cache[j][i - 1][SHORTEST]);
		}
	}
}

type solved(int a, int b) {
	if (depth[a] < depth[b]) {
		int tmp = a;
		a = b;
		b = tmp;
	}

	int amin = INF, amax = -INF, bmin = INF, bmax = -INF;
	if (b == 1) {
		bmin = INF;
		bmax = -INF;
	}

	for (int i = MAX_LOG - 1; i > -1; i--) {
		if (depth[a] - depth[b] >= (1 << i)) {
			amax = max(amax, cache[a][i][LONGEST]);
			amin = min(amin, cache[a][i][SHORTEST]);
			a = parent[a][i];
		}
	}

	if (a == b) return { min(amin, bmin), max(amax, bmax) };

	for (int i = MAX_LOG - 1; i > -1; i--) {
		if (parent[a][i] != parent[b][i]) {
			amax = max(amax, cache[a][i][LONGEST]);
			amin = min(amin, cache[a][i][SHORTEST]);
			bmax = max(bmax, cache[b][i][LONGEST]);
			bmin = min(bmin, cache[b][i][SHORTEST]);
			a = parent[a][i];
			b = parent[b][i];
		}
	}

	if (parent[a][0] == parent[b][0]) {
		return { min(min(amin, bmin), min(cache[a][0][SHORTEST], cache[b][0][LONGEST])), max(max(amax, bmax), max(cache[b][0][LONGEST], cache[a][0][LONGEST])) };
	}

	return { min(amin, bmin), max(amax, bmax) };
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

	getDepth(1, 1, 0);
	dp();

	cin >> K;

	while (K--) {
		cin >> D >> E;

		type ret = solved(D, E);

		cout << ret.first << " " << ret.second << "\n";
	}

	return 0;
}
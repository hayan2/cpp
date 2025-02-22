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
int sccidx[MAX_LEN][MAX_LOG][DISTANCE] = { 0, };
int parent[MAX_LEN][MAX_LOG] = { 0, };
int depth[MAX_LEN] = { 0, };
int V, K, u, v, w, D, E;

// WA

void getDepth(int cur, int curDepth, int prev) {
	depth[cur] = curDepth;

	for (auto nxt : tree[cur]) {
		if (nxt.first != prev) {
			parent[nxt.first][0] = cur;
			sccidx[nxt.first][0][LONGEST] = nxt.second;
			sccidx[nxt.first][0][SHORTEST] = nxt.second;
			getDepth(nxt.first, curDepth + 1, cur);
		}
	}
}

void dp() {
	for (int i = 1; i < MAX_LOG; i++) {
		for (int j = 1; j <= V; j++) {
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
			sccidx[j][i][LONGEST] = max(sccidx[parent[j][i - 1]][i - 1][LONGEST], sccidx[j][i - 1][LONGEST]);
			sccidx[j][i][SHORTEST] = min(sccidx[parent[j][i - 1]][i - 1][SHORTEST], sccidx[j][i - 1][SHORTEST]);
		}
	}
}

type solved(int a, int b) {	
	if (depth[a] < depth[b]) {
		int tmp = a;
		a = b;
		b = tmp;
	}

	int amin = sccidx[a][0][SHORTEST], amax = sccidx[a][0][LONGEST], bmin = sccidx[b][0][SHORTEST], bmax = sccidx[b][0][LONGEST];
	if (b == 1) {
		bmin = INF;
		bmax = -1;
	}

	for (int i = MAX_LOG - 1; i > -1; i--) {
		if (depth[a] - depth[b] >= (1 << i)) {
			amax = max(amax, sccidx[a][i][LONGEST]);
			amin = min(amin, sccidx[a][i][SHORTEST]);
			a = parent[a][i];
		}
	}

	if (a == b) return { min(amin, bmin), max(amax, bmax) };

	for (int i = MAX_LOG - 1; i > -1; i--) {
		if (parent[a][i] != parent[b][i]) {
			amax = max(amax, sccidx[a][i][LONGEST]);
			amin = min(amin, sccidx[a][i][SHORTEST]);
			bmax = max(bmax, sccidx[b][i][LONGEST]);
			bmin = min(bmin, sccidx[b][i][SHORTEST]);
			a = parent[a][i];
			b = parent[b][i];
		}
	}

	amax = max(amax, sccidx[a][0][LONGEST]);
	amin = min(amin, sccidx[a][0][SHORTEST]);
	bmax = max(bmax, sccidx[b][0][LONGEST]);
	bmin = min(bmin, sccidx[b][0][SHORTEST]);

	return { min(amin, bmin), max(amax, bmax) };
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V;

	for (int i = 0; i < V - 1; i++) {
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
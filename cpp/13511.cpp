#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_N 100001
#define MAX_LOG 18
#define ull unsigned long long

typedef pair<ull, ull> type;

vector<type> tree[MAX_N];
ull dist[MAX_N] = { 0, }, sccidx[MAX_N][MAX_LOG] = { 0, }, depth[MAX_N] = { 0, };
ull V, E, u, v, w, query;

void getDepth(ull cur, ull prev) {
	sccidx[cur][0] = prev;
	depth[cur] = depth[prev] + 1;

	for (type nxt : tree[cur]) {
		if (nxt.first != prev) {
			dist[nxt.first] = dist[cur] + nxt.second;
			getDepth(nxt.first, cur);
		}
	}
}

void getParnet() {
	for (int i = 1; i < MAX_LOG; i++) {
		for (int j = 1; j <= V; j++) {
			sccidx[j][i] = sccidx[sccidx[j][i - 1]][i - 1];
		}
	}
}

ull LCA(ull a, ull b) {
	if (depth[a] < depth[b]) {
		ull tmp = a;
		a = b;
		b = tmp;
	}

	for (int i = MAX_LOG - 1; i > -1; i--) {
		if (depth[a] - depth[b] >= (1LL << i)) a = sccidx[a][i];
	}

	if (a == b) return a;

	for (int i = MAX_LOG - 1; i > -1; i--) {
		if (sccidx[a][i] != sccidx[b][i]) {
			a = sccidx[a][i];
			b = sccidx[b][i];
		}
	}

	return sccidx[a][0];
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

	getDepth(1, 0);
	getParnet();

	cin >> E;

	while (E--) {
		cin >> query;

		if (query == 1) {
			cin >> u >> v;

			cout << dist[u] + dist[v] - 2 * dist[LCA(u, v)] << "\n";
		}
		else {
			cin >> u >> v >> w;

			ull l = LCA(u, v);
			if (depth[u] - depth[l] + 1 < w) {
				w = depth[u] + depth[v] - 2 * depth[l] - w + 1;
				for (int i = MAX_LOG - 1; i > -1; i--) {
					if (w >= (1LL << i)) {
						w -= (1LL << i);
						v = sccidx[v][i];
					}
				}
				cout << v << "\n";
			}
			else {
				w--;
				for (int i = MAX_LOG - 1; i > -1; i--) {
					if (w >= (1LL << i)) {
						w -= (1LL << i);
						u = sccidx[u][i];
					}
				}
				cout << u << "\n";
			}
		}
	}

	return 0;
}
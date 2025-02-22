#define MAX_LEN 100001
#define VISITED 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

vector<int> tree[MAX_LEN];
int sccidx[MAX_LEN];
int visited[MAX_LEN] = { 0, };
int V, R, Q;
int u, v, q;

int solved(int s) {
	if (visited[s]) return sccidx[s];
	visited[s] = VISITED;

	for (auto nxt : tree[s]) {
		if (visited[nxt]) continue;
		sccidx[s] += solved(nxt);
	}

	return sccidx[s];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> R >> Q;
	fill_n(&sccidx[0], V + 1, 1);

	for (int i = 0; i < V - 1; i++) {
		cin >> u >> v;

		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	solved(R);

	while (Q--) {
		cin >> q;

		cout << sccidx[q] << "\n";
	}

	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_LEN 100001
#define MAX_LOG 18
#define ROOT 1

using namespace std;

vector<int> tree[MAX_LEN];
int sccidx[MAX_LEN][MAX_LOG] = { 0, };
int depth[MAX_LEN] = { 0, };
int V, E, u, v;

void getDepth(int cur, int curDepth, int parent) {
	depth[cur] = curDepth;

	for (auto nxt : tree[cur]) {
		if (nxt != parent) {
			sccidx[nxt][0] = cur;
			getDepth(nxt, curDepth + 1, cur);
		}
	}
}

void getParent() {	
	for (int i = 1; i < MAX_LOG; i++) {
		for (int j = 1; j <= V; j++) {
			sccidx[j][i] = sccidx[sccidx[j][i - 1]][i - 1];
		}
	}
}

int solved(int a, int b) {
	if (depth[a] < depth[b]) {
		int tmp = a;
		a = b;
		b = tmp;
	}

	for (int i = MAX_LOG - 1; i > -1; i--) {
		if (depth[a] - depth[b] >= (1 << i)) {
			a = sccidx[a][i];
		}
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
		cin >> u >> v;

		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	getDepth(ROOT, 1, 0);
	getParent();

	cin >> E;
	
	while (E--) {
		int a, b;

		cin >> a >> b;

		cout << solved(a, b) << "\n";
	}
	
	return 0;
}
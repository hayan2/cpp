#define MAX_LEN 10001
#define ll unsigned long long
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, pair<int, int>> type;

vector<type> sccidx;
int root[MAX_LEN];
int V, E;

int find(int x) {
	if (root[x] == x) return root[x];
	else return root[x] = find(root[x]);
}

void unionSet(int a, int b) {
	a = find(a);
	b = find(b);

	if (a > b) root[b] = a;
	else if (a < b) root[a] = b;
}

int solved() {
	vector<type> mst;
	int ret = 0;

	for (type cur : sccidx) {
		int u = cur.second.first;
		int v = cur.second.second;

		if (find(u) == find(v)) continue;

		mst.push_back(cur);
		unionSet(u, v);
		ret += cur.first;

		if (mst.size() == V - 1) return ret;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E;	
	int u, v, w;

	while (E--) {
		cin >> u >> v >> w;

		sccidx.push_back({ w, { u, v } });
	}

	for (int i = 1; i <= V; i++) root[i] = i;
	sort(sccidx.begin(), sccidx.end());

	cout << solved();

	return 0;
}
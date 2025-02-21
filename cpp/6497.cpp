#define MAX_LEN 200015
#define ull unsigned long long
#include <iostream>
#include <algorithm>
#include <vector>

// AC  mem	9076KB    time	228MS

using namespace std;

typedef pair<ull, pair<int, int>> Mst;

vector<Mst> cache;
ull res = 0;
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
	else root[a] = b;
}

ull solved() {
	ull ret = 0;
	int cnt = 0;

	for (Mst cur : cache) {
		int u = cur.second.first;
		int v = cur.second.second;
		ull w = cur.first;

		if (find(u) == find(v)) continue;

		if (cnt == V - 1) break;
		cnt++;
		unionSet(u, v);
		ret += w;
	}

	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	while (1) {
		cin >> V >> E;
		if (!V && !E) break;
		for (int i = 0; i < V; i++) root[i] = i;

		for (int i = 0; i < E; i++) {
			ull w;
			int u, v;

			cin >> u >> v;
			cin >> w;

			cache.push_back({ w, { u, v } });
			res += w;			
		}
		sort(cache.begin(), cache.end());

		cout << res - solved() << "\n";

		cache.clear();
		res = 0;
	}
	
	return 0;
}
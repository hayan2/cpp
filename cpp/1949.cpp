#define MAX_LEN 10001
#define VISITED 1
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct Dp {
	int contain;
	int notContain;
}Dp;

vector<int> edge[MAX_LEN];
Dp sccidx[MAX_LEN] = { 0, };
int visited[MAX_LEN] = { 0, };
int V;
int u, v, w;

Dp solved(int s) {
	if (visited[s]) return sccidx[s];
	visited[s] = VISITED;

	for (auto nxt : edge[s]) {
		if (visited[nxt]) continue;
		Dp ret = solved(nxt);
		sccidx[s].contain += ret.notContain;
		sccidx[s].notContain += (ret.contain > ret.notContain) ? ret.contain : ret.notContain;
	}

	return sccidx[s];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V;

	for (int i = 1; i <= V; i++) {
		cin >> w;
		sccidx[i].contain = w;
		sccidx[i].notContain = 0;
	}
	for (int i = 1; i < V; i++) {
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}

	Dp res = solved(1);

	(res.contain > res.notContain) ? cout << res.contain : cout << res.notContain;

	return 0;
}
#define MAX_LEN 10001
#define CONTAIN 1
#define NOT_CONTAIN 0
#define VISITED 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

typedef struct TDP {
	int contain;
	int notContain;
}TDP;

vector<int> tree[MAX_LEN];
vector<int> res;
TDP sccidx[MAX_LEN];
int visited[MAX_LEN] = { 0, };
int path[MAX_LEN] = { 0, };
int V;
int u, v, w;

TDP solved(int s) {
	if (visited[s]) return sccidx[s];
	visited[s] = VISITED;

	for (auto nxt : tree[s]) {
		if (visited[nxt]) continue;
		TDP ret = solved(nxt);
		sccidx[s].contain += ret.notContain;
		sccidx[s].notContain += (ret.contain > ret.notContain) ? ret.contain : ret.notContain;

		(sccidx[nxt].contain > sccidx[nxt].notContain) ? path[nxt] = CONTAIN : path[nxt] = NOT_CONTAIN;
	}

	return sccidx[s];
}

void findPath(int cur, int pn) {
	visited[cur] = VISITED;
	if (pn) {
		res.push_back(cur);
		for (auto nxt : tree[cur]) {
			if (!visited[nxt]) findPath(nxt, NOT_CONTAIN);
		}
	}
	else {
		for (auto nxt : tree[cur]) {
			if (!visited[nxt]) findPath(nxt, path[nxt]);
		}
	}
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
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	TDP ret = solved(1);
	memset(visited, 0, sizeof(visited));
	(ret.contain > ret.notContain) ? findPath(1, CONTAIN) : findPath(1, NOT_CONTAIN);

	(ret.contain > ret.notContain) ? cout << ret.contain : cout << ret.notContain;	
	cout << "\n";
	sort(res.begin(), res.end());
	for (auto x : res) {
		cout << x << " ";
	}

	return 0;
}
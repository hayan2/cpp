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
Dp cache[MAX_LEN] = { 0, };
int visited[MAX_LEN] = { 0, };
int N;
int u, v, w;

Dp solved(int s) {
	if (visited[s]) return cache[s];
	visited[s] = VISITED;

	for (auto nxt : edge[s]) {
		if (visited[nxt]) continue;
		Dp ret = solved(nxt);
		cache[s].contain += ret.notContain;
		cache[s].notContain += (ret.contain > ret.notContain) ? ret.contain : ret.notContain;
	}

	return cache[s];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> w;
		cache[i].contain = w;
		cache[i].notContain = 0;
	}
	for (int i = 1; i < N; i++) {
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}

	Dp res = solved(1);

	(res.contain > res.notContain) ? cout << res.contain : cout << res.notContain;

	return 0;
}
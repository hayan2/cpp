#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

#define MAX 2000
#define VISITED 1

int id[MAX * 2 + 1];
int N, M, u, v, idx;

int notA(int a) { return a > N ? a - N : a + N; }
int isNegative(int a) { return a < 0 ? -a : a + N; }

void dfs(vector<vector<int>>& edge, vector<int>& visited, vector<int>& st, int cur) {
	visited[cur] = VISITED;
	for (auto nxt : edge[cur]) if (!visited[nxt]) dfs(edge, visited, st, nxt);
	st.push_back(cur);
}

void dfs(vector<vector<int>>& redge, vector<int>& visited, int cur) {
	visited[cur] = VISITED;
	id[cur] = idx;
	for (auto nxt : redge[cur]) if (!visited[nxt]) dfs(redge, visited, nxt);
}

int solved() {
	for (int i = 1; i <= N; i++) if (id[i] == id[i + N]) return 0;
	return 1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (cin >> N >> N) {
		vector<vector<int>> edge(N * 2 + 1);
		vector<vector<int>> redge(N * 2 + 1);
		vector<int> visited(N * 2 + 1);
		vector<int> st;
		memset(id, 0, sizeof(id));

		idx = 0;

		while (M--) {
			cin >> u >> v;

			u = isNegative(u);
			v = isNegative(v);
			edge[notA(u)].push_back(v);
			edge[notA(v)].push_back(u);
			redge[v].push_back(notA(u));
			redge[u].push_back(notA(v));
		}
		edge[1].push_back(1 + N);
		redge[1 + N].push_back(1);

		for (int i = 1; i <= N * 2; i++) if (!visited[i]) dfs(edge, visited, st, i);
		fill(visited.begin(), visited.end(), 0);
		reverse(st.begin(), st.end());
		for (auto x : st) if (!visited[x]) idx++, dfs(redge, visited, x);

		solved() ? cout << "yes\n" : cout << "no\n";
	}

	return 0;
}
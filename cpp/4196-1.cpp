#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define VISITED 1

int V, E, T, u, v;

void dfs(vector<vector<int>>& edge, vector<int>& st, vector<bool>& visited, int cur) {
	if (visited[cur]) return;
	visited[cur] = VISITED;
	for (auto nxt : edge[cur]) dfs(edge, st, visited, nxt);
	st.push_back(cur);
}

void solved(vector<vector<int>>& edge, vector<bool>& visited, int cur) {
	if (visited[cur]) return;
	visited[cur] = VISITED;
	for (auto nxt : edge[cur]) solved(edge, visited, nxt);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--) {
		cin >> V >> E;

		vector<vector<int>> edge(V + 1);
		vector<bool> visited(V + 1);
		vector<int> st;		

		for (int i = 0; i < E; i++) {
			cin >> u >> v;

			edge[u].push_back(v);
		}

		for (int i = 1; i <= V; i++) if (!visited[i]) dfs(edge, st, visited, i);
		reverse(st.begin(), st.end());
		fill(visited.begin(), visited.end(), false);

		int res = 0;
		for (auto x : st) {
			if (!visited[x]) {
				res++;
				solved(edge, visited, x);
			}
		}

		cout << res << "\n";
	}

	return 0;
}
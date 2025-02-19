#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string.h>

using namespace std;

#define FINISHED 1

int sccidx[100001], indegree[100001];
int idx, T, V, E, u, v;

int SCC(vector<vector<int>>& edge, vector<vector<int>>& scc, vector<int>& id, vector<int>& finished, stack<int>& s, int cur) {
	id[cur] = idx++;
	s.push(cur);

	int ret = id[cur];

	for (auto nxt : edge[cur]) {
		if (!id[nxt]) ret = min(ret, SCC(edge, scc, id, finished, s, nxt));
		else if (!finished[nxt]) ret = min(ret, id[nxt]);
	}

	if (ret == id[cur]) {
		vector<int> res;
		int size = scc.size();
		while (1) {
			int top = s.top();
			s.pop();
			res.push_back(top);
			sccidx[top] = size;
			finished[top] = FINISHED;
			if (top == cur) break;
		}
		sort(res.begin(), res.end());
		scc.push_back(res);
	}

	return ret;
}

void solved(vector<vector<int>>& edge) {
	for (int i = 0; i < V; i++) {
		for (auto x : edge[i]) {
			if (sccidx[x] != sccidx[i]) indegree[sccidx[x]]++;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--) {
		cin >> V >> E;

		vector<vector<int>> edge(V + 1);
		vector<vector<int>> scc;
		vector<int> id(V + 1, 0);
		vector<int> finished(V + 1, 0);
		stack<int> s;
		memset(sccidx, 0, sizeof(sccidx));
		memset(indegree, 0, sizeof(indegree));
		idx = 1;

		for (int i = 0; i < E; i++) {
			cin >> u >> v;

			edge[u].push_back(v);
		}

		for (int i = 0; i < V; i++) if (!id[i]) SCC(edge, scc, id, finished, s, i);
		solved(edge);

		int res = -1, cnt = 0;
		for (int i = 0; i < scc.size(); i++) {
			if (!indegree[i]) {
				res = i;
				cnt++;
			}
		}

		if (cnt == 1) for (auto x : scc[res]) cout << x << "\n";
		else cout << "Confused\n";
		cout << "\n";
	}

	return 0;
}
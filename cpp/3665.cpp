#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>

#define MAX_LEN 501

using namespace std;

bool sccidx[MAX_LEN][MAX_LEN];
int indegree[MAX_LEN] = { 0, };
int T, N, m, u, v;

void solved() {
	queue<int> queue;

	for (int i = 1; i <= N; i++) {
		if (!indegree[i]) queue.push(i);
	}

	vector<int> res;

	while (!queue.empty()) {
		int cur = queue.front();
		queue.pop();
		res.push_back(cur);
		indegree[cur]--;

		for (int i = 1; i <= N; i++) {
			if (sccidx[cur][i]) indegree[i]--;
			if (!indegree[i]) queue.push(i);
		}
	}

	if (res.size() == N) {
		for (auto x : res) cout << x << " ";
		cout << "\n";
	}
	else cout << "IMPOSSIBLE" << "\n";
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--) {
		memset(sccidx, false, sizeof(sccidx));
		memset(indegree, 0, sizeof(indegree));

		cin >> N;

		vector<int> rank(N + 1);
		for (int i = 1; i <= N; i++) {
			cin >> rank[i];
		}

		for (int i = 1; i < N; i++) {
			for (int j = i + 1; j <= N; j++) {
				sccidx[rank[i]][rank[j]] = true;
				indegree[rank[j]]++;
			}
		}
		//
		cin >> m;
		for (int i = 1; i <= m; i++) {			
			cin >> u >> v;
			
			if (sccidx[u][v]) {
				sccidx[u][v] = false;
				sccidx[v][u] = true;
				indegree[u]++;
				indegree[v]--;
			}
			else {
				sccidx[v][u] = false;
				sccidx[u][v] = true;
				indegree[v]++;
				indegree[u]--;
			}
		}

		solved();
	}

	return 0;
}
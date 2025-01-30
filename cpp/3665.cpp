#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>

#define MAX_LEN 501

using namespace std;

bool cache[MAX_LEN][MAX_LEN];
int indegree[MAX_LEN] = { 0, };
int T, n, m, u, v;

void solved() {
	queue<int> queue;

	for (int i = 1; i <= n; i++) {
		if (!indegree[i]) queue.push(i);
	}

	vector<int> res;

	while (!queue.empty()) {
		int cur = queue.front();
		queue.pop();
		res.push_back(cur);
		indegree[cur]--;

		for (int i = 1; i <= n; i++) {
			if (cache[cur][i]) indegree[i]--;
			if (!indegree[i]) queue.push(i);
		}
	}

	if (res.size() == n) {
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
		memset(cache, false, sizeof(cache));
		memset(indegree, 0, sizeof(indegree));

		cin >> n;

		vector<int> rank(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> rank[i];
		}

		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j <= n; j++) {
				cache[rank[i]][rank[j]] = true;
				indegree[rank[j]]++;
			}
		}
				
		cin >> m;
		for (int i = 1; i <= m; i++) {			
			cin >> u >> v;
			
			if (cache[u][v]) {
				cache[u][v] = false;
				cache[v][u] = true;
				indegree[u]++;
				indegree[v]--;
			}
			else {
				cache[v][u] = false;
				cache[u][v] = true;
				indegree[v]++;
				indegree[u]--;
			}
		}

		solved();
	}

	return 0;
}
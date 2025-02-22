#include <iostream>
#include <algorithm>
#include <queue>

#define MAX_LEN 32001

using namespace std;

vector<int> sccidx[MAX_LEN];
int indegree[MAX_LEN] = { 0, };
int V, E, u, v;

void solved() {
	queue<int> queue;

	for (int i = 1; i <= V; i++) {
		if (!indegree[i]) queue.push(i);
	}
	
	while (!queue.empty()) {
		int cur = queue.front();
		queue.pop();
		cout << cur << " ";

		for (auto x : sccidx[cur]) {
			if (!(--indegree[x])) queue.push(x);			
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E;

	while (E--) {
		cin >> u >> v;

		sccidx[u].push_back(v);
		indegree[v]++;
	}

	solved();

	return 0;
}
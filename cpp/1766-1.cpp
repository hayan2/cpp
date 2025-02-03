#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX_LEN 32001

using namespace std;

vector<int> cache[MAX_LEN];
int indegree[MAX_LEN] = { 0, };
int N, M, u, v;

void solved() {
	priority_queue<int> queue;
	
	for (int i = 1; i <= N; i++) if (!indegree[i]) queue.push(-i);

	while (!queue.empty()) {
		int cur = -queue.top();
		queue.pop();

		cout << cur << " ";

		for (auto x : cache[cur]) {
			indegree[x]--;
			if (!indegree[x]) queue.push(-x);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	while (M--) {
		cin >> u >> v;

		cache[u].push_back(v);
		indegree[v]++;
	}

	solved();

	return 0;
}
#define MAX_LEN 502
#define VISITED 1
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;

int visited[MAX_LEN] = { 0, };
int V, E;

bool solved(vector<vector<int>> tree, int s) {
	queue<int> queue;
	queue.push(s);
	visited[s] = VISITED;

	bool isTree = true;
	while (!queue.empty()) {
		int cur = queue.front();
		queue.pop();

		for (auto nxt : tree[cur]) {
			if (visited[nxt] != 0 && visited[nxt] != visited[cur] - 1) isTree = false;
			if (visited[nxt] != 0) continue;

			visited[nxt] = visited[cur] + 1;
			queue.push(nxt);
		}
	}
	return isTree;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt = 1;
	while (1) {
		cin >> V >> E;
		if (!V && !E) break;

		vector<vector<int>> tree(V + 1);
		int u, v;

		for (int i = 1; i <= E; i++) {
			cin >> u >> v;

			tree[u].push_back(v);
			tree[v].push_back(u);
		}

		int res = 0;
		for (int i = 1; i <= V; i++) {
			if (!visited[i]) {
				if (solved(tree, i)) res++;
			}			
		}

		memset(visited, 0, sizeof(visited));

		cout << "Case " << cnt++ << ": ";
		if (res > 1) {
			cout << "A forest of " << res << " trees.";
		}
		else if (res == 1) {
			cout << "There is one trees.";
		}
		else {
			cout << "No trees.";
		}
		cout << "\n";
	}

	return 0;
}
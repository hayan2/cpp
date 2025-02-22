#define MAX_LEN 100001
#define VISITED 1
#define ROOT 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> sccidx[MAX_LEN];
int visited[MAX_LEN] = { 0, };
int V;

vector<int> solved() {
	vector<int> ret(V + 1, 0);
	queue<int> queue;

	queue.push(ROOT);
	visited[ROOT] = VISITED;

	while (!queue.empty()) {
		int vertex = queue.front();
		queue.pop();

		for (int i = 0; i < sccidx[vertex].size(); i++) {			
			if (!visited[sccidx[vertex][i]]) {
				ret[sccidx[vertex][i]] = vertex;
				visited[vertex] = VISITED;
				queue.push(sccidx[vertex][i]);
			}			
		}
	}

	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	cin >> V;

	int u, v;
	for (int i = 0; i < V - 1; i++) {
		cin >> u >> v;

		sccidx[u].push_back(v);
		sccidx[v].push_back(u);
	}

	vector<int> ret = solved();

	for (int i = 2; i <= V; i++) {
		cout << ret[i] << "\n";
	}

	return 0;
}
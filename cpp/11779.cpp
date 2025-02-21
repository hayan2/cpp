#define MAX_LEN 100001
#define INF 1e9
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

vector<pair<int, int>> graph[MAX_LEN];
vector<int> ret(MAX_LEN, INF);
int prevPath[MAX_LEN];
int V, E;

int solved(int u, int v) {	
	priority_queue<pair<int, int>> heap;

	heap.push({ 0, u });

	while (!heap.empty()) {
		int weight = -heap.top().first;
		int dest = heap.top().second;
		heap.pop();

		if (ret[dest] < weight) {
			continue;
		}
		ret[dest] = weight;

		for (int i = 0; i < graph[dest].size(); i++) {
			int heapWeight = weight + graph[dest][i].second;
			int heapDest = graph[dest][i].first;

			if (ret[heapDest] > heapWeight) {
				ret[heapDest] = heapWeight;
				heap.push({ -heapWeight, heapDest });
				prevPath[heapDest] = dest;
			}			
		}
	}

	return ret[v];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E;

	int u, v, w;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;

		graph[u].push_back({ v, w });
	}
	int v1, v2;
	cin >> v1 >> v2;

	cout << solved(v1, v2) << endl;

	stack<int> res;

	res.push(v2);
	for (int i = v2; i != v1;) {
		res.push(prevPath[i]);
		i = prevPath[i];
	}

	cout << res.size() << endl;

	while (!res.empty()) {
		cout << res.top() << " ";
		res.pop();
	}

	return 0;
}
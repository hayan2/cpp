#define _CRT_SECURE_NO_WARNINGS
#define INF 1e9
#define MAX_V 2001
#define MAX_DEST 101
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// in order from left,
// vertex, edge, destination options, artist origin, the road passed
int V, E, t, s, g, h;

std::vector<int> sol(vector<pair<int, int>>* graph, int u) {
	vector<int> ret(V + 1, INF);
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
			}
		}
	}

	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;

	cin >> T;

	while (T--) {
		vector<pair<int, int>> graph[MAX_V];
		vector<int> dest;
		int res[MAX_V] = { 0, };
		cin >> V >> E >> t;
		cin >> s >> g >> h;
		int u, v, w, idx = 0;

		for (int i = 0; i < E; i++) {
			cin >> u >> v >> w;

			graph[u].push_back({ v, w });
			graph[v].push_back({ u, w });
		}
		int d;
		for (int i = 0; i < t; i++) {
			cin >> d;
			dest.push_back(d);
		}

		vector<int> distS = sol(graph, s);
		vector<int> distPass = sol(graph, (distS[g] > distS[h]) ? g : h);
		int origin = (distS[g] > distS[h]) ? g : h;

		for (int i = 0; i < t; i++) {
			if (distPass[dest[i]] >= INF || distS[dest[i]] < distPass[dest[i]] + distS[origin]) {
				continue;
			}
			res[idx++] = dest[i];
		}

		sort(res, res + idx);
		for (int i = 0; i < idx; i++) {
			cout << res[i] << " ";
		}
		cout << endl;
	}

	return 0;
}
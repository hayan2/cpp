#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#define ull unsigned long long 
#define MAX_V 805
#define MAX_E 200005
#define INF 1e9
#define START 1
using namespace std;

// [u], v, w
vector<pair<int, int>> graph[MAX_V];
int V, E, v1, v2;

ull sol(int u, int v) {
	vector<ull> ret(MAX_V, INF);
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
		
	return ret[v];
}

int main(void) {
	int u, v, w, v1, v2;

	scanf("%d %d", &V, &E);

	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &u, &v, &w);

		graph[u].push_back({ v, w });
		graph[v].push_back({ u, w });
	}

	scanf("%d %d", &v1, &v2);

	ull res1 = sol(START, v1) + sol(v1, v2) + sol(v2, V);
	ull res2 = sol(START, v2) + sol(v2, v1) + sol(v1, V);
	
	(res1 >= INF && res2 >= INF) ? printf("-1") : ((res1 > res2) ? printf("%lld", res2) : printf("%lld", res1));

	return 0;
}